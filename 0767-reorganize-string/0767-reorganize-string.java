class Solution {
    public String reorganizeString(String s) {
        
        int cnt[]=new int[256];
        
        int max=0;
        int c=0;
        
        for(int i=0;i<s.length();i++){
            ++cnt[s.charAt(i)];
            if(cnt[s.charAt(i)]>max){
                max=cnt[s.charAt(i)];
                c=s.charAt(i);
            }
        }
        
        
        if(max>(s.length()+1)/2)
            return "";
        
        int arr[]=new int[s.length()];
        
        int idx=0;
        while(cnt[c]>0){
            arr[idx]=c;
            idx+=2;
            --cnt[c];
        }
        
        for(int i=97;i<233;i++){
            while(cnt[i]>0){
                if(idx>=s.length()){
                    idx=1;
                }
                arr[idx]=i;
                idx+=2;
                --cnt[i];
            }
        }
        
        
        
        String res="";
        
        for(int i=0;i<s.length();i++){
            res+=(char)arr[i];
        }
        
        return res;
    }
}