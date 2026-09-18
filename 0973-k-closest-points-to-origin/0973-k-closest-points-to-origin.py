class Solution(object):
    def kClosest(self, points, k):
        """
        :type points: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        maxHeap = []

        for x,y in points:
            dist = x**2 + y**2

            heapq.heappush(maxHeap,(-dist,[x,y]))

            if len(maxHeap)>k:
                heapq.heappop(maxHeap)
        return [point for dist,point in maxHeap]