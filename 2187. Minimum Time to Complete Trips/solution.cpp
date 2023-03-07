/*
548 ms
94.6 MB
*/

/**
 * TC: O(n log n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Binary search
*/

#define ll long long
class Solution {
public:
    ll minimumTime(vector<int>& time, int totalTrips) {
        // Let start and end pointers
        ll s = 0;
        // Gioven constraints  1 <= time[i], totalTrips <= 10^7
        ll e = 1e14;
        ll m = s + (e - s)/2;
        ll possible_ans = 0;
        while(s <= e){
            // Current ans = 0;
            ll curr_trips = 0;
            // Check if in current time it is possible to make total trips
            for(int i = 0 ; i < time.size(); i++){
                curr_trips += m / time[i];
            }
            // If it is possible save ans and search for minimum solution
            if(curr_trips == totalTrips){
                possible_ans = m;
                e = m -1;
            }
            
            else if(curr_trips > totalTrips){
                possible_ans = m;
                e = m - 1;
            }
            // If not possible search for bigger solution
            else{
                s = m + 1;
            }
            m = s + (e - s)/2;
        }
        return possible_ans;
    }
};