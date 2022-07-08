# TODO
def main():
    n = get_height()

    for i in range(n):
        for j in range(n - 1 - i, 0, -1):
            print(" ", end="")

        for k in range(i + 1):
            print("#", end="")

        print("  ", end="")

        for k in range(i + 1):
            print("#", end="")

        print("\n", end="")



def get_height():
    while True:
        try:
            n = int(input("height = "))
            if n < 9 and n > 0:
                break
        except:
            print("Please provide an integer")

    return n


main()
