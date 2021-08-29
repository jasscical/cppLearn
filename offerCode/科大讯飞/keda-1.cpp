#include <bits/stdc++.h>
using namespace std;
static bool cmp(int a, int b){
    return a > b;
}
int main(){
    int n = 50;
    vector<int> score(50);
    for(int i = 0; i < 50; i++){
        cin >> score[i];
    }
    int target;
    cin >> target;
    
    sort(score.begin(), score.end(), cmp);
    int i;
    for(i = 0; i < score.size(); i++){
        if(score[i] == target) break;
    }
    if(i >= 0 && i <= 4) cout << "A+" << endl;
    if(i >= 5 && i <= 14) cout << "A0" << endl;
    if(i >= 15 && i <= 29) cout << "B+" << endl;
    if(i >= 30 && i <= 34) cout << "B0" << endl;
    if(i >= 35 && i <= 44) cout << "C+" << endl;
    if(i >= 45 && i <= 47) cout << "C0" << endl;
    if(i >= 48 && i <= 49) cout << "F" << endl;
    return 0;
}