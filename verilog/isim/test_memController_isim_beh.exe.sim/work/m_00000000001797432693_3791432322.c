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
static int ng2[] = {8, 0};
static unsigned int ng3[] = {8U, 0U};
static unsigned int ng4[] = {32767U, 32767U};
static unsigned int ng5[] = {8192U, 0U};
static unsigned int ng6[] = {2U, 0U};



static void Always_47_0(char *t0)
{
    char t6[8];
    char t18[8];
    char t27[8];
    char t35[8];
    char t71[8];
    char t73[8];
    char t79[8];
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
    char *t72;
    char *t74;
    char *t75;
    char *t76;
    unsigned int t77;
    unsigned int t78;
    char *t80;

LAB0:    t1 = (t0 + 4576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 5144);
    *((int *)t2) = 1;
    t3 = (t0 + 4608);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(47, ng0);

LAB5:    xsi_set_current_line(48, ng0);
    t4 = (t0 + 2296U);
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

LAB25:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 2936U);
    t3 = *((char **)t2);
    t2 = (t0 + 744);
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

LAB32:
LAB33:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t19 = (t0 + 2136U);
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

LAB24:    xsi_set_current_line(49, ng0);
    t69 = ((char*)((ng1)));
    t70 = (t0 + 3496);
    xsi_vlogvar_wait_assign_value(t70, t69, 0, 0, 8, 0LL);
    goto LAB26;

LAB29:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB30;

LAB31:    xsi_set_current_line(51, ng0);

LAB34:    xsi_set_current_line(53, ng0);
    t19 = (t0 + 2776U);
    t20 = *((char **)t19);
    memset(t18, 0, 8);
    t19 = (t18 + 4);
    t26 = (t20 + 4);
    t32 = *((unsigned int *)t20);
    t33 = (t32 >> 0);
    t36 = (t33 & 1);
    *((unsigned int *)t18) = t36;
    t37 = *((unsigned int *)t26);
    t38 = (t37 >> 0);
    t42 = (t38 & 1);
    *((unsigned int *)t19) = t42;
    t28 = ((char*)((ng1)));
    memset(t27, 0, 8);
    t34 = (t18 + 4);
    t39 = (t28 + 4);
    t43 = *((unsigned int *)t18);
    t44 = *((unsigned int *)t28);
    t45 = (t43 ^ t44);
    t46 = *((unsigned int *)t34);
    t47 = *((unsigned int *)t39);
    t48 = (t46 ^ t47);
    t51 = (t45 | t48);
    t52 = *((unsigned int *)t34);
    t53 = *((unsigned int *)t39);
    t55 = (t52 | t53);
    t56 = (~(t55));
    t57 = (t51 & t56);
    if (t57 != 0)
        goto LAB38;

LAB35:    if (t55 != 0)
        goto LAB37;

LAB36:    *((unsigned int *)t27) = 1;

LAB38:    t41 = (t27 + 4);
    t59 = *((unsigned int *)t41);
    t60 = (~(t59));
    t61 = *((unsigned int *)t27);
    t62 = (t61 & t60);
    t64 = (t62 != 0);
    if (t64 > 0)
        goto LAB39;

LAB40:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3096U);
    t4 = *((char **)t3);
    t3 = (t0 + 3056U);
    t5 = (t3 + 72U);
    t12 = *((char **)t5);
    t13 = (t0 + 2616U);
    t19 = *((char **)t13);
    memset(t27, 0, 8);
    t13 = (t27 + 4);
    t20 = (t19 + 4);
    t7 = *((unsigned int *)t19);
    t8 = (t7 >> 0);
    *((unsigned int *)t27) = t8;
    t9 = *((unsigned int *)t20);
    t10 = (t9 >> 0);
    *((unsigned int *)t13) = t10;
    t11 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t11 & 7U);
    t14 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t14 & 7U);
    xsi_vlog_generic_get_index_select_value(t18, 1, t4, t12, 2, t27, 3, 2);
    xsi_vlog_mul_concat(t6, 8, 1, t2, 1U, t18, 1);
    t26 = (t0 + 3496);
    xsi_vlogvar_wait_assign_value(t26, t6, 0, 0, 8, 0LL);

LAB41:    goto LAB33;

LAB37:    t40 = (t27 + 4);
    *((unsigned int *)t27) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB38;

LAB39:    xsi_set_current_line(55, ng0);
    t49 = ((char*)((ng2)));
    t50 = (t0 + 3096U);
    t63 = *((char **)t50);
    t50 = (t0 + 3056U);
    t69 = (t50 + 72U);
    t70 = *((char **)t69);
    t72 = ((char*)((ng3)));
    t74 = (t0 + 2616U);
    t75 = *((char **)t74);
    memset(t73, 0, 8);
    t74 = (t73 + 4);
    t76 = (t75 + 4);
    t65 = *((unsigned int *)t75);
    t66 = (t65 >> 0);
    *((unsigned int *)t73) = t66;
    t67 = *((unsigned int *)t76);
    t68 = (t67 >> 0);
    *((unsigned int *)t74) = t68;
    t77 = *((unsigned int *)t73);
    *((unsigned int *)t73) = (t77 & 7U);
    t78 = *((unsigned int *)t74);
    *((unsigned int *)t74) = (t78 & 7U);
    memset(t79, 0, 8);
    xsi_vlog_unsigned_add(t79, 4, t72, 4, t73, 4);
    xsi_vlog_generic_get_index_select_value(t71, 1, t63, t70, 2, t79, 4, 2);
    xsi_vlog_mul_concat(t35, 8, 1, t49, 1U, t71, 1);
    t80 = (t0 + 3496);
    xsi_vlogvar_wait_assign_value(t80, t35, 0, 0, 8, 0LL);
    goto LAB41;

}

static void Always_63_1(char *t0)
{
    char t7[8];
    char t8[8];
    char t17[8];
    char t27[8];
    char t29[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t28;
    char *t30;

LAB0:    t1 = (t0 + 4824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 5160);
    *((int *)t2) = 1;
    t3 = (t0 + 4856);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(63, ng0);

LAB5:    xsi_set_current_line(66, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 3656);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 15);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 2936U);
    t3 = *((char **)t2);

LAB6:    t2 = (t0 + 472);
    t4 = *((char **)t2);
    t6 = xsi_vlog_unsigned_case_compare(t3, 2, t4, 32);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = (t0 + 608);
    t4 = *((char **)t2);
    t6 = xsi_vlog_unsigned_case_compare(t3, 2, t4, 32);
    if (t6 == 1)
        goto LAB9;

LAB10:
LAB11:    goto LAB2;

LAB7:    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng1)));
    t5 = (t0 + 2616U);
    t9 = *((char **)t5);
    memset(t8, 0, 8);
    t5 = (t8 + 4);
    t10 = (t9 + 4);
    t11 = *((unsigned int *)t9);
    t12 = (t11 >> 3);
    *((unsigned int *)t8) = t12;
    t13 = *((unsigned int *)t10);
    t14 = (t13 >> 3);
    *((unsigned int *)t5) = t14;
    t15 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t15 & 127U);
    t16 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t16 & 127U);
    t18 = (t0 + 2776U);
    t19 = *((char **)t18);
    memset(t17, 0, 8);
    t18 = (t17 + 4);
    t20 = (t19 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (t21 >> 3);
    *((unsigned int *)t17) = t22;
    t23 = *((unsigned int *)t20);
    t24 = (t23 >> 3);
    *((unsigned int *)t18) = t24;
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 & 63U);
    t26 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t26 & 63U);
    xsi_vlogtype_concat(t7, 15, 13, 2U, t17, 6, t8, 7);
    memset(t27, 0, 8);
    xsi_vlog_unsigned_add(t27, 15, t2, 14, t7, 15);
    t28 = (t0 + 3656);
    xsi_vlogvar_assign_value(t28, t27, 0, 0, 15);
    goto LAB11;

LAB9:    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng5)));
    t5 = (t0 + 3096U);
    t9 = *((char **)t5);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t10 = (t9 + 4);
    t11 = *((unsigned int *)t9);
    t12 = (t11 >> 0);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t10);
    t14 = (t13 >> 0);
    *((unsigned int *)t5) = t14;
    t15 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t15 & 255U);
    t16 = *((unsigned int *)t5);
    *((unsigned int *)t5) = (t16 & 255U);
    t18 = ((char*)((ng6)));
    memset(t8, 0, 8);
    xsi_vlog_unsigned_lshift(t8, 15, t7, 15, t18, 2);
    t19 = (t0 + 2776U);
    t20 = *((char **)t19);
    memset(t17, 0, 8);
    t19 = (t17 + 4);
    t28 = (t20 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (t21 >> 1);
    *((unsigned int *)t17) = t22;
    t23 = *((unsigned int *)t28);
    t24 = (t23 >> 1);
    *((unsigned int *)t19) = t24;
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 & 3U);
    t26 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t26 & 3U);
    memset(t27, 0, 8);
    xsi_vlog_unsigned_add(t27, 15, t8, 15, t17, 15);
    memset(t29, 0, 8);
    xsi_vlog_unsigned_add(t29, 15, t2, 14, t27, 15);
    t30 = (t0 + 3656);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 15);
    goto LAB11;

}


extern void work_m_00000000001797432693_3791432322_init()
{
	static char *pe[] = {(void *)Always_47_0,(void *)Always_63_1};
	xsi_register_didat("work_m_00000000001797432693_3791432322", "isim/test_memController_isim_beh.exe.sim/work/m_00000000001797432693_3791432322.didat");
	xsi_register_executes(pe);
}
