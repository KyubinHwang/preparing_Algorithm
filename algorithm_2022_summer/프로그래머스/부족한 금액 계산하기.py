def solution(price, money, count):
    answer = -1

    arr = []
    for i in range(1, count + 1):
        arr.append(price * i)

    answer = sum(arr) - money

    if answer >= 0:
        return answer
    else:
        return 0