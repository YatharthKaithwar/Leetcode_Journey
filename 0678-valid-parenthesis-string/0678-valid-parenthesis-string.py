class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        min_open = max_open = 0
        for char in s:
            if char == '(':
                min_open += 1
                max_open += 1
            elif char == ')':
                min_open -= 1
                max_open -= 1
            elif char == '*':
                min_open -= 1
                max_open += 1
            if max_open < 0 or min_open < 0:
                if max_open < 0: return False
                min_open = 0
        return min_open == 0