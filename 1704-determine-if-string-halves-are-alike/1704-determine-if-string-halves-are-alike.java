class Solution {
    boolean vowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    
    public boolean halvesAreAlike(String s) {
        
        int n=s.length(),x=0;
        s=s.toLowerCase();
        for(int i=0;i<n/2;i++){
            if(vowel(s.charAt(i)))
                x++;
        }
        
        for(int i=n/2;i<n;i++){
            if(vowel(s.charAt(i)))
                x--;
        }
        
        return x==0;
    }
}