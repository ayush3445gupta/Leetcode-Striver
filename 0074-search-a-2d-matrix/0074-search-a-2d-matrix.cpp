class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size(),m=matrix[0].size();
    // find the row in which target is present
    for (int i = 0; i < n; i++)
    {
        if(target>=matrix[i][0] && target<=matrix[i][m-1]){
            int l=0,r=m-1;
            while (l<=r)
            {
                int m=(l+r)>>1;
                if(matrix[i][m]==target)return true;
                else if (matrix[i][m]>target)r=m-1;
                else l=m+1;   
            }
            return false;
        }
    }
    return false;
    }
};