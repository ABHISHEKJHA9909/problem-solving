class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        auto i=g.begin(),j=s.begin();
        int ans=0;
        while(i!=g.end() && j!=s.end()){
            if(*i<=*j)
                ++i,++j,++ans;
            else if(*i>*j)
                j++;
        }
        return ans;
    }
};