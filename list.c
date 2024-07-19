#include"list.h"


void menu()
{
	printf("1.在链表末尾添加新节点\n");
	printf("2.在链表头部插入新节点\n");
	printf("3.在指定位置插入新节点\n");
	printf("4.删除指定数据的节点\n");
	printf("5.反转链表\n");
	printf("6.查找链表中的某个数据\n");
	printf("7.打印链表\n");
	printf("8.获取链表长度\n");
	printf("9.对链表进行排序\n");
	printf("10.使用双向链表\n");
	printf("11.使用循环链表\n");
	printf("12.检测链表中是否有环\n");
	printf("13.查找链表的中间节点\n");
	printf("14.保存链表到文件\n");
	printf("15.从文件中加载链表\n");
	printf("16.统计与分析\n");
	printf("0.退出\n");
	printf("请输入选择\n");
}

void dlistMenu()
{
	printf("1.在双向链表末尾添加新节点\n");
	printf("2.删除双向链表中的节点\n");
	printf("3.反转双向链表\n");
	printf("4.打印双向链表\n");
	printf("5.反向打印双向链表\n");
	printf("请输入选择\n");
}

void clistMenu()
{
	printf("1.在循环链表末尾添加新节点\n");
	printf("2.删除循环链表中的节点\n");
	printf("3.打印循环链表\n");
	printf("请输入选择\n");
}

void statsMenu()
{
	printf("1.统计链表中的某个数据出现的次数\n");
	printf("2.计算链表数据的平均值\n");
	printf("3.计算链表数据的方差\n");
	printf("请输入选择\n");
}

//添加新节点
struct Node* createNode(int data)//用于创建一个新的链表节点
{//参数data是存储在新节点中的数据，返回类型是struct Node*及返回一个指向新创建节点的指针
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//使用malloc动态分配内存，大小为struct Node的大小。malloc返回有一个void*指针，因此需要进行类型转换（struct Node*）
	if (newNode == NULL)//检查newNode是否为NULL，及检查内存分配是否成功
	{
		printf("内存分配失败\n");//如果分配失败，打印错误
		exit(EXIT_FAILURE);//终止程序
	}
	newNode->data = data;//设置新节点的数据字段为传入的参数data
	newNode->next = NULL;//将新节点的next指针设为NULL，表示它暂时不指向任何节点
	return newNode;//返回新创建并初始化的节点指针
}

//在链表末尾添加节点
void appendNode(struct Node** head, int data)//用于在链表末尾添加一个新节点
{//参数head是指向链表头指针的指针(即struct Node**)。参数data是要存储在新节点中的数据。返回类型为void，表示函数没有返回值
	struct Node* newNode = createNode(data);//调用函数创建一个包含data的新节点
	if (*head == NULL)//判断链表是否为空
	{
		*head = newNode;//如果链表为空(即头指针*head为NULL)，则将新节点设为头节点
		return;//并返回
	}
	struct Node* temp = *head;//初始化一个指针temp指向头节点
	while (temp->next != NULL)
	{//使用while循环遍历链表，直到temp指向链表的最后一个节点(即temp->next为NULL)
		temp = temp->next;
	}
	temp->next = newNode;//讲啊最后一个节点的next指针指向新节点，完成添加操作
}

//在链表头部插入节点
void insertAtHead(struct Node** head, int data)//用于在链表头部插入一个新节点
{//参数head是指向链表头指针的指针。参数data是要存储在新节点中的数据。返回类型为void
	struct Node* newNode = createNode(data);//调用函数创建一个包含data的新节点
	newNode->next = *head;//将新节点的next指针指向当前头节点
	*head = newNode;//更新头节点指针为新节点
}

//在指定位置插入节点
void insertAtPosition(struct Node** head, int data, int position)//用于在指定位置插入一个新节点
{//参数head是指向链表头指针的指针。参数data是要存储在新节点中的数据。参数position是要插入节点的位置(从0开始)返回类型为void
	if (position == 0)//检查位置是否为头部
	{
		insertAtHead(head, data);//如果位置为0，调用函数在头部插入节点
		return;//并返回
	}
	struct Node* newNode = createNode(data);//创建一个新节点
	struct Node* temp = *head;//初始化一个指针temp指向头节点
	for (int i = 0; temp != NULL && i < position - 1; i++)//使用for循环遍历链表，直到temp指向指定位置的前一个节点
	{//如果链表的长度不足以达到指定位置，退出循环
		temp = temp->next;
	}
	if (temp == NULL)//检查位置有效性，如果遍历结束后temp为NULL，表示指定位置超出链表长度
	{
		printf(":位置超出链表长度\n");//打印错误信息
		free(newNode);//释放新节点内存
		return;//退出
	}
	newNode->next = temp->next;//插入新节点
	temp->next = newNode;
}

//删除节点
void deleteNode(struct Node** head, int key)//用于删除包含指定值的节点
{//参数head是指向链表头指针的指针，参数key是要删除的节点值，返回类型为void
	struct Node* temp = *head;//初始化指针
	struct Node* prev = NULL;
	if (temp != NULL && temp->data == key)//检查头节点，如果头节点部位NULL且头节点的数据等于key，则删除头节点
	{
		*head = temp->next;//将同系欸但指针更新为头节点的下一个节点
		free(temp);//释放原头节点的内存
		return;//返回结束函数
	}
	while (temp != NULL && temp->data != key)//使用while循环遍历链表，直到找到数据等于key的节点或到达链表末尾
	{
		prev = temp;//prev指针用于跟踪当前节点的前一个节点
		temp = temp->next;
	}
	if (temp == NULL)//如果遍历结束后temp为NULL，表示未找到包含key的节点
	{
		printf("未找到数据 %d\n", key);//打印错误信息
		return;//并返回
	}
	prev->next = temp->next;//将前一个系欸但的next指针指向当前节点的下一个节点，跳过当前节点
	free(temp);//释放当前节点的内存
}

//反转链表
void reverseList(struct Node** head)//用于反转链表
{//参数head是指向链表头指针的指针，返回类型为void
	struct Node* prev = NULL;//初始化指针
	struct Node* current = *head;
	struct Node* next = NULL;
	while (current != NULL)//使用while循环遍历链表
	{
		next = current->next;
		current->next = prev;//将current节点的next指针指向前一个节点的prev
		prev = current;//更新prev为当前节点current
		current = next;//current为下一个节点next
	}
	*head = prev;//循环结束后，prev指针指向原链表的最后一个节点，更新头节点指针为prev
}

//搜索节点
int searchNode(struct Node* head, int key)//搜索链表中是否促成你在包含指定值的节点
{//参数head值链表头指针，参数key是要搜索的节点值，返回类型为int，返回1表示找到，返回0表示未找到
	struct Node* temp = head;//初始化指针

	while (temp != NULL)//使用while循环遍历链表
	{ 
		if (temp->data == key)//如果找到包含key的节点
		{
			return 1;//返回1
		}
		temp = temp->next;//否则，继续遍历下一个节点
	}
	return 0;//遍历结束未找到目标节点，返回0
}

//打印链表
void printList(struct Node* head)//用于打印链表中的所有节点
{//参数head是链表头指针，返回类型为void
	struct Node* temp = head;//初始化指针
	while (temp != NULL)//使用while循环遍历链表
	{
		printf("%d -> ", temp->data);//打印当前节点的数据
		temp = temp->next;
	}
	printf("\n");//遍历结束后打印换行符
}

//获取链表长度
int getListLength(struct Node* head)//用于获取链表的长度
{//参数head是链表头指针，返回类型为int，表示链表的长度
	int length = 0;
	struct Node* temp = head;//初始化变量
	while (temp != NULL)//使用while循环遍历链表并计数
	{
		length++;//每遍历一个节点，长度lenght加一
		temp = temp->next;
	}
	return length;//返回计算得到的链表长度
}

//获取中间节点
struct Node* getMiddle(struct Node* head)//用于获取链表的中间节点
{//参数head是链表头指针，返回类型为struct Node*表示链表的中间节点指针
	if (head == NULL)//检查链表是否为空
	{
		return NULL;//返回NULL
	}
	struct Node* slow = head;
	struct Node* fast = head;//初始化指针
	while (fast->next != NULL && fast->next->next != NULL)//使用while循环遍历链表//快慢指针法
	{//快指针每次移动两步，慢指针每次移动一步
		slow = slow->next;//慢指针指向链表的中间节点
		fast = fast->next->next;//当快指针到达链表末尾时
	}
	return slow;//返回满指针直指向的节点，即链表的中间节点
}

//合并两个有序的链表
struct Node* merge(struct Node* left, struct Node* right)//用于合并两个有序的链表
{//参数left和right时指向连个有序链表头节点的指针，返回类型为struct Node*表示合并后的链表头指针
	if (left == NULL)//检查空链表，如果left为空
	{
		return right;//直接返回right链表
	}
	if (right == NULL)//如果right链表为空
	{
		return left;//直接返回left链表
	}
	if (left->data < right->data)//比较left和right节点的数据值
	{//如果left的数据小于right的数据值，将left节点连接到结果链表，并递归合并left->next和right
		left->next = merge(left->next, right);
		return left;//返回
	}
	else
	{//否则，将right节点连接到结果链表，并递归合并left和right->next
		right->next = merge(left, right->next);
		return right;//返回
	}
}

//合并排序链表
struct Node* mergeSort(struct Node* head)//用于对链表进行归并排序
{//参数head时链表头指针，返回类型为struct Node*表示排序后的链表头指针
	if (head == NULL || head->next == NULL)//如果链表为空或只有一个节点
	{
		return head;//直接返回
	}
	struct Node* mid = getMiddle(head);//使用函数找到链表的中间节点mid
	struct Node* left = head;//将链表拆分为left
	struct Node* right = mid->next;//和right两部分，right从mid->next开始
	mid->next = NULL;//将mid->next设为NULL，分割链表
	left = mergeSort(left);//递归调用函数对left排序
	right = mergeSort(right);//递归调用函数对right排序
	return merge(left, right);//使用函数合并排序好的left和right链表，并返回合并后的链表头指针
}

//排序链表
void sortList(struct Node** head)//用于对链表进行排序
{//参数head时指向链表头指针的指针，返回类型为void
	if (*head == NULL || (*head)->next == NULL)//如果链表为空或只有一个节点
	{
		return;//直接返回
	}
	struct Node* mid = getMiddle(*head);//使用函数找到链表的中间节点mid
	struct Node* left = *head;//将链表拆分为left
	struct Node* right = mid->next;//和right两部分，right从mid->next开始
	mid->next = NULL;//将mid->next设为NULL，分割链表
	left = mergeSort(left);//递归调用函数对left排序
	right = mergeSort(right);//递归调用函数对right排序
	*head = merge(left, right);//使用函数合并排序后的left和right链表，并更新头节点指针
}

//双向链表函数

//创建双向链表
struct DNode* createDNode(int data)//用于创建一个新的双向链表节点 
{//参数data是要存储在新节点中的数据，返回类型为struct DNode*表示新创建的节点指针
	//使用malloc动态分配内粗你，大小为struct DNode的大小，malloc返回一个void*指针，因此需要进行类型转换(struct DNode*)
	struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
	if (newNode == NULL)//检查newNode是否为NULL，即检查内存分配是否成功
	{
		printf("内存分配失败\n");//如果失败打印错误信息
		exit(EXIT_FAILURE);//并终止程序
	}
	newNode->data = data;//设置新节点的数据字段为传入的参数data
	newNode->next = NULL;//将新节点的next指针设为NULL，表示它暂不指向任何节点
	newNode->prev = NULL;//将新节点的prev指针设为NULL，表示它暂不指向任何节点
	return newNode;//返回熊创建并初始化的节点指针
}

//在双向链表末尾添加节点
void appendDNode(struct Node** head, int data)//用于在双向链表末尾添加一个新节点
{//参数head是指向链表头指针的指针，参数data是要存储在新节点中的数据，返回类型为void
	struct DNode* newNode = createDNode(data);//调用函数创建一个包含data的新节点
	if (*head == NULL)//如果链表为空(即头指针*head为NULL)
	{
		*head = newNode;//则将新节点设为头节点
		return;//并返回
	}
	struct DNode* temp = *head;//初始化一个指针temp指向头节点
	while (temp->next != NULL)//使用while循环遍历链表，直到temp指向链表的最后一个节点(即temp->next为NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;//将最后一个节点的next指针指向新节点
	newNode->prev = temp;//将新节点的prev指针指向最后一个节点，完成添加操作
}

//删除双向链表节点
void deleteDNode(struct DNode** head, int key)//用于删除包含指定值的双向链表节点
{//参数head是指向链表头指针的指针，参数key是要删除的节点值，返回类型为void
	struct DNode* temp = *head;//初始化指针
	while (temp != NULL && temp->data != key)//使用while循环遍历链表，直到找到数据等于key的系欸但或到达链表末尾
	{
		temp = temp->next;
	}
	if (temp == NULL)//如果遍历结束后temp为NULL，表示未找到包含key的系欸但
	{
		printf("未找到数据 %d\n", key);//打印错误
		return;//并返回
	}
	if (temp->prev != NULL)
	{//如果temp有前驱点，将前驱系欸但的next指向temp的下一个节点
		temp->prev->next = temp->next;
	}
	else
	{//如果temp没有前驱节点(即temp是头节点)，将头节点指针更新为temp的下一个节点
		*head = temp->next;
	}
	if (temp->next != NULL)
	{//如果temp有后续节点，将后续节点的prev指针指向temp的前一个节点
		temp->next->prev = temp->prev;
	}
	free(temp);//释放内存
}

//反转双向链表
void reverseDList(struct DNode** head)//用于反转双向链表
{//参数head是指向链表头指针的指针，返回类型为void
	struct DNode* temp = NULL;//初始化指针
	struct DNode* current = *head;
	while (current != NULL)//使用while循环遍历链表
	{
		temp = current->prev;//交换当前节点的prev和next指针
		current->prev = current->next;
		current->next = temp;
		current = current->prev;//更新current指针为下一个节点
	}
	if (temp != NULL)//更新头节点
	{//循环结束后，temp指针指向原链表的最后一个节点，更新头节点指针为temp->prev
		*head = temp->prev;
	}
}

//打印双向链表
void printDList(struct DNode* head)//用于打印双线链表的所有节点
{//参数head是链表头指针，返回类型为void
	struct DNode* temp = head;//初始化指针
	while(temp != NULL)//使用while循环遍历链表
	{
		printf("%d -> ", temp->data);//打印当前节点的数据
		temp = temp->next;
	}
	printf("NULL\n");//遍历结束后，打印NULL表示链表的结束
}

//反向打印双向链表
void printReverseDList(struct DNode* tail)//用于反向打印双向链表中的所有节点
{//参数tail是链表尾指针，返回类型为void
	struct DNode* temp = tail;//初始化系欸但
	while (temp != NULL)//使用while循环遍历链表，从为节点向前遍历
	{
		printf("%d -> ", temp->data);//打印当前节点的数据
		temp = temp->prev;//将temp更新为当前系欸但的前一个系欸但temp->prev，直到遍历完整个链表
	}
	printf("NULL\n");//遍历结束后，打印NULL表示链表的结束
}

//循环双向链表
void appendCircularNode(struct DNode** head, int data)//用于在循环双向链表末尾添加一个新节点
{//参数head是指向链表头指针的指针，参数data是要存储在新节点中的数据，返回类型为void
	struct Node* newNode = createNode(data);//调用哈纳树创建一个包含data的新节点
	if (*head == NULL)//如果链表为空(即头指针*head为NULL)
	{
		*head = newNode; //则将新节点设为头节点
		newNode->next = *head;//并将其next指针指向自身，形成循环
		return;//返回结束函数
	}
	struct Node* temp = *head;//初始化一个指针temp指向头节点
	while (temp->next != *head)//使用while循环遍历链表，直到temp指向链表的最后一个节点(即temp->next为头节点)
	{
		temp = temp->next;
	}
	temp->next = newNode;//将最后一个节点的next指针指向新节点newNode
	newNode->next = *head;//将新节点的next指针指向同系欸但*head，形成循环
}

//删除循环双向链表
void deleteCirculaarNode(struct Node** head, int key)//用于删除除包含指定值的循环双向链表节点
{//参数head是指向头指针的指针，参数key是要删除的节点值，返回类型为void
	if (*head == NULL)//检查链表是否为空
	{
		return;//如果为空，直接返回
	}
	struct Node* temp = *head, * prev = NULL;//初始化指针temp指向头节点，prev为NULL
	if (temp != NULL && temp->data == key)//如果头节点的数据等于key
	{
		while (temp->next != *head)//遍历找到最后一个节点
		{
			temp = temp->next;
		}
		if (*head == (*head)->next)//如果链表中只有一个节点
		{
			free(*head);//释放头节点
			*head = NULL;//将头节点指针设为NULL
		}
		else//链表中有多个节点
		{
			temp->next = (*head)->next;//将最后一个节点的next指针指向头节点的下一个节点
			free(*head);//释放头节点
			*head = temp->next;//更新头节点指针
		}
		return;//返回，结束函数
	}
	while (temp->next != *head && temp->data != key)//遍历链表查找要删除的节点
	{
		prev = temp;//更新钱啊一个节点
		temp = temp->next;//移动到下一个节点
	}
	if (temp->data == key)//如果找到目标节点
	{
		prev->next = temp->next;//将前一个节点的next指针指向目标节点的下一个节点
		free(temp);//释放目标节点
	}
	else//如果未找到目标节点
	{
		printf("未找到数据 %d\n", key);//打印错误信息
	}
}

//打印循环双向链表
void printCircularList(struct Node* head)//用于打印循环刷那个想链表中的所有节点
{//参数head是链表头指针，返回类型为void
	if (head == NULL)//检查链表是否为空
	{
		return;//如果为空，直接返回
	}
	struct Node* temp = head;//初始化指针
	do//使用do-while循环遍历链表，打印当前节点的数据
	{
		printf("%d -> ", temp->data);
		temp = temp->next;//将temp更新为下一个节点，直到回到头节点
	} while (temp != head);
	printf("HEAD\n");//遍历结束后，打印HEAD表示循环链表结束
}

//检查链表是否有环
int hasCycle(struct Node* head)//用于检查链表是否有环
{//参数head是链表头指针，返回类型为int，返回1表示有环，返回0表示无环
	struct Node* slow = head;//初始化两个指针slow和fast，均指向链表头节点
	struct Node* fast = head;
	while (fast != NULL && fast->next != NULL)//使用while循环遍历链表，条件是fast和fast->next均不为NULL
	{
		slow = slow->next;//在每次循环中，slow指针前进一步
		fast = fast->next->next;//fast指针前进两步
		if (slow == fast)//如果slow指针与fast指针相遇，表示链表中有环
		{
			return 1;//返回1
		}
	}
	return 0;//循环结束，slow和fast指针未相遇，则表示链表中并不存在环，返回0
}

//查找链表的中间节点
struct Node* findMiddleNode(struct Node* head)//用于查找链表的中间节点
{//参数head是链表头指针，返回类型为struct Node*表示链表的中间节点指针
	struct Node* slow = head;//初始化指针
	struct Node* fast = head;
	while (fast != NULL && fast->next != NULL)//使用2while循环遍历链表
	{
		slow = slow->next;//慢指针每次移动一步
		fast = fast->next->next;//快指针每次移动两步
	}//当快指针到达链表底部时，慢指针指向链表的中间节点
	return slow;//返回慢指针指向的节点，即链表的中间节点
}

//保存链表到文件
void saveListToFile(struct Node* head, const char* filename)//用于将链表保存到文件
{//参数head是链表头指针 ，参数filename是文件名，返回类型为void
	FILE* file = fopen(filename, "w");//使用fopen打开文件进行写操作
	if (file == NULL)//如果文件打开失败
	{
		printf("无法打开文件\n");//打印错误信息
		return;//并返回
	}
	struct Node* temp = head;
	while (temp != NULL)//使用while循环遍历链表
	{
		fprintf(file, "%d\n", temp->data);//将每个节点的数据写入文件，每个数据占一行
		temp = temp->next;
	}
	fclose(file);//使用fclose 关闭文件
}

//从文件加载链表
struct Node* loadListFromFile(const char* filename)//用于从文件加载链表
{//参数filename是文件名，返回类型为struct Node*表示加载后的链表头指针
	FILE* file = fopen(filename, "r");//使用fopen打开文件进行读写操作
	if (file == NULL)//如果文件打开失败
	{
		printf("无法打开文件\n");//打印错误信息
		return NULL;//并返回NULL
	}
	struct Node* head = NULL;//初始化变量
	struct Node* temp = NULL;
	int data;
	while (fscanf(file, "%d", &data) != EOF)//使用fscanf从文件读取数据，直到文件结束
	{
		struct Node* newNode = createNode(data);//为每个读取到的数据创建一个新节点，并将其添加到链表
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
	fclose(file);//使用fclose关闭文件
	return head;//返回加载后的链表头指针
}

//统计节点值出现的次数
int countOccurrences(struct Node* head, int value)//用于统计链表中指定值的节点出现次数
{//参数head是链表头指针，参数value是要统计的值，返回类型为int，表示出现的次数
	int count = 0;//初始化变量
	struct Node* temp = head;
	while (temp != NULL)//使用while循环遍历链表
	{
		if (temp->data == value)//如果大当前集结点的数据等于value
		{
			count++;//增加计数
		}
		temp = temp->next;
	}
	return count;//返回出现的次数
}

//计算链表节点值的平均值
double calculateAverage(struct Node* head)//用于计算链表啊中节点值的平均值
{//参数head使链表头指针，返回类型为double，表示平均值
	if (head == NULL)//如果链表为空
	{
		return 0.0;//返回0.0
	}
	int sun = 0;//初始化变量
	int count = 0;
	struct Node* temp = head;//temp指针初始化为头节点
	while (temp != NULL)//使用while循环遍历链表
	{
		sun += temp->data;//将每个节点的data累加到sum
		count++;//并增加计数count
		temp = temp->next;//将temp更新为下一个节点，直到遍历完整个链表
	}
	return (double)sun / count;//返回节点值的平均值，即sum除以count，并转换为double类型
}

//计算链表节点值的方差
double calculaateVariance(struct Node* head)//用于计算链表中节点值的方差
{//参数head使链表头指针，返回类型为double，表示方差
	double average = calculateAverage(head);//调用函数计算节点值的平均值
	if (average == 0.0)//如果平均值为0.0
	{
		return 0.0;//返回0.0
	}
	double sun = 0.0;//初始化变量
	int count = 0;
	struct Node* temp = head;
	while (temp != NULL)//使用while循环遍历链表
	{
		sun += (temp->data - average) * (temp->data - average);//计算每个节点的data与平均值之间的平方，并累加到isum
		count++;//增加计数
		temp = temp->next;//见表格temp更新为下一个节点，直到遍历完整个链表
	}
	return sun / count;//返回节点值的方差
}

//释放链表内存
void freeList(struct Node** head)//用于释放链表的内存
{//参数head是指向链表头指针的指针，返回类型为void
	struct Node* temp;//初始化指针
	while (*head != NULL)//使用while循环遍历链表条件是*head不为NULL
	{
		temp = *head;//将temp指针指向当前头节点
		*head = (*head)->next;//更新头节点指针为下一个节点
		free(temp);//释放当前节点内存，重复上述过程，直到遍历完整个链表
	}
}