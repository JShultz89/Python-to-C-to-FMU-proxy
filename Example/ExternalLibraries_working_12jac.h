/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define ExternalLibraries_working_INDEX_JAC_D 3
  int ExternalLibraries_working_functionJacD_column(void* data, threadData_t *threadData);
  int ExternalLibraries_working_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */

#if defined(__cplusplus)
extern "C" {
#endif
  #define ExternalLibraries_working_INDEX_JAC_C 2
  int ExternalLibraries_working_functionJacC_column(void* data, threadData_t *threadData);
  int ExternalLibraries_working_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define ExternalLibraries_working_INDEX_JAC_B 1
  int ExternalLibraries_working_functionJacB_column(void* data, threadData_t *threadData);
  int ExternalLibraries_working_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define ExternalLibraries_working_INDEX_JAC_A 0
  int ExternalLibraries_working_functionJacA_column(void* data, threadData_t *threadData);
  int ExternalLibraries_working_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */
#define $PySeedA data->simulationInfo.analyticJacobians[0].seedVars[0]
#define $PySeedA__varInfo dummyVAR_INFO


