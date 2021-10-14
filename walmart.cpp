#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
    cin>>t;
    while(t--){
    int n,k;
	cin>>n>>k;
	double a[n],sum=0,res,m=n;
	for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		sum-=a[i]*k/100.0;
		m-=k/100.0;
		res=sum/m;
		if(res>=a[i-1]) {
			printf("%.7f",res);
			break;
		}
	}
    }
	return 0;
}