class Solution {
    public int[][] reconstructQueue(int[][] arr) {
        Arrays.sort(arr,new Comparator<int[]>(){
            public int compare(int a[],int b[]){
                if(a[0]<b[0])
                    return 1;
                else if(a[0]>b[0])
                    return -1;
                else if(a[1]>b[1])
                    return 1;
                else if(a[1]<b[1])
                    return -1;
                return 0;
            }
        });
        int n=arr.length;
        List<Integer[]>res=new ArrayList<Integer[]>(n);
        for(int i=0;i<n;i++){
            Integer a[]={arr[i][0],arr[i][1]};
            res.add(arr[i][1],a);
        }
        int j=0;
        for(Integer[]i:res){
            int a[]={i[0],i[1]};
            arr[j++]=a;
        }
        return arr;
    }
}