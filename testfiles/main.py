#!/usr/bin/env python3

import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: {} <name>".format(sys.argv[0]))
        sys.exit(1)

    name = sys.argv[1]
    secret_code = 1234

    print(f"Hello {name}! The secret code is {secret_code}.")

if __name__ == "__main__":
    main()
