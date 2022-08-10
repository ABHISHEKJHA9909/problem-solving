class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        pair<int,int> arr[20][20]={};
        
        for(int i=0;i<n;i++){
            arr[0][i]={nums[i],0};
        }
        
        for(int i=1;i<n;i++){
            for(int j=i;j<n;j++){
                pair<int,int>p1={nums[j]+arr[i-1][j-1].second,arr[i-1][j-1].first};
                pair<int,int>p2={nums[j-i]+arr[i-1][j].second,arr[i-1][j].first};
                arr[i][j]=max(p1,p2);
            }
        }
        return arr[n-1][n-1].first>=arr[n-1][n-1].second;
    }
};