class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int cnt[26]={0};
        
        for(string s:words2){
            int cnt2[26]={0};
            
            for(char c:s){
                cnt2[c-'a']++;
            }
            
            for(int i=0;i<26;i++){
                cnt[i]=max(cnt[i],cnt2[i]);
            }
        }
        
        vector<string>res;
        
        for(int i=0;i<words1.size();i++){
            int cnt2[26]={0};
            for(char c:words1[i]){
                cnt2[c-'a']++;
            }
            
            bool b=true;
            for(int i=0;i<26;i++){
                if(cnt[i]>cnt2[i]){
                    b=false;
                    break;
                }
            }
            
            if(b==true)
                res.push_back(words1[i]);
        }
        
        return res;
    }
};