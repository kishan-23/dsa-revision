// Phone directory
// link: https://practice.geeksforgeeks.org/problems/phone-directory4628/1/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    struct node{
        node* child[26];
        bool is_end;
        node(){
            for(int i=0;i<26;i++)
                child[i] = NULL;
            this->is_end = false;
        }
    };
    
    node* insert(node* root,string word){
        node* temp = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(temp->child[index]==NULL) temp->child[index] = new node();
            temp = temp->child[index];
        }
        temp->is_end = true;
        return root;
    }
    
    node* prefix(node* root, string pre){
        if(root==NULL) return root;
        node* temp = root;
        for(int i=0;i<pre.size();i++){
            int index = pre[i] - 'a';
            if(!temp->child[index]) return NULL;
            temp = temp->child[index];
        }
        return temp;
    }
    
    vector<string> disp;
    
    void display(node* root,string str){
        if(root->is_end) disp.push_back(str);
        if(root==NULL) return;
        for(int i=0;i<26;i++){
            str.push_back('a'+i);
            if(root->child[i]) display(root->child[i],str);
            str.pop_back();
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        node* root = new node();
        for(int i=0;i<n;i++){
            string str = contact[i];
            root = insert(root,str);
        }
        
        vector<vector<string>> ans;
        
        string q="";
        for(char i:s){
            q.push_back(i);
            disp.clear();
            node* temp = prefix(root,q);
            if(temp!=NULL) display(temp,q);
            else disp.push_back("0");
            ans.push_back(disp);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends