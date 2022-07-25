class Solution {
public:
    int reverse(int x) {
        int curr=0;
        if(x>0){
            while(x){
                curr*=10;
                curr+=x%10;
                x/=10;
                if(x && curr >=INT_MAX/10 ){
                    if(curr==INT_MAX/10 && x<=INT_MAX%10)
                        continue;
                    return 0;
                }
            }
        }
        else{
            while(x){
                curr*=10;
                curr+=x%10;
                x/=10;
                
                if(x && curr <=INT_MIN/10 ){
                    if(curr==INT_MIN/10 && x>=INT_MIN%10)
                        continue;
                    return 0;
                }
                cout<<curr<<' '<<INT_MIN/10<<endl;
            }
        }
        return curr;
    }
};