class Solution {
    class comp implements Comparator<Integer[]> {
        public int compare(Integer[] str1, Integer[] str2)
        {
            return str1[0].compareTo(str2[0]);
        }
    }   
    // class comp implements Comparator<Integer[]>{
    //     public boolean compare(Integer a[],Integer b[]){
    //         return a[0]>b[0];
    //     }
    // }
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer>m=new HashMap<Integer,Integer>();
        
        for(int i=0;i<nums.length;i++){
            if(m.containsKey(nums[i])==false)
                m.put(nums[i],0);
            m.put(nums[i],m.get(nums[i])+1);
        }
        
        PriorityQueue<Integer[]>pq=new PriorityQueue<Integer[]>(new comp());
        for(Integer i:m.keySet()){
            Integer arr[]={m.get(i),i};
            pq.add(arr);
            if(pq.size()>k)
                pq.remove();
        }
        int res[]=new int[pq.size()];
        int i=0;
        while(pq.size()!=0){
            Integer []l=pq.poll();
            res[i++]=(l[1]).intValue();
        }
        
        return res;
    }
}