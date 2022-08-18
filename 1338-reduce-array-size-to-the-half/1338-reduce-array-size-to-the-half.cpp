class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i:arr){
            m[i]++;
        }
        
        unordered_map<int,int>mp;
        for(auto [x,y]:m){
            mp[y]++;
        }
        
        vector<pair<int,int>>v;
        for(auto [x,y]:mp){
            v.push_back({x,y});
        }
        
        sort(v.begin(),v.end());
        int res=0,curr=0;
        
        for(int i=v.size()-1;i>=0;i--){
            int need=arr.size()/2-res;
            if(v[i].first*v[i].second<need){
                res+=(v[i].first*v[i].second);
                curr+=v[i].second;
            }
            else{
                curr+=(need+v[i].first-1)/v[i].first;
                break;
            }
        }
        return curr;
    }
};