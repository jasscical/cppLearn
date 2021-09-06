#include <bits/stdc++.h>
using namespace std;

/*
样例输入
4
1 2 3 4
2 4 3 4
样例输出
8
*/




int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    // 贪心的思想，先装最大的
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> c(a.size());
    int index = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (index >= 0 && b[index] >= a[i]) {
            index--;
        }     
        c[i] = n - index - 1 ;
    }

    for(int cc:c) cout << cc << " ";
    cout << endl;
    // c  4 4 3 2    有几个书架能装下该书
    // a  1 2 3 4    书 
    //         /|
    // b  2 3 4 4    书架
    
    long res = c[n - 1];
    int tmp = 1; // 统计已用了几个书架
    long MOD_M = 1000000007;
    for(int i = n - 2; i > 0 ; i--) {
        res = res * (c[i] - tmp) % (MOD_M);
        tmp++;
    }
    cout << res << endl;
}

/*
public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int[] c = new int[n];
        int index = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (index >= 0 && b[index] >= a[i])
                index--;
            c[i] = n - index -1 ;
        }
        long res=c[n-1];
        int tmp =1;
        long MOD_M = 1000000007 ;
        for (int i = n-2; i >0 ; i--) {
            res = res * (c[i] - tmp) % (MOD_M);
            tmp++;
        }
        System.out.println(res);
//        for (int i = 0; i < n; i++) {
//            System.out.println(c[i]);
//        }
    }
}


vector<int> path;
long res = 0;
void backtracking(vector<int>& nums, vector<int>& b, vector<bool>& used){
    if(path.size() == nums.size()){
        int j = 0;
        for(; j < b.size(); j++){
            if(b[j] < path[j]) break;
        }
        if(j == b.size()) res++;
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
            continue;
        }
        if(nums[i] > b[i]) return;
        if(used[i] == false){
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, b, used);
            path.pop_back();
            used[i] = false;
        }
    }
}

*/