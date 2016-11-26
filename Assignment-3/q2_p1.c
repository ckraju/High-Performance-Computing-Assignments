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
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int max(int a, int b)
{
  if(a > b) return a;
  return b;
}
int min(int a, int b)
{
  if(a < b) return a;
  return b;
}

PPMImage* twistImage(PPMImage *im, int n)
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
  int x = (2 * n  + 1) * (2 * n + 1) + 3;
  int r,g,b;
  omp_set_num_threads(4);
  #pragma omp parallel for shared(im, im2, rows, cols) private(i, j)
  for(i=0;i<rows;i++)
  {
    for(j=0; j<cols; j++)
    {
      int tmp1[150], tmp2[150], tmp3[150];
      int index = j + i * cols;
      int x1 = i - n;
      int y1 = j - n;
      int x2 = i + n;
      int y2 = j + n;
      int ni, nj, k = 0;
      for(ni = x1; ni <= x2; ni++)
      {
        for(nj = y1; nj <= y2; nj++)
        {
          int ii, jj;
          ii = ni; jj = nj;
          if(ii < 0) ii = 0;
          if(jj < 0) jj = 0;
          if(ii >= rows) ii = rows - 1;
          if(jj >= cols) jj = cols - 1;
          int in = ii * cols + jj;
          PPMPixel *t = im->data + in;
          tmp1[k] = t->red;
          tmp2[k] = t->green;
          tmp3[k++] = t->blue;
        }
      }
      qsort(tmp1, k, sizeof(int), cmpfunc);
      int med1 = tmp1[k / 2];
      qsort(tmp3, k, sizeof(int), cmpfunc);
      int med3 = tmp3[k / 2];
      qsort(tmp2, k, sizeof(int), cmpfunc);
      int med2 = tmp2[k / 2];
      PPMPixel *c = im2->data + index;
      c->red = med1;
      c->green = med2;
      c->blue = med3;
    } 
  }
  return im2;
}
int main(int argc, char* argv[]){
  if(argc<2)
    printf("Enter filename\n");
  char* filename=argv[1];
  char* tmp=argv[2];
  int num=atoi(tmp);
  

  PPMImage *im;
 // clock_t start, end;

  im = readPPM(filename);

  //start=clock();
  float start=omp_get_wtime();
  PPMImage *im2 = twistImage(im, num);
  float end=omp_get_wtime(); 
  //end=clock();
    
  printf("Time: %0.10f\n", (end-start));
  /* printf("Time: %0.10f\n", (stop_omp-start_omp) ); */
  char* fn="q2p1.ppm";
  writePPM(fn,im2);
}

