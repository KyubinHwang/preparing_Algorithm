# 1
def solution(source):
    answer = []
    source = list(source)
    while source:
        tmp = []
        delsource = []
        for i in range(len(source)):
            if source[i] not in tmp:
                delsource.append(source[i])
                tmp.append(source[i])
        for i in delsource:
            source.remove(i)
        tmp.sort()

        answer += tmp

    result = ''.join(answer)

    return result

# 2
from collections import deque

def solution(music):
    answer = 0
    piano = [[], [2, 3], [1, 3], [1, 2, 4, 5], [3, 5], [3, 4, 6, 7], [5, 7],
        [5, 6, 8], [7, 9, 10], [8, 10], [8, 9, 11, 12], [10, 12], [10, 11]
    ]

    def bfs(present, target):
        q = deque()
        q.append(present)
        visited = [0 for _ in range(13)]
        while q:
            x = q.popleft()
            for pos in piano[x]:
                if visited[pos] == 0:
                    visited[pos] = visited[x] + 1
                    q.append(pos)

                if pos == target:
                    return visited[target]

        return visited[target]

    present = 1

    for i in music:
        count = bfs(present, i)
        present = i
        answer += count

    return answer

# 3
result = 0

def solution(paper, n):

    def dfs(paper, dept):
        global result

        if dept == n:
            return

        for i in range(len(paper) - 1):
            a = paper[:i + 1]
            a.reverse()
            b = paper[i + 1:]
            if len(a) < len(b):
                for j in range(len(a)):
                    b[j] = a[j] + b[j]
                result = max(result, max(b))
                dfs(b, dept + 1)
            else:
                for j in range(len(b)):
                    a[j] = a[j] + b[j]
                result = max(result, max(a))
                dfs(a, dept + 1)

    dfs(paper, 0)

    return max(result, max(paper))