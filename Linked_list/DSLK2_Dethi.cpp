#include <stdio.h>
#include <stdlib.h>

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

// Hàm khởi tạo danh sách liên kết
void initList(LinkedList *list)
{
    list->head = NULL;
    list->size = 0;
}

// Hàm chèn một phần tử vào danh sách liên kết ở vị trí index
void insertNode(LinkedList *list, int index, int value)
{
    if (index < 0 || index > list->size)
    {
        printf("Chỉ số không hợp lệ!\n");
        return;
    }
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->num = value;
    newNode->next = NULL;

    if (index == 0)
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    else
    {
        ListNode *temp = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    list->size++;
}

// Hàm sửa một phần tử trong danh sách liên kết ở vị trí index
void updateNode(LinkedList *list, int index, int value)
{
    if (index < 0 || index >= list->size)
    {
        printf("Chỉ số không hợp lệ!\n");
        return;
    }
    ListNode *temp = list->head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    temp->num = value;
}

// Hàm xóa một phần tử trong danh sách liên kết ở vị trí index
void deleteNode(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        printf("Chỉ số không hợp lệ!\n");
        return;
    }
    ListNode *temp;
    if (index == 0)
    {
        temp = list->head;
        list->head = list->head->next;
    }
    else
    {
        ListNode *prev = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }
        temp = prev->next;
        prev->next = temp->next;
    }
    free(temp);
    list->size--;
}

// Hàm đảo ngược danh sách liên kết
void reverseList(LinkedList *list)
{
    ListNode *prev = NULL, *current = list->head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

// Hàm in ra danh sách liên kết
void printList(LinkedList *list)
{
    ListNode *temp = list->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->num);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    LinkedList list;
    initList(&list);

    // Chèn các phần tử vào danh sách liên kết
    insertNode(&list, 0, 10);
    insertNode(&list, 1, 20);
    insertNode(&list, 2, 30);
    insertNode(&list, 3, 40);

    printf("Danh sách sau khi chèn: ");
    printList(&list);

    // Sửa phần tử ở vị trí thứ 2
    updateNode(&list, 2, 25);
    printf("Danh sách sau khi sửa: ");
    printList(&list);

    // Xóa phần tử ở vị trí thứ 1
    deleteNode(&list, 1);
    printf("Danh sách sau khi xóa: ");
    printList(&list);

    // Đảo ngược danh sách
    reverseList(&list);
    printf("Danh sách sau khi đảo ngược: ");
    printList(&list);

    return 0;
}
