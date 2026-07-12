class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buying1 = -prices[0];
        int selling1 = 0;
        int buying2 = -prices[0];
        int selling2 = 0;


        for(int i =1; i<prices.size(); i++){
            buying1 = max(buying1 , -prices[i]); // max of buying1 and price at ith index
            selling1 = max(selling1 , buying1 + prices[i]); // max of selling price and (buying+price)
 
            buying2 = max(buying2 , selling1 - prices[i]);
            selling2 = max(selling2 , buying2 + prices[i]);
        }
        return selling2;
    }
};