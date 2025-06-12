class Solution {
public:
    int partitionString(string s) {
    int n=s.length();
   unordered_set<char>st;
    int count=0;
    int i=0,j=0;
    while (j<n)
    {
        if(st.find(s[j])!=st.end()){
            count++;
            st.clear();
        }
        st.insert(s[j]);
        j++;
    }
    if(st.empty())return count;
    return count+1;
    }
};