#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s == "") return "";
        string words;
        // 去除首尾空格
        int start = 0, end = s.size()-1;
        while(s[start] == ' '){
            start++;
        }
        while(s[end] == ' '){
            end--;
        }
        s = s.substr(start, end);
        
        
        cout << s << endl;
        
        // 从后往前双指针遍历，截取一个单词就存到words中
        int i = s.size()-1, j = i;
        cout << "original j = " << j << ", i = " << i << endl;
        while(i>=0){
            // 往前走找到单词的第一个字母
            while(i >= 0 && s[i] != ' '){
                i--;
            }
            // 找到后，截取s[i]~s[j]存到words
            cout << "s.substr(i+1, j-i) = " << s.substr(i+1, j-i) << endl;
            words += s.substr(i+1, j-i);
            words += " ";
            cout << "words  = " << words << endl;
            // 更新j的位置
            while(s[i] == ' '){
                i--;
            }
            cout << "j = " << j << ", i = " << i << endl;
            j = i;
            cout << "after j = " << j << ", i = " << i << endl;
            cout << endl;
        }
        //words.pop_back();
        return words;
    }
};

int main(){
	Solution s;
	string res = s.reverseWords(" hello world! ");
	cout << "res = " << res;
	return 0;
}
