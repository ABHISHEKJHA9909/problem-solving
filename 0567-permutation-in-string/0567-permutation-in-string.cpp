class Solution {
public:
    bool checkInclusion(string t, string s) {
        int n=t.size();
        int cnt[256]={0};
        
        for(char &c:t)
            ++cnt[c];
        
        for(int i=0,j=0,len=0,m=s.size();i<m;i++){
            --cnt[s[i]];
            ++len;
            
            if(cnt[s[i]]==-1){
                do{
                    --len;
                }
                while(++cnt[s[j++]]!=0);
            }
            // cout<<i<<' '<<len<<endl;
            if(len==n)
                return true;
        }
        
        return false;
    }
};