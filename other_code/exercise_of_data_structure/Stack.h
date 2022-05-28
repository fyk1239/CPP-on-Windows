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
}SqStack; //∂®“ÂÀ≥–Ú’ª  

typedef struct 
{
	SElemtype data[MAX] ;
	int top1 ; //’ª1’ª∂•÷∏’Î 
	int top2 ; //’ª2’ª∂•÷∏’Î 
}SqDoubleStack; //∂®“Âπ≤”√ø’º‰À≥–Ú’ª 

typedef struct StackNode
{
	SElemtype data ;
	struct StackNode *next ;
}StackNode , LinkStackptr ;//∂®“Â¡¥’ªΩ·µ„ 

typedef struct LinkStack
{
	LinkStackptr top ;
	int count ;
}LinkStack ; //∂®“Â¡¥’ª 

Status SqPush(SqStack *S , SElemtype e)
{
	if ( S->top == MAX - 1 )
		return ERROR ;
	S->top ++ ;
	S->data[S->top] = e ; 
	return OK ;
}//À≥–Ú’ª»Î’ª 

Status SqPop(SqStack *S , SElemtype *e)
{
	if ( S->top == - 1 )
		return ERROR ;
	e = S->data[S->top] ; 
	S->top -- ;
	return OK ;
}//À≥–Ú’ª≥ˆ’ª 

Status Push(LinkStack *S , SElemtype e)
{
	LinkStackptr s = (LinkStackptr)malloc(sizeof(StackNode)) ;
	s->data = e ; 
	s->next = S->top ; 
	S->top = s ;
	S->count ++ ;
	return OK ;
}//¡¥’ª»Î’ª 

Status Pop(LinkStack *S , SElemtype *e)
{
	if ( S->top == - 1 )
		return ERROR ;
	e = S->data[S->top] ; 
	S->top -- ;
	return OK ;
}//¡¥’ª≥ˆ’ª

Status SqStackEmpty(SqStack S)
{
	if ( S->top == -1 )
		return TRUE ;
	return FALSE ;
}//À≥–Ú’ª≈–ø’ 

Status LinkStackEmpty(LinkStack S)
{
	if ( count == -1 )
		return TRUE ;
	return FALSE ;
}//¡¥’ª≈–ø’ 
