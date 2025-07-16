#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id;
    char title[50];
    int priority;
    char deadline[50];
} Task;

typedef struct Node {
    Task data;
    struct Node* next;
} Node;

typedef struct Noded {
    Node *data;
    struct Noded* next;
    struct Noded* prev;
} Noded;

Node* addTask(Node* head, Task task) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = task;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* deleteTask(Node *head, int id) {
    if (!head) {
        return NULL;
    }
    if (head->data.id == id) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *current = head;
    while (current->next && current->next->data.id != id) {
        current = current->next;
    }
    if (current->next) {
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    return head;
}

Node *updateTask(Node* head, int id) {
    Node *temp = head;
    while (temp) {
        if (temp->data.id == id) {
            printf("Nhap tieu de moi:");
            gets(temp->data.title);
            printf("Nhap muc do uu tien moi");
            scanf("%d", &temp->data.priority);
            printf("Nhap thoi gian hoan thanh nhiem vu moi:");
            gets(temp->data.deadline);
            getchar();
            break;
        }
        temp = temp->next;
    }
    return head;
}



void displayTasks(Node *head) {
    if (!head) {
        printf("Danh sach trong ");
        return;
    }
    while (head) {
        printf("ID: %d || Tieu de: %s || Muc do uu tien: %d || Thoi gian hoan thanh: %s", head->data.id,
               head->data.title, head->data.priority, head->data.deadline);
        head = head->next;
    }
}


void sortByPriority(Node* head) {
    if (!head) {
        return;
    }
    for (Node* i= head; i->next; i=i->next) {
        for (Node* j= i->next; j->next; j=j->next) {
            if (i->data.priority > j->data.priority) {
                Task temp = j->data;
                  j->data=i->data;
                i->data=temp;
            }
        }
    }
    printf("Sau khi sap xep");
}

int main() {
    Node* head = NULL;

    int choice;
    do {
        printf("MENU\n");
        printf("1. Them nhiem vu\n");
        printf("2. Hien thi danh sach nhiem vu\n");
        printf("3  Xoa nhiem vu\n");
        printf("4. Cap nhat thong tin nhiem vu\n");
        printf("5. Danh dau nhiem vu hoan thanh\n");
        printf("6. Sap xep nhiem vu\n");
        printf("7 Tim kiem nhiem vu\n");
        printf("8 Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            Task task;
            printf("Nhap id nhiem vu: ");
            scanf("%d", &task.id); getchar();

            printf("Nhap tieu de nhiem vu: ");
            gets(task.title); getchar();

            printf("Nhap muc do uu tien: ");
            scanf("%d", &task.priority);

            printf("Nhap thoi gian hoan thanh: ");
            gets(task.deadline); getchar();

            head = addTask(head, task);
        } else if (choice == 2) {
            displayTasks(head);
        } else if (choice == 3) {
            int id;
            printf("Nhap id can xoa");
            scanf("%d", &id);
            getchar();
            head = deleteTask(head, id);
        } else if (choice == 4) {
            int id;
            printf("Nhap id can cap nhat");
            scanf("%d", &id);
            getchar();
            head = updateTask(head, id);
        } else if (choice == 6) {
            sortByPriority(head);
        }
    } while (choice != 8);
return 0;
}