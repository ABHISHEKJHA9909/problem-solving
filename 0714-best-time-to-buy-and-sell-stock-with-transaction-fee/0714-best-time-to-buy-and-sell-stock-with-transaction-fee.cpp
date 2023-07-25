class Solution {
public:
    map<pair<int,int>,int>m;
    
    int rec(int i,bool canBuy,int fee,vector<int>& arr){
        if(i==arr.size())
            return 0;
        if(m.find({i,canBuy})!=m.end())
            return m[{i,canBuy}];
        int idle=rec(i+1,canBuy,fee,arr);
        
        if(canBuy){
            int buy=-arr[i]+rec(i+1,!canBuy,fee,arr);
            return m[{i,canBuy}]=max(idle,buy);
        }
        else{
            int sell=+arr[i]-fee+rec(i+1,!canBuy,fee,arr);
            return m[{i,canBuy}]=max(idle,sell);
        }
        
        return 0;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        return rec(0,true,fee,prices);
    }
};

/**

y=max(y,x-i-fee)
x=max(x,y+i)

    1 ,  3,  7,  5,  10,  3
y  -4   -4  -4  -4   -2               
x   0    0   3   4   6           

**/