#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define boyut 400
int fstrlen(char dizi[]){
	int i;
	for(i=0;dizi[i]!='\0';i++);
	return i; 
}
void fters(char dizi[],int size){
	int i;
	for(i=size-1;i>=0;i--)
	printf("%c",dizi[i]);
}
void fterskelime(char dizi[],int size){// 2. �dev art�k nas�l anlamad�ysan !!!
	int j=1,i,a,ksize[boyut/2]={0},kelimesayisi=1;
	for(i=0;i<size;i++)if(dizi[i]==' ')kelimesayisi++;// Kelime say�s� bulundu.
	for(j=1;j<=kelimesayisi;j++){// Kelime say�s� j
		for(i=0;i<=size;i++){// Dizideki karakter diz[1] ...
			if(dizi[i]==' ' || dizi[i]=='\0'){// Kelimeler bo�luklarla veya NULL ile son buldu�u i�in if i�inde ' ' veya NULL 
				for(a=1;a<=j;a++)
				if(i!=ksize[j-a]){ // �ncekilerine e�it de�ilse atas�n. (ayn� de�erden 1den fazla olmas�n).
					ksize[j]=i;// atama .
					break; // 1. kelimeye 1den fazla de�er atamams� i�in.
				}
			}
		}
	}
	for(j=1;j<=kelimesayisi;j++){ // Kelime say�s� kadar tekrar eder.
		for(i=ksize[j]-1;i>=ksize[j-1];i--){ // 2 bo�luk aras�n� yazd�r�r.
			printf("%c",dizi[i]);
		}
		printf(" ");
	}
}
int main(){
	char dizi[boyut];
	printf("Enter a string:\t");
	gets(dizi);
	printf("\nThe size of the string: %d",fstrlen(dizi)); // Boyutu bulduk.
	printf("\nCumlesinin tersi:\t"); fters(dizi,fstrlen(dizi)); //Ters �evirme fonksiyonu.
	printf("\nCumlenin kelime kelime tersi:\t");fterskelime(dizi,fstrlen(dizi));
	
	
}
