class Solution {
    private int toNum(int[] nums){
        int num=0;
        
        for(int i=0;i<8;++i){
            int mask=1<<i;
            
            if(nums[i]==1){
                num|=mask;
            }
        }
        
        return num;
    }
    
    private int[] toArray(int num){
        int[] nums=new int[8];
        
        for(int i=0;i<8;++i){
            int mask=1<<i;
            
            if((num&mask)!=0){
                nums[i]=1;
            }
        }
        
        return nums;
    }
    
    private void print(int num){
        for(int i=0;i<8;++i){
            System.out.print(((num&(1<<i))!=0?1:0));
        }
        // System.out.println();
    }
    
    public int[] prisonAfterNDays(int[] cells, int n) {
        Map<Integer,Integer> m = new HashMap<>();
        boolean[] flag=new boolean[256];
        
        int num=toNum(cells);
        int cycle=0;
        
        while(flag[num]==false){
            // print(num);
            m.put(cycle,num);
            flag[num]=true;
            
            ++cycle;
            
            int prev=num;
            prev>>=1;
            
            int next=num;
            next<<=1;
            
            num=prev^next;
            num=~num;
            
            num&=(~(1));
            num&=(~(1<<7));
            num&=((1<<8)-1);
        }
        
        if(n<cycle){
            return toArray(m.get(n));
        }
        
        n-=cycle;
        
        int x=0;
        
        for(int i=0;i<256;++i){
            if(m.get(i)==num){
                x=i;
                break;
            }
        }
        
        
        cycle-=x;
        // System.out.println(x+ " "+ cycle);
        
        return toArray(m.get(x+(n%cycle)));
    }
}