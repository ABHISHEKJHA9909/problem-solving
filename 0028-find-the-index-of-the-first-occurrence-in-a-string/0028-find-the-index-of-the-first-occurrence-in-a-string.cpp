class Solution {
public:
    int strStr(string s, string t) {
        int n=s.size(),m=t.size();
        
        for(int i=0;(n-i)>=m;i++){
            int j=0,k=i;
            while(j<m && s[k]==t[j])
                j++,k++;
            if(j==m)
                return i;
        }
        
        return -1;
    }
};