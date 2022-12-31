/*
6 ms
6.2 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution + Memoization
*/

class Solution {
public:
    int fibo(int n, vector<int> &arr) {
        if(n < 2)
        return n;
        if(arr[n] != -1)
        return arr[n];
        int answer = fibo(n-1, arr) + fibo(n-2, arr);
        arr[n] = answer;
        return answer;
    }

    int fib(int n) {
        vector<int> arr(n+1, -1);
        return fibo(n, arr);
    }
};
