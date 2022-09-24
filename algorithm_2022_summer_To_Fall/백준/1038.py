from collections import deque
N = int(input())

queue = deque(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'])

if N <= 9:
    print(queue[N])
    exit(0)

count = 9

while queue :
    q = queue.popleft()
    for i in range(0, 10):
        if int(q[-1]) <= i :
            break
        queue.append(q + str(i))
        count += 1
        if count == N:
            print(queue[-1])
            exit(0)

print(-1)