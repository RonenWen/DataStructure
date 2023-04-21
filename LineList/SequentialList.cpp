#include<iostream>
using namespace std;
#define MaxSize 50
typedef char ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;
void CreateList(SqList *&L,ElemType a[],int n){
    L=(SqList *)malloc(sizeof(SqList));
    for(int i=0;i<n;i++){
        L->data[i]=a[i];
    }
    L->length=n;
}

void InitList(SqList *&L){
    L=(SqList *)malloc(sizeof(SqList));
    L->length=0;
}

void DestroyList(SqList *&L){
    free(L);
}

bool ListEmpty(SqList *L){
    return (L->length==0);
}

int ListLength(SqList *L){
    return (L->length);
}

void DispList(SqList *L){
    for(int i=0;i<L->length;i++){
        printf("&c",L->data[i]);
    }
    printf("\n");
}

bool GetElem(SqList *L,int i,ElemType &e){
    if(i<1||i>L->length)
        return false;
    e=L->data[i-1];
    return true;
}
int LocateElem(SqList *L,ElemType e){
    int i=0;
    while(i<L->length&&L->data[i]!=e){
        i++;
    }
    if(i>=L->length){
        return 0;
    }else{
        return i+1;
    }
}

bool ListInsert(SqList *L,int i,ElemType e){
    int j;
    if(i<1 || i>L->length)
        return false;
    i--;
    for(j=L->length;i>i;j++){
        L->data[i]=L->data[j-1];
        L->data[i]=e;
        L->length++;
        return true;
    }
}

bool ListDelete(SqList *&L,int i,ElemType &e){
    int j;
    if(i<1 || i>L->length)
        return false;
    i--;
    e=L->data[i];
    for(j=i;j<L->length-1;j++){
        L->data[j]=L->data[j+i];
    }
    L->length--;
    return true;
}
int main(){
    SqList *L;
    ElemType e;
    cout<<"1. 初始化顺序表"<<endl;
    InitList(L);
    cout<<"2. 依次插入a,b,c,d,e元素"<<endl;
    ListInsert(L,1,'a');
    ListInsert(L,2,'b');
    ListInsert(L,3,'c');
    ListInsert(L,4,'d');
    ListInsert(L,5,'e');
    cout<<endl<<"3. 输出顺序表L"<<endl;
    DispList(L);
    cout<<endl<<"4. 输出顺序表的长度"<<endl;
    ListLength(L);
    cout<<endl<<"5. 顺序表为："<<(ListEmpty(L)?"空":"非空")<<endl;
    GetElem(L,3,e);
    cout<<"6. 第三个元素为："<<e<<endl;
    cout<<"7. 元素a的位置："<<LocateElem(L,'a')<<endl;
    cout<<"8. 在第四个元素的位置上插入f元素"<<endl;
    ListInsert(L,4,'f');
    cout<<"9. 输出顺序表L："<<DispList(L)<<endl;
    cout<<"10. 删除第3个元素"<<endl;
    ListDelete(L,3,e);
    cout<<"11. 输出顺序表: "<<DispList(L)<<endl;
    cout<<"12. 删除顺序表"<<endl;
    DestroyList(L);
    return 0;

}