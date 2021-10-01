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
    int i,j,n,m,ans=0,cnt=0,sum=0;
        // cout<<"op"<<endl;
        string s;
        const char* k;
        getline(cin,s);

        stringstream ss(s);
        
        // k = s.c_str();

        auto tok = strtok((char*)s.c_str(),",");
        cout<<typeid(tok).name()<<endl;
        while(tok)
        {
            cout<<tok<<" ";
            tok = strtok(0,",");
        }
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