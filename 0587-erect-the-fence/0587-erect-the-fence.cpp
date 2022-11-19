class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]<b[0])
            return true;
        else if(a[0]==b[0] && a[1]<b[1])
            return true;
        return false;
    }
    
    static bool cw(vector<int>&a ,vector<int>&b ,vector<int>&c ){
        return (c[1]-b[1])*(b[0]-a[0])-(b[1]-a[1])*(c[0]-b[0])>=0;
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>>res;
        int n=trees.size();
        
        sort(trees.begin(),trees.end(),comp);
        
        for(int i=0;i<n;i++){
            while(res.size()>1 && !cw(res[res.size()-2],res[res.size()-1],trees[i]))
                res.pop_back();
            res.push_back(trees[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(res.size()>1 && !cw(res[res.size()-2],res[res.size()-1],trees[i])==true)
                res.pop_back();
            res.push_back(trees[i]);
        }
        // res.pop_back();
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};