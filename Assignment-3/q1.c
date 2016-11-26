#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
#include<math.h>
typedef struct {
  unsigned char red,green,blue;
} PPMPixel;

typedef struct {
  int x, y; 
  PPMPixel *data;
} PPMImage;

typedef struct {
  unsigned char gs;
} PPMPixelGS;


typedef struct {
  int x, y;
  PPMPixelGS *data;
} PPMImageGS;



#define RGB_COMPONENT_COLOR 255


unsigned char bi(unsigned char r1,unsigned char r2,unsigned char r3,unsigned char r4) 
{
   return (r1+r2+r3+r4)/4;
    
}

static PPMImage *readPPM(const char *filename)
{
  char buff[16];
  PPMImage *img;
  FILE *fp;
  int c, rgb_comp_color;
  //open PPM file for reading
  fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Unable to open file '%s'\n", filename);
    exit(1);
  }

  //read image format
  if (!fgets(buff, sizeof(buff), fp)) {
    perror(filename);
    exit(1);
  }

  //check the image format
  if (buff[0] != 'P' || buff[1] != '6') {
    fprintf(stderr, "Invalid image format (must be 'P6')\n");
    exit(1);
  }

  //alloc memory form image
  img = (PPMImage *)malloc(sizeof(PPMImage));
  if (!img) {
    fprintf(stderr, "Unable to allocate memory\n");
    exit(1);
  }

  //check for comments
  c = getc(fp);
  while (c == '#') {
    while (getc(fp) != '\n') ;
    c = getc(fp);
  }

  ungetc(c, fp);
  //read image size information
  if (fscanf(fp, "%d %d", &img->x, &img->y) != 2) {
    fprintf(stderr, "Invalid image size (error loading '%s')\n", filename);
    exit(1);
  }

  //read rgb component
  if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
    fprintf(stderr, "Invalid rgb component (error loading '%s')\n", filename);
    exit(1);
  }

  //check rgb component depth
  if (rgb_comp_color!= RGB_COMPONENT_COLOR) {
    fprintf(stderr, "'%s' does not have 8-bits components\n", filename);
    exit(1);
  }

  while (fgetc(fp) != '\n') ;
  //memory allocation for pixel data
  img->data = (PPMPixel*)malloc(img->x * img->y * sizeof(PPMPixel));

  if (!img) {
    fprintf(stderr, "Unable to allocate memory\n");
    exit(1);
  }

  //read pixel data from file
  if (fread(img->data, 3 * img->x, img->y, fp) != img->y) {
    fprintf(stderr, "Error loading image '%s'\n", filename);
    exit(1);
  }

  fclose(fp);
  return img;
}

void writePPM(const char *filename, PPMImage *img)
{
  FILE *fp;
  //open file for output
  fp = fopen(filename, "wb");
  if (!fp) {
    fprintf(stderr, "Unable to open file '%s'\n", filename);
    exit(1);
  }

  //write the header file
  //image format
  fprintf(fp, "P6\n");

  //comments


  //image size
  fprintf(fp, "%d %d\n",img->x,img->y);

  // rgb component depth
  fprintf(fp, "%d\n",255);

  // pixel data
  fwrite(img->data, 3 * img->x, img->y, fp);
  fclose(fp);
}

PPMImage* twistImage(PPMImage *im)
{
  int rows = im->x;
  int cols = im->y;
  int i,j;
  int tx = rows / 2, ty = cols / 2;
  float PI = 3.141527f;
  float DRAD = PI / 180.0f;
  PPMImage *im2 = (PPMImage *) malloc(sizeof(PPMImage));
  im2->x = rows;
  im2->y = cols;
  im2->data = (PPMPixel*) malloc(rows*cols*sizeof(PPMPixel));
  int r,g,b,idx;
  for(i=0;i<rows;i++)
  {
      for(j=0; j<cols; j++)
    {
      int index = j + i * cols;
      float radius = sqrtf((i - tx) * (i - tx) + (j - ty) * (j - ty));
      float theta = (radius / 2) * DRAD ;
      float x = cos(theta) * (i - tx) - sin(theta) * (j - ty) + tx;
      float y = sin(theta) * (i - tx) + cos(theta) * (j - ty) + ty;
      
      if((x < 0 || y < 0 || x >= rows || y >= cols  ))
      {
          x = 0;
          y = 0;   
        }
        
        
        
        int x1= ceil(x);
        int x2= floor(x);
        int y1= ceil(y);
        int y2= floor(y);
        int index1 = (int)( x1 * cols + y1);
        int index2 = (int)( x1 * cols + y2);
        int index3 = (int)( x2 * cols + y1);
        int index4 = (int)( x2 * cols + y2);
        PPMPixel *t1 = im->data + index1;
        PPMPixel *t2 = im->data + index2;
        PPMPixel *t3 = im->data + index3;
        PPMPixel *t4 = im->data + index4;
        PPMPixel *tmp2 = im2->data + index;
        
        tmp2->red = bi(t1->red,t2->red,t3->red,t4->red);
        tmp2->green = bi(t1->green,t2->green,t3->green,t4->green);
        tmp2->blue = bi(t1->blue,t2->blue,t3->blue,t4->blue);
    } 
  }
  return im2;
}
int main(int argc, char* argv[]){
  if(argc<2)
    printf("Enter filename\n");
  char* filename=argv[1];

  PPMImage *im;
 // clock_t start, end;

  im = readPPM(filename);

  //start=clock();
  float start=omp_get_wtime();
  PPMImage *im2 = twistImage(im);
  float end=omp_get_wtime(); 
  //end=clock();
    
  printf("Time: %0.10f\n", (end-start));
  /* printf("Time: %0.10f\n", (stop_omp-start_omp) ); */
  writePPM("q1.ppm",im2);
}

