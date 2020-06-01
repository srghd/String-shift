//Serge Haddad
//CSUN 2019

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 

struct node{
	struct node * prev;
	struct node * next;
	char origc;
	char shifted;
};
struct node *head = NULL;
struct node *last = NULL;
struct node *current =NULL; 

bool isEmpty() {
   return head == NULL;
}

//display the list from first to last
void displayForward() {

   struct node *ptr = last;
	
   while(ptr != NULL) {    
	
      //print data
      printf("%c",ptr->shifted);
		
      //move to next item
      ptr = ptr ->prev;
      
   }
	
}
//display the list in from last to first
void displayBackwards() {

   struct node *ptr = head;
	
   while(ptr != NULL) {        
      printf("%c",ptr->shifted);
      ptr = ptr->next;
   }
	
  
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}

void insertfirst(char origc, char shifted)
{
	struct node *link =(struct node*) malloc(sizeof(struct node));
	link-> origc = origc;
	link-> shifted = shifted;
	if(isEmpty()){
		last = link;
	} 
	else{
		head -> prev = link;
	}
	link -> next = head;
	head = link;
}

int main() {
    int c;
    char  *name;
    size_t namesize = 32;
    name = (char *)malloc(namesize * sizeof(char));
    int limit=0;
	printf("Enter a string:");
	getline(&name,&namesize,stdin);
	
	printf("enter a number between -10,-5 or 0,15:\n");
 	scanf("%d", &c);
	while ( (c > 15) || (c<0 && c>-5) || (c<-10))
	{
		printf("the number you entered is invalid. try again\n");
		scanf("%d", &c);
	}


while(limit<strlen(name)){
    char temp=name[limit];
    char shifting;
    if(temp>='a' && temp <='z'){
    	if (c>=0){
        	shifting =((temp - 'a') + c) % 26 + 'a';
        	insertfirst(temp,shifting);
        	limit++;}
        else{
        	shifting =((temp - 'a') + (26 + c)) % 26 + 'a';
        	insertfirst(temp,shifting);
        	limit++;
        }
    }
    else if (temp>='A' && temp <='Z'){
        if (c>=0){
            shifting =((temp - 'A') + c) % 26 + 'A';
            insertfirst(temp,shifting);
            limit++;}
        else{
            shifting =((temp - 'A') + (26 + c)) % 26 + 'A';
        	insertfirst(temp,shifting);
        	limit++;
        }
    }
    else {
        shifting=temp;
        insertfirst(temp,shifting);
        limit++;
    }
}
printf("%s\n",name);
displayForward();
displayBackwards();

return 0;
}

