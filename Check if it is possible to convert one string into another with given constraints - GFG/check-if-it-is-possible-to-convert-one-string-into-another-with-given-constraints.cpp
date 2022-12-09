//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isItPossible(string s, string t, int m, int n) {
        if(m!=n)
            return 0;
        int i=0,j=0;
        
        while(i<m && j<n){
            while(i<m && s[i]=='#')i++;
            while(j<n && t[j]=='#')j++;
            if(s[i]!=t[j])
                return 0;
            if(i<m && s[i]=='A' && i<j)
                return 0;
            if(j<n && s[i]=='B' && i>j)
                return 0;
            i++,j++;
        }
        
        while(i<m){
            if(s[i]!='#')
                return 0;
            i++;
        }
        
        while(j<n){
            if(t[j]!='#')
                return 0;
            j++;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends