#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
class string
{
public:

	string(const char* src = NULL)
	{
		//TODO1：构造函数
		//开始添加代码
        if(src == NULL){
            m_data = new char[1];
            m_data[0] = '\0';
            m_length = 0;
        }else{
            m_length = strlen(src);
            m_data = new char[m_length + 1];
            strcpy(m_data, src);
        }
		//结束添加代码
	}

	~string()
	{
		//TODO2：析构函数
		//开始添加代码
        delete[] m_data;
		//结束添加代码
	}

	int size() const
	{
		return m_length;
	}

	const char *c_str() const
	{
		return m_data;
	}

	string(const string &src)
	{
		//TODO3：拷贝构造函数
		//开始添加代码
        m_length = src.size();
        m_data = new char[m_length + 1];
        strcpy(m_data, src.m_data);
		//结束添加代码
	}

	string operator+(const string &src) const
	{
		string ret;
		//TODO4：运算符+
		//开始添加代码
        int length = m_length + src.size();
		ret.m_length = length;
        ret.m_data = new char[length + 1];
        strcat(ret.m_data, m_data);
        strcat(ret.m_data, src.m_data);
		//结束添加代码
		return ret;
	}

	string& operator+=(const string &src)
	{
		//TODO5：运算符+=
		//开始添加代码		
		int length = m_length + src.size();
		m_length = length;
		char* m_data_copy = new char[length + 1];
		strcat(m_data_copy, m_data);
		strcat(m_data_copy, src.m_data);
		m_data = m_data_copy;
		//结束添加代码
		return *this;
	}

	bool operator==(const string &str) const
	{
		//TODO5：运算符==
		//开始添加代码
        if(strcmp(this->m_data, str.m_data) == 0) return true;
        else return false;
		//结束添加代码
	}

	void Reverse()
	{
		//TODO5：字符串反转
		//开始添加代码
		//std::cout << m_data << std::endl;
		int i = 0, j = size() - 1;
		if(i >= j) return;
		while(i < j){
			char t = m_data[i];
			m_data[i] = m_data[j];
			m_data[j] = t; 
			i++;
			j--;
		}
		return;
		//结束添加代码
	}

	void Sort()
	{
		//TODO6：字符串从小到大排序
		//开始添加代码
		qsort(m_data, m_length, sizeof(m_data[0]), cmp);
		//结束添加代码
	}
	static int cmp(const void* a, const void* b){
		char* _a = (char*)a;
		char* _b = (char*)b;
		return strcmp(_a, _b);
	}
private:
	char *m_data;
	int m_length;
};

int main()
{
	//构造函数
	string str1 = "abcde";
	string str2("12345");

	//拷贝构造函数
	string str3 = str1;
	std::cout << (str3 == str1) << std::endl;

	//拷贝构造函数
	string str4(str2);
	std::cout << (str2 == str4) << std::endl;

	//+ 运算符
	string str5 = str1 + str2;
	std::cout << (str5 == "abcde12345") << std::endl;
	std::cout << (str5.size() == str1.size() + str2.size()) << std::endl;

	//+= 运算符
	str5 += str1;
	std::cout << (str5 == "abcde12345abcde") << std::endl;

	//反转
	string str6 = "12345678";
	str6.Reverse();
	std::cout << (str6 == "87654321") << std::endl;

	//排序
	string str7 = "202008131617";
	str7.Sort();
	std::cout << (str7 == "000111223678") << std::endl;
	return 0;
}
