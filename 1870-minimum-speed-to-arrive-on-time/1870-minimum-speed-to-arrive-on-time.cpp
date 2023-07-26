class Solution {
public:
    double fun(vector<int>& dist,double speed){
        double ans=0;
        for(int i=0;i<dist.size()-1;i++){
            ans+=ceil(dist[i]/speed);
        }
        ans += (double)dist.back()/speed;
        return ans;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= dist.size()-1)
            return -1;
        
        int i=1,j=INT_MAX;
        int res=0;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            // cout<<mid<<' '<<fun(dist,mid)<<endl;
            
            if(fun(dist,mid)<=hour){
                res=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        
        return res;
    }
};