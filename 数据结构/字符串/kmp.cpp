#include <vector>
#include <iostream>
using namespace std;

// 计算最长重复前后缀列表
void prefixTable(string& pattern, vector<int>& prefix){
    prefix[0] = 0; 
    int len = 0; // 前面字符
    int i = 1; // 当前字符 从下标1开始
    while(i < pattern.size()){
        // 当前字符跟前面len对应的字符匹配上
        if(pattern[i] == pattern[len]){
            ++len;
            prefix[i] = len;
            ++i;
        }
        // 当前字符跟前面len对应的字符 没有匹配上
        else{
            // len - 1 ==》len退为prefix[len - 1]
            if(len > 0){
                len = prefix[len - 1];
            }
            // len = 0，无法再退
            else{ 
                prefix[i] = 0;
                ++i;
            }
        }
    }
}

// 往前移动一个位置，把第一个置为 -1
void movePrifixTable(vector<int>& prefix){
    for(int i = prefix.size() - 2; i >= 0; i--){
        prefix[i + 1] = prefix[i];
    }
    prefix[0] = -1;
}

void kmpSearch(string& text, string& pattern){
    vector<int> prefix(pattern.size(), 0);
    prefixTable(pattern, prefix);
    movePrifixTable(prefix);

    int i = 0;
    int j = 0;
    while(i < text.size()){
        // 匹配串到了最后一个位置且最后一个位置也匹配
        // 那么说明匹配到一个子串
        // text后面可能能再找到匹配的子串
        // 所以 j 跳到prefix[j]跟text[i]匹配
        if(j == pattern.size() - 1 && text[i] == pattern[j]){
            cout << "Found at index: " << i - j << endl;
            j = prefix[j];
        }
        // 当前位置i的字符与匹配位置j的字符相等
        if(text[i] == pattern[j]){
            ++i;
            ++j;
        }
        // 当前位置i的字符与匹配位置j的字符不相等
        else{
            // j跳到prefix[j]开始匹配
            j = prefix[j];
            // 如果 j 跳到-1，那么都往前移动一格
            if(j == -1){
                ++i;
                ++j;
            }
        }
    }
    

}

int main(){   
    string pattern = "ABABCABAA";
    string text = "ABABABCABAABABABABCABAA";
    /*
    vector<int> prefix(pattern.size(), 0);
    prefixTable(pattern, prefix);

    cout << "original prefix: " << endl;
    for(auto p:prefix) cout << p << "\t";
    cout << endl;

    cout << "move prefix:" << endl;
    movePrifixTable(prefix);
    for(auto p:prefix) cout << p << "\t";
    cout << endl;  
    */
    kmpSearch(text, pattern);
}