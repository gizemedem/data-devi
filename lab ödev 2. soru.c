#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//listeye rastgele üretilmiş 100 sayı eklensin, girilen tüm sayıları büyükten küçüğe sıralayan ve ekrana basan c kodunu yazınız.

struct Node{
	int value;
	struct Node* next;    //next node address
};

//lets create add a new node function

void insert(struct Node** head,int value){
	struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
	newNode->value=value;
	newNode->next = *head; // add a new node beginning of list
	*head = newNode; // update the list head
}
// lets sort from big to small
void order(struct Node** head){
	struct Node* current, *point;
	int temp;
	
	if(*head == NULL){
		return; // if list is empty
	} else{
		for(current =*head; current !=NULL; current=current->next){
			for(point=current->next; point !=NULL; point->next){
				if(current->value < point->value){
					// change places data
					temp = current->value;
					current->value=point->value;
					point->value=temp;
				}
		}
	}
}
}
// write a function on screen
void writelist(struct Node* head){
	struct Node* current=head;
	while(current !=NULL){
		printf("%d",current->value);
		current=current->next;
	}
	printf("\n");
}
int main(){
	struct Node* list =NULL; // lets start empty list
	int i,number;
	srand(time(NULL));  //we need create random number 
	// we add numbers in list
	for(i=0; i<100; i++){
		number= rand()% 500; 
		insert(&list, number);
	}
	printf("random 100 numbers:\n");
	
	writelist(list); // you can see random numbers on screen.
	order(&list); // order big to small
	
	printf("selection sort big to small:\n");

	writelist(list);
	return 0;
}









