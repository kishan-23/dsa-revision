// Total Decoding Messages
// https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int n = str.size();
		    vector<long long> dp(n+1,0);
		    const int mod = 1000000007;
		    dp[0] = dp[1]=1;
		    if(str[0]=='0') return 0;
		    for(int i=2;i<=n;i++){
		        char x = str[i-1];
		        if(x=='0'){
		            if((str[i-2]>'2')||str[i-2]=='0') return 0;
		            else dp[i] = dp[i-2];
		            continue;
		        }
		        else dp[i] = dp[i-1];
		        
		        if(str[i-2]=='1') dp[i]=(dp[i]+dp[i-2])%mod;
		        else if(str[i-2]=='2'&&(x>='0'&&x<'7')) dp[i]=(dp[i]+dp[i-2])%mod;
		    }
		    return dp[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends