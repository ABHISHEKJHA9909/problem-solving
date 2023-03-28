class Solution {
public:
    
    int d[3]={1,7,30};
    
    map<pair<int,int>,int>m;
    
    int rec(int i,int day,vector<int>& days,vector<int>& costs){
        while(i<days.size() && days[i]<day)
            i++;
        if(i>=days.size())
            return 0;
        if(m.find({i,day})!=m.end())
            return m[{i,day}];
        int res=INT_MAX;
        
        for(int j=0 ;j<3;j++){
            res=min(res,costs[j]+rec(i,days[i]+d[j],days,costs));
        }
        
        return m[{i,day}]=res;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return rec(0,1,days,costs);
    }
};