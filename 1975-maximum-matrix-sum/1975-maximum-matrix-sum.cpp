class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int neg=0,s=0,mini=INT_MAX;
        for(auto &i:matrix){
            for(int &j:i){
                if(j<0)
                    neg++;
                s+=abs(j);
                mini=min(mini,(long long)abs(j));
            }
        }
        cout<<s<<' '<<neg<<' '<<mini<<endl;
        if(neg&1)
            return s-2*mini;
        return s;
    }
};