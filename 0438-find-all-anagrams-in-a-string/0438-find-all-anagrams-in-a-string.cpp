class Solution {
public:
    bool allzero(vector<int>&vec){
    return vec==vector<int>(26,0);
}
vector<int> findAnagrams(string s, string p) {
    vector<int>vec(26,0);
    int n=p.length();
    for(char &c:p)vec[c-'a']++;
    vector<int>ans;
    int left=0,right=0;
    int m=s.length();
    while (right<m)
    {
       vec[s[right]-'a']--;

       if(right-left+1==n){
        if(allzero(vec)){
            ans.push_back(left);
        }
        vec[s[left]-'a']++;
        left++;
       }
       right++;
    }   
    return ans;    
    }
};