https://ac.nowcoder.com/discuss/390407

#include <bits/stdc++.h>	//know1[i]:i及i的左部分长度为k的区间最大值 
using namespace std;		//know2[i]:i及i的右部分长度为k的区间最大值  
#define ll long long
int t,n,k;ll a[200001],cal,know1[200001],know2[200001],ans,minx=-20000000000;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);cal=0;ans=minx;
		memset(know1,0,sizeof(know1[0])*n);
		memset(know2,0,sizeof(know2[0])*n);
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			cal+=a[i];
			if(i>=k-1){
				if(i!=k-1) know1[i]=max(know1[i-1],cal);
				else know1[i]=cal;
				cal-=a[i-k+1];
			}
		}
		cal=0;
		for(int i=n-1;i>=0;i--){
			cal+=a[i];
			if(n-i>=k){
				if(n-i!=k) know2[i]=max(know2[i+1],cal);
				else know2[i]=cal;
				cal-=a[i+k-1];
			}
		}
		for(int i=k-1;i+1<=n-k;i++){
			ans=max(ans,know1[i]+know2[i+1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
