class Solution {
public:
    int fillCups(vector<int>& amount) {
    priority_queue<int>pq;
    int steps=0;
    for(int i:amount) 
        if(i!=0) pq.push(i);
    while (!pq.empty())
    {
        if(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            a-=1,b-=1;
            if(a>0)pq.push(a);
            if(b>0)pq.push(b);
        }
        else{
            return steps+pq.top();
        }
        steps++;
    }
    return steps;  
}
};