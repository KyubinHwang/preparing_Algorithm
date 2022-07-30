def solution(nums):
    answer = 0
    count = 0
    arr = []

    for i in range(3, 3000):
        check = True
        for j in range(2, i):
            if i % j == 0:
                check = False
        if check:
            arr.append(i)

    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            for l in range(j + 1, len(nums)):
                count = nums[i] + nums[j] + nums[l]
                if count in arr:
                    answer += 1
                count = 0

    return answer