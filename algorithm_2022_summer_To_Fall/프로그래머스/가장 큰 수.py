def solution(numbers):
    answer = ''
    number = [str(i) for i in numbers]

    number.sort(key=lambda x : x * 3, reverse=True)

    for i in number:
        answer += i

    if len(answer) >= 2 and answer[0] == '0' and answer[1] == '0':
        return '0'

    return answer