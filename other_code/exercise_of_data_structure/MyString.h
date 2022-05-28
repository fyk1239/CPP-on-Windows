// ADT String
#define MAX 200
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
    typedef int Status;

typedef struct String
{
    int str[MAX];
} String;

Status StrAssign(String S, *chars str);
Status StrCopy(String S, String Des);
Status ClearString(String S);
Status Strcompare(String S1, String S2);
Status StringEmpty(String S);
Status StrLength(String S);
Status Concat(String T, String S1, String S2);
Status SubString(String *Sub, String S, int pos, int len);
Status Replace(String S, String T, String V);
Status Index(String S, String);
Status StrInsert(String S, String T, int pos);
Status StrDelete(String S, int pos, int len);

Status Index(String S1, String S2, int pos)
{
    int i = pos ; 
    int j = 1 ; 
    while (i <= S[0] && j <= T[0])
    {
        if (S[i] == T[j])
        {
            i ++ ; 
            j ++ ; 
        }
        else
        {
            i = i - j + 2 ; 
            j = 1 ; 
        }
    }
    if (j > T[0])
    {
        return i - T[0] ; 
    }
    else
    {
        return ERROR ;
    }
    
    
}