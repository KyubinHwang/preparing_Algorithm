def solution(answers):
    supo1 = [1, 2, 3, 4, 5] * 2000
    supo2 = [2, 1, 2, 3, 2, 4, 2, 5] * 1250
    supo3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5] * 1000
    count = [0, 0, 0]
    for i in range(len(answers)):
        if answers[i] == supo1[i]:
            count[0] += 1
        if answers[i] == supo2[i]:
            count[1] += 1
        if answers[i] == supo3[i]:
            count[2] += 1

    return [i + 1 for i, j in enumerate(count) if j == max(count)]