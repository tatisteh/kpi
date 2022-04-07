#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Варіант 27. Для однозв’язного списку груп (поля: title, amount_of_students) реалізувати функції:
//а) додавання елемента у хвіст списку;
//б) видалення елемента з голови списку;
//в) виведення елемента з найменшою кількістю студентів;
//г) надрукувати весь список, формат: “title: amount_of_students”;
//д) видалити весь список.

#define BUFFER_SIZE 1024
#define N 4

typedef struct {
	char * title;		
	int amountOfStudents;				
} group;

typedef struct {
	group * nodeValue;
	void * nextNode;
} listNode;

char * getString(char *);
int getIntValue(char *);
void freeGroup(group **);
void inputGroupInfo(group *);
void printGroupInfo(group *);
group * newGroup();
listNode * newNode();
void addNodeTale(listNode**);
void deleteNodeHead(listNode**);
int minimumAmount(listNode*);
void printList(listNode*);
int freeList(listNode**);


int main(int argc, char const *argv[])
{
	group * st = (group *) malloc(sizeof(group));

	if (st == NULL) {												//перевіряємо чи виділено память
		printf("out of memory error\n");
		exit(1);
	}

	//printf("sizeof group %d\n", sizeof(group));
	//printf("st in stack: %p, value of st in heap %p\n", &st, st);

	//inputGroupInfo(st);

	//printGroupInfo(st);
	
	//freeGroup(&st);
	//printf("st in stack: %p, value of st in heap %p\n", &st, st);

	listNode * headList = NULL;

	for(int i = 0; i < N; i++) {									//додаємо N вузлів в список
		addNodeTale(&headList);
	}

    printf("print list\n");
    printList(headList);

	printf("deleting node in head\n");
	deleteNodeHead(&headList);										//видаляємо елемент з голови списку

	printf("print list after deletion\n");
	printList(headList);

	printf("Group with minimal number of students is\n");			//шукаємо групу з найменшою кількістю студентів
	minimumAmount(headList);

	printf("%d nodes were deleted\n", freeList(&headList));			//видаляємо створені вузли, очищуємо список

	return 0;
}

int freeList(listNode** head) {
	int counter = 0;
	while(*head != NULL) {
		listNode* temp = *head;
		*head = (*head)->nextNode;
		free(temp);
		counter++;
	}
	return counter;
}

void printList(listNode* head) {
	while(head != NULL) {
		printGroupInfo(head->nodeValue);
		head = head->nextNode;
	}
}

int minimumAmount(listNode* head) {
    int min = INT_MAX;
  
    while (head != NULL) {
        if (min > head->nodeValue->amountOfStudents) {
            min = head->nodeValue->amountOfStudents;
            printGroupInfo(head->nodeValue);
        }
        head = head->nextNode;
    }
    return min;
}

void deleteNodeHead(listNode ** head){
	listNode* temp = (*head)->nextNode;
	free((*head)->nodeValue);
	free(*head);
	*head = temp;
}

void addNodeTale(listNode ** head) {
	listNode * result = newNode();
	result->nodeValue = newGroup();
	if (*head == NULL) {
		*head = result;
	} else {
		listNode * temp = *head;
		while (temp->nextNode != NULL) {
			temp = temp->nextNode;
		}
		temp->nextNode = result;
	}
}

group * newGroup() {
	group * result = (group *) malloc(sizeof(group));
	if (result == NULL) {												
		printf("out of memory error\n");
		exit(1);
	}

	inputGroupInfo(result);
	return result;
}

listNode * newNode() {
	listNode * result = (listNode *) malloc (sizeof(listNode));

	if (result == NULL) {												
		printf("out of memory error\n");
		exit(1);
	}

	result->nextNode = NULL;
	return result;
}

void inputGroupInfo(group * s) {
	s->title = getString("Input group title");		
	s->amountOfStudents = getIntValue("Input amount of students");	
}

char * getString(char * message) {
	char buffer[BUFFER_SIZE];
	char * result;
	printf("%s\n", message);
	fflush(stdout);
	scanf("%s", buffer);
	result = (char *) malloc(sizeof(char)*(strlen(buffer) + 1));
	strcpy(result, buffer);
	return result;
} 

int getIntValue(char * message){
	int result;
	printf("%s\n", message);
	fflush(stdout);
	scanf("%d", &result);
	return result;
}

void printGroupInfo(group * st){
	printf("--------------------GROUP--------------------\n");
	printf("\tTitle:\t\t\t%s\n", st->title);
	printf("\tAmount of students:\t%d\n", st->amountOfStudents);
	printf("---------------------------------------------\n");
}

void freeGroup(group ** st) {
	free((*st)->title);
	free(*st);
	*st = NULL;
}

