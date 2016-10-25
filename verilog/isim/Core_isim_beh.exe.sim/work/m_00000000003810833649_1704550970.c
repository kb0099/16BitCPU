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

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Tim/Desktop/3710 next level/16-bit_computer/verilog/Core.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static int ng3[] = {1, 0};
static const char *ng4 = "instr address: %d";
static const char *ng5 = "INSTRUCTION IN: %d";
static unsigned int ng6[] = {1U, 0U};
static unsigned int ng7[] = {2U, 0U};
static int ng8[] = {2, 0};
static unsigned int ng9[] = {3U, 0U};
static int ng10[] = {3, 0};
static unsigned int ng11[] = {4U, 0U};
static unsigned int ng12[] = {6U, 0U};
static const char *ng13 = "READ1";
static const char *ng14 = "WRITE";
static const char *ng15 = "ADD instr addr: %d";
static int ng16[] = {4, 0};
static unsigned int ng17[] = {9216U, 0U};
static const char *ng18 = "JUMP";
static int ng19[] = {5, 0};
static const char *ng20 = "READ2";
static int ng21[] = {6, 0};
static unsigned int ng22[] = {5U, 0U};



static void Initial_36_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(36, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2064);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_38_1(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    int t32;
    char *t33;
    char *t34;
    char *t35;

LAB0:    t1 = (t0 + 4192U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 4760);
    *((int *)t2) = 1;
    t3 = (t0 + 4224);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(39, ng0);

LAB5:    xsi_set_current_line(42, ng0);
    t4 = (t0 + 2384);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng2)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB9;

LAB6:    if (t20 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB9:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2224);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t7);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t6);
    t19 = *((unsigned int *)t7);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB17;

LAB14:    if (t20 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t8) = 1;

LAB17:    t10 = (t8 + 4);
    t25 = *((unsigned int *)t10);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB18;

LAB19:
LAB20:
LAB12:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2224);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng2)));
    memset(t8, 0, 8);
    t7 = (t5 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB33;

LAB32:    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB33;

LAB36:    if (*((unsigned int *)t5) > *((unsigned int *)t6))
        goto LAB34;

LAB35:    t23 = (t8 + 4);
    t11 = *((unsigned int *)t23);
    t12 = (~(t11));
    t13 = *((unsigned int *)t8);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB37;

LAB38:
LAB39:    goto LAB2;

LAB8:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(42, ng0);

LAB13:    xsi_set_current_line(44, ng0);
    t30 = ((char*)((ng3)));
    t31 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t31, t30, 0, 0, 1, 0LL);
    xsi_set_current_line(46, ng0);
    t2 = (t0 + 2864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng4, 2, t0, (char)118, t4, 15);
    goto LAB12;

LAB16:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(49, ng0);

LAB21:    xsi_set_current_line(50, ng0);
    t23 = (t0 + 1344U);
    t24 = *((char **)t23);
    xsi_vlogfile_write(1, 0, 0, ng5, 2, t0, (char)118, t24, 16);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 1344U);
    t3 = *((char **)t2);

LAB22:    t2 = ((char*)((ng2)));
    t32 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 32);
    if (t32 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng3)));
    t32 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 32);
    if (t32 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng8)));
    t32 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 32);
    if (t32 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng10)));
    t32 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 32);
    if (t32 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB20;

LAB23:    xsi_set_current_line(52, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB31;

LAB25:    xsi_set_current_line(53, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB31;

LAB27:    xsi_set_current_line(54, ng0);
    t4 = ((char*)((ng9)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB31;

LAB29:    xsi_set_current_line(55, ng0);
    t4 = ((char*)((ng11)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB31;

LAB33:    t10 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB35;

LAB34:    *((unsigned int *)t8) = 1;
    goto LAB35;

LAB37:    xsi_set_current_line(59, ng0);

LAB40:    xsi_set_current_line(60, ng0);
    t24 = (t0 + 2224);
    t30 = (t24 + 56U);
    t31 = *((char **)t30);

LAB41:    t33 = ((char*)((ng3)));
    t32 = xsi_vlog_unsigned_case_compare(t31, 3, t33, 32);
    if (t32 == 1)
        goto LAB42;

LAB43:    t2 = ((char*)((ng8)));
    t32 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t32 == 1)
        goto LAB44;

LAB45:    t2 = ((char*)((ng10)));
    t32 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t32 == 1)
        goto LAB46;

LAB47:    t2 = ((char*)((ng16)));
    t32 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t32 == 1)
        goto LAB48;

LAB49:    t2 = ((char*)((ng19)));
    t32 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t32 == 1)
        goto LAB50;

LAB51:    t2 = ((char*)((ng21)));
    t32 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t32 == 1)
        goto LAB52;

LAB53:
LAB54:    goto LAB39;

LAB42:    xsi_set_current_line(61, ng0);

LAB55:    xsi_set_current_line(63, ng0);
    t34 = ((char*)((ng1)));
    t35 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t35, t34, 0, 0, 1, 0LL);
    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(65, ng0);
    xsi_vlogfile_write(1, 0, 0, ng13, 1, t0);
    goto LAB54;

LAB44:    xsi_set_current_line(67, ng0);

LAB56:    xsi_set_current_line(68, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 1904);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 16, 0LL);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng6)));
    t4 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 15, t5, 15, t6, 15);
    t7 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t7, t8, 0, 0, 15, 0LL);
    xsi_set_current_line(74, ng0);
    xsi_vlogfile_write(1, 0, 0, ng14, 1, t0);
    goto LAB54;

LAB46:    xsi_set_current_line(76, ng0);

LAB57:    xsi_set_current_line(77, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng6)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 16, t6, 16, t7, 16);
    t9 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t9, t8, 0, 0, 16, 0LL);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 2704);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 15, t5, 15, t6, 15);
    t7 = (t0 + 2704);
    xsi_vlogvar_wait_assign_value(t7, t8, 0, 0, 15, 0LL);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 15, t5, 15, t6, 15);
    t7 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t7, t8, 0, 0, 15, 0LL);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_vlogfile_write(1, 0, 0, ng15, 2, t0, (char)118, t5, 15);
    goto LAB54;

LAB48:    xsi_set_current_line(85, ng0);

LAB58:    xsi_set_current_line(86, ng0);
    t4 = ((char*)((ng17)));
    t5 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);
    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(88, ng0);
    xsi_vlogfile_write(1, 0, 0, ng18, 1, t0);
    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    goto LAB54;

LAB50:    xsi_set_current_line(93, ng0);

LAB59:    xsi_set_current_line(94, ng0);
    t4 = (t0 + 1344U);
    t5 = *((char **)t4);
    t4 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 16, 0LL);
    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng6)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 15, t5, 15, t6, 15);
    t7 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t7, t8, 0, 0, 15, 0LL);
    xsi_set_current_line(98, ng0);
    xsi_vlogfile_write(1, 0, 0, ng20, 1, t0);
    goto LAB54;

LAB52:    xsi_set_current_line(100, ng0);

LAB60:    xsi_set_current_line(101, ng0);
    t4 = ((char*)((ng22)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB54;

}

static void Always_108_2(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;

LAB0:    t1 = (t0 + 4440U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 4776);
    *((int *)t2) = 1;
    t3 = (t0 + 4472);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(109, ng0);

LAB5:    xsi_set_current_line(110, ng0);
    t4 = (t0 + 2384);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng2)));
    memset(t8, 0, 8);
    t9 = (t6 + 4);
    t10 = (t7 + 4);
    t11 = *((unsigned int *)t6);
    t12 = *((unsigned int *)t7);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t9);
    t15 = *((unsigned int *)t10);
    t16 = (t14 ^ t15);
    t17 = (t13 | t16);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    t21 = (~(t20));
    t22 = (t17 & t21);
    if (t22 != 0)
        goto LAB9;

LAB6:    if (t20 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB9:    t24 = (t8 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t8);
    t28 = (t27 & t26);
    t29 = (t28 != 0);
    if (t29 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 2704);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1744);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 15);

LAB12:    goto LAB2;

LAB8:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(111, ng0);
    t30 = (t0 + 2864);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = (t0 + 1744);
    xsi_vlogvar_assign_value(t33, t32, 0, 0, 15);
    goto LAB12;

}


extern void work_m_00000000003810833649_1704550970_init()
{
	static char *pe[] = {(void *)Initial_36_0,(void *)Always_38_1,(void *)Always_108_2};
	xsi_register_didat("work_m_00000000003810833649_1704550970", "isim/Core_isim_beh.exe.sim/work/m_00000000003810833649_1704550970.didat");
	xsi_register_executes(pe);
}
