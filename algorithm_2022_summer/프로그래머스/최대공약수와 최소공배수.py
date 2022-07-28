def gcd(a, b):
    if a % b == 0 :
        return b
    else :
        return gcd(b, a % b)

def solution(n, m):
    answer = []
    tmp = gcd(n, m)
    answer.append(tmp)

    tmp = (n // tmp) * (m // tmp) * tmp

    answer.append(tmp)

    return answer