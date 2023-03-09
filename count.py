import argparse
import collections

parser = argparse.ArgumentParser(prog="wordsText")
parser.add_argument('filename', default="words.txt", type=str)

counts = collections.Counter()

def count_words(filename):

    with open(filename, "r") as f:
        while True:
            line = f.readline()
            if not line:
                break
            words = line.lower().split()
            if not words:
                continue
            counts.update(words)

    pairs = sorted(counts.items(), key=lambda kv: kv[1], reverse=True)
    for word, count in counts.most_common():
        print(word, count)


if __name__ == "__main__":
    args = parser.parse_args()
    count_words(args.filename)