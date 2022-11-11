class Solution {
private:
    int isOdd(int num){
        if(num % 2 != 0){
            return 1;
        }
        return 0;
    }
public:
    int countOdds(int low, int high) {
        if(isOdd(low)){
            low = low - 1;
        }
        if(isOdd(high)){
            high = high + 1;
        }
        return (high - low) /2;
    }
};