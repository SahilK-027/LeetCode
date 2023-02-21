/*
35 ms
22.4 MB
*/
/**
 * TC: O(log n)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : Binary search
 */

// find mid.
//     if mid is even, then it's duplicate should be in next index.
// 	or if mid is odd, then it's duplicate  should be in previous index.
// 	check these two conditions, 
// 	if any of the conditions is satisfied,
// 	then pattern is not missed, 
// 	so check in next half of the array. i.e, left = mid + 1
// 	if condition is not satisfied, then the pattern is missed.
// 	so, single number must be before mid.
// 	so, update end to mid.

#define isEven(m) ( m & 1 ? false : true)
#define isOdd(m) ( m & 1 ? true : false)
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int s = 0, e = arr.size()-1;
        int m = s + (e - s)/2;
        // edge cases
        if(e == 0) return arr[0];
        else if(arr[0] != arr[1]) return arr[0];
        else if(arr[e] != arr[e-1]) return arr[e];

        // Binary search
        while(s <= e){
            if(arr[m] != arr[m-1] && arr[m] != arr[m+1]) return arr[m];

            if(isEven(m) && arr[m] == arr[m+1] 
                || 
                isOdd(m) && arr[m] == arr[m-1]){
                    s = m +1;
            }
            //condition is not satisfied, then the pattern is missed.
            else{
                e = m-1;
            }
            m = s + (e - s)/2;
        }
        return s;
    }
};