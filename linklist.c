#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* define structure for  node*/
struct lnode{
    int data;
    struct lnode *next;
};

/*we canot type like this in evry sentance struct lnode *node so we use typdef it easy to acces*/

typedef struct lnode node;
node* head=NULL;

/*Function Declaration*/

void insert_at_start(int val);
void Display();
void insert_at_pos(int pos, int val);

int main(){
        int val,choice,pos;
    while(1){
        printf("----------------------option--------------------------\n");
        printf("1.) Insert Begening\n");
        printf("2.) Display\n");
        printf("3.) Insert at postion\n");
        printf("4.) Remove\n");
        printf("---------------------------------------------------------\n");
        printf("\n");

        printf("Enter the choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:printf("Enter the value: ");
                   scanf("%d",&val);
                   insert_at_start(val);
                   break;

            case 2:
                   Display();
                   break;

            case 3:printf("Enter the Postion : ");
                   scanf("%d",&pos);
                   printf("Enter the value : ");
                   scanf("%d",&val);
                   if(pos == 0)
                       insert_at_start(val);

                   if(pos < 0){
                       printf("Invalide option");
                       return 0;
                   }
                   insert_at_pos(pos, val);
                   break;


        }

    }
}


void insert_at_start(int val){
  node* newnode = (node*) malloc(sizeof(node)); // type castin  malloc Null pointer into struct ptr
  /*if newnode Get some error it will alocate NULL  this error is uncommon if we use lareg amount of data This error Ocurr*/
  if(newnode == NULL){
    printf("Out of Memory\n");
    return;
  }
  newnode->data=val;//assing value to the data for new node
  if(head == NULL){
    printf("Value inserted at Head ponter \n");
    newnode->next=NULL;         // we assing NULL to Next pointer because of Ther is no value int next node it the head os the node so we assing NULL
    head=newnode; // changing our newnode into head node;
  }else{
    newnode->next=head; // assing ptr next addr  value in head
    head=newnode;
  }

  printf("Value inserted  %d\n",val);
  printf("\n");
}


void Display(){
    node* temp=head;
    if(head == NULL){
        printf("Ther is No value in the list\n");
        return;
    }
    temp=head;
    printf("Values in the list : ");
    while(temp != NULL){
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert_at_pos(int pos,int val){
    //create new node for new value
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Out of memory\n");
        return;
    }

    newnode->data=val;
    node* temp=head;

    for(int i=0; i< pos-1; i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;

    printf("Inserted at %d postion, value %d ",pos, val);
    printf("\n");
}
