class Solution {
    public:
    bool canCross(vector<int>& arr) {
        if(arr.size()==1)
            return true;
        if(arr[1]!=1)
            return false;
        unordered_map<int,set<int>>m;
        m[1].insert(1);
        for(int i=2;i<arr.size();i++){
            m[arr[i]]={};
        }
        
        for(int i=1;i<arr.size();i++){
            int n=m[arr[i]].size();
            for(int k:m[arr[i]]){
                
                m[arr[i]+k].insert(k);
                
                m[arr[i]+k+1].insert(k+1);
                
                m[arr[i]+k-1].insert(k-1);
            }
        }
        
        return m[arr.back()].size()!=0;
    }
};