/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define StoreData_Trial1_INDEX_JAC_D 3
  int StoreData_Trial1_functionJacD_column(void* data, threadData_t *threadData);
  int StoreData_Trial1_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */

#if defined(__cplusplus)
extern "C" {
#endif
  #define StoreData_Trial1_INDEX_JAC_C 2
  int StoreData_Trial1_functionJacC_column(void* data, threadData_t *threadData);
  int StoreData_Trial1_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define StoreData_Trial1_INDEX_JAC_B 1
  int StoreData_Trial1_functionJacB_column(void* data, threadData_t *threadData);
  int StoreData_Trial1_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define StoreData_Trial1_INDEX_JAC_A 0
  int StoreData_Trial1_functionJacA_column(void* data, threadData_t *threadData);
  int StoreData_Trial1_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */
#define $PxSeedA data->simulationInfo.analyticJacobians[0].seedVars[0]
#define $PxSeedA__varInfo dummyVAR_INFO


