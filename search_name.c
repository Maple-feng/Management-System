#include "fun.h"

void search_name(){
//int main(){
	FILE *fp;
	int num = 0;
	int i;
	int n, m;
	char a[20];
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
	printf("请输入查询信息的名字：（ctrl+z退出）\n");
	scanf("%s", a);
	//printf("%s\n", a);
	//n = strlen(a);
	/*printf("%d\n", n);*/
	while (q!= NULL){
		m = strcmp(q->name, a);
		if (m == 0){
			printf("查找成功\n");
			/*fseek(fp, -(4+n), SEEK_CUR);*/
			printf("%s\t%s\t%s\t%5.1f\t%5.1f\t%5.1f\t%5.1f\t%5.1f\n", q->id, q->name, q->sex, q->score1, q->score2, q->score3, q->score4, q->score5);
		}
		q = q->next;
	}
	free(q);
	free(s);
	free(head);
	free(tail);
	q = NULL;
	s = NULL;
	head = NULL;
	tail = NULL;
	system("pause");
	system("cls");
	return;
}