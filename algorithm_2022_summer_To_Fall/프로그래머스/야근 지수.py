import heapq

def solution(n, works):
    answer = 0
    q = []
    for i in works:
        heapq.heappush(q, -i)

    while n:
        tmp = -heapq.heappop(q)
        tmp -= 1
        heapq.heappush(q, -tmp)
        n -= 1

    if -q[-1] < 0 :
        return 0
    else :
        for i in q:
            answer += i * i

    return answer