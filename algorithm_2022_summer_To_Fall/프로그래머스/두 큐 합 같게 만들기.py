from collections import deque

def solution(queue1, queue2):
    answer = 0
    q1 = deque(queue1)
    q2 = deque(queue2)
    hap1 = sum(q1)
    hap2 = sum(q2)

    while True:
        if hap1 > hap2:
            tmp = q1.popleft()
            q2.append(tmp)
            hap1 -= tmp
            hap2 += tmp
            answer += 1
        elif hap1 == hap2:
            return answer
        else:
            tmp = q2.popleft()
            q1.append(tmp)
            hap1 += tmp
            hap2 -= tmp
            answer += 1

        if answer == len(queue1) * 3:
            return -1