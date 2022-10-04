from collections import defaultdict
import itertools

def solution(clothes):
    answer = 1
    camofla = defaultdict(list)

    for cloth in clothes:
        camofla[cloth[1]].append(cloth[0])

    for i in camofla:
        answer *= len(camofla[i]) + 1

    # 조합으로 풀면 테케 1 시간초과 
    # for i in range(1, len(camofla) + 1):
    #     nC = itertools.combinations(camofla, i)
    #     nC = list(nC)
    #     for j in nC:
    #         tmp = 1
    #         for l in j:
    #             tmp *= len(camofla[l])
    #         answer += tmp

    return answer - 1