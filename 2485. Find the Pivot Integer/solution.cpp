class Solution {
private:
    int findSumLeft(int num){
        int sum = 0;
        for(int i = 1; i<= num; i++){
            sum += i;
        }
        return sum;
    }
    int findSumRight(int num, int n){
        int sum = 0;
        for(int i = num; i<= n; i++){
            sum += i;
        }
        return sum;
    }
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        int i = 2;
        while(i < n){
            int leftAns = findSumLeft(i);
            int rightAns = findSumRight(i,n);
            if(leftAns == rightAns) 
            {
                return i;
            }
            else 
                i++;
        }
        return -1;
    }
};