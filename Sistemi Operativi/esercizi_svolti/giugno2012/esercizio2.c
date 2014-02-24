//funge!!!!
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
int n=argc-1, i, *numeri, w;
float x=0, j;
 FILE *fp;
 pid_t pid, padre;

   if(argc<2){
     printf("ERRORE!!!!!");
     exit(-1);
    }
  numeri=(int *)malloc(n*sizeof(int));
   for(i=0; i<n; i++){
     numeri[i]=atoi(argv[i+1]);
   }
   padre=getpid();
   fp=fopen("ciao.txt","w");
     for(i=0; i<n-1; i++){
         pid=fork();
        if(pid==0){
          switch(rand()%3){
           case 0: x=numeri[i]+numeri[i+1];
                      break;
           case 1: x=numeri[i]-numeri[i+1];
                     break;
           case 2: x=numeri[i]*numeri[i+1];
                     break;
           case 3: x=numeri[i]/numeri[i+1];
                      break;
           }
         fprintf(fp,"%.2f ",x);
         exit(i);
         } 
      if(pid<0){
       printf("ERRORE!!");
       exit(-1);
       }
      }
  fclose(fp);
   fp=fopen("ciao.txt","r");
  if(padre){  //se sono il padre attendo i figli
  for(i=0; i<n-1; i++){
    wait(&w);
   if(WIFEXITED(w)){
      fscanf(fp,"%f ",&j);
     printf("%.2f\n", j);
     }
   }
   }
  
  fclose(fp);
exit(EXIT_SUCCESS);
}
