#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, a;
    getline(cin, s);
    getline(cin, a);
    int countChar = 0;
    for(int i = 0, j = 0; i < a.size(); ){
        while(1){
            if(j == s.size()) j = 0;
            if(s[j] == a[i]){
                j++;
                break;
            }else{
                j++;
                countChar++:
            }
        }
        i++;
    }
    cout << countChar << endl;
    return 0;
}