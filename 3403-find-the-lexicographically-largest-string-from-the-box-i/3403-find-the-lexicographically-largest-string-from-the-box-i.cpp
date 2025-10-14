class Solution {
public:
string answerString(string word, int numFriends) {
      int n=word.length();
      if(numFriends==1)return word;
      char mx_char='a';
      for (int i = 0; i < n; i++)
        if(word[i]>mx_char)mx_char=word[i];

    set<string>vec; 
    for (int i = 0; i < n; i++)
    {
        if(word[i]==mx_char){
            int leftslice=i;
            if(leftslice+1>=numFriends)
                vec.insert(word.substr(i));
            else{
            int req=numFriends-leftslice;
            int right=n-req;
            int len=right-i+1;
            vec.insert(word.substr(i,len));
            }
        }
    }
    auto it=vec.end();
    it--;
    return *it;  
    }
};