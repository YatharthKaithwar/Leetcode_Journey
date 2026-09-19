class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]:
            return 0
        
        rows = len(grid)
        cols = len(grid[0])
        maxArea = 0

        def DFS(r,c):
            if r<0 or c<0 or r>=rows or c>=cols or grid[r][c]==0:
                return 0

            grid[r][c] = 0

            return (1+DFS(r+1,c)+DFS(r-1,c)+DFS(r,c+1)+DFS(r,c-1))
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:

                    maxArea = max(maxArea,DFS(r,c))
        
        return maxArea
