#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define nil NULL
typedef struct node *address;
struct node
{
    char *info;
    address column;
    address row;
};
typedef address list;
void createempty(list *L);
bool isempty(list L);
address alokasi(char nama[]);
void insertlist(list *L,char nama[]);
void insertsublist(list *L,char root[],char nama[]);
void printlist(list L);

int main(){
    list L;
    char nama[10];
    createempty(&L);
    insertlist(&L,"Aku");
    insertlist(&L,"Kowe");
    insertlist(&L,"Ndekne");
    insertsublist(&L,"Aku","Watsittoya");
    insertsublist(&L,"Kowe","Tempoles");
    insertsublist(&L,"Aku","Tortelini");
    insertsublist(&L,"Aku","Yuujinkrab");
    insertsublist(&L,"Ndekne","Roundpants");
    printlist(L);
    return 0;
}


void createempty(list *L){
    *L=nil;
}
bool isempty(list L){
    return (L==nil);
}
address alokasi(char nama[]){
    address P=(address)malloc(sizeof(struct node));
    P->info=(char*)malloc(sizeof(char)*(strlen(nama)));
    strcpy(P->info,nama);
    P->column=nil;
    P->row=nil;
}
void insertlist(list *L,char nama[]){
    address P=alokasi(nama);
    address Last=*L;
    if(isempty(*L)) *L=P;
    else{
        while(Last->column!=nil){
            Last=Last->column;
        }
        Last->column=P;
    }
}
void insertsublist(list *L,char root[],char nama[]){
    address P=alokasi(nama);
    address Prec=*L;
    if(isempty(*L)) *L=P;
    else{
        while(strcmpi(Prec->info,root)){
            Prec=Prec->column;
        }
        while(Prec->row!=nil){
            Prec=Prec->row;
        }
        Prec->row=P;
    }
}
void printlist(list L){
    address P=L;
    address subP;
    while(P!=nil){
        subP=P;
        while(subP!=nil){
            printf("%s ",subP->info);
            if(subP->row!=nil) printf("\t");
            subP=subP->row;
        }
        if(P->column!=nil) printf("\n");
        P=P->column;
    }
}
