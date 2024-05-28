#include <iostream>
using namespace std;

typedef char ElemType;

// 定义树的节点
struct BiNode {
    ElemType data; // 节点的数据类型
    BiNode* left;  // 左子树
    BiNode* right; // 右子树

    BiNode(ElemType val) : data(val), left(nullptr), right(nullptr) {}
};

using BiTree = BiNode*; // 起别名

// 二叉树类
class BinaryTree {
public:
    BinaryTree() : m_root(nullptr), size(0) {}

    void Create();   // 递归的创建二叉树的节点
    int getSize();   // 递归得到树的节点数目
    int getHeight(); // 递归得到树的高度
    void preOrder(); // 前序遍历
    void inOrder();  // 中序遍历
    void postOrder();// 后序遍历
    void destroy();  // 删除二叉树

private:
    BiTree create(); // 递归的创建二叉树的节点
    void preOrder(BiTree root);  // 前序遍历
    void inOrder(BiTree root);   // 中序遍历
    void postOrder(BiTree root); // 后序遍历
    void destroy(BiTree root);   // 摧毁树
    int getHeight(BiTree root);  // 递归得到树的高度
    void AddNode(const ElemType key, int direction, BiTree root); // 添加节点

    BiTree m_root; // 根节点
    int size;      // 节点总数
};

#pragma region 私有成员函数
// 添加节点
void BinaryTree::AddNode(const ElemType key, int direction, BiTree root) {
    if (direction == 0) {
        // 从左子树插入
        if (root->left == nullptr)
            root->left = new BiNode(key);
        else
            AddNode(key, direction, root->left);
    } else if (direction == 1) {
        // 从右子树插入
        if (root->right == nullptr)
            root->right = new BiNode(key);
        else
            AddNode(key, direction, root->right);
    }
}

// 二叉树的建立，按前序遍历的方式建立二叉树
BiTree BinaryTree::create() {
    BiTree current = nullptr;
    ElemType val;
    cin >> val; // 输入键值

    if (val == '#') // 标识当前子树为空，转向下一节点
    {
        return nullptr;
    } else {
        // 递归的创建左右子树
        size++;
        current = new BiNode(val);
        current->left = create();
        current->right = create();
        return current;
    }
}

// 删除二叉树(private 函数)
void BinaryTree::destroy(BiTree root) {
    if (root) {
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}

// 递归得到树的高度
int BinaryTree::getHeight(BiTree root) {
    if (root == nullptr)
        return 0;
    int left_height = getHeight(root->left);
    int right_height = getHeight(root->right);
    return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}

// 前序遍历
void BinaryTree::preOrder(BiTree root) {
    if (root == nullptr)
        return;
    else {
        cout << root->data << "  -->  "; // 首先打印根节点
        preOrder(root->left);            // 接着遍历左子树
        preOrder(root->right);           // 接着遍历右子树
    }
}

// 中序遍历
void BinaryTree::inOrder(BiTree root) {
    if (root == nullptr)
        return;
    else {
        inOrder(root->left);             // 首先遍历左子树
        cout << root->data << "  -->  "; // 接着打印根节点
        inOrder(root->right);            // 接着遍历右子树
    }
}

// 后序遍历
void BinaryTree::postOrder(BiTree root) {
    if (root == nullptr)
        return;
    else {
        postOrder(root->left);           // 首先遍历左子树
        postOrder(root->right);          // 接着遍历右子树
        cout << root->data << "  -->  "; // 接着打印根节点
    }
}
#pragma endregion

#pragma region 公有成员函数
// 二叉树的建立
void BinaryTree::Create() {
    size = 0;
    m_root = create();
}

// 删除二叉树
void BinaryTree::destroy() {
    destroy(m_root);
    m_root = nullptr; // 重置根节点指针
    size = 0;         // 重置节点计数
}

// 递归得到树的高度
int BinaryTree::getHeight() {
    return getHeight(m_root);
}

// 前序遍历
void BinaryTree::preOrder() {
    cout << "前序遍历的结果如下：" << endl;
    preOrder(m_root);
    cout << endl;
}

// 中序遍历
void BinaryTree::inOrder() {
    cout << "中序遍历的结果如下：" << endl;
    inOrder(m_root);
    cout << endl;
}

// 后序遍历
void BinaryTree::postOrder() {
    cout << "后序遍历的结果如下：" << endl;
    postOrder(m_root);
    cout << endl;
}

// 获取大小
int BinaryTree::getSize() {
    return size;
}
#pragma endregion


