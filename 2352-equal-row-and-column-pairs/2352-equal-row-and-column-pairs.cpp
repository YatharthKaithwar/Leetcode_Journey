class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        int count = 0;

        map <vector<int>, int> mp;// creating a map to store row value and freq.

        for(int row = 0; row<n; row++){
            mp[grid[row]]++;// storing row value in map and increasing freq.
        }
        for(int  c=0; c<n; c++){
            vector<int> temp;//for storing both tow and colm value
            for(int r = 0; r<n; r++){
                temp.push_back(grid[r][c]);
            }
            count += mp[temp];//adding the freq to count
        }
        return count;
    }
};