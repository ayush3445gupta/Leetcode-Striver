class Solution {
public:
    string reverseVowels(string s) {
     int n=s.length();
     int l=0,r=n-1;
     set<char>st={'a','e','i','o','u'};
     while (l<r)
     {
        char c1=tolower(s[l]);
        char c2=tolower(s[r]);
        if(st.find(c1)!=st.end()){
            if(st.find(c2)!=st.end()){
            swap(s[l],s[r]);
            l++,r--;
            }
            else r--;
        }
        else if(st.find(c2)!=st.end()){
            l++;
        }
        else l++,r--;
     }
        return s;
    }
};