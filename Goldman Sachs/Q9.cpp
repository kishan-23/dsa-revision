// Number following a pattern 
// link: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int curr=1,n=S.size();
        string ans="";
        bool f = false;
        for(int i=0;i<n;i++){
            if(S[i]=='I'){
                if(f&&i<n-1&&S[i+1]=='D'){
                    continue;
                }
                ans+=to_string(curr);
                curr++;
            }
            else{
                f=true;
                int j=i;
                while(S[j]=='D')
                    j++;
                string temp="";
                int x = j;
                while(j>=i){
                    temp+=to_string(curr);
                    curr++;
                    j--;
                }
                reverse(temp.begin(),temp.end());
                ans+=temp;
                i=x-1;
            }
        }
        if(!f) ans+=to_string(curr);
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends