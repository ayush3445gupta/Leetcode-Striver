class Solution {
public:
    bool isPerfectSquare(int num) {
    if(num==1)return true;
      int i=1,j=num;
      while (i<=j)
      {
        long long int mid=i+(j-i)/2;
        long long prod=mid*mid;
        if(prod==num)return true;
        else if(prod>num)j=mid-1;
        else i=mid+1;
      }
       return false; 
    }
};