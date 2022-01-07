// First non-repeating character in a stream
// link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans;
		    int cnt[26]={0};
		    int occ[26];
		    for(int i=0;i<26;i++)
		        occ[i] = INT_MAX;
		    for(int i=0;i<A.size();i++){
		        int x = A[i]-'a';
		        cnt[x]++;
		        occ[x] = min(occ[x],i);
		        int y=-1;
		        for(int j=0;j<26;j++){
		            if(cnt[j]==1){
		                if(y>=0&&occ[y]<occ[j]) continue;
		                else y = j;
		            }
		        }
		        if(y==-1) ans.push_back('#');
		        else ans.push_back('a'+y);
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends