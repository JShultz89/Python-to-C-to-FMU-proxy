function CStoreSlash
  input Real dou;
external "C" annotation(Include="
#include <stdio.h>
#include <stdlib.h>

void CStore(double input)
{
	double storage[1];
	FILE *outfile;

	storage[0] = input;
	outfile = fopen(\"output.txt\",\"w\");
	fprintf(outfile, \"%f\n\", storage[0]);	//prints value to text file
	printf(\"Value stored:%f\",storage[0]);
}
");
end CStoreSlash;