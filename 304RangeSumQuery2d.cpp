class NumMatrix
{
  private:
    vector<vector<int>> arr, bit;
    int n, m;

    int lowbit(int x)
    {
        return x & (-x);
    }

    int prefixSum(int row, int col)
    {
        int sum = 0;
        for (int i = row + 1; i > 0; i -= lowbit(i))
        {
            for (int j = col + 1; j > 0; j -= lowbit(j))
            {
                sum += bit[i][j];
            }
        }
        return sum;
    }

  public:
    NumMatrix(vector<vector<int>> matrix)
    {
        n = matrix.size();
        m = matrix[0].size();
        arr = vector<vector<int>>(n, vector<int>(m, 0));
        bit = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val)
    {
        int delta = val - arr[row][col];
        arr[row][col] = val;

        for (int i = row + 1; i <= n; i += lowbit(i))
        {
            for (int j = col + 1; j <= m; j += lowbit(j))
            {
                bit[i][j] += delta;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return (
            prefixSum(row2, col2) -
            prefixSum(row2, col1 - 1) -
            prefixSum(row1 - 1, col2) +
            prefixSum(row1 - 1, col1 - 1));
    }
};