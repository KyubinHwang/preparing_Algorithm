from collections import deque

def solution(priorities, location):
    answer = 0
    priority = deque(priorities)
    arr = deque([i for i in range(len(priority))])

    while location in arr:
        if priority[0] >= max(priority):
            priority.popleft()
            arr.popleft()
            answer += 1
        else:
            priority.append(priority.popleft())
            arr.append(arr.popleft())

    return answer