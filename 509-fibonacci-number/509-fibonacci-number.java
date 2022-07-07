class Solution {
    public int fib(int n) {
        if(n==0)
            return 0;
        int i=0,j=1,curr=1;
        while(--n>0){
            curr=i+j;
            i=j;
            j=curr;
        }
        return curr;
    }
}