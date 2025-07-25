class Solution {
public:
vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
     int n=grid.size();
     
    for (int row = 0; row < n; row++)
    {
        int col = 0;
        vector<int>temp;
        int temprow=row;
        while (temprow<n &&  col<n)
        {
          temp.push_back(grid[temprow][col]);
          temprow++,col++;       
        }
        sort(rbegin(temp),rend(temp));
        col=0;
        temprow=row;
        while (temprow<n && col<n)
        {
            grid[temprow][col] = temp[col];
            temprow++;col++;
        }
    }
    
    for (int col = 1; col < n; col++)
    {
       int row=0;
       vector<int>temp;
       int tempcol=col;
       while (tempcol<n && row<n)
       {
        temp.push_back(grid[row][tempcol]);
        tempcol++,row++;
       }
       sort(begin(temp),end(temp));

       row=0;
       tempcol=col;
       while (row<n && tempcol<n)
       {
        grid[row][tempcol]=temp[row];
        row++,tempcol++;
       }  
    }
     return grid;
    }
};