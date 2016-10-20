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
static const char *ng0 = "//chips.eng.utah.edu/home/aupayne/16-bit_computer/verilog/pixel_generator.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {255U, 0U};
static unsigned int ng3[] = {8192U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {8U, 0U};



static void Always_56_0(char *t0)
{
    char t6[8];
    char t18[8];
    char t27[8];
    char t35[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;

LAB0:    t1 = (t0 + 5576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 6144);
    *((int *)t2) = 1;
    t3 = (t0 + 5608);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(56, ng0);

LAB5:    xsi_set_current_line(57, ng0);
    t4 = (t0 + 2976U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t35, t6, 8);

LAB12:    t63 = (t35 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t35);
    t67 = (t66 & t65);
    t68 = (t67 != 0);
    if (t68 > 0)
        goto LAB24;

LAB25:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 3616U);
    t3 = *((char **)t2);
    t2 = (t0 + 1424);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t4);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t2);
    t11 = *((unsigned int *)t5);
    t14 = (t10 ^ t11);
    t15 = (t9 | t14);
    t16 = *((unsigned int *)t2);
    t17 = *((unsigned int *)t5);
    t21 = (t16 | t17);
    t22 = (~(t21));
    t23 = (t15 & t22);
    if (t23 != 0)
        goto LAB30;

LAB27:    if (t21 != 0)
        goto LAB29;

LAB28:    *((unsigned int *)t6) = 1;

LAB30:    t13 = (t6 + 4);
    t24 = *((unsigned int *)t13);
    t25 = (~(t24));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t25);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB31;

LAB32:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 3616U);
    t3 = *((char **)t2);
    t2 = (t0 + 1560);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t4);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t2);
    t11 = *((unsigned int *)t5);
    t14 = (t10 ^ t11);
    t15 = (t9 | t14);
    t16 = *((unsigned int *)t2);
    t17 = *((unsigned int *)t5);
    t21 = (t16 | t17);
    t22 = (~(t21));
    t23 = (t15 & t22);
    if (t23 != 0)
        goto LAB37;

LAB34:    if (t21 != 0)
        goto LAB36;

LAB35:    *((unsigned int *)t6) = 1;

LAB37:    t13 = (t6 + 4);
    t24 = *((unsigned int *)t13);
    t25 = (~(t24));
    t29 = *((unsigned int *)t6);
    t30 = (t29 & t25);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB38;

LAB39:
LAB40:
LAB33:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t19 = (t0 + 2816U);
    t20 = *((char **)t19);
    memset(t18, 0, 8);
    t19 = (t20 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB16;

LAB14:    if (*((unsigned int *)t19) == 0)
        goto LAB13;

LAB15:    t26 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t26) = 1;

LAB16:    memset(t27, 0, 8);
    t28 = (t18 + 4);
    t29 = *((unsigned int *)t28);
    t30 = (~(t29));
    t31 = *((unsigned int *)t18);
    t32 = (t31 & t30);
    t33 = (t32 & 1U);
    if (t33 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t28) != 0)
        goto LAB19;

LAB20:    t36 = *((unsigned int *)t6);
    t37 = *((unsigned int *)t27);
    t38 = (t36 | t37);
    *((unsigned int *)t35) = t38;
    t39 = (t6 + 4);
    t40 = (t27 + 4);
    t41 = (t35 + 4);
    t42 = *((unsigned int *)t39);
    t43 = *((unsigned int *)t40);
    t44 = (t42 | t43);
    *((unsigned int *)t41) = t44;
    t45 = *((unsigned int *)t41);
    t46 = (t45 != 0);
    if (t46 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB12;

LAB13:    *((unsigned int *)t18) = 1;
    goto LAB16;

LAB17:    *((unsigned int *)t27) = 1;
    goto LAB20;

LAB19:    t34 = (t27 + 4);
    *((unsigned int *)t27) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB20;

LAB21:    t47 = *((unsigned int *)t35);
    t48 = *((unsigned int *)t41);
    *((unsigned int *)t35) = (t47 | t48);
    t49 = (t6 + 4);
    t50 = (t27 + 4);
    t51 = *((unsigned int *)t49);
    t52 = (~(t51));
    t53 = *((unsigned int *)t6);
    t54 = (t53 & t52);
    t55 = *((unsigned int *)t50);
    t56 = (~(t55));
    t57 = *((unsigned int *)t27);
    t58 = (t57 & t56);
    t59 = (~(t54));
    t60 = (~(t58));
    t61 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t61 & t59);
    t62 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t62 & t60);
    goto LAB23;

LAB24:    xsi_set_current_line(58, ng0);
    t69 = ((char*)((ng1)));
    t70 = (t0 + 4176);
    xsi_vlogvar_wait_assign_value(t70, t69, 0, 0, 8, 0LL);
    goto LAB26;

LAB29:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB30;

LAB31:    xsi_set_current_line(60, ng0);
    t19 = (t0 + 4656);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    memset(t18, 0, 8);
    t28 = (t18 + 4);
    t34 = (t26 + 4);
    t32 = *((unsigned int *)t26);
    t33 = (t32 >> 0);
    t36 = (t33 & 1);
    *((unsigned int *)t18) = t36;
    t37 = *((unsigned int *)t34);
    t38 = (t37 >> 0);
    t42 = (t38 & 1);
    *((unsigned int *)t28) = t42;
    t39 = (t0 + 4496);
    xsi_vlogvar_wait_assign_value(t39, t18, 0, 0, 1, 0LL);
    goto LAB33;

LAB36:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB37;

LAB38:    xsi_set_current_line(61, ng0);

LAB41:    xsi_set_current_line(62, ng0);
    t19 = (t0 + 4496);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    t28 = (t26 + 4);
    t32 = *((unsigned int *)t28);
    t33 = (~(t32));
    t36 = *((unsigned int *)t26);
    t37 = (t36 & t33);
    t38 = (t37 != 0);
    if (t38 > 0)
        goto LAB42;

LAB43:    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4176);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);

LAB44:    goto LAB40;

LAB42:    xsi_set_current_line(63, ng0);
    t34 = ((char*)((ng2)));
    t39 = (t0 + 4176);
    xsi_vlogvar_wait_assign_value(t39, t34, 0, 0, 8, 0LL);
    goto LAB44;

}

static void Always_70_1(char *t0)
{
    char t8[8];
    char t9[8];
    char t19[8];
    char t29[8];
    char t31[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t30;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;

LAB0:    t1 = (t0 + 5824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 6160);
    *((int *)t2) = 1;
    t3 = (t0 + 5856);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(70, ng0);

LAB5:    xsi_set_current_line(72, ng0);
    t4 = (t0 + 3616U);
    t5 = *((char **)t4);

LAB6:    t4 = (t0 + 1152);
    t6 = *((char **)t4);
    t7 = xsi_vlog_unsigned_case_compare(t5, 2, t6, 32);
    if (t7 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 1288);
    t3 = *((char **)t2);
    t7 = xsi_vlog_unsigned_case_compare(t5, 2, t3, 32);
    if (t7 == 1)
        goto LAB9;

LAB10:    t2 = (t0 + 1424);
    t3 = *((char **)t2);
    t7 = xsi_vlog_unsigned_case_compare(t5, 2, t3, 32);
    if (t7 == 1)
        goto LAB11;

LAB12:
LAB14:
LAB13:    xsi_set_current_line(88, ng0);

LAB26:    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4336);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 15);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4656);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);

LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(73, ng0);

LAB16:    xsi_set_current_line(74, ng0);
    t4 = ((char*)((ng1)));
    t10 = (t0 + 3296U);
    t11 = *((char **)t10);
    memset(t9, 0, 8);
    t10 = (t9 + 4);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t11);
    t14 = (t13 >> 3);
    *((unsigned int *)t9) = t14;
    t15 = *((unsigned int *)t12);
    t16 = (t15 >> 3);
    *((unsigned int *)t10) = t16;
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 127U);
    t18 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t18 & 127U);
    t20 = (t0 + 3456U);
    t21 = *((char **)t20);
    memset(t19, 0, 8);
    t20 = (t19 + 4);
    t22 = (t21 + 4);
    t23 = *((unsigned int *)t21);
    t24 = (t23 >> 3);
    *((unsigned int *)t19) = t24;
    t25 = *((unsigned int *)t22);
    t26 = (t25 >> 3);
    *((unsigned int *)t20) = t26;
    t27 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t27 & 63U);
    t28 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t28 & 63U);
    xsi_vlogtype_concat(t8, 15, 13, 2U, t19, 6, t9, 7);
    memset(t29, 0, 8);
    xsi_vlog_unsigned_add(t29, 15, t4, 14, t8, 15);
    t30 = (t0 + 4336);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 15);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4656);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    goto LAB15;

LAB9:    xsi_set_current_line(77, ng0);

LAB17:    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 3776U);
    t6 = *((char **)t4);
    memset(t8, 0, 8);
    t4 = (t8 + 4);
    t10 = (t6 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 0);
    *((unsigned int *)t8) = t14;
    t15 = *((unsigned int *)t10);
    t16 = (t15 >> 0);
    *((unsigned int *)t4) = t16;
    t17 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t17 & 255U);
    t18 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t18 & 255U);
    t11 = ((char*)((ng4)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_lshift(t9, 15, t8, 15, t11, 2);
    t12 = (t0 + 3456U);
    t20 = *((char **)t12);
    memset(t19, 0, 8);
    t12 = (t19 + 4);
    t21 = (t20 + 4);
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 1);
    *((unsigned int *)t19) = t24;
    t25 = *((unsigned int *)t21);
    t26 = (t25 >> 1);
    *((unsigned int *)t12) = t26;
    t27 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t27 & 3U);
    t28 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t28 & 3U);
    memset(t29, 0, 8);
    xsi_vlog_unsigned_add(t29, 15, t9, 15, t19, 15);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_add(t31, 15, t2, 14, t29, 15);
    t22 = (t0 + 4336);
    xsi_vlogvar_assign_value(t22, t31, 0, 0, 15);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4656);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    goto LAB15;

LAB11:    xsi_set_current_line(81, ng0);

LAB18:    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng3)));
    t4 = (t0 + 3776U);
    t6 = *((char **)t4);
    memset(t8, 0, 8);
    t4 = (t8 + 4);
    t10 = (t6 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 0);
    *((unsigned int *)t8) = t14;
    t15 = *((unsigned int *)t10);
    t16 = (t15 >> 0);
    *((unsigned int *)t4) = t16;
    t17 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t17 & 255U);
    t18 = *((unsigned int *)t4);
    *((unsigned int *)t4) = (t18 & 255U);
    t11 = ((char*)((ng4)));
    memset(t9, 0, 8);
    xsi_vlog_unsigned_lshift(t9, 15, t8, 15, t11, 2);
    t12 = (t0 + 3456U);
    t20 = *((char **)t12);
    memset(t19, 0, 8);
    t12 = (t19 + 4);
    t21 = (t20 + 4);
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 1);
    *((unsigned int *)t19) = t24;
    t25 = *((unsigned int *)t21);
    t26 = (t25 >> 1);
    *((unsigned int *)t12) = t26;
    t27 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t27 & 3U);
    t28 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t28 & 3U);
    memset(t29, 0, 8);
    xsi_vlog_unsigned_add(t29, 15, t9, 15, t19, 15);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_add(t31, 15, t2, 14, t29, 15);
    t22 = (t0 + 4336);
    xsi_vlogvar_assign_value(t22, t31, 0, 0, 15);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3456U);
    t3 = *((char **)t2);
    memset(t8, 0, 8);
    t2 = (t8 + 4);
    t4 = (t3 + 4);
    t13 = *((unsigned int *)t3);
    t14 = (t13 >> 0);
    t15 = (t14 & 1);
    *((unsigned int *)t8) = t15;
    t16 = *((unsigned int *)t4);
    t17 = (t16 >> 0);
    t18 = (t17 & 1);
    *((unsigned int *)t2) = t18;
    t6 = ((char*)((ng1)));
    memset(t9, 0, 8);
    t10 = (t8 + 4);
    t11 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = *((unsigned int *)t6);
    t25 = (t23 ^ t24);
    t26 = *((unsigned int *)t10);
    t27 = *((unsigned int *)t11);
    t28 = (t26 ^ t27);
    t32 = (t25 | t28);
    t33 = *((unsigned int *)t10);
    t34 = *((unsigned int *)t11);
    t35 = (t33 | t34);
    t36 = (~(t35));
    t37 = (t32 & t36);
    if (t37 != 0)
        goto LAB22;

LAB19:    if (t35 != 0)
        goto LAB21;

LAB20:    *((unsigned int *)t9) = 1;

LAB22:    t20 = (t9 + 4);
    t38 = *((unsigned int *)t20);
    t39 = (~(t38));
    t40 = *((unsigned int *)t9);
    t41 = (t40 & t39);
    t42 = (t41 != 0);
    if (t42 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 3776U);
    t3 = *((char **)t2);
    t2 = (t0 + 3296U);
    t4 = *((char **)t2);
    memset(t8, 0, 8);
    t2 = (t8 + 4);
    t6 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = (t13 >> 0);
    *((unsigned int *)t8) = t14;
    t15 = *((unsigned int *)t6);
    t16 = (t15 >> 0);
    *((unsigned int *)t2) = t16;
    t17 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t17 & 7U);
    t18 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t18 & 7U);
    memset(t9, 0, 8);
    xsi_vlog_unsigned_rshift(t9, 16, t3, 16, t8, 3);
    t10 = (t0 + 4656);
    xsi_vlogvar_assign_value(t10, t9, 0, 0, 16);

LAB25:    goto LAB15;

LAB21:    t12 = (t9 + 4);
    *((unsigned int *)t9) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(84, ng0);
    t21 = (t0 + 3776U);
    t22 = *((char **)t21);
    t21 = ((char*)((ng5)));
    t30 = (t0 + 3296U);
    t43 = *((char **)t30);
    memset(t19, 0, 8);
    t30 = (t19 + 4);
    t44 = (t43 + 4);
    t45 = *((unsigned int *)t43);
    t46 = (t45 >> 0);
    *((unsigned int *)t19) = t46;
    t47 = *((unsigned int *)t44);
    t48 = (t47 >> 0);
    *((unsigned int *)t30) = t48;
    t49 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t49 & 7U);
    t50 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t50 & 7U);
    memset(t29, 0, 8);
    xsi_vlog_unsigned_add(t29, 4, t21, 4, t19, 4);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_rshift(t31, 16, t22, 16, t29, 4);
    t51 = (t0 + 4656);
    xsi_vlogvar_assign_value(t51, t31, 0, 0, 16);
    goto LAB25;

}


extern void work_m_00000000003273733715_3791432322_init()
{
	static char *pe[] = {(void *)Always_56_0,(void *)Always_70_1};
	xsi_register_didat("work_m_00000000003273733715_3791432322", "isim/vga_memCntrlr_test_isim_beh.exe.sim/work/m_00000000003273733715_3791432322.didat");
	xsi_register_executes(pe);
}
