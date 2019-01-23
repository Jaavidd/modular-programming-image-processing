
#include "image.h"

void I_print (struct color img[], int nb_pixels) {
	for (int i = 0; i < nb_pixels; i++) C_print (img[i]);
}
void I_coef (struct color img[], int nb_pixels, float coef) {
	for (int i = 0; i < nb_pixels; i++) img [i] = C_multiply (img[i], coef);
}
void I_negative (struct color img[], int nb_pixels) {
	for (int i = 0; i < nb_pixels; i++) img [i] = C_negative (img[i]);
}
void I_permute (struct color img[], int nb_pixels) {
	for (int i = 0; i < nb_pixels; i++) img [i] = C_permute (img[i]);
}
void I_grayScale(struct color img[],int nb_pixels) {
        for(int i=0; i < nb_pixels; i++) img[i]=C_grayScale (img[i]);
}
void I_threshold(struct color img[],int nb_pixels, int th) {
        for(int i=0; i<nb_pixels; i++) C_threshold (img[i],th);
}  

void I_compose(struct color img1[], struct color img2[], int nb_pixels,struct color target) {       
int i=0;
for(int i=0; i<nb_pixels; i++)
	{
		if(C_areEqual(img1[i], target))
		{
			img1[i].red=img2[i].red;
			img1[i].green=img2[i].green;
			img1[i].blue=img2[i].blue;
		}
	}             

}
void I_addColor(struct color* img, int nb_pixels, struct color c)
{
	for(int i=0; i<nb_pixels; i++)
	{
		img[i].red+=c.red;
		img[i].green+=c.green;
		img[i].blue+=c.blue;
	}
}
         
                // I COULDN'T DO THESE 3 FUNCTIONS,BUT I TRIED.           

/* void I_gradient(struct color img_in[],struct color img_out[],int nb_pixels) {
struct color grey=C_new(127,127,127);
int i=1;
for(i=1;i<nb_pixels;i++) {
img_out[i]=img_in[i]-img_in[i-1];
img_out[i]=img_out[i]+grey;
}

*/


void I_gradient(struct color* img_in, struct color* img_out, int nb_pixels)
{
        struct color gray=C_new(127, 127, 127),grayScale0, grayScale1;
	img_out[0]=gray;
        for(int i=1; i<nb_pixels; i++)
        {
                grayScale0=C_grayScale(img_in[i-1]);
                grayScale1=C_grayScale(img_in[i]);
                if(C_intensity(grayScale1)>=C_intensity(grayScale0))
                        img_out[i]=C_addCoef(gray, C_addCoef(grayScale1, grayScale0, -1), 0.5);
                else
                        img_out[i]=C_addCoef(gray, C_addCoef(grayScale0, grayScale1, -1), -0.5);
        }
}


struct color I_average(struct color* img, int nb_pixels, int fromhere, int nb_pixels_average)
{
	struct color ans={0, 0, 0};
	for(int i=0; i<nb_pixels_average; i++)
	{
		ans.red+=img[fromhere+i].red;
		ans.green+=img[fromhere+i].green;
		ans.blue+=img[fromhere+i].blue;
	}
	ans.red/=nb_pixels_average;
	ans.green/=nb_pixels_average;
	ans.blue/=nb_pixels_average;
	return ans;
}

void I_motionBlur(struct color* img, struct color* img_out, int nb_pixels, int strength)
{
	for(int i=0; i<nb_pixels-strength; i++)
		img_out[i]=I_average(img, nb_pixels, i, strength+1);
	for(int i=nb_pixels-strength; i<nb_pixels; i++)
		img_out[i]=I_average(img, nb_pixels, i, nb_pixels-i+1);
}
