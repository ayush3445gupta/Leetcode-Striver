class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
     int n=nums.size();
   // approach 1 => store in set
   set<int>st;

   for (int i = 0; i < n; i++)
   {
    if(i>indexDiff){
        st.erase(nums[i-indexDiff-1]);
    }
    if(!st.empty()){
    int top = *st.rbegin();
    if(abs(nums[i]-top)<=valueDiff)return true;
    else if (abs(*st.begin()-nums[i])<=valueDiff)
    return true;
    }
    st.insert(nums[i]);
   }
   return false;
    }
};