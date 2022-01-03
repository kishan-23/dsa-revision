// Decode the string
// link: https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        int n = s.size(),c=0;
        string temp="";
        stack<int> si;
        stack<string> ss;
        for(int i=0;i<n;i++){
            int z = s[i]-'0';
            if(z>=0&&z<=9){
                c = (c*10+(s[i]-'0'));
            }
            else if(s[i]=='['){
                si.push(c);
                ss.push(temp);
                c=0;
                temp="";
            }
            else if(s[i]==']'){
                int x = si.top();
                si.pop();
                string y = ss.top();
                ss.pop();
                for(int j=0;j<x;j++)
                    y = y+temp;
                temp = y;
            }
            else temp.push_back(s[i]);
        }
        
        return temp;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends