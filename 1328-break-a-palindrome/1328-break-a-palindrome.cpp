class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        if(s.size()==1)
            return "";
        int i=0;
        while(i<n/2){
            if(s[i]!='a'){
                s[i]='a';
                return s;
            }
            i++;
        }
        s.back()='b';
        return s;
    }
};