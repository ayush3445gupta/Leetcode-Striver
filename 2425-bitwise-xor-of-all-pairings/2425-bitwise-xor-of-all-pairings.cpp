class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1%2==0 && n2%2==0)return 0;
        unordered_map<int,int>mp;
        for (int i = 0; i <n1; i++)
        {
            mp[nums1[i]]+=n2;
        }
        for (int i = 0; i <n2; i++)
        {
            mp[nums2[i]]+=n1;
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second%2!=0)ans^=it->first;
        }
return ans;
    }
};