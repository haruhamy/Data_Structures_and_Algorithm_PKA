#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

/* Cấu trúc của một Node trong danh sách liên kết */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Hàm tạo một Node mới với dữ liệu cho trước */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    return new_Node;
}

/* Hàm đảo ngược danh sách liên kết */
Node *reverse(Node **r)
{
    Node *prev = NULL;
    Node *cur = *r;
    Node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}

/* Hàm chèn một Node vào đầu danh sách liên kết đơn */
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}

/* Hàm giải phóng bộ nhớ của danh sách liên kết */
void freeList(struct Node *Node)
{
    struct Node *temp;
    while (Node != NULL)
    {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}

/* Hàm nhân hai danh sách liên kết và trả về kết quả */
long long multiplyTwoLists(struct Node *l1, struct Node *l2)
{
    long long num1 = 0, num2 = 0;

    // Chuyển danh sách liên kết đầu tiên thành một số
    while (l1 != NULL)
    {
        num1 = (num1 * 10 + l1->data) % MOD;
        l1 = l1->next;
    }

    // Chuyển danh sách liên kết thứ hai thành một số
    while (l2 != NULL)
    {
        num2 = (num2 * 10 + l2->data) % MOD;
        l2 = l2->next;
    }

    // Nhân hai số và trả về kết quả modulo MOD
    return (num1 * num2) % MOD;
}

/* Hàm tiện ích để in một danh sách liên kết */
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Chương trình chính để kiểm tra các hàm trên */
int main(void)
{
    int t, n, m, i, x;
    cin >> t;
    while (t--)
    {
        struct Node *first = NULL;
        struct Node *second = NULL;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++)
        {
            cin >> x;
            push(&second, x);
        }

        reverse(&first);
        reverse(&second);
        long long res = multiplyTwoLists(first, second);

        cout << res << endl;
        freeList(first);
        freeList(second);
    }
    return 0;
}
