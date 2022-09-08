class Solution {
public:
    
    void nll(vector<int>&arr,int n,int* left){
        stack<int>s;
        for(int i=0;i<n;i++){
            while(s.size() && arr[s.top()]>=arr[i])
                s.pop();
            left[i]=s.size()?s.top():-1;
            s.push(i);
        }
    }
    
    
    void nlr(vector<int>&arr,int n,int *right){
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(s.size() && arr[s.top()]>=arr[i])
                s.pop();
            right[i]=s.size()?s.top():n;
            s.push(i);
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