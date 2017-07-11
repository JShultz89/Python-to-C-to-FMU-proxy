function pyRunString
  input String s;
external "C" annotation(Include="
#include <Python.h>

void pyRunString(const char *str)
{
  Py_SetProgramName(\"pyRunString\");  /* optional but recommended */
  Py_Initialize();
  PyRun_SimpleString(str);
  Py_Finalize();
}
");
end pyRunString;