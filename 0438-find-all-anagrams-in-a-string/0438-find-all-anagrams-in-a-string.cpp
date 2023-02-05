class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int cnt[256]={0};
        
        for(char &c:p)
            ++cnt[c];
        
        vector<int>res;
        
        for(int i=0,l=0,j=0,n=s.size();i<n;i++){
            if(--cnt[s[i]]==-1){
                while(++cnt[s[j++]]!=0){
                    --l;
                }
            }
            else
                l++;
            // cout<<i<<' '<<l<<endl;
            
            if(l==p.size()){
                res.push_back(j);
            }
        }
        
        return res;
    }
};