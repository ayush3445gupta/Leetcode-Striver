class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            pq.push({i+j,{j,i}});
        }
    }
    
    vector<int>res;
while (!pq.empty())
    {
        int col=pq.top().second.first;
        int row=pq.top().second.second;
        res.push_back(nums[row][col]);
        pq.pop();
    }
    return res;
}
};