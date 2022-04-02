class Solution {
public:
    bool isp(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return 0;
            i++,j--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        if(isp(s))
            return true;
        
        int i=0,j=s.size()-1;
        while(i<j && s[i]==s[j]){
            i++,j--;
        }
        
        if(isp(s.substr(i,j-i))||isp(s.substr(i+1,j-i)))
            return true;
        return false;
    }
};