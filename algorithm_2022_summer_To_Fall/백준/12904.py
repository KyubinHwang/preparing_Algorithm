S = list(input())
T = list(input())
check = False

while T:
    if T[-1] == 'A':
        T.pop()
    else:
        T.pop()
        T = T[::-1]

    if T == S:
        check = True    
        break
    
if check:
    print(1)
else :
    print(0)