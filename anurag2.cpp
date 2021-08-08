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
const int N = 100005, M=22;
void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
    string str;
    cin>>str;

    vector<bool> mark(26,0);
    
    for(int i=0;str[i];i++)
    {
         if ('A' <= str[i] && str[i] <= 'Z')
            j = str[i] - 'A';
 
        else if ('a' <= str[i] && str[i] <= 'z')
            j = str[i] - 'a';
        else
            continue;
 
        mark[j] = true;
    }
    string answer;
    for(int i=0;i<26;i++)
    {
        if(!mark[i])answer += 'a' + i;
    }
    cout<<answer<<endl;
        
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
            // int t;
            // cin>>t;
            // while(t--)
            solve();
        }
    }