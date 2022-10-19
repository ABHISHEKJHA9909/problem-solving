
bool comp(pair<int,string> &a,pair<int,string> &b){
    if(a.first!=b.first)
        return a.first>b.first;
    return a.second<b.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int >m;
        
        for(string s:words)
            m[s]++;
        
        vector<pair<int,string>>v;
        for(auto &[x,y]:m){
            v.push_back({y,x});
        }
        sort(v.begin(),v.end(),comp);
        
        vector<string>res;
        for(int i=0;i<k;i++)
            res.push_back(v[i].second);
        
        return res;
    }
};