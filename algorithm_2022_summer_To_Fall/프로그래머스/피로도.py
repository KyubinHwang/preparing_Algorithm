answer = 0

def solution(k, dungeons):
    visited = [0] * len(dungeons)

    def dfs(dept, k):
        global answer
        if dept == len(dungeons):
            answer = dept
            return answer

        answer = max(answer, dept)

        for i in range(len(dungeons)):
            if k >= dungeons[i][0] and visited[i] == 0:
                visited[i] = 1
                dfs(dept + 1, k - dungeons[i][1])
                visited[i] = 0

    dfs(0, k)

    return answer