https://ac.nowcoder.com/discuss/390407

//优先队列+贪心
//优先队列:自动排序--->将战力小的排在前面
//贪心:1.原算法:将人数从min到max的战力依次算出,记录最大值即可
//     2.贪心简化:从max人数算到min,计算时用优先队列减少人数(即弹走战力小的),减少计算量(O(nlogn)),再记录最大值即可

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
