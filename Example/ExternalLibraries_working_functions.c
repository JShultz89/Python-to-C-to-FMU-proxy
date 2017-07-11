#include "ExternalLibraries_working_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "ExternalLibraries_working_literals.h"
#include "ExternalLibraries_working_includes.h"



modelica_real omc_ExternalLibraries__working_ExternalFunc2(threadData_t *threadData, modelica_real _x)
{
  double _x_ext;
  double _y_ext;
  modelica_real _y;
  _x_ext = (double)_x;
  _y_ext = ExternalFunc2(_x_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_ExternalLibraries__working_ExternalFunc2(threadData_t *threadData, modelica_metatype _x)
{
  modelica_real tmp1;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_x);
  _y = omc_ExternalLibraries__working_ExternalFunc2(threadData, tmp1);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

#ifdef __cplusplus
}
#endif
