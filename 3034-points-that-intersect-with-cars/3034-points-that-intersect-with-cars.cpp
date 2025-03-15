class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
   
    vector<int>diff_arr(101,0);
    for (int i = 0; i < nums.size(); i++)
    {
        diff_arr[nums[i][0]]+=1;
        int end=nums[i][1];
        if(end+1<101)diff_arr[end+1]-=1;
    }
    int count=0;
    for (int i = 1; i <101; i++)
    {
        diff_arr[i]+=diff_arr[i-1];
        if(diff_arr[i]>0)count++;
    }
      return count;
}
};