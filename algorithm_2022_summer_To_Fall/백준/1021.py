from collections import deque

N, M = map(int, input().split())
lst = list(map(int, input().split()))
deq = deque(range(1, N + 1))

count = 0

for i in lst:
    while 1:
        if deq[0] == i:
            deq.popleft()
            break

        if deq.index(i) - 0 <= len(deq) - deq.index(i):
            deq.append(deq.popleft())
            count += 1
        else:
            deq.appendleft(deq.pop())
            count += 1

print(count)