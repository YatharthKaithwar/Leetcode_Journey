class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        for (int i=1; i<prices.size(); i++){ //Starting from the 2nd index to compare it with previous one)
            if(prices[i]>prices[i-1]){       //if ith index price is greater than its previous one 
                maxProfit += (prices[i] - prices[i-1]);// add it to the profit
            }
        }
        return maxProfit;
    }
};