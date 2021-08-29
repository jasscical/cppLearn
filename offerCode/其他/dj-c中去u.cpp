#include <bits/stdc++.h>

using namespace std;

/*
样例输入
d:3,D:5,A:10#d:2,A:9
样例输出
d:1,D:5,A:1
*/

/*


*/

#include <iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    string s = "d:3,D:5,A:10#d:2,A:9";
    //cin >> s;
    map<char, int> m;
    auto pos = s.find('#');
    string C = s.substr(0, pos);
    string U = s.substr(pos+1);
    if (U == "")
        cout << C << "#";
    pos = C.find(',');
 
    while (pos != string::npos)
    {
        string mh = C.substr(0, pos);
        C = C.substr(pos + 1);
        char zimu = mh[0];
        int num = atoi(mh.substr(2).c_str());
        m[zimu] = m[zimu] + num;

        pos = C.find(',');
    }
    m[C[0]] = m[C[0]] + atoi(C.substr(2).c_str());

    pos = U.find(',');
    while (pos != string::npos)
    {
        string mh = U.substr(0, pos);
        U = U.substr(pos + 1);
        auto pos_mh = mh.find(':');
        char zimu = mh[0];
        int num = atoi(mh.substr(2).c_str());
        m[zimu] = m[zimu] - num;

        pos = U.find(',');
    }
    m[U[0]] = m[U[0]] - atoi(U.substr(2).c_str());

    
    int Size = m.size();
    int i = 0;
    for (auto x : m) {
        ++i;
        cout << x.first << ":" << x.second;
        if (i != Size) {
            cout << ",";
        }
        
    }
    cout << endl;
}




/*
int main(){
    map<char, int> umap;
    string str = "d:3,D:5,A:10#d:2,A:9";
    //cin >> str;
    int i = 0;
     while( i < str.size() && str[i] != '#'){
         char _key = str[i];
         if( isalpha(_key) ){
             // d:200,
             // 截取":"后  ","前的数字字符
             int pos = i + 2;
             while(i < str.size() && isdigit(str[i])) ++i;
             if( i < str.size() && str[i] == ','){
                string tmp = str.substr(pos, i - pos);
                if(tmp != ""){
                    int tValue = stoi(tmp); 
                    umap[_key] = tValue;
                }
             }
         }
     }
    if(i >= str.size()) cout << str << endl;
    while(i < str.size()){
        char _key = str[i];
         if( isalpha(_key) ){
             // d:200,
             // 截取":"后  ","前的数字字符
             int pos = i + 2;
             while(i < str.size() && isdigit(str[i])) ++i;
             if( i < str.size() && str[i] == ','){
                string tmp = str.substr(pos, i - pos);
                if(tmp != ""){
                    int tValue = stoi(tmp); 
                    umap[_key] -= tValue;
                }
             }
         }
    }

    int k = 0;
    for(const auto& iter : umap){
        if(k < str.size()){
            cout << iter.first << ":" << iter.second << ",";
            ++k;
        }
    }
    return 0;
}
*/