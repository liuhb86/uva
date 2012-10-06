

#include<stdio.h>
#include<string.h>

#define MAXN 30
char Com1[50], Com2[50];
int N, A, B;

struct ss {
   int stack[MAXN];
   int index;
   int add;
   int pos;
}Block[MAXN];

void Ini() {
   int i;
   for(i = 0; i<N; i++) {
	   Block[i].stack[0] = i;
	   Block[i].add = i;
	   Block[i].pos = 0;
       Block[i].index = 1;
   }
}

void Move_onto(int a) {
   int i, j, k;
   int add = Block[a].add;
   int in = Block[add].index;
   int p  = Block[a].pos;
   for(i = in-1; i>p; i--) {
       j = Block[add].stack[i];
	   k = Block[j].index;
	   Block[j].add = j;
	   Block[j].stack[k++] = j;
	   Block[j].pos = k-1;
	   Block[j].index++;
	   Block[add].index--;
   }

}

void Set() {
    int ada, adb, in;
	ada = Block[A].add;
	adb = Block[B].add;
	in = Block[adb].index;
	Block[ada].index--;
	Block[adb].stack[in++] = A;
	Block[adb].index++;
	Block[A].add = adb;
	Block[A].pos = Block[adb].index-1;
}

void Pile() {
     int posa, ada, adb, inda, indb;
	 int i, j;
	 ada  =  Block[A].add;
	 adb  =  Block[B].add;
	 posa =  Block[A].pos;
	 inda =  Block[ada].index;
	 indb =  Block[adb].index;
     for(i = posa; i<inda; i ++){
	     j = Block[ada].stack[i];
		 Block[adb].stack[indb++] = j;
		 Block[ada].index--;
		 Block[j].pos = indb-1;
		 Block[j].add = adb;
		 Block[adb].index++;
	 }
}

void Print() {
   int i, j, index;
   for(i = 0; i<N; i++) {
      index = Block[i].index;
	  printf("%d:",i);
	  for(j = 0; j<index; j++)
		  printf(" %d",Block[i].stack[j]);
	  printf("\n");
   }
}

void Cal() {
	while(1) {
	   scanf("%s",Com1);
	   if(!strcmp(Com1,"quit")) break;
	   scanf("%d%s%d",&A,Com2,&B);
	   if(A == B || (Block[A].add == Block[B].add))
		   continue;
	   if(!strcmp(Com2,"onto"))
		   Move_onto(B);
	   if(!strcmp(Com1,"move")){
		   Move_onto(A);
		   Set();
		   continue;
	   }
	   if(!strcmp(Com1,"pile")){ 
    	   Pile();

	   }
	}
    
}

int main() {

	while(scanf("%d",&N) == 1) {
      Ini();
	  Cal();
      Print();
	}
            
}
