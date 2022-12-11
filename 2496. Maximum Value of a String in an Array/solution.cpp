/**
 * @author : Sahilk-027
 * @brief : Simple brute force
*/

class Solution {
private:
    // The function to check if character in string is alphabet or not
    bool isAlphabet(char ch){
        if(int(ch) >= 97 && int(ch) <= 122)
        {
            return true;
        }
        return false;
    }
public:
    int maximumValue(vector<string>& strs) {
        int maxi = INT_MIN;
        int n = strs.size();
        for(int i = 0 ;i< n ;i++){
            int flag = 1;
            for(int j = 0; j < strs[i].size(); j++){
                // If there is alphabet in string then max will be length of string
                if(isAlphabet(strs[i][j])){
                    int len = strs[i].length();
                    maxi = max(maxi, len);
                    // We are using flag to teel that string had an alphabet
                    flag = 0;
                    break;
                }
            }
            // If flag is still 1 means there was no alphabet in string
            if(flag){
                // So number will be string to int of string
                int num = stoi(strs[i]);
                maxi = max(maxi, num);
            }
        }
        return maxi;
    }
};
