import heapq

def solution(operations):
    minheap = []

    for operation in operations:
        if operation[0] == 'I':
            heapq.heappush(minheap, int(operation[2:]))
        elif len(minheap) == 0 :
            continue
        elif operation[2:] == '1':
            minheap.pop()
        else:
            heapq.heappop(minheap)

    minheap.sort()

    if len(minheap) == 0:
        return [0, 0]
    else:
        return [minheap[-1], minheap[0]]