// Bu c programı bir dosyadan diğerine kopyalama işlemi yapar.
// Program 1 veya 2 argüman alabilir.
// Eğer 1 argüman alıyorsa; kopyalanacak dosya ismi, orjinal dosyanın sonuna "_kopyası" ifadesi eklenerek oluşturulacak ve 1. argümandaki dosyanın içeriği bu dosyaya aktarılacaktır. 
// Eğer 2 argüman alıyorsa; 1. argüman içeriği alınacak dosyanın adını, 2. argüman ise oluşturulacak dosyanın adı olacak ve yine 1. argümandaki dosyanın içeriği bu dosyaya aktarılacaktır.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[] ){
    FILE *kaynak,*hedef;
	char ch;
	if((kaynak=fopen(argv[1],"r"))==NULL){
		printf("Kaynak Dosya Acilamadi.");
		exit(1);
	}
	if(argc==3){
		if((hedef=fopen(argv[2],"w"))==NULL){
			printf("Hedef Dosya Açılmadı\n");
			exit(1);
		}
	}
	else if(argc==2){
		strcat(argv[1],"_copy");
		if((hedef=fopen(argv[1],"w"))==NULL){
			printf("Hedef Dosya Açılmadı\n");
			exit(1);
		}
	}
	else{
		printf("Parametre Hatasi");
		exit(1);
	}
	
	while((ch=fgetc(kaynak))!=EOF){ 
			fprintf(hedef,"%c",ch);
		}
	printf("Dosya Kopyalandı\n");
    return 0;
}
