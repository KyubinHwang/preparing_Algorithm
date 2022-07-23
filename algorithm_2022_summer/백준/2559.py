N, K  = map(int, input().split())
temp = list(map(int, input().split()))
part = sum(temp[:K])
result = [part]

for i in range(0, len(temp) - K):
    part = part - temp[i] + temp[i + K]
    result.append(part)

print(max(result))

