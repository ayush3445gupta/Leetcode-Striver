class Solution {
public:
    pair<int,int> find(int n){
    int a=1,ans=0;
    while (n!=0)
    {
        int r=n%10;
        a*=r;
        n/=10;
        if(n==0)ans=r;
    }
    return {a,ans};
}
int smallestNumber(int n, int t) {
   if(n<10){
        if(n<t)return t;
        else if(n%t==0)return n;
        else
            return min(t*((n/t)+1),10);
    }
   
   int p= find(n).first;  
   if(p%t==0)return n;
   int first=find(n).second;
   int cnt=0;
   while (p%t!=0)
   {
    p+=first;
    cnt++;
   }
   return min(n+cnt,(first+1)*10);
    }
};