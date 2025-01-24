class Solution {
public:
    string reverseOnlyLetters(string s) {
      int left=0,right=s.length()-1;
      while (left<right)
      {
        if(isalpha(s[left])){
            if(isalpha(s[right])){
                swap(s[left],s[right]);
                left++,right--;
            }
            else right--;
        }
        else if(isalpha(s[right])){
            left++;
        }
        else left++,right--;
      }
        return s;
    }
};