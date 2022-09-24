def solution(tickets):
    answer = []
    airport = {}

    for way in tickets:
        if way[0] in airport:
            airport[way[0]].append(way[1])
        else:
            airport[way[0]] = [way[1]]

    for i in airport.keys():
        airport[i].sort(reverse=True)

    stack = ["ICN"]

    while stack:
        top = stack[-1]
        if (top not in airport) or not(airport[top]):
            answer.append(stack.pop())
        else:
            stack.append(airport[top].pop())

    result = []

    for i in range(len(answer)):
        result.append(answer[len(answer) - i - 1])

    return result