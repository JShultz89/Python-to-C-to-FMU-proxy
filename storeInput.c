//storeInput.c
//Used to test passing data from EnergyPlus to C code
//Input: any number of doubles
//Saves doubles to an array, writes them to output.txt file, and returns the number of doubles saved

#include <stdio.h>
#include <stdlib.h>

void store(double input){
	double storage[1];
	FILE *outfile;

	storage[0] = input;
	outfile = fopen("output.txt","w");
	fprintf(outfile, "%f\n", storage[0]);	//prints value to text file
	printf("Value stored:%f",storage[0]);
	//return 0;
}

int main(int argc, char *argv[])
{
	double storage[argc];
	int i = 0;
	int j = 1;
	double x;
	FILE *outfile;

	if(argc < 2)
	{
		printf("No input values.\n");
		return 1;
	}
	else
	{
		outfile = fopen("output.txt","w");
		while(i < argc - 1)
		{
			x = atof(argv[j]);		//converts inputs from char* type to double type
			storage[i] = x;			//adds value to array of doubles
			printf("%f\n", x);		//prints value to command line
			fprintf(outfile, "%f\n", x);	//prints value to text file
			i++;
			j++;
		}
	}
	printf("%i values stored.\n",i);
	return 0;
}