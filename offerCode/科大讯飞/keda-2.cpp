#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> input(n);
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        int j = i + 1;
        for(; j < n && input[j] == input[i]; j++);
        int tmp = j - i;
        if(i - 2 >= 0 && input[i - 2] == input[i]) tmp++;
        else if(j + 1 < n && input[i] == input[j + 1]) tmp++;
        if(tmp > res) res = tmp;
    }
    cout << res << endl;
    return 0;
}