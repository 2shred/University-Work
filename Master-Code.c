/*READ THIS BEFORE USING
Make sure you read this before running the code to understand what to do.

    - Make sure you have entered the base text into "input.txt"
    followed by the "Enter" key.
    
    - Enter your program option in "Program-Selection". Options are numbered
    between 1-6.
    
    - Ensure that you choose "runMaster" when running the code.
    
    - If you are using a program that requires a numeral key (1 & 2)
    enter in a number between 0 and 25 in "rotKey" before running the program.
    
    - If you are using a program that requires a alphabetic key (3 &
    4), enter in a 26 character alphabetic key in "subKey.txt". Ensure
    that the character are all UPPER-CASE
    
    - For programs 5 & 6, just enter the base text into input.txt
    
*/

#include <stdio.h>

void rotEnc(); //Rotation encryption function that will encrypt the text using the rotation method
void subEnc(); //Substitution encryption function that will encrypt the text using the substitution method
void rotDecK(); //Rotation decryption function that will decrypt the text using the rotation method with the given key
void subDecK(); //Substitution decryption function that will decrypt the text using the substitution method with the given key
void rotDec0(); //Rotation decryption function that will decrypt the text using the rotation method without the key
void subDec0(); //Substitution decryption function that will decrypt the text using the substitution method without the key

int main() //The "Main Menu"
{
    int n;
    scanf("%d", &n); //The number is scanned from "Program-Selection" due to the custom run program
    if(n < 1 || n > 6)
        printf("Please select an option in Program-Selection between 1-6:\n1: Rotation Encryption\n2: Substitution Encryption\n3: Rotation Decryption w/ key\n4: Substitution Decryption w/ key\n5: Rotation Decryption w/out key\n6: Substitution Decryption w/out key\n\n");
    
    switch(n)
    {
        case 1:
        {
            rotEnc();
            printf("Encryption completed! Check output.txt for the result!");
            break;
        }
        case 2:
        {
            subEnc();
            printf("Encryption completed! Check output.txt for the result!");
            break;
        }
        case 3:
        {
            rotDecK();
            printf("Decryption completed! Check output.txt for the result!");
            break;
        }
        case 4:
        {
            subDecK();
            printf("Decryption completed! Check output.txt for the result!");
            break;
        }
        case 5:
            break;
        case 6:
            break;
        default:
        {
            break;
        }
    }
}

void rotEnc()
{
    FILE *input;
    FILE *output;
    FILE *rotKey;
    char c;
    int s;
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    rotKey = fopen("rotKey.txt", "r");
    
    while(feof(input) == 0)
    {
        fscanf(rotKey, "%d", &s);
        if(s < 0 || s > 25)
        {
            printf("Enter a number between 0 and 25 in rotKey.txt");
            break;
        }
        fscanf(input, "%c", &c);
        if(c >= 'a' && c <= 'z')
            c = c - 32;
        if(c >= 'A' && c <= 'Z')
        {
            c = c + s;
            if(c > 'Z') //If the shift pushes the character past the character 'Z' 
                c = c - 'Z' + 'A' - 1;
            else if(c < 'A') //If the shift pushes the character before the character 'A'
                c = c + 'Z' - 'A' - 1;
        }
        fprintf(output, "%c", c);
    }
    return;
}

void subEnc()
{
    FILE *input;
    FILE *output;
    FILE *subKey;
    char key[32]; //Setting value to 32 just to be safe
    char stand[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i; //Counter for "key" array
    int k; //Counter for "stand" string
    char c; //Scan characters from "subKey"
    char t; //Scan characters from "input" (Making it separate to make it less confusing)
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    subKey = fopen("subKey.txt", "r");
    
    for(i = 0; feof(subKey) == 0; i++) //Assigning values from "subKey" to an array
    {
        fscanf(subKey, "%c", &c);
        key[i] = c;
    }
    while(feof(input) == 0)
    {
        fscanf(input, "%c", &t);
        if(t >= 'a' && t <= 'z')
            t = t - 32;
        if(t == 32)
            fprintf(output, "%c", t);
        if(t >= 'A' && t <= 'Z')
        {
            for(k = 0; stand[k] != 0; k++)
            {
                if(stand[k] == t)
                {
                    t = key[k];
                    fprintf(output, "%c", t);
                    break;
                }
            }
        }
    }
    return;
}

void rotDecK()
{
    FILE *input;
    FILE *output;
    FILE *rotKey;
    char c;
    int s;
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    rotKey = fopen("rotKey.txt", "r");
    
    while(feof(input) == 0)
    {
        fscanf(rotKey, "%d", &s);
        if(s < 0 || s > 25)
        {
            printf("Enter a number between 0 and 25 in rotKey.txt");
            break;
        }
        fscanf(input, "%c", &c);
        if(c >= 'a' && c <= 'z')
            c = c - 32;
        if(c >= 'A' && c <= 'Z')
        {
            c = c - s;
            if(c > 'Z')
                c = c - 'Z' + 'A' + 1;
            else if(c < 'A')
                c = c + 'Z' - 'A' + 1;
        }
        fprintf(output, "%c", c);
    }
    return;
}

void subDecK()
{
    FILE *input;
    FILE *output;
    FILE *subKey;
    char key[32];
    char stand[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i; //Counter for "key" array
    int k; //Counter for "stand" string
    char c; //Scan characters from "subKey"
    char t; //Scan characters from "input" (Making it separate to make it less confusing)
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    subKey = fopen("subKey.txt", "r");
    
    for(i = 0; feof(subKey) == 0; i++)
    {
        fscanf(subKey, "%c", &c);
        key[i] = c;
    }
    while(feof(input) == 0)
    {
        fscanf(input, "%c", &t);
        if(t >= 'a' && t <= 'z')
            t = t - 32;
        if(t == 32)
            fprintf(output, "%c", t);
        if(t >= 'A' && t <= 'Z')
        {
            for(k = 0; key[k] != 0; k++)
            {
                if(key[k] == t)
                {
                    t = stand[k];
                    fprintf(output, "%c", t);
                    break;
                }
            }
        }
    }
    return;
}

void rotDec0()
{
    
}