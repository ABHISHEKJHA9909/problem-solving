class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        
        for(int &i:piles){
            pq.push(i);
        }
        
        while(k--){
            pq.push((pq.top()+1)/2);
            pq.pop();
        }
        
        int res=0;
        while(pq.size()){
            res+=pq.top();
            pq.pop();
        }
        
        return res;
    }
};