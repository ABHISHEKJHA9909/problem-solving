class Solution {
public:
    string arr[7]={"I","V","X","L","C","D","M"};
    
    string intToRoman(int num) {
        int i=0;
        string res="";
        while(num){
            int curr=num%10;
            num/=10;
            if(curr==0){
                
            }
            else if(curr<=3){
                while(curr--){
                    res=arr[i]+res;
                }
            }
            else if(curr==4){
                res=arr[i]+arr[i+1]+res;
            }
            else if(curr<=8){
                while(curr--!=5){
                    res=arr[i]+res;
                }
                res=arr[i+1]+res;
            }
            else{
                res=arr[i+2]+res;
                res=arr[i]+res;
            }
            i+=2;
        }
        return res;
    }
};