from collections import deque

def solution(n, edges):
    answer = 0
    visited = [0] * (n + 1)
    arr = [[] for _ in range(n + 1)]
    q = deque()

    edges.sort()
    for i in range(len(edges)):
        arr[edges[i][0]].append(edges[i][1])
        arr[edges[i][1]].append(edges[i][0])

    q.append(1)

    res = 0

    while q:
        tmp = q.popleft()
        for i in arr[tmp]:
            if visited[i] == 0 and i != 1:
                q.append(i)
                visited[i] += visited[tmp] + 1
                res = max(res, visited[i])

    for i in range(2, len(visited)):
        if res == visited[i]:
            answer += 1

    return answer