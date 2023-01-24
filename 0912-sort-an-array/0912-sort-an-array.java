class Solution {
    int n,temp[];
    
    void MergeSort(int[]nums,int i,int j){
        if(i>=j)
            return;
        
        int mid=i+(j-i)/2;
        MergeSort(nums,i,mid);
        MergeSort(nums,mid+1,j);
        Merge(nums,i,mid+1,j);
    }
    
    void Merge(int[] nums,int i,int n,int j){
        int x=n,y=0,z=i;
        while(i<n && x<=j){
            if(nums[i]<nums[x])
                temp[y++]=nums[i++];
            else
                temp[y++]=nums[x++];
        }
        while(i<n)
            temp[y++]=nums[i++];
        while(x<=j)
            temp[y++]=nums[x++];
        y=0;
        while(z!=j+1)
            nums[z++]=temp[y++];
        
    }
    
    public int[] sortArray(int[] nums) {
        n=nums.length;
        temp=new int[n];
        
        MergeSort(nums,0,n-1);
        
        return nums;
    }
}