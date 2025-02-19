class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
     int n=pizzas.size();
     sort(pizzas.begin(),pizzas.end());
     int totalGroups = n / 4;
     int odd = (totalGroups + 1)/2;
     int even = totalGroups/2;
     long long wt=0;
     for (int i =0; i <odd; i++)
     {
        wt+=pizzas[n-i-1];
     }
     int lastIdx=n-odd-2;
     while (even!=0)
     {
        wt+=pizzas[lastIdx];
        lastIdx-=2;
        even--;
     }
     return wt;
}
};