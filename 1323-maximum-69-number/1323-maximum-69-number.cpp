class Solution {
public:
int maximum69Number (int num) {
     string temp=to_string(num);
     for (int i = 0; i < temp.length(); i++)
     {
      if(temp[i]=='6'){
        temp[i]='9';
        break;
      }
     }
    int ans=stoi(temp);
    return ans;
    }
};