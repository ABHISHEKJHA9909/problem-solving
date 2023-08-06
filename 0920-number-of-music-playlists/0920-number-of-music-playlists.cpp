class Solution {
public:
    const  int mod=1000000007;
    
    int rec(int goal,long long old,int k,int n,map<pair<int,int>,int> &m){
        if(goal==0 and old==n)
            return 1;
        if(goal==0 or old>n)
            return 0;
        
        pair<int,int>curr={goal,old};
        
        if(m.find(curr)!=m.end())
            return m[curr];
        
        
        int res=0;
        res=((long long)(n-old)*rec(goal-1,old+1,k,n,m))%mod;
        
        if(old>k)
            res+=((long long)(old-k)*rec(goal-1,old,k,n,m))%mod;
        
        return m[curr]=res;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        map<pair<int,int>,int>m;
        return rec(goal,0,k,n,m);
    }
};