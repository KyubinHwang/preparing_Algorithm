def solution(s):
    answer = True
    tmp = 0
    for i in range(len(s)):
        if s[i] == '(':
            tmp += 1
        else:
            tmp -= 1

        if tmp < 0 :
            return False

    if tmp == 0:
        return True
    else:
        return False

    return True