class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        
        pair<double,double> arr[n];
        for(int i=0;i<n;i++){
            arr[i].first=position[i];
            arr[i].second=speed[i];
        }
        sort(arr,arr+n);
        
        double time[n];
        for(int i=0;i<n;i++){
            time[i]=(double)(target-arr[i].first)/(double)arr[i].second;
        }
        
        int res=1;
        
        double prev=time[n-1];
        
        for(int i=n-2;i>=0;i--){
            if(time[i]<=prev)
                continue;
            prev=time[i];
            res++;
        }
        
        return res;
    }
};