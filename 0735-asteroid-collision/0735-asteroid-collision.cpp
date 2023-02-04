class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        
        for(int &i:asteroids){
            int curr=i;
            
            while( s.size() && curr && (s.top()>0 && curr<0) ){
                // cout<<s.top()<<' ';
                if(abs(curr)<abs(s.top()))
                    curr=s.top();
                else if(abs(curr)==abs(s.top()))
                    curr=0;
                s.pop();
            }
            if(curr)
                s.push(curr);
            
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