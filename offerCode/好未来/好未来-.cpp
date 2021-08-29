#include <bits/stdc++.h>
using namespace std;

int FindSubstring(string& pSrc, string& pSub){
    string::size_type pos;
    if((pos = pSrc.find(pSub)) != string::npos) return pos;
    else return -1;
}

int main(){
    char s1[10000], s2[10000];
    scanf("%s", s1);
    scanf("%s", s2);
    //cin >> s1 >> s2;
    string pSrc = s1, pSub = s2;
    int res = FindSubstring(pSrc, pSub);
    cout << res << endl;
    return 0;
}