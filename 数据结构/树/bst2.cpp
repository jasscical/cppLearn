#include <iostream>
#include <climits>
#define dataType int
using namespace std;

class bstTree{
private:
    dataType val;
    bstTree* left;
    bstTree* right;
public:
    // 构造函数
    bstTree():val(0), left(nullptr), right(nullptr){} 
    bstTree(dataType& newVal):val(newVal), left(nullptr), right(nullptr){}
    
    // 析构函数
    ~bstTree(){
        delete this->left;
        delete this->right;
    }

    // 节点值获取、设置
    dataType getVal() const{
        return this->val;
    }
    void setVal(dataType newVal){
        this->val = newVal;
    }

    // 左孩子获取、设置
    bstTree* getLeft() const{
        return this->left;
    }
    void setLeft(bstTree*& newLeft){
        this->left = newLeft;
    }

    // 右孩子获取、设置
    bstTree* getRight() const{
        return this->right;
    }
    void setRight(bstTree*& newRight){
        this->right = newRight;
    }
};

// 插入元素
void buildBSTree(bstTree*& root){
    cout << "输入一个数组构建BST，以空格分隔，\\n结束" << endl;
    dataType dtmp;
    while(cin >> dtmp){
        bstTree* newNode = new bstTree(dtmp); // 不用delete
        
        if(root == nullptr){ // 如果树还没有构造，直接指向新创建的节点
            root = newNode;
        }else{ // 如果已经构造，那么要去左右子树找到合适的位置
            bstTree* pNode = root;
            while(true){
                if(dtmp <= pNode->getVal()){ // 小于等于当前节点，往左找
                    if(pNode->getLeft() == nullptr){
                        pNode->setLeft(newNode);
                        break;
                    }else{
                        pNode = pNode->getLeft(); 
                    }
                }else{
                    if(pNode->getRight() == nullptr){ // 大于当前节点，往右找
                        pNode->setRight(newNode);
                        break;
                    }else{
                        pNode = pNode->getRight();
                    }
                }
            }
        }
        if(cin.get() == '\n') break;
    }
}

// 方法2：插入元素
bstTree* insertToBST(bstTree* root, int val){
    if(root == nullptr){
        root = new bstTree(val);
    }
    if(val < root->getVal()) root->setLeft = insertToBST(root->getLeft(), val);
    if(val > root->getVal()) root->setRight = insertToBST(root->getRight(), val);
    return root;
}

// 中序遍历
void inOrder(bstTree* root){
    if(root == nullptr) return;
    inOrder(root->getLeft());
    cout << root->getVal() << " ";
    inOrder(root->getRight());
}

// 先序遍历
void preOrder(bstTree* root){
    if(root == nullptr) return;  
    cout << root->getVal() << " ";
    preOrder(root->getLeft());
    preOrder(root->getRight());
}

// 后序遍历
void postOrder(bstTree* root){
    if(root == nullptr) return;    
    postOrder(root->getLeft());
    postOrder(root->getRight());
    cout << root->getVal() << " ";
}


int main(){
    bstTree* root = nullptr;
    buildBSTree(root);
    
    cout << endl << "中序遍历：" << endl;
    inOrder(root);
    cout << endl << "先序遍历：" << endl;
    preOrder(root);
    cout << endl << "后序遍历：" << endl;
    postOrder(root);
    cout << endl;
    //PostOrder(root);

    return 0;
}