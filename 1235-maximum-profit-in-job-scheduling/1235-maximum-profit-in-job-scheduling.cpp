class Solution {
public:
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n=s.size();
        
        vector<int> arr[n];
        for(int i=0;i<n;i++){
            arr[i]={e[i],s[i],p[i]};
        }
        sort(arr,arr+n);
        map<int,int>m={{0,0}};
        
        for(auto i:arr){
            int cur=prev(m.upper_bound(i[1]))->second+i[2];
            if(cur>m.rbegin()->second)
                m[i[0]]=cur;
        }
        
        return m.rbegin()->second;
    }
};