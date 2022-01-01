// Ugly Numbers
// link: https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    int c=0;
	    ull curr=1;
	    set<ull> st;
	    st.insert(1);
	    
	    while(c<n){
	        auto it = st.begin();
	        curr = *it;
	        st.erase(it);
	        st.insert(curr*2);
	        st.insert(curr*3);
	        st.insert(curr*5);
	        c++;
	    }
	    return curr;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends