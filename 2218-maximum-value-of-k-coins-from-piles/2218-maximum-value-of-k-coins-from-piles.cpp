class Solution {
public:
    int n;
    vector<int>brr;
    map<pair<int,int>,int>m;
    
    
    int rec(int i,vector<vector<int>>& arr,int k){
        if(k==0||i==n)
            return 0;
        
        pair<int,int>key={i,k};
        if(m.find(key)!=m.end())
            return m[key];
        
        int res=0;
        res=max(res,rec(i+1,arr,k));
        
        for(int j=0,s=0,m=arr[i].size();j<m && k--;j++){
            s+=arr[i][j];
            res=max(res,s+rec(i+1,arr,k));
        }
        
        return m[key]=res;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        brr=vector<int>(n+2,0);
        return rec(0,piles,k);
    }
};