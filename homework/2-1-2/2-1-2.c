#include <stdio.h>
typedef struct
{
	int xpos;
	int ypos;
}Point;

Point getScale2xPoint(const Point* p){
	Point pt;
	pt.xpos = p->xpos;
	pt.ypos = p->ypos;
	pt.xpos *= 2;
	pt.ypos *= 2;
	return pt;
}

void swapPoints(Point* p1, Point* p2){
	Point pt;
	pt = *p1;
	*p1 = *p2;
	*p2 = pt;
	return;
}

int main(void){
	Point point[2];
	scanf("%d %d",&point[0].xpos,&point[0].ypos);
	point[1] = getScale2xPoint(&point[0]);
	printf("Calling getScale2xPoint()\n");
	printf("p1 : %d %d\n",point[0].xpos,point[0].ypos);
	printf("p2 : %d %d\n",point[1].xpos,point[1].ypos);
	swapPoints(&point[0],&point[1]);
	printf("Calling swapPoint()\n");
	printf("p1 : %d %d\n",point[0].xpos,point[0].ypos);
	printf("p2 : %d %d\n",point[1].xpos,point[1].ypos);
}
	
