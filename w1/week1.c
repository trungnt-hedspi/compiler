#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char WORD[20];
typedef struct
{
    char word[20];
    int number;
    int list[20];
    int top;
}data;

typedef struct node
{
    data d;
    struct node*next;
}node;

typedef struct
{
    node*head;
    node*end;
}linklist;

void insert(linklist*root,char*xau,int j)
{node *p;
int i=0;
    if(root->head==NULL)
    {
      //  printf("%s  %d",xau,j);
        p=(node*)malloc(sizeof(node));
        strcpy(p->d.word,xau);
        p->d.number=1;
        p->d.list[0]=j;
        p->d.top=1;
        p->next=NULL;
        root->head=root->end=p;
    }


    else
    {
for(p=root->head;p!=NULL;p=p->next)
{
    if(strcmp(p->d.word,xau)==0)
    {
       // printf("%s  %d",xau,j);
        i=1;
        p->d.number++;
       if(p->d.list[p->d.top-1]!=j)
       {
           p->d.list[p->d.top]=j;
           p->d.top++;
       }
    }

}

if(i==0)
{
//printf("%s  %d",xau,j);
        p=(node*)malloc(sizeof(node));
        strcpy(p->d.word,xau);
        p->d.number=1;
         p->d.list[0]=j;
        p->d.top=1;

        p->next=root->head;
        root->head=p;

}

    }
}

void showlist(linklist *root)
{node*p;
int i=0;
for(p=root->head;p!=NULL;p=p->next)
{
    printf("%s %d ",p->d.word,p->d.number);
    for(i=0;i<p->d.top;i++)
    {
        printf("%d ",p->d.list[i]);
    }
    printf("\n");
}

}

void sort(linklist*root)
{
    node*p1,*p2;
    int i=0;
    data d1,d2,tg;
    for(p1=root->head;p1!=root->end;p1=p1->next)

    for(p2=p1;p2!=NULL;p2=p2->next)

    {
        d1=p2->d;
        d2=p1->d;
        if(strcmp(d1.word,d2.word)<0)
        {
           // printf("%s %s ",d1.word,d2.word);
            tg=p2->d;
            p2->d=p1->d;
            p1->d=tg;
        }
    }


    showlist(root);
}
int main()
{FILE *f;
int i=0,j=1,n=0,sign=0,daucau=0;
char c;
char xau[40];
WORD stopw[40];
linklist root;
root.head=root.end=NULL;
    f=fopen("stopw.txt","r");
    while(!feof(f))
    {
        c=fgetc(f);
        if(isalpha(c))
        {
            xau[i]=c;
            i++;
        }else
        {
            xau[i]='\0';
            strcpy(stopw[n],xau);
            n++;
            strcpy(xau,"");
            i=0;
        }
    }


fclose(f);
fopen("unnikatha.txt","r");

  while(!feof(f))
    {
        c=fgetc(f);
        if(c=='\n')
        {j++;
        continue;
        }

        if(isalpha(c))
        {

            if(daucau!=1&&c>=60&&c<=95)
            while(isalpha(fgetc(f)))
                  continue;
else{
            xau[i]=tolower(c);
            i++;
    }
        }else
        {



            xau[i]='\0';
if(strcmp(xau,"")!=0)
{//printf("%s  %d \n",xau,j);
    for(i=0;i<n;i++)
    {
        if(strcmp(xau,stopw[i])==0)
        sign=1;
    }
  if(sign!=1)
insert(&root,xau,j);
}
            strcpy(xau,"");
            i=0;
            sign=0;
        }

          if(c=='.')
            daucau=1;
            else
            daucau=0;
    }


fclose(f);




sort(&root);

//showlist(&root);


    return 0;
}
