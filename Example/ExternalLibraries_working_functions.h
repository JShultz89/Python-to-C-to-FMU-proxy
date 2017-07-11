#ifndef ExternalLibraries_working__H
#define ExternalLibraries_working__H
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
modelica_real omc_ExternalLibraries__working_ExternalFunc2(threadData_t *threadData, modelica_real _x);
DLLExport
modelica_metatype boxptr_ExternalLibraries__working_ExternalFunc2(threadData_t *threadData, modelica_metatype _x);
static const MMC_DEFSTRUCTLIT(boxvar_lit_ExternalLibraries__working_ExternalFunc2,2,0) {(void*) boxptr_ExternalLibraries__working_ExternalFunc2,0}};
#define boxvar_ExternalLibraries__working_ExternalFunc2 MMC_REFSTRUCTLIT(boxvar_lit_ExternalLibraries__working_ExternalFunc2)

extern double ExternalFunc2(double /*_x*/);
#include "ExternalLibraries_working_model.h"


#ifdef __cplusplus
}
#endif
#endif

