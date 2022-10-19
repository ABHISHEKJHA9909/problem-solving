class compare{
    public:
    bool operator()(const pair<int,string> &a,const pair<int,string> &b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int >m;
        
        for(string s:words)
            m[s]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;
        
        for(auto [x,y]:m){
            pq.push({y,x});
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<string>res;
        
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};