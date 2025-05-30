class Solution {
public:
bool checkInclusion(string s1, string s2) {
     int n1=s1.length(),n2=s2.length();
     sort(begin(s1),end(s1));
     int i=0,j=0;
     while (j<n2)
     {
        if(j-i+1==n1){
            string s=s2.substr(i,n1);
            sort(begin(s),end(s));
            if(s==s1)return true;
            i++;
        }
        j++;
     }
        return false;
    }
};