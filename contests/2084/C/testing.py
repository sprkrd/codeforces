#!/usr/bin/env python3

from itertools import permutations

N = 5

problems = []

for n in range(1, N+1):
    for perma in permutations(range(1,n+1)):
        for permb in permutations(range(1,n+1)):
            problems.append((n, perma, permb))

print(len(problems))
for n, perma, permb in problems:
    print(n)
    print(" ".join(map(str, perma)))
    print(" ".join(map(str, permb)))


