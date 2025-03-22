class Solution {
public:
    int maxSum(vector<int>& nums) {
    // sort(begin(nums),end(nums),greater<int>());
    int sum=0;
    set<int>st;
    for (int i = 0; i < nums.size(); i++)
    {
       if(st.find(nums[i])==st.end()){
        if(nums[i]>0){
            sum+=nums[i];
            st.insert(nums[i]);
        }
       } 
    }
    if(sum==0)return *max_element(nums.begin(),nums.end());
    return sum;
}
};