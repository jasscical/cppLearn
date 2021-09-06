#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// 多参数函数模板：实现任意类型转换
// 将要转换的数据放入stringstream流中，
// 然后将流中的数据放入我们转换目标对象，最后返回转换后的
// 调用：out_type o =  convert<out_type>(in_value)
template<typename out_type, typename in_value>
out_type convert(const in_value & t){
    stringstream stream;
    stream << t;//向流中传值
    out_type result;//这里存储转换结果
    stream >> result;//向result中写入值
    return result;
}


int main(){
    // 字符串 -> 整数
    string str = "0012345";
    int sta = convert<int>(str);
    cout << sta << endl;

    // 整数 -> 字符串
    int a = 56789;
    string ats = convert<string>(a);
    cout << ats << endl;

    // 字符 -> 整数
    char c = '9';
    int cti = convert<int>(c);
    cout << cti << endl;
    cout << c - '0' << endl;

    // 整数 -> 字符
    int b = 7;
    char itc = convert<char>(b);
    cout << itc << endl;
    cout << char(b + '0') << endl;
}