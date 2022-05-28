using namespace std;
typedef int Elemtype;
//#include"LinkList1.h"
#include"LinkList.h"

void Linklist_jiao(Linklist *La, Linklist *Lb, Linklist *Lc)
//求M，L两个集合的交集
 {
    Linklist pa,pb,pc;
    pa=(*La)->next;
	
    pc = *Lc;
    cout<<"1"<<endl;
    while(pa)
    {
        cout<<"aaaa"<<endl;
        pb=(*Lb)->next;
        while(pb)
        {
            cout<<"bbbb"<<endl;
            if(pa->data==pb->data)
            {
                cout<<"bingo"<<endl;
                Linklist p = (Linklist)malloc(sizeof(Node));
                p->data=pa->data;
                p->next=pc->next;
                pc->next=p;
				pc = p;
				
                //cout << pc->data << endl;
                //pc->next=actual;
                
            }
            pb=pb->next;
    	}
        pa=pa->next;
    }
    return ;
}

int main()
{
    Linklist ha,hb,hc;
    Elemtype a[]={1,2,3,4,6};
    Elemtype b[]={5,4,3,2,1};
    CreateList_L_Rear(&ha,a,5);
    CreateList_L_Rear(&hb,b,5);
    ListTraverse_L(ha);
    ListTraverse_L(hb);
    Linklist_jiao(&ha,&hb,&hc);
    ListTraverse_L(hc);

    cout << "罗慧婷" << endl;
    return 0;
}
