class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        for(int& i:stones){
            pq.push(i);
        }
        
        while(pq.size()!=1){
            int x=pq.top();
            pq.pop();
            x-=pq.top();
            pq.pop();
            pq.push(x);
        }
        
        return pq.top();
    }
};