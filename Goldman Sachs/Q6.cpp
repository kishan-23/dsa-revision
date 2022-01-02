// Greatest Common Divisor of Strings
// link: https://leetcode.com/problems/greatest-common-divisor-of-strings/

bool div(string a, string b){
    int x = a.size(), y = b.size();
    if(x%y||x<y) return false;
    string t;
    while(a.size()>t.size()){
        t+=b;
    }
    return (t==a);
}


string gcdOfStrings(string str1, string str2) {
    int x = str1.size(), y = str2.size(),i=1;
    string temp = "";
    while(i<=x){
        if(x%i){
            i++;
            continue;
        } 
        temp = str1.substr(0,x/i);
        if(div(str1,temp)&&div(str2,temp)) return temp;
        i++;
    }
    return "";
}