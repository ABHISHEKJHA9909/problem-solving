class Solution {
public:
    int maximum69Number (int num) {
        vector<int>arr;
        while(num){
            arr.push_back(num%10);
            num/=10;
        }
        
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]==6){
                arr[i]=9;
                break;
            }
        }
        
        for(int i=arr.size()-1;i>=0;i--){
            num*=10;
            num+=arr[i];
        }
        
        return num;
    }
};