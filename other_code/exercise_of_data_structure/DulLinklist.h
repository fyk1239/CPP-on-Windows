#include<ctime>
#include<cstdlib>
#define MAX 20 
#define OK 1 
#define ERROR 0 
#define TRUE 1 
#define FALSE 0
typedef int Status ; 
typedef int Elemtype ; 

typedef struct Node
{
	Elemtype data ; 
	struct Node *prior ;
	struct Node *next ;
} DulNode ;
typedef struct Node *DulLinklist ; 

Status GetElem(DulLinklist L , int i , Elemtype *e ) 
{
	int j = 1 ; 
	DulLinklist p ; 
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

Status ListInsert(DulLinklist *L , int i , Elemtype e)
{
	int j = 1 ; 
	DulLinklist p , s ; 
	p = *L ; 
	while(p && j < 1)
	{
		p = p->next ; 
		j ++ ;  
	}
	if ( !p || j > 1 ) 
		return ERROR ;
	s = (DulLinklist)malloc(sizeof(DulNode)) ;
	s->data = e ; 
	s->next = p->next ; 
	s->prior = p ;
	p->next->prior = s ; 
	p->next = s ;
	
	return OK ;
}
Status ListDelete(DulLinklist *L , int i , Elemtype *e)
{
	int j = 1 ; 
	DulLinklist p ; 
	p = *L ; 
	while(p && j < 1)
	{
		p = p->next ; 
		j ++ ;  
	}
	if ( !p || j > 1 ) 
		return ERROR ; 
	p->prior->next = p->next ; 
	p->next->prior = p->prior ;
	free(p) ;
	return OK ;
}

void CreateListHead(DulLinklist *L , int n)
{
	DulLinklist p ; 
	int i ; 
	srand(time(0)) ;
	*L = (DulLinklist)malloc(sizeof(DulNode)) ; 
	(*L)->next = NULL ;
	for ( i = 0 ; i < n ; i ++ )
	{
		p = (DulLinklist)malloc(sizeof(Node)) ; 
		p->data = rand() % 100 + 1 ; 
		p->next = (*L)->next ; 
		p->prior = (*L) ;
		(*L)->next = p ; 
	}
}

void CreateListTail(DulLinklist *L , int n)
{
	DulLinklist p , r ; 
	int i ; 
	srand(time(0)) ;
	*L = (DulLinklist)malloc(sizeof(Node)) ; 
	r = *L ; 
	for ( i = 0 ; i < n ; i ++ )
	{
		p = (DulLinklist)malloc(sizeof(Node)) ; 
		p->data = rand() % 100 + 1 ; 
		r->next = p ; 
		r = p ; 
	}
	r->next = NULL ; 
}

Status ClearList(DulLinklist *L)
{
	DulLinklist p , q ; 
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

int GetNumber(DulLinklist *L)
{
	int cnt ; 
	DulLinklist q = *L , p = *L ; 
	while ( p->next != q )
	{
		p = p->next ; 
		cnt ++ ; 
	}
	return cnt ;
}


