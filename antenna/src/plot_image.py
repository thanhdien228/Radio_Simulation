import numpy as np  # use fft
import matplotlib.pyplot as plt
import argparse  # support parse command


def read_data(file_path):
    with open(file_path, "r") as file:
        lines = file.read().split()
    data_number = np.array(lines, dtype=np.float64)
    return data_number


def process_data(data_number, fs):
    wavepoint = data_number
    X_domain = np.linspace(0,(1/fs)* np.size(data_number), np.size(data_number))
    return wavepoint, X_domain


def plot_domain(X_domain, Y_domain, name_pic):
    plt.figure(figsize=(20,6))
    plt.plot(X_domain, Y_domain)
    plt.xlabel("Time (s)")
    plt.ylabel("Amplitude")
    plt.title("modulated signal")
    plt.show()
    plt.savefig(name_pic)
    plt.close()


def parse_command(parser):
    parser.add_argument("--output", help="an output file")
    parser.add_argument("--input", help="an input data")
    parser.add_argument("--fs", type=int, help="frequency sample")
    args = parser.parse_args()
    return args


parser = argparse.ArgumentParser()
args = parse_command(parser)
dataNumber = read_data(args.input)  # read complex
wavepoint, X_domain = process_data(dataNumber, args.fs)
plot_domain(X_domain, wavepoint, args.output)
