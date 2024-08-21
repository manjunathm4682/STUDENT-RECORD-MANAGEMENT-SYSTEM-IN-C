#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct st
{
int rollno;
char name[10];
float perc;
struct st *next;
}SLL;

SLL *head=0;                                    //globally head pointer declared

int node_count(SLL *);
int rollnumber();
void stud_add(void);
void stud_show(void);
void stud_del(void);
void delete_rn(void);
void delete_name(void);
void stud_mod(void);
void search_rn(void);
void search_name(void);
void search_perc(void);
void stud_save(void);
void sort_data_name(void);
void sort_data_perc(void);
void delete_all_node(void);
void funA(void);
void funB(void);
void reverse_link(void);
int rollnumber();
void main()
{
        char ch;
        while(1)
        {
        printf("*****STUDENT RECORD MENU*****\n");
        printf("_____________________________\n\n");
        printf("a/A : add new record\n");
        printf("d/D : delete a record\n");
        printf("s/S : show the list\n");
        printf("m/M : modify a record\n");
        printf("v/V : save\n");
        printf("e/E : exit\n");
        printf("t/T : sort the list \n");
        printf("l/L : delete all the records\n");
        printf("r/R : reverse the list\n");
        printf("\nEnter your choice: \n");
        scanf(" %c",&ch);
        switch(ch)
        {
                case 'a':stud_add();break;
                case 'd':stud_del();break;
                case 's':stud_show();break;
                case 'm':stud_mod();break;
                case 'v':stud_save();break;
                case 'e':funA();break;
                case 't':funB();break;
                case 'l':delete_all_node();break;
                case 'r':reverse_link();break;



defalut:printf("\n**********************\nWrong option selected\n\n");
        }
        }

}

void reverse_link(void)
{
        if(head==0)
        {
                printf("no records found\n");
                return;
        }
        SLL *t=head;
        int i=0,c=0;
        for(c=0;t;t=t->next,c++);
        t=head;
        if(c>1)
        {
                SLL **arr=malloc(sizeof(SLL) * c);

                while(t)
                {
                        arr[i++]=t;
                        t=t->next;
                }

                for(i=1;i<c;i++)
                        arr[i]->next=arr[i-1];
                arr[0]->next=0;
                head=arr[c-1];
        }
}





void funB(void)
{
                         char h;
                         printf("Enter :\n");
                         printf("n/N : sort with name\n");
                         printf("p/P : sort with percentage\n");
                         scanf(" %c",&h);
                         switch(h)
                         {
                                 case 'n': sort_data_name();break;
                                 case 'p': sort_data_perc();break;

                                 default: printf("wrong input\n");
                         }

}

void funA(void)
{
                         char c;
                         printf("Enter :\n");
                         printf("s/S : save and exit\n");
                         printf("e/E : exit without saving\n");
                         scanf(" %c",&c);
                         switch(c)
                         {
                                 case 's': stud_save(); exit(0);
                                 case 'e': exit(1);

                                 printf("wrong input\n");
                         }

}




void stud_save(void)
{

        FILE *fp = fopen("student.txt","w");
        SLL *p=head;
        while(p)
        {
                fprintf(fp,"%d %s %f\n",p->rollno,p->name,p->perc);
                p=p->next;
        }

        printf("data saved successfully\n");
        fclose(fp);
}


void delete_all_node(void)
{
        if(head==0)
        {
                printf("no records found\n");
                return;
        }
        SLL *p=head;
        SLL *del=p;
        int c=1;
        while(del)
        {
                p=del->next;
                sleep(1);
                printf("deleted node %d \n",c++);
                free(del);
                del=p;
        }
        printf("all the records deleted\n");
        head=0;

}

void sort_data_perc(void)
{
        int c;
        SLL *p=head;
        if(p==0)
        {
                printf("No records found while sorting data by perc\n");
                return;
        }
        SLL *p1,*p2,t;
        int i,j;
        for(c=0;p;p=p->next,c++);
        p=head;
        p1=head;
        for(i=0;i<c-1;i++)
        {
                p2=p1->next;
                for(j=0;j<c-1-i;j++)
                {
                        if(p1->perc > p2->perc)
                        {
                                t.rollno=p1->rollno;
                                p1->rollno=p2->rollno;
                                p2->rollno=t.rollno;

                                strcpy(t.name,p1->name);
                                strcpy(p1->name,p2->name);
                                strcpy(p2->name,t.name);

                                t.perc=p1->perc;
                                p1->perc=p2->perc;
                                p2->perc=t.perc;

                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }

}

void sort_data_name(void)
{
        int c;
        SLL *p=head;
        if(p==0)
        {
                printf("No records found while sorting data by name\n");
                return;
        }
        SLL *p1,*p2,t;
        int i,j;
        for(c=0;p;p=p->next,c++);
        p=head;
        p1=head;
        for(i=0;i<c-1;i++)
        {
                p2=p1->next;
                for(j=0;j<c-1-i;j++)
                {
                        if(strcmp(p1->name,p2->name)>0)
                        {
                                t.rollno=p1->rollno;
                                p1->rollno=p2->rollno;
                                p2->rollno=t.rollno;

                                strcpy(t.name,p1->name);
                                strcpy(p1->name,p2->name);
                                strcpy(p2->name,t.name);

                                t.perc=p1->perc;
                                p1->perc=p2->perc;
                                p2->perc=t.perc;

                        }
                        p2=p2->next;
                }
                p1=p1->next;
        }

}






void stud_mod(void)
{
        char ch;
printf("Enter which record to search for modification\n");
printf("r/R : to search a rollno\n");
printf("n/N : to search a name\n");
printf("p/P : percentage based\n");
scanf(" %c",&ch);
switch(ch)
{
        case 'r' : search_rn();break;
        case 'n' : search_name();break;
        case 'p' : search_perc();break;

        default:printf("WRONG INPUT\n");
}
}

void search_perc(void)
{
SLL *p=head;
int rn;
float per;
printf("Enter the rn and percentage\n");
scanf("%d %f",&rn,&per);
while(p)
{
        if((p->rollno == rn) && (p->perc == per))
        {
                printf("Enter the new perc to modify\n");
                scanf("%f",&p->perc);
                return;
        }
        p=p->next;
}
printf("rn and percentage not found\n");

}



void search_name(void)
{
        SLL *p=head;
        int rn;
        char n[20];
        printf("Enter the rn and name to search\n");
        scanf("%d %s",&rn,n);
        while(p)
        {
                if((strcmp(n,p->name)==0)&&(rn==p->rollno))
                {
                        printf("Enter the name to modify\n");
                        scanf("%s",p->name);
                        return;
                }
                p=p->next;
        }
        printf("rn and name not found\n");

}


void search_rn(void)
{
SLL *p=head;
int rn;
printf("Enter the rn to search\n");
scanf("%d",&rn);
while(p)
{
        if(p->rollno == rn)
        {
                printf("Enter the new rollno to modify\n");
                scanf("%d",&p->rollno);
                return;
        }
        p=p->next;
}
printf("rn not found\n");
}


void stud_del(void)
{
        char ch;
printf("r/R : enter roll to delete\n");
printf("n/N : enter name to delete\n");
scanf(" %c",&ch);

switch(ch)
{
        case 'r' :delete_rn();break;
        case 'n' :delete_name();break;

}
}

void delete_rn(void)
{
                        if(head==0)
                        {
                                printf("No records found\n");
                                return;
                        }
                        int rn;
                        printf("Enter rollno to delete the node\n");
                        scanf("%d",&rn);

                        SLL *del=head,*prev;

                        while(del)
                        {
                                if(del->rollno == rn)
                                {
                                        if(del==head)
                                                head=del->next;
                                        else
                                                prev->next=del->next;
                                        free(del);
                                        return;
                                }
                                prev=del;
                                del=del->next;
                        }
                        printf("name not found\n");

}


void delete_name(void)
                {
                        if(head==0)
                        {
                                printf("No records found\n");
                                return;
                        }
                        char n[20];
                        printf("Enter name to delete the node\n");
                        scanf(" %s",n);

                        SLL *del=head,*prev;

                        while(del)
                        {
                                if(strcmp(n,del->name)==0)
                                {
                                        if(del==head)
                                                head=del->next;
                                        else
                                                prev->next=del->next;
                                        free(del);
                                        return;
                                }
                                prev=del;
                                del=del->next;
                        }
                        printf("name not found\n");
                }

void stud_show(void)
{
        SLL *p=head;
        if(p==0)
        {
        printf("No nodes are present\n");
        return;
        }
        while(p)
        {
        printf("%d %s %f\n",p->rollno,p->name,p->perc);
        p=p->next;
        }
}

int rollnumber()
{
int i,c,t,j;
SLL *ptr;
ptr=head;
c=node_count(ptr);
int *a=malloc(sizeof(int)*c);
i=0;
/*while(ptr)
{
a[i++]=ptr->rollno;
ptr->next;
}
*/

for(i=0;i<c;i++)
{
a[i]=ptr->rollno;
ptr=ptr->next;
}
//sorting the number
for(i=0;i<c-1;i++)
{
for(j=0;j<c-1-i;j++)
{
if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}

for(i=0,j=1;j<=c;i++,j++)
{
if(j!=a[i])
        return j;               // the rollnumber which is not present
}
return a[c-1]+1;
}

int node_count(SLL *p)
{
int c=0;
while(p)
{
c++;
p=p->next;
}
return c;
}


void stud_add(void)
{
SLL *new;
new=malloc(sizeof(SLL));
new->rollno=rollnumber();
printf("Enter the name and perc\n");
scanf(" %s %f",new->name,&new->perc);
new->next=0;
if(head==0 || new->rollno < head ->rollno )
{
        new->next=head;
        head=new;
}
else
{
SLL *p=head;
while((p->next!=0) && (new->rollno > p->next->rollno))
        p=p->next;
new->next=p->next;
p->next=new;

}
}


          