import heapq

def solution(scoville, K):
    answer = 0
    heap = []

    for i in scoville:
        heapq.heappush(heap, i)

    while heap[0] < K:
        root = heapq.heappop(heap)

        if len(heap) >= 1:
            x = heapq.heappop(heap)
            tmp = root + x * 2
            answer += 1
            heapq.heappush(heap, tmp)
        else : 
            return -1

    return answer
