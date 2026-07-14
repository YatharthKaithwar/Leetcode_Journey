class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int longestStreak =1;
         if(nums.empty()) return 0;
        
        for (int num : set){// iteration
            if(set.find(num-1)==set.end()){// check if number is starting point in the set
                int cnt = 1;
                int current_num = num;
                while(set.find(current_num+1)!=set.end()){// expand the sequence
                    current_num += 1;
                    cnt += 1;
                }

                longestStreak = max(longestStreak,cnt);
            }

        }
        return longestStreak;
    }
};