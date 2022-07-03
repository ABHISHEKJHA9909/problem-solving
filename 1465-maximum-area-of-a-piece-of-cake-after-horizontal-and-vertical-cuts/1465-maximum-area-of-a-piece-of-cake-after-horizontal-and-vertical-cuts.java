class Solution {
    public int maxArea(int h, int w, int[] hrr, int[] vrr) {
        Arrays.sort(hrr);
        Arrays.sort(vrr);
        long hr=Math.max(hrr[0],h-hrr[hrr.length-1]),vr=Math.max(vrr[0],w-vrr[vrr.length-1]);
        for(int i=1;i<hrr.length;i++){
            hr=Math.max(hr,hrr[i]-hrr[i-1]);
        }
        for(int i=1;i<vrr.length;i++){
            vr=Math.max(vr,vrr[i]-vrr[i-1]);
        }
        return (int)((hr*vr)%(1000000007));
    }
}