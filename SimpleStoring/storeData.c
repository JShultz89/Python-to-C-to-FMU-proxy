//storeData.c
//#include <stdio.h>

double storeData(double input){
	double storage[1];
	//FILE *outfile;
	storage[0] = input;
	//outfile = fopen("output.txt","w");
	//fprintf(outfile, "%f\n", storage[0]);
	return storage[0];
}

/**Main function is necessary for testing C code on its own, but seems to break 
the simulation with OpenModelica Shell**/
//void main(){
//	storeData(2.34);
//}