class Solution {
public:
    
    void func(vector<int>& res,int num,int rem,int& k){
        if(rem==0){
            res.push_back(num);
            return;
        }
        int prev=num%10;
        
        if(prev+k<10)
            func(res,num*10+prev+k,rem-1,k);
        if(prev-k!=prev+k && prev-k>-1)
            func(res,num*10+prev-k,rem-1,k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>res;
        
        for(int i=1;i<=9;i++){
            func(res,i,n-1,k);
        }
        
        return res;
    }
};