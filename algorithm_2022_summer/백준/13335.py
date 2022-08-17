from collections import deque

n, w, L = map(int, input().split())

q = deque(list(map(int, input().split())))
bridge = deque([0] * w)
weight, time = 0, 0

while True:
    finished = bridge.popleft()
    weight -= finished 
    if q:
        if weight + q[0] <= L:
            bridge.append(q[0])
            weight += q[0]
            q.popleft()
        else:
            bridge.append(0)

    time += 1
    
    if not bridge:
        break
        
print(time)