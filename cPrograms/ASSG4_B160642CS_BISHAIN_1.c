#include<stdio.h>
#include<stdlib.h>

struct node
{
     int key;
     struct node* next;
};
typedef struct node hashTable;

int m;
int x;

int hashFunction(int);
void chainedHashInsert(hashTable *[],int);
void chainedHashSearch(hashTable *[],int);
void chainedHashDelete(hashTable *[],int);
int main()
{
  
  
  char ch;
  scanf("%c\n",&ch);
  scanf("%d\n",&m);
    if(m<0)
    {
      printf("INVALID INPUT");
      return 0;
    }




if(ch=='d')
    {
       hashTable *chainedHash[m];
       
       for(int i=0;i<m;i++)
       {
          chainedHash[i] = NULL;
       }
           char ch1;
          scanf("%c ",ch1);
          getchar();
          int count = 0;
      do
        {
         switch(ch) 
          {

         
   
          
          case 'i':
           
             if(count<m) 

            {
             
             scanf("%d\n",&x);
             if(x<-2000000000 || x>2000000000)
             {
               printf("INVALID INPUT");
               return 0;
             } 
             getchar();

             chainedHashInsert(chainedHash,x);
             count++;
            }
          
             else
               {
                 printf("CANNOT INSERT");
                 return 0;
               }
           
          break;

          case 's':
          
            scanf("%d",&x);
            getchar();
            if(x<-2000000000 || x>2000000000)
             {
               printf("-1");
             } 
            
            else 
             
               chainedHashSearch(chainedHash,x); 
             
            
          
          break;
          
        /*  if(ch1=='d')
          {
            scanf("%d",x);
            getchar();
            if(x<-2000000000 || x>2000000000)
             {
              
               return ;
             } 
             
            else
             {
               chainedHashDelete(chainedHash,x);
             }
          }

          if(ch1=='p')
          {
            chainedHashPrint(chainedHash);
          }

        */  
         

        case 't':
        break;

        default:
        printf("Enter Correct Choice");
        break;
      }
     scanf("&c",&ch1);
     getchar();
    }while(ch1=!'t');
   } 
   
   return 0; 
}

int hashFunction(int val)
{
	int key = val % m;
	while(key < 0)
	{
		key = (key + m) % m;
	}
	return key;
}

void chainedHashInsert(hashTable *array[], int value)
{
	int index = hashFunction(value);
	printf("%d\n", index);
	if(array[index] == NULL)
	{
		hashTable *node = (hashTable *)malloc(sizeof(hashTable));
		node->key = value;
		node->next = NULL;
		array[index] = node;
	}
	else
	{
		hashTable *temp = array[index];
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		hashTable *temp1 = (hashTable *)malloc(sizeof(hashTable));
		temp1->key = value;
		temp1->next = NULL;
		temp->next = temp1;
	}
}

void chainedHashSearch(hashTable *array[], int value)
{
	int index = hashFunction(value);

	while(array[index] != NULL)
	{
		if(array[index]->key == value)
		{
				printf("%d FOUND\n", index);
				return;
		}
		array[index] = array[index]->next;
	}
	printf("%d NOT FOUND\n", index);
	return;
}

