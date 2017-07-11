#include "CallAdd_base.h"






void model_init_add_blocks(jmi_t** jmi) {



}

int model_ode_initialize_base(jmi_t* jmi) {
    int ef = 0;
    _z_2 = func_CallAdd_CAdd_exp0(_FirstInput_0, _SecondInput_1);
    return ef;
}


int model_ode_initialize(jmi_t* jmi) {
    return model_ode_initialize_base(jmi);
}

int model_init_R0(jmi_t* jmi, jmi_real_t** res) {

    return 0;
}
