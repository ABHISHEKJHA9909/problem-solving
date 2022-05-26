class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int res=0;  //variable to store result
        
        for(uint32_t i=0;i<32;i++){
            
            if(n & (1<<i)) //checking wether element present at ith place
                res++;
            
        }
        
        return res;
    }
};