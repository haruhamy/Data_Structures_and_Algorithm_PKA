// Cân bằng trong cây nhị phân (Balanced Binary Tree)
#include <bits/stdc++.h> // Include toàn bộ thư viện chuẩn C++
using namespace std;     // Sử dụng không gian tên std để tránh phải gõ std:: trước mỗi lệnh

// Định nghĩa cấu trúc của một Node trong cây nhị phân AVL
struct Node
{
    int key;     // Giá trị của node
    Node *left;  // Con trỏ đến node con bên trái
    Node *right; // Con trỏ đến node con bên phải
    int height;  // Chiều cao của node
};

// Tính chiều cao của một node
int height(Node *node)
{
    if (node == nullptr) // Nếu node là nullptr, chiều cao là 0
        return 0;
    return node->height; // Trả về chiều cao của node
}

// Tạo một node mới
Node *createNode(int key)
{
    Node *newNode = new Node(); // Cấp phát bộ nhớ cho node mới
    newNode->key = key;         // Gán giá trị cho node
    newNode->left = nullptr;    // Khởi tạo con trỏ trái là nullptr
    newNode->right = nullptr;   // Khởi tạo con trỏ phải là nullptr
    newNode->height = 1;        // Khởi tạo chiều cao của node là 1
    return newNode;             // Trả về node mới
}

// Xoay trái tại node y
Node *rotateLeft(Node *y)
{
    Node *x = y->right; // Lấy node con phải của y
    Node *T2 = x->left; // Lấy con trái của x

    x->left = y;   // Thực hiện xoay trái
    y->right = T2; // Gán con trái của x cho con phải của y

    y->height = std::max(height(y->left), height(y->right)) + 1; // Cập nhật chiều cao cho y
    x->height = std::max(height(x->left), height(x->right)) + 1; // Cập nhật chiều cao cho x

    return x; // Trả về node mới sau khi xoay
}

// Xoay phải tại node y
Node *rotateRight(Node *y)
{
    Node *x = y->left;   // Lấy node con trái của y
    Node *T2 = x->right; // Lấy con phải của x

    x->right = y; // Thực hiện xoay phải
    y->left = T2; // Gán con phải của x cho con trái của y

    y->height = std::max(height(y->left), height(y->right)) + 1; // Cập nhật chiều cao cho y
    x->height = std::max(height(x->left), height(x->right)) + 1; // Cập nhật chiều cao cho x

    return x; // Trả về node mới sau khi xoay
}

// Lấy hiệu số cân bằng của một node
int getBalanceFactor(Node *node)
{
    if (node == nullptr) // Nếu node là nullptr, hiệu số cân bằng là 0
        return 0;
    return height(node->left) - height(node->right); // Trả về hiệu số chiều cao giữa con trái và con phải
}

// Chèn một node mới vào cây
Node *insertNode(Node *root, int key)
{
    if (root == nullptr) // Nếu cây rỗng, tạo node mới
        return createNode(key);

    if (key < root->key) // Nếu key nhỏ hơn giá trị của root, chèn vào bên trái
        root->left = insertNode(root->left, key);
    else if (key > root->key) // Nếu key lớn hơn giá trị của root, chèn vào bên phải
        root->right = insertNode(root->right, key);
    else // Nếu key bằng giá trị của root, không làm gì
        return root;

    root->height = std::max(height(root->left), height(root->right)) + 1; // Cập nhật chiều cao cho root

    int balanceFactor = getBalanceFactor(root); // Lấy hiệu số cân bằng

    // Kiểm tra cân bằng và xoay cây để cân bằng
    if (balanceFactor > 1)
    { // Nếu mất cân bằng bên trái
        if (key < root->left->key)
        { // Left Left Case
            return rotateRight(root);
        }
        else if (key > root->left->key)
        { // Left Right Case
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (balanceFactor < -1)
    { // Nếu mất cân bằng bên phải
        if (key > root->right->key)
        { // Right Right Case
            return rotateLeft(root);
        }
        else if (key < root->right->key)
        { // Right Left Case
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root; // Trả về node root sau khi chèn và cân bằng
}

// In-order traversal để in cây nhị phân AVL
void inorderTraversal(Node *root)
{
    if (root == nullptr) // Nếu cây rỗng, trả về
        return;
    inorderTraversal(root->left);  // Duyệt trái
    cout << root->key << " ";      // In giá trị của node
    inorderTraversal(root->right); // Duyệt phải
}

int main()
{
    Node *root = nullptr; // Khởi tạo cây rỗng

    // Chèn các phần tử vào cây
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    cout << "Cây nhị phân AVL sau khi chèn: ";
    inorderTraversal(root); // In cây sau khi chèn

    return 0;
}
