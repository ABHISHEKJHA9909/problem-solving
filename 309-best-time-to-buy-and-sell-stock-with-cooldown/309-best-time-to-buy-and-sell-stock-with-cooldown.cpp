class Solution {
public:
    map<pair<int,int>,int>m;
    int rec(vector<int>&arr,int i,int p){
        if(i>=arr.size())
            return 0;
        
        if(m.find({i,p})!=m.end())
            return m[{i,p}];
        
        int sell=0,notsell=0;
        
        if(arr[i]>p)
            sell= arr[i]-p+rec(arr,i+2,i+2<arr.size()?arr[i+2]:-1);
        notsell=rec(arr,i+1,min(p,(i+1<arr.size()?arr[i+1]:INT_MAX))) ;
        return m[{i,p}]=max(sell,notsell);
    }
    
    int maxProfit(vector<int>& prices) {
        return rec(prices,0,prices[0]);
    }
};