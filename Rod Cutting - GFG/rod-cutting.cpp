//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int n;
    
    int rec(int i,int l,int *price,unordered_map<string,int>&m){
        if(l==0)
            return 0;
        if(i==n)
            return INT_MIN;
        
        string s=to_string(i)+"-"+to_string(l);
        
        if(m.find(s)!=m.end())
            return m[s];
        
        
        int curr=0;
        if((i+1)<=l)
            curr=price[i]+rec(i,l-i-1,price,m);
        curr=max(curr,rec(i+1,l,price,m));
        
        return m[s]=curr;
    }
    
    int cutRod(int price[], int n) {
        
        vector<int>dp(n+1,0);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                if((i+1)<=j)
                    dp[j]=max(price[i]+dp[j-(i+1)],dp[j]);
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends