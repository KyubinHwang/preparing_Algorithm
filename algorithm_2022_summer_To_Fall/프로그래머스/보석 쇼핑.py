def solution(gems):
    gemCount = len(set(gems))
    dic = {}
    start = 0
    end = 0
    answer = [1, len(gems)]

    while end < len(gems):
        if gems[end] not in dic:
            dic[gems[end]] = 1
        else :
            dic[gems[end]] += 1

        end += 1

        if len(dic) == gemCount:
            while start < end:
                if dic[gems[start]] > 1:
                    dic[gems[start]] -= 1
                    start += 1
                elif answer[1] - answer[0] >= end - start:
                    answer[1] = end
                    answer[0] = start + 1
                    break
                else:
                    break

    return answer