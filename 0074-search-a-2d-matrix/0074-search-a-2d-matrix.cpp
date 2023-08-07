class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        int r=arr.size(),c=arr[0].size();
        
        int i=0,j=r*c-1;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            cout<<mid<<' ';
            if(arr[mid/c][mid%c]==tar)
                return true;
            else if(arr[mid/c][mid%c]>tar)
                j=mid-1;
            else
                i=mid+1;
        }
        
        return false;
    }
};