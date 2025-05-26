class Solution {
public:
vector<int> findLonely(vector<int>& nums) {
     int n=nums.size();
     if(n==1)return nums;
     sort(begin(nums),end(nums));
     vector<int>ans;
     unordered_map<int,int>mp;
     for(int i:nums)mp[i]++;
     for (auto it=mp.begin(); it!=mp.end(); it++)
     {
        if(it->second==1 && mp.find(it->first+1)==mp.end() && mp.find(it->first-1)==mp.end())ans.push_back(it->first);
     }
     return ans;
    }
};