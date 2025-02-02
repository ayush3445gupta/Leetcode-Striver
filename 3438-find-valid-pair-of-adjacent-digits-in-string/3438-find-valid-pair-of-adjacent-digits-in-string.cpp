class Solution {
public:
    string findValidPair(string s) {
     string res="";
     unordered_map<int,int>mp;
     for(char c:s)mp[c-'0']++;
     for (int i = 0; i < s.length()-1; i++)
     {
        if(s[i]!=s[i+1] && (s[i]-'0')==mp[s[i]-'0'] && int(s[i+1]-'0')==mp[s[i+1]-'0']){
            res+=s[i],res+=s[i+1];
            break;
        }
     }
    return res;    
    }
};