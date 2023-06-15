/*
22 ms
15.9 MB

TC : O(log N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Binary search
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s = 0;
        int e = letters.size() - 1;
        int m = s + (e-s)/2;
        char ans = '0';
        while(s <= e){
            if(int(letters[m]) > int(target)){
                ans = letters[m];
                e = m -1;
            }
            else if(int(letters[m]) <= int(target)){
                s = m + 1;
            }
            m = s + (e-s)/2;
        }
        if(ans == '0') return letters[0];
        return ans;
    }
};