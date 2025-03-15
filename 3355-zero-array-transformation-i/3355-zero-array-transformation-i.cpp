class Solution {
public:
bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n=nums.size();
    vector<int>difference_array(n+1,0);
    
    for (int i = 0; i < queries.size(); i++)
    {
        int li=queries[i][0];
        int ri=queries[i][1];
        difference_array[li]--;
        difference_array[ri+1]++;
    }
    int cum_sum=0;
    for (int i = 0; i < n; i++)
    {
        cum_sum+=difference_array[i];
        if(cum_sum+nums[i]>0)return false;

    }
    return true;
}
};