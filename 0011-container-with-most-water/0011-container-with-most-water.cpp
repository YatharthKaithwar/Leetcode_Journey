class Solution {
public:
    int maxArea(vector<int>& height) {
      int maxwtr=0;
      int lp = 0 , rp = height.size()-1;

      while (lp < rp){
        int w = rp-lp;
        int ht = min(height[lp],height[rp]);
        int curr_wtr = w * ht;
        maxwtr = max(maxwtr , curr_wtr);

        if(height[lp]<height[rp]){ 
            lp++;
        } else{
            rp--;
        }
      }  
      return maxwtr;
      return maxwtr;
    }
};