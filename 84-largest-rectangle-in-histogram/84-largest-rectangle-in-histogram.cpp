class Solution {
public:
    
    void nll(vector<int>&arr,int n,int* left){
        int j;
        for(int i=0;i<n;i++){
            j=i-1;
            while(j>=0 && arr[j]>=arr[i])
                j=left[j];
            left[i]=j;
        }
    }
    
    
    void nlr(vector<int>&arr,int n,int *right){
        int j;
        for(int i=n-1;i>=0;i--){
            j=i+1;
            while(j<n && arr[j]>=arr[i])
                j=right[j];
            right[i]=j;
        }
    }                                           
    
    int largestRectangleArea(vector<int>& arr) {
        int const  n=arr.size();
        int left[n];
        nll(arr,n,left);
        int right[n];
        nlr(arr,n,right);
        
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,(right[i]-left[i]-1)*(arr[i]));
        }
        return res;
    }
};