class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int start = 1, end = arr.size()-1;
      while(start < end){
           int mid = start + (end - start) / 2;

           if(arr[mid]>arr[mid+1]){ // If the middle element is strictly greater than the next element,
                                    // we are in the decreasing part of the mountain.
            end =mid;
           }
           else { // If the middle element is less than the next element,
                  // we are in the increasing part of the mountain.
                  // The peak must be strictly to the right of 'mid'.
            start =mid+1;
           }
      }
      return start;
}
};
