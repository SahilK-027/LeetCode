class Solution {
public:
    int subtractProductAndSum(int n) {
       int product=1,sum=0;
        
        while(n)
        {
         int mod=n%10;                 //Getting the units place of the number
            product=product*mod;
            sum=sum+mod;
          n=n/10;                      //Getting the remaining digits except the units place of the number
        }
        return (product-sum);
    }
};
