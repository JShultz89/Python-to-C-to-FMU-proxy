#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <jmi.h>
#include <jmi_block_residual.h>
#include "jmi_log.h"
#include "ModelicaUtilities.h"
#include "ModelicaStandardTables.h"

extern void dgemm_(char* TRANSA, char* TRANSB, int* M, int* N, int* K, double* ALPHA, double* A, int* LDA, double* B, int* LDB, double* BETA, double* C, int* LDC);

int model_ode_derivatives(jmi_t* jmi);
int model_ode_initialize(jmi_t* jmi);
int model_dae_R(jmi_t* jmi, jmi_real_t** res);
int model_init_R0(jmi_t* jmi, jmi_real_t** res);
void model_add_blocks(jmi_t** jmi);
void model_init_add_blocks(jmi_t** jmi);
int model_init_eval_parameters(jmi_t* jmi);
int jmi_set_start_values(jmi_t* jmi);
int model_ode_guards(jmi_t* jmi);
int model_ode_guards_init(jmi_t* jmi);


#define __block_jacobian_check_tol_4 ((*(jmi->z))[jmi->offs_real_pi+0])
#define __cs_rel_tol_7 ((*(jmi->z))[jmi->offs_real_pi+1])
#define __cs_step_size_9 ((*(jmi->z))[jmi->offs_real_pi+2])
#define __events_default_tol_11 ((*(jmi->z))[jmi->offs_real_pi+3])
#define __events_tol_factor_12 ((*(jmi->z))[jmi->offs_real_pi+4])
#define __nle_solver_default_tol_17 ((*(jmi->z))[jmi->offs_real_pi+5])
#define __nle_solver_max_residual_scaling_factor_19 ((*(jmi->z))[jmi->offs_real_pi+6])
#define __nle_solver_min_residual_scaling_factor_20 ((*(jmi->z))[jmi->offs_real_pi+7])
#define __nle_solver_min_tol_21 ((*(jmi->z))[jmi->offs_real_pi+8])
#define __nle_solver_regularization_tolerance_22 ((*(jmi->z))[jmi->offs_real_pi+9])
#define __nle_solver_step_limit_factor_23 ((*(jmi->z))[jmi->offs_real_pi+10])
#define __nle_solver_tol_factor_24 ((*(jmi->z))[jmi->offs_real_pi+11])
#define __block_solver_experimental_mode_5 ((*(jmi->z))[jmi->offs_integer_pi+0])
#define __cs_experimental_mode_6 ((*(jmi->z))[jmi->offs_integer_pi+1])
#define __cs_solver_8 ((*(jmi->z))[jmi->offs_integer_pi+2])
#define __iteration_variable_scaling_13 ((*(jmi->z))[jmi->offs_integer_pi+3])
#define __log_level_14 ((*(jmi->z))[jmi->offs_integer_pi+4])
#define __nle_solver_max_iter_18 ((*(jmi->z))[jmi->offs_integer_pi+5])
#define __residual_equation_scaling_29 ((*(jmi->z))[jmi->offs_integer_pi+6])
#define __block_jacobian_check_3 ((*(jmi->z))[jmi->offs_boolean_pi+0])
#define __enforce_bounds_10 ((*(jmi->z))[jmi->offs_boolean_pi+1])
#define __nle_brent_ignore_error_15 ((*(jmi->z))[jmi->offs_boolean_pi+2])
#define __nle_solver_check_jac_cond_16 ((*(jmi->z))[jmi->offs_boolean_pi+3])
#define __nle_solver_use_last_integrator_step_25 ((*(jmi->z))[jmi->offs_boolean_pi+4])
#define __nle_solver_use_nominals_as_fallback_26 ((*(jmi->z))[jmi->offs_boolean_pi+5])
#define __rescale_after_singular_jac_27 ((*(jmi->z))[jmi->offs_boolean_pi+6])
#define __rescale_each_step_28 ((*(jmi->z))[jmi->offs_boolean_pi+7])
#define __runtime_log_to_file_30 ((*(jmi->z))[jmi->offs_boolean_pi+8])
#define __use_Brent_in_1d_31 ((*(jmi->z))[jmi->offs_boolean_pi+9])
#define __use_jacobian_equilibration_32 ((*(jmi->z))[jmi->offs_boolean_pi+10])
#define __use_newton_for_brent_33 ((*(jmi->z))[jmi->offs_boolean_pi+11])
#define _FirstInput_0 ((*(jmi->z))[jmi->offs_real_u+0])
#define _SecondInput_1 ((*(jmi->z))[jmi->offs_real_u+1])
#define _z_2 ((*(jmi->z))[jmi->offs_real_w+0])
#define _time ((*(jmi->z))[jmi->offs_t])
#define __homotopy_lambda ((*(jmi->z))[jmi->offs_homotopy_lambda])
#define pre_FirstInput_0 ((*(jmi->z))[jmi->offs_pre_real_u+0])
#define pre_SecondInput_1 ((*(jmi->z))[jmi->offs_pre_real_u+1])
#define pre_z_2 ((*(jmi->z))[jmi->offs_pre_real_w+0])


#define sf(i) (jmi->variable_scaling_factors[i])

#define _real_ci(i) ((*(jmi->z))[jmi->offs_real_ci+i])
#define _real_cd(i) ((*(jmi->z))[jmi->offs_real_cd+i])
#define _real_pi(i) ((*(jmi->z))[jmi->offs_real_pi+i])
#define _real_pd(i) ((*(jmi->z))[jmi->offs_real_pd+i])
#define _real_dx(i) ((*(jmi->z))[jmi->offs_real_dx+i])
#define _real_x(i) ((*(jmi->z))[jmi->offs_real_x+i])
#define _real_u(i) ((*(jmi->z))[jmi->offs_real_u+i])
#define _real_w(i) ((*(jmi->z))[jmi->offs_real_w+i])
#define _t ((*(jmi->z))[jmi->offs_t])

#define _real_d(i) ((*(jmi->z))[jmi->offs_real_d+i])
#define _integer_d(i) ((*(jmi->z))[jmi->offs_integer_d+i])
#define _integer_u(i) ((*(jmi->z))[jmi->offs_integer_u+i])
#define _boolean_d(i) ((*(jmi->z))[jmi->offs_boolean_d+i])
#define _boolean_u(i) ((*(jmi->z))[jmi->offs_boolean_u+i])

#define _pre_real_dx(i) ((*(jmi->z))[jmi->offs_pre_real_dx+i])
#define _pre_real_x(i) ((*(jmi->z))[jmi->offs_pre_real_x+i])
#define _pre_real_u(i) ((*(jmi->z))[jmi->offs_pre_real_u+i])
#define _pre_real_w(i) ((*(jmi->z))[jmi->offs_pre_real_w+i])

#define _pre_real_d(i) ((*(jmi->z))[jmi->offs_pre_real_d+i])
#define _pre_integer_d(i) ((*(jmi->z))[jmi->offs_pre_integer_d+i])
#define _pre_integer_u(i) ((*(jmi->z))[jmi->offs_pre_integer_u+i])
#define _pre_boolean_d(i) ((*(jmi->z))[jmi->offs_pre_boolean_d+i])
#define _pre_boolean_u(i) ((*(jmi->z))[jmi->offs_pre_boolean_u+i])

#define _sw(i) ((*(jmi->z))[jmi->offs_sw + i])
#define _sw_init(i) ((*(jmi->z))[jmi->offs_sw_init + i])
#define _pre_sw(i) ((*(jmi->z))[jmi->offs_pre_sw + i])
#define _pre_sw_init(i) ((*(jmi->z))[jmi->offs_pre_sw_init + i])
#define _guards(i) ((*(jmi->z))[jmi->offs_guards + i])
#define _guards_init(i) ((*(jmi->z))[jmi->offs_guards_init + i])
#define _pre_guards(i) ((*(jmi->z))[jmi->offs_pre_guards + i])
#define _pre_guards_init(i) ((*(jmi->z))[jmi->offs_pre_guards_init + i])

#define _atInitial (jmi->atInitial)



void func_CallAdd_CAdd_def0(jmi_ad_var_t x_v, jmi_ad_var_t y_v, jmi_ad_var_t* z_o);
jmi_ad_var_t func_CallAdd_CAdd_exp0(jmi_ad_var_t x_v, jmi_ad_var_t y_v);




