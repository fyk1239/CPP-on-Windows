#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct work //����work�ṹ��
{
	int jobNo;		  //����
	char Name[20];	  //����
	char sex[10];	  //�Ա�
	int birthday;	  //��������
	int num;		  //��Ů����
	char marital[20]; //����״��
	struct work *next;
} wo;

void luru(wo *head)
{
	system("cls"); //������
	wo *p = head;
	wo *q; //����p��p2Ϊͷָ��
	int a;
	printf("������������������ְԱ��Ϣ  :");
	scanf("%d", &a); //������Ա������
	int c = 0;
	for (int n = 0; n < a; n++)
	{

		wo *p1 = (wo *)malloc(sizeof(wo));
		c++;
		printf("�������%d��ְԱ����Ϣ\n", c);
		printf("������ְ����:      ");
		scanf("%d", &p1->jobNo);
		while (p1->jobNo < 1)
		{
			printf("�����ְ���Ų����Ϲ涨������������!!\n");
			printf("����������ְ����:      ");
			scanf("%d", &p1->jobNo);
		}
		q = head;
		while (q->next != NULL)
		{
			q = q->next;
			while (p1->jobNo == q->jobNo)
			{
				printf("��ְ�����Ѵ��ڣ����������룡\n");
				scanf("%d", &p1->jobNo);
			}
		}
		printf("����������:        ");
		scanf("%s", &p1->Name);
		printf("�������Ա�(W/M)��  ");
		scanf("%s", &p1->sex);
		while (strcmp(p1->sex, "W") != 0 && strcmp(p1->sex, "M") != 0)
		{
			printf("�����ְ���Ա𲻷��Ϲ涨������������!!\n");
			printf("����������ְ���Ա�:      ");
			scanf("%s", &p1->sex);
		}
		printf("�������������:");
		scanf("%d", &p1->birthday);
		printf("���������״��");
		scanf("%s", &p1->marital);

		printf("��������Ů����");
		scanf("%d", &p1->num);

		q = head;

		p->next = p1;
		p = p->next;
		p->next = NULL;
		printf("��ӳɹ�����\n");
	}
	p->next = NULL; // p��nextָ��գ�����
	printf("\n�������!\n");
	getchar();
	getchar();
	system("cls");
	return; //������������
}
void shuchu(wo *head)
{
	system("cls");
	wo *p = (wo *)malloc(sizeof(wo));
	wo *p1 = (wo *)malloc(sizeof(wo));
}

void liulan(wo *head)
{
	system("cls");
	wo *p = (wo *)malloc(sizeof(wo));
	wo *p1 = (wo *)malloc(sizeof(wo));
	p = head;
	p1 = p->next;
	printf("ְԱ��Ϣ������\n");
	FILE *fp;
	fp = fopen("D:\\ְ������ϵͳ.txt", "r"); //�ļ���
	if (fp == NULL)
	{
		printf("�ļ����ܴ򿪣�\n");
	}
	p = head;
	p1 = (work *)malloc(sizeof(work));
	p->next = p1;
	p = p1;
	while (1)
	{ //��ʾ����ѭ��
		fscanf(fp, "ְ����:%d   ������%s    �Ա�%s    �������£�%d    ����״����%s    ��Ů������%d\n",
			   &p->jobNo, &p->Name, &p->sex, &p->birthday, &p->marital, &p->num);
		printf("ְ����: %d ", p1->jobNo);
		printf("����: %s ", p1->Name);
		printf("�Ա�: %s ", p1->sex);
		printf("��������: %s ", p1->birthday);
		printf("����״��: %s ", p1->marital);
		printf("��Ů����: %d ", p1->num);

		if (feof(fp))
		{ //�ļ��������ط�0�����򷵻�0
			p->next = NULL;
			break;
		}
		p1 = (work *)malloc(sizeof(work));
		p->next = p1;
		p = p1;
	}
	fclose(fp);
}
void chaxun(wo *head)
{
	wo *p = head;
	char n[20];
	int j, i;
	system("cls");
	printf("1.������״����ѯ\n2.����Ů������ѯ\n��������Ҫ��ѯ�ķ�ʽ:");
	scanf("%d", &i);
	switch (i)
	{ //ѡ���ѯ��ʽ
	case 1:
		printf("���������״����");
		scanf("%s", &n);
		while (p->next != NULL)
		{

			if (strcmp(p->next->marital, n) == 0)
			{
				printf("ְ���ţ�%d ", p->next->jobNo);
				printf("����: %s", p->next->Name);
				printf("�Ա�%s", p->next->sex);
				printf("�������£�%d", p->next->birthday);
				printf("����״����%s", p->next->marital);
				printf("��Ů������%d", p->next->num);
				return;
			}
			p = p->next;
			if (p->next == NULL)
			{ //ѭ�������p��next���Ҳδ�ҵ���������ݣ�������
				printf("�����ְ�������ڣ�\n");
				return;
			}
		}
		break;

	case 2:
		printf("��������Ҫ��ѯ����Ů������");
		scanf("%d", &j);
		while (p->next != NULL)
		{
			if (p->next->num == j)
			{
				printf("ְ���ţ�%d ", p->next->jobNo);
				printf("����: %s", p->next->Name);
				printf("�Ա�%s", p->next->sex);
				printf("���䣺%d", p->next->birthday);
				printf("����״����%s", p->next->marital);
				printf("��Ů������%d", p->next->num);
				return;
			}
			p = p->next;
			if (p->next == NULL)
			{
				printf("�����ְ�������ڣ�\n");
				return;
			}
		}
		break;
	}
}

void shanchu(wo *head)
{
	system("cls");
	wo *p1, *p2;
	p1 = head;
	p2 = p1->next;
	char name[100];
	printf("��������Ҫɾ����ְԱ������");
	scanf("%s", &name);
	while (p2 != NULL)
	{
		while (strcmp(name, p2->Name) == 0)
		{
			p1->next = p2->next;
			free(p2); // p2�ڵ��ͷ�
			printf("ɾ���ɹ���");
		}
		p1 = p2;
		p2 = p2->next;
		return;
	}
	if (p2 == NULL)
		printf("δ�����ְԱ����Ϣ�����������룡");
}

void xiugai(wo *head)
{
	system("cls");
	liulan(head); //������������������������Ϣ
	wo *p1, *p2, *q;
	char na[10];
	int n, i = 0, j, k, xh, t;
	p1 = p2 = head->next;
	printf("1.�޸�ְ����\n2.�޸�����\n3.�޸��Ա�\n4.ȫ���޸�\n�������޸ķ�ʽ:");
	scanf("%d", &j);
	switch (j)
	{
	case 1: //����ԭ����ְ���Ÿ���ְ����
		printf("��������Ҫ�޸ĵ�ְ����");
		scanf("%d", &xh);
		while (p1 != NULL)
		{
			if (p1->jobNo == xh)
			{
				i++;
				printf("�������޸ĺ��ְԱ��: ");
				scanf("%d", &p1->jobNo);
				while (p1->jobNo < 1)
				{
					printf("�����ְ���Ų����Ϲ涨������������!!\n");
					printf("����������ְ����:      ");
					scanf("%d", &p1->jobNo);
				}
				q = head;
				while (q->next != NULL)
				{
					q = q->next;
					if (q == p1)
						continue;
					while (p1->jobNo == q->jobNo)
					{
						printf("��ְ�����Ѵ��ڣ����������룡\n");
						scanf("%d", &p1->jobNo);
					}
				}
				printf("ְԱ��Ϣ�޸����!");
				break;
			}
			p1 = p1->next;
		}
		if (i == 0)
		{
			printf("��ְԱְ���Ų����ڣ�\n");
		}
		return;
	case 2: //����ְ�����޸�����
		printf("��������Ҫ�޸ĵ�ְ��������ְ����(�޸�����)");
		scanf("%d", &n);
		while (p1 != NULL)
		{
			if (p1->jobNo == n)
			{
				i++;
				printf("�������޸ĺ��ְԱ������");
				scanf("%s", &p1->Name);
				printf("ְԱ��Ϣ�޸���ɣ�");
				break;
			}
			p1 = p1->next;
		}
		if (i == 0)
		{
			printf("��ְԱ���������ڣ�\n");
		}
		return;
	case 3: //����ְ�����޸��Ա�
		printf("��������Ҫ�޸ĵ�ְ����");
		scanf("%d", &xh);
		while (p1 != NULL)
		{
			if (p1->jobNo == xh)
			{
				i++;
				printf("�������޸ĺ��ְԱ�Ա� ");
				scanf("%s", &p1->sex);
				while (strcmp(p1->sex, "W") != 0 && strcmp(p1->sex, "M") != 0)
				{
					printf("�����ְ���Ա𲻷��Ϲ涨������������!!\n");
					printf("����������ְ���Ա�:      ");
					scanf("%s", &p1->sex);
				}
				printf("ְԱ��Ϣ�޸���ɣ�");
				break;
			}
			p1 = p1->next;
		}
		if (i == 0)
		{
			printf("��ְԱְ���Ų����ڣ�\n");
		}
		return;
	case 4: //����ְ�����޸�ȫ����Ϣ
		printf("��������Ҫ�޸�ְԱ��ְ���ţ�");
		scanf("%d", &n);
		while (n < 1)
		{
			printf("�����ְ���Ų����Ϲ涨������������!!\n");
			printf("����������ְ����:      ");
			scanf("%d", &n);
		}
		while (p1 != NULL)
		{
			if (p1->jobNo == n)
			{
				i++;
				printf("����������: ");
				scanf("%s", &p1->Name);
				printf("�������Ա�(W/M)��");
				scanf("%s", &p1->sex);
				while (strcmp(p1->sex, "W") != 0 && strcmp(p1->sex, "M") != 0)
				{
					printf("�����ְ���Ա𲻷��Ϲ涨������������!!\n");
					printf("����������ְ���Ա�:      ");
					scanf("%s", &p1->sex);
				}
				printf("������������£�");
				scanf("%s", &p1->birthday);
				printf("���������״����");
				scanf("%s", &p1->marital);
				printf("��������Ů������");
				scanf("%d", &p1->num);
				printf("ְԱ��Ϣ�޸���ɣ�");
				break;
			}
			p1 = p1->next;
		}
		if (i == 0)
		{
			printf("��ְԱְ���Ų����ڣ�\n");
		}
		return;
	}
}

void tianjia(wo *head)
{
	system("cls");
	wo *p, *p1, *q;
	p = (work *)malloc(sizeof(work));
	p1 = (work *)malloc(sizeof(work));
	p = head;
	printf("�����������ְԱ����Ϣ��");
	printf("������ְ����: ");
	scanf("%d", &p1->jobNo);
	while (p1->jobNo < 1)
	{
		printf("�����ְ���Ų����Ϲ涨������������!!\n");
		printf("����������ְ����:      ");
		scanf("%d", &p1->jobNo);
	}
	q = head;
	while (q->next != NULL)
	{
		q = q->next;
		while (p1->jobNo == q->jobNo)
		{
			printf("��ְ�����Ѵ��ڣ����������룡\n");
			scanf("%d", &p1->jobNo);
		}
	}
	printf("����������: ");
	scanf("%s", &p1->Name);
	printf("�������Ա�(W/M)��");
	scanf("%s", &p1->sex);
	while (strcmp(p1->sex, "W") != 0 && strcmp(p1->sex, "M") != 0)
	{
		printf("�����ְ���Ա𲻷��Ϲ涨������������!!\n");
		printf("����������ְ���Ա�:      ");
		scanf("%s", &p1->sex);
	}
	printf("������������£�");
	scanf("%s", &p1->birthday);
	printf("��������Ů������");
	scanf("%d", &p1->num);
	printf("���������״����");
	scanf("%s", &p1->marital);

	p1->next = p->next;
	p->next = p1;
	p1 = p1->next; //ͷ�巨
	printf("��ӳɹ�!");
}

void baocun(wo *head)
{
	system("cls");
	FILE *fp;								 //����ָ�����fp
	fp = fopen("D:\\ְ������ϵͳ.txt", "w"); //�ļ���
	wo *p = head;
	p = p->next;
	while (p != NULL)
	{
		fprintf(fp, "ְ����:%d     ������%s      �Ա�%s      �������£�%s       ��Ů������%d     ����״����%s\n",
				p->jobNo, p->Name, p->sex, p->birthday, p->num, p->marital);
		p = p->next;
	}
	fclose(fp);
	printf("����ɹ���\n");
}

int main()
{
	void baocun(wo * head);	 //����
	void luru(wo * head);	 //¼��
	void liulan(wo * head);	 //���
	void chaxun(wo * head);	 //��ѯ
	void shanchu(wo * head); //ɾ��
	void xiugai(wo * head);	 //�޸�
	void tianjia(wo * head); //���

	system("color b4");
	struct work wo[100];
	int s;
	work *head = (work *)malloc(sizeof(work));
	head->next = NULL;
	system("cls");
	while (1)
	{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("    \t\t***********ְ������ϵͳ*********\n");
		printf("    \t\t********************************\n");
		printf("    \t\t*         1.¼��ְ����Ϣ       *\n");
		printf("    \t\t*         2.���ְ����Ϣ       *\n");
		printf("    \t\t*         3.��ѯְ����Ϣ       *\n");
		printf("    \t\t*         4.ɾ��ְ����Ϣ       *\n");
		printf("    \t\t*         5.�޸�ְ����Ϣ       *\n");
		printf("    \t\t*         6.����ְ����Ϣ       *\n");
		printf("    \t\t*         7.�˳�ְ��ϵͳ       *\n");
		printf("    \t\t*         8.����ְ����Ϣ       *\n");
		printf("    \t\t********************************\n");
		printf("    \t\t***�˳�ϵͳ���ѯ�������Ϣ�������*******\n");
		printf("������ѡ��Ĺ���:");
		scanf("%d", &s);
		switch (s)
		{
		case 1: //¼��ְԱ��Ϣ
			luru(head);
			system("pause");
			system("cls");
			break;
		case 2: //�����Ա��Ϣ
			liulan(head);
			system("pause");
			system("cls");
			break;
		case 3: //��ѯְԱ��Ϣ
			chaxun(head);
			system("pause");
			system("cls");
			break;
		case 4: //��������ɾ��
			shanchu(head);
			system("pause");
			system("cls");
			break;
		case 5: //�޸���Ϣ
			xiugai(head);
			system("pause");
			system("cls");
			break;
		case 6: //���ְԱ��Ϣ
			tianjia(head);
			system("pause");
			system("cls");
			break;

		case 7: //�˳�
			exit(0);
			break;
		case 8: //��Ϣ����
			baocun(head);
			system("pause");
			system("cls");
			break;
		default: //������Ĵ���취
			printf("������������������!!!");
			system("pause");
			system("cls");
			break;
		}
	}
}
