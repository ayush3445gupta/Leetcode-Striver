class Solution {
public:
string edit(string s){
    int n = s.length();
    string t;
    for (int i = 0; i < n; i++)
    {
       char c = s[i];
       if(isalnum(c)){
        if(c>='0' && c<='9')t+=c;
        else if (c!=tolower(c)){
            c=tolower(c);
            t+=c;
        }
        else t+=c;
       }
       }
    
    return t;
}

bool isPalindrome(string s) {
     string t = edit(s);
     string k = t;
     reverse(begin(k),end(k));
    return k==t;
}
};