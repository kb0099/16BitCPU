/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    unisims_ver_m_00000000001946988858_2297623829_init();
    unisims_ver_m_00000000003266096158_2593380106_init();
    work_m_00000000002596209280_1082978998_init();
    work_m_00000000003810833649_1704550970_init();
    xilinxcorelib_ver_m_00000000001358910285_1933459722_init();
    xilinxcorelib_ver_m_00000000001687936702_3412580636_init();
    xilinxcorelib_ver_m_00000000001080096809_0294060604_init();
    xilinxcorelib_ver_m_00000000001603977570_3966857645_init();
    work_m_00000000003289761879_3063639841_init();
    work_m_00000000001082162760_1797395409_init();
    work_m_00000000002740861748_1542830520_init();
    work_m_00000000003273733715_3791432322_init();
    work_m_00000000000247642912_0432795988_init();
    work_m_00000000003927716172_1345247661_init();
    work_m_00000000002329533212_0341795706_init();
    work_m_00000000002604164640_3926213419_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000002604164640_3926213419");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
