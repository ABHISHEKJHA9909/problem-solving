class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        int n=c.size();
        vector<int>diff(n);
        
        for(int i=0;i<n;i++){
            diff[i]=c[i]-r[i];
        }
        
        sort(diff.begin(),diff.end());
        
        
        int res=0;
        for(int &i:diff){
            a-=i;
            if(a>=0)
                res++;
            else
                break;
        }
        
        return res;
    }
};