#include <stdio.h>

/*INSTRUCTIONS:
    - Please enter a character in 'Option.txt' between a and f to select an option from below
*/


void encryptRotKey(void); //File 1 = Encryption of Rotation Cipher with a Key
void decryptRotKey(void); //File 2 = Decryption of Rotation Cipher with a Key
void encryptSubKey(void); //File 3 = Encryption of Substitution Cipher with a Key
void decryptSubKey(void); //File 4 = Decryption of Substitution Cipher with a Key
void decryptRotNoKey(void); //File 5 = Decryption of Rotation Cipher without a Key
void decryptRotNoKey(void); //File 6 = Decryption of Substitution Cipher without a Key

int main()
{
    FILE *Option;
    
    Option = fopen("Option.txt", "r")
    
    switch(letter)
    {
        case 'a':
            //Open first file
            break;
        case 'b':
            //Open second file
            break;
        case 'c':
            //Open third file
            break;
        case 'd':
            //Open fourth file
            break;
        case 'e':
            //Open fifth file
            break;
        case 'f':
            //Open sixth file
            break;
        default:
            printf("Error finding the file, please re-enter a character between 'a' and 'f'");
        
    }
}

void encryption(char *baseText, int shift);

void encryptRotKey(void)
{
  int shift = 5;  
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

