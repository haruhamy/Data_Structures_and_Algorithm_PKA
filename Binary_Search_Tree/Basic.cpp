#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const int MAX = 1e6 + 5;
const unsigned long long LINF = 8e18 + 5;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Ham giai phong du lieu
void Free(Node *root)
{
    if (root == nullptr)
        return;

    Free(root->left);
    Free(root->right);
    delete root;
}

// Ham dieu huong cua cay
bool LeftOf(const int value, const Node *root)
{
    return value < root->data;
}

bool RightOf(const int value, const Node *root)
{
    return value > root->data;
}

// Them phan tu vao BST
Node *Insert(Node *root, const int value)
{
    if (root == nullptr)
    {
        Node *node = new Node(value);
        return node;
    }
    if (LeftOf(value, root))
        root->left = Insert(root->left, value);
    else if (RightOf(value, root))
        root->right = Insert(root->right, value);
    return root;
}

// Tim kiem tren BST
bool Search(const Node *root, int value)
{
    if (root == nullptr)
        return false;
    if (root->data == value)
    {
        return true;
    }
    else if (LeftOf(value, root))
    {
        return Search(root->left, value);
    }
    else if (RightOf(value, root))
    {
        return Search(root->right, value);
    }
    return false;
}

// Lay gia tri con trai nhat
int LeftMostValue(const Node *root)
{
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

// Xoa Node trong BST
Node *Delete(Node *root, int value)
{
    if (root == nullptr)
        return root;
    if (LeftOf(value, root))
        root->left = Delete(root->left, value);
    else if (RightOf(value, root))
        root->right = Delete(root->right, value);
    else
    {
        // root->data == value, delete this node
        if (root->left == nullptr)
        {
            Node *newRoot = root->right;
            delete root;
            return newRoot;
        }
        if (root->right == nullptr)
        {
            Node *newRoot = root->left;
            delete root;
            return newRoot;
        }
        root->data = LeftMostValue(root->right);
        root->right = Delete(root->right, root->data);
    }
    return root;
}

// Duyet PreOrder
void PreOrder(Node *root)
{
    if (root != nullptr)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

// Duyet InOrder
void InOrder(Node *root)
{
    if (root != nullptr)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

// Duyet PostOrder
void PostOrder(Node *root)
{
    if (root != nullptr)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    Node *root = nullptr;

    int choice, value;

    while (1)
    {
        cout << "\nMenu:\n";
        cout << "1. Them phan tu vao cay\n";
        cout << "2. Tim kiem mot phan tu\n";
        cout << "3. Xoa mot phan tu\n";
        cout << "4. Duyet cay PreOrder\n";
        cout << "5. Duyet cay InOrder\n";
        cout << "6. Duyet cay PostOrder\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Nhap gia tri can them: ";
            cin >> value;
            root = Insert(root, value);
            break;
        case 2:
            cout << "Nhap gia tri can tim: ";
            cin >> value;
            if (Search(root, value))
                cout << "Gia tri " << value << " duoc tim thay trong cay\n";
            else
                cout << "Gia tri " << value << " khong tim thay trong cay\n";
            break;
        case 3:
            cout << "Nhap gia tri can xoa: ";
            cin >> value;
            root = Delete(root, value);
            break;
        case 4:
            cout << "Duyet PreOrder: ";
            PreOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Duyet InOrder: ";
            InOrder(root);
            cout << endl;
            break;
        case 6:
            cout << "Duyet PostOrder: ";
            PostOrder(root);
            cout << endl;
            break;
        case 0:
            Free(root);
            return 0;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    }

    return 0;
}
