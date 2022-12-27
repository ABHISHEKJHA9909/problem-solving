class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        int n=c.size();
        for(int i=0;i<n;i++){
            c[i]-=r[i];
        }
        
        sort(c.begin(),c.end());
        
        
        int res=0;
        for(int &i:c){
            a-=i;
            if(a>=0)
                res++;
            else
                break;
        }
        
        return res;
    }
};