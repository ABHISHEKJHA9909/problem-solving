class Solution {
    public int partitionString(String s) {
        boolean arr[]=new boolean[26];
        int n=s.length();
        
        int res=1;
        
        for(int i=0;i<n;i++){
            if(arr[s.charAt(i)-'a']==true){
                res++;
                for(int j=0;j<26;j++)
                    arr[j]=false;
            }
            arr[s.charAt(i)-'a']=true;
        }
        
        return res;
    }
}