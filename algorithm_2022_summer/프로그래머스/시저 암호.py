def solution(s, n):
    answer = ''

    for i in range(len(s)):
        if s[i] == ' ':
            answer += s[i]
        else:
            tmp = ord(s[i])
            if 65 <= tmp <= 90:
                if tmp + n > 90:
                    answer += chr(tmp + n - 26)
                else:
                    answer += chr(tmp + n)
            else:
                if tmp + n > 122:
                    answer += chr(tmp + n - 26)
                else:
                    answer += chr(tmp + n)
    return answer