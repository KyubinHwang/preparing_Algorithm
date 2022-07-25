import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
dpMax = arr
dpMin = arr

for _ in range(N - 1):
    x, y, z = map(int, input().split())
    dpMax = [x + max(dpMax[0], dpMax[1]), y + max(dpMax), z + max(dpMax[1],dpMax[2])]
    dpMin = [x + min(dpMin[0], dpMin[1]), y + min(dpMin), z + min(dpMin[1],dpMin[2])]

print(max(dpMax), min(dpMin))