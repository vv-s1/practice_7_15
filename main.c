
#include"list.h"


//主函数
int main()
{
	struct Node* head = NULL;//初始化单向链表的头指针
	struct DNode* dhead = NULL;//初始化双向链表的头指针
	struct Node* chead = NULL;//初始化循环链表的指针
	int choice, data, position;//定义变量用于存储用户的选择、输入的数据和插入位置
	//循环处理用于输入
	while (1)//无线循环，用于不断处理用户输入直到选择退出
	{
		menu();//调用函数打印菜单
		if (scanf("%d", &choice) != 1)//获取用户输入并判断是否为数字
		{
			printf("输出错误，请输入数字\n");//如果不是则提示错误信息
			while (getchar() != '\n');//清空缓存区
			continue;
		}
		switch (choice)//根据用户输入的选择执行相应操作
		{
		case 1://添加节点到单向链表末尾
			printf("输入数据: ");
			if (scanf("%d", &data) != 1)
			{
				printf("输入错误，请输入数字\n");
				while (getchar() != '\n');//清空缓存区
				continue;
			}
			appendNode(&head, data);
			break;
		case 2://AI打哪象链表头部插入节点
			printf("输入数据: ");
			if (scanf("%d", &data) != 1)
			{
				printf("输入错误，请输入数字\n");
				while (getchar() != '\n');//清空缓存区
				continue;
			}
			insertAtHead(&head, data);
			break;
		case 3://在单向链表指定位置插入节点
			printf("输入数据: ");
			if (scanf("%d", &data) != 1)
			{
				printf("输入错误，请输入数字\n");
				while (getchar() != '\n');//清空缓存区
				continue;
			}
			printf("输入位置：");
			if (scanf("%d", &position) != 1)
			{
				printf("输入错误，请输入数字\n");
				while (getchar() != '\n');//清空缓存区
				continue;
			}
			insertAtPosition(&head, data, position);
			break;
		case 4://删除单向链表中的指定数据的节点
			printf("输入要删除的数据：");
			if (scanf("%d", &data) != 1)
			{
				printf("输入错误，请输入数字\n");
				while (getchar() != '\n');//清空缓存区
				continue;
			}
			deleteNode(&head, data);
			break;
		case 5://反转单向链表
			reverseList(&head);
			break;
		case 6://查找单向链表中指定的数据
			printf("输入要查找的数据：");
			if (scanf("%d", &data) != 1)
			{
				printf("输入错误，请输入数字\n");
				while (getchar() != '\n');//清空缓存区
				continue;
			}
			if (searchNode(head, data))
			{
				printf("数据 %d 存在于链表中\n", data);
			}
			else
			{
				printf("数据 %d 不存在于链表中\n", data);
			}
			break;
		case 7://打印链表
			printList(head);
			break;
		case 8://获取并打印单向链表的长度
			printf("链表长度为：%d\n", getListLength(head));
			break;
		case 9://对单向链表进行排序
			sortList(&head);
			break;
		case 10://打印双向链表操作菜单并处理相应操作
			dlistMenu();
			if (scanf("%d", &choice) != 1)
			{
				printf("输入错误，请输入数字\n");
				while (getchar() != '\n');//清空缓存区
				continue;
			}
			switch (choice)
			{
			case 1:
				printf("输入数据：");
				if (scanf("%d", &data) != 1)
				{
					printf("输入错误，请输入数字\n");
					while (getchar() != '\n');//清空缓存区
					continue;
				}
				appendDNode(&dhead, data);
				break;
			case 2:
				printf("输入要删除的数据：");
				if (scanf("%d", &data) != 1)
				{
					printf("输入错误，请输入数字\n");
					while (getchar() != '\n');//清空缓存区
					continue;
				}
				deleteDNode(&dhead, data);
				break;
			case 3:
				reverseDList(&dhead);
				break;
			case 4:
				printDList(dhead);
				break;
			case 5:
				printf("输入要删除的数据：");
				if (scanf("%d", &data) != 1)
				{
					printf("输入错误，请输入数字\n");
					while (getchar() != '\n');//清空缓存区
					continue;
				}
				deleteDNode(&dhead, data);
				printReverseDList(dhead);
				break;
			}
			break;
		case 11://打印循环链表操作菜单并处理相应操作
			clistMenu();
			if (scanf("%d", &choice) != 1)
			{
				printf("输入错误，请输入数字\n");
				while (getchar() != '\n');//清空缓存区
				continue;
			}
			switch (choice)
			{
			case 1:
				printf("输入数据：");
				if (scanf("%d", &data) != 1)
				{
					printf("输入错误，请输入数字\n");
					while (getchar() != '\n');//清空缓存区
					continue;
				}
				appendCircularNode(&chead, data);
				break;
			case 2:
				printf("输入要删除的数据：");
				if (scanf("%d", &data) != 1)
				{
					printf("输入错误，请输入数字\n");
					while (getchar() != '\n');//清空缓存区
					continue;
				}
				deleteCirculaarNode(&chead, data);
				break;
			case 3:
				printCircularList(chead);
				break;
			}
			break;
		case 12://检测单项链表中是否有环
			if (hasCycle(head))
			{
				printf("链表中存在环\n");
			}
			else
			{
				printf("链表中不存在环\n");
			}
			break;
		case 13://查找单项链表的中间节点并打印
			printf("链表的中间节点为：%d\n", findMiddleNode(head)->data);
			break;
		case 14://保存单向链表到文件
			saveListToFile(head, "list.txt");
			break;
		case 15://从文件中加载单向链表
			head = loadListFromFile("list.txt");
			break;
		case 16://打印并统计与分析操作菜单并处理相应操作
			statsMenu();
			if (scanf("%d", &choice) != 1)
			{
				printf("输入错误，请输入数字\n");
				while (getchar() != '\n');//清空缓存区
				continue; 
			}
			switch (choice)
			{
			case 1:
				printf("输入数据：");
				if (scanf("%d", &data) != 1)
				{
					printf("输入错误，请输入数字\n");
					while (getchar() != '\n');//清空缓存区
					continue;
				}
				printf("数据 %d 出现 %d 次\n", data, countOccurrences(head, data));
				break;
			case 2:
				printf("链表数据的平均值为:%.2f\n", calculateAverage(head));
				break;
			case 3:
				printf("链表数据的方差为:%.2f\n", calculaateVariance(head));
				break;
			}
			break;
		case 0:
			 (&head);
			freeList((struct Node**)&dhead);
			freeList(&chead);
			printf("退出程序\n");
			return 0;
		default:
			printf("无效选择，请重新输入\n");
			break;
		}
	}
}
