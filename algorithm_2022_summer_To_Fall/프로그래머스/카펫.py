def solution(brown, yellow):
    answer = []

    width = 1
    length = 1

    for i in range(1, brown + yellow + 1):
        if (brown + yellow) % i == 0:
            length = i
            width = (brown + yellow) / i
            if yellow == (length - 2) * (width - 2):
                if width <= length:
                    answer.append(length)
                    answer.append(width)
                    return answer

    return answer
