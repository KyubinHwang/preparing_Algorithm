import sys 
import heapq
input = sys.stdin.readline

N, K = map(int, input().split())
jewel = []
bag = []

for i in range(N):
    M, V = map(int, input().split())
    jewel.append([M, V])
jewel.sort()

for i in range(K):
    C = int(input())
    bag.append(C)
bag.sort()

result = []
answer = 0
for b in bag:
    while jewel and b >= jewel[0][0]:
        heapq.heappush(result, -jewel[0][1])
        heapq.heappop(jewel)
    
    if result:
        answer += heapq.heappop(result)
    elif not jewel:
        break

print(-answer)