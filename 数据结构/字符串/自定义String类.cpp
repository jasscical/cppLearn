#include <iostream>
#include <cstring>
using namespace std; 

Class String{
public:
	// ȱʡ���캯�� 
	String(const char *str = nullptr);
	// �������캯��
	String(const String &str);
	// �ַ�����ֵ����
	String operator=(const String &str); 
	// ȱʡ�������� 
	~String();
private:
	char *m_data;
	int m_size;
}

String::String(const char *str){
	// ���ڴ���Ķ�����зǿռ�� 
	if(str == nullptr){ 
		m_data = new char[1]; // ���'\0'
		m_data[0] = '\0';
		m_size = 0;                                                                                              
	}else{
		// ��Ϊ�յĻ�����Ҫ����һ����ʵĴ�С�ռ� ���str���� 
		m_size = strlen(str);
		m_data = new char[m_size + 1]�� 
		strcpy(m_data, str);
	}
}
String::String(const String &str){
	m_size = str.m_size;
	m_data = new char[m_size + 1]; // �� '\0' ��ռ�ռ�ӽ�ȥ 
	strcpy(m_data, str.m_data);
} 
String& String::operator=(const String &str){ //�������� 
	// ����Ը�ֵ
	if(this == &str){
		return *this;
	} 
	delete[] m_data;
	m_size = strlen(str.m_data);
	m_data = new char[m_size +  1];
	strcpy(m_data, str.m_data); 
	
	return *this; // ���ر���������� 
} 
String::~String(){
	delete[] m_data;
}

