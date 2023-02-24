class Solution {
public:
    int numTeams(vector<int>& arr) {
        unordered_map<int,int>m;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j])
                    cnt++;
            }
            m[i]=cnt;
        }
        
        int res=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j])
                    res+=m[j];
            }
        }
        
        m.clear();
        
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j])
                    cnt++;
            }
            m[i]=cnt;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j])
                    res+=m[j];
            }
        }
        
        return res;
    }
};