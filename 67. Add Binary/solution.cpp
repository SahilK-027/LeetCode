/*
5 ms
6.1 MB
*/
/**
 * TC: O(max(a.length(), b.length()))
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : String Traversal
 */


class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry=0;

        string ans = "";

        while(i>=0 || j>=0){
            int total = carry;
            if(i>=0) total += a[i]-'0';
            if(j>=0) total += b[j]-'0';
            carry = total > 1 ? 1 : 0;
            ans += (total % 2) + '0';
            i--;
            j--;
        }
        
        if(carry) ans += carry + '0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};