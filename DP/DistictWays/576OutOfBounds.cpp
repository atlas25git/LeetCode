class Solution {
public:
    const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dp[50][50][51] = {[0 ... 49] = {[0 ... 49] = {[0 ... 50] = -1}}};  // initialize all elements to -1 denoting not yet computed
public:    
bool outOfBounds(int m, int n, int r, int c) {
	return r < 0 || r >= m || c < 0 || c >= n;
}
int findPaths(int m, int n, int maxMove, int r, int c) {        
	bool isOut = outOfBounds(m, n, r, c);
	if(isOut || !maxMove) return isOut;
	if(dp[r][c][maxMove] != -1) return dp[r][c][maxMove];  // return if already computed result
	dp[r][c][maxMove] = 0;   // elements of dp are initalized to -1, so set to 0 before exploring moves
	for(int i = 0; i < 4; i++) 
		dp[r][c][maxMove] = (dp[r][c][maxMove] + findPaths(m, n, maxMove-1, r + moves[i][0], c + moves[i][1])) % mod;
	return dp[r][c][maxMove];
}
};

//Just memoize this
class Solution {
  public int findPaths(int m, int n, int N, int i, int j) {
    if (i == m || j == n || i < 0 || j < 0) return 1;
    if (N == 0) return 0;
    return findPaths(m, n, N - 1, i - 1, j)
        + findPaths(m, n, N - 1, i + 1, j)
        + findPaths(m, n, N - 1, i, j - 1)
        + findPaths(m, n, N - 1, i, j + 1);
  }
}