class Solution {
public:
   int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
     int n=capacity.size();
     vector<int>extras(n);
     for (int i = 0; i < n; i++)
        extras[i]=capacity[i]-rocks[i];
     sort(begin(extras),end(extras));
     int counter=0;
     
     for (int i = 0; i < n; i++)
     {
        if(extras[i]==0)counter++;
        else{
            if(additionalRocks>=extras[i]){
                counter++;
                additionalRocks-=extras[i];
            }
            else return counter;
        }
     }
    return counter;    
    }
};