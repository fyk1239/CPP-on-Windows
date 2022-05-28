#define MAX 20 
#define OK 1 
#define ERROR 0 
#define TRUE 1 
#define FALSE 0
typedef int Status ; 
typedef int Elemtype ;

typedef struct
{
	Elemtype data[MAX] ;
	int length ;
}List ;

Status GetElem(List *L , Elemtype i , int *e)
{
	if (L->length == 0 || i < 1 || i > L->length)
		return ERROR ;
	*e = L->data[i - 1] ; 
	return OK ;
}

Status ListInsert (List *L , int i , Elemtype e)
{
	int k ;
	if ( L->length == MAX ) 
		return ERROR ;
	if ( i < 1 || i > L->length + 1 )
		return ERROR ;
	if ( i <= L->length )
	{
		for ( k = L->length - 1 ; k >= i - 1 ; k -- )
			L->data[k + 1] = L->data[k] ;
	}
	L->data[i - 1] = e ; 
	L->length ++ ; 
	return OK ;
}

Status ListDelete(List *L , Elemtype i , Elemtype *e ) 
{
	if (L->length == 0 )
		return ERROR ;
	
	if ( i < 0 || i >= L->length )
		return ERROR ;
	*e = L->data[i - 1] ; 
	for ( int k = i ; k < L->length - 1 ; k ++ )
		L->data[k - 1] = L->data[k] ; 
	L->length -- ; 
	return OK ; 
}

Status ListDelete1(List *L , Elemtype s , Elemtype t ) 
{
	if (L->length == 0 )
		return ERROR ;	
	for ( int i = 0 ; i < L->length ; i ++ )
	{
		if( L->data[i] > s && L->data[i] < t )
		{
			for ( int k = i ; k < L->length - 1 ; k ++ )
				L->data[k - 1] = L->data[k] ; 
			L->length -- ; 
		}
	}
	return OK ; 
}
