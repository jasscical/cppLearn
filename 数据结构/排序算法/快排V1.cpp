#include <iostream> 
#include <vector>
using namespace std;


void quickSort(vector<int>& arr, int l, int r){
        if(l >= r) return; // ������ֻ��һ����ʱ����ֹ�ݹ�
        int i = l, j = r;  //�ڱ����ַ�Χ���� arr[l] ��ߵ�һ������Ϊ��׼����
        int &p = arr[l];
		while(i < j){
           	while(i < j && arr[j] >= p) j--; //������while��˳��� ��j�ұ�ȫ�������ڱ�ֵ 
            while(i < j && arr[i] <= p) i++; // i ���ȫ��С���ڱ�ֵ 
            swap(arr[i], arr[j]);  //��ʱ����i,jλ�õ�ֵ����ô��l, i����ֵ <= �ڱ�ֵ�� ��i + 1, r�� >= �ڱ�ֵ                  
			}
        swap(p, arr[i]); // �ڱ���λ���ź��� 
        // �ݹ����ң�������ִ���ڱ�����
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
    
    
int main(){
	vector<int> nums = {3, 2, 8, 7, 9, 4, 5, 6};
	cout << "original :" << endl;
	for(auto n : nums) cout << n << " ";
	cout << endl;
	quickSort(nums, 0 , nums.size() - 1);
	cout << endl;
	cout << "sort :" << endl;
	for(auto n : nums) cout << n << " ";
	return 0;
}
