from itertools import permutations

N, M = map(int, input().split())

arr = list(map(int, input().split()))

s = sorted(permutations(arr, M))

for i in s:
    for j in i:
        print(j, end=' ')
    print()