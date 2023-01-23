class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>arr(n+1,0);
        
        for(auto &i:trust){
            arr[i[0]]--;
            arr[i[1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(arr[i+1]==n-1)
                return i+1;
        }
        
        return -1;
    }
};