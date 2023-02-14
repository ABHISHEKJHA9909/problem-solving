class Solution {
    public String addBinary(String a, String b) {
        
        String res="";
        int i=a.length()-1,j=b.length()-1,carry=0;
        
        while(i>=0 || j>=0 || carry==1){
            int curr=carry;
            carry=0;
            
            if(i>=0 && a.charAt(i)=='1'){
                curr+=1;
            }
            if(j>=0 && b.charAt(j)=='1'){
                curr+=1;
            }
            
            if(curr==0){
                res="0"+res;
            }
            else if(curr==1){
                res="1"+res;
            }
            else if(curr==2){
                res="0"+res;
                carry=1;
            }
            else{
                res="1"+res;
                carry=1;
            }
            
            --i;
            --j;
        }
        
        return res;
    }
}