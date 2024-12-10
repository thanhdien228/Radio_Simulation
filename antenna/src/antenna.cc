#include "antenna.h"

Antenna::Antenna()
{
    g_serverLogger.enableLogFile(true);
}

void Antenna::visualizeData(bool isPlotFFT)
{
    std::string plotFileKey;
    if (isPlotFFT)
    {
        plotFileKey = "/plotFFT";
    }
    else
    {
        plotFileKey = "/plotFile";
    }
    std::map<std::string, std::string> dataKeys = {
        {"input", "/input"},
        {"output", "/output"},
        {"fs", "/fs"},
        {"plotFile", plotFileKey}};

    std::map<std::string, std::optional<std::string>> dataValues;
    for (const auto &entry : dataKeys)
    {
        dataValues[entry.first] = getValue(entry.second);
    }

    if (!dataValues["input"].has_value() || !dataValues["output"].has_value() ||
        !dataValues["fs"].has_value() || !dataValues["plotFile"].has_value())
    {
        g_serverLogger.error("Error missing data for visualization.");
        return;
    }

    std::string str = "python3 " + dataValues["plotFile"].value() + " --output " + dataValues["output"].value() \
     + " --input " + dataValues["input"].value() + " --fs " + dataValues["fs"].value();
    const char *command = str.c_str();
    int returnCode = system(command);
    if (returnCode == SUCCESS)
    {       
        g_serverLogger.info("Calling system call to visualize data successfully");
    }
    else
    {
        g_serverLogger.error("Error when calling system call to visualize data.");
    }
}

std::optional<std::string> Antenna::getValue(const std::string &p_key)
{
    try
    {
        auto resVariant = InMemDatabase::getInstance().getValue(p_key);
        const char *value = "";
        extractValue(resVariant, value);
        return std::string(value);
    }
    catch (const DBException &e)
    {
        g_serverLogger.error(stringify("Error when loading database: ", e.what()));
        return std::nullopt;
    }
}

std::string Antenna::randomBinaryMessageGenerator(const int p_length)
{
    std::string binaryMessage;
    srand(time(0));
    for (int index = 0; index < p_length; index++)
    {
        binaryMessage += (rand() % 2 + '0');
    }
    std::cout << "Generated data: " << binaryMessage << std::endl;
    return binaryMessage;
}
