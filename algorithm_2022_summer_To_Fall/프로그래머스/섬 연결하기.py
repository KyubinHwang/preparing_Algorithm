def solution(n, costs):
    answer = 0
    islands = [i for i in range(n)]

    costs.sort(key = lambda x : x[2])

    def find_parent(x):
        if islands[x] != x:
            islands[x] = find_parent(islands[x])

        return islands[x]

    def union_parent(a, b):
        a = find_parent(a)
        b = find_parent(b)
        if a < b:
            islands[b] = a
        else:
            islands[a] = b

    for cost in costs:
        if find_parent(cost[0]) != find_parent(cost[1]):
            union_parent(cost[0], cost[1])
            answer += cost[2]
        else:
            continue

    return answer