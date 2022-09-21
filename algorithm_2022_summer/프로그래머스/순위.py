from collections import defaultdict

def solution(n, results):
    answer = 0
    win = defaultdict(set)
    lose = defaultdict(set)

    for result in results:
        win[result[0]].add(result[1])
        lose[result[1]].add(result[0])

    for i in range(1, n + 1):
        for j in win[i]:
            lose[j].update(lose[i])
        for j in lose[i]:
            win[j].update(win[i])

    for i in range(1, n + 1):
        if len(win[i]) + len(lose[i]) == n - 1:
            answer += 1

    return answer