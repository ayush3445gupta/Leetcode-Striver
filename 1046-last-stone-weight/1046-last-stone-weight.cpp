class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int>pq;
       for(int w:stones)pq.push(w);
       while (pq.size()>1)
       {
        int w1=pq.top();
        pq.pop();
        int w2=pq.top();
        pq.pop();
        pq.push(abs(w2-w1));
       }
        return pq.top();
    }
};