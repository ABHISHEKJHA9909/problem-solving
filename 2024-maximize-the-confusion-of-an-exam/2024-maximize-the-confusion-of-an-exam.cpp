class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.size();
        
        int res=0;
        
        for(int i=0,j=0,t=0,f=0;i<n;i++){
            
            s[i]=='T'?++t:++f;
            
            while(min(t,f)>k){
                s[j++]=='T'?--t:--f;
            }
            res=max(res,i-j+1);
        }
        
        return res;
    }
};