class Solution {
public:
vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
    if(digits[n-1]!=9){
        digits[n-1]+=1;
        return digits;
    }    
    vector<int>res;
    int catche=0;
    int i=n-1;
    while(i>=0 && digits[i]==9)
    {
        res.push_back(0);
        catche=1;
        i--;
    }
    if(i<0)res.push_back(1);
    else{
        res.push_back(digits[i]+1);
        i--;
        while (i>=0)
        {
            res.push_back(digits[i]);
            i--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
    }
};