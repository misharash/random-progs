#include <stdio.h>
#include <time.h>
#include <stdlib.h>
char * helps="Randgen (Random Generator) 1.1.1 by MishaRash (GCC 4 version), 2015-09-15.\nUsage:\n-b\t boolean value (True/False), default action\n-i <N>\t integer in range [0;N]\n-i <M> <N>\t integer in range [M;N]\n-f \t float in range [0;1]\n-f <N> \t float in range [0;N]\n-f <M> <N> \t float in range [M;N]\n-s <list of variants>\t select random variant from list.\n-h\t print help\n";
//version 1.0 was 2015-03-24
//version 1.1 was 2015-05-06
//in 1.1.1 better init value for random generation (CPU clock instead of seconds time)
//in 1.1 I added float number generation and two limits for integer 
//and fixed a problem with wrong check of number of arguments
int boolrand(int num,int argc, char * argv[]) {
  if (num%2)
    printf("True\n");
  else
    printf("False\n");
  return 0;
}
int intrand(int num,int argc, char * argv[]) {
  if (argc>2) {
    int k=0;
    sscanf(argv[2],"%d",&k);
    if (argc>3) {
        int l;
        sscanf(argv[3],"%d",&l);
        printf("%d\n",k+num%(l-k+1));
    }
    else
        printf("%d\n",num%(k+1));
  }
  else
    printf("Too few arguments.\n%s",helps);
  return 0;
}
int switchrand(int num,int argc, char * argv[]) {
  if (argc>2)
    printf("%s\n",argv[2+num%(argc-2)]);
  else
    printf("Too few arguments.\n%s",helps);
  return 0;
}
int floatrand(int num,int argc, char * argv[]) {
  float num2=((float) num)/RAND_MAX;
  if (argc>2) {
    float k;
    sscanf(argv[2],"%f",&k);
    if (argc>3) {
        float l;
        sscanf(argv[3],"%f",&l);
        printf("%f\n",k+num2*(l-k));
    }
    else
        printf("%f\n",num2*k);
  }
  else
    printf("%f\n",num2);
  return 0;
}
int main(int argc, char * argv[]) {
  srand(clock());
  int num=rand();
  if (argc==1) {
    boolrand(num,argc,argv);
  }
  else {
    if (!strcmp(argv[1],"-b"))
      boolrand(num,argc,argv);
    else {
      if (!strcmp(argv[1],"-i"))
        intrand(num,argc,argv);
      else {
        if (!strcmp(argv[1],"-s"))
          switchrand(num,argc,argv);
        else {
          if (!strcmp(argv[1],"-f"))
            floatrand(num,argc,argv);
          else {
            if (!strcmp(argv[1],"-h"))
              printf("%s",helps);
            else
              printf("Unrecognized flag.\n%s",helps);
          }
        }
      }
    }
  }
  return 0;
}
