#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// this node include students information .
struct student{
	int studentNo;
	char name[100];
	int age;
	struct student* next;
};
// add a new student node function
void insertstudent(struct student** head, int studentNo, char* name, int age){
	struct student* newNode= (struct student*)malloc(sizeof(struct student));
	newNode->studentNo= studentNo;
	strcpy(newNode->name,name);
	newNode->age=age;
	newNode->next=*head;
	*head=newNode;
}
// write registered students info in screen
void writestudent(struct student* head){
	struct student* current =head;
	int counter =0;
	while (current != NULL){
		printf("student number: %d\n",current->studentNo);
		printf("student name:%s\n",current->name);
		printf("student age:%d\n",current->age);
		printf("\n");
		counter++;
		current=current->next;
	}
	printf("total number of student:%d\n",counter);
}
// search student name function
struct student* searchStudent(struct student* head, char* searchName){
	struct student* current=head;
	while (current !=NULL){
		if(strcmp(current->name,searchName)==0){
			return current; // the name was found
		}
		current= current->next;
	}
	return NULL; // no name
}
// delete node  function 
void deleteStudent(struct student** head, char* searchName){
	struct student* current= *head;
	struct student* index =NULL;
	
	while(current != NULL){
		if(strcmp(current->name, searchName)==0){
			if(index==NULL){
				*head= current->next; //delete first node
			} else{
				index->next= current ->next; // deleting the middle or last node	
			}
			free(current);
			return;
		}
		index=current;
		current=current->next;
	}
}

// write the most largest name of student on screen
void longName(struct student* head){
	struct student* current=head;
	int max=0;
	struct student* maxname=NULL;
	while(current != NULL){
		int lenght = strlen (current->name);
		if(lenght > max){
			max= lenght;
			maxname=current;
		}
		current= current->next;
	}
	if(maxname != NULL){
		printf("the longest name:%s (uzunluk:%d)\n",maxname->name,max);
	}else{
		printf("there is no found\n");
	}
}
int main(){
	struct student* studentlist=NULL;
	//add student information
	insertstudent(&studentlist,200,"gizem",20);
	insertstudent(&studentlist,201,"bilal",21);
	insertstudent(&studentlist,202,"ceylin",22);
	insertstudent(&studentlist,203,"osman",23);
	
	// print all student information on the screen and count it
	printf("all student information:\n");
	writestudent(studentlist);
	printf("\n");
	
	// search name
	char* searchName="gizem";
	struct student* searchstudent=searchStudent(studentlist, searchName);
	if(searchStudent != NULL){
		printf("%s named student found:\n",searchName);
		printf("student number:%d\n",searchstudent->studentNo);
		printf("student age:%d\n",searchstudent->age);
	}else{
		printf("%s named student no found\n",searchName);
	}
	printf("\n");
	// deleting student
	
	char* deletingname="bilal";
	printf("%s deleted\n",deletingname);
	deleteStudent(&studentlist,deletingname);
	
	//finding the student with the longest name
	longName(studentlist);
	// clear memory
	while(studentlist != NULL){
		struct student* temp=studentlist;
		studentlist= studentlist->next;
		free(temp);
	}
	return 0;
	
}













