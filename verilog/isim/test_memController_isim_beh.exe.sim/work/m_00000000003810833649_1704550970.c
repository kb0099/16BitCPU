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
static const char *ng0 = "//chips.eng.utah.edu/home/aupayne/16-bit_computer/verilog/Core.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {10, 0};
static int ng4[] = {0, 0};
static int ng5[] = {1, 0};
static const char *ng6 = "instr address: %d";
static const char *ng7 = "INSTRUCTION IN: %d";
static unsigned int ng8[] = {2U, 0U};
static int ng9[] = {2, 0};
static unsigned int ng10[] = {3U, 0U};
static int ng11[] = {3, 0};
static unsigned int ng12[] = {4U, 0U};
static unsigned int ng13[] = {6U, 0U};
static const char *ng14 = "READ1";
static const char *ng15 = "WRITE";
static const char *ng16 = "ADD instr addr: %d";
static int ng17[] = {4, 0};
static unsigned int ng18[] = {9216U, 0U};
static const char *ng19 = "JUMP";
static int ng20[] = {5, 0};
static const char *ng21 = "READ2";
static int ng22[] = {6, 0};
static unsigned int ng23[] = {5U, 0U};



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
    char t32[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    unsigned int t10;
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
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t55;
    int t56;

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

LAB5:    xsi_set_current_line(40, ng0);
    t4 = (t0 + 3024);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng2)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 26, t6, 26, t7, 26);
    t9 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t9, t8, 0, 0, 26, 0LL);
    xsi_set_current_line(41, ng0);
    t2 = (t0 + 3024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t10 = *((unsigned int *)t4);
    t11 = *((unsigned int *)t5);
    t12 = (t10 ^ t11);
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t7);
    t15 = (t13 ^ t14);
    t16 = (t12 | t15);
    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t7);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB9;

LAB6:    if (t19 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t8) = 1;

LAB9:    t22 = (t8 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t8);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB2;

LAB8:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(41, ng0);

LAB13:    xsi_set_current_line(42, ng0);
    t28 = (t0 + 2384);
    t29 = (t28 + 56U);
    t30 = *((char **)t29);
    t31 = ((char*)((ng4)));
    memset(t32, 0, 8);
    t33 = (t30 + 4);
    t34 = (t31 + 4);
    t35 = *((unsigned int *)t30);
    t36 = *((unsigned int *)t31);
    t37 = (t35 ^ t36);
    t38 = *((unsigned int *)t33);
    t39 = *((unsigned int *)t34);
    t40 = (t38 ^ t39);
    t41 = (t37 | t40);
    t42 = *((unsigned int *)t33);
    t43 = *((unsigned int *)t34);
    t44 = (t42 | t43);
    t45 = (~(t44));
    t46 = (t41 & t45);
    if (t46 != 0)
        goto LAB17;

LAB14:    if (t44 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t32) = 1;

LAB17:    t48 = (t32 + 4);
    t49 = *((unsigned int *)t48);
    t50 = (~(t49));
    t51 = *((unsigned int *)t32);
    t52 = (t51 & t50);
    t53 = (t52 != 0);
    if (t53 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2224);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t8, 0, 8);
    t6 = (t4 + 4);
    t7 = (t5 + 4);
    t10 = *((unsigned int *)t4);
    t11 = *((unsigned int *)t5);
    t12 = (t10 ^ t11);
    t13 = *((unsigned int *)t6);
    t14 = *((unsigned int *)t7);
    t15 = (t13 ^ t14);
    t16 = (t12 | t15);
    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t7);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB25;

LAB22:    if (t19 != 0)
        goto LAB24;

LAB23:    *((unsigned int *)t8) = 1;

LAB25:    t22 = (t8 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t8);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB26;

LAB27:
LAB28:
LAB20:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2224);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng4)));
    memset(t8, 0, 8);
    t7 = (t5 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB41;

LAB40:    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB41;

LAB44:    if (*((unsigned int *)t5) > *((unsigned int *)t6))
        goto LAB42;

LAB43:    t28 = (t8 + 4);
    t10 = *((unsigned int *)t28);
    t11 = (~(t10));
    t12 = *((unsigned int *)t8);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB45;

LAB46:
LAB47:    goto LAB12;

LAB16:    t47 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t47) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(42, ng0);

LAB21:    xsi_set_current_line(44, ng0);
    t54 = ((char*)((ng5)));
    t55 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t55, t54, 0, 0, 1, 0LL);
    xsi_set_current_line(46, ng0);
    t2 = (t0 + 2864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng6, 2, t0, (char)118, t4, 15);
    goto LAB20;

LAB24:    t9 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(49, ng0);

LAB29:    xsi_set_current_line(50, ng0);
    t28 = (t0 + 1344U);
    t29 = *((char **)t28);
    xsi_vlogfile_write(1, 0, 0, ng7, 2, t0, (char)118, t29, 16);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 1344U);
    t3 = *((char **)t2);

LAB30:    t2 = ((char*)((ng4)));
    t56 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 32);
    if (t56 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng5)));
    t56 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 32);
    if (t56 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng9)));
    t56 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 32);
    if (t56 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng11)));
    t56 = xsi_vlog_unsigned_case_compare(t3, 16, t2, 32);
    if (t56 == 1)
        goto LAB37;

LAB38:
LAB39:    goto LAB28;

LAB31:    xsi_set_current_line(52, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB39;

LAB33:    xsi_set_current_line(53, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB39;

LAB35:    xsi_set_current_line(54, ng0);
    t4 = ((char*)((ng10)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB39;

LAB37:    xsi_set_current_line(55, ng0);
    t4 = ((char*)((ng12)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB39;

LAB41:    t22 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB43;

LAB42:    *((unsigned int *)t8) = 1;
    goto LAB43;

LAB45:    xsi_set_current_line(59, ng0);

LAB48:    xsi_set_current_line(60, ng0);
    t29 = (t0 + 2224);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);

LAB49:    t33 = ((char*)((ng5)));
    t56 = xsi_vlog_unsigned_case_compare(t31, 3, t33, 32);
    if (t56 == 1)
        goto LAB50;

LAB51:    t2 = ((char*)((ng9)));
    t56 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t56 == 1)
        goto LAB52;

LAB53:    t2 = ((char*)((ng11)));
    t56 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t56 == 1)
        goto LAB54;

LAB55:    t2 = ((char*)((ng17)));
    t56 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t56 == 1)
        goto LAB56;

LAB57:    t2 = ((char*)((ng20)));
    t56 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t56 == 1)
        goto LAB58;

LAB59:    t2 = ((char*)((ng22)));
    t56 = xsi_vlog_unsigned_case_compare(t31, 3, t2, 32);
    if (t56 == 1)
        goto LAB60;

LAB61:
LAB62:    goto LAB47;

LAB50:    xsi_set_current_line(61, ng0);

LAB63:    xsi_set_current_line(63, ng0);
    t34 = ((char*)((ng1)));
    t47 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t47, t34, 0, 0, 1, 0LL);
    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng13)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(65, ng0);
    xsi_vlogfile_write(1, 0, 0, ng14, 1, t0);
    goto LAB62;

LAB52:    xsi_set_current_line(67, ng0);

LAB64:    xsi_set_current_line(68, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 1904);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 16, 0LL);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng12)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(74, ng0);
    xsi_vlogfile_write(1, 0, 0, ng15, 1, t0);
    goto LAB62;

LAB54:    xsi_set_current_line(76, ng0);

LAB65:    xsi_set_current_line(77, ng0);
    t4 = (t0 + 2544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng2)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 16, t6, 16, t7, 16);
    t9 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t9, t8, 0, 0, 16, 0LL);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 2704);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng2)));
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
    t6 = ((char*)((ng2)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 15, t5, 15, t6, 15);
    t7 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t7, t8, 0, 0, 15, 0LL);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_vlogfile_write(1, 0, 0, ng16, 2, t0, (char)118, t5, 15);
    goto LAB62;

LAB56:    xsi_set_current_line(85, ng0);

LAB66:    xsi_set_current_line(86, ng0);
    t4 = ((char*)((ng18)));
    t5 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 15, 0LL);
    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 3, 0LL);
    xsi_set_current_line(88, ng0);
    xsi_vlogfile_write(1, 0, 0, ng19, 1, t0);
    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng1)));
    t4 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t4, t2, 0, 0, 1, 0LL);
    goto LAB62;

LAB58:    xsi_set_current_line(93, ng0);

LAB67:    xsi_set_current_line(94, ng0);
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
    t6 = ((char*)((ng2)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_add(t8, 15, t5, 15, t6, 15);
    t7 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t7, t8, 0, 0, 15, 0LL);
    xsi_set_current_line(98, ng0);
    xsi_vlogfile_write(1, 0, 0, ng21, 1, t0);
    goto LAB62;

LAB60:    xsi_set_current_line(100, ng0);

LAB68:    xsi_set_current_line(101, ng0);
    t4 = ((char*)((ng23)));
    t5 = (t0 + 2224);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 3, 0LL);
    goto LAB62;

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
    t7 = ((char*)((ng4)));
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
	xsi_register_didat("work_m_00000000003810833649_1704550970", "isim/test_memController_isim_beh.exe.sim/work/m_00000000003810833649_1704550970.didat");
	xsi_register_executes(pe);
}
