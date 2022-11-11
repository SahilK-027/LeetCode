// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); 
        int s = 1;
        int e = n, m;
        while(s < e){
            m = s + (e-s) / 2;
            if(!isBadVersion(m)) {
                s = m + 1; 
            } 
            else{
                e = m;
            } 
        }
        return s;
    }
};