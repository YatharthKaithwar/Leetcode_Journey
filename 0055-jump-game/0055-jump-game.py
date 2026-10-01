class Solution(object):
    def canJump(self, arr):
        """
        :type nums: List[int]
        :rtype: bool
        """
        maxReach = 0

        for i in range(len(arr)):
            if i>maxReach:
                return False

            maxReach = max(maxReach,i+arr[i])

            if maxReach >= len(arr)-1:
                return True
        return True

        