def solution(name):
    answer = 0
    num = [min(abs(ord('A') - ord(n)), 26 - abs(ord('A') - ord(n))) for n in name]
    answer += sum(num)

    check = len(name) - 1

    for i in range(len(name)):
        next = i + 1
        while next < len(name) and name[next] == 'A':
            next += 1
        check = min([check, 2 * i + len(name) - next, i + 2 * (len(name) - next)])

    answer += check

    return answer