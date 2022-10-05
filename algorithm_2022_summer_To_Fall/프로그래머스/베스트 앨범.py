from collections import defaultdict

def solution(genres, plays):
    answer = []
    dic = defaultdict(list)
    check = defaultdict(int)

    for i in range(len(genres)):
        dic[genres[i]].append([plays[i], i])
        check[genres[i]] += plays[i]

    for i in dic:
        dic[i].sort(key = lambda x : x[0], reverse=True)

    listcheck = sorted(check.items(), key = lambda item: item[1], reverse = True)
    dictA = dict(listcheck)

    for i in dictA:
        tmp = 2
        for j in dic[i]:
            if tmp == 0:
                break
            answer.append(j[1])
            tmp -= 1

    return answer