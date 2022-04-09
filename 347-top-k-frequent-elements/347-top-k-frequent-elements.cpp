class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int &i:nums){
            m[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:m){
            pq.push({-i.second,i.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> res;
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};