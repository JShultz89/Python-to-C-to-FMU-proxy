#include "CallAdd_base.h"




void func_CallAdd_CAdd_def0(jmi_ad_var_t x_v, jmi_ad_var_t y_v, jmi_ad_var_t* z_o) {
    JMI_DYNAMIC_INIT()
    JMI_DEF(REA, z_v)
    z_v = CAdd(x_v, y_v);
    JMI_RET(GEN, z_o, z_v)
    JMI_DYNAMIC_FREE()
    return;
}

jmi_ad_var_t func_CallAdd_CAdd_exp0(jmi_ad_var_t x_v, jmi_ad_var_t y_v) {
    JMI_DEF(REA, z_v)
    func_CallAdd_CAdd_def0(x_v, y_v, &z_v);
    return z_v;
}








