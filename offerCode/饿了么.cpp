//改写自：https://www.jianshu.com/p/1e625af51a3a
#include<bits/stdc++.h>
using namespace std;
const int N=100010;

int order[N];  //order[id]  第id号店上一次的订单 时刻 
int prior[N];  //prior[id]  第id号店的优先级
int flag[N];   //flag[id]   第id号店在不在优先缓存中

struct node{
    int time,id;
}a[N];

bool cmp(node a, node b){
    if(a.id==b.id) // 同一家店，就按送达时间的先后顺序 升序 
        return a.time<b.time;
    return a.id<b.id;  // 不是同一家店，就按 id 升序 
}

int main(){
    /*
    n -- 外卖店数 
	m -- 订单数 
	T -- 时刻 
	*/ 
	
	int m,n,T;  cin>>n>>m>>T;
    for(int i=0;i<m;i++)
        cin>>a[i].time>>a[i].id;  // 每一 个订单：送达时间time + 送达门店 id 
    
	sort(a,a+m,cmp); //按时间排序
    
	// 1.每送一个外卖，对指定门店的影响 
	for(int i=0;i<m;i++){
        int tt=a[i].time,  id=a[i].id; // 第 i 个订单对应的 时刻 tt,送达门店 id 
        
		// 此时tt时刻，送完这个订单外卖 i ，对 门店优先级prior[id]的影响 
		if(tt != order[id])  //如果当前订单不等于上一次的订单，则减去它们之间的间隔 ==> 理解为出现了新的订单 
            prior[id] -= tt-order[id]-1;
        prior[id] = prior[id] < 0 ? 0: prior[id];  //不小于0
        
		if(prior[id]<=3)  flag[id]=0;
        prior[id]+=2;
        if(prior[id]> 5)  flag[id]=1;
        
		order[id]=tt;  // 更新此刻订单为上一次订单，为下次使用 
    }
    
    //  2.第 1 步中每一个外卖在送的过程中， 只是针对特定的门店id产生优先级影响 ，但此时其他门店没有接到订单，其实优先级也是有影响的，就是随时间在递减 
    // 这里处理 n 个门店，计算上一次（可以理解为送完外卖的最后一次）时刻order[i] 距离 送完所有外卖 T时刻 有多久，来计算优先级 prior[i]
	for(int i=1;i<=n;i++)  //最后处理第T时刻
        if(order[i]<T){
            prior[i] -= T-order[i];
            if(prior[i]<=3)
                flag[i]=0;
        }

    // 3.统计优先级 
	int ans=0;
    for(int i=0;i<=n;i++)
        if(flag[i])
            ans++;
    cout<<ans;
    return 0;
}

