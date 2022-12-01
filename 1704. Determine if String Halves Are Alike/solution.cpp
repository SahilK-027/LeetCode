class Solution {
public:
    bool halvesAreAlike(string s) {
        int i = 0;
        int j = s.length()-1;
        int v_count1 = 0;
        int v_count2 = 0;
        while(i < j){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
            || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                 v_count1++;
            }
            if(s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U'
            || s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                v_count2++;
            }
            i++;
            j--;
        }
        return v_count1 == v_count2;
    }
};