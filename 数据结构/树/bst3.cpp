#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#define dataType int
using namespace std;


struct bstTree{
    dataType val;
    bstTree* left;
    bstTree* right;
    // 构造函数
    bstTree():val(0), left(nullptr), right(nullptr){} 
    bstTree(dataType& newVal):val(newVal), left(nullptr), right(nullptr){}    
};

// 插入元素方法1：无返回值
// 需要一个parent节点保存父节点
// void insertToBST1(bstTree* root, int val)是root指向调用者，但是在这个函数中
// 是对root指针进行操作，应该要返回root给调用者，让调用者指向root所指向的
void insertToBST1(bstTree*& root, int val){
    if(root == nullptr){
        root = new bstTree(val);
        return;
    }
    bstTree* cur = root;
    bstTree* parent;
    // 遍历二叉树找到插入的位置(处于空，根据父节点的值来决定作为父节点的左、右孩子)
    while(cur){
        parent = cur; // 保存父节点
        if(val < cur->val) cur = cur->left;
        else cur = cur->right;
    }

    if(val < parent->val){
        parent->left = new bstTree(val);
    }else{
        parent->right = new bstTree(val);
    }
    delete cur;
    return;
}

// 插入元素方法1：无返回值, 递归写法
bstTree* parent;
void insertToBST1_1(bstTree* root, int val){
    if(root == nullptr){
        if(val < parent->val){
            parent->left = new bstTree(val);
        }else{
            parent->right = new bstTree(val);
        }
        return;
    }
    parent = root;
    if(val < root->val) insertToBST1_1(root->left, val);
    if(val > root->val) insertToBST1_1(root->right, val);
    return;
}

// 插入元素方法2：有返回值
bstTree* insertToBST2(bstTree* root, int val){
    if(root == nullptr){
        root = new bstTree(val);
    }
    if(val < root->val) root->left = insertToBST2(root->left, val);
    if(val > root->val) root->right = insertToBST2(root->right, val);
    return root;
}

// 中序遍历
void inOrder(bstTree* root){
    if(root == nullptr) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// 先序遍历
void preOrder(bstTree* root){
    if(root == nullptr) return;  
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 后序遍历
void postOrder(bstTree* root){
    if(root == nullptr) return;    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}


// 单个元素插入
void buildBSTree(bstTree*& root){
    cout << "输入一个数组构建BST，以空格分隔，\\n结束" << endl;
    dataType dtmp;
    while(cin >> dtmp){
        
        cout << "insertToBST1(root, dtmp) start..." << endl;
        insertToBST1(root, dtmp);  
        cout << "insertToBST1(root, dtmp) over !!!" << endl; 
        
        /*
        cout << "insertToBST1_1(root, dtmp) start..." << endl;
        if(root == nullptr){
            root = new bstTree(dtmp);
        }else{
            insertToBST1_1(root, dtmp);
        }
        cout << "insertToBST1_1(root, dtmp) over !!!" << endl; */
        

        /*
        cout << "inertToBST2(root, dtmp) start..." << endl;
        root = insertToBST2(root, dtmp);   
        cout << "inertToBST2(root, dtmp) over !!!" << endl; */
         
        if(cin.get() == '\n') break;
    }
}


bstTree* sortArrayToBSTree(vector<int>& nums, int l, int r){
    if(l > r) return nullptr;
    int mid = l + ((r - l) / 2);
    bstTree* root = new bstTree(nums[mid]);
    root->left = sortArrayToBSTree(nums, l, mid - 1);
    root->right = sortArrayToBSTree(nums, mid + 1, r);
    return root;
}


int main(){
    bstTree* root = nullptr;
    //buildBSTree(root); // 输入单个插入,进行构造

    // 从有序数组中构造
    vector<int> nums = {4 ,7 ,5 ,1 ,3 ,6 ,2};
    sort(nums.begin(), nums.end());
    root = sortArrayToBSTree(nums, 0, nums.size() - 1);
    
    cout << endl << "中序遍历：" << endl;
    inOrder(root);
    cout << endl << "先序遍历：" << endl;
    preOrder(root);
    cout << endl << "后序遍历：" << endl;
    postOrder(root);
    
    cout << endl << "====end====" << endl;  
    // 指针root不再指向申请的内存空间(也就是bstTree类对象)
    // 在程序退出时bstTree类对象会调用析构函数
    delete root; 
    root = nullptr;

    return 0;
}