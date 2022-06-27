class Solution {
    char max(char a,char b){
        if(a>b)
            return a;
        return b;
    }
    public int minPartitions(String n) {
        char c='0';
        for(int i=0;i<n.length();i++){
            c=max(c,n.charAt(i));
        }
        return c-'0';
    }
}