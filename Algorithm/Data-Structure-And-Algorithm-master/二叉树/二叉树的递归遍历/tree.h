#include <iostream>
using namespace std;

typedef char ElemType;

// �������Ľڵ�
struct BiNode {
    ElemType data; // �ڵ����������
    BiNode* left;  // ������
    BiNode* right; // ������

    BiNode(ElemType val) : data(val), left(nullptr), right(nullptr) {}
};

using BiTree = BiNode*; // �����

// ��������
class BinaryTree {
public:
    BinaryTree() : m_root(nullptr), size(0) {}

    void Create();   // �ݹ�Ĵ����������Ľڵ�
    int getSize();   // �ݹ�õ����Ľڵ���Ŀ
    int getHeight(); // �ݹ�õ����ĸ߶�
    void preOrder(); // ǰ�����
    void inOrder();  // �������
    void postOrder();// �������
    void destroy();  // ɾ��������

private:
    BiTree create(); // �ݹ�Ĵ����������Ľڵ�
    void preOrder(BiTree root);  // ǰ�����
    void inOrder(BiTree root);   // �������
    void postOrder(BiTree root); // �������
    void destroy(BiTree root);   // �ݻ���
    int getHeight(BiTree root);  // �ݹ�õ����ĸ߶�
    void AddNode(const ElemType key, int direction, BiTree root); // ��ӽڵ�

    BiTree m_root; // ���ڵ�
    int size;      // �ڵ�����
};

#pragma region ˽�г�Ա����
// ��ӽڵ�
void BinaryTree::AddNode(const ElemType key, int direction, BiTree root) {
    if (direction == 0) {
        // ������������
        if (root->left == nullptr)
            root->left = new BiNode(key);
        else
            AddNode(key, direction, root->left);
    } else if (direction == 1) {
        // ������������
        if (root->right == nullptr)
            root->right = new BiNode(key);
        else
            AddNode(key, direction, root->right);
    }
}

// �������Ľ�������ǰ������ķ�ʽ����������
BiTree BinaryTree::create() {
    BiTree current = nullptr;
    ElemType val;
    cin >> val; // �����ֵ

    if (val == '#') // ��ʶ��ǰ����Ϊ�գ�ת����һ�ڵ�
    {
        return nullptr;
    } else {
        // �ݹ�Ĵ�����������
        size++;
        current = new BiNode(val);
        current->left = create();
        current->right = create();
        return current;
    }
}

// ɾ��������(private ����)
void BinaryTree::destroy(BiTree root) {
    if (root) {
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}

// �ݹ�õ����ĸ߶�
int BinaryTree::getHeight(BiTree root) {
    if (root == nullptr)
        return 0;
    int left_height = getHeight(root->left);
    int right_height = getHeight(root->right);
    return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}

// ǰ�����
void BinaryTree::preOrder(BiTree root) {
    if (root == nullptr)
        return;
    else {
        cout << root->data << "  -->  "; // ���ȴ�ӡ���ڵ�
        preOrder(root->left);            // ���ű���������
        preOrder(root->right);           // ���ű���������
    }
}

// �������
void BinaryTree::inOrder(BiTree root) {
    if (root == nullptr)
        return;
    else {
        inOrder(root->left);             // ���ȱ���������
        cout << root->data << "  -->  "; // ���Ŵ�ӡ���ڵ�
        inOrder(root->right);            // ���ű���������
    }
}

// �������
void BinaryTree::postOrder(BiTree root) {
    if (root == nullptr)
        return;
    else {
        postOrder(root->left);           // ���ȱ���������
        postOrder(root->right);          // ���ű���������
        cout << root->data << "  -->  "; // ���Ŵ�ӡ���ڵ�
    }
}
#pragma endregion

#pragma region ���г�Ա����
// �������Ľ���
void BinaryTree::Create() {
    size = 0;
    m_root = create();
}

// ɾ��������
void BinaryTree::destroy() {
    destroy(m_root);
    m_root = nullptr; // ���ø��ڵ�ָ��
    size = 0;         // ���ýڵ����
}

// �ݹ�õ����ĸ߶�
int BinaryTree::getHeight() {
    return getHeight(m_root);
}

// ǰ�����
void BinaryTree::preOrder() {
    cout << "ǰ������Ľ�����£�" << endl;
    preOrder(m_root);
    cout << endl;
}

// �������
void BinaryTree::inOrder() {
    cout << "��������Ľ�����£�" << endl;
    inOrder(m_root);
    cout << endl;
}

// �������
void BinaryTree::postOrder() {
    cout << "��������Ľ�����£�" << endl;
    postOrder(m_root);
    cout << endl;
}

// ��ȡ��С
int BinaryTree::getSize() {
    return size;
}
#pragma endregion


