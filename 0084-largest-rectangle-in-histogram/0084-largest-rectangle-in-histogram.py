class Solution(object):
    def largestRectangleArea(self, heights):

        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []  # Stores tuples of (index, height)
        max_area = 0
    
        for i, h in enumerate(heights):
            start = i
        # If current height is shorter, we must pop and calculate areas
            while stack and stack[-1][1] > h:
                prev_i, prev_h = stack.pop()
            # Width is the difference between current index and the popped element's start index
                width = i - prev_i
                max_area = max(max_area, prev_h * width)
            # The current bar can extend backwards to the popped bar's starting index
                start = prev_i
            
            stack.append((start, h))
        
    # Process any remaining bars that extend all the way to the end of the histogram
        for i, h in stack:
            width = len(heights) - i
            max_area = max(max_area, h * width)
        
        return max_area