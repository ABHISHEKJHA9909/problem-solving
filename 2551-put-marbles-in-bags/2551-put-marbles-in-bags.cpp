class Solution {
public:
    long long putMarbles(vector<int>& arr, int k) {
        priority_queue<int>mx,mn;
        
        for(int i=0;i<arr.size()-1;i++){
            mx.push(arr[i]+arr[i+1]);
            mn.push(-(arr[i]+arr[i+1]));
            if(mx.size()==k)
                mx.pop(),mn.pop();
        }
        
        long long a=0,b=0;
        while(mx.size())
            a+=mx.top(),mx.pop();
        
        while(mn.size())
            b-=mn.top(),mn.pop();
        
        return b-a;
    }
};