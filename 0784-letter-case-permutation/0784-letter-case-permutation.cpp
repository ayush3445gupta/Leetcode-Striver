class Solution {
public:
bool isChar(char a){
    return ((a>='a' && a<='z')|| (a>='A' && a<='Z'));
}
void solve(int i,string s,vector<string>&ans,int n){
    if(i>=n){
        ans.push_back(s);
        return;
    }

    if(isalpha(s[i])){
       s[i]=tolower(s[i]);
       solve(i+1,s,ans,n);
       s[i]=toupper(s[i]);
       solve(i+1,s,ans,n);
    }
    else solve(i+1,s,ans,n);
}
vector<string> letterCasePermutation(string s) {
    int n=s.length();
    vector<string>ans;
    solve(0,s,ans,n);   
    return ans;  
    }
};