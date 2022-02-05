import csv
import re
import sys
from pathlib import Path


def input_dna(filename):
    return Path(filename).read_text()


# Get csv from user
def input_csv(filepath):
    users = []
    with open(filepath) as csv_file:
        users_data = csv.DictReader(csv_file)

        for user in users_data:
            users.append(dict(user))
    return users


def counting_strings(Substring, sequence):
    counters = []
    pattern = re.compile(r'({})+'.format(Substring))
    matches = pattern.finditer(sequence)
    for match in matches:
        count = match.end() - match.start()
        counters.append(round(count / len(Substring)))
    return max(counters) if counters else []


def main(data_csv, sequence):
    users = input_csv(data_csv)
    dna = input_dna(sequence)

    for user in users:
        match = 0
        for key, value in user.items():
            if not key == 'name':
                counted = counting_strings(key, dna)
                if not counted == int(value):
                    continue
                match += 1
# does not match
        if match == len(user) - 1:
            print(user['name'])
            return
    print('No match')


if __name__ == "__main__":
    if not len(sys.argv) == 3:
        print('Usage: python dna.py data.csv sequence.txt')
        exit()
    main(sys.argv[1], sys.argv[2])