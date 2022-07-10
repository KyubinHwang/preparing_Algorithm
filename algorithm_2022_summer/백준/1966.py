from collections import deque

N = int(input())

for _ in range(N):
    n, m = map(int, input().split())
    lst = deque(map(int, input().split()))
    queue = deque(range(n))

    count = 0
    while queue:
        if lst[queue[0]] == max(lst):
            if queue[0] == m :
                print(count + 1)
                break
            lst[queue[0]] = 0
            queue.popleft()
            count += 1
        else:
            queue.append(queue.popleft())