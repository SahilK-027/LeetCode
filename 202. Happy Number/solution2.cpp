class Solution {
public:
    int recursion (vector<int> &arr,int n,int cnt)
{
     int sum=0;
     if(n==1&&cnt==1)
    {
        
        return 1;
    }
   
    for(int i=0;i<arr.size();i++)
    {
        if(n==arr[i])
        {
            return 0;
        }
        
    }
    arr.push_back(n);
   
    cnt=0;
    while(n)
    {
  
    int a=n%10;
    sum+=a*a;
    n=n/10;
    cnt++;
    }       
return recursion(arr,sum,cnt);
}

    bool isHappy(int n) {
        vector <int> arr;
        if(recursion(arr,n,1))
        {
            return true;
        }
        else
        {
            return false;
        }
        

        
    }
};
