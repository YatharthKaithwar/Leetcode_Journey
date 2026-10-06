class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==1:
            return nums[0]

        def robCircle(houses):
            prev2 = 0 
            prev1 = 0

            for n in houses:
                amount = max(prev1,prev2+n)
                prev2 = prev1
                prev1 = amount
            return prev1
        return max(robCircle(nums[:-1]),robCircle(nums[1:])) 