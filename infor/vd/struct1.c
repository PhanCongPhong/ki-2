#include <stdio.h>
struct point {
	int x;
	int y;
};
int main()
{
	struct point pt1;
	pt1.x=1;
    pt1.y=2;
    struct point pt2={3,4};
    struct point pt3=
    {
    	y :5,x : 3
    };
    printf("%d %d",pt2.x,pt2.y );
	return 0;
}