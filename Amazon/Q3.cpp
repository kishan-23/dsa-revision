// IPL 2021 - Match Day 2 (find maximum in each window of size k)
// link: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!dq.empty()&&arr[dq.back()]<arr[i])
                dq.pop_back();
            dq.push_back(i);
            while(!dq.empty()&&dq.front()+k<=i)
                dq.pop_front();
            if(i>=k-1) ans.push_back(arr[dq.front()]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends