class Solution {
public:
int minDeletion(string s, int k) {
    int n=s.length();
    map<char,int>mp;
    for(char c:s)mp[c]++;
    int dist=mp.size()-k;
    if(dist==0)return 0;
    int ans=0;
    vector<pair<char,int>>vec(mp.begin(),mp.end());
    sort(begin(vec),end(vec),[](const auto &a,const auto &b){
        return a.second<b.second;
    });
    for(int i=0;i<vec.size() && dist>0;i++){
        ans+=vec[i].second;
        dist--;
    }
    return ans;
    }
};