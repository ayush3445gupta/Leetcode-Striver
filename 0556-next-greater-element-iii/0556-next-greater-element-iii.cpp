class Solution {
public:
int nextGreaterElement(int n) {
        vector<int> digits;
        while (n!=0){
            int a=n%10;
            digits.push_back(a);
            n=n/10;
        }
        n=digits.size();
        reverse(digits.begin(), digits.end());
    int ind=-1;
    for (int i =n-2; i >=0; i--)
    {
       if(digits[i]<digits[i+1]){
        ind=i;
        break;
       }
    }
    if(ind==-1)return -1;
    for (int i =n-1; i>ind; i--)
    {
        if(digits[i]>digits[ind]){
            swap(digits[i],digits[ind]);
            break;
        }
    }
    reverse(digits.begin()+ind+1,digits.end());
    
    long long ans=0;
    for (int i = 0; i <digits.size(); i++)
    {
        ans=10*ans+digits[i];
        if(ans>INT_MAX)return -1;
    }
    return ans;
}
};