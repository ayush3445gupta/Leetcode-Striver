class Solution {
public:
typedef long long ll;
const int mod = 1e9+7;
int specialTriplets(vector<int>& nums) {
    //  /2 iterations forward & backward
    
    int n=nums.size();
    unordered_map<int,int>mp,mp1;
    vector<bool>ispresent(n,0);
    for (int i = 0; i < n; i++)
    {
        if(mp.find(2*nums[i])!=mp.end()){
            ispresent[i]=1;
        }
        mp[nums[i]]++;
    }
    
    ll cnt=0;
    for (int i = n - 1; i >= 0; i--)
    {
        mp[nums[i]]--;
        if(ispresent[i]){

            if(mp1.find(2*nums[i])!=mp1.end()){
                cnt+=(mp1[2*nums[i]]*mp[2*nums[i]]);
            }
        }
            mp1[nums[i]]++;
    }
    return ((cnt%mod)+mod)%mod;
    }
};