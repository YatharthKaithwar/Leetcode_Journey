class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left =1;
        long long right = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        while(left<right){
            long long mid = left + (right-left)/2;
            long long trips = 0;

            for (int t : time){// iteratins array to calculate trips time
                trips += mid/t;// calculate trips

                if(trips>=totalTrips) break;// if trips are greater than total trips
            }
            if(trips>=totalTrips){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};