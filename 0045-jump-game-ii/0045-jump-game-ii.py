class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n<=1:
            return 0
        if nums[0]==0:
            return -1
        
        jumps = 0
        maxReach = 0
        currEnd = 0

        for i in range(n):
            maxReach = max(maxReach,i+nums[i])

            if i==currEnd:
                jumps+=1
                currEnd=maxReach
                if currEnd>=n-1:
                    return jumps
        return -1