#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct work //定义work结构体
{
	int jobNo;		  //工号
	char Name[20];	  //姓名
	char sex[10];	  //性别
	int birthday;	  //出生年月
	int num;		  //子女个数
	char marital[20]; //婚姻状况
	struct work *next;
} wo;

void luru(wo *head)
{
	system("cls"); //清屏！
	wo *p = head;
	wo *q; //设置p和p2为头指针
	int a;
	printf("请输入你想新增几个职员信息  :");
	scanf("%d", &a); //新增成员的数量
	int c = 0;
	for (int n = 0; n < a; n++)
	{

		wo *p1 = (wo *)malloc(sizeof(wo));
		c++;
		printf("请输入第%d个职员的信息\n", c);
		printf("请输入职工号:      ");
		scanf("%d", &p1->jobNo);
		while (p1->jobNo < 1)
		{
			printf("输入的职工号不符合规定，请重新输入!!\n");
			printf("请重新输入职工号:      ");
			scanf("%d", &p1->jobNo);
		}
		q = head;
		while (q->next != NULL)
		{
			q = q->next;
			while (p1->jobNo == q->jobNo)
			{
				printf("该职工号已存在，请重新输入！\n");
				scanf("%d", &p1->jobNo);
			}
		}
		printf("请输入姓名:        ");
		scanf("%s", &p1->Name);
		printf("请输入性别(W/M)：  ");
		scanf("%s", &p1->sex);
		while (strcmp(p1->sex, "W") != 0 && strcmp(p1->sex, "M") != 0)
		{
			printf("输入的职工性别不符合规定，请重新输入!!\n");
			printf("请重新输入职工性别:      ");
			scanf("%s", &p1->sex);
		}
		printf("请输入出生年月:");
		scanf("%d", &p1->birthday);
		printf("请输入婚姻状况");
		scanf("%s", &p1->marital);

		printf("请输入子女个数");
		scanf("%d", &p1->num);

		q = head;

		p->next = p1;
		p = p->next;
		p->next = NULL;
		printf("添加成功！！\n");
	}
	p->next = NULL; // p的next指向空，结束
	printf("\n创建完毕!\n");
	getchar();
	getchar();
	system("cls");
	return; //返回主函数！
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
	printf("职员信息总览：\n");
	FILE *fp;
	fp = fopen("D:\\职工管理系统.txt", "r"); //文件名
	if (fp == NULL)
	{
		printf("文件不能打开！\n");
	}
	p = head;
	p1 = (work *)malloc(sizeof(work));
	p->next = p1;
	p = p1;
	while (1)
	{ //表示无限循环
		fscanf(fp, "职工号:%d   姓名：%s    性别：%s    出生年月：%d    婚姻状况：%s    子女个数：%d\n",
			   &p->jobNo, &p->Name, &p->sex, &p->birthday, &p->marital, &p->num);
		printf("职工号: %d ", p1->jobNo);
		printf("姓名: %s ", p1->Name);
		printf("性别: %s ", p1->sex);
		printf("出生年月: %s ", p1->birthday);
		printf("婚姻状况: %s ", p1->marital);
		printf("子女个数: %d ", p1->num);

		if (feof(fp))
		{ //文件结束返回非0，否则返回0
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
	printf("1.按婚姻状况查询\n2.按子女个数查询\n请输入想要查询的方式:");
	scanf("%d", &i);
	switch (i)
	{ //选择查询方式
	case 1:
		printf("请输入婚姻状况：");
		scanf("%s", &n);
		while (p->next != NULL)
		{

			if (strcmp(p->next->marital, n) == 0)
			{
				printf("职工号：%d ", p->next->jobNo);
				printf("姓名: %s", p->next->Name);
				printf("性别：%s", p->next->sex);
				printf("出生年月：%d", p->next->birthday);
				printf("婚姻状况：%s", p->next->marital);
				printf("子女个数：%d", p->next->num);
				return;
			}
			p = p->next;
			if (p->next == NULL)
			{ //循环，如果p的next最后也未找到输入的数据，输入结果
				printf("输入的职工不存在！\n");
				return;
			}
		}
		break;

	case 2:
		printf("请输入想要查询的子女个数：");
		scanf("%d", &j);
		while (p->next != NULL)
		{
			if (p->next->num == j)
			{
				printf("职工号：%d ", p->next->jobNo);
				printf("姓名: %s", p->next->Name);
				printf("性别：%s", p->next->sex);
				printf("年龄：%d", p->next->birthday);
				printf("婚姻状况：%s", p->next->marital);
				printf("子女个数：%d", p->next->num);
				return;
			}
			p = p->next;
			if (p->next == NULL)
			{
				printf("输入的职工不存在！\n");
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
	printf("请输入想要删除的职员姓名：");
	scanf("%s", &name);
	while (p2 != NULL)
	{
		while (strcmp(name, p2->Name) == 0)
		{
			p1->next = p2->next;
			free(p2); // p2节点释放
			printf("删除成功！");
		}
		p1 = p2;
		p2 = p2->next;
		return;
	}
	if (p2 == NULL)
		printf("未存入该职员的信息，请重新输入！");
}

void xiugai(wo *head)
{
	system("cls");
	liulan(head); //调用浏览函数，先输出所有信息
	wo *p1, *p2, *q;
	char na[10];
	int n, i = 0, j, k, xh, t;
	p1 = p2 = head->next;
	printf("1.修改职工号\n2.修改姓名\n3.修改性别\n4.全部修改\n请输入修改方式:");
	scanf("%d", &j);
	switch (j)
	{
	case 1: //根据原来的职工号更改职工号
		printf("请输入需要修改的职工号");
		scanf("%d", &xh);
		while (p1 != NULL)
		{
			if (p1->jobNo == xh)
			{
				i++;
				printf("请输入修改后的职员号: ");
				scanf("%d", &p1->jobNo);
				while (p1->jobNo < 1)
				{
					printf("输入的职工号不符合规定，请重新输入!!\n");
					printf("请重新输入职工号:      ");
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
						printf("该职工号已存在，请重新输入！\n");
						scanf("%d", &p1->jobNo);
					}
				}
				printf("职员信息修改完成!");
				break;
			}
			p1 = p1->next;
		}
		if (i == 0)
		{
			printf("该职员职工号不存在！\n");
		}
		return;
	case 2: //根据职工号修改姓名
		printf("请输入想要修改的职工姓名的职工号(修改姓名)");
		scanf("%d", &n);
		while (p1 != NULL)
		{
			if (p1->jobNo == n)
			{
				i++;
				printf("请输入修改后的职员姓名：");
				scanf("%s", &p1->Name);
				printf("职员信息修改完成！");
				break;
			}
			p1 = p1->next;
		}
		if (i == 0)
		{
			printf("该职员姓名不存在！\n");
		}
		return;
	case 3: //根据职工号修改性别
		printf("请输入想要修改的职工号");
		scanf("%d", &xh);
		while (p1 != NULL)
		{
			if (p1->jobNo == xh)
			{
				i++;
				printf("请输入修改后的职员性别： ");
				scanf("%s", &p1->sex);
				while (strcmp(p1->sex, "W") != 0 && strcmp(p1->sex, "M") != 0)
				{
					printf("输入的职工性别不符合规定，请重新输入!!\n");
					printf("请重新输入职工性别:      ");
					scanf("%s", &p1->sex);
				}
				printf("职员信息修改完成！");
				break;
			}
			p1 = p1->next;
		}
		if (i == 0)
		{
			printf("该职员职工号不存在！\n");
		}
		return;
	case 4: //根据职工号修改全部信息
		printf("请输入想要修改职员的职工号：");
		scanf("%d", &n);
		while (n < 1)
		{
			printf("输入的职工号不符合规定，请重新输入!!\n");
			printf("请重新输入职工号:      ");
			scanf("%d", &n);
		}
		while (p1 != NULL)
		{
			if (p1->jobNo == n)
			{
				i++;
				printf("请输入姓名: ");
				scanf("%s", &p1->Name);
				printf("请输入性别(W/M)：");
				scanf("%s", &p1->sex);
				while (strcmp(p1->sex, "W") != 0 && strcmp(p1->sex, "M") != 0)
				{
					printf("输入的职工性别不符合规定，请重新输入!!\n");
					printf("请重新输入职工性别:      ");
					scanf("%s", &p1->sex);
				}
				printf("请输入出生年月：");
				scanf("%s", &p1->birthday);
				printf("请输入婚姻状况：");
				scanf("%s", &p1->marital);
				printf("请输入子女个数：");
				scanf("%d", &p1->num);
				printf("职员信息修改完成！");
				break;
			}
			p1 = p1->next;
		}
		if (i == 0)
		{
			printf("该职员职工号不存在！\n");
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
	printf("请输入新添加职员的信息！");
	printf("请输入职工号: ");
	scanf("%d", &p1->jobNo);
	while (p1->jobNo < 1)
	{
		printf("输入的职工号不符合规定，请重新输入!!\n");
		printf("请重新输入职工号:      ");
		scanf("%d", &p1->jobNo);
	}
	q = head;
	while (q->next != NULL)
	{
		q = q->next;
		while (p1->jobNo == q->jobNo)
		{
			printf("该职工号已存在，请重新输入！\n");
			scanf("%d", &p1->jobNo);
		}
	}
	printf("请输入姓名: ");
	scanf("%s", &p1->Name);
	printf("请输入性别(W/M)：");
	scanf("%s", &p1->sex);
	while (strcmp(p1->sex, "W") != 0 && strcmp(p1->sex, "M") != 0)
	{
		printf("输入的职工性别不符合规定，请重新输入!!\n");
		printf("请重新输入职工性别:      ");
		scanf("%s", &p1->sex);
	}
	printf("请输入出生年月：");
	scanf("%s", &p1->birthday);
	printf("请输入子女个数：");
	scanf("%d", &p1->num);
	printf("请输入婚姻状况：");
	scanf("%s", &p1->marital);

	p1->next = p->next;
	p->next = p1;
	p1 = p1->next; //头插法
	printf("添加成功!");
}

void baocun(wo *head)
{
	system("cls");
	FILE *fp;								 //定义指针变量fp
	fp = fopen("D:\\职工管理系统.txt", "w"); //文件名
	wo *p = head;
	p = p->next;
	while (p != NULL)
	{
		fprintf(fp, "职工号:%d     姓名：%s      性别：%s      出生年月：%s       子女个数：%d     婚姻状况：%s\n",
				p->jobNo, p->Name, p->sex, p->birthday, p->num, p->marital);
		p = p->next;
	}
	fclose(fp);
	printf("保存成功！\n");
}

int main()
{
	void baocun(wo * head);	 //保存
	void luru(wo * head);	 //录入
	void liulan(wo * head);	 //浏览
	void chaxun(wo * head);	 //查询
	void shanchu(wo * head); //删除
	void xiugai(wo * head);	 //修改
	void tianjia(wo * head); //添加

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
		printf("    \t\t***********职工管理系统*********\n");
		printf("    \t\t********************************\n");
		printf("    \t\t*         1.录入职工信息       *\n");
		printf("    \t\t*         2.浏览职工信息       *\n");
		printf("    \t\t*         3.查询职工信息       *\n");
		printf("    \t\t*         4.删除职工信息       *\n");
		printf("    \t\t*         5.修改职工信息       *\n");
		printf("    \t\t*         6.新增职工信息       *\n");
		printf("    \t\t*         7.退出职工系统       *\n");
		printf("    \t\t*         8.保存职工信息       *\n");
		printf("    \t\t********************************\n");
		printf("    \t\t***退出系统后查询保存的信息需先浏览*******\n");
		printf("请输入选择的功能:");
		scanf("%d", &s);
		switch (s)
		{
		case 1: //录入职员信息
			luru(head);
			system("pause");
			system("cls");
			break;
		case 2: //浏览成员信息
			liulan(head);
			system("pause");
			system("cls");
			break;
		case 3: //查询职员信息
			chaxun(head);
			system("pause");
			system("cls");
			break;
		case 4: //输入姓名删除
			shanchu(head);
			system("pause");
			system("cls");
			break;
		case 5: //修改信息
			xiugai(head);
			system("pause");
			system("cls");
			break;
		case 6: //添加职员信息
			tianjia(head);
			system("pause");
			system("cls");
			break;

		case 7: //退出
			exit(0);
			break;
		case 8: //信息保存
			baocun(head);
			system("pause");
			system("cls");
			break;
		default: //乱输入的处理办法
			printf("输入有误，请重新输入!!!");
			system("pause");
			system("cls");
			break;
		}
	}
}
