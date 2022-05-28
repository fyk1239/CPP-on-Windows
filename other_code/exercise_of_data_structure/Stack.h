#define MAX 20 
#define OK 1 
#define ERROR 0 
#define TRUE 1 
#define FALSE 0
typedef int Status ; 
typedef int SElemtype ; 
typedef struct 
{
	SElemtype data[MAX] ;  
	int top ;
}SqStack; //����˳��ջ  

typedef struct 
{
	SElemtype data[MAX] ;
	int top1 ; //ջ1ջ��ָ�� 
	int top2 ; //ջ2ջ��ָ�� 
}SqDoubleStack; //���干�ÿռ�˳��ջ 

typedef struct StackNode
{
	SElemtype data ;
	struct StackNode *next ;
}StackNode , LinkStackptr ;//������ջ��� 

typedef struct LinkStack
{
	LinkStackptr top ;
	int count ;
}LinkStack ; //������ջ 

Status SqPush(SqStack *S , SElemtype e)
{
	if ( S->top == MAX - 1 )
		return ERROR ;
	S->top ++ ;
	S->data[S->top] = e ; 
	return OK ;
}//˳��ջ��ջ 

Status SqPop(SqStack *S , SElemtype *e)
{
	if ( S->top == - 1 )
		return ERROR ;
	e = S->data[S->top] ; 
	S->top -- ;
	return OK ;
}//˳��ջ��ջ 

Status Push(LinkStack *S , SElemtype e)
{
	LinkStackptr s = (LinkStackptr)malloc(sizeof(StackNode)) ;
	s->data = e ; 
	s->next = S->top ; 
	S->top = s ;
	S->count ++ ;
	return OK ;
}//��ջ��ջ 

Status Pop(LinkStack *S , SElemtype *e)
{
	if ( S->top == - 1 )
		return ERROR ;
	e = S->data[S->top] ; 
	S->top -- ;
	return OK ;
}//��ջ��ջ

Status SqStackEmpty(SqStack S)
{
	if ( S->top == -1 )
		return TRUE ;
	return FALSE ;
}//˳��ջ�п� 

Status LinkStackEmpty(LinkStack S)
{
	if ( count == -1 )
		return TRUE ;
	return FALSE ;
}//��ջ�п� 
