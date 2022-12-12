class Solution {
public:
    int climbStairs(int n) {
        int pp=0;
        int p=1;
        int curr=0;
        while(n--){
            curr=(p+pp);
            pp=p;
            p=curr;
        }
        return curr;
    }
};