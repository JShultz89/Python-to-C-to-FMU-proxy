//outputTest.c

//This version takes in an array of any number of doubles, passes them to the specified
//Python script and returns the results in an array-like structure that holds 5 doubles.
//If more output variables are required, add more double variables to the MultiVal struct, 
//alter the MultiVal constructor function, add double variables to the outputTest function,
//and add the appropriate number of additional lines to atrieve the output values in the 
//outputTest function.    

#include <stdio.h>
#include <windows.h>

//Array-like structure that stores 5 doubles. Necessary because C cannot return arrays
struct MultiVal{ //Declare new variable type, MultiVal
	double a; //Members of MultiVal struct 
	double b; //These can be accessed later on using var_name.a, var_name.b, etc. where
	double c; //var_name is the name of the variable (Example found in constructor function below)
	double d;
	double e;
};

//Definition of function that creates MultiVal structures
//Defines struct with name "result" and assigns input to elements in "result"
struct MultiVal constructor(double v, double w, double x, double y, double z){
	struct MultiVal result;
	result.a = v;
	result.b = w;
	result.c = x;
	result.d = y;
	result.e = z;
	return result;
}

//Define datatypes that can contain pointers to functions called from the Python DLL. 
//In order to hold the function, the datatype must specify the input and output of the function. 
//For example, DLLFUNC1 points to functions that do not require any arguments and don't return any variables (Py_Initialize, Py_Finalize)
//while DLLFUNC2 points to functions that require one char* type argument and return void pointers (PyString_FromString, PyImport_Import)
typedef void (CALLBACK* DLLFUNC1)();	
typedef void* (CALLBACK* DLLFUNC2)(char*);
typedef void* (CALLBACK* DLLFUNC3)(void*);	//void* - points to non-specific var type, used to store PyObject variables in this code
typedef void* (CALLBACK* DLLFUNC4)(void*,char*);
typedef int (CALLBACK* DLLFUNC5)(void*);
typedef void (CALLBACK* DLLFUNC6)(void*);
typedef void* (CALLBACK* DLLFUNC7)(void*,void*);
typedef void* (CALLBACK* DLLFUNC8)(int);
typedef void* (CALLBACK* DLLFUNC9)(long);
typedef int (CALLBACK* DLLFUNC10)(void*,int,void*);
typedef long (CALLBACK* DLLFUNC11)(void*);
typedef void* (CALLBACK* DLLFUNC12)(double);
typedef double (CALLBACK* DLLFUNC13)(void*);
typedef void* (CALLBACK* DLLFUNC14)(void*,int);

struct MultiVal outputTest(double args[]){
	//Variable Declarations
	//In C, all variables used in a function must be declared at the beginning 
	HINSTANCE hDLL;																//stores base address of the module
	DLLFUNC1 DllPy_Initialize;				//I:void						O:void			//stores pointer to a function
	DLLFUNC2 DllPyString_FromString;	//I:char* 					O:PyObject*
	DLLFUNC2 DllPyImport_Import;			//I:char* 					O:PyObject*
	DLLFUNC3 DllPyModule_GetDict;			//I:PyObject* 			O:PyObject*
	DLLFUNC4 DllPyDict_GetItemString;	//I:PyObject*,char*	O:PyObject*
	DLLFUNC5 DllPyCallable_Check;			//I:PyObject* 			O:int
	DLLFUNC7 DllPyObject_CallObject;	//I:PyObject*,PyObject* O:Pyobject* 
	DLLFUNC1 DllPyErr_Print;					//I:void 						O:void
	DLLFUNC6 DllPy_DECREF;						//I:PyObject* 			O:void
	DLLFUNC1 DllPy_Finalize;					//I:void 						O:void
	DLLFUNC8 DllPyTuple_New; 					//I:int 						O:PyObject*
	DLLFUNC9 DllPyInt_FromLong; 			//I:long 						O:PyObject*
	DLLFUNC10 DllPyTuple_SetItem;			//I:PyObject*,Py_ssize_t,PyObject* O:int
	DLLFUNC11 DllPyInt_AsLong;				//I:PyObject*				O:Long
	DLLFUNC12 DllPyFloat_FromDouble;	//I:double 					O:PyObject*
	DLLFUNC13 DllPyFloat_AsDouble;		//I:PyObject* 			O:double
	DLLFUNC8 DllPyList_New; 					//I:Py_ssize_t			O:PyObject*
	DLLFUNC10 DllPyList_SetItem;			//I:PyObject*,Py_ssize_t,PyObject* O:int
	DLLFUNC14 DllPyList_GetItem;			//I:PyObject*, int 	O:PyObject*
	void *pName, *pModule, *pDict, *pFunc, *pTuple, *pValue, *pList, *pOutList; //Defines local C pointers that retain PyObject information to pass between PyObjects in the C code 
	int i;					//Variable used in for-loop
	struct MultiVal output; //Defines an instance of the struct MultiVal called "output" inside of this function
	double a, b, c, d, e; //Variables used to hold individual values before passing to the struct "output", include more or less variables as needed

	
	hDLL = LoadLibrary("python27.dll");	//retrieves base address of Python DLL file used with the PyObjects below
	if (hDLL != NULL){					//checks that LoadLibrary was successful
		//retrieve address of a function, given address of module (DLL file) and name of function (PyObject)
		DllPy_Initialize = (DLLFUNC1)GetProcAddress(hDLL,"Py_Initialize");	
		DllPyString_FromString = (DLLFUNC2)GetProcAddress(hDLL,"PyString_FromString");
		DllPyImport_Import = (DLLFUNC2)GetProcAddress(hDLL,"PyImport_Import");
		DllPyModule_GetDict = (DLLFUNC3)GetProcAddress(hDLL,"PyModule_GetDict");
		DllPyDict_GetItemString = (DLLFUNC4)GetProcAddress(hDLL,"PyDict_GetItemString");
		DllPyCallable_Check = (DLLFUNC5)GetProcAddress(hDLL,"PyCallable_Check");
		DllPyObject_CallObject = (DLLFUNC7)GetProcAddress(hDLL,"PyObject_CallObject");
		DllPyErr_Print = (DLLFUNC1)GetProcAddress(hDLL,"PyErr_Print");
		DllPy_DECREF = (DLLFUNC6)GetProcAddress(hDLL,"Py_XDECREF");
		DllPy_Finalize = (DLLFUNC1)GetProcAddress(hDLL,"Py_Finalize");
		DllPyTuple_New = (DLLFUNC8)GetProcAddress(hDLL,"PyTuple_New");
		DllPyInt_FromLong = (DLLFUNC9)GetProcAddress(hDLL,"PyInt_FromLong");
		DllPyTuple_SetItem = (DLLFUNC10)GetProcAddress(hDLL,"PyTuple_SetItem");
		DllPyInt_AsLong = (DLLFUNC11)GetProcAddress(hDLL,"PyInt_AsLong");
		DllPyFloat_FromDouble = (DLLFUNC12)GetProcAddress(hDLL,"PyFloat_FromDouble");
		DllPyFloat_AsDouble = (DLLFUNC13)GetProcAddress(hDLL,"PyFloat_AsDouble");
		DllPyList_New = (DLLFUNC8)GetProcAddress(hDLL,"PyList_New");
		DllPyList_SetItem = (DLLFUNC10)GetProcAddress(hDLL,"PyList_SetItem");
		DllPyList_GetItem = (DLLFUNC14)GetProcAddress(hDLL,"PyList_GetItem");

		//checks for any NULL variables (any functions that were not found)
		if(!DllPy_Initialize && !DllPyString_FromString && !DllPyImport_Import && 
			!DllPyModule_GetDict && !DllPyDict_GetItemString && !DllPyCallable_Check 
			&& !DllPyObject_CallObject && !DllPyErr_Print && !DllPy_DECREF && 
			!DllPy_Finalize &&!DllPyTuple_New && !DllPyInt_FromLong && !DllPyTuple_SetItem 
			&& !DllPyInt_AsLong && !DllPyFloat_FromDouble && !DllPyFloat_AsDouble && 
			!DllPyList_New && !DllPyList_SetItem){
			printf("Functions were not found\n");
		}
		//if all functions were found and stored successfully, move on to using them to call Python script
		else{			
			/*SCRIPT CALLING CODE*/
			//Initialize the Python Interpreter
			DllPy_Initialize();

			//Convert the name of the python file into a python string
			//CHANGE: update python file name as needed for your project  
			pName = DllPyString_FromString("PyOutputArray");

			//Imports the python file as a module
			pModule = DllPyImport_Import(pName);
			if(!pModule){printf("Module not found"); DllPyErr_Print();}

			//Sets up contents (functions) of module (python object of the python script) in a dictionary data structure
			// so that the function name in Python can be called upon. 
			pDict = DllPyModule_GetDict(pModule);

			//Retrieves function from dictionary based on command line input
			//CHANGE: update python function name as needed for your project
			pFunc = DllPyDict_GetItemString(pDict, "returnArray");
			
			//Checks that pFunc is callable
			if(DllPyCallable_Check(pFunc)){
				//ARGUMENT CODE, args is a list of the inputs passed into the c code from modelica 
				//Prepare argument list for call
				if(sizeof(args)>0){

					//Create tuple of size 1 to hold pList that will be passed to DllPyObject_CallObject
					pTuple = DllPyTuple_New(1);	
					//Create PyList large enough to hold all arguments
					pList = DllPyList_New(sizeof(args));	 
					for(i = 0; i < sizeof(args); i++){
						//Convert doubles to PyFloats
						pValue = DllPyFloat_FromDouble(args[i]);
						if(!pValue){
							DllPyErr_Print();
						}
						//Inserts PyFloats (from args doubles) into pList
						DllPyList_SetItem(pList, i, pValue);	
					}
					//Adds pList (PyList) to pTuple (tuple)
					DllPyTuple_SetItem(pTuple, 0, pList);	
					
					//Calls pFunc using pTuple as argument inputs and stores result in pOutList
					pOutList = DllPyObject_CallObject(pFunc,pTuple);

					//Retrieves values from pOutList and converts them from PyObjects to doubles
					a = DllPyFloat_AsDouble(DllPyList_GetItem(pOutList,0));
					b = DllPyFloat_AsDouble(DllPyList_GetItem(pOutList,1));
					c = DllPyFloat_AsDouble(DllPyList_GetItem(pOutList,2));
					d = DllPyFloat_AsDouble(DllPyList_GetItem(pOutList,3));
					e = DllPyFloat_AsDouble(DllPyList_GetItem(pOutList,4));
					//Conversion check
					//printf("Python to C: %f, %f, %f, %f, %f \n",a,b,c,d,e);
					
					//Create MultiVal object to store output values
					output = constructor(a,b,c,d,e);
				}
			}
			else{
				//Print error
				DllPyErr_Print();
			}

			//PyFinalize
			DllPy_Finalize();
			//Return MultiVal object, output, that contains 5 doubles that have each been converted from 
			//the PyFloats that were found in the PyList returned by the Python script
			return output;
		}
	}
	else{
		printf("Library was not found\n");
	}
}
/*
int main(){
	//Declaure variables
	double input[4] = {23.4, 1, 1, 1};
	struct MultiVal output;
	//Call function
	output = outputTest(input);
	//Check results
	printf("Results: %f, %f, %f, %f, %f \n",output.a,output.b,output.c,output.d,output.e);
}*/