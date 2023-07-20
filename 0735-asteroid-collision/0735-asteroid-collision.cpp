class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>s;
        
        for(int &i:arr){
            if(s.size()){
                while(s.size()){
                    if(s.top()>0 && i<0){
                        if(s.top()>-i)
                            i=s.top();
                        else if(s.top()==-i)
                            i=0;
                        s.pop();
                    }
                    else
                        break;
                    if(i==0)
                        break;
                }
            }
            if(i)
                s.push(i);
        }
        
        vector<int>res;
        while(s.size()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};