class Solution {
public:
int solve(vector<int>&arr){
    int c=0;
    for (int i = 0; i < arr.size(); i++)
    {
        c+=(abs(arr[i]-2*i));
    }
    return c;
}
int minSwaps(vector<int>& nums) {
    int n=nums.size();
    vector<int>odd,even;
    for(int i=0;i<n;i++)if(nums[i]&1)odd.push_back(i);
    else even.push_back(i);

    int e=even.size(),o=odd.size();
    if(abs(o-e)>1)return -1;

    // try 2 pattern 
    // 1->  o,e,o,e,o,e
    // 2-> e,o,e,o,e,o

    int ans=INT_MAX;
    if(e>=o)ans=min(ans,solve(even));
    if(o>=e) ans=min(ans,solve(odd));

    return ans;
    }
};