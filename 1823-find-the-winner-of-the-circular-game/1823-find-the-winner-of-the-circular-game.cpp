class Solution {
public:
// int findTheWinner(int n, int k) {
//     vector<int>vec;
//     for (int i = 1; i <=n; i++)
//     {
//         vec.push_back(i);
//     }
    
//     int start=0;
//     while (vec.size()>1)
//     {
//         int erase_idx = (start+k-1)%vec.size();
//         vec.erase(vec.begin()+erase_idx);
//         start  = erase_idx;
//     }
//     return vec.front();
//     }

int findTheWinner(int n, int k) {
    queue<int>q;
    for (int i = 1; i <=n; i++)
    {
      q.push(i);
    }
    
    while (q.size()>1)
    {
        for (int i = 1; i <=k-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
    }
};