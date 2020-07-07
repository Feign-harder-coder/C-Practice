//链表基本操作们
#include <stdio.h> 
//前230行是有关单链表的操作
//230-行是有关双向链表的操作
//


//定义单链表
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;



//链表初始化
//带头节点的初始化、判空语句为：L->Next = NULL;
//不带头节点的初始化、判空语句为：L= NULL;



//建立单链表
    //尾插法——顺序的，常用作建立链表
    LinkList List_TailInsert(LinkList &L){
        int x;
        L = (LNode *)malloc(sizeof(LNode));
        LNode *s,*r = L;
        scanf("%d",&x);
        while(x!=9999){                                                //意为：当x=9999时表示程序退出，这是个自己定义的一个特殊数字。
            s = (LNode *)malloc(sizeof(LNode));
            s->data =x;
            r->next = s;
            r = s;            
            scanf("%d",&x);
        }
        r->next = NULL;                        //最后一个数据的next部分置为NULL；
        return L;
    }



    //头插法——逆序的，常用作链表逆置，很重要
    LinkList List_HeadInsert(LinkList &L){
        LNode *s=L;
        int x;
        scanf("%d",&x);
        while(x!=9999){
            s = (LNode *)malloc(sizeof(LNode));
            s->data = x;
            s->next = L->next;
            L->next = s;
            scanf("%d",&x);
        }
        return L;
    }



//单链表查找（带头节点）
    //按位查找O(n)
    LNode *GetElemByI(LinkList L,int i){
    if(i<0){
        return NULL;
    }    
    LNode *p;
    int j = 0;
    p=L;
    while(p!=NULL&&j<i){
        j++;
        p = p->next;
    }
    return p;
    }



    //按值查找O(n)
    LNode *GetElemByNum(LinkList L,int e){
        LNode *p;
        p=L->next;
        int j = 0;
        while(p!=NULL&&p->data!=e){
            p=p->next;
        }
        return p;
    }
    
    
    
    //单链表求表长O(n)
    int Length(LinkList L){
        int len = 0;
        LNode p = L;
        while(p!=NULL){
            p=p->next;
            len++;
        }
        return len;
    }



//单链表插入节点
    //1.With-Head-InsertO(n)
bool With-Head-Insert(LinkList &L,int i,int e){
    if(i<1){
        return false;
    }
    LNode *p;
    int j = 0;
    p=L;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p == NULL){                        //i值不合法的情况
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}



    //2.Without-Head-InsertO(n)
        //缺点：需单独判断向第一个元素之前插入数据的情况，若要向第一个数据之前插入或者删除，则需要修改头指针。
bool Without-Head-Insert(LinkList &L,int i,int e){
    if(i<1){
        return false;
    }
    if(i == 1){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->next = L;
        s->data = e;
        L=s;                        //头指针指向新的节点
    }
    LNode *p;
    int j = 0;
    p=L;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p == NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}



    //指定节点后插O(1)
bool Back_Insert(LNode *p,int e){
    if(p == NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next = s;
    return true;
}



    //指定节点前插O(1)
        //基本思路：首先进行后插，然后交换两个L->data的值
bool Front_Insert(LNode *p,int e){
    if(p == NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next=p->next;
    p->next = s;
    int t = p->data;
    p->data = s->data;
    s->data = t;
    return true;
}



    //单链表删除节点（带头节点）
        //按位序删除O(n)
bool Delete_by_i(ListLink *L,int i,int &e){
    if(i<1){
        return false;
    }
    int j=0;
    LNode *p;                                                    //我此时只需要一个指针，故不用通过下面语句申请存储空间    LNode *p = (LNode *)malloc(sizeof(LNode));
    p=L;
    while(p != NULL&&j<i-1){
        j++;
        p=p->next;
    }
    if(p == NULL){
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(p)                    //千万不要忘了这个操作
    return true;
}



    //按节点删除O(1)
bool Delete_By_Node(LNode *p){                    //此处用了和前插同样的思想，即交换数据
    if(p == NULL){
        return false;
    }
    LNode *q = p->next;
    p->data=q->data
    p->next = q->next;
    free(p);
    return true;
}




//双链表
typedef struct DNode{
    int data;
    struct DNode *prior,*next;
}DNode, *DLinkList;















