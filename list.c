#include"list.h"


void menu()
{
	printf("1.������ĩβ����½ڵ�\n");
	printf("2.������ͷ�������½ڵ�\n");
	printf("3.��ָ��λ�ò����½ڵ�\n");
	printf("4.ɾ��ָ�����ݵĽڵ�\n");
	printf("5.��ת����\n");
	printf("6.���������е�ĳ������\n");
	printf("7.��ӡ����\n");
	printf("8.��ȡ������\n");
	printf("9.�������������\n");
	printf("10.ʹ��˫������\n");
	printf("11.ʹ��ѭ������\n");
	printf("12.����������Ƿ��л�\n");
	printf("13.����������м�ڵ�\n");
	printf("14.���������ļ�\n");
	printf("15.���ļ��м�������\n");
	printf("16.ͳ�������\n");
	printf("0.�˳�\n");
	printf("������ѡ��\n");
}

void dlistMenu()
{
	printf("1.��˫������ĩβ����½ڵ�\n");
	printf("2.ɾ��˫�������еĽڵ�\n");
	printf("3.��ת˫������\n");
	printf("4.��ӡ˫������\n");
	printf("5.�����ӡ˫������\n");
	printf("������ѡ��\n");
}

void clistMenu()
{
	printf("1.��ѭ������ĩβ����½ڵ�\n");
	printf("2.ɾ��ѭ�������еĽڵ�\n");
	printf("3.��ӡѭ������\n");
	printf("������ѡ��\n");
}

void statsMenu()
{
	printf("1.ͳ�������е�ĳ�����ݳ��ֵĴ���\n");
	printf("2.�����������ݵ�ƽ��ֵ\n");
	printf("3.�����������ݵķ���\n");
	printf("������ѡ��\n");
}

//����½ڵ�
struct Node* createNode(int data)//���ڴ���һ���µ�����ڵ�
{//����data�Ǵ洢���½ڵ��е����ݣ�����������struct Node*������һ��ָ���´����ڵ��ָ��
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//ʹ��malloc��̬�����ڴ棬��СΪstruct Node�Ĵ�С��malloc������һ��void*ָ�룬�����Ҫ��������ת����struct Node*��
	if (newNode == NULL)//���newNode�Ƿ�ΪNULL��������ڴ�����Ƿ�ɹ�
	{
		printf("�ڴ����ʧ��\n");//�������ʧ�ܣ���ӡ����
		exit(EXIT_FAILURE);//��ֹ����
	}
	newNode->data = data;//�����½ڵ�������ֶ�Ϊ����Ĳ���data
	newNode->next = NULL;//���½ڵ��nextָ����ΪNULL����ʾ����ʱ��ָ���κνڵ�
	return newNode;//�����´�������ʼ���Ľڵ�ָ��
}

//������ĩβ��ӽڵ�
void appendNode(struct Node** head, int data)//����������ĩβ���һ���½ڵ�
{//����head��ָ������ͷָ���ָ��(��struct Node**)������data��Ҫ�洢���½ڵ��е����ݡ���������Ϊvoid����ʾ����û�з���ֵ
	struct Node* newNode = createNode(data);//���ú�������һ������data���½ڵ�
	if (*head == NULL)//�ж������Ƿ�Ϊ��
	{
		*head = newNode;//�������Ϊ��(��ͷָ��*headΪNULL)�����½ڵ���Ϊͷ�ڵ�
		return;//������
	}
	struct Node* temp = *head;//��ʼ��һ��ָ��tempָ��ͷ�ڵ�
	while (temp->next != NULL)
	{//ʹ��whileѭ����������ֱ��tempָ����������һ���ڵ�(��temp->nextΪNULL)
		temp = temp->next;
	}
	temp->next = newNode;//�������һ���ڵ��nextָ��ָ���½ڵ㣬�����Ӳ���
}

//������ͷ������ڵ�
void insertAtHead(struct Node** head, int data)//����������ͷ������һ���½ڵ�
{//����head��ָ������ͷָ���ָ�롣����data��Ҫ�洢���½ڵ��е����ݡ���������Ϊvoid
	struct Node* newNode = createNode(data);//���ú�������һ������data���½ڵ�
	newNode->next = *head;//���½ڵ��nextָ��ָ��ǰͷ�ڵ�
	*head = newNode;//����ͷ�ڵ�ָ��Ϊ�½ڵ�
}

//��ָ��λ�ò���ڵ�
void insertAtPosition(struct Node** head, int data, int position)//������ָ��λ�ò���һ���½ڵ�
{//����head��ָ������ͷָ���ָ�롣����data��Ҫ�洢���½ڵ��е����ݡ�����position��Ҫ����ڵ��λ��(��0��ʼ)��������Ϊvoid
	if (position == 0)//���λ���Ƿ�Ϊͷ��
	{
		insertAtHead(head, data);//���λ��Ϊ0�����ú�����ͷ������ڵ�
		return;//������
	}
	struct Node* newNode = createNode(data);//����һ���½ڵ�
	struct Node* temp = *head;//��ʼ��һ��ָ��tempָ��ͷ�ڵ�
	for (int i = 0; temp != NULL && i < position - 1; i++)//ʹ��forѭ����������ֱ��tempָ��ָ��λ�õ�ǰһ���ڵ�
	{//�������ĳ��Ȳ����Դﵽָ��λ�ã��˳�ѭ��
		temp = temp->next;
	}
	if (temp == NULL)//���λ����Ч�ԣ��������������tempΪNULL����ʾָ��λ�ó���������
	{
		printf(":λ�ó���������\n");//��ӡ������Ϣ
		free(newNode);//�ͷ��½ڵ��ڴ�
		return;//�˳�
	}
	newNode->next = temp->next;//�����½ڵ�
	temp->next = newNode;
}

//ɾ���ڵ�
void deleteNode(struct Node** head, int key)//����ɾ������ָ��ֵ�Ľڵ�
{//����head��ָ������ͷָ���ָ�룬����key��Ҫɾ���Ľڵ�ֵ����������Ϊvoid
	struct Node* temp = *head;//��ʼ��ָ��
	struct Node* prev = NULL;
	if (temp != NULL && temp->data == key)//���ͷ�ڵ㣬���ͷ�ڵ㲿λNULL��ͷ�ڵ�����ݵ���key����ɾ��ͷ�ڵ�
	{
		*head = temp->next;//��ͬϵ�G��ָ�����Ϊͷ�ڵ����һ���ڵ�
		free(temp);//�ͷ�ԭͷ�ڵ���ڴ�
		return;//���ؽ�������
	}
	while (temp != NULL && temp->data != key)//ʹ��whileѭ����������ֱ���ҵ����ݵ���key�Ľڵ�򵽴�����ĩβ
	{
		prev = temp;//prevָ�����ڸ��ٵ�ǰ�ڵ��ǰһ���ڵ�
		temp = temp->next;
	}
	if (temp == NULL)//�������������tempΪNULL����ʾδ�ҵ�����key�Ľڵ�
	{
		printf("δ�ҵ����� %d\n", key);//��ӡ������Ϣ
		return;//������
	}
	prev->next = temp->next;//��ǰһ��ϵ�G����nextָ��ָ��ǰ�ڵ����һ���ڵ㣬������ǰ�ڵ�
	free(temp);//�ͷŵ�ǰ�ڵ���ڴ�
}

//��ת����
void reverseList(struct Node** head)//���ڷ�ת����
{//����head��ָ������ͷָ���ָ�룬��������Ϊvoid
	struct Node* prev = NULL;//��ʼ��ָ��
	struct Node* current = *head;
	struct Node* next = NULL;
	while (current != NULL)//ʹ��whileѭ����������
	{
		next = current->next;
		current->next = prev;//��current�ڵ��nextָ��ָ��ǰһ���ڵ��prev
		prev = current;//����prevΪ��ǰ�ڵ�current
		current = next;//currentΪ��һ���ڵ�next
	}
	*head = prev;//ѭ��������prevָ��ָ��ԭ��������һ���ڵ㣬����ͷ�ڵ�ָ��Ϊprev
}

//�����ڵ�
int searchNode(struct Node* head, int key)//�����������Ƿ�ٳ����ڰ���ָ��ֵ�Ľڵ�
{//����headֵ����ͷָ�룬����key��Ҫ�����Ľڵ�ֵ����������Ϊint������1��ʾ�ҵ�������0��ʾδ�ҵ�
	struct Node* temp = head;//��ʼ��ָ��

	while (temp != NULL)//ʹ��whileѭ����������
	{ 
		if (temp->data == key)//����ҵ�����key�Ľڵ�
		{
			return 1;//����1
		}
		temp = temp->next;//���򣬼���������һ���ڵ�
	}
	return 0;//��������δ�ҵ�Ŀ��ڵ㣬����0
}

//��ӡ����
void printList(struct Node* head)//���ڴ�ӡ�����е����нڵ�
{//����head������ͷָ�룬��������Ϊvoid
	struct Node* temp = head;//��ʼ��ָ��
	while (temp != NULL)//ʹ��whileѭ����������
	{
		printf("%d -> ", temp->data);//��ӡ��ǰ�ڵ������
		temp = temp->next;
	}
	printf("\n");//�����������ӡ���з�
}

//��ȡ������
int getListLength(struct Node* head)//���ڻ�ȡ����ĳ���
{//����head������ͷָ�룬��������Ϊint����ʾ����ĳ���
	int length = 0;
	struct Node* temp = head;//��ʼ������
	while (temp != NULL)//ʹ��whileѭ��������������
	{
		length++;//ÿ����һ���ڵ㣬����lenght��һ
		temp = temp->next;
	}
	return length;//���ؼ���õ���������
}

//��ȡ�м�ڵ�
struct Node* getMiddle(struct Node* head)//���ڻ�ȡ������м�ڵ�
{//����head������ͷָ�룬��������Ϊstruct Node*��ʾ������м�ڵ�ָ��
	if (head == NULL)//��������Ƿ�Ϊ��
	{
		return NULL;//����NULL
	}
	struct Node* slow = head;
	struct Node* fast = head;//��ʼ��ָ��
	while (fast->next != NULL && fast->next->next != NULL)//ʹ��whileѭ����������//����ָ�뷨
	{//��ָ��ÿ���ƶ���������ָ��ÿ���ƶ�һ��
		slow = slow->next;//��ָ��ָ��������м�ڵ�
		fast = fast->next->next;//����ָ�뵽������ĩβʱ
	}
	return slow;//������ָ��ֱָ��Ľڵ㣬��������м�ڵ�
}

//�ϲ��������������
struct Node* merge(struct Node* left, struct Node* right)//���ںϲ��������������
{//����left��rightʱָ��������������ͷ�ڵ��ָ�룬��������Ϊstruct Node*��ʾ�ϲ��������ͷָ��
	if (left == NULL)//�����������leftΪ��
	{
		return right;//ֱ�ӷ���right����
	}
	if (right == NULL)//���right����Ϊ��
	{
		return left;//ֱ�ӷ���left����
	}
	if (left->data < right->data)//�Ƚ�left��right�ڵ������ֵ
	{//���left������С��right������ֵ����left�ڵ����ӵ�����������ݹ�ϲ�left->next��right
		left->next = merge(left->next, right);
		return left;//����
	}
	else
	{//���򣬽�right�ڵ����ӵ�����������ݹ�ϲ�left��right->next
		right->next = merge(left, right->next);
		return right;//����
	}
}

//�ϲ���������
struct Node* mergeSort(struct Node* head)//���ڶ�������й鲢����
{//����headʱ����ͷָ�룬��������Ϊstruct Node*��ʾ����������ͷָ��
	if (head == NULL || head->next == NULL)//�������Ϊ�ջ�ֻ��һ���ڵ�
	{
		return head;//ֱ�ӷ���
	}
	struct Node* mid = getMiddle(head);//ʹ�ú����ҵ�������м�ڵ�mid
	struct Node* left = head;//��������Ϊleft
	struct Node* right = mid->next;//��right�����֣�right��mid->next��ʼ
	mid->next = NULL;//��mid->next��ΪNULL���ָ�����
	left = mergeSort(left);//�ݹ���ú�����left����
	right = mergeSort(right);//�ݹ���ú�����right����
	return merge(left, right);//ʹ�ú����ϲ�����õ�left��right���������غϲ��������ͷָ��
}

//��������
void sortList(struct Node** head)//���ڶ������������
{//����headʱָ������ͷָ���ָ�룬��������Ϊvoid
	if (*head == NULL || (*head)->next == NULL)//�������Ϊ�ջ�ֻ��һ���ڵ�
	{
		return;//ֱ�ӷ���
	}
	struct Node* mid = getMiddle(*head);//ʹ�ú����ҵ�������м�ڵ�mid
	struct Node* left = *head;//��������Ϊleft
	struct Node* right = mid->next;//��right�����֣�right��mid->next��ʼ
	mid->next = NULL;//��mid->next��ΪNULL���ָ�����
	left = mergeSort(left);//�ݹ���ú�����left����
	right = mergeSort(right);//�ݹ���ú�����right����
	*head = merge(left, right);//ʹ�ú����ϲ�������left��right����������ͷ�ڵ�ָ��
}

//˫��������

//����˫������
struct DNode* createDNode(int data)//���ڴ���һ���µ�˫������ڵ� 
{//����data��Ҫ�洢���½ڵ��е����ݣ���������Ϊstruct DNode*��ʾ�´����Ľڵ�ָ��
	//ʹ��malloc��̬�����ڴ��㣬��СΪstruct DNode�Ĵ�С��malloc����һ��void*ָ�룬�����Ҫ��������ת��(struct DNode*)
	struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
	if (newNode == NULL)//���newNode�Ƿ�ΪNULL��������ڴ�����Ƿ�ɹ�
	{
		printf("�ڴ����ʧ��\n");//���ʧ�ܴ�ӡ������Ϣ
		exit(EXIT_FAILURE);//����ֹ����
	}
	newNode->data = data;//�����½ڵ�������ֶ�Ϊ����Ĳ���data
	newNode->next = NULL;//���½ڵ��nextָ����ΪNULL����ʾ���ݲ�ָ���κνڵ�
	newNode->prev = NULL;//���½ڵ��prevָ����ΪNULL����ʾ���ݲ�ָ���κνڵ�
	return newNode;//�����ܴ�������ʼ���Ľڵ�ָ��
}

//��˫������ĩβ��ӽڵ�
void appendDNode(struct Node** head, int data)//������˫������ĩβ���һ���½ڵ�
{//����head��ָ������ͷָ���ָ�룬����data��Ҫ�洢���½ڵ��е����ݣ���������Ϊvoid
	struct DNode* newNode = createDNode(data);//���ú�������һ������data���½ڵ�
	if (*head == NULL)//�������Ϊ��(��ͷָ��*headΪNULL)
	{
		*head = newNode;//���½ڵ���Ϊͷ�ڵ�
		return;//������
	}
	struct DNode* temp = *head;//��ʼ��һ��ָ��tempָ��ͷ�ڵ�
	while (temp->next != NULL)//ʹ��whileѭ����������ֱ��tempָ����������һ���ڵ�(��temp->nextΪNULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;//�����һ���ڵ��nextָ��ָ���½ڵ�
	newNode->prev = temp;//���½ڵ��prevָ��ָ�����һ���ڵ㣬�����Ӳ���
}

//ɾ��˫������ڵ�
void deleteDNode(struct DNode** head, int key)//����ɾ������ָ��ֵ��˫������ڵ�
{//����head��ָ������ͷָ���ָ�룬����key��Ҫɾ���Ľڵ�ֵ����������Ϊvoid
	struct DNode* temp = *head;//��ʼ��ָ��
	while (temp != NULL && temp->data != key)//ʹ��whileѭ����������ֱ���ҵ����ݵ���key��ϵ�G���򵽴�����ĩβ
	{
		temp = temp->next;
	}
	if (temp == NULL)//�������������tempΪNULL����ʾδ�ҵ�����key��ϵ�G��
	{
		printf("δ�ҵ����� %d\n", key);//��ӡ����
		return;//������
	}
	if (temp->prev != NULL)
	{//���temp��ǰ���㣬��ǰ��ϵ�G����nextָ��temp����һ���ڵ�
		temp->prev->next = temp->next;
	}
	else
	{//���tempû��ǰ���ڵ�(��temp��ͷ�ڵ�)����ͷ�ڵ�ָ�����Ϊtemp����һ���ڵ�
		*head = temp->next;
	}
	if (temp->next != NULL)
	{//���temp�к����ڵ㣬�������ڵ��prevָ��ָ��temp��ǰһ���ڵ�
		temp->next->prev = temp->prev;
	}
	free(temp);//�ͷ��ڴ�
}

//��ת˫������
void reverseDList(struct DNode** head)//���ڷ�ת˫������
{//����head��ָ������ͷָ���ָ�룬��������Ϊvoid
	struct DNode* temp = NULL;//��ʼ��ָ��
	struct DNode* current = *head;
	while (current != NULL)//ʹ��whileѭ����������
	{
		temp = current->prev;//������ǰ�ڵ��prev��nextָ��
		current->prev = current->next;
		current->next = temp;
		current = current->prev;//����currentָ��Ϊ��һ���ڵ�
	}
	if (temp != NULL)//����ͷ�ڵ�
	{//ѭ��������tempָ��ָ��ԭ��������һ���ڵ㣬����ͷ�ڵ�ָ��Ϊtemp->prev
		*head = temp->prev;
	}
}

//��ӡ˫������
void printDList(struct DNode* head)//���ڴ�ӡ˫����������нڵ�
{//����head������ͷָ�룬��������Ϊvoid
	struct DNode* temp = head;//��ʼ��ָ��
	while(temp != NULL)//ʹ��whileѭ����������
	{
		printf("%d -> ", temp->data);//��ӡ��ǰ�ڵ������
		temp = temp->next;
	}
	printf("NULL\n");//���������󣬴�ӡNULL��ʾ����Ľ���
}

//�����ӡ˫������
void printReverseDList(struct DNode* tail)//���ڷ����ӡ˫�������е����нڵ�
{//����tail������βָ�룬��������Ϊvoid
	struct DNode* temp = tail;//��ʼ��ϵ�G��
	while (temp != NULL)//ʹ��whileѭ������������Ϊ�ڵ���ǰ����
	{
		printf("%d -> ", temp->data);//��ӡ��ǰ�ڵ������
		temp = temp->prev;//��temp����Ϊ��ǰϵ�G����ǰһ��ϵ�G��temp->prev��ֱ����������������
	}
	printf("NULL\n");//���������󣬴�ӡNULL��ʾ����Ľ���
}

//ѭ��˫������
void appendCircularNode(struct DNode** head, int data)//������ѭ��˫������ĩβ���һ���½ڵ�
{//����head��ָ������ͷָ���ָ�룬����data��Ҫ�洢���½ڵ��е����ݣ���������Ϊvoid
	struct Node* newNode = createNode(data);//���ù���������һ������data���½ڵ�
	if (*head == NULL)//�������Ϊ��(��ͷָ��*headΪNULL)
	{
		*head = newNode; //���½ڵ���Ϊͷ�ڵ�
		newNode->next = *head;//������nextָ��ָ�������γ�ѭ��
		return;//���ؽ�������
	}
	struct Node* temp = *head;//��ʼ��һ��ָ��tempָ��ͷ�ڵ�
	while (temp->next != *head)//ʹ��whileѭ����������ֱ��tempָ����������һ���ڵ�(��temp->nextΪͷ�ڵ�)
	{
		temp = temp->next;
	}
	temp->next = newNode;//�����һ���ڵ��nextָ��ָ���½ڵ�newNode
	newNode->next = *head;//���½ڵ��nextָ��ָ��ͬϵ�G��*head���γ�ѭ��
}

//ɾ��ѭ��˫������
void deleteCirculaarNode(struct Node** head, int key)//����ɾ��������ָ��ֵ��ѭ��˫������ڵ�
{//����head��ָ��ͷָ���ָ�룬����key��Ҫɾ���Ľڵ�ֵ����������Ϊvoid
	if (*head == NULL)//��������Ƿ�Ϊ��
	{
		return;//���Ϊ�գ�ֱ�ӷ���
	}
	struct Node* temp = *head, * prev = NULL;//��ʼ��ָ��tempָ��ͷ�ڵ㣬prevΪNULL
	if (temp != NULL && temp->data == key)//���ͷ�ڵ�����ݵ���key
	{
		while (temp->next != *head)//�����ҵ����һ���ڵ�
		{
			temp = temp->next;
		}
		if (*head == (*head)->next)//���������ֻ��һ���ڵ�
		{
			free(*head);//�ͷ�ͷ�ڵ�
			*head = NULL;//��ͷ�ڵ�ָ����ΪNULL
		}
		else//�������ж���ڵ�
		{
			temp->next = (*head)->next;//�����һ���ڵ��nextָ��ָ��ͷ�ڵ����һ���ڵ�
			free(*head);//�ͷ�ͷ�ڵ�
			*head = temp->next;//����ͷ�ڵ�ָ��
		}
		return;//���أ���������
	}
	while (temp->next != *head && temp->data != key)//�����������Ҫɾ���Ľڵ�
	{
		prev = temp;//����Ǯ��һ���ڵ�
		temp = temp->next;//�ƶ�����һ���ڵ�
	}
	if (temp->data == key)//����ҵ�Ŀ��ڵ�
	{
		prev->next = temp->next;//��ǰһ���ڵ��nextָ��ָ��Ŀ��ڵ����һ���ڵ�
		free(temp);//�ͷ�Ŀ��ڵ�
	}
	else//���δ�ҵ�Ŀ��ڵ�
	{
		printf("δ�ҵ����� %d\n", key);//��ӡ������Ϣ
	}
}

//��ӡѭ��˫������
void printCircularList(struct Node* head)//���ڴ�ӡѭ��ˢ�Ǹ��������е����нڵ�
{//����head������ͷָ�룬��������Ϊvoid
	if (head == NULL)//��������Ƿ�Ϊ��
	{
		return;//���Ϊ�գ�ֱ�ӷ���
	}
	struct Node* temp = head;//��ʼ��ָ��
	do//ʹ��do-whileѭ������������ӡ��ǰ�ڵ������
	{
		printf("%d -> ", temp->data);
		temp = temp->next;//��temp����Ϊ��һ���ڵ㣬ֱ���ص�ͷ�ڵ�
	} while (temp != head);
	printf("HEAD\n");//���������󣬴�ӡHEAD��ʾѭ���������
}

//��������Ƿ��л�
int hasCycle(struct Node* head)//���ڼ�������Ƿ��л�
{//����head������ͷָ�룬��������Ϊint������1��ʾ�л�������0��ʾ�޻�
	struct Node* slow = head;//��ʼ������ָ��slow��fast����ָ������ͷ�ڵ�
	struct Node* fast = head;
	while (fast != NULL && fast->next != NULL)//ʹ��whileѭ����������������fast��fast->next����ΪNULL
	{
		slow = slow->next;//��ÿ��ѭ���У�slowָ��ǰ��һ��
		fast = fast->next->next;//fastָ��ǰ������
		if (slow == fast)//���slowָ����fastָ����������ʾ�������л�
		{
			return 1;//����1
		}
	}
	return 0;//ѭ��������slow��fastָ��δ���������ʾ�����в������ڻ�������0
}

//����������м�ڵ�
struct Node* findMiddleNode(struct Node* head)//���ڲ���������м�ڵ�
{//����head������ͷָ�룬��������Ϊstruct Node*��ʾ������м�ڵ�ָ��
	struct Node* slow = head;//��ʼ��ָ��
	struct Node* fast = head;
	while (fast != NULL && fast->next != NULL)//ʹ��2whileѭ����������
	{
		slow = slow->next;//��ָ��ÿ���ƶ�һ��
		fast = fast->next->next;//��ָ��ÿ���ƶ�����
	}//����ָ�뵽������ײ�ʱ����ָ��ָ��������м�ڵ�
	return slow;//������ָ��ָ��Ľڵ㣬��������м�ڵ�
}

//���������ļ�
void saveListToFile(struct Node* head, const char* filename)//���ڽ������浽�ļ�
{//����head������ͷָ�� ������filename���ļ�������������Ϊvoid
	FILE* file = fopen(filename, "w");//ʹ��fopen���ļ�����д����
	if (file == NULL)//����ļ���ʧ��
	{
		printf("�޷����ļ�\n");//��ӡ������Ϣ
		return;//������
	}
	struct Node* temp = head;
	while (temp != NULL)//ʹ��whileѭ����������
	{
		fprintf(file, "%d\n", temp->data);//��ÿ���ڵ������д���ļ���ÿ������ռһ��
		temp = temp->next;
	}
	fclose(file);//ʹ��fclose �ر��ļ�
}

//���ļ���������
struct Node* loadListFromFile(const char* filename)//���ڴ��ļ���������
{//����filename���ļ�������������Ϊstruct Node*��ʾ���غ������ͷָ��
	FILE* file = fopen(filename, "r");//ʹ��fopen���ļ����ж�д����
	if (file == NULL)//����ļ���ʧ��
	{
		printf("�޷����ļ�\n");//��ӡ������Ϣ
		return NULL;//������NULL
	}
	struct Node* head = NULL;//��ʼ������
	struct Node* temp = NULL;
	int data;
	while (fscanf(file, "%d", &data) != EOF)//ʹ��fscanf���ļ���ȡ���ݣ�ֱ���ļ�����
	{
		struct Node* newNode = createNode(data);//Ϊÿ����ȡ�������ݴ���һ���½ڵ㣬��������ӵ�����
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			temp->next = newNode;
		}
		temp = newNode;
	}
	fclose(file);//ʹ��fclose�ر��ļ�
	return head;//���ؼ��غ������ͷָ��
}

//ͳ�ƽڵ�ֵ���ֵĴ���
int countOccurrences(struct Node* head, int value)//����ͳ��������ָ��ֵ�Ľڵ���ִ���
{//����head������ͷָ�룬����value��Ҫͳ�Ƶ�ֵ����������Ϊint����ʾ���ֵĴ���
	int count = 0;//��ʼ������
	struct Node* temp = head;
	while (temp != NULL)//ʹ��whileѭ����������
	{
		if (temp->data == value)//�����ǰ���������ݵ���value
		{
			count++;//���Ӽ���
		}
		temp = temp->next;
	}
	return count;//���س��ֵĴ���
}

//��������ڵ�ֵ��ƽ��ֵ
double calculateAverage(struct Node* head)//���ڼ��������нڵ�ֵ��ƽ��ֵ
{//����headʹ����ͷָ�룬��������Ϊdouble����ʾƽ��ֵ
	if (head == NULL)//�������Ϊ��
	{
		return 0.0;//����0.0
	}
	int sun = 0;//��ʼ������
	int count = 0;
	struct Node* temp = head;//tempָ���ʼ��Ϊͷ�ڵ�
	while (temp != NULL)//ʹ��whileѭ����������
	{
		sun += temp->data;//��ÿ���ڵ��data�ۼӵ�sum
		count++;//�����Ӽ���count
		temp = temp->next;//��temp����Ϊ��һ���ڵ㣬ֱ����������������
	}
	return (double)sun / count;//���ؽڵ�ֵ��ƽ��ֵ����sum����count����ת��Ϊdouble����
}

//��������ڵ�ֵ�ķ���
double calculaateVariance(struct Node* head)//���ڼ��������нڵ�ֵ�ķ���
{//����headʹ����ͷָ�룬��������Ϊdouble����ʾ����
	double average = calculateAverage(head);//���ú�������ڵ�ֵ��ƽ��ֵ
	if (average == 0.0)//���ƽ��ֵΪ0.0
	{
		return 0.0;//����0.0
	}
	double sun = 0.0;//��ʼ������
	int count = 0;
	struct Node* temp = head;
	while (temp != NULL)//ʹ��whileѭ����������
	{
		sun += (temp->data - average) * (temp->data - average);//����ÿ���ڵ��data��ƽ��ֵ֮���ƽ�������ۼӵ�isum
		count++;//���Ӽ���
		temp = temp->next;//�����temp����Ϊ��һ���ڵ㣬ֱ����������������
	}
	return sun / count;//���ؽڵ�ֵ�ķ���
}

//�ͷ������ڴ�
void freeList(struct Node** head)//�����ͷ�������ڴ�
{//����head��ָ������ͷָ���ָ�룬��������Ϊvoid
	struct Node* temp;//��ʼ��ָ��
	while (*head != NULL)//ʹ��whileѭ����������������*head��ΪNULL
	{
		temp = *head;//��tempָ��ָ��ǰͷ�ڵ�
		*head = (*head)->next;//����ͷ�ڵ�ָ��Ϊ��һ���ڵ�
		free(temp);//�ͷŵ�ǰ�ڵ��ڴ棬�ظ��������̣�ֱ����������������
	}
}