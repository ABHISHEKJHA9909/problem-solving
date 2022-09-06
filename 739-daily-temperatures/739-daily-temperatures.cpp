class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        
        vector<int>res(n);
        stack<int>s;
        
        for(int i=n-1;i>=0;i--){
            while(s.size() && arr[s.top()]<=arr[i])
                s.pop();
            res[i]=s.size()?s.top()-i:0;
            s.push(i);
        }
        
        return res;
    }
};