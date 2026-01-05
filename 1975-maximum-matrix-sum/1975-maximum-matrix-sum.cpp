class Solution {
public:
typedef long long ll;
ll maxMatrixSum(vector<vector<int>>& matrix) {
     int n=matrix.size();
     ll sum=0;
     int mn=INT_MAX,cnt=0;
     bool zeros=0;
     for (int i = 0; i < n; i++)
     {
       for (int j = 0; j < n;j++)
       {
        int x=matrix[i][j];
        sum+=abs(x);
        mn=min(mn,abs(x));
        if(x==0)zeros=1;
        else if (x<0)cnt++;
       }
     }
       if(cnt%2==0 || (cnt&1 && zeros))return sum;
       return sum-2*mn; 
    }
};