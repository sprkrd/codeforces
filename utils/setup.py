#!/usr/bin/env python3

import os
import sys


FN = """new_cf_problem() {{
    if [ -z "$1" ]; then
        echo "Specify problem name"
        return 1
    elif [ -d "$1" ]; then
        echo "Directory $1 already exists"
        return 1
    else
        echo "Creating code skeleton for problem $1..."
        mkdir $1
        cp {utils_path}/Makefile_template $1/Makefile
        touch $1/test1.in
        touch $1/test1.out
        python3 {utils_path}/new_problem.py ${{@:2}} > $1/main.cpp
        echo "Done!"
    fi
}}"""

FN_HEAD = FN.split()[0]


def main(argv):
    utils_path = os.path.realpath(os.path.dirname(argv[0]))
    bashrc = os.path.expanduser("~/.bashrc")
    with open(bashrc, "r") as f:
        file_content = f.read()
    if FN_HEAD in file_content:
        print(f"{FN_HEAD} already present in .bashrc file", file=sys.stderr)
        sys.exit(1)
    else:
        fn_with_path = FN.format(utils_path=utils_path)
        with open(bashrc, "a") as f:
            f.write(fn_with_path)
        print(f"added {FN_HEAD} function to .bashrc")

if __name__ == "__main__":
    main(sys.argv)



