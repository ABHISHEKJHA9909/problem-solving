//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int start[], int end[]) {
        pair<int,int> curr[2*n];
        
        for(int i=0;i<n;i++){
            curr[i]={start[i],1};
        }
        for(int i=0;i<n;i++){
            curr[n+i]={end[i],-1};
        }
        
        sort(curr,curr+2*n);
        
        int res=0,cnt=0;
        
        for(int i=0;i<2*n;i++){
            while(i+1<2*n && curr[i].first==curr[i+1].first){
                cnt+=curr[i].second;
                i++;
            }
            cnt+=curr[i].second;
            res=max(res,cnt);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends