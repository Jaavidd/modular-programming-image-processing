#include <stdio.h>
#include "color.h"
#include "image.h"
#include "ppm.h"
int main () {

struct color *img;
int nbpixels;
struct ppm p;
p= PPM_new("merida.ppm");
nbpixels=PPM_nbPixels(p);
img=PPM_pixels(p);
struct ppm p1=PPM_new("forest.ppm");
	struct color *img1=PPM_pixels(p1);
	struct color tmp=C_new(img[0].red, img[0].green, img[0].blue);
	
/*
I_coef(img,nbpixels,0);
PPM_save(p,img,"coef.ppm");
I_negative (img,nbpixels);
PPM_save(p,img,"negative.ppm");
I_permute  (img,nbpixels);
PPM_save(p,img,"permute.ppm");
I_grayScale(img,nbpixels);
PPM_save(p,img,"grayscale.ppm");
I_threshold(img,nbpixels,1);
PPM_save(p,img,"threshold.ppm");  */
I_compose(img, img1, nbpixels, tmp);
PPM_save(p,img,"compose.ppm");
/*
I_gradient(img,gray,nbpixels);
PPM_save(p,img,"gradient.ppm");
*/


}

