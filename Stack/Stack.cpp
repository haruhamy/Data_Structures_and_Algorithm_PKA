#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
typedef struct _listnode
{
    int num;                // Giá trị của nút
    struct _listnode *next; // Con trỏ đến nút tiếp theo
} ListNode;

// Định nghĩa cấu trúc của một danh sách liên kết
typedef struct _linkedlist
{
    ListNode *head; // Con trỏ đến nút đầu tiên của danh sách
    int size;       // Kích thước của danh sách
} LinkedList;

// Định nghĩa cấu trúc của một ngăn xếp sử dụng danh sách liên kết
typedef struct _stack
{
    LinkedList ll; // Một danh sách liên kết
} Stack;

// Hàm chèn một nút vào vị trí có chỉ số index trong danh sách liên kết
void insertNode(ListNode **ptrHead, int index, int value)
{
    ListNode *newNode, *temp;
    int i;

    // Ép kiểu void * thành ListNode *
    newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->num = value;
    newNode->next = NULL;

    if (index == 0)
    {
        newNode->next = *ptrHead;
        *ptrHead = newNode;
    }
    else
    {
        temp = *ptrHead;
        for (i = 0; i < index - 1; i++)
        {
            if (temp != NULL)
                temp = temp->next;
        }
        if (temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Hàm xóa nút có chỉ số index trong danh sách liên kết
void removeNode(ListNode **ptrHead, int index)
{
    ListNode *temp, *preTemp;
    int i;

    if (*ptrHead == NULL)
        return;

    if (index == 0)
    {
        temp = *ptrHead;
        *ptrHead = (*ptrHead)->next;
        free(temp);
    }
    else
    {
        temp = *ptrHead;
        for (i = 0; i < index - 1; i++)
        {
            if (temp->next != NULL)
                temp = temp->next;
        }
        if (temp->next != NULL)
        {
            preTemp = temp->next;
            temp->next = preTemp->next;
            free(preTemp);
        }
    }
}

// Hàm kiểm tra ngăn xếp có rỗng không
bool isEmptyStack(Stack *s)
{
    return (s->ll.size == 0);
}

// Hàm push để chèn giá trị vào ngăn xếp
void push(Stack *s, int item)
{
    insertNode(&(s->ll.head), 0, item); // Chèn vào đầu danh sách
    s->ll.size++;                       // Tăng kích thước của ngăn xếp
}

// Hàm pop để lấy một phần tử từ ngăn xếp
int pop(Stack *s)
{
    int item;
    if (!isEmptyStack(s))
    {                                 // Kiểm tra ngăn xếp có rỗng không
        item = ((s->ll.head)->num);   // Lấy giá trị của nút đầu tiên
        removeNode(&(s->ll.head), 0); // Xóa nút đầu tiên
        (s->ll.size)--;               // Giảm kích thước của ngăn xếp
        return item;                  // Trả về giá trị
    }
    else
    {
        printf("\nNgăn xếp rỗng"); // In thông báo ngăn xếp rỗng
        return -1;                 // Trả về giá trị báo lỗi
    }
}

// Hàm main để kiểm tra các tính năng của ngăn xếp
int main()
{
    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;

    push(&s, 10); // Đẩy 10 vào ngăn xếp
    push(&s, 20); // Đẩy 20 vào ngăn xếp
    push(&s, 30); // Đẩy 30 vào ngăn xếp

    printf("Pop: %d\n", pop(&s)); // Lấy phần tử từ ngăn xếp (30)
    printf("Pop: %d\n", pop(&s)); // Lấy phần tử từ ngăn xếp (20)
    printf("Pop: %d\n", pop(&s)); // Lấy phần tử từ ngăn xếp (10)
    printf("Pop: %d\n", pop(&s)); // Cố gắng lấy phần tử từ ngăn xếp rỗng

    return 0;
}
