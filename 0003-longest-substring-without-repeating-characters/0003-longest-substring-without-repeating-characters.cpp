class Solution {
public:
int lengthOfLongestSubstring(string s) {
   int n=s.length();
   if(n==0)return 0;
   map<char,int>mp;
   int l=0;
   int mx=0;
   for (int i = 0; i < n; i++)
   {
        mp[s[i]]++;
        while (mp[s[i]]>1 && l<i)
        {
           mp[s[l]]--;
           l++;
        }
        mx=max(mx,i-l+1);
   }
     return mx;   
    }
};