class Solution {
public:
string generateTag(string caption) {
      string res="#";
      int n = caption.length();
      int i=0,j=0;
      int f=0;
      while (j<n && res.length()<100)
      {
        if(caption[j]==' '){
            string temp = caption.substr(i,j-i);
            if(f==0)
            {
                for(char& c:temp){
                    if(c!=tolower(c))c=c-'A'+'a';
                }
                f=1;
            }
            else{
                for (int l = 0; l < temp.length(); l++)
                {
                    char c = temp[l];
                    if(l==0){
                        if(c!=toupper(c)) c=c-'a'+'A';
                    }
                    else{
                        if(c!=tolower(c)) c = c-'A'+'a';
                    }
                    temp[l]=c;
                }
            }
            res+=temp;
            j++;
            i=j;
        }
        else j++;
      }

      string k = caption.substr(i,min(99,j-i));
      if(f==0){
            for (int i = 0; i < k.length(); i++)
            {
                char c = k[i];
                if(c!=tolower(c))c=c-'A'+'a';
                k[i]=c;
            }
    }
    else{
        for (int i = 0; i < k.length(); i++)
        {
            char c = k[i];
            if(i==0){
                if(c!=toupper(c))c=c-'a'+'A';
            }
            else{
                if(c!=tolower(c)) c = c-'A'+'a';
            }
            k[i]=c;
        }
    }
      res+=k;
      return res;
    }
};