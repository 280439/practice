#include <conio.h>
#include <stdio.h>
#include <string.h>

char state = 'Y'; 

enum {MinNo = 5, MaxNo = 12};

    
unsigned int multiplier[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,0.1,0.01};
float tolerance[] = {'\0',1,2,'\0','\0',0.5,0.25,0.1,0.05,'\0',5,10};

char *convertToLower (char *dest, char *src); //converts all to lower case
char *seperateNumbers (char *sep, long value); //puts space every 3rd digit
int searchValue (char *colourcode); //search the index values in colour codes
int compareString (char *string1, char *string2); //comarison between two strings


int main(void)
{
    int i,m,n,tol;
	int error = 0;
	int colour_val[MinNo]; //stores the value in band
	
    char input[MinNo][MaxNo]; //input by user
    char invalid[MinNo][MaxNo]; //enteries which are invalid
	
    long resistance = 0; 
	
    char finalResistorValue[20] = "";//output
	
    do
    {
        //user input 
    printf("%s\n%s\n%s\n",
        "Please, enter the colours for the resistor's three bands,",
        "begin with the last band(nearest to the end).",
        "Type the colours in Uppercase letters only.");

    for (i = 0; i < MinNo; ++i)
    {
        printf("Band %d : ", i + 1); // print headers for each band
        scanf(" %s", &input[i]);  // get the user input
        // converts user input to index of colours
        colour_val[i] = searchValue(input[i]); 
    }       
    for (i = 0; i < MinNo; ++i)
    {
        if (colour_val[i] == -1)
        {
            strcpy(invalid[i], input[i]);
            error++;
        }
    }
    if (error > 0)
    {
        if (error == 1)
        {
            printf("Invalid colour: %s\n", invalid[0]);
        }
        else if (error == 2)
        {
            printf("Invalid colours: %s, %s\n", invalid[0], invalid[1]);
        }
        else 
        {
            printf("Invalid colours: %s, %s, %s\n",
             invalid[0], invalid[1], invalid[2]);
        }
    }
    else
    {
        for (i = 0; i < MinNo - 1; ++i)
        {
            resistance = (resistance * 10) + colour_val[i];
        }
         m = colour_val[3];
         n=colour_val[4];
        resistance *= multiplier[m];
        seperateNumbers (finalResistorValue, resistance);
        tol=tolerance[n];

        printf("Resistance value is : %s Ohms %d %% Tolerance\n", finalResistorValue,tol);
		
        for (i = 0; i < MinNo; ++i)
        {
            //printf("Input ==> %s\t", input[i]);
            //printf("index ==> %d\n", colour_val[i]);
        }
    }
    error = 0;
    resistance = 0;
    for (i = 0; i < MinNo; ++i)
    {
        colour_val[i] = 0;
    }
	
    //asking user if they want to continue or not
    printf("Do you want to proceed with another resistor?\n");
    scanf(" %c", &state);


    if (state == 'Y');
    else break;
	
	} while (state == 'Y');

    return 0;
}





