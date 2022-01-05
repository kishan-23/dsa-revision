// Maximum Profit 
// link: https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(K+1,0));
        int mn=INT_MAX, profit=0;
        for(int i=0;i<N;i++){
            profit = max(profit,A[i]-mn);
            mn = min(mn,A[i]);
            dp[i+1][1] = profit;
        }
        
        for(int k=2;k<=K;k++){
            for(int i=0;i<N;i++){
                dp[i+1][k] = dp[i][k];
                for(int j=i;j>=0;j--)
                    dp[i+1][k] = max(dp[i+1][k],(A[i]-A[j])+dp[j][k-1]);
            }
        }
        
        return dp[N][K];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends