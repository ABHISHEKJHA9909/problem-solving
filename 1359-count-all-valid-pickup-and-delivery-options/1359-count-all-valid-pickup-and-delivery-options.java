class Solution {
	private static int MOD=1000000007;
	
	public int countOrders(int n) {

		long res=1;
		
		for(int i=n;i>=1;--i){
            int d=2*i;
			int curr=(i*(d-1))%MOD;
            // System.out.println(i+" "+d+" "+curr);
			res*=curr;
			res%=MOD;
		}
		
		return (int)res;
	}
}