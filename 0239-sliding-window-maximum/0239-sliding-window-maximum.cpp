class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     int n=nums.size();
     vector<int>ans;
     int i=0,j=0;
     priority_queue<int>pq;
     unordered_map<int,int>mp;
     while (j<n)
     {
        mp[nums[j]]++;
        pq.push(nums[j]);
        if(j-i+1==k){
            while (mp.find(pq.top())==mp.end())
            {
                pq.pop();
            }
            ans.push_back(pq.top());
            if(pq.top()==nums[i])pq.pop();
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;
        }
        j++;
     }
        return ans;
    }
};