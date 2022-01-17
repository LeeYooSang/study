#include <stdio.h>
int main(void){
	typedef struct {
		char name[10];
		int age;
	}Human;

	Human human[3];
	for(int i=0;i<3;i++){
		scanf("%s %d",&human[i].name,&human[i].age);
	}
	for(int i=0;i<3;i++){
		printf("Name:%s, Age:%d\n",human[i].name,human[i].age);
	};
	return 0;	
}
