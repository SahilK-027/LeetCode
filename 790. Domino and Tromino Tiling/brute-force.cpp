// Recursive solution
// TC : O(2^n)
// Recursive Solution
class Solution {
private:
    long long solve(int n){
        if(n <= 2){
            return n;
        }
        if(n == 3){
            return 5;
        }
        long long ans =  (2 * solve(n-1) + solve(n-3)) % 1000000007;
        return ans ;
    }
public:
    int numTilings(int n) {
        return solve(n) / 1ll;
    }
};