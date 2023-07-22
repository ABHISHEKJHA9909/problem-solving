class Solution {
public:
    int dir[8][2]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    
    double rec(int i,int j,int n,int k,unordered_map<string,double>&m){
        if(i<0||i>=n||j<0||j>=n)
            return 0;
        if(k==0)
            return 1;
        string s=to_string(i)+" "+to_string(j)+" "+to_string(k);
        if(m.find(s)!=m.end())
            return m[s];
        double res=0;
        for(auto &p:dir){
            res+=rec(i+p[0],j+p[1],n,k-1,m);
        }
        return m[s]=res/8;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        unordered_map<string,double>m;
        return rec(row,column,n,k,m);
    }
};