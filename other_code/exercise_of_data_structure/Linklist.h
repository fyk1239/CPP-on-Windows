#include<iostream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
#define MAX 20 
#define OK 1 
#define ERROR 0 
#define TRUE 1 
#define FALSE 0
typedef int Status ; 
typedef int Elemtype ; 
using namespace std ;
typedef struct Node
{
	Elemtype data ; 
	struct Node *next ;
} Node ;
typedef struct Node *Linklist ; 

Status GetElem(Linklist L , int i , Elemtype *e ) 
{
	int j = 1 ; 
	Linklist p ; 
	p = L->next ; 
	while (p && j < 1)
	{
		p = p->next ; 
		j ++ ;
	}
	if ( !p || j > i )
		return ERROR ; 
	*e = p->data ;
	return OK ;
}

Status ListInsert(Linklist *L , int i , Elemtype e)
{
	int j = 1 ; 
	Linklist p = *L , s ; 
	while(p && j < 1)
	{
		p = p->next ; 
		j ++ ;  
	}
	if ( !p || j > 1 ) 
		return ERROR ;
	s = (Linklist)malloc(sizeof(Node)) ;
	s->data = e ; 
	s->next = p->next ; 
	p->next = s ; 
	return OK ;
}
Status ListDelete(Linklist *L , int i , Elemtype *e)
{
	int j = 1 ; 
	Linklist p = *L , s ; 
	while(p && j < 1)
	{
		p = p->next ; 
		j ++ ;  
	}
	if ( !p || j > 1 ) 
		return ERROR ;
	s = p->next ; 
	p->next = s->next ; 
	free(s) ;
	return OK ;
}

void CreateListHead(Linklist *L , int n)
{
	Linklist p ; 
	int i ; 
	srand(time(0)) ;
	*L = (Linklist)malloc(sizeof(Node)) ; 
	(*L)->next = NULL ;
	for ( i = 0 ; i < n ; i ++ )
	{
		p = (Linklist)malloc(sizeof(Node)) ; 
		p->data = rand() % 100 + 1 ; 
		p->next = (*L)->next ; 
		(*L)->next = p ; 
	}
}

void CreateListTail(Linklist *L , int n)
{
	Linklist p , r ; 
	int i ; 
	srand(time(0)) ;
	*L = (Linklist)malloc(sizeof(Node)) ; 
	r = *L ; 
	for ( i = 0 ; i < n ; i ++ )
	{
		p = (Linklist)malloc(sizeof(Node)) ; 
		p->data = rand() % 100 + 1 ; 
		r->next = p ; 
		r = p ; 
	}
	r->next = NULL ; 
}

Status ClearList(Linklist *L)
{
	Linklist p , q ; 
	p = (*L)->next ;
	while(p)
	{
		q = p->next ; 
		free(p) ; 
		p = q ; 
	}
	(*L)->next = NULL ; 
	return OK ;
}

Status LinkDelete2(Linklist *L , Elemtype e)
{
	Linklist p = *L , tmp ; 
	if (!(p->next))
		return ERROR ;
	while (p->next)
	{
		if (p->next->data == e)
		{
			tmp = p->next ; 
			p->next = p->next->next ; 
			free(tmp) ;
		}
	}
	return OK ;
}

void CreateList_L_Rear(Linklist *L , Elemtype a[] , int n ) 
	{   // ��֪һά����A[n]�д������Ա������Ԫ�أ�����β�巨����������L
   		Linklist p , q ;   
		int i ;
	  	*L = (Linklist)malloc(sizeof(Node)) ;    // ������ͷ���
		q = *L ;                                // qʼ��ָ��β��㣬��ʼʱβ���Ҳ��ͷ���
		for( i = 0 ; i < n ; i ++ ) 
    	{   p = (Linklist)malloc(sizeof(Node));          // �����½��
            p->data = a[i] ;                               // ��Ԫ��ֵ
            q->next = p ;                                  // ������β���֮��
            q = p ;                                         // qָ���µı�β
 	    }
   		q->next = NULL;                                    // ��β���next���ÿ�
     }
     
void ListTraverse_L(Linklist L)
{
	Linklist p = L->next ;
 	while(p)
  	{  
		cout << setw(6) << p->data ; 
        p = p->next ;
    }
	cout << endl;
	return ;
}// ListTraverse_L
