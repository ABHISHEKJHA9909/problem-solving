#define ll long long 
class Solution {
public:
    int maximumRobots(vector<int>& c, vector<int>& r, long long b) {
        
        priority_queue<pair<int,int>>pq;
        
        long long sum=0;
        int j=-1,n=c.size(),res=0;
        
        for(int i=0;i<n;i++){
            sum+=r[i];
            pq.push({c[i],i});
            while(1LL*rem(pq,j)+sum*(i-j)>b){
                sum-=r[++j];
            }
            res=max(res,(i-j));
        }
        
        return res;
    }
    
    int rem(priority_queue<pair<int,int>>&pq,int &j){
        while(pq.size() && pq.top().second<=j){
            pq.pop();
        }
        return pq.size()?pq.top().first:0;
    }
};