from itertools import permutations

def solution(numbers):
    answer = 0
    arr = [i for i in numbers]
    tmp = []

    for i in range(1, len(arr) + 1):
        tmp += list(permutations(numbers, i))

    number = set([int(''.join(i)) for i in tmp])

    for i in number:
        check = True
        if i < 2 :
            check = False
        else:
            for j in range(2, int(i**0.5) + 1):
                if i % j == 0:
                    check = False
        if check :
            answer += 1            

    return answer