class Solution {
public:
    int jump(vector<int>& arr) {
        if(arr.size()==1)
            return 0;
        int res=0,n=arr.size();
        int mx=0+arr[0],jj;                                            
        
        for(int i=0;mx<n-1;){
            for(int j=1;j<=arr[i];j++){
                if(i+j<n && mx<i+j+arr[i+j]){
                    mx=i+j+arr[i+j];
                    jj=i+j;
                }
            }
            i=jj;
            res++;
        }
        
        return ++res;
    }
};