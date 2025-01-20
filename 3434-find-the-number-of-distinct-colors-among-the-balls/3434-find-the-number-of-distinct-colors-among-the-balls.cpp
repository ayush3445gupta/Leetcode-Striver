class Solution {
public:
vector<int> queryResults(int limit, vector<vector<int>>& queries) {

     unordered_map<int,int>mp,colors;
     vector<int>res;
     for (int i = 0; i < queries.size(); i++)
     {
        int ball=queries[i][0],col=queries[i][1];
        if(mp.find(ball)!=mp.end()){
            if(colors[mp[ball]]==1)colors.erase(mp[ball]);
            else colors[mp[ball]]--;
        }
            mp[ball]=col;
            colors[col]++;       
        res.push_back(colors.size());
     }
     return res;
    }
};