from cs50 import get_int


def main():
    # Get height input from user and promt until it qualifies
    while True:
        height = get_int("Height: ")
        width = height
        # Receive integers from the user from 0 to 8
        if height > 0 and height <= 8:
            break
    # Loop to print Spaces
    for i in range(1, height + 1):
        num_hashes = i
        num_spaces = width - num_hashes

        print(" " * num_spaces, end="")
        print("#" * num_hashes, end="")
        print("  ", end="")
        print("#" * num_hashes)


if __name__ == "__main__":
    main()