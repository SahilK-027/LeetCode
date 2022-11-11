class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
            array<int,26> a1={0};
            array<int,26> a2={0};
            for(int i=0;i<ransomNote.length();i++)
                a1[int(ransomNote[i]-'a')]++;
            for(int i=0;i<magazine.length();i++)
                a2[int(magazine[i]-'a')]++;
            for(int i=0;i<26;i++){
                if(a1[i]==0)
                    continue;
                else if(a2[i]<a1[i])
                    return false;
            }
            return true;
        }
};