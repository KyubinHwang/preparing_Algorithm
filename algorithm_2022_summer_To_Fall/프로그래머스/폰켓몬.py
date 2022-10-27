def solution(nums):
    length = len(nums) // 2

    if len(set(nums)) >= length:
        return length
    else:
        return len(set(nums))