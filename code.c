#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define t 100

void iallocate();
void ideallocate();
void idisplay();
int ifull();
void lallocate();
void ldeallocate();
void ldisplay();
int lfull();
void allocate();
void deallocate();
void display();
int full();

struct Indexed
{
    char n[30];
    int len;
    int indexblock;
    int indexblock2;
    int *IB[t];
    int *IB2[t];
}A[30];

struct Link
{
    char n[30];
    int len;
    int st;
    struct node
    {
        int index;
        struct node *next;
    }*Start,*current,*newnode,*temp;
}F[30];

struct Index
{
    char n[30];
    int len;
    int indexblock;
    int *IB[t];
}C[30];

int Table[t+1],pos=0,r,i,x,z,y,j,ch,B=0,indexblock,k=0;
char fn[30];

int main()
{
    printf(" Maximum size of the file for which Linked List File Allocation will be implemented : ");
    scanf("%d",&x);
    printf(" Maximum size of the file for which Normal Indexed File Allocation will be implemented : ");
    scanf("%d",&z);
    printf("\nEnter File Length : ");
    scanf("%d",&y);
    if(y>z)
    {
     printf("\nModified Indexed File Allocation \n");
     do{
     printf("\n\n1.Allocate a File\n2.Deallocate a File\n3.Display a File\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&ch);
     switch(ch)
     {
                case 1:
                    pos++;
                    iallocate();
                    break;

                case 2:
                    k--;
                    ideallocate();
                    break;

                case 3:
                    idisplay();
                    break;

                case 4:
                    exit(0);

                default:
                    printf("\nInvalid Choice ");
        }
     }while(ch!=4);
    }
    else if(y<x)
    {
        printf("\nLinked List File Allocation \n");
     do{
     printf("\n\n1.Allocate a File \n2.Deallocate a File \n3.Display a File\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&ch);
     switch(ch)
     {
                case 1:
                    pos++;
                    lallocate();
                    break;

                case 2:
                    ldeallocate();
                    break;

                case 3:
                    ldisplay();
                    break;

                case 4:
                    exit(0);

                default:
                    printf("\nInvalid Choice ");
        }
     }while(ch!=4);
    }

    else if(y>x && y<z )
    {
     printf("\nIndexed File Allocation \n");
     do{
     printf("\n\n1.Allocate a File\n2.Deallocate a File\n3.Display a File\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&ch);


     switch(ch)
     {
                case 1:
                    pos++;
                    allocate();
                    break;

                case 2:
                    k--;
                    deallocate();
                    break;

                case 3:
                    display();
                    break;

                case 4:
                    exit(0);

                default:
                    printf("\nInvalid Choice ");
        }
     }while(ch!=4);

    }
}

void iallocate()
{
   printf("\nEnter File Name : ");
   scanf("%s",&(A[pos].n));
   printf("\nEnter File Length : ");
   scanf("%d",&(A[pos].len));
   if(ifull())
   {
        pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }
    A[pos].indexblock=rand()%t+1;
    A[pos].indexblock2=rand()%t+1;
    Table[A[pos].indexblock]=1;
    Table[A[pos].indexblock2]=1;
   for(i=1;i<=(A[pos].len)/2;i++)
   {
        while(1)
        {

            r=rand()%t+1;
            if(Table[r]==0)
            {

                    A[pos].IB[i]=&Table[r];
                    Table[r]=r;
                    break;
            }
        }
        while(1)
        {

            r=rand()%t+1;
            if(Table[r]==0)
            {

                    A[pos].IB2[i]=&Table[r];
                    Table[r]=r;
                    break;
            }
        }
    }
    printf("\n\tDirectory\n");
    printf("\nFileName\tIndex Block 1\tIndex Block 2\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d\t\t%d",A[i].n,A[i].indexblock,A[i].indexblock2);
        printf("\n");
    }

}

void ideallocate()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&fn);
   for(i=1;i<=pos;i++)
   {
            if(strcmp(A[i].n,fn)==0)
            {
                for(j=1;j<=(A[pos].len)/2;j++)
                  {
                   *A[pos].IB[j]=0;
                  }
                for(j=1;j<=(A[pos].len)/2;j++)
                  {
                   *A[pos].IB2[j]=0;
                  }
                Table[A[pos].indexblock]=0;
                Table[A[pos].indexblock2]=0;
                strcpy(A[i].n,"NULL");
                A[i].indexblock=-1;
                A[i].indexblock2=-1;
                A[i].len=0;
                printf("\nFile (%s) Deleted Successfully \n",fn);
                break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\tDirectory\n");
    printf("\nFileName\tIndex Block 1\tIndex Block 2\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d\t\t%d",A[i].n,A[pos].indexblock,A[pos].indexblock2);
        printf("\n");
    }
}

void idisplay()
{
    printf("\nEnter The File Name : ");
    scanf("%s",fn);
    printf("\nBlocks Allocated Are : \n");
    for(i=1;i<=pos;i++)
    {
        if(strcmp(A[i].n,fn)==0)
        {
            printf("\n\t IndexBlock\n");
            printf("\n\t     %d\n",A[pos].indexblock);
            printf("\t------------");
            for(j=1;j<=(A[pos].len)/2;j++)
            {
                printf("\n\t|    %d\t   |\n",*A[pos].IB[j]);
            }
            printf("\t------------\n");

            printf("\n\t     %d\n",A[pos].indexblock2);
            printf("\t------------");
            for(j=1;j<=(A[pos].len)/2;j++)
            {
                printf("\n\t|    %d\t   |\n",*A[pos].IB2[j]);
            }
            printf("\t------------");

            break;
        }
    }
    if(i==pos+1)
    {
        printf("\n\nNo File Found\n");
    }
}

int ifull()
{
    for(i=1,B=0;i<=pos;i++)
        B=B+A[i].len;
    if(B>t-pos-k)
        return 1;
    else
        return 0;
}

void allocate()
{
   printf("\nEnter File Name : ");
   scanf("%s",&(C[pos].n));
   printf("\nEnter File Length : ");
   scanf("%d",&(C[pos].len));
   if(full())
   {
        pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }
    C[pos].indexblock=rand()%t+1;
    Table[C[pos].indexblock]=1;
   for(i=1;i<=C[pos].len;i++)
   {
        while(1)
        {

            r=rand()%t+1;
            if(Table[r]==0)
            {

                    C[pos].IB[i]=&Table[r];
                    Table[r]=r;
                    break;
            }
        }
    }
    printf("\n\tDirectory\n");
    printf("\nFileName\tIndexBlock\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d",C[i].n,C[i].indexblock);
        printf("\n");
    }

}
void deallocate()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&fn);
   for(i=1;i<=pos;i++)
   {
            if(strcmp(C[i].n,fn)==0)
            {
                for(j=1;j<=C[pos].len;j++)
                   *C[pos].IB[j]=0;
                Table[C[pos].indexblock]=0;
                strcpy(C[i].n,"NULL");
                C[i].indexblock=-1;
                C[i].len=0;
                printf("\nFile (%s) Deleted Successfully \n",fn);
                break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\tDirectory\n");
    printf("\nFileName\tIndexBlock\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d",C[i].n,C[pos].indexblock);
        printf("\n");
    }
}
void display()
{
    printf("\nEnter The File Name : ");
    scanf("%s",fn);
    printf("\nBlocks Allocated Are : \n");
    for(i=1;i<=pos;i++)
    {
        if(strcmp(C[i].n,fn)==0)
        {
            printf("\n\t IndexBlock\n");
            printf("\n\t     %d\n",C[pos].indexblock);
            printf("\t------------");
            for(j=1;j<=C[pos].len;j++)
            {
                printf("\n\t|    %d\t   |\n",*C[pos].IB[j]);
            }
            printf("\t------------");

            break;
        }
    }
    if(i==pos+1)
    {
        printf("\n\nNo File Found\n");
    }
}
int full()
{
    for(i=1,B=0;i<=pos;i++)
        B=B+C[i].len;
    if(B>t-pos-k)
        return 1;
    else
        return 0;
}

void lallocate()
{
   printf("\nEnter File Name : ");
   scanf("%s",&(F[pos].n));
   printf("\nEnter File Length : ");
   scanf("%d",&(F[pos].len));
   F[pos].Start=NULL;
   if(lfull())
   {
        pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }

   for(i=1;i<=F[pos].len;i++)
   {
        F[pos].newnode=(struct node *)malloc(sizeof(struct node));

        while(1)
        {

            r=rand()%t+1;
            if(Table[r]==0)
            {
                    F[pos].newnode->index =r;
                    F[pos].newnode->next=NULL;
                    if(F[pos].Start==NULL)
                    {
                        F[pos].Start=F[pos].newnode;
                        F[pos].current=F[pos].newnode;
                    }
                    else
                    {
                        F[pos].current->next=F[pos].newnode;
                        F[pos].current=F[pos].newnode;
                    }

                    Table[r]=1;
                    break;
            }
        }
    }
    F[pos].st=F[pos].Start->index;
    for(i=r;i<r+F[pos].len;i++)
        Table[i]=1;
    printf("\n\tLinked List File Allocation \n");
    printf("\nFileName\tStart\tEnd\tLength\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d\t%d\t%d",F[i].n,F[i].st,F[pos].current->index,F[i].len);
        printf("\n");
    }

}

void ldeallocate()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&fn);
   for(i=1;i<=pos;i++)
   {
            if(strcmp(F[i].n,fn)==0)
            {
                F[i].current=F[i].Start;
                while(F[i].current)
                {
                    Table[F[i].current->index]=0;
                    F[i].temp=F[i].current;
                    F[i].current=F[i].current->next;
                    free(F[i].temp);
                }

                strcpy(F[i].n,"NULL");
                F[i].st=0;
                F[i].len=0;
                printf("\nFile (%s) Deleted Successfully \n",fn);
                break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\t\tLinked List File Allocation \n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=pos;i++)
    {
        printf("\n%s\t\t%d\t%d",F[i].n,F[i].st,F[i].len);
        printf("\n");
    }
}

void ldisplay()
{
    printf("\nEnter The File Name : ");
    scanf("%s",fn);
    printf("\nBlocks Allocated Are : ");
    for(i=1;i<=pos;i++)
    {
        if(strcmp(F[i].n,fn)==0)
        {
            F[i].current=F[i].Start;
            while(F[i].current)
            {
               printf("--%d-->",F[i].current->index);
               F[i].current=F[i].current->next;
            }
            break;
        }
    }
    if(i==pos+1)
    {
        printf("\n\nNo File Found\n");
    }
}

int lfull()
{
    for(i=1,B=0;i<=pos;i++)
        B=B+F[i].len;
    if(B>t)
        return 1;
    else
        return 0;
}
