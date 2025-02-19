class Solution {
public:
bool hasSpecialSubstring(string s, int k) {
      int n=s.length();
      unordered_map<char,int>mp;
      int i=0,j=0;
      for (int j= 0; j<n; j++)
      {
        mp[s[j]]++;
        if(j-i+1==k){
            if(mp.size()==1){
            if((i!=0 && s[i-1]!=s[i])|| (i==0)){
                if((j!=n-1 && s[j]!=s[j+1]) || j==n-1)return true;   
            }
            }
            if(mp[s[i]]==1)mp.erase(s[i]);
                else mp[s[i]]--;
                i++;      
        }
      }
      return false;  
    }
};