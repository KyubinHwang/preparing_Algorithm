T = int(input())

def binary_search(start, end, find, listN):
    while start <= end:
        middle = (start + end) // 2
        if find == listN[middle]:
            return 1
        elif find < listN[middle]:
            end = middle - 1
        else:
            start = middle + 1
    return 0

for _ in range(T):
    N = int(input())
    lstN = sorted(list(map(int, input().split())))
    M = int(input())
    lstM = list(map(int, input().split()))
    for i in lstM :
        start = 0
        end = N - 1
        print(binary_search(start, end, i, lstN))