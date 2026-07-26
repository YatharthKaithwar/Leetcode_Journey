class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks,int mid){// function to find possibilities
        for(auto &task : tasks){// iteration
            int actual = task[0];// actual energy spent
            int minimum = task[1];// minimum required

            if(minimum>mid){// minimum required energy is greater than the mid than it's will not to execute the work
                return false;// not possible
            }
            else{//  its possible
            mid-=actual;// decreasing the energy spent from mid(total)
        }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
     int n = tasks.size();

     int l = 0;
     int r = 1e9;

     int result = INT_MAX;

     auto lambda = [](auto &task1, auto &task2){// for finding max difference
        int diff1 = task1[1]-task1[0];
        int diff2 = task2[1]-task2[0];
        return diff1>diff2;
        };

     sort(begin(tasks),end(tasks),lambda);

     while(l<=r){
        int mid = l + (r-l)/2;

        if(isPossible(tasks,mid)){
            result = mid;
            r = mid-1 ;
        }
        else{
            l = mid+1;
        }
     }
     return result;   
    }
};