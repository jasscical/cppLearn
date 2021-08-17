#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> sum(1000);
long long m=9000000000000000000;

void search(int a,long long aVal,int b,long long bVal, int n)
{
    if(a>=n-1||b>=n) return;
    long long t=llabs(aVal-bVal);
    if(t<m) m=t;
    aVal+=sum[b];
    bVal-=sum[b];
    search(a,aVal,b+1,bVal, n);
    aVal-=sum[a];
    bVal+=sum[a];
    search(a+1,aVal,b+1,bVal, n);
}

long long minimum(vector<int>& sum){
    long long bVal;
    bVal = 0.0;
    for(int i = 1; i < sum.size(); i++) bVal += sum[i];
    search(0, sum[0], 1, bVal, sum.size());
    return m;
}

int main()
{
    //sum = {1, 2, 3, 4, 5};
    sum = {3, 45, 19, 23, 34, 78};
    long long res = minimum(sum);
    cout<<res<<endl;

    return 0;
}