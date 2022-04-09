class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int>m;
        int res=0;
        for(int i=0,n=arr.size();i<n;i++){
            int t=target-arr[i];
            for(int j=i+1;j<n;j++){
                if(m.find(t-arr[j])!=m.end())
                    res+=m[t-arr[j]];
                res%=1000000007;
            }
            m[arr[i]]++;
        }
        
        return res;
    }
};