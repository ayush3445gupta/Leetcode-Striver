class Solution {
public:
int characterReplacement(string s, int k) {
    int n=s.length();
    vector<int>hash(26,0);
     int left=0,right=0,maxFreq=0,maxLen=0;
     while (right<n)
     {
        hash[s[right]-'A']++;
        maxFreq=max(maxFreq,hash[s[right]-'A']);
        while (left<right && (right-left+1)-maxFreq>k)
        {
            hash[s[left]-'A']--;
            maxFreq=0;
            for (int i = 0; i < 26; i++) maxFreq=max(maxFreq,hash[i]);
            left++;
        }
        if((right-left+1)-maxFreq<=k)maxLen=max(maxLen,right-left+1);
        right++;
     }
     return maxLen;
    }
};