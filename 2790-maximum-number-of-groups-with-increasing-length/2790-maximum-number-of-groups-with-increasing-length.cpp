class Solution {
public:
    int maxIncreasingGroups(vector<int>& arr) {
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        long long sum=0,cnt=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>=(cnt+1)*(cnt+2)/2)
                cnt++;
        }
        
        return cnt;
    }
};