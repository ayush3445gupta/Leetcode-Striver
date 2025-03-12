class Solution {
public:
    int largestInteger(int num) {
    //  bruteforce
    // use 2 pq for even and odd
    int n2=num;
    vector<int>vec;
    priority_queue<int>pq_even,pq_odd;
    while (n2>0)
    {
        int r=n2%10;
        if(r%2!=0)pq_odd.push(r);
        else pq_even.push(r);
        vec.push_back(r);
        n2/=10;
    }
    int ans=0,i=0;
    for (int i =vec.size()-1; i>=0; i--)
    {
        if(vec[i]&1){
            ans+=(pq_odd.top()*pow(10,i));
            pq_odd.pop();
        }
        else {
            ans+=(pq_even.top()*pow(10,i));
            pq_even.pop();
        }
    }
    
    return ans;
}
};