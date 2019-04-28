/*READ THIS BEFORE USING
Make sure you read this before running the code to understand what to do.

    - Make sure you have entered the base text into "input.txt"
    followed by the "Enter" key.
    
    - Enter your program option in "Program-Selection". Options are numbered
    between 1-5.
    
    - Ensure that you choose "runMaster" when running the code.
    
    - If you are using a program that requires a numeral key (1 & 2)
    enter in a number between 0 and 25 in "rotKey" before running the program.
    
    - If you are using a program that requires a alphabetic key (3 &
    4), enter in a 26 character alphabetic key in "subKey.txt". Ensure
    that the character are all UPPER-CASE.
    
    - For program 5, just enter the base text into input.txt.
    
*/

#include <stdio.h>

void rotEnc(); //Rotation encryption function that will encrypt the text using the rotation method
void subEnc(); //Substitution encryption function that will encrypt the text using the substitution method
void rotDecK(); //Rotation decryption function that will decrypt the text using the rotation method with the given key
void subDecK(); //Substitution decryption function that will decrypt the text using the substitution method with the given key
void rotDec0(); //Rotation decryption function that will decrypt the text using the rotation method without the key

int main() //The "Main Menu"
{
    int n;
    scanf("%d", &n); //The number is scanned from "Program-Selection" due to the custom run program
    
    switch(n) //Depending on the number entered in "Program-Selection", the code will follow one of the following cases below.
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
        {
            rotDec0();
            printf("Attack successful! Check output.txt for the possible solutions");
            break;
        }
        default:
        {
            printf("Please select an option in Program-Selection between 1-5:\n1: Rotation Encryption\n2: Substitution Encryption\n3: Rotation Decryption w/ key\n4: Substitution Decryption w/ key\n5: Rotation Decryption w/out key\n\n");
            break;
        }
    }
}

void rotEnc()
{
    FILE *input;
    FILE *output;
    FILE *rotKey; //"rotKey.txt" and "subKey.txt" are different text files as one is nurmeral based while the other one is alphabetic based.
    char c; //Initialising a variable that will assign each individual character from "input.txt" and encrypt it using the formulas below.
    int s; //Inisialising a variable that will store a real number from "rotKey.txt". This would be the key
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    rotKey = fopen("rotKey.txt", "r");
    
    while(feof(input) == 0) //Reading through "input.txt" character by character and exiting when it reaches the end.
    {
        fscanf(rotKey, "%d", &s);
        if(s < 0 || s > 25) //Specifying the range of the key to being in between 0 to 25.
        {
            printf("Enter a number between 0 and 25 in rotKey.txt");
            break;
        }
        fscanf(input, "%c", &c);
        if(c >= 'a' && c <= 'z') //Converting the letter from a lower-case to an upper-case
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
    char key[32]; //Setting string length to 32 just to be safe
    char stand[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    int k;
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
            t = t - 32; //Converting a lower-case character (if it exist) to an upper-case character
        if(t == 32)
            fprintf(output, "%c", t); //Printing out a '<SPACE>' character directly to output.
        if(t >= 'A' && t <= 'Z')
        {
            for(k = 0; stand[k] != 0; k++) //For loop that will go through each character of the alphabet individually.
            {
                if(stand[k] == t) //Testing to see if the letter of the alphabet matches the letter in the base text
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
        if(s < 0 || s > 25) //Testing to see if the key is a number between 0 and 25
        {
            printf("Enter a number between 0 and 25 in rotKey.txt");
            break;
        }
        fscanf(input, "%c", &c);
        if(c >= 'a' && c <= 'z')
            c = c - 32;
        if(c >= 'A' && c <= 'Z')
        {
            c = c - s; //Subtracting the shift from the encrypted text to decrypt it.
            if(c > 'Z')
                c = c - 'Z' + 'A' + 1; //
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
    char key[26];
    char stand[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    int k;
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
            t = t - 32; //Converting lower-case to upper-case
        if(t == 32)
            fprintf(output, "%c", t);
        if(t >= 'A' && t <= 'Z')
        {
            for(k = 0; key[k] != 0; k++)
            {
                if(key[k] == t) //Similar to subEnc but "key[k]" and "stand[k]" are flipped around
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
    FILE *input;
    FILE *output;
    int k;
    char c;
    
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    fprintf(output, "Original (0): "); //Re-print base text for default value
    while(feof(input) == 0)
        {
            fscanf(input, "%c", &c);
            fprintf(output, "%c", c);
        }
    fprintf(output, "\n");
    fseek(input, 0, SEEK_SET); //Setting the position indicator back to the start to read through the file again for the next attacks
    
    for(k = 1; k <= 25; k++) //Brute force loop: Testing all possible outcomes from 1-25.
    {
        fprintf(output, "+%d: ", k);
        while(feof(input) == 0) //From here, code is very similar to the "rotEnc" code.
        {
            fscanf(input, "%c", &c);
            if(c >= 'a' && c <= 'z')
                c = c - 32;
            if(c >= 'A' && c <= 'Z')
            {
                c = c + k;
                if(c > 'Z')
                    c = c - 'Z' + 'A' - 1;
                else if(c < 'A')
                    c = c + 'Z' - 'A' - 1;
            }
            fprintf(output, "%c", c);
        }
        fprintf(output, "\n");
        fseek(input, 0, SEEK_SET);
    }
    return;
}