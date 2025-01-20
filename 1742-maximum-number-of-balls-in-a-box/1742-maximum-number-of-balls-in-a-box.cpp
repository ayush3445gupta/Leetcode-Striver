class Solution {
public:
    int findsum(int n){
    int r=0;
    while (n>0)
    {
        r+=(n%10);
        n/=10;
    }
    return r;
}
int countBalls(int lowLimit, int highLimit) {
    unordered_map<int,int>mp;
    for (int i = lowLimit; i <=highLimit; i++)
    {
        mp[findsum(i)]++;
    }
    int maxi=INT_MIN;
    for(auto it=mp.begin();it!=mp.end();it++){
        maxi=max(maxi,it->second);
    }
    return maxi;
    }
};