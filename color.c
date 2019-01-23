#include <stdio.h>
#include "color.h"

void C_print(struct color c) {
printf("(%d,%d,%d)",c.red,c.green,c.blue);
}

struct color C_new(int r,int g,int b) {
struct color temp={clamp(r),clamp(g),clamp(b)};
return temp;


}
int clamp(int n) {
if(n<0) { return 0; }
else if (n>255) { return 255; }
else { return n; }
}

struct color C_multiply(struct color c, float coef) {
if(coef>0) {
  c.red=clamp(c.red*coef);
  c.green=clamp(c.green*coef);
  c.blue=clamp(c.blue*coef);

}
return c;
}
struct color C_negative(struct color c) {

c.red=255-c.red;
c.green=255-c.green;
c.blue=255-c.blue;
return c;
}
struct color C_permute(struct color c) {
int temp=c.red;
c.red=c.green;
c.green=c.blue;
c.blue=temp;
return c;
}

int C_intensity(struct color c) {
	int ans;

	ans=(c.red+c.green+c.blue)/3;
	return ans;
}
struct color C_grayScale(struct color c) {
c.red=C_intensity(c);
c.green=c.red;
c.blue=c.red;
return c;

}

int C_threshold(struct color c,int th) {
if(C_intensity(c)>th) {
return 255;
}
else {
return 0;
}
}
int C_areEqual(struct color c1,struct color c2) {
if(c1.red==c2.red && c1.green==c2.green && c1.blue==c2.blue) {
return 1;
}
else {
return 0;
}
}
struct color C_addCoef(struct color c1,struct color c2,float coef) {
struct color ans;
ans.red=clamp(c1.red+coef*c2.red);
ans.green=clamp(c1.green+coef*c2.green);
ans.blue=clamp(c1.blue+coef*c2.blue);
return ans;
}




