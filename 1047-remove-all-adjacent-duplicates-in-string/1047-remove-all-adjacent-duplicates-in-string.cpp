class Solution {
public:
    string removeDuplicates(string s) {
        int i=1,j=0;
        
        while(i<s.size()){
            if(j>=0 && s[i]==s[j])
                j--,i++;
            else{
                s[++j]=s[i++];
            }
        }
        
        return s.substr(0,j+1);
    }
};