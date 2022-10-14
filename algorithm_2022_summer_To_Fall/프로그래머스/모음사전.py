from itertools import product

def solution(word):
    alphabet = ['A', 'E', 'I', 'O', 'U']
    arr = []

    for i in range(1, 6):
        for j in product(alphabet, repeat=i):
            arr.append(''.join(list(j)))


    arr.sort()

    return arr.index(word) + 1