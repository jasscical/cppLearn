//��д�ԣ�https://www.jianshu.com/p/1e625af51a3a
#include<bits/stdc++.h>
using namespace std;
const int N=100010;

int order[N];  //order[id]  ��id�ŵ���һ�εĶ��� ʱ�� 
int prior[N];  //prior[id]  ��id�ŵ�����ȼ�
int flag[N];   //flag[id]   ��id�ŵ��ڲ������Ȼ�����

struct node{
    int time,id;
}a[N];

bool cmp(node a, node b){
    if(a.id==b.id) // ͬһ�ҵ꣬�Ͱ��ʹ�ʱ����Ⱥ�˳�� ���� 
        return a.time<b.time;
    return a.id<b.id;  // ����ͬһ�ҵ꣬�Ͱ� id ���� 
}

int main(){
    /*
    n -- �������� 
	m -- ������ 
	T -- ʱ�� 
	*/ 
	
	int m,n,T;  cin>>n>>m>>T;
    for(int i=0;i<m;i++)
        cin>>a[i].time>>a[i].id;  // ÿһ ���������ʹ�ʱ��time + �ʹ��ŵ� id 
    
	sort(a,a+m,cmp); //��ʱ������
    
	// 1.ÿ��һ����������ָ���ŵ��Ӱ�� 
	for(int i=0;i<m;i++){
        int tt=a[i].time,  id=a[i].id; // �� i ��������Ӧ�� ʱ�� tt,�ʹ��ŵ� id 
        
		// ��ʱttʱ�̣���������������� i ���� �ŵ����ȼ�prior[id]��Ӱ�� 
		if(tt != order[id])  //�����ǰ������������һ�εĶ��������ȥ����֮��ļ�� ==> ���Ϊ�������µĶ��� 
            prior[id] -= tt-order[id]-1;
        prior[id] = prior[id] < 0 ? 0: prior[id];  //��С��0
        
		if(prior[id]<=3)  flag[id]=0;
        prior[id]+=2;
        if(prior[id]> 5)  flag[id]=1;
        
		order[id]=tt;  // ���´˿̶���Ϊ��һ�ζ�����Ϊ�´�ʹ�� 
    }
    
    //  2.�� 1 ����ÿһ���������͵Ĺ����У� ֻ������ض����ŵ�id�������ȼ�Ӱ�� ������ʱ�����ŵ�û�нӵ���������ʵ���ȼ�Ҳ����Ӱ��ģ�������ʱ���ڵݼ� 
    // ���ﴦ�� n ���ŵ꣬������һ�Σ��������Ϊ�������������һ�Σ�ʱ��order[i] ���� ������������ Tʱ�� �ж�ã����������ȼ� prior[i]
	for(int i=1;i<=n;i++)  //������Tʱ��
        if(order[i]<T){
            prior[i] -= T-order[i];
            if(prior[i]<=3)
                flag[i]=0;
        }

    // 3.ͳ�����ȼ� 
	int ans=0;
    for(int i=0;i<=n;i++)
        if(flag[i])
            ans++;
    cout<<ans;
    return 0;
}

