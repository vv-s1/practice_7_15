
#define _CRT_SECURE_NO_WARNINGS 1

//头文件引用
#include<stdio.h>
#include<stdlib.h>

//单向链表节点结构体
struct Node
{
	int data;
	struct Node* next;
};

//双向链表节点结构体
struct DNode
{
	int data;
	struct DNode* next;
	struct DNode* prev;
};

void menu();//单链表相关操作的菜单
void dlistMenu();//双链表相关操作的菜单
void clistMenu();//循环链表相关操作的菜单
void statsMenu();//统计与分析操作的菜单
struct Node* createNode(int data);//创建新节点(单向链表)
void appendNode(struct Node** head, int data);//在链表末尾添加节点
void insertAtHead(struct Node** head, int data);//在链表头插入节点
void insertAtPosition(struct Node** head, int data, int position);//在指定位置插入节点
void deleteNode(struct Node** head, int key);//删除节点
void reverseList(struct Node** head);//反转链表
int searchNode(struct Node* head, int key);//查找节点
void printList(struct Node* head);//打印链表
int getListLength(struct Node* head);//获取链表长度
void sortList(struct Node** head);//对链表进行排序(冒泡排序)
struct Node* getMiddle(struct Node* head); //获取中间节点
struct Node* mergeSort(struct Node* head);//合并排序链表
struct Node* merge(struct Node* lift, struct Noode* rught);//合并两个有序的链表
void appendDNode(struct Node** head, int data);//在双向链表末尾添加节点
struct DNode* createDNode(int data);//创建双向链表
void deleteDNode(struct DNode** head, int key);//删除双向链表节点
void reverseDList(struct DNode** head);//反转双向链表
void printDList(struct DNode* head);//打印双向链表
void printReverseDList(struct DNode* tail);//反向打印双向链表
void appendCircularNode(struct DNode** head, int data);//循环双向链表
void deleteCirculaarNode(struct Node** head, int key);//删除循环双向链表
void printCircularList(struct Node* head);//打印循环双向链表
int hasCycle(struct Node* head);//检查链表是否有环
struct Node* findMiddleNode(struct Node* head);//查找链表的中间节点
void saveListToFile(struct Node* head, const char* filename);//保存链表到文件
struct Node* loadListFromFile(const char* filename);//从文件加载链表
int countOccurrences(struct Node* head, int value);//统计节点值出现的次数
double calculateAverage(struct Node* head);//计算链表节点值的平均值
double calculaateVariance(struct Node* head);//计算链表节点值的方差
void freeList(struct Node** head);//释放链表内存

