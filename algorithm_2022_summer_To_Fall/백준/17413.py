import sys

input = sys.stdin.readline

S = map(str, input().strip())
check = False
result = ""
word = ""

for i in S:
    if check == False:
        if i == '<' :
            check = True
            word += i
        elif i == ' ':
            word += i
            result += word
            word = ""
        else:
            word = i + word
    else:
        word += i
        if i == '>' :
            check = False
            result += word
            word = ""

print(result + word)
