#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s == "") return "";
        string words;
        // ȥ����β�ո�
        int start = 0, end = s.size()-1;
        while(s[start] == ' '){
            start++;
        }
        while(s[end] == ' '){
            end--;
        }
        s = s.substr(start, end);
        
        
        cout << s << endl;
        
        // �Ӻ���ǰ˫ָ���������ȡһ�����ʾʹ浽words��
        int i = s.size()-1, j = i;
        cout << "original j = " << j << ", i = " << i << endl;
        while(i>=0){
            // ��ǰ���ҵ����ʵĵ�һ����ĸ
            while(i >= 0 && s[i] != ' '){
                i--;
            }
            // �ҵ��󣬽�ȡs[i]~s[j]�浽words
            cout << "s.substr(i+1, j-i) = " << s.substr(i+1, j-i) << endl;
            words += s.substr(i+1, j-i);
            words += " ";
            cout << "words  = " << words << endl;
            // ����j��λ��
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
