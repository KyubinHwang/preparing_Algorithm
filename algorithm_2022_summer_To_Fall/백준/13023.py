N, M = map(int, input().split())
friend = [[] for _ in range(N)] 
visited = [False] * N

for i in range(M) :
    a, b = map(int, input().split())
    friend[a].append(b)
    friend[b].append(a)

def dfs(index, dept):
    if dept == 4:
        print(1)
        exit()
    for i in friend[index]:
        if not visited[i] == True:
            visited[i] = True
            dfs(i, dept + 1)
            visited[i] = False


for i in range(N):
    visited[i] = True
    dfs(i, 0)
    visited[i] = False

print(0)