#include "fun.h"

void student_delete(){
	FILE *fp;
	FILE *fp1;
	char a[10];
	int m, n;
	pstu head = (pstu)malloc(sizeof(stu));
	head->next = NULL;
	pstu q = head;
	pstu tail = head;
	pstu cur = head;
	pstu s = (pstu)malloc(sizeof(stu));
	pstu pre;
	memset(s, 0, sizeof(stu));

	fp = fopen("student.txt","r");
	if (NULL == fp){
		perror("open file fail");
		return -1;
	}
	while (fscanf(fp, "%s\t%s\t%s\t%f\t%f\t%f\t%f\t%f", &s->id, s->name, s->sex, &s->score1, &s->score2, &s->score3, &s->score4, &s->score5) > 0){
		s->next = tail->next;
		tail->next = s;
		tail = s;
		s = (pstu)malloc(sizeof(stu));
		memset(s, 0, sizeof(stu));
	}
	fp1= fopen("student.txt", "w+");
	if (NULL == fp1){
		perror("open file fail");
		return -1;
	}
	printf("请输入要删除的学号\t（ctrl+z退出）\n");
	printf("例如：1001\n");
	scanf("%s", a);
	n = atoi(a);
	pre = head;
	while (cur != NULL){
		m = atoi(cur->id);
		if (m == n){
			pre->next = cur->next;
		}
		pre = cur;
		cur = cur->next;
	}
	fclose(fp);
	q = head->next;
	while (q != NULL){
		fprintf(fp1,"%s\t%s\t%s\t%5.1f\t%5.1f\t%5.1f\t%5.1f\t%5.1f\n", q->id, q->name, q->sex, q->score1, q->score2, q->score3, q->score4, q->score5);
		q = q->next;
	}
	free(q);
	free(s);
	free(head); 
	free(cur);
	q = NULL;
	s = NULL;
	head = NULL;
	tail = NULL;
	cur = NULL;
	fclose(fp1);
	system("pause");
	system("cls");
	return;
}