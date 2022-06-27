class Solution {
public:
    bool isPossible(vector<int>& arr) {
        priority_queue<int>pq;
        long long sum=0;
        for(int &i:arr){
            pq.push(i);
            sum+=i;
        }
        while(pq.top()!=1){
            sum-=pq.top();
            if(sum==0 || sum>=pq.top())return false;
            int cur=pq.top()%sum;
            if(sum!=1 && cur==0)return false;
            pq.pop();
            pq.push(cur);
            sum+=cur;
        }
        return true;
    }
};