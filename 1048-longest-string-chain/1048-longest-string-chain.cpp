class Solution {
public:
static bool cmp(string &s1,string&s2){
    return s1.length()<s2.length();
}
int f(int idx,vector<string>&words,vector<int>&dp,unordered_map<string,int>&mp){
    if(dp[idx]!=-1)return dp[idx];
    int k=words[idx].length();
    if(k==1)return dp[idx]=1;  

    int best=1;
    for (int i = 0; i < k; i++)
    {
        string temp=words[idx];
        temp.erase(i,1);
        if(mp.find(temp)!=mp.end()){
            best=max(best,1+f(mp[temp],words,dp,mp));
        }
    }
    return dp[idx]=best;
}
int longestStrChain(vector<string>& words) {
       int n=words.size();
        sort(begin(words),end(words),cmp);
        vector<int>dp(n,-1);
        
        unordered_map<string,int>mp;
        for (int i = 0; i < n; i++)mp[words[i]]=i;
        
        int max_len=1;
        for (int i = 0; i < n; i++)
          max_len=max(max_len,f(i,words,dp,mp));
    return max_len;    
    }
};