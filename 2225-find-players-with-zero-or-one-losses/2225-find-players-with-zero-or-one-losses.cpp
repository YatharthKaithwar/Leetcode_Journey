class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map <int,int> lost_map;

        for(int i=0;i<matches.size();i++){
            int loser = matches[i][1];// pushing all the loser playeers in map
            lost_map[loser]++;// increasing there losing frequency
        }
        vector <int> notLost;
        vector <int> lostOnce;

        for(int i = 0;i<matches.size();i++){
            int winner = matches[i][0];// adding winner to winner vector
            int loser = matches[i][1];// adding loser to loser vector

            if(lost_map.find(winner)==lost_map.end()){
                notLost.push_back(winner);// pushing winner in the notLost vector
                lost_map[winner]=2;// for not taking a winner twice
            }
            if(lost_map[loser]==1){
                lostOnce.push_back(loser);// adding once lost player
            }
        }
        sort(begin(notLost),end(notLost));
        sort(begin(lostOnce),end(lostOnce));

        return {notLost,lostOnce};

    }
};