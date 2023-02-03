/*
0 ms
7.3 MB
*/

/**
 * TC: O(N)
 * SC: O(1)
 */

/**
 * @author : SahilK-027
 * @brief :  String + Math
*/

// If str1 + str2 == str2 + str1 then can then only strings will have GCD
// AND if GCD exists then it will start from 0th index of string1 / string2 and its length will be equal to GCD of lengths of String1 and string2
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans1 = str1 + str2;
        string ans2 = str2 + str1;
        string result = "";
        if(ans1 == ans2){
            result = str2.substr(0, gcd(str1.length(), str2.length()));
        }
        return result;
    }
};