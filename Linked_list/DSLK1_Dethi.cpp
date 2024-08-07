#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cho một nút trong danh sách liên kết
typedef struct _listnode
{
    int num;                // Phần data
    struct _listnode *next; // Phần con trỏ next, lưu ý có dấu *
} ListNode;

// Hàm tìm nút tại vị trí thứ i trong danh sách liên kết
ListNode *findNode(ListNode *head, int i)
{
    ListNode *cur = head;

    // Kiểm tra xem danh sách có rỗng hoặc vị trí i có hợp lệ không
    if ((head == NULL) || (i < 0))
    {
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai\n");
        return NULL;
    }

    // Duyệt danh sách đến vị trí thứ i
    while (i > 0)
    {
        cur = cur->next; // Dịch node cur
        i = i - 1;       // Giảm i để vòng lặp thực hiện i lần

        // Kiểm tra nếu nút hiện tại là NULL (vị trí không tồn tại trong danh sách)
        if (cur == NULL)
        {
            printf("Phan tu tim kiem khong ton tai\n");
            return NULL;
        }
    }
    return cur;
}

// Hàm chèn một nút mới với giá trị value tại vị trí index trong danh sách liên kết
void insertNode(ListNode **pHead, int index, int value)
{
    ListNode *cur, *newNode; // Khai báo một node

    // Kiểm tra nếu danh sách rỗng hoặc chèn tại đầu danh sách
    if (*pHead == NULL || index == 0)
    {
        newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    }
    // Tìm vị trí trước vị trí cần chèn và thực hiện chèn nút mới
    else if ((cur = findNode(*pHead, index - 1)) != NULL)
    {
        newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else
    {
        printf("Khong the chen phan tu moi tai chi so %d!\n", index);
    }
}

// Hàm xóa một nút tại vị trí index trong danh sách liên kết
void removeNode(ListNode **ptrHead, int index)
{
    ListNode *cur, *prev;

    // Kiểm tra nếu danh sách rỗng
    if (*ptrHead == NULL)
    {
        printf("Danh sach lien ket rong!\n");
        return;
    }

    // Nếu xóa nút đầu tiên
    if (index == 0)
    {
        cur = *ptrHead;
        *ptrHead = cur->next;
        free(cur);
    }
    // Tìm vị trí trước vị trí cần xóa và thực hiện xóa nút
    else if ((prev = findNode(*ptrHead, index - 1)) != NULL)
    {
        cur = prev->next;
        if (cur != NULL)
        {
            prev->next = cur->next;
            free(cur);
        }
        else
        {
            printf("Khong the xoa phan tu tai chi so %d!\n", index);
        }
    }
    else
    {
        printf("Khong the xoa phan tu tai chi so %d!\n", index);
    }
}

// Hàm in danh sách liên kết
void printList(ListNode *head)
{
    ListNode *cur = head;
    while (cur != NULL)
    {
        printf("%d -> ", cur->num);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    ListNode *head = NULL;

    // Chèn các nút vào danh sách liên kết
    insertNode(&head, 0, 10); // Chèn vào đầu danh sách
    insertNode(&head, 1, 20); // Chèn vào vị trí 1
    insertNode(&head, 2, 30); // Chèn vào vị trí 2
    insertNode(&head, 1, 15); // Chèn vào vị trí 1

    printf("Danh sach lien ket sau khi chen: \n");
    printList(head); // In danh sách liên kết sau khi chèn

    // Xóa nút tại vị trí 2
    removeNode(&head, 2);
    printf("Danh sach lien ket sau khi xoa nut tai chi so 2: \n");
    printList(head); // In danh sách liên kết sau khi xóa

    // Tìm nút tại vị trí 1
    ListNode *node = findNode(head, 1);
    if (node != NULL)
    {
        printf("Gia tri cua nut tai chi so 1: %d\n", node->num);
    }

    return 0;
}
