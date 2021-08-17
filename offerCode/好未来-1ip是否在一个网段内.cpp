#include <bits/stdc++.h>
using namespace std;

 
vector<string> split(const string& str, const string& delim) {  
	vector<string> res;  
	if("" == str) return res;  
	//先将要切割的字符串从string类型转换为char*类型  
	char * strs = new char[str.length() + 1] ; //不要忘了  
	strcpy(strs, str.c_str());   
 
	char * d = new char[delim.length() + 1];  
	strcpy(d, delim.c_str());  
 
	char *p = strtok(strs, d);  
	while(p) {  
		string s = p; //分割得到的字符串转换为string类型  
		res.push_back(s); //存入结果数组  
		p = strtok(NULL, d);  
	}  
 
	return res;  
} 


string& replace_all(string& src, const string& oldStr, const string& newStr){
	string::size_type pos = 0;
	while((pos = src.find(oldStr, pos)) != string::npos){
		src.replace(pos, oldStr.size(), newStr);
		pos += oldStr.size();
	}
	return src;
}

bool isInRange(string& ip, string& cidr) {
    vector<string> ips = split(ip, "\\.");
    int ipAddr = (stoi(ips[0]) << 24)
            | (stoi(ips[1]) << 16)
            | (stoi(ips[2]) << 8) | stoi(ips[3]);
    string ct = replace_all(cidr, ".*/", "");
    int type = stoi(ct);
    int mask = 0xFFFFFFFF << (32 - type);

    string cidrIp = replace_all(cidr, "/.*", "");  
    vector<string> cidrIps = split(cidrIp, "\\.");

    int cidrIpAddr = (stoi(cidrIps[0]) << 24)
            | (stoi(cidrIps[1]) << 16)
            | (stoi(cidrIps[2]) << 8)
            | stoi(cidrIps[3]);

    return (ipAddr & mask) == (cidrIpAddr & mask);
}




int main() {
        string ip = "192.168.1.12";
        string cidr = "192.168.1.64/28";
        if(isInRange(ip, cidr)) cout << "true" << endl;
        else cout << "false" << endl;
}
 