class Solution {
public:
    string minWindow(string s, string t) {
        int cnt[256]={0};
        for(char &c:t){
            ++cnt[c];
        }
        int ii=1000000000,jj=0,len=0;
        
        for(int i=0,j=0;i<s.size();i++){
            if(cnt[s[i]]>0){
                len++;
            }
            --cnt[s[i]];
            
            
            while(len==t.size()){
                if(ii-jj>i-j){
                    ii=i,jj=j;
                }
                if(cnt[s[j]]==0)
                    len--;
                ++cnt[s[j]];
                ++j;
            }
        }
        
        return ii-jj>s.size()?"":s.substr(jj,ii-jj+1);
    }
};