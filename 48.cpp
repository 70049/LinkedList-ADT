#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class LinkedlistADT
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *start;
    node *search(int data)
    {
        node *t;
        if(start==NULL)
            return (NULL);
        t=start;
        while(t!=NULL){
            if(t->item==data)
                return(t);
            t=t->next;
        }
        return(NULL);
    }
public:
    LinkedlistADT(){
        start=NULL;
    }
    int countitem();
    void InsertatStart(int data);
    void InsertatLast(int data);
    void Insertafter(int Currentdata,int data);
    int Searchitem(int data);
    int Deletefromstart();
    int Deletefromlast();
    int DeleteCurrentitem(int Currentdata);
    void Sortlist();
    void Edititem(int Currentdata,int newdata);
    void Viewlist();
    int getFirstitem();
    int getlastitem();
    ~LinkedlistADT()
    {
        while(start!=NULL){
            Deletefromstart();
        }
    }
};

void LinkedlistADT::InsertatStart(int data)
{
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
void LinkedlistADT::InsertatLast(int data)
{
    node *t,*n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else{
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
void LinkedlistADT::Insertafter(int Currentdata,int data)
{
    node *t=search(Currentdata);
    if(t==NULL)
        cout<<"\nNo such Value Exist:";
    else{
        node *n=new node;
        n->item=data;
        n->next=t->next;
        t->next=n;
    }
}
int LinkedlistADT::Deletefromstart()
{
    if(start==NULL){
        cout<<"\nOverFlow";
        return (0);}
    node *r;
    r=start;
    start=start->next;
    delete(r);
    return(1);
}
void LinkedlistADT::Edititem(int Currentdata,int newdata)
{
    node *t=search(Currentdata);
    if(t==NULL)
        cout<<"\nItem not found:";
    else
        t->item=newdata;
}
int LinkedlistADT::Deletefromlast()
{
    if(start==NULL){
        cout<<"\nUnderFLow";
        return(0);
    }
    else if(start->next==NULL){
        delete(start);
        start=NULL;
        return(1);
    }
    node *t1,*t2;
    t1=t2=start;
    do{
        t2=t1;
        t1=t1->next;
    }while(t1->next!=NULL);
    t2->next=NULL;
    delete(t1);
    return(1);
}
int LinkedlistADT::DeleteCurrentitem(int Currentdata)
{
    node *t=search(Currentdata);
    if(NULL==t){
        cout<<"\nItem Not Found";
        return(0);
    }
    else if(t->next==NULL){
        Deletefromlast();
        return(1);
    }
    while(t->next!=NULL){
        t->item=t->next->item;
        t=t->next;
    }
    Deletefromlast();
    return(1);
}
int LinkedlistADT::countitem()
{
    int count=0;
    node *t;
    t=start;
    while(t!=NULL){
        count++;
        t=t->next;
    }
    return(count);
}
int LinkedlistADT::getFirstitem()
{
    if(start==NULL)
    {
        cout<<"\nList is empty";
        return(-1);
    }
    return(start->item);
}
int LinkedlistADT::getlastitem()
{
    node *t;
    if(start==NULL){
        cout<<"\nList Is Empty";
        return(-1);
    }
    t=start;
    while(t->next!=NULL)
        t=t->next;
    return(t->item);
}
void LinkedlistADT::Viewlist()
{
    node *t;
    t=start;
    if(start==NULL)
        cout<<"\nList Is Empty:";
    else{
        while(t!=NULL){
            cout<<" "<<t->item;
            t=t->next;
        }
    }
}
int LinkedlistADT::Searchitem(int data)
{
    node *t;
    t=start;
    while(t!=NULL){
        if(t->item==data)
            return(1);
        t=t->next;
    }
    return(0);
}
void LinkedlistADT::Sortlist()
{
    node *t;
    int r,i,x,n;
    n=countitem();
    for(r=1;r<=n-1;r++){
        t=start;
        for(i=0;i<=n-1-r;i++){
            if(t->item>t->next->item){
                x=t->item;
                t->item=t->next->item;
                t->next->item=x;
            }
            t=t->next;
        }
    }
}

int main()
{
    LinkedlistADT a1;
    a1.InsertatStart(10);
    a1.InsertatStart(20);
    a1.InsertatStart(30);
    a1.InsertatStart(40);
    a1.InsertatLast(50);
    a1.Insertafter(20,5);
    a1.Viewlist();
    cout<<"\n";
    a1.Viewlist();
    getch();
}
