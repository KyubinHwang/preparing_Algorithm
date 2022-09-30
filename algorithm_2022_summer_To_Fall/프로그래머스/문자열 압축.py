def solution(s):
    answer = len(s)
    
    for i in range(1, len(s) // 2 + 1):
        tmp = ""
        count = 1
        temp = s[:i]
        for j in range(i, len(s) + i, i):
            if temp == s[j:j + i]:
                count += 1
            else:
                if count == 1:
                    tmp += temp
                else:
                    tmp += str(count) + temp
                temp = s[j:j + i]
                count = 1
        
        answer = min(answer, len(tmp))
        
    return answer