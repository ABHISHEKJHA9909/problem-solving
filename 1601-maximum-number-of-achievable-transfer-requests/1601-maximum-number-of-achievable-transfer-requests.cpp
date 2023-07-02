class Solution {
public:
    int n;
    vector<int>net;
    int res=0;
    
    void rec(int i, vector<vector<int>>& arr,int k){
        if(i==n){
            for(int &j:net){
                if(j!=0)
                    return;
            }
            res=max(res,k);
            return;
        }
        
        rec(i+1,arr,k);
        
        net[arr[i][0]]-=1;
        net[arr[i][1]]+=1;
        rec(i+1,arr,k+1);
        net[arr[i][0]]+=1;
        net[arr[i][1]]-=1;
    }
    
    int maximumRequests(int n, vector<vector<int>>& arr) {
        net=vector<int>(n,0);
        this->n=n;
        int k=arr.size();
         // rec(0,requests,0);
        
        for(int i=1;i<(1<<k);i++){
            int curr=0;
            fill(net.begin(),net.end(),0);
            for(int j=i,ind=0 ; j ; j>>=1,ind++){
                if(j&1){
                    ++net[arr[ind][0]];
                    --net[arr[ind][1]];
                    curr++;
                }
            }
            bool b=true;
            for(int i=0;i<n;i++){
                if(net[i]!=0){
                    b=false;
                    break;
                }
            }
            if(b){
                res=max(res,curr);
            } 
        }
        
        return res;
    }
};