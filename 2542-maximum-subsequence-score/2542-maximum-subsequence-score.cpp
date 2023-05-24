class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int,int>>arr;
        int n=nums1.size();
        
        for(int i=0;i<n;i++){
            arr.push_back({nums2[i],nums1[i]});
        }
        
        sort(arr.begin(),arr.end());
        
        long long res=0,sum=0;
        priority_queue<int>pq;
        
        for(int i=n-1;i>=0;i--){
            pq.push(-arr[i].second);
            sum+=arr[i].second;
            if(pq.size()>k){
                sum+=pq.top();
                pq.pop();
                res=max(res,sum*arr[i].first);
            }
            else if(pq.size()==k){
                res=sum*arr[i].first;
            }
        }
        
        return res;
    }
};