class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>ss,tt;
        
        for(char &c:s){
            if(c=='('){
                ss.push(-1);
            }
            else{
                int cur=0;
                while(ss.size() && ss.top()>0){
                    cur+=ss.top();
                    ss.pop();
                }
                if(ss.size() && ss.top()==-1){
                    cur+=2;
                    ss.pop();
                    if(ss.size() && ss.top()>0){
                        cur+=ss.top();
                        ss.pop();
                    }
                    if(cur>0)
                        ss.push(cur);
                }
                else{
                    if(cur>0)
                        ss.push(cur);
                    ss.push(-2);
                }
            }
        }
        
        int res=0;
        while(ss.size()!=0){
            cout<<ss.top()<<' ';
            res=max(res,ss.top());
            ss.pop();
        }
        cout<<endl;
        return res;
    }
};