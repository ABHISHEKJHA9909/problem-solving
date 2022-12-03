class Solution {
public:
    int cnt[256];
    
    string frequencySort(string s) {
        for(char &c:s){
            cnt[c]++;
        }
        
        sort(s.begin(),s.end(),[this](char a,char b){
            if(cnt[a]==cnt[b])
                return a>b;
            return cnt[a]>cnt[b];
        });
        
        return s;
    }
};