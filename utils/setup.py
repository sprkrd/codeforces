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
        echo "Creating folder for problem $1"
        cp -r {template_path} $1
    fi
}}"""


def main(argv):
    template_path = os.path.realpath(os.path.join(os.path.dirname(argv[0]), "template"))
    bashrc = os.path.expanduser("~/.bashrc")
    with open(bashrc, "r") as f:
        file_content = f.read()

    fn_head = FN.split()[0]
    if fn_head in file_content:
        print("new_cf_problem() already present in .bashrc file", file=sys.stderr)
        sys.exit(1)
    else:
        fn_with_path = FN.format(template_path=template_path)
        with open(bashrc, "a") as f:
            f.write(fn_with_path)
        print("added new_cf_problem function to .bashrc")

if __name__ == "__main__":
    main(sys.argv)



