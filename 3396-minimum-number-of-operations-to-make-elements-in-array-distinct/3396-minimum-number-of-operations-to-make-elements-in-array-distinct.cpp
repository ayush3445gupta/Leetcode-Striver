class Solution {
public:
    int minimumOperations(vector<int>& nums) {
      unordered_set<int>st;
      int ind=-1;
      for (int i = nums.size()- 1; i >= 0; i--)
      {
        if(st.find(nums[i])==st.end())st.insert(nums[i]);
        else{
            ind=i;
            break;
        }
      }
    if(ind==-1)return 0;
    return ceil((ind+1)/3.0);
    }
};