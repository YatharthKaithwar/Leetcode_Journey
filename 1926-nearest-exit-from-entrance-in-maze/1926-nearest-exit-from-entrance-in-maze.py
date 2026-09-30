class Solution(object):
    def nearestExit(self, maze, entrance):
        """
        :type maze: List[List[str]]
        :type entrance: List[int]
        :rtype: int
        """
        rows = len(maze)
        cols = len(maze[0])
        sRow,sCol=entrance

        maze[sRow][sCol]='+'

        queue = deque([(sRow,sCol,0)])
        directions = ((-1,0),(1,0),(0,-1),(0,1))

        while queue:
            r,c,dist = queue.popleft()

            for dr,dc in directions:
                nr = r+dr
                nc = c+dc

                if 0<=nr<rows and 0<=nc<cols and maze[nr][nc]=='.':
                    if nr == 0 or nr == rows-1 or nc == 0 or nc == cols-1:
                        return dist+1
                    maze[nr][nc]='+'
                    queue.append((nr,nc,dist+1))
        return -1

