
#define _CRT_SECURE_NO_WARNINGS
#define MAXWORD 80

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct element {
	char word[MAXWORD];
	int count;
} element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// 초기화 함수
ListNode* init(ListNode* head)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL) exit(1);
	head->link = NULL;
	return head;
}
//헤더 노드를 이용한 삽입 함수
void insert_node(ListNode* head, char* key) {
	int cmp;
	ListNode* prev, * ptr;
	//아래를 완성하시오
	/*prev = (ListNode*)malloc(sizeof(ListNode));
	ptr = (ListNode*)malloc(sizeof(ListNode));*/
	prev = head;
	ptr = head->link;
	
	ListNode* new_node = new ListNode;
	strcpy(new_node->data.word, key);
	new_node->data.count = 1;
	new_node->link = NULL;
	while (ptr != NULL) {
		cmp = strcmp(ptr->data.word, key);
		if (cmp < 0) {
			
			prev = ptr;
			ptr = ptr->link;
			
	
		}
		else if (cmp == 0) {
			ptr->data.count++;
			return;
			
		}
		else{
	
			new_node->link = ptr->link;
			ptr->link = new_node;
			return;
			
		}
	}
	if (ptr == NULL) {
		prev->link = new_node;
	}

}
//헤더 노드를 이용한 삭제 함수
void delete_node(ListNode* head, char* key)
{
	int cmp;
	ListNode* prev, * ptr, * removed;

	prev = head;
	ptr = head->link;
	while (ptr != NULL) {
		cmp = strcmp(ptr->data.word, key);
		if (cmp < 0) {
			prev = ptr;
			ptr = ptr->link;
		}
		else if (cmp == 0) {
			removed = ptr;
			prev->link = ptr->link;
			//free(removed);
			delete removed;
			return;
		}
		else
			return;
	}
}
void sort_print(ListNode* head) {
	ListNode* ptr = head->link;

	printf("단어 \t회수\n");
	while (ptr) {
		printf("%s \t%d\n", ptr->data.word, ptr->data.count);
		ptr = ptr->link;
	}
}
int main()
{
	FILE* fp;
	char word[MAXWORD];
	ListNode* head = NULL;

	head = init(head);

	//fopen_s(&fp, "data.txt", "r");
	fp = fopen("data.txt", "r");
	//while (fscanf_s(fp, "%s", word, sizeof(word)) != EOF) {
	while (fscanf(fp, "%s", word) != EOF) {
		printf("%s ", word);
		insert_node(head, word);
	}
	printf("\n");
	fclose(fp);

	sort_print(head);

	printf("삭제할 단어(종료:0): ");
	scanf_s("%s", word, sizeof(word));
	while (word[0] != '0') {
		delete_node(head, word);
		sort_print(head);
		printf("삭제할 단어: ");
		//scanf_s("%s", word, sizeof(word));
		scanf("%s", word);
	}

	return 0;
}
/* 실제 출력 결과
* 내가 당신을 사랑하는 것은 까닭이 없는 것이 아닙니다 다른 사람들은 나의 홍안만을 사랑하지마는 당신은 나의 백발도 사랑하는 까닭입니다
단어    회수
내가    1
까닭입니다      1
나의    1
나의    1
것이    1
까닭이  1
것은    1
당신을  1
당신은  1
다른    1
사랑하는        2
백발도  1
사람들은        1
없는    1
사랑하지마는    1
아닙니다        1
홍안만을        1
삭제할 단어(종료:0): 없는
단어    회수
내가    1
까닭입니다      1
나의    1
나의    1
것이    1
까닭이  1
것은    1
당신을  1
당신은  1
다른    1
사랑하는        2
백발도  1
사람들은        1
사랑하지마는    1
아닙니다        1
홍안만을        1
삭제할 단어: 0

C:\Users\morat\source\repos\hongPractice\Debug\hongPractice.exe (process 127292) exited with code 0.
Press any key to close this window . . .


*/
/* 예시 출력 결과
내가 당신을 사랑하는 것은 까닭이 없는 것이 아닙니다 다른 사람들은 나의 홍안만을
사랑하지마는 당신은 나의 백발도 사랑하는 까닭입니다
단어    회수
것은    1
것이    1
까닭이  1
까닭입니다      1
나의    2
내가    1
다른    1
당신은  1
당신을  1
백발도  1
사람들은        1
사랑하는        2
사랑하지마는    1
아닙니다        1
없는    1
홍안만을        1
삭제할 단어(종료:0): 없는
단어    회수
것은    1
것이    1
까닭이  1
까닭입니다      1
나의    2
내가    1
다른    1
당신은  1
당신을  1
백발도  1
사람들은        1
사랑하는        2
사랑하지마는    1
아닙니다        1
홍안만을        1
삭제할 단어: 0
계속하려면 아무 키나 누르십시오 . . .
*/