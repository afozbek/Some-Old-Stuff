#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <conio.h>

int main()

{
	int a;
	int *ptr = NULL;
	
	a=10;
	ptr=&a;
	
	printf("%d\n",a);  //10luk TABANDA a..
	printf("%p\n",a);//16 l�k TABANDA a..
	printf("%d\n",ptr);//10 luk tabanda a'n�n adresi..
	printf("%p\n",ptr);//16 l�k tabanda a'n�n adresi..
	printf("%p\n",&a);//a n�n n adresi.. 
	printf("%p\n",&ptr);//16 l�k tabanda ptr n�n adresi..
	
	system("PAUSE");
	
}
