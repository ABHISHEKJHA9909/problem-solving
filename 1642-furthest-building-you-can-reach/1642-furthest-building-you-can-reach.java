class Solution {
    public int furthestBuilding(int[] arr, int b, int l) {
        PriorityQueue<Integer>pq=new PriorityQueue<Integer>();
        
        for(int i=0;i<arr.length-1;i++){
            if(arr[i]>arr[i+1])
                continue;
            pq.add((arr[i+1]-arr[i]));
            if(pq.size()>l){
                if(b<pq.peek())
                    return i;
                b-=pq.peek();
                pq.remove();
            }
        }
        
        return arr.length-1;
    }
}