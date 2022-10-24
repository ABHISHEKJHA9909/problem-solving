#define bp __builtin_popcount

class Solution {
public:
    vector<int>arr;
    int n;
    
    int stoci(string &s){
        int x=0;
        for(char &c:s){
            if(x&(1<<(c-'a')))
                return 0;
            x=x|(1<<(c-'a'));
        }
        return x;
    }
    
    int knap(int i,int s){
        if(i==n){
            return bp(s);
        }
        int t=0,nt=0;
        
        if(bp(arr[i])+bp(s)==bp(arr[i]|s)){
            t=knap(i+1,s|arr[i]);
        }
        nt=knap(i+1,s);
        
        return max(t,nt);
    }
    
    int maxLength(vector<string>& brr) {
        n=brr.size();
        
        for(string &s:brr){
            arr.push_back(stoci(s));
        }
        
        return knap(0,0);
    }
};