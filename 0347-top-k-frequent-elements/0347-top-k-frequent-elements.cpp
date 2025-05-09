class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>freq;
    for(int i:nums)freq[i]++;
    priority_queue<pair<int,int>>pq;
    for(auto it:freq)pq.push({it.second,it.first});

    vector<int>ans;
    while (!pq.empty() &&k>0)
    {
        ans.push_back(pq.top().second);
        k--;
        pq.pop();   
    }
    return ans;
}
};