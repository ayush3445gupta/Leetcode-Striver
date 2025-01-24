class Solution {
public:
    bool checkPalindrome(string s){
    int n=s.length();
    if(n==1)return 1;
    int left=0,right=n-1;
    while (left<right)
    {
        if(s[left]!=s[right])return false;
        else left++,right--;
    }
    return true;
}
bool validPalindrome(string s) {
      int n=s.length();
      int left=0,right=n-1;
      while (left<right)
      {
        if(s[left]!=s[right]){
            // 1.delete left and check
            // 2. delete right and check
            string l=s,r=s;
            l.erase(left,1);
            r.erase(right,1);
            if(checkPalindrome(l) || checkPalindrome(r))return true;
            return false;
        }
        else {
            left++,right--;
        }
      }
    return true;
    }
};