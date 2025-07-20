class Solution {
public:
int findContentChildren(vector<int>& g, vector<int>& s) {
    int children=g.size();
    sort(begin(g),end(g));
    sort(begin(s),end(s));
    int cnt=0;
    
    int i=0,j=0;
    while (j<s.size() && i<g.size())
    {
        if(g[i]<=s[j]){
            cnt++;
            i++;
        }
            j++;
    }
    return cnt;
    }
};