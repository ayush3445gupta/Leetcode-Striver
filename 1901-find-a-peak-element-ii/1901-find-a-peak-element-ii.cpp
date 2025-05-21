class Solution {
public:
int find(vector<vector<int>>&mat,int col){
    int mx=INT_MIN;
    int row=-1;
    for (int i = 0; i < mat.size(); i++)
    {
        if(mat[i][col]>mx){
            mx=mat[i][col];
            row=i;
        }
    }
    return row;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int n=mat.size(),m=mat[0].size();
      int low=0,high=m-1;
      while (low<=high)
      {
        int mid=(low+high)>>1;
        int row=find(mat,mid);
        int l=(mid-1>=0)?mat[row][mid-1]:-1;
        int r=(mid+1<m)?mat[row][mid+1]:-1;

        if(mat[row][mid]>l && mat[row][mid]>r)return {row,mid};
        else if (mat[row][mid]<l)high=mid-1;
        else low=mid+1;
      }
        return {-1,-1};
    }
};