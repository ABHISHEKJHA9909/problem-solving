class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int s=0;
        for(int i=1,n=arr.size();i<=n;i+=2){
            int curr=0;
            for(int j=0,k=0;j<n;j++){
                if(j-k+1<i){
                    curr+=arr[j];
                }
                else if(j-k+1==i){
                    curr+=arr[j];
                    s+=curr;
                    // cout<<curr<<' ';
                }
                else{
                    curr+=arr[j];
                    curr-=arr[k++];
                    s+=curr;
                    // cout<<curr<<' ';
                }
            }
            // cout<<endl;
        }
        return s;
    }
};