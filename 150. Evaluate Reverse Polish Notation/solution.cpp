/*
27 ms
12.2 mb
*/

/**
 * @author : SahilK-027
 * @brief : Stack
*/

class Solution {
private:
    long long int solve(long long int n1, long long int n2, long long int op)
    {
        long long int ans = 0;
        switch(op){
            // Multiply
            case 42:
                ans = n1 * n2;
                break;
            // Add
            case 43:
                ans = n1 + n2;
                break;
            // Subtract
            case 45:
                ans = n1 - n2;
                break;
            // Divide
            case 47:
                ans = n1 / n2;
                break;
        }
        return ans;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        int ans = 0;
        for(auto i: tokens){
            if(i.length() == 1 && (i[0] == '+' || i[0] == '-' || i[0] == '*' || i[0] == '/')){
                // Got operator
                int op = int(i[0]);
                long long int num1 = st.top();
                st.pop();
                long long int num2 = st.top();
                st.pop();
                long long int result = solve(num2, num1, op);
                cout<<result<<endl;
                st.push(result);
            }
            else{
                // Got number
                long long int ele = stoi(i);
                st.push(ele);
            }
        }
        ans = st.top();
        return ans;
    }
};