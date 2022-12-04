class Solution {
private:
    int solve(int n1, int n2, int ans = 0){
        if(n1 == 0 || n2 == 0) return ans;
        if(n1 >= n2) return solve(n1 - n2, n2, ans+1);
        else return solve(n1, n2-n1, ans+1);
    }
public:
    int countOperations(int n1, int n2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        return solve(n1,n2); 
    }
};