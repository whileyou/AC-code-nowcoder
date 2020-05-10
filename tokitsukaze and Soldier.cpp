https://ac.nowcoder.com/discuss/390407

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,cal,num,min_; 
priority_queue<ll,vector<ll>,greater<ll>> q;
struct sol{
	ll v,s;
}sol[100001];
bool cmp(struct sol a,struct sol b)
{
	return a.s>b.s;
}
int main()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	scanf("%lld %lld",&sol[i].v,&sol[i].s);
	sort(sol,sol+n,cmp);
	for(int i=0;i<n;i++)
	{
		min_=sol[i].s;
		while(num>=min_) cal-=q.top(),q.pop(),num--;
		q.push(sol[i].v);num++;
		cal+=sol[i].v;ans=max(ans,cal);
	}
	printf("%lld",ans);
	return 0;
}
