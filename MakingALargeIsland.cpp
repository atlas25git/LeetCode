
class Solution {
public:
	int largestIsland(vector<vector<int>>& g) {
		int n = g.size();
		vector<int> vCount(2,0);    //Storage area of islands with different Numbers
		int number = 2;                //We set the number of the first island to 2
		int maxNum = 1;                
		for (int i = 0; i<g.size(); i++)
			for (int j = 0; j<g[i].size(); j++)    
				if (g[i][j] == 1)
				{
					int others = 0;
					int count = 0;
					fun(g,vCount, count, i, j, number,others);    //Depth first search
					number++;
					vCount.push_back(count);
					maxNum = max(maxNum, count + others+1);
				}
		return maxNum>n*n ? n*n : maxNum;
	}
	void fun(vector<vector<int>>& g, vector<int>& vCount, int& count, int i, int j, int& number,int& others) {
		if (i<0 || i==g.size() || j<0 || j==g.size() || g[i][j] > 1) return;
		if (g[i][j] == 0) {
			int up(0), down(0), left(0),temp(0);  
			if (i > 0 && g[i - 1][j] != number) {
				temp += vCount[g[i - 1][j]];    //There is  a islands on the top of different number;
				up = g[i - 1][j];
			}
			if (i < g.size() - 1 && g[i + 1][j] != number&&g[i + 1][j] != up) {
				temp += vCount[g[i + 1][j]];   //There is  a islands below of different number;
				down = g[i + 1][j];
			}
			if (j > 0 && g[i][j - 1] != number&&g[i][j - 1] != up&&g[i][j - 1] != down) {
				temp += vCount[g[i][j - 1]];   //There is  a islands on the left of different number;
				left = g[i][j - 1];
			}
			if (j < g.size() - 1 && g[i][j + 1] != number&&g[i][j + 1] != up&&g[i][j + 1] != down&&g[i][j + 1] != left) 
				temp += vCount[g[i][j + 1]];       //There is  a islands on the right of different number;
			others = max(others, temp);    //If we change this 0 to 1, the total area of the surrounding islands
			return;
		}
		g[i][j] = number;
		count++;
		fun(g, vCount, count, i - 1, j, number,others);
		fun(g, vCount, count, i + 1, j, number, others);
		fun(g, vCount, count, i, j - 1, number, others);
		fun(g, vCount, count, i, j + 1, number, others);
	}
