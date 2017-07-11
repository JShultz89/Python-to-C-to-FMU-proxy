#if defined(__cplusplus)
  extern "C" {
#endif
  int ExternalLibraries_working_mayer(DATA* data, modelica_real** res, short*);
  int ExternalLibraries_working_lagrange(DATA* data, modelica_real** res, short *, short *);
  int ExternalLibraries_working_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int ExternalLibraries_working_setInputData(DATA *data, const modelica_boolean file);
  int ExternalLibraries_working_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif