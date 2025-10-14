class Solution {
public:

// string answerString(string word, int numFriends) {
//       int n=word.length();
//       if(numFriends==1)return word;
//       char mx_char='a';
//       for (int i = 0; i < n; i++)
//         if(word[i]>mx_char)mx_char=word[i];

//     set<string>vec; 
//     string res;
//     for (int i = 0; i < n; i++)
//     {
//         if(word[i]==mx_char){
//             int leftslice=i;
//             if(leftslice+1>=numFriends)
//             res=max(res,word.substr(i));
//             else{
//             int req=numFriends-leftslice;
//             int right=n-req;
//             int len=right-i+1;
//             res=max(res,word.substr(i,len));
//             }
//         }
//     }
//     return res;  
//     }

string lastSubstring(string s) {
    int n=s.length();
    int i=0,j=1,k=0;
    while(j+k<n){
        if(s[i+k]==s[j+k])k++;
        else if(s[i+k]>s[j+k]){
            j+=k+1;
            k=0;
        }
        else {
            i=max(i+k+1,k);
            j=i+1;
            k=0;
        }
    }
    return s.substr(i);
    }
   string answerString(string word, int numFriends) {
    if(numFriends==1)return word;

    string last=lastSubstring(word);
    int n=word.size(),m=last.size();
    return last.substr(0,min(m,n-numFriends+1))
   }
};