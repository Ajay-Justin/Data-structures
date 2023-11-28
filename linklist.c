#include<stdio.h>
#include<stdlib.h>
#include<string.h>
   
struct lnode{
    int data;
    struct lnode *next;
};
  
typedef struct lnode node;
node* head=NULL;
  
 
//function declaration
void insertatBegging(int val);
void Display(); 
void insertatPostion(int pos, int val);
void deleteatBegging();
void deleteatPostion(int pos);
int checkInvalidOrNOt(int pos);
void insertatEnd(int val);
void deleteatEnd();
void readAtpostion(int pos);
void insertAtEnd(int val);
void search(int val);
void total();

int main(){     
    int val,choice,pos,ser;
      
    while(1){
        printf("\n");
        printf("__________________OPTIONS_____________________\n");
        printf("1.Insert at begging\n");
        printf("2.Insert at postion\n");
        printf("3.Delete at postion\n");
        printf("4.Delete at begging\n");
        printf("5 Delete at end\n");
        printf("6.Insert at end\n");
        printf("7.Read at postion\n");
        printf("8.search\n");
        printf("9.Display data\n");
        printf("10.Total ammount of data\n");
        printf("___________________________________________\n");
        printf("\n");
        printf("Enter the Choice: ");
        scanf("%d",&choice);
        switch (choice){

            case 1: printf("Inserted at postion\n");
                    printf("Enter the value : ");
                    scanf("%d",&val);
                    insertatBegging(val);
                    break;
            case 2: printf("Inserted at postion\n");
                    printf("Enter the postion : ");
                    scanf("%d",&pos);
                    printf("Enter the value : ");
                    scanf("%d",&val);
                    if(pos == 0)
                        insertatBegging(val);
                    if(pos < 0){
                        printf("Invalid postion\n");
                        return 0;
                    }else{
                        insertatPostion(pos, val);
                    }
                    break;

            case 3: printf("Delete at postion\n");
                    printf("Enter the postion : ");
                    scanf("%d",&pos);
                    if(pos < 0){
                        printf("Invalid postion");
                        return 0;
                    }
                    if(pos == 0){
                        deleteatBegging();
                        return 0;
                    }
                    deleteatPostion(pos);
                    break;
            case 4:printf("Delete at begging\n");
                   if((checkInvalidOrNOt(pos))==0)
                       return 0;

                    deleteatBegging();
                    printf("\n");
                    break;

            case 5: printf("Delete at end\n");
                    deleteatEnd();
                    break;

            case 6: printf("Inserted at end\n");
                    printf("Enter the value : ");
                    scanf("%d",&val);
                    insertAtEnd(val);
                    break;
            case 7: printf("Read at postion\n");
                    printf("Enter the postion : ");
                    scanf("%d",&pos);
                    if((checkInvalidOrNOt(pos))==0)
                        return 0;
                    readAtpostion(pos);
                    break;
            case 8: printf("search\n");
                    printf("Enter the value : ");
                    scanf("%d",&val);
                    search(val);
                    break;
            case 9: Display();
                    break;
            case 10: printf("Total amount of data\n");
                     total();
                     break;
        }
    }
  
  
  }
  
 void insertatBegging(int val){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Out of Memory\n");
        return;
    }
    newnode->data=val;
    if(head == NULL){
        printf("Data inserted at Head\n");
        newnode->next=NULL;
        head=newnode;
        return;
    }
    newnode->next=head;
    head=newnode;
    printf("Data Inserted\n");
}

void Display(){

    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    node* temp;
    temp=head;
    printf("Values are in the list : ");
    while(temp != NULL){
        printf("%d, ",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

void insertatPostion(int pos, int val){
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Out of memory\n");
        return;
    }

    newnode->data=val;
    node* temp;
    temp=head;
    for(int i=0; i< pos-1; i++){
        temp=temp->next;
        if(temp == NULL){
            printf("Invlaid postion");
            return;
        }
        printf("\n");
    }
    newnode->next=temp->next;
    temp->next=newnode;
    printf("Data inserted %d at %d postion",val,pos);
    printf("\n");

}
void deleteatBegging(int pos,int val){
    node* temp;
    temp=head;
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    head=temp->next;
    if(temp == NULL){
        printf("Thier is no value\n");
        return;
    }
    printf("Value Deleted at head %d\n",temp->data);
    free(temp);
    printf("\n");
}

void deleteatPostion(int pos){
    node* prevnode;
    node* temp=head;
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    
    for(int i=1;i<=pos;i++){
        prevnode=temp;
        temp=temp->next;
        if(temp == NULL){
            printf("Invalid postion or no value\n");
            return;
        }
        
    }
    prevnode->next=temp->next;
    printf("Node delted at %d postion value  %d\n",pos,temp->data);
    free(temp);
    printf("\n");
}

int checkInvalidOrNOt(int pos){
    if(pos >= 0){
        return 1;
    }
    printf("Invalid postion\n");
    printf("\n");
    return 0;

}
void deleteatEnd(){
    node* temp=head;
    node* prevnode;
    node* temp2;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    int i=0;
    while(temp != NULL){
        prevnode=temp2;
        temp2=temp;
        temp=temp->next;
    }
    
        
    printf("Value delete at end %d\n",temp2->data);
    prevnode->next=NULL;
    free(temp);
    free(temp2);
    printf("\n");
    
}

void readAtpostion(int pos){
    node *temp=head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    for(int i=1;i<=pos;i++){
        temp=temp->next;
        if(temp == NULL){
            printf("No value in thr given function\n");
            return;
        }
    }
    printf("The value of you enterd postion value  %d\n",temp->data);
    printf("\n");
    free(temp);
}

void insertAtEnd(int val){
    node * newnode=(node*)malloc(sizeof(node));
    node* prevnode;
    node* temp;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    temp=head;
    newnode->data=val;
    while(temp != NULL){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=newnode;
    newnode->next=NULL;
    printf(" Data in prevnode : %d\n",prevnode->data);
    printf("Data inserted %d",val);
    free(temp);

}

void search(int val){
    node* temp;
    node* prevnode;
    temp=head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    int i=0;
    while(temp != NULL){
        prevnode=temp;
        temp=temp->next;
        
        if(prevnode->data == val){
            printf("Value found %d\n",prevnode->data);
        }
    }
}

void total(){
    node* temp;
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    temp=head;
    int i=0;
    while(temp != NULL){
        temp=temp->next;
        i++;
    }
    printf("Total number of data in list %d",i);
    free(temp);
}
