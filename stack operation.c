#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int*stack;
int top=-1;
int max;
bool isEmpty(){
	return top==-1;
}
bool isFull(){
	return top==max -1;
}
void push(){
	int value;
	if (isFull()) {
		printf("stack is full\n");
	} else {
		printf("stack is full\n");
		scanf("%d",&value);
		top=top+1;
		stack[top]=value;
		printf("%d pushed to stack\n",value);
	}
}
void pop(){
	if (isEmpty()){
		printf("stack is empty\n");
	}else{
		printf("%d is popped out\n",stack[top]);
		top=top-1;
	}
}
void display(){
	if (!isEmpty()) {
		printf("\n stack elements:\n");
		for(int i=0;i<=top;i++){
		    printf("stack[%d] = %d\n", i + 1, stack[i]);
	    }
    } else {
	    printf("stack is empty\n");
    }
}
void peek(){
	if (!isEmpty()){
		printf("Top element is: %d\n", stack[top]);
	}else{
		printf("stack is empty\n");
	}
}
int main(){
	int choice;
	printf("enter the maximum size of the stack;");
	scanf("%d" ,&max);
	stack=(int*)malloc(max * sizeof(int));
	if (stack == NULL){
		printf("memory allocation failed!\n");
		return 1;
	}
	do{
		printf("\n-------------------------\n");
		printf("1) PUSH\n");
		printf("2) POP\n");
		printf("3) PEEK\n");
		printf("4) DISPLAY\n");
		printf("5) QUIT\n");
		printf("\n-------------------------\n");
		printf("select your choice:");
		scanf("%d",&choice);
		switch (choice){
			case 1: push(); break;
	 	    case 2: pop(); break;
			case 3: peek(); break;
			case 4: display(); break;
			case 5:
				free(stack);
			   printf("existing program.good bye!\n");
			   exit(0);
			default:
				printf("invalid operation ! try again...\n");
		}	
    }while(1);
    return 0;
}