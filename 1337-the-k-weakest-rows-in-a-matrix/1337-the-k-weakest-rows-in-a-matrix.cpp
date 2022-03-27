class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;
        
        for(int i=0,r=mat.size(),c=mat[0].size();i<r;i++){
            
            int curr=0;
            for(int j=0;j<c;j++){
                if(mat[i][j]==1)
                    curr++;
            }
            pq.push({curr,i});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>res;
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};