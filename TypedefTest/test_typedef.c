#include <stdio.h>
#include <windows.h>

typedef void (CALLBACK* DLLFUNC1)();	
typedef void* (CALLBACK* DLLFUNC2)(char*);
typedef void* (CALLBACK* DLLFUNC3)(void*);	//void* - points to non-specific var type (PyObject)
typedef void* (CALLBACK* DLLFUNC4)(void*,char*);
typedef int (CALLBACK* DLLFUNC5)(void*);
typedef void (CALLBACK* DLLFUNC6)(void*);
typedef void* (CALLBACK* DLLFUNC7)(void*,void*);
typedef void* (CALLBACK* DLLFUNC8)(int);
typedef void* (CALLBACK* DLLFUNC9)(long);
typedef int (CALLBACK* DLLFUNC10)(void*,int,void*);
typedef long (CALLBACK* DLLFUNC11)(void*);

double test_typedef(double x, double y){ 
	double answer;
	HINSTANCE hDLL;								//stores base address of the module
	DLLFUNC1 DllFunc1;	
	DLLFUNC2 DllFunc2;	//PyString_FromString - I:char* 			O:PyObject*
	DLLFUNC2 DllFunc3;	//PyImport_Import - 	I:char* 			O:PyObject*
	DLLFUNC3 DllFunc4;	//PyModule_GetDict - 	I:PyObject* 		O:PyObject*
	DLLFUNC4 DllFunc5;	//PyDict_GetItemString - I:PyObject*,char* 	O:PyObject*
	DLLFUNC5 DllFunc6;	//PyCallable_Check - 	I:PyObject* 		O:int
	DLLFUNC7 DllFunc7;	//PyObject_CallObject - I:PyObject*,PyObject* O:Pyobject* 
	DLLFUNC1 DllFunc8;	//PyErr_Print - 		I:void 				O:void
	DLLFUNC6 DllFunc9;	//Py_DECREF - 			I:PyObject* 		O:void
	DLLFUNC1 DllFunc10;	//Py_Finalize - 		I:void 				O:void
	DLLFUNC8 DllFunc11; //PyTuple_New - 		I:int 				O:PyObject*
	DLLFUNC9 DllFunc12; //PyInt_FromLong - 		I:long 				O:PyObject*
	DLLFUNC10 DllFunc13;//PyTuple_SetItem - 	I:PyObject*,Py_ssize_t,PyObject* O:int
	DLLFUNC11 DllFunc14;//PyInt_AsLong - 		I:PyObject*			O:Long

	void *pName, *pModule, *pDict, *pFunc, *pArgs, *pValue;
	int i;

	hDLL = LoadLibrary("python27.dll");	//retrieves base address of file
	if (hDLL != NULL){					//checks that LoadLibrary was successful
		//retrieve address of a function, given address of module and name of function
		DllFunc1 = (DLLFUNC1)GetProcAddress(hDLL,"Py_Initialize");
		DllFunc2 = (DLLFUNC2)GetProcAddress(hDLL,"PyString_FromString");
		DllFunc3 = (DLLFUNC2)GetProcAddress(hDLL,"PyImport_Import");
		DllFunc4 = (DLLFUNC3)GetProcAddress(hDLL,"PyModule_GetDict");
		DllFunc5 = (DLLFUNC4)GetProcAddress(hDLL,"PyDict_GetItemString");
		DllFunc6 = (DLLFUNC5)GetProcAddress(hDLL,"PyCallable_Check");
		DllFunc7 = (DLLFUNC7)GetProcAddress(hDLL,"PyObject_CallObject");
		DllFunc8 = (DLLFUNC1)GetProcAddress(hDLL,"PyErr_Print");
		DllFunc9 = (DLLFUNC6)GetProcAddress(hDLL,"Py_XDECREF");
		DllFunc10 = (DLLFUNC1)GetProcAddress(hDLL,"Py_Finalize");
		DllFunc11 = (DLLFUNC8)GetProcAddress(hDLL,"PyTuple_New");
		DllFunc12 = (DLLFUNC9)GetProcAddress(hDLL,"PyInt_FromLong");
		DllFunc13 = (DLLFUNC10)GetProcAddress(hDLL,"PyTuple_SetItem");
		DllFunc14 = (DLLFUNC11)GetProcAddress(hDLL,"PyInt_FromLong");

		if(!DllFunc1 && !DllFunc2 && !DllFunc3 && !DllFunc4 && !DllFunc5 
			&& !DllFunc6 && !DllFunc7 && !DllFunc8 && !DllFunc9 && !DllFunc10 
			&&!DllFunc11 && !DllFunc12 && !DllFunc13 && !DllFunc14){
			printf("Functions were not found\n");
			return 0;
		}
		else{
			DllFunc1();
			pName = DllFunc2("add_func");
			pModule = DllFunc3(pName);
			if(!pModule){DllFunc8();}
			//else{x = x + 10;}
			pDict = DllFunc4(pModule);
			pFunc = DllFunc5(pDict, "add");
			if(!pFunc){DllFunc8();}
			//DllFunc10();
		}
	}
	

	answer = x + y;
	return answer;
}