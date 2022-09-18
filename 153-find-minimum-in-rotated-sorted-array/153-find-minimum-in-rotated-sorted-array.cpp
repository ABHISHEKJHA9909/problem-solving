class Solution {
public:
    int findMin(vector<int>& arr) {
        int i=0,j=arr.size()-1,res=INT_MAX;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            res=min(res,arr[mid]);
            
            if(arr[i]<=arr[mid]){
                if(arr[mid]>arr[j])
                    i=mid+1;
                else
                    j=mid-1;
            }
            else{
                j=mid-1;
            }
        }
        
        return res;
    }
};