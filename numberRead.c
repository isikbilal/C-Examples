//Kullanıcı tarafından girilecek olan bir sayıyı okuyan c programı (Örn: 173456 = Yüz yetmiş üç bin dört yüz elli altı)
//The c program that reads a number to be entered by the user (Ex: 173456 = One hundred and seventy three thousand four hundred and fifty six)

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sayi;
char birlerBasamagi[9][10]={"Bir","İki","Üç","Dört","Bes","Alti","Yedi","Sekiz","Dokuz"}; 
char  onlarBasamagi[9][10]={"On","Yirmi","Otuz","Kırk","Elli","Altmis","Yetmis","Seksan","Doksan"};
char yuzlerBasamagi[9][10]={"Yüz","İki Yüz","Üç Yüz","Dört Yüz","Bes Yüz","Alti Yüz","Yedi Yüz","Sekiz Yüz","Dokuz Yüz"};
void sart(int value,char basamak[9][10],int control){ 
	if(sayi>=value){
		//printf("%d",value);
		int indis=(sayi/value)-1;
		//printf("%d",indis);
		sayi=sayi%value;
		printf("%s ",basamak[indis]); 
		if(control==1) 
			printf("Milyon ");
		else if(control==2)
			printf("Bin ");
	}
}
int main(){
	printf("Sayı Giriniz");
	scanf("%d",&sayi);
	sart(100000000,yuzlerBasamagi,0);
	sart(10000000,onlarBasamagi,0);
	sart(1000000,birlerBasamagi,1);
	sart(100000,yuzlerBasamagi,0);
	sart(10000,onlarBasamagi,0);
	sart(1000,birlerBasamagi,2);
	sart(100,yuzlerBasamagi,0);
	sart(10,onlarBasamagi,0);
	sart(1,birlerBasamagi,0);
return 0;
}
