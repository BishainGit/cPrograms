struct Node{
    int data;
    struct Node * next;
    
};

void push(struct Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   
    /* 2. put in the data  */
    new_node->data  = new_data; 
   
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
   
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node; 
} 

void print(struct Node* head){
    
     while(head->next != NULL){
         
         printf("%d",head->data);
         head = head->next ;
     }
      printf("%d",head->data);
}


struct Node* rearrange(struct Node **head_ref){
     struct Node *temp = (*head_ref);
     while(temp->data != 3){
           temp = temp->next;
     }
     struct Node *yad1 = temp;
          
     struct Node *yad2 = temp->next;
        
     struct Node *yad3 = temp->next->next;
          

     yad1->next = yad3;
     yad2->next = NULL;
     yad3->next->next = yad2;

     
    //
    temp = (*head_ref);
    yad1 = temp; //1
        
    yad2 = yad1->next ; //2
         
         
    while(temp->data != 5){
           temp = temp->next;
     }
         

     yad3 = temp->next;
         
       temp->next = temp->next->next;
       yad3->next = yad2;
       yad1->next = yad3;
    
    //
    temp = (*head_ref);
    while(temp->data != 2){
           temp = temp->next;
     }
     yad1 = temp; //1
           
     yad2 = yad1->next ; //2
        

       yad3 = temp->next->next;
       temp->next->next = temp->next->next->next;
           yad3->next = yad2;
           yad1->next = yad3;
         
   return (*head_ref); 
}

