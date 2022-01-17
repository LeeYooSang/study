#include <stdio.h>

void rotateLeft(int* pa,int* pb,int* pc){
	int a;
	a = *pa;
	*pa=*pb;
	*pb=*pc;
	*pc=a;
	return;
}
void rotateRight(int* pa, int* pb, int* pc){
	int a;
	a = *pc;
	*pc=*pb;
	*pb=*pa;
	*pa=a;
	return;
}

int main(void){
	int a,b,c,num;
	a=10;
	b=20;
	c=30;
	printf("%d %d %d\n",a,b,c);
	while(1){
		scanf("%d",&num);
		if(num!=1 && num!=2)
		{
			break;
		}
		else if(num==1){
			rotateLeft(&a,&b,&c);
			printf("%d %d %d\n",a,b,c);
		}
		else if(num==2){
			rotateRight(&a,&b,&c);
			printf("%d %d %d\n",a,b,c);
		}
	}
}
