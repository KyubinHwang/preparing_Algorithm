def solution(n, computers):
    answer = 0
    network = [set([]) for _ in range(0, n + 1)]
    
    for i in range(len(computers)):
        for j in range(len(computers[i])):
            if computers[i][j] == 1:
                if i != j:
                    network[i + 1].add(j + 1)
                    network[j + 1].add(i + 1)
    
    def dfs(n):
        visited[n] = 1
        for i in network[n]:
            if visited[i] == 0:
                dfs(i)
        
    visited = [0] * (n + 1)
    for i in range(1, n + 1):
        if visited[i] == 0:
            dfs(i)
            answer += 1
    

    return answer