#!/usr/bin/env python3

import re
import sys

IDENT_SIZE = 4


def nest(line, level=0):
    return " "*(IDENT_SIZE*level) + line


class Parameter:
    @staticmethod
    def from_str_spec(spec):
        name, param_type = spec.split(":")
        m = re.match(r"(\w+)\[(\w+)\]", param_type)
        if m:
            param_type = f"vector<{m.group(1)}>"
            arraysize = m.group(2)
        else:
            arraysize = None
        return Parameter(param_type, name, arraysize)

    def __init__(self, param_type, name, arraysize=None):
        self.param_type = param_type
        self.name = name
        self.arraysize = arraysize

    def to_cpp(self, nest_level=0):
        lines = []
        if self.arraysize is None:
            lines.append(nest(f"{self.param_type} {self.name};", nest_level))
            lines.append(nest(f"cin >> {self.name};", nest_level))
        else:
            lines.append(nest(f"{self.param_type} {self.name}({self.arraysize});", nest_level))
            lines.append(nest(f"for (auto& x : {self.name})", nest_level))
            lines.append(nest("{", nest_level))
            lines.append(nest("cin >> x;", nest_level+1))
            lines.append(nest("}", nest_level))
        return lines

    def is_array(self):
        return self.arraysize is not None

    def __str__(self):
        if self.arraysize:
            return f"{self.name}:{self.param_type}[{self.arraysize}]"
        return f"{self.name}:{self.param_type}"


def create_program_skeleton(*args):
    lines = []
    lines.append("#include <bits/stdc++.h>")
    lines.append("using namespace std;")
    lines.append("")
    lines.append("int main()")
    lines.append("{")
    lines.append(nest("int t;", 1))
    lines.append(nest("cin >> t;", 1))
    lines.append(nest("while (t--)", 1))
    lines.append(nest("{", 1))
    for spec in args:
        param = Parameter.from_str_spec(spec)
        lines += param.to_cpp(nest_level=2)
    lines.append(nest("}", 1))
    lines.append("}")
    return "\n".join(lines)


def main(argv):
    print(create_program_skeleton(*argv[1:]))


if __name__ == "__main__":
    main(sys.argv)

