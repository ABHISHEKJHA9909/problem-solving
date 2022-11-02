class Solution {
public:
    unordered_map<string,vector<string>>m;
    unordered_map<string,bool>vis;
    int res=INT_MAX;
    
    int change(string &start,string &end){
        int cnt=0;
        for(int i=0;i<8;i++){
            if(start[i]!=end[i])
                cnt++;
        }
        return cnt;
    }
    
    void dfs(string start,string end,int curr){
        if(start==end){
            res=min(res,curr);
        }
        vis[start]=true;
        for(string &t:m[start]){
            if(vis[t]==true)
                continue;
            dfs(t,end,curr+1);
        }
        vis[start]=false;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        
        for(int i=0,n=bank.size();i<n;i++){
            vis[bank[i]]=false;
            for(int j=i+1;j<n;j++){
                if(change(bank[i],bank[j])==1){
                    m[bank[i]].push_back(bank[j]);
                    m[bank[j]].push_back(bank[i]);
                }
            }
        }
        
        if(m.find(start)==m.end()){
            for(string &s:bank){
                if(change(start,s)==1){
                    m[start].push_back(s);
                    m[s].push_back(start);
                }
            }
        }
        
        dfs(start,end,0);
        
        return res==INT_MAX?-1:res;
    }
};