class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<vector<int>>diff;
        
        for(int &i:arr){
            diff.push_back({abs(i-x),i});
        }
        
        sort(diff.begin(),diff.end());
        
        vector<int>res;
        
        for(int i=0;i<k;i++)
            res.push_back(diff[i][1]);
        
        sort(res.begin(),res.end());
        return res;
    }
};