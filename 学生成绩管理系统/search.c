#include "fun.h"

void search(){
//int main(){
	FILE *fp;
	int num = 0;
	int i;
	pstu head = (pstu)malloc(sizeof(stu));
	head->next = NULL;
	pstu cur = head;
	pstu tail = head;
	pstu s = (pstu)malloc(sizeof(stu));
	pstu q;
	memset(s, 0, sizeof(stu));

	fp = fopen("student.txt", "r+");
	if (NULL == fp){
		perror("open file fail");
		return -1;
	}
	while (fscanf(fp, "%s\t%s\t%s\t%f\t%f\t%f\t%f\t%f", &s->id, s->name, s->sex, &s->score1, &s->score2, &s->score3, &s->score4, &s->score5)>0){
		num++;
		s->next = tail->next;
		tail->next = s;
		tail = s;
		s = (pstu)malloc(sizeof(stu));
		memset(s, 0, sizeof(stu));
	}
	q = head->next;

	fseek(fp, 0, SEEK_SET);
	while (q != NULL){
		printf("%s\t%s\t%s\t%5.1f\t%5.1f\t%5.1f\t%5.1f\t%5.1f\n", q->id, q->name, q->sex, q->score1, q->score2, q->score3, q->score4, q->score5);
		q = q->next;
	}
	free(q);
	free(s);
	free(head);
	q = NULL;
	s = NULL;
	head = NULL;
	tail = NULL;
	system("pause");
	system("cls");
	return;
}