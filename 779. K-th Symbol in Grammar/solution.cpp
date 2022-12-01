class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case
        if(n == 0){
            return 0;
        }
        // Recursive call
        int parent = kthGrammar(n-1, (k / 2) + (k % 2));

        if(parent == 0){
            // Zero parent
            if(k % 2 == 0){
                // Even k
                return 1;
            }
            else{
                // Odd k
                return 0;
            }
        }
        else{
            //  1 parent
            if(k % 2 == 0){
                // Even k
                return 0;
            }
            else{
                // Odd k
                return 1;
            }
        }
    }
};