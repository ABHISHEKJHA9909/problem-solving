class Solution {
public:
    int n;
    map<pair<int,int>,int>m;
    int MOD=1000000007;
    
    int res(vector<int> &arr,int i,int j,int fuel){
        if(m.find({i,fuel})!=m.end())
            return m[{i,fuel}];
        int sum=0;
        if(i==j){
            sum++;
        }
        
        // if(fuel<=0)
        //     return sum;
        
        for(int k=0;k<n;k++){
            if(i==k)
                continue;
            if(abs(arr[i]-arr[k])<=fuel){
                sum+=res(arr,k,j,fuel-abs(arr[i]-arr[k]));
                sum%=MOD;
            }
        }
        
        return m[{i,fuel}]=sum;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n=locations.size();
        return res(locations,start,finish,fuel);
    }
};