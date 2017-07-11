#include "StoreData_Trial1_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "StoreData_Trial1_literals.h"
#include "StoreData_Trial1_includes.h"



modelica_real omc_StoreData__Trial1_storeData(threadData_t *threadData, modelica_real _x)
{
  double _x_ext;
  double _y_ext;
  modelica_real _y;
  _x_ext = (double)_x;
  _y_ext = storeData(_x_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_StoreData__Trial1_storeData(threadData_t *threadData, modelica_metatype _x)
{
  modelica_real tmp1;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_x);
  _y = omc_StoreData__Trial1_storeData(threadData, tmp1);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

#ifdef __cplusplus
}
#endif
