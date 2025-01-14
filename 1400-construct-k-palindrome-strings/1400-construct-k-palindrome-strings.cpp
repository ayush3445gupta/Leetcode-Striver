class Solution {
public:
   bool canConstruct(string s, int k) {
    if(s.length()<k)return false;
    if(s.length()==k)return true;
       unordered_map<char,int>mp;
       for(char c:s) mp[c]++;
       int cnt=0;
       for(auto it:mp){
        if(it.second%2!=0)cnt++;
       }
       return cnt<=k;
    }
};