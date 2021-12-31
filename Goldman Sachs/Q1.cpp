vector<vector<string> > Anagrams(vector<string>& string_list) {
    //code here
    //all the anagrams when sorted, result in the same string
    //so, hash of a string = sorted string, strings with same hash are anagram
        
    //for this map, key(string):- hash of string; 
    //value(int):- the index of list in which the strings with hash equal to key will be stored
    map<string,int> mp;
    int x=0;

    for(string str:string_list){
        sort(str.begin(),str.end());
        if(mp.count(str)) continue;
        //if this hash doesn't exist in map, insert and increment the index (x).
        mp[str] = x++;
    }
        
    //answer list, x also equals the size of required array of lists of strings
    vector<vector<string>> ans(x);
        
    for(string str:string_list){
        string temp = str;
        sort(temp.begin(),temp.end());
        ans[mp[temp]].push_back(str);
    }
        
    return ans;
        
}