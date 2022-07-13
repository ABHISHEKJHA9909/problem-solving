class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<int,int>cnt;
        int res=0;
        
        for(int i=0,j=0;i<n;i++){
            if(++cnt[s[i]-'a']==2){
                while(--cnt[s[j++]-'a']!=1);
            }
            
            res=max(res,i-j+1);
        }
        
        return res;
    }
};