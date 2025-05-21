class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m=matrix.size(),n=matrix[0].size();
    // find the row in which target is present
    int l=0,r=m-1;
    while (l<=r)
    {
        int m=(l+r)>>1;
        if(matrix[m][0]==target)return true;
        else if (matrix[m][0]>target)r=m-1;
        else l=m+1;
    }
    int row=r;
    int l2=0,r2=n-1;
    while (l2<=r2)
    {
        int m2=(l2+r2)>>1;
        if(matrix[row][m2]==target)return true;
        else if (matrix[r][m2]>target)r2=m2-1;
        else l2=m2+1;   
    }
    return false;
    }
};