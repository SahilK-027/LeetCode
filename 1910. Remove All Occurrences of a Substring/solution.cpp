class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
//Initially as there will be at least one substring we will make count 1
        int count=1; 
        while(s.length()!=0 && count == 1)
        {
            count = 0;
            if(s.find(part)<s.length())
            {
                count++;        //If part find in string
                s.erase(s.find(part),part.length()); //erase it
            }
            else{
                break; //if part not found break;
            }
        }                 
        return s;
    }
};