#!/usr/bin/env python3

from itertools import permutations
from sys import argv


filein = argv[1]
fileout = argv[2]


problems = []

with open(filein, "r") as f:
    lines = f.readlines()
    T = int(lines[0])
    for i in range(T):
        problems.append((int(lines[1+3*i]), list(map(int, lines[2+3*i].split())), list(map(int, lines[3+3*i].split()))))


outputs = []

with open(fileout, "r") as f:
    lines = f.readlines()
    k = 0
    for i in range(T):
        sol_length = int(lines[k])
        k += 1
        if sol_length != -1:
            perma = problems[i][1].copy()
            permb = problems[i][2].copy()
            for j in range(sol_length):
                switch_i, switch_j = map(int, lines[k].split())
                k += 1
                perma[switch_i-1], perma[switch_j-1] = perma[switch_j-1], perma[switch_i-1]
                permb[switch_i-1], permb[switch_j-1] = permb[switch_j-1], permb[switch_i-1]
            if perma != list(reversed(permb)):
                print(f"Error test #{i+1}: {problems[i]} {sol_length} {perma} {permb}")

# 1 2 3 4 5
# 1 3 2 5 4

# 3 2 1 4 5
# 2 3 1 5 4

# 3 5 1 4 2
# 2 4 1 5 3

