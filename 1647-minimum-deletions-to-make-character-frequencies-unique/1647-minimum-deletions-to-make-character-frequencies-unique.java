class Solution {
    String sort(String s){
        char c[]=s.toCharArray();
        Arrays.sort(c);
        return String.valueOf(c);
    }
    public int minDeletions(String s) {
        Set<Integer>hs=new HashSet<Integer>();
        s=sort(s);
        int res=0;
        for(int i=0;i<s.length();){
            char curr=s.charAt(i);
            int currl=0;
            while(i<s.length() && s.charAt(i)==curr){
                currl++;
                i++;
            }
            while(hs.contains(currl)!=false && currl!=0){
                currl--;
                res++;
            }
            hs.add(currl);
        }
        return res;
    }
}