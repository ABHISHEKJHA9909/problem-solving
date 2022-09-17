class Solution {
public:
    long long fun(vector<int>& arr,int x){
        long long  y=0;
        for( int &i:arr){
            y+=(1LL + i+x-2)/x;
        }
        return y;
    }
    
    int minEatingSpeed(vector<int>& arr, int h) {
        long long i=1,j=1e18;
        long long res=1e18;
        
        while(i<=j){
            long long mid=(i+j)/2;
            cout<<mid<<' ';
            if(fun(arr,mid)<=h){
                res=min(res,mid);
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        
        return res;
    }
};