//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int arr[], int n) {
        vector<int>brr;
        
        for(int i=0;i<n;i++){
            auto it=lower_bound(brr.begin(),brr.end(),arr[i]);
            if(it==brr.end()){
                brr.push_back(arr[i]);
            }
            else{
                *it=arr[i];
            }
            
        }
        
        return n-brr.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends