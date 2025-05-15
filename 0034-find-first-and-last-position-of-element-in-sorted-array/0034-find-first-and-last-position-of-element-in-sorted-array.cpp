class Solution {
public:
void search(vector<int>&nums,int n,int target,bool isLeft,vector<int>&ans){
    int l=0,r=n-1;
    while (l<=r)
    {
        int m=l+(r-l)/2;
        if(nums[m]==target){
            if(isLeft){
                ans[0]=m;
                r=m-1;
            }
            else{
                ans[1]=m;
                l=m+1;
            } 
        }
        else if (nums[m]>target)r=m-1;
        else l=m+1;
    }
    return;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>ans={-1,-1};
    int n=nums.size();
    if(n==0)return ans;
    search(nums,n,target,1,ans);
    search(nums,n,target,0,ans);
    return ans;
}
};