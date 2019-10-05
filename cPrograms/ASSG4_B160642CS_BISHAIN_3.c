#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#define max "2147483648"
#define min "-2147483648"
struct node
{
  int key, rank;
  struct node* next,*parent;
};

long int x,i=0,c1=0,c2=0,c3=0,c4=0;

typedef struct node d;
d *a1[10000];
d *a2[10000];
d *a3[10000];
d *a4[10000];

void makeset(long int);
d *find_set(d*);
d *find_node(long int);
d *find_union(long int,long int);

void makeset_rank(long int);
d *find_set_rank(d*);
d *find_node_rank(long int);
d *find_union_rank(long int,long int);

void makeset_path(long int);
d *find_set_path(d*);
d *find_node_path(long int);
d *find_union_path(long int,long int);

void makeset_both(long int);
d *find_set_both(d*);
d *find_node_both(long int);
d *find_union_both(long int,long int);

long int checkFloat(char []);

int main()
{
   d *t1,*t2,*t3,*t4;
   long int j,n1,n2,n3;
   for(j=0;j<10000;j++)
   {
      a1[j]=NULL;
      a2[j]=NULL;
      a3[j]=NULL;
      a4[j]=NULL;
   }
   char ch;
   char num1[100],num2[100],num3[100];
   scanf("%c",&ch);
   getchar();
   do
   {
    switch(ch)
    {
        case 'm':
          scanf("%s",num1);
          n1 = checkFloat(num1);
          if(n1==-1||n1>10000||n1<0)
          {
             printf("INVALID INPUT\n");
             return 0;
          }
          getchar();
if(find_set(find_node(n1))!=NULL&&find_set_rank(find_node_rank(n1))!=NULL&&find_set_path(find_node_path(n1))!=NULL&&find_set_both(find_node_both(n1))!=NULL)
          {
            printf("PRESENT\n");
          }
          else
          {
             makeset(n1);
             makeset_rank(n1);
             makeset_path(n1);
             makeset_both(n1);
             i++;
             printf("%d\n",n1);
          }
                    
        break;
        
        case 'f':
          scanf("%s",num2);
          n2=checkFloat(num2);
          if(n2==-1||n2>10000||n2<0)
          {
             printf("INVALID INPUT\n");
             return 0;
          }
          getchar();
          t1=find_set(find_node(n2));
          t2=find_set_rank(find_node_rank(n2));
          t3=find_set_path(find_node_path(n2));
          t4=find_set_both(find_node_both(n2));
  if(t1==NULL||t2==NULL||t3==NULL||t4==NULL)
  {
      printf("NOT FOUND\n");
  }
  else
    printf("%d %d %d %d\n",t1->key,t2->key,t3->key,t4->key);
       break;

        case 'u':
          scanf("%s %s",num1,num2);
          n1=checkFloat(num1);
          n2=checkFloat(num2);
          if(n1==-1||n1>10000||n1<0)
          {
             printf("INVALID INPUT\n");
             return 0;
          }
          if(n2==-1||n2>10000||n2<0)
          {
             printf("INVALID INPUT\n");
             return 0;
          }
          getchar();
          t1=find_union(n1,n2);
          t2=find_union_rank(n1,n2);
          t3=find_union_path(n1,n2);
          t4=find_union_both(n1,n2);
          if(t1==NULL||t2==NULL||t3==NULL||t4==NULL)
          {
             printf("ERROR\n");
          }
          else
          {
             printf("%d %d %d %d\n",t1->key,t2->key,t3->key,t4->key);
           }
          break;
   
          
          default:
          printf("ENTER CORRECT CHOICE\n");
          break;

    }
     scanf("%c",&ch);
     getchar();
     
   }while(ch!='s');
   printf("%d %d %d %d\n",c1,c2,c3,c4);
}

void makeset(long int x)
{
    d* new_node=( d*)malloc(sizeof( d));
   new_node->key = x;
   new_node->next= NULL;
   new_node->parent = new_node;
   a1[i]=new_node;
}
d *find_node(long int x)
{
   long int j=0;
   while(a1[j]!=NULL)
   {
      if(a1[j]->key==x)
      {
        return a1[j];
      }
      else 
         j++;
   }
   return NULL;
}
d *find_set(d* node)
{
   if(node==NULL)
   {
     return NULL;
   }
   else if(node->parent != node)
  {  c1++;
     return find_set(node->parent);
  }
  else if(node->parent==node)
  {
      c1++;
      return node->parent;
  }
}
d *find_union(long int x,long int y)
{
  d *set1 = find_set(find_node(x));
  d *set2 = find_set(find_node(y));
  if(set1==NULL&&set2==NULL)
  {
     return NULL;
  }
  else if(set1==set2)
  {
    return set1;
  }
  else 
     set2->parent = set1;
     return set1;
}
/****************************/
void makeset_rank(long int x)
{
   d* node = (d*)malloc(sizeof(d));
   node->key=x;
   node->rank=0;
   node->next=NULL;
   node->parent=node;
   a2[i]=node;
}

d* find_node_rank(long int x)
{
  long int j =0;
  while(a2[j]!=NULL)
  {
    if(a2[j]->key==x)
    {
      return a2[j];
    }
    else
     j++;
  }
  return NULL;
}

d* find_set_rank(d* node)
{
   if(node==NULL)
   {
     return NULL;
   }
   else if(node->parent!=node)
   {
      c2++;
     return find_set_rank(node->parent);
    }
   else if(node->parent==node)
   {
      c2++;
     return node->parent;
   }
}

d* find_union_rank(long int x,long int y)
{
   d *set1 = find_set_rank(find_node_rank(x));
   d *set2 = find_set_rank(find_node_rank(y));
   if(set1==NULL||set2==NULL)
   {
     return NULL;
   }
   else if(set1==set2)
   {
     return set1;
   }
   else
    {
      if(set1->rank>set2->rank)
      {
         set2->parent=set1;
         return set1;
      }
      else if(set2->rank>set1->rank)
      {
         set1->parent=set2;
         return set2;
      }
      else
         set2->parent=set1;
         set1->rank=set1->rank+1;
         return set1;
    }
}
/************************************/
void makeset_path(long int x)
{
  d* node =(d*)malloc(sizeof(d));
  node->key=x;
  node->next=NULL;
  node->parent=node;
  a3[i]=node;
}

d *find_node_path(long int x)
{
  long int j=0;
  while(a3[j]!=NULL)
  {
     if(a3[j]->key==x)
     {
       return a3[j];
     }
     else
       j++;
  }
  return NULL;
}



d *find_set_path(d *node)
{
  if(node==NULL)
  {
    return NULL;
  }
  else if(node->parent!=node)
  {
 
    node->parent= find_set_path(node->parent);
  }
  else if(node->parent==node)
   {
    c3++;
    return node->parent;
   }
    
}

d *find_union_path(long int x,long int y)
{
   d *set1 = find_set_path(find_node_path(x));
   d *set2 = find_set_path(find_node_path(y));
   if(set1==NULL||set2==NULL)
   {
     return NULL;
   }
   else if(set1==set2)
   {
     return set1;
   }
   else
    set2->parent=set1;
    return set1;
}

/**********************************/
void makeset_both(long int x)
{
  d *node = (d*)malloc(sizeof(d));
  node->key=x;
  node->next=NULL;
  node->parent=node;
  a4[i]=node;
}

d *find_node_both(long int x)
{
  long int j=0;
  while(a4[j]!=NULL)
  {
    if(a4[j]->key==x)
    {
      return a4[j];
    }
   else
     j++;
   
  }
  return NULL;
}
 
d *find_set_both(d *node)
{
   if(node==NULL)
   {
     return NULL;
   }
   else if(node->parent!=node)
        {
          node->parent = find_set_both(node->parent);
        }
     else
        c4++;
        return node->parent;
}

d *find_union_both(long int x,long int y)
{
   d *set1 = find_set_both(find_node_both(x));
   d *set2 = find_set_both(find_node_both(y));
   if(set1==NULL||set2==NULL)
   {
      return NULL;
   }
   else if(set1==set2)
       {
          return set1;
       }
       else
        {
           if(set1->rank>set2->rank)
           {
              set2->parent=set1;
              return set1;
           }
           else if(set2->rank>set1->rank)
                {
                  set1->parent = set2;
                  return set2;
                }
                else
                  set2->parent = set1;
                  set1->rank = set1->rank + 1;
                  return set1;
        }
  
}

/***********************************/
long int checkFloat(char num[])
{
  if(strcmp(num,max)==0||strcmp(num,min)==0)
  {
    return -1;
  }
  long int i,sum=0,val;
  for(i=0;num[i]!='\0';i++)
  {
    if(num[i]<'0'||num[i]>'9')
    {
     return -1;
    }
    else
     val = num[i]-'0';
     sum = sum*10 + val;
  }
  return sum;
}
  
