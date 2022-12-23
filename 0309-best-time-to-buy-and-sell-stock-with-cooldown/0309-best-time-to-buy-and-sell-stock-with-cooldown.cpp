class Solution {
public:
    map<pair<int,int>,int>m;
    
    int rec(vector<int>& arr,int i,int curr){
        if(i>=arr.size())
            return 0;
        if(m.find({i,curr})!=m.end())
            return m[{i,curr}];
        
        if(curr>=arr[i])
            return rec(arr,i+1,arr[i]);
        
        return m[{i,curr}] = max(rec(arr,i+1,curr),arr[i]-curr+rec(arr,i+2,i+2<arr.size()?arr[i+2]:0));
        
    }
    
    int maxProfit(vector<int>& prices) {
        return rec(prices,0,prices[0]);
    }
};