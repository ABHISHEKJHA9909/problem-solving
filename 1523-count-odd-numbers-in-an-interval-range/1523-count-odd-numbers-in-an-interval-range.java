class Solution {
    public int countOdds(int low, int high) {
        
        if((low&1)==1 && (high&1)==1)
            return (high-low+2)/2;
        if((low&1)==1 || (high&1)==1)
            return (high-low+1)/2;
        return (high-low)/2;
    }
}