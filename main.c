
#include"list.h"


//������
int main()
{
	struct Node* head = NULL;//��ʼ�����������ͷָ��
	struct DNode* dhead = NULL;//��ʼ��˫�������ͷָ��
	struct Node* chead = NULL;//��ʼ��ѭ�������ָ��
	int choice, data, position;//����������ڴ洢�û���ѡ����������ݺͲ���λ��
	//ѭ��������������
	while (1)//����ѭ�������ڲ��ϴ����û�����ֱ��ѡ���˳�
	{
		menu();//���ú�����ӡ�˵�
		if (scanf("%d", &choice) != 1)//��ȡ�û����벢�ж��Ƿ�Ϊ����
		{
			printf("�����������������\n");//�����������ʾ������Ϣ
			while (getchar() != '\n');//��ջ�����
			continue;
		}
		switch (choice)//�����û������ѡ��ִ����Ӧ����
		{
		case 1://��ӽڵ㵽��������ĩβ
			printf("��������: ");
			if (scanf("%d", &data) != 1)
			{
				printf("�����������������\n");
				while (getchar() != '\n');//��ջ�����
				continue;
			}
			appendNode(&head, data);
			break;
		case 2://AI����������ͷ������ڵ�
			printf("��������: ");
			if (scanf("%d", &data) != 1)
			{
				printf("�����������������\n");
				while (getchar() != '\n');//��ջ�����
				continue;
			}
			insertAtHead(&head, data);
			break;
		case 3://�ڵ�������ָ��λ�ò���ڵ�
			printf("��������: ");
			if (scanf("%d", &data) != 1)
			{
				printf("�����������������\n");
				while (getchar() != '\n');//��ջ�����
				continue;
			}
			printf("����λ�ã�");
			if (scanf("%d", &position) != 1)
			{
				printf("�����������������\n");
				while (getchar() != '\n');//��ջ�����
				continue;
			}
			insertAtPosition(&head, data, position);
			break;
		case 4://ɾ�����������е�ָ�����ݵĽڵ�
			printf("����Ҫɾ�������ݣ�");
			if (scanf("%d", &data) != 1)
			{
				printf("�����������������\n");
				while (getchar() != '\n');//��ջ�����
				continue;
			}
			deleteNode(&head, data);
			break;
		case 5://��ת��������
			reverseList(&head);
			break;
		case 6://���ҵ���������ָ��������
			printf("����Ҫ���ҵ����ݣ�");
			if (scanf("%d", &data) != 1)
			{
				printf("�����������������\n");
				while (getchar() != '\n');//��ջ�����
				continue;
			}
			if (searchNode(head, data))
			{
				printf("���� %d ������������\n", data);
			}
			else
			{
				printf("���� %d ��������������\n", data);
			}
			break;
		case 7://��ӡ����
			printList(head);
			break;
		case 8://��ȡ����ӡ��������ĳ���
			printf("������Ϊ��%d\n", getListLength(head));
			break;
		case 9://�Ե��������������
			sortList(&head);
			break;
		case 10://��ӡ˫����������˵���������Ӧ����
			dlistMenu();
			if (scanf("%d", &choice) != 1)
			{
				printf("�����������������\n");
				while (getchar() != '\n');//��ջ�����
				continue;
			}
			switch (choice)
			{
			case 1:
				printf("�������ݣ�");
				if (scanf("%d", &data) != 1)
				{
					printf("�����������������\n");
					while (getchar() != '\n');//��ջ�����
					continue;
				}
				appendDNode(&dhead, data);
				break;
			case 2:
				printf("����Ҫɾ�������ݣ�");
				if (scanf("%d", &data) != 1)
				{
					printf("�����������������\n");
					while (getchar() != '\n');//��ջ�����
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
				printf("����Ҫɾ�������ݣ�");
				if (scanf("%d", &data) != 1)
				{
					printf("�����������������\n");
					while (getchar() != '\n');//��ջ�����
					continue;
				}
				deleteDNode(&dhead, data);
				printReverseDList(dhead);
				break;
			}
			break;
		case 11://��ӡѭ����������˵���������Ӧ����
			clistMenu();
			if (scanf("%d", &choice) != 1)
			{
				printf("�����������������\n");
				while (getchar() != '\n');//��ջ�����
				continue;
			}
			switch (choice)
			{
			case 1:
				printf("�������ݣ�");
				if (scanf("%d", &data) != 1)
				{
					printf("�����������������\n");
					while (getchar() != '\n');//��ջ�����
					continue;
				}
				appendCircularNode(&chead, data);
				break;
			case 2:
				printf("����Ҫɾ�������ݣ�");
				if (scanf("%d", &data) != 1)
				{
					printf("�����������������\n");
					while (getchar() != '\n');//��ջ�����
					continue;
				}
				deleteCirculaarNode(&chead, data);
				break;
			case 3:
				printCircularList(chead);
				break;
			}
			break;
		case 12://��ⵥ���������Ƿ��л�
			if (hasCycle(head))
			{
				printf("�����д��ڻ�\n");
			}
			else
			{
				printf("�����в����ڻ�\n");
			}
			break;
		case 13://���ҵ���������м�ڵ㲢��ӡ
			printf("������м�ڵ�Ϊ��%d\n", findMiddleNode(head)->data);
			break;
		case 14://���浥�������ļ�
			saveListToFile(head, "list.txt");
			break;
		case 15://���ļ��м��ص�������
			head = loadListFromFile("list.txt");
			break;
		case 16://��ӡ��ͳ������������˵���������Ӧ����
			statsMenu();
			if (scanf("%d", &choice) != 1)
			{
				printf("�����������������\n");
				while (getchar() != '\n');//��ջ�����
				continue; 
			}
			switch (choice)
			{
			case 1:
				printf("�������ݣ�");
				if (scanf("%d", &data) != 1)
				{
					printf("�����������������\n");
					while (getchar() != '\n');//��ջ�����
					continue;
				}
				printf("���� %d ���� %d ��\n", data, countOccurrences(head, data));
				break;
			case 2:
				printf("�������ݵ�ƽ��ֵΪ:%.2f\n", calculateAverage(head));
				break;
			case 3:
				printf("�������ݵķ���Ϊ:%.2f\n", calculaateVariance(head));
				break;
			}
			break;
		case 0:
			 (&head);
			freeList((struct Node**)&dhead);
			freeList(&chead);
			printf("�˳�����\n");
			return 0;
		default:
			printf("��Чѡ������������\n");
			break;
		}
	}
}
