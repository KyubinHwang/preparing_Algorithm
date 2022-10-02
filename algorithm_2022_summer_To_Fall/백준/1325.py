import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
hack = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    hack[b].append(a)

def bfs(n):
    q = deque()
    q.append(n)
    visited = [0] * (N + 1)
    visited[n] = 1
    count = 0
    while q:
        t = q.popleft()
        for i in hack[t]:
            if visited[i] == 0:
                visited[i] = 1
                count += 1
                q.append(i)
    
    return count


answer = []
cnt = 0
for i in range(1, N + 1):
    res = bfs(i)

    if cnt == res:
        answer.append(i)
    elif cnt < res:
        cnt = res
        answer.clear()
        answer.append(i)

print(* answer)