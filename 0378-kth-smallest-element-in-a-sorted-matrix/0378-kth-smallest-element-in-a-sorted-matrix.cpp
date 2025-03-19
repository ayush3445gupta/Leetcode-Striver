class Solution {
public:
int kthSmallest(vector<vector<int>>& matrix, int k) {
    map<int,int>mp;
    for (int i = 0; i <matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            mp[matrix[i][j]]++;
        }    
    };
    int cnt=0;
    for(auto it:mp){
        cnt+=it.second;
        if(cnt>=k)return it.first;  
    }
    return -1;
}
};