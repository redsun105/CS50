from csv import DictReader, reader
from sys import argv, exit


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # TODO: Read database file into a variable

    # TODO: Read DNA sequence file into a variable
    with open(argv[2], "r") as sequence_file:
        dna = sequence_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    sequences = {}
    with open(argv[1], "r") as peoplefile:
        peoplereader = reader(peoplefile)
        for row in peoplereader:
            header = row
            header.pop(0)
            for item in header:
                sequences[item] = 0
            break

    for key in sequences:
        ans = longest_match(dna, key)
        sequences[key] = ans

    # TODO: Check database for matching profiles
    with open(argv[1], "r") as peoplefile:
        people = DictReader(peoplefile)
        for person in people:
            match = 0
            for key in sequences:
                if sequences[key] == int(person[key]):
                    match += 1
            if match == len(sequences):
                print(person["name"])
                exit()

        print("no match")

        return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
