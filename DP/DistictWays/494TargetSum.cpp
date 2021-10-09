class Solution {
public:
    // map<pair<int,int>,int> memo;
    int offset = 0;
    vector<vector<int>> dp;
    int findTargetSumWays(vector<int>& nums, int target) {
     
        for(auto x: nums)offset+=x;
        dp.resize(nums.size()+1,vector<int>(2*offset+1,INT_MIN));
        
        
        
        
        return dp[nums.size()][offset+];//recft(nums,target,0,0);
    }
    
    int recft(vector<int>& nums, int target,int i,int sum)
    {
        if(i==nums.size())
        {
            if(target == sum)return 1;
            else return 0;
        }
        // if(memo.count({i,sum}))return memo[{i,sum}];
           if(dp[i][offset + sum]!=INT_MIN)return dp[i][offset+sum];

        return dp[i][offset + sum] = recft(nums,target,i+1,sum+nums[i]) + recft(nums,target,i+1,sum-nums[i]);
    }
};

class Solution {
public:
    
    vector<vector<int>> dp;
    int offset = 0;
    int findTargetSumWays(vector<int>& nums, int t) {
        for(auto x: nums)offset+=x;
        dp.resize(offset + offset + 1,vector<int>(nums.size(),INT_MIN));
        return calc(t,0,0,nums);
    }
    
    int calc(int t,int i,int sum,vector<int>& nums)
    {
        if(i == nums.size())
        {
            if(sum == t)return 1;
            else return 0;
        }
        if(dp[offset + sum][i]!=INT_MIN)
            return dp[offset + sum][i];
        int add = calc(t,i+1,sum+nums[i],nums);
        int sub = calc(t,i+1,sum-nums[i],nums);
        return dp[offset + sum][i] = add + sub;
    }
};

int findTargetSumWays(vector<int>& nums, int S) {
	int sum = 0;
	for (auto n : nums) sum += n;
	if ((sum + S) % 2 == 1 || S > sum || S < -sum) return 0;
	int newS = (sum + S) / 2;
	vector<int> dp(newS + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = newS; j >= nums[i]; --j) {
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp[newS];
}

/***************************************
*****Solution authored by Atlas25.******
*****************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int mod = 1e9 + 7;
const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
int fact[N], inv[N], invfact[N];
void factInverse() {
fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
for (long long i = 2; i < N; i++) {
fact[i] = (fact[i - 1] * i) % MOD;
inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
}
}
const std::string WHITESPACE = " \n\r\t\f\v";
std::string ltrim(const std::string &s)
{
size_t start = s.find_first_not_of(WHITESPACE);
return (start == std::string::npos) ? "" : s.substr(start);
}
std::string rtrim(const std::string &s)
{
size_t end = s.find_last_not_of(WHITESPACE);
return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
std::string trim(const std::string &s) {
return rtrim(ltrim(s));
}
int add(int a, int b) {
if ((a += b) >= MOD)
    a -= MOD;
else if (a < 0)
    a += MOD;
return a;
}
int mul(int x, int y) {
    return (1LL * x * y) % MOD;
}
int nCr(int n, int r) {
    if (r > n)
        return 0;
    return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}
vector<string> tokenize(string s, const char* del)
{
    vector<string> res;
    auto x = s.c_str();
    char y[s.size()+1];
    strcpy(y,x);
    auto tok = strtok(y,del);
    while(tok)
    {
    res.push_back(string(tok));
    tok = strtok(0,del);
    }
    return res;
}
void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        
}
void init() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int32_t main(){
    init();
        {
            int t;
            cin>>t;
            while(t--)
            solve();
        }
    }