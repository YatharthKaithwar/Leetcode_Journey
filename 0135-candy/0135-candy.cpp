class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;

        vector<int> candies(n, 1);// Every child must have at least one candy

        for (int i = 1; i < n; ++i) {// Left-to-Right 
            if (ratings[i] > ratings[i - 1]) {// If the current child has a higher rating than the left neighbor
                candies[i] = candies[i - 1] + 1;// give them one more candy than their left neighbor
            }
        }
        for (int i = n - 2; i >= 0; --i) {// Right-to-Left
            if (ratings[i] > ratings[i + 1]) {// If the current child has a higher rating than the right neighbor
                candies[i] = std::max(candies[i], candies[i + 1] + 1); // update their candy count to satisfy both left and right constraints.
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);//Sum up the total candies
    }
};