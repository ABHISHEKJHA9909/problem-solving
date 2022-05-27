class Solution {
public:
    int numberOfSteps(int num) {
        int e=0,o=0;
        while(num){
            if(num&1){
                o++;
                cout<<1;
            }
            else{
                e++;
                cout<<0;
            }
            num>>=1;
        }
        int res=0;
        if(o)res+= 1 + 2*(o-1);
        if(e)res+=1*e;
        return res;
    }
};