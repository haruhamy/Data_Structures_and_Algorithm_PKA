#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
const int MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const int MAX = 1e6 + 5;
const unsigned long long LINF = 8e18 + 5;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *start = NULL;

Node *displayy(Node *start)
{
    if (start == NULL)
    {
        cout << "Danh sach rong" << endl;
        return start;
    }
    Node *ptr = start;
    while (ptr->next != start)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d \n", ptr->data);
    return start;
}

Node *insert_beg(Node *start, int num)
{
    Node *new_Node = new Node;
    new_Node->data = num;
    Node *ptr = start;
    if (start == NULL)
    {
        start = new_Node;
        start->next = start;
        start->prev = start;
        return start;
    }
    while (ptr->next != start)
        ptr = ptr->next;
    new_Node->prev = ptr;
    ptr->next = new_Node;
    new_Node->next = start;
    start->prev = new_Node;
    start = new_Node;
    return start;
}

class CircularlyDoublyLinkedList
{
private:
    int sizee = 0;

public:
    CircularlyDoublyLinkedList(const int *arr, const int n)
    {
        this->sizee = n;
        for (int i = 0; i < n; i++)
        {
            start = insert_beg(start, arr[i]);
        }
    }

    CircularlyDoublyLinkedList(const std::vector<int> &vec)
    {
        this->sizee = vec.size();
        for (int val : vec)
        {
            start = insert_beg(start, val);
        }
    }

    ~CircularlyDoublyLinkedList()
    {
        Node *current = start;
        if (current != NULL)
        {
            do
            {
                Node *next = current->next;
                delete current;
                current = next;
            } while (current != start);
        }
    }

    void display()
    {
        start = displayy(start);
    }

    Node *search(const int val)
    {
        if (start == NULL)
        {
            cout << "Khong tim thay data" << endl;
            return NULL;
        }
        Node *current = start;
        do
        {
            if (current->data == val)
            {
                return current;
            }
            current = current->next;
        } while (current != start);
        cout << "Khong tim thay data" << endl;
        return NULL;
    }

    int size()
    {
        return sizee;
    }

    void insert_beginning()
    {
        int k;
        cout << "Nhap vao gia tri can chen: ";
        cin >> k;
        start = insert_beg(start, k);
        sizee++;
    }
};

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    CircularlyDoublyLinkedList list(vec);

    int choice;

    while (1)
    {
        cout << "\nMenu:\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Tim kiem mot phan tu\n";
        cout << "3. Chen mot phan tu vao dau danh sach\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.display();
            break;
        case 2:
        {
            int val;
            cout << "Nhap gia tri can tim: ";
            cin >> val;
            Node *result = list.search(val);
            if (result != NULL)
                cout << "Gia tri " << val << " duoc tim thay trong danh sach" << endl;
            break;
        }
        case 3:
            list.insert_beginning();
            break;
        case 0:
            return 0;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    }

    return 0;
}
