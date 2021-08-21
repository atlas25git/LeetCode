class Solution
{
public:
	int kthSmallest(vector<vector<int>>& matrix, int k)
	{   
        vector<int>s({1,2,3,4});
        cout<<lower_bound(s.begin(),s.end(),5)-s.begin()<<endl;
        cout<<upper_bound(s.begin(),s.end(),5)-s.begin()<<endl;

		int n = matrix.size();
		int le = matrix[0][0], ri = matrix[n - 1][n - 1];
		int mid = 0;
		while (le < ri)
		{
			mid = le + (ri-le)/2;
			int num = 0;
			for (int i = 0; i < n; i++)
			{   //for the rows not containg the element their len will be added
				// int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				int pos = lower_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();                
                
                if(pos<matrix[i].size())pos++;
                
                // cout<<"Row No"<<k<<endl;
                //cout<<pos<<endl;
				num += pos;
			}
			if (num < k)
			{
				le = mid + 1;
			}
			else
			{
				ri = mid;
			}
		}
		return le;
	}
};