#include <iostream>
#include <cstring>
using namespace std; 

Class String{
public:
	// 缺省构造函数 
	String(const char *str = nullptr);
	// 拷贝构造函数
	String(const String &str);
	// 字符串赋值函数
	String operator=(const String &str); 
	// 缺省析构函数 
	~String();
private:
	char *m_data;
	int m_size;
}

String::String(const char *str){
	// 对于传入的对象进行非空检查 
	if(str == nullptr){ 
		m_data = new char[1]; // 存放'\0'
		m_data[0] = '\0';
		m_size = 0;                                                                                              
	}else{
		// 不为空的话，需要构造一块合适的大小空间 存放str数据 
		m_size = strlen(str);
		m_data = new char[m_size + 1]； 
		strcpy(m_data, str);
	}
}
String::String(const String &str){
	m_size = str.m_size;
	m_data = new char[m_size + 1]; // 对 '\0' 所占空间加进去 
	strcpy(m_data, str.m_data);
} 
String& String::operator=(const String &str){ //返回类型 
	// 检查自赋值
	if(this == &str){
		return *this;
	} 
	delete[] m_data;
	m_size = strlen(str.m_data);
	m_data = new char[m_size +  1];
	strcpy(m_data, str.m_data); 
	
	return *this; // 返回本对象的引用 
} 
String::~String(){
	delete[] m_data;
}

