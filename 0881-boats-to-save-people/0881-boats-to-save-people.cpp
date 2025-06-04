class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      int n=people.size();
      sort(begin(people),end(people));
      int left=0,right=n-1;
      int cnt=0;
      while (left<right)
      {
        int w=people[left]+people[right];
        if(w<=limit){
            left++,right--;
        }
        else{
            right--;
        }
        cnt++;
      }
      if(left==right)cnt++;
    return cnt;   
    }
};