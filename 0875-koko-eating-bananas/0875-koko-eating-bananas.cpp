class Solution {
public:
int minEatingSpeed(vector<int>& piles, int h) {
      long long int n=piles.size();
      if(n==1){
        return ceil((double)piles[0]/(double)(h));
      }
      sort(begin(piles),end(piles));
      long long int left=1,right=piles[n-1];
      while (left<=right)
      {
        long long int mid=left+(right-left)/2;
        long long int time=0;
        for (int i = 0; i < n; i++)
        {
            time+=(piles[i]/mid);
            if(piles[i]%mid!=0)time+=1;
        }
        if (time<=h)right=mid-1;
        else left=mid+1;
      }
        return left;
    }
};