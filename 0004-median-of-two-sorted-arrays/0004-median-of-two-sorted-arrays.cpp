class Solution {
public:
    int n,m;
    
    double get(vector<int>& nums1,vector<int>& nums2,int k){
        int i=0,j=0;
        
        while(i<n && j<m){
            if(k==0){
                return nums1[i]<nums2[j]?nums1[i]:nums2[j];
            }
            if(nums1[i]<nums2[j])
                i++;
            else
                j++;
            k--;
        }
        
        return i==n?(nums2[j+k]):nums1[i+k];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size(),m=nums2.size();
        
        if((n+m)&1)
            return get(nums1,nums2,(n+m)/2);
        return (get(nums1,nums2,(n+m)/2) +get(nums1,nums2,(n+m-1)/2))/2;
    }
};