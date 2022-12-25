class Solution {
public:
    vector<int> answerQueries(vector<int>& arr, vector<int>& q) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        
        vector<int>res;
        
        for(int &x:q){
            res.push_back(lower_bound(arr.begin(),arr.end(),x+1)-arr.begin());
        }
        
        return res;
    }
};