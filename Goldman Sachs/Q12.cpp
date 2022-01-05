// 12.	Find total number of Squares in a N*N chessboard
// link:https://www.geeksforgeeks.org/program-to-find-number-of-squares-on-a-chessboard/

#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void solve(){
    ll n;
    cin>>n;
    ll ans=(n*(n+1)*(2*n+1))/6;
    cout<<ans<<endl;
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}