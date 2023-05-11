class Solution {
public:
    
    map<pair<int,int>,int>m;
    
    int rec(vector<int>&arr1, vector<int>&arr2,int i,int j){
        if(i==arr1.size() || j==arr2.size())
            return 0;
        
        if(m.find({i,j})!=m.end())
            return m[{i,j}];
        
        int temp=0;
        
        if(arr1[i]==arr2[j])
            temp=1+rec(arr1,arr2,i+1,j+1);
        temp=max(temp,rec(arr1,arr2,i+1,j));
        temp=max(temp,rec(arr1,arr2,i,j+1));
        
        return m[{i,j}]= temp;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return rec(nums1,nums2,0,0);
    }
};