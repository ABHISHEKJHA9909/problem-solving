class Solution {
    public String largestNumber(int[] nums) {
        Comparator<String> comparator = Comparator.reverseOrder();

        PriorityQueue<String>pq=new PriorityQueue<>((a,b)->{
            return comparator.compare(a+b,b+a);
        }
        );
        
        long sum=0;
        
        for(int i:nums){
            sum+=i;
            pq.add(String.valueOf(i));
        }
        if(sum==0){
            return "0";
        }
        
        StringBuilder sb=new StringBuilder();
        while(pq.size()!=0){
            sb.append(pq.poll());
        }
        
        return sb.toString();
    }
}