#include <stdio.h>


void encryption(char *baseText, int shift);

int main()
{
  int shift = 8
 ;  
  char baseText[] = "WELL HELLO THERE SIR"; //Base text before encryption
  
  printf("Encryption:\n");
  encryption(baseText, shift); //Prints out the encrypted text
  
}

void encryption(char *baseText, int shift) //(Definition)
{
    int i = 0;
    int n;

        for(i = 0; baseText[i] != '0'; ++i) //Progress through each letter and performs 
        {
            n =  baseText[i];
            if(n >= 'a' && n <= 'z') //If the letter is lower-case
            {
                n = n + shift;
                
                if(n > 'z') //In case the shift moves the character past 'z'
                {
                    n = n - 'z' + 'a' - 1;  
                }
                else if(n < 'a') //In case the shift 
                {
                    n = n + 'z' - 'a' + 1;
                }
                
                baseText[i] = n;
            }
            else if(n >= 'A' && n <= 'Z') //If the letter is upper-case
            {
                n = n + shift;
                
                if(n > 'Z')
                {
                    n = n - 'Z' + 'A' - 1;  
                }
                else if(n < 'A')
                {
                    n = n + 'Z' - 'A' + 1;
                }
                baseText[i] = n;
            }
        }
        printf("%s", baseText);
        return;
    }
//This push is to test the commit
