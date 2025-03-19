class Solution {
public:
// vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         priority_queue<pair<int,pair<int,int>>>pq1;

//         for(int i:nums1){
//             for(int j:nums2){
//                 pq1.push({i+j,{i,j}});
//                 if(pq1.size()>k)pq1.pop();
//             }
//         }
//         vector<vector<int>>ans;
//         while (!pq1.empty())
//         {
//             int i=pq1.top().second.first;
//             int j=pq1.top().second.second;
//             ans.push_back({i,j});
//             pq1.pop();
//         }
//         return ans;
// }
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>pq1;

        for(int i:nums1){
            for(int j:nums2){
                if(pq1.size()<k)pq1.push({i+j,{i,j}});
                else if(pq1.top().first>(i+j)){
                    pq1.pop();
                    pq1.push({i+j,{i,j}});
                }
                else{
                    break;
                }
            }
        }
        vector<vector<int>>ans;
        while (!pq1.empty())
        {
            int i=pq1.top().second.first;
            int j=pq1.top().second.second;
            ans.push_back({i,j});
            pq1.pop();
        }
        return ans;
}
};