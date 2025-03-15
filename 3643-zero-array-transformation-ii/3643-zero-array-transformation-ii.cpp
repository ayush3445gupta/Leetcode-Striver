class Solution {
public:
int n,q;
bool checkwithDifferenceArray(vector<int>& nums, vector<vector<int>>& queries,int idx){
// O (K=Q)
    vector<int>diff_arr(n,0);
    for (int i = 0; i <=idx; i++)
    {
        int l=queries[i][0];
        int r=queries[i][1];
        int x=queries[i][2];

       diff_arr[l]+=x;
       if(r+1<n)diff_arr[r+1]-=x;
    }

    int cum_sum=0;
    for (int i = 0; i < n; i++)  // O(N)
    {
        cum_sum+=diff_arr[i];
        if(nums[i]>cum_sum)return false;
        // nums[i] 0 nahi ban paya
    }

    return true;
}
int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    n=nums.size();
    q=queries.size();

    auto lambda = [](int x){
      return x==0;
    };
  //   no query required when all elements are zero
    if(all_of(begin(nums),end(nums),lambda)){
      return 0;
    }
    int l=0,r=q-1;
    int k=-1;
    while(l<=r){     //(log(Q)*(Q+N))
        int mid=l+(r-l)/2;
      if(checkwithDifferenceArray(nums,queries,mid)==true){
        r=mid-1;
        k=mid+1;
      }
      else{
        l=mid+1;
      }
    }
    return k;
}
};