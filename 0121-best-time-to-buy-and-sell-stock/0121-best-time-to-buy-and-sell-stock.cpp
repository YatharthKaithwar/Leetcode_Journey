class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minimum = prices[0];
        int maxProfit = 0;

        for (int i = 0 ; i<n ; i++ ){
            int cost = prices[i] - minimum;
            maxProfit = max(cost,maxProfit);
            minimum = min(minimum,prices[i]);
        }
        return maxProfit;
    }
};