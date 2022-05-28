#define MAX 20 
#define OK 1 
#define ERROR 0 
#define TRUE 1 
#define FALSE 0
typedef int Status ; 
typedef int QElemtype ;
typedef struct
{
	QElemtype data[MAX] ;
	int front ; 
	int rear ; 
}SqQueue ;

Status InitQueue(SqQueue *Q)
{
	Q->front = 0 ;
	Q->rear = 0 ; 
	return OK ;
}

int QueueLength(SqQueue Q)
{
	return ( Q->rear - Q->front + MAX ) % MAX ;
}

Status EnQueue(SqQueue *Q , QElemtype e) //进队
{
	if((Q->rear) + 1 % MAX == Q->front)
		return ERROR ; 
	Q->data[Q->rear] = e ;
	Q->rear = (Q->rear + 1) % MAX; //rear指针后移，若到最后则转到数组头部。
	return OK ; 
}

Status DeQueue(SqQueue *Q , QElemtype *e) //出队
{
	if(Q->front == Q->rear)
		return ERROR ;
	*e = Q->front ;
	Q->front = (Q->front + 1) % MAX; //front指针后移，若到最后则转到数组头部。
	return OK ;
}

