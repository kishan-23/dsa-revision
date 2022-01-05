// Find max 10 numbers in a list having 10M entries.
// link: 

#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i:v){
        pq.push(i);
        if(pq.size()>k) pq.pop();
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
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