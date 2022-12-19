class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<int> arr[n];
        
        for(auto &i:edges){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        
        queue<int>q;
        q.push(s);
        
        vector<int>vis(n,0);
        vis[s]=1;
        
        while(q.size()){
            int x=q.front(); q.pop();
            if(x==d)
                return true;
            for(int &j:arr[x]){
                if(vis[j]==0){
                    vis[j]=1;
                    q.push(j);
                }
            }
            
        }
        
        return false;
    }
};