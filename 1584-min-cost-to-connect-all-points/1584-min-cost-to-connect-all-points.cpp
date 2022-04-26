class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n=arr.size();
        
        int c=0,res=0;
        priority_queue<pair<int,int>>pq;
        int i=0;
        
        vector<int>vis(n,0);
        
        while(++c<n){
            vis[i]=1;
            for(int j=0;j<n;j++){
                if(vis[j]==0)
                    pq.push({-(abs(arr[i][0]-arr[j][0])+abs(arr[i][1]-arr[j][1])),j});
            }
            while(vis[pq.top().second])
                pq.pop();
            
            res-=pq.top().first;
            i=pq.top().second;
            pq.pop();
        }
        
        return res;
    }
};