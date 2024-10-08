class Solution {
    public int[] asteroidCollision(int[] arr) {
        int len=arr.length;
        
        Stack<Integer>s=new Stack<>();
        
        for(int i=0;i<len;++i){
            while(!s.isEmpty() && s.peek()>0 && arr[i] < 0 && s.peek()<-1*arr[i]){
                s.pop();
            }
            
            if(s.isEmpty() || arr[i]*s.peek() > 0 || (s.peek()<0 && arr[i]>0)){
               s.push(arr[i]); 
            }
            else{
                if(Math.abs(s.peek()) == Math.abs(arr[i]) && s.peek()>0){
                    s.pop();
                }
            }
        }
        
        List<Integer>res=new ArrayList<>();
        
        while(!s.isEmpty()){
            res.add(s.peek());
            s.pop();
        }
        
        Collections.reverse(res);
        int[] brr=new int[res.size()];
        
        for(int i=0;i<res.size();++i){
            brr[i]=res.get(i);
        }
        
        return brr;
    }
}