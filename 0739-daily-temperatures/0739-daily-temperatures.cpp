class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int>s;
        vector<int>res(arr.size());
        
        for(int i=arr.size()-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]<=arr[i])
                s.pop();
            if(s.empty())
                res[i]=0;
            else
                res[i]=s.top()-i;
            s.push(i);
        }
        
        return res;
    }
};