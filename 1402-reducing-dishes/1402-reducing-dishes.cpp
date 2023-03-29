class Solution {
public:
    map<pair<int,int>,int>m;
    
    int rec(int i,int time,vector<int>& arr){
        if(i==arr.size())
            return 0;
        if(m.find({i,time})!=m.end())
            return m[{i,time}];
        return m[{i,time}]=max(time*arr[i] +rec(i+1,time+1,arr),rec(i+1,time,arr));
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return rec(0,1,satisfaction);
    }
};