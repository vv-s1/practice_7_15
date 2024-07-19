
#define _CRT_SECURE_NO_WARNINGS 1

//ͷ�ļ�����
#include<stdio.h>
#include<stdlib.h>

//��������ڵ�ṹ��
struct Node
{
	int data;
	struct Node* next;
};

//˫������ڵ�ṹ��
struct DNode
{
	int data;
	struct DNode* next;
	struct DNode* prev;
};

void menu();//��������ز����Ĳ˵�
void dlistMenu();//˫������ز����Ĳ˵�
void clistMenu();//ѭ��������ز����Ĳ˵�
void statsMenu();//ͳ������������Ĳ˵�
struct Node* createNode(int data);//�����½ڵ�(��������)
void appendNode(struct Node** head, int data);//������ĩβ��ӽڵ�
void insertAtHead(struct Node** head, int data);//������ͷ����ڵ�
void insertAtPosition(struct Node** head, int data, int position);//��ָ��λ�ò���ڵ�
void deleteNode(struct Node** head, int key);//ɾ���ڵ�
void reverseList(struct Node** head);//��ת����
int searchNode(struct Node* head, int key);//���ҽڵ�
void printList(struct Node* head);//��ӡ����
int getListLength(struct Node* head);//��ȡ������
void sortList(struct Node** head);//�������������(ð������)
struct Node* getMiddle(struct Node* head); //��ȡ�м�ڵ�
struct Node* mergeSort(struct Node* head);//�ϲ���������
struct Node* merge(struct Node* lift, struct Noode* rught);//�ϲ��������������
void appendDNode(struct Node** head, int data);//��˫������ĩβ��ӽڵ�
struct DNode* createDNode(int data);//����˫������
void deleteDNode(struct DNode** head, int key);//ɾ��˫������ڵ�
void reverseDList(struct DNode** head);//��ת˫������
void printDList(struct DNode* head);//��ӡ˫������
void printReverseDList(struct DNode* tail);//�����ӡ˫������
void appendCircularNode(struct DNode** head, int data);//ѭ��˫������
void deleteCirculaarNode(struct Node** head, int key);//ɾ��ѭ��˫������
void printCircularList(struct Node* head);//��ӡѭ��˫������
int hasCycle(struct Node* head);//��������Ƿ��л�
struct Node* findMiddleNode(struct Node* head);//����������м�ڵ�
void saveListToFile(struct Node* head, const char* filename);//���������ļ�
struct Node* loadListFromFile(const char* filename);//���ļ���������
int countOccurrences(struct Node* head, int value);//ͳ�ƽڵ�ֵ���ֵĴ���
double calculateAverage(struct Node* head);//��������ڵ�ֵ��ƽ��ֵ
double calculaateVariance(struct Node* head);//��������ڵ�ֵ�ķ���
void freeList(struct Node** head);//�ͷ������ڴ�

