// Count the subarrays having product less than k 
// link: https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long product = 1;
        int i=0,j=0,m=-1;
        long long ans=0;
        
        while(i<n&&j<n) {
            product*=a[j];
            
            if(product>=k) {
                long long x = max(m,i-1)-i+1, y = j-max(m,i-1)-1;
                ans+=((y*(y+1))/2);
                ans+=(x*y);
                while(product>=k&&i<=j) {
                    product=product/a[i];
                    i++;
                }
                
                m=j-1;
            }
            
            j++;
        }
        
        long long x = max(m,i-1)-i+1, y = j-max(m,i-1)-1;
        ans+=((y*(y+1))/2);
        ans+=(x*y);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends