// Find Missing And Repeating
// link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    
    int a[2];
    int last_set_bit(int n){
        int pos=0,t=1;
        while(t<=n){
            t = (1<<pos++);
            if(n&t) return --pos;
        }
        return --pos;
    }
    
    int *findTwoElement(int *arr, int n) {
        // code here
        //x->missing, y->repeating xr will be x^y later
        int xr = 0,x=0,y=0;
        for(int i=0;i<n;i++)
            xr = xr^arr[i];
        
        if(n%4==0) xr = xr^n;
        else if(n%4==1) xr = xr^1;
        else if(n%4==2) xr = xr^(n+1);
        
        
        int pt = 1<<last_set_bit(xr);
        for(int i=0;i<n;i++){
            if(pt&arr[i]) x = x^arr[i];
            else y = y^arr[i];
        }
        
        for(int i=1;i<=n;i++){
            if(pt&i) x = x^i;
            else y = y^i;
        }
        
        a[0] = y, a[1] = x;
        
        for(int i=0;i<n;i++){
            if(x==arr[i]){
                swap(a[0],a[1]);
                break;
            }
        }
        
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
