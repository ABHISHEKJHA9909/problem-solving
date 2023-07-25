class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int i=1,j=arr.size()-2,res=-1,curr_max;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]<arr[mid+1]){
                res=mid+1;
                i=mid+1;
            }
            else{
                res=mid;
                j=mid-1;
            }
        }
        
        return res;
    }
};