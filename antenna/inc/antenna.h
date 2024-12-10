#pragma once
#include <cstdlib>
#include <iostream>
#include "serverCommon.h"
#include <format>
#include <optional>

constexpr int SUCCESS = 0;

class Antenna
{
public:
    Antenna();
    ~Antenna() = default;
     /**
     * @brief recieve the modulate/demodulate type to get the right input data to plot (ask/psk/fsk/qam)
     *
     * @param p_type type of modulate/demodulate
     *
     * @returns None
     */
    void visualizeData(bool isPlotFFT);

    /**
     * @brief generate the random binary data which simulate the data which we receive
     *
     * @param p_length length of the binary data
     *
     * @returns value of length
     */
    std::string randomBinaryMessageGenerator(const int p_length);
private:
     /**
     * @brief using key to get value from database
     *
     * @param p_key key of the data that need read
     *
     * @returns value of key
     */
    std::optional<std::string>  getValue(const std::string &p_key);
};
