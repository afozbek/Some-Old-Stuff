	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define boyut 400

int f0(char dizi[]) //A.Furkan �zbek -1306160017
	{  
	int i;
	for(i=0;dizi[i]!='\0';i++);
	return i; 
	}
void f1(char dizi[],int size)	// 1. �dev
	{  
	int i;
	for(i=size-1;i>=0;i--) // size-1 dememizin nedeni dizinin size'� NULL olur...
	printf("%c",dizi[i]);
	}
void f2(char dizi[],int size)	// 2. �dev....
	{

	int i,k,j,l=0;
	k = strlen(dizi); //k ya karakter boyutu tan�mland�...

	for(i=0;i<=k;i++) //d�ng�..
	{
		if(dizi[i] == ' ')
		{	
			j=i;                    
			for(j=i-1;j>=l;j--)			//d�ng� bo�lu�a geldi�inde bo�luktan bir �nceden ba�lar ba�a kadar yazar..
			printf("%c",dizi[j]);   
			l=i;						//bo�lu�un oldu�u yer integer olarak l'e atan�r..
		}
		if(dizi[i] == '\0')				//d�ng� sona yani kelimeden sonraki karaktere gelirse oradan ba�lar..
		{
			printf(" ");		//ilk bo�luk atar...bu iki kelime yazd���nda hata olmamas� i�in..
			j=i;			
			for(j=i-1;j>=l;j--)		//kar���kl�k olmas�n diye �nceki yazd���m�z bo�lu�a kadar 
			printf("%c",dizi[j]);
		}
	}

}
void f3(char c[])	//3. �dev.....
	{		
	char a[33] = {'a','b','c','�','d','e','f','g','�','h','�','i','j','k','l','m','n','o','�','p','r','s','�','t','u','�','v','y','z','q','w','x'};
	char A[33] = {'A','B','C','�','D','E','F','G','�','H','I','�','J','K','L','M','N','O','�','P','R','S','�','T','U','�','V','Y','Z','Q','W','X' };	
	char s[33] ={ '0','1','2','3','4','5','6','7','8','9',' ','.'};
	int size = strlen(c);
	int i,kelimesayisi=1,furkan=0,j;
	for(i=0;i<size;i++)if(c[i]==' ')kelimesayisi++;//kelime i�in...
	


	for(i=0;i<size;i++){
		for(j=0;j<33;j++){
			if	(c[i] == a[j] || c[i] == A[j] || c[i] == s[j] )
				furkan++;
			}
	}	
	printf("\nCharacters:%d",size);
	printf("\n----------------------------------------------------------------");
	printf("\nWords:%d",kelimesayisi);
	printf("\n----------------------------------------------------------------");
	printf(	"\nSpecial Char:%d", size - furkan );
	
	}
void f4(char cumle[])  //4. �dev...
	{
	char harfler[33]={'a','b','c','�','d','e','f','g','�','h','�','i','j','k','l','m','n','o','�','p','r','s','�','t','u','�','v','y','z','q','w','x'};
	int sayac[26]={0},i,j;
	int b = strlen(cumle);
	strlwr(cumle);    // b�y�k harfleri k���lten fonksiyon...
	printf("\n");
	for(i=0; i<b;i++ )//c�mle boyutu
	{
		for(j=0; j<26;j++)
		if(cumle[i]==harfler[j])
		{
			sayac[j]++;
		}
	}
	for(i=0; i<26;i++)
	{
		if(sayac[i]==0)
		{
			continue;//e�er bir harften yoksa onu yazd�rmaz...
		}
		
		printf("%c:%d ",harfler[i],sayac[i]);
		
	}
	

}
void f5(char dizi[]) //5...�dev..
	{
	int i,j,k;

	int y = 1; 
	int bosluk[boyut / 2] = { 0 }, kelime[boyut / 2] = { 0 }; int atama[boyut / 2] = { 0 }; //3 farkl� dizi olu�turduk ana diziden farkl�..
	for (int i = 0; i <= strlen(dizi); i++) {
		if (dizi[i] == ' ' || dizi[i] == '\0') {
			bosluk[y] = i; //dizimizdeki bo�luklar� bir diziye kaydettik int olarak. dizi[6] da bo�luk varsa bo�luk[1]=6 gibi..
			y++; //sonra art�rd�k..
			kelime[y - 1] = bosluk[y - 1] - bosluk[y - 2];//kelimelerin uzunlu�unu kaydettik ilerde kullan�caz..
		} 
	}
	for ( i = 0; i < y; i++) {
		for ( j = 1; j < y; j++) {
			if (kelime[i] > kelime[j]) { //kelimelerin uzunluklar�na g�re puan al�yorlar en uzun olan en fazla puan� olucak.
				atama[i]++;
			
			}
		}
	}
		for (int i = y; i >= 0; i--) { //bo�lu�umuz+'\0' �m�z�n oldu�u �eyleri kaydettik y'de burdan ba�lad�k 0 a kadar indik..
			for (int j = 1; j <= y; j++) {
				if (atama[j] == i) { //ge�ici bir yere atad�k belle�imizde kaybolmas�n diye..
					for ( k = bosluk[j - 1]; k <= bosluk[j]; k++)
						printf("%c", dizi[k]);

				}
			}
		}
	}
void f6(char cumle[])   //6..arayay�m m�?
	{
	char degisim2,harfler[33]={'a','b','c','�','d','e','f','g','�','h','�','i','j','k','l','m','n','o','�','p','r','s','�','t','u','�','v','y','z','q','w','x'};
	int sayac[33]={0},i,j,degisim1;
	
	strlwr(cumle);    // b�y�k harfleri k���lten fonksiyon..
	for(i=0; i<strlen(cumle);i++ )//c�mle boyutu
	{
		for(j=0; j<33;j++)
		if(cumle[i]==harfler[j])
		{
			sayac[j]++;
		}
	}
	for(i=0; i<33; i++) 
	
	{
		for(j=0;j<33-i;j++)//-i
		{
			if(sayac[j]<sayac[j+1])
			{
				degisim1=sayac[j];		//B�y�k olanlar�n yerleri de�i�iyor....(Sayi olanlarin)
				sayac[j]=sayac[j+1];
				sayac[j+1]=degisim1;
				
				degisim2=harfler[j];	//Ayni sekilde harflerin yerleri degisiyor...
				harfler[j]=harfler[j+1];
				harfler[j+1]=degisim2;
	
			}
		}
	}
	
	for(i=0;sayac[i]!=0;i++)
	{
	
		printf("%c",harfler[i]);
		if(sayac[i]!=sayac[i+1])
		{
			printf(" ");
		}
	}

}

int main()			//A.Furkan �ZBEK  -  1306160017
{
	char dizi[boyut];
	printf("Enter a string:\t");
	gets(dizi);
	printf("\nThe size of the string: %d",f0(dizi)); // Boyutu bulduk.
	printf("\n----------------------------------------------------------------");
	printf("\nThe rewerse of the sentence:"); f1(dizi,f0(dizi)); //Ters �evirme fonksiyonu.
	printf("\n----------------------------------------------------------------");
	printf("\nThe rewerse of the word by word:");f2(dizi,f0(dizi));
	printf("\n----------------------------------------------------------------");f3(dizi);
	printf("\n----------------------------------------------------------------");f4(dizi);
	printf("\n----------------------------------------------------------------\nOrder words by length:");f5(dizi);
	printf("\n-----------------------------------------------------------------\nOrder characters by repetition:");f6(dizi);
	printf("\n\nGood bye:)");
	return 0;
	
}
