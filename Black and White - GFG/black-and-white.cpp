//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends

int dir[8][2]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};

int check(int i,int j,int &n,int &m){
    return i>=0 && j>=0 && i<n && j<m;
}

long long numOfWays(int n, int m)
{
    long long res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int k=0;k<8;k++){
                if(check(i+dir[k][0],j+dir[k][1],n,m))
                    cnt++;
            }
            res+=(n*m-cnt-1);
            res%=1000000007;
        }
    }
    
    return res;
}