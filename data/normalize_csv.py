import sys
import pandas as pd


def normalize(file_path):
    df = pd.read_csv(file_path,header=None)
    df = (df - df.min()) / (df.max() - df.min())
    df.to_csv(file_path + "_normalized", index=False, header=False)


if __name__ == '__main__':
    file_path = sys.argv[1]
    normalize(file_path)
