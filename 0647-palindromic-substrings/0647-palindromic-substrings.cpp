class Solution {
public:
int cnt=0;
int n;
void check(int i,int j,string& s){
    while (i>=0 && j<n && s[i]==s[j])
    {
        cnt++;
        i--,j++;
    }
}
int countSubstrings(string s) {
    n=s.length();
    cnt=0;
    for (int i = 0; i < n; i++)
    {
        check(i,i,s);    // for odd
        check(i,i+1,s);   // for even
    }
    return cnt;
}
};