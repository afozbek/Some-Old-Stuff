#include <stdio.h>

int main()
{
	int i,j,n;
	int yil,bos;
	
	printf("Number:\n");  //say�y� al�yoruz..
	scanf("%d",&n);
	
	bos=n-1;             //atamam�z laz�m bunu deneyerek de g�rebilirsiniz..
	yil=1;

	for(i=1;i<=n;i++)                //i�i�e for d�ng�s�..

	{
		for(j=1;j<=bos;j++)
		{
			printf(" ");
		}
		for(j=1;j<=yil;j++)
		{
			printf("*");
		}
		printf("\n");
		bos--;
		yil+=2; //burada +2 yerine +1 koysayd�k yan dik ��gen olurdu..
	}
	

	
	
}
