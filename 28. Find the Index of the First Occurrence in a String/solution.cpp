// Runtime: 0 ms
// Memory Usage: 6.1 MB
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int start = 0;
        int j = 0;
        while(j < needle.length() && i<haystack.length()){
            j = 0;
            start = i;
            int x = i;
            while(haystack[x] == needle[j] && j < needle.length()){
                x++;
                j++;
            }
            i++;
        }
        if(j == needle.length()){
            return start;
        }
        else{
            return -1;
        }
    }
};
