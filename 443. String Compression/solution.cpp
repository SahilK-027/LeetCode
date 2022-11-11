class Solution {
public:
    int compress(vector<char>& chars) {
        int ans_index=0;
        int i=0;
        while(i<chars.size())
        {
            int j=i+1;
            while(j<chars.size() && chars[j]==chars[i]){
                j++;
            }
            //We will come out of this while loop when 
            //We have traversed the complete vector
            // OR J is pointing to different element
            
            //Store the old character
            chars[ans_index] = chars[i];
            ans_index++; 
            
            int count = j-i; // i is first occurace and j is (last+1) th occurance
            if(count > 1)
            {
                //We have to add count by converting it into single single digit
                
                string cnt=to_string(count); 
                //converting counting into single digit
                for(int i=0;i<cnt.length();i++)
                {
                    chars[ans_index]=cnt[i];
                    ans_index++;
                }
            }
            
            
            i=j;//->Our job for 1st character is done now proceed further
        }
        return ans_index;
    }
};