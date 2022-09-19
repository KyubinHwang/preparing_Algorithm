from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    q = deque([0]*bridge_length)
    bridge = deque(truck_weights)
    count = 0

    while bridge:
        temp = q.popleft()
        count -= temp
        answer += 1
        if count + bridge[0] > weight:
            q.append(0)
        else:
            tmp = bridge.popleft()
            count += tmp
            q.append(tmp)

    return answer + bridge_length