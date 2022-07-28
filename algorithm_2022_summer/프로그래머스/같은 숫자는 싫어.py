def solution(arr):
    answer = []
    tmp = -1
    for i in arr:
        if len(answer) == 0:
            answer.append(i)
            tmp = i
        else:
            if tmp == i:
                continue
            else:
                answer.append(i)
                tmp = i

    return answer