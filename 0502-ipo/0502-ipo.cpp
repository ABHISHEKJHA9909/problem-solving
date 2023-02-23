class Solution {
public:
    bool static comp(pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;
    }
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=0;i<profits.size();i++){
            pq.push({capital[i],profits[i]});
        }
        
        priority_queue<int>pq2;
        while(k--){
            while(pq.size() && pq.top().first<=w){
                pq2.push(pq.top().second);
                pq.pop();
            }
            if(pq2.size()){
                w+=pq2.top();
                pq2.pop();
            }
        }
        
        return w;
    }
};