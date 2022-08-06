class Solution {
public:
    long long taskSchedulerII(vector<int>& arr, int s) {
        unordered_map<long long ,long long >m;
        long long res=0,cnt=0;
        
        for(int i=0;i<arr.size();i++){
            long long curr=i+cnt;
            if(m.find(arr[i])!=m.end() && curr-m[arr[i]]-1<s){
                res+=s-(curr-m[arr[i]]-1);
                cnt+=s-(curr-m[arr[i]]-1);
            }
            m[arr[i]]=i+cnt;
        }
        
        return res+arr.size();
    }
};