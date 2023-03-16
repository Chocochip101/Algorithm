def solve(N, number):
    cache = []
    for i in range(1, 9):
        nums = set()
        nums.add(int(str(N) * i))
        
        for j in range(i - 1):
            for x in cache[j]:
                for y in cache[ - 1 - j]:
                    nums.add(x + y)
                    nums.add(x - y)
                    nums.add(x * y)
                    if y != 0:
                        nums.add(x // y)
        
        if number in nums:
            return i
        cache.append(nums)
    return -1
        
def solution(N, number):
    return solve(N, number)