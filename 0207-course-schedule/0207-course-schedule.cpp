class Solution {
public:
    
    bool dfs(int i,vector<int> *arr,vector<int>& vis){
        if(vis[i]==1)
            return false;
        if(vis[i]==2)
            return true;
        
        vis[i]=1;
        for(int &j:arr[i]){
            if(!dfs(j,arr,vis))
                return false;
        }
        
        vis[i]=2;
        
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& brr) {
        vector<int> arr[n];
        for(auto &x:brr){
            arr[x[0]].push_back(x[1]);
        }
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!dfs(i,arr,vis))
                return false;
        }
        
        return true;
    }
};