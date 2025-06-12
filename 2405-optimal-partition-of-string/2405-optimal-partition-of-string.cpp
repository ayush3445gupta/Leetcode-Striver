class Solution {
public:
//     int partitionString(string s) {
//     int n=s.length();
//    unordered_set<char>st;
//     int count=0;
//     int i=0,j=0;
//     while (j<n)
//     {
//         if(st.find(s[j])!=st.end()){
//             count++;
//             st.clear();
//         }
//         st.insert(s[j]);
//         j++;
//     }
//     if(st.empty())return count;
//     return count+1;
//     }
int partitionString(string s) {
    int n=s.length();
    int lastSeen[26]={};
    int count=0;
    int start_substring = 0;

    for (int i = 0; i < n; i++)
    {
        char ch=s[i];
        if(lastSeen[ch-'a']>=start_substring){
            count++;
            start_substring=i+1;
        }
        lastSeen[ch-'a']=i+1;
    }
    return count;
    }
};