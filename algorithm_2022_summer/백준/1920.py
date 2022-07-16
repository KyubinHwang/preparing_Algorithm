N = int(input())
lstN = sorted(list(map(int, input().split())))
M = int(input())
lstM = list(map(int, input().split()))

def binary_search(start, end, find, listN):
    if start > end:
        return 0
    middle = (start + end) // 2
    if find == listN[middle]:
        return 1
    elif find < listN[middle]:
        return binary_search(start, middle - 1, find, listN)
    else:
        return binary_search(middle + 1, end, find, listN)


for i in lstM :
    start = 0
    end = N - 1
    print(binary_search(start, end, i, lstN))