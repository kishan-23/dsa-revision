// Run Length Encoding (Easy)
// link: https://practice.geeksforgeeks.org/problems/run-length-encoding/1/

#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  char c=src[0];
  int count=1;
  string ans;
  for(int i=1;i<src.size();i++){
      if(src[i]!=src[i-1]){
          ans.push_back(c);
          ans+=to_string(count);
          c = src[i];
          count = 1;
      }
      else count++;
  }
  ans.push_back(c);
  ans+=to_string(count);
  return ans;
}     
 
