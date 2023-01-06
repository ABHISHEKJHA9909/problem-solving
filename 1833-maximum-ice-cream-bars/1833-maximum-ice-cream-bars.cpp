class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        for(int i=0,n=costs.size();i<n;i++){
            if(coins<costs[i])
                return i;
            coins-=costs[i];
        }
        return costs.size();
    }
};