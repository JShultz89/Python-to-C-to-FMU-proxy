#ifndef StoreData_Trial1__H
#define StoreData_Trial1__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif


DLLExport
modelica_real omc_StoreData__Trial1_storeData(threadData_t *threadData, modelica_real _x);
DLLExport
modelica_metatype boxptr_StoreData__Trial1_storeData(threadData_t *threadData, modelica_metatype _x);
static const MMC_DEFSTRUCTLIT(boxvar_lit_StoreData__Trial1_storeData,2,0) {(void*) boxptr_StoreData__Trial1_storeData,0}};
#define boxvar_StoreData__Trial1_storeData MMC_REFSTRUCTLIT(boxvar_lit_StoreData__Trial1_storeData)

extern double storeData(double /*_x*/);
#include "StoreData_Trial1_model.h"


#ifdef __cplusplus
}
#endif
#endif

