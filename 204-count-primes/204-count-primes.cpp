class Solution {
public:
    int arr[5000005];
    
    int countPrimes(int n) {
        int res=0;
        
        for(int i=2;i*i<=n;i++){
            if(arr[i]==0){
                for(int j=2*i;j<=n;j+=i){
                    arr[j]=1;
                }
            }
        }
        
        for(int i=2;i<n;i++){
            if(arr[i]==0)
                res++;
        }
        
        return res;
    }
};