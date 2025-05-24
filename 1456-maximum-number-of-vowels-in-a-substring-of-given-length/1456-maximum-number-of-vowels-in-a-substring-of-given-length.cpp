class Solution {
public:
bool isVowel(char a){
    return (a=='a' || a=='e' || a=='i' || a=='o'||a=='u');
}
int maxVowels(string s, int k) {
    int n=s.length();
    int current_cnt=0,max_cnt=INT_MIN;
    int i=0,j=0;
    while (j<n)
    {
        if(isVowel(s[j]))current_cnt++;
        if(j-i+1==k){
            max_cnt=max(max_cnt,current_cnt);
            if(isVowel(s[i]))current_cnt--;
            i++;
        }
        j++;
    }
    return max_cnt;
    }
};