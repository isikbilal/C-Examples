// Klavyeden girilen bir kelimenin anagram olup olmadığını kontrol eden program.

// A program to check if a word entered from the keyboard is anagram.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (int argc, char *argv[]) 
{
   char *s1 = argv[1];
   char *s2 = argv[2];

   char temp;

   int i, j;
   int n  = strlen(s1);
   int n1 = strlen(s2);

	if( n != n1) 
	{    
      		printf("%s - %s anagram değildir! \n", s1, s2);
		exit(0);
  	}
   	
	for (i = 0; i < n; i++) 
	{
	     	 for (j = 0; j < n; j++) 
		{
			 if (s1[i] > s1[j]) 
			{
			    temp  = s1[i];
			    s1[i] = s1[j];
			    s1[j] = temp;
			 }
			 if (s2[i] > s2[j]) 
			{
			    temp  = s2[i];
			    s2[i] = s2[j];
			    s2[j] = temp;
			 }
	      }
   }

   for(i = 0; i<n; i++) 
   {
      if(s1[i] != s2[i]) 
	{    
       printf("Anagram değildir! \n");
	exit(0);
         
      }
   }

    printf("Girilen Değerler Anagramdır! \n");
exit(0);
   
   

   
   
}
