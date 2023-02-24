/*
77 ms
26.1 MB
*/
/**
 * TC: O(n)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : Binary search
 */


// Applying binary search
class Solution {
private:
    bool isPossible(int mid, vector<int>& weights, int days){
        int day_cnt = 1;
        int curDaySum = 0;

        for(int i=0; i< weights.size(); i++)
        {
            // Until weight sum is less than mid assign the weight in that particular day
            if(curDaySum+weights[i]<=mid)
            {
                curDaySum += weights[i];
            }
            //As soon as weight sum on current day exceeds mid value increment the day count
            else
            { 
                day_cnt++;
                //If day has exceeded the max num of days
                //OR weight is greter than mid value 
                if(day_cnt > days || weights[i] > mid)
                { 
                    return false;
                }
                curDaySum = weights[i];
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Find sum for search space
        int sum = 0;
        for(auto i: weights){
            sum += i;
        }
        
        // Apply binary search on search space
        int s = 0;
        int e = sum;
        int m = s + (e -s)/2;
        int ans = INT_MAX;
        while(s <= e){
            // Check if the current weight sum is assignable to current day
            if(isPossible(m, weights, days)){
                // If it is possible we will store minimum weight in ans
                ans = min(ans, m);
                // Next possible min will be at left of current so 
                e = m - 1;
            }

            else{
                // Next possible min will be at right of current so 
                s = m + 1;
            }
            m = s + (e -s)/2;
        }
        return ans;
    }
};