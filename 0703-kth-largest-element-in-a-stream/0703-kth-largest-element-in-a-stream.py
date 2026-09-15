class KthLargest(object):

    def __init__(self, k, nums):
        self.k = k 
        self.heap = nums

        heapq.heapify(self.heap)

        while len(self.heap)>self.k:
            heapq.heappop(self.heap)
        """
        :type k: int
        :type nums: List[int]
        """
        

    def add(self, val):
        heapq.heappush(self.heap,val)

        if len(self.heap)>self.k:
            heapq.heappop(self.heap)
        
        return self.heap[0]
        """
        :type val: int
        :rtype: int
        """
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)