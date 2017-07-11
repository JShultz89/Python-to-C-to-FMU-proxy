#include "CallAdd_base.h"


int jmi_set_start_values_0_0(jmi_t* jmi) {
    int ef = 0;
    __block_jacobian_check_3 = (JMI_FALSE);
    __block_jacobian_check_tol_4 = (1.0E-6);
    __block_solver_experimental_mode_5 = (0);
    __cs_experimental_mode_6 = (0);
    __cs_rel_tol_7 = (1.0E-6);
    __cs_solver_8 = (0);
    __cs_step_size_9 = (0.001);
    __enforce_bounds_10 = (JMI_TRUE);
    __events_default_tol_11 = (1.0E-10);
    __events_tol_factor_12 = (1.0E-4);
    __iteration_variable_scaling_13 = (1);
    __log_level_14 = (3);
    __nle_brent_ignore_error_15 = (JMI_FALSE);
    __nle_solver_check_jac_cond_16 = (JMI_FALSE);
    __nle_solver_default_tol_17 = (1.0E-10);
    __nle_solver_max_iter_18 = (100);
    __nle_solver_max_residual_scaling_factor_19 = (1.0E10);
    __nle_solver_min_residual_scaling_factor_20 = (1.0E-10);
    __nle_solver_min_tol_21 = (1.0E-12);
    __nle_solver_regularization_tolerance_22 = (-1.0);
    __nle_solver_step_limit_factor_23 = (10.0);
    __nle_solver_tol_factor_24 = (1.0E-4);
    __nle_solver_use_last_integrator_step_25 = (JMI_TRUE);
    __nle_solver_use_nominals_as_fallback_26 = (JMI_TRUE);
    __rescale_after_singular_jac_27 = (JMI_TRUE);
    __rescale_each_step_28 = (JMI_FALSE);
    __residual_equation_scaling_29 = (1);
    __runtime_log_to_file_30 = (JMI_FALSE);
    __use_Brent_in_1d_31 = (JMI_TRUE);
    __use_jacobian_equilibration_32 = (JMI_FALSE);
    __use_newton_for_brent_33 = (JMI_TRUE);
    return ef;
}

int jmi_set_start_values_1_0(jmi_t* jmi) {
    int ef = 0;
    _FirstInput_0 = (0);
    _SecondInput_1 = (0);
    _z_2 = (0);
    return ef;
}

int jmi_set_start_values_base(jmi_t* jmi) {
    int ef = 0;
    ef |= jmi_set_start_values_0_0(jmi);
    model_init_eval_parameters(jmi);
    ef |= jmi_set_start_values_1_0(jmi);
    return ef;
}


int jmi_set_start_values(jmi_t* jmi) {
    return jmi_set_start_values_base(jmi);
}
