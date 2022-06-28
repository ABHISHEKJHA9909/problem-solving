class Solution {
    boolean is(String s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s.charAt(i)==s.charAt(j)){
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    public boolean isPalindrome(String s) {
        String res="";
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if((c>='a'&&c<='z')||(c>='0'&&c<='9'))
                res+=c;
            if(c>='A'&&c<='Z')
                res+=(char)(c+32);
        }
        return is(res);
    }
}