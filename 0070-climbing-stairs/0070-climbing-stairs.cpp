class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }

        int prev2 = 1; // 2nd prev stair has 1 way(if we start from third stair)
        int prev1 = 2; // prev stair has 2 way (if we start from third stair)
        int current = 0;// current stair will be 0

        for (int i = 3; i<=n ; i++){// iteration start from 3rd stair
            current = prev2 + prev1;// ways to prev two stairs are added
            prev2 = prev1;// updated prev2 to its next
            prev1 = current;// updated prev1 to its next
        }
        return current;
    }
};