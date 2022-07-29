class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<vector<int>>pq;
        
        for(int &i:arr){
            pq.push({abs(i-x),i});
            if(pq.size()==k+1)
                pq.pop();
        }
        
        vector<int>res;
        
        while(pq.size()){
            res.push_back(pq.top()[1]);
            pq.pop();
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};