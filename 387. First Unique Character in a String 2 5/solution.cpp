class Solution {
private:
    int search(string s, char ans){
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ans)
                return i;
        return -1;
    }
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for (int i = 0; i < s.length(); i++){
            arr[int(s[i] - 'a')]++;     //store count of corresponding element
        }
        for (int i = 0; i < s.length(); i++){ 
            if (arr[int(s[i] - 'a')] == 1){ //If for particular index is occuring once
                char ans = s[i];
                int index = search(s, ans);
                return index;
            }
        }
    return -1;
    }
};
