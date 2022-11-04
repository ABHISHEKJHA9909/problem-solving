class Solution {
public:
    
    bool is_vowel(char &c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        
        while(i<j){
            while(i<s.size() && !is_vowel(s[i]))i++;
            while(j>=0 && !is_vowel(s[j]))j--;
            if(i<j){
                swap(s[i],s[j]);
            }
            i++,j--;
        }
        
        return s;
    }
};