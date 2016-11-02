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
static const char *ng0 = "C:/Users/Tim/Desktop/3710 next level/16-bit_computer/verilog/newCore.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {0, 0};
static const char *ng4 = "READ";
static int ng5[] = {2, 0};
static const char *ng6 = "ADD";
static int ng7[] = {1, 0};
static const char *ng8 = "WRITE";
static int ng9[] = {3, 0};
static const char *ng10 = "JUMP";
static unsigned int ng11[] = {2U, 0U};
static unsigned int ng12[] = {9216U, 0U};
static unsigned int ng13[] = {3U, 0U};
static int ng14[] = {8000, 0};



static void Initial_37_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(37, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2608);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Cont_47_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 5216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 3088);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6144);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 65535U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 15);
    t18 = (t0 + 6032);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_49_2(char *t0)
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

LAB0:    t1 = (t0 + 5464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 6048);
    *((int *)t2) = 1;
    t3 = (t0 + 5496);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(50, ng0);

LAB5:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 2928);
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

LAB11:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 3408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 2448);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 15);

LAB12:    goto LAB2;

LAB8:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(52, ng0);
    t30 = (t0 + 3248);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = (t0 + 2448);
    xsi_vlogvar_assign_value(t33, t32, 0, 0, 15);
    goto LAB12;

}

static void Always_57_3(char *t0)
{
    char t6[8];
    char t30[8];
    char t35[8];
    char t51[8];
    char t59[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
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
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    char *t93;
    char *t94;

LAB0:    t1 = (t0 + 5712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 6064);
    *((int *)t2) = 1;
    t3 = (t0 + 5744);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(58, ng0);

LAB5:    xsi_set_current_line(60, ng0);

LAB6:    xsi_set_current_line(61, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 2608);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(63, ng0);
    t2 = (t0 + 3888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB10;

LAB7:    if (t18 != 0)
        goto LAB9;

LAB8:    *((unsigned int *)t6) = 1;

LAB10:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 3888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB43;

LAB40:    if (t18 != 0)
        goto LAB42;

LAB41:    *((unsigned int *)t6) = 1;

LAB43:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB44;

LAB45:    xsi_set_current_line(96, ng0);
    t2 = (t0 + 3888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng11)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB65;

LAB62:    if (t18 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t6) = 1;

LAB65:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB66;

LAB67:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 3888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng13)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB87;

LAB84:    if (t18 != 0)
        goto LAB86;

LAB85:    *((unsigned int *)t6) = 1;

LAB87:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB88;

LAB89:
LAB90:
LAB68:
LAB46:
LAB13:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 3888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 2, t4, 2, t5, 2);
    t7 = (t0 + 3888);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 2, 0LL);
    xsi_set_current_line(126, ng0);
    t2 = (t0 + 3568);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 11, t4, 11, t5, 11);
    t7 = (t0 + 3568);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 11, 0LL);
    goto LAB2;

LAB9:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB10;

LAB11:    xsi_set_current_line(64, ng0);

LAB14:    xsi_set_current_line(65, ng0);
    t28 = (t0 + 1888U);
    t29 = *((char **)t28);
    t28 = (t0 + 3728);
    xsi_vlogvar_wait_assign_value(t28, t29, 0, 0, 16, 0LL);
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 1888U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB18;

LAB15:    if (t18 != 0)
        goto LAB17;

LAB16:    *((unsigned int *)t6) = 1;

LAB18:    memset(t30, 0, 8);
    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t8) != 0)
        goto LAB21;

LAB22:    t22 = (t30 + 4);
    t31 = *((unsigned int *)t30);
    t32 = (!(t31));
    t33 = *((unsigned int *)t22);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB23;

LAB24:    memcpy(t59, t30, 8);

LAB25:    t87 = (t59 + 4);
    t88 = *((unsigned int *)t87);
    t89 = (~(t88));
    t90 = *((unsigned int *)t59);
    t91 = (t90 & t89);
    t92 = (t91 != 0);
    if (t92 > 0)
        goto LAB37;

LAB38:
LAB39:    goto LAB13;

LAB17:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB18;

LAB19:    *((unsigned int *)t30) = 1;
    goto LAB22;

LAB21:    t21 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB22;

LAB23:    t28 = (t0 + 1888U);
    t29 = *((char **)t28);
    t28 = ((char*)((ng2)));
    memset(t35, 0, 8);
    t36 = (t29 + 4);
    t37 = (t28 + 4);
    t38 = *((unsigned int *)t29);
    t39 = *((unsigned int *)t28);
    t40 = (t38 ^ t39);
    t41 = *((unsigned int *)t36);
    t42 = *((unsigned int *)t37);
    t43 = (t41 ^ t42);
    t44 = (t40 | t43);
    t45 = *((unsigned int *)t36);
    t46 = *((unsigned int *)t37);
    t47 = (t45 | t46);
    t48 = (~(t47));
    t49 = (t44 & t48);
    if (t49 != 0)
        goto LAB29;

LAB26:    if (t47 != 0)
        goto LAB28;

LAB27:    *((unsigned int *)t35) = 1;

LAB29:    memset(t51, 0, 8);
    t52 = (t35 + 4);
    t53 = *((unsigned int *)t52);
    t54 = (~(t53));
    t55 = *((unsigned int *)t35);
    t56 = (t55 & t54);
    t57 = (t56 & 1U);
    if (t57 != 0)
        goto LAB30;

LAB31:    if (*((unsigned int *)t52) != 0)
        goto LAB32;

LAB33:    t60 = *((unsigned int *)t30);
    t61 = *((unsigned int *)t51);
    t62 = (t60 | t61);
    *((unsigned int *)t59) = t62;
    t63 = (t30 + 4);
    t64 = (t51 + 4);
    t65 = (t59 + 4);
    t66 = *((unsigned int *)t63);
    t67 = *((unsigned int *)t64);
    t68 = (t66 | t67);
    *((unsigned int *)t65) = t68;
    t69 = *((unsigned int *)t65);
    t70 = (t69 != 0);
    if (t70 == 1)
        goto LAB34;

LAB35:
LAB36:    goto LAB25;

LAB28:    t50 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB29;

LAB30:    *((unsigned int *)t51) = 1;
    goto LAB33;

LAB32:    t58 = (t51 + 4);
    *((unsigned int *)t51) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB33;

LAB34:    t71 = *((unsigned int *)t59);
    t72 = *((unsigned int *)t65);
    *((unsigned int *)t59) = (t71 | t72);
    t73 = (t30 + 4);
    t74 = (t51 + 4);
    t75 = *((unsigned int *)t73);
    t76 = (~(t75));
    t77 = *((unsigned int *)t30);
    t78 = (t77 & t76);
    t79 = *((unsigned int *)t74);
    t80 = (~(t79));
    t81 = *((unsigned int *)t51);
    t82 = (t81 & t80);
    t83 = (~(t78));
    t84 = (~(t82));
    t85 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t85 & t83);
    t86 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t86 & t84);
    goto LAB36;

LAB37:    xsi_set_current_line(67, ng0);
    t93 = ((char*)((ng2)));
    t94 = (t0 + 2928);
    xsi_vlogvar_wait_assign_value(t94, t93, 0, 0, 1, 0LL);
    goto LAB39;

LAB42:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB43;

LAB44:    xsi_set_current_line(71, ng0);

LAB47:    xsi_set_current_line(72, ng0);
    t28 = (t0 + 3728);
    t29 = (t28 + 56U);
    t36 = *((char **)t29);

LAB48:    t37 = ((char*)((ng3)));
    t78 = xsi_vlog_unsigned_case_compare(t36, 16, t37, 32);
    if (t78 == 1)
        goto LAB49;

LAB50:    t2 = ((char*)((ng5)));
    t78 = xsi_vlog_unsigned_case_compare(t36, 16, t2, 32);
    if (t78 == 1)
        goto LAB51;

LAB52:    t2 = ((char*)((ng7)));
    t78 = xsi_vlog_unsigned_case_compare(t36, 16, t2, 32);
    if (t78 == 1)
        goto LAB53;

LAB54:    t2 = ((char*)((ng9)));
    t78 = xsi_vlog_unsigned_case_compare(t36, 16, t2, 32);
    if (t78 == 1)
        goto LAB55;

LAB56:
LAB57:    goto LAB46;

LAB49:    xsi_set_current_line(73, ng0);

LAB58:    xsi_set_current_line(76, ng0);
    xsi_vlogfile_write(1, 0, 0, ng4, 1, t0);
    goto LAB57;

LAB51:    xsi_set_current_line(78, ng0);

LAB59:    xsi_set_current_line(79, ng0);
    t3 = (t0 + 3088);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 16, t5, 16, t7, 16);
    t8 = (t0 + 3088);
    xsi_vlogvar_wait_assign_value(t8, t6, 0, 0, 16, 0LL);
    xsi_set_current_line(81, ng0);
    xsi_vlogfile_write(1, 0, 0, ng6, 1, t0);
    goto LAB57;

LAB53:    xsi_set_current_line(83, ng0);

LAB60:    xsi_set_current_line(86, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t0 + 2608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(87, ng0);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);
    goto LAB57;

LAB55:    xsi_set_current_line(89, ng0);

LAB61:    xsi_set_current_line(90, ng0);
    t3 = (t0 + 3248);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 15, t5, 15, t7, 15);
    t8 = (t0 + 3248);
    xsi_vlogvar_wait_assign_value(t8, t6, 0, 0, 15, 0LL);
    xsi_set_current_line(91, ng0);
    xsi_vlogfile_write(1, 0, 0, ng10, 1, t0);
    goto LAB57;

LAB64:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB65;

LAB66:    xsi_set_current_line(97, ng0);

LAB69:    xsi_set_current_line(98, ng0);
    t28 = (t0 + 3728);
    t29 = (t28 + 56U);
    t37 = *((char **)t29);

LAB70:    t50 = ((char*)((ng3)));
    t78 = xsi_vlog_unsigned_case_compare(t37, 16, t50, 32);
    if (t78 == 1)
        goto LAB71;

LAB72:    t2 = ((char*)((ng5)));
    t78 = xsi_vlog_unsigned_case_compare(t37, 16, t2, 32);
    if (t78 == 1)
        goto LAB73;

LAB74:    t2 = ((char*)((ng7)));
    t78 = xsi_vlog_unsigned_case_compare(t37, 16, t2, 32);
    if (t78 == 1)
        goto LAB75;

LAB76:    t2 = ((char*)((ng9)));
    t78 = xsi_vlog_unsigned_case_compare(t37, 16, t2, 32);
    if (t78 == 1)
        goto LAB77;

LAB78:
LAB79:    goto LAB68;

LAB71:    xsi_set_current_line(99, ng0);

LAB80:    xsi_set_current_line(100, ng0);
    t52 = (t0 + 1888U);
    t58 = *((char **)t52);
    t52 = (t0 + 3088);
    xsi_vlogvar_wait_assign_value(t52, t58, 0, 0, 16, 0LL);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 3408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 15, t4, 15, t5, 15);
    t7 = (t0 + 3408);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 15, 0LL);
    xsi_set_current_line(102, ng0);
    xsi_vlogfile_write(1, 0, 0, ng4, 1, t0);
    goto LAB79;

LAB73:    xsi_set_current_line(104, ng0);

LAB81:    xsi_set_current_line(105, ng0);
    t3 = (t0 + 3408);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 15, t5, 15, t7, 15);
    t8 = (t0 + 3408);
    xsi_vlogvar_wait_assign_value(t8, t6, 0, 0, 15, 0LL);
    goto LAB79;

LAB75:    xsi_set_current_line(107, ng0);

LAB82:    xsi_set_current_line(108, ng0);
    t3 = (t0 + 3408);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 15, t5, 15, t7, 15);
    t8 = (t0 + 3408);
    xsi_vlogvar_wait_assign_value(t8, t6, 0, 0, 15, 0LL);
    xsi_set_current_line(109, ng0);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);
    goto LAB79;

LAB77:    xsi_set_current_line(111, ng0);

LAB83:    xsi_set_current_line(112, ng0);
    t3 = ((char*)((ng12)));
    t4 = (t0 + 3408);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 15, 0LL);
    xsi_set_current_line(113, ng0);
    xsi_vlogfile_write(1, 0, 0, ng10, 1, t0);
    goto LAB79;

LAB86:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB87;

LAB88:    xsi_set_current_line(119, ng0);

LAB91:    xsi_set_current_line(120, ng0);
    t28 = (t0 + 3248);
    t29 = (t28 + 56U);
    t50 = *((char **)t29);
    t52 = ((char*)((ng14)));
    memset(t30, 0, 8);
    t58 = (t50 + 4);
    if (*((unsigned int *)t58) != 0)
        goto LAB93;

LAB92:    t63 = (t52 + 4);
    if (*((unsigned int *)t63) != 0)
        goto LAB93;

LAB96:    if (*((unsigned int *)t50) > *((unsigned int *)t52))
        goto LAB94;

LAB95:    t65 = (t30 + 4);
    t31 = *((unsigned int *)t65);
    t32 = (~(t31));
    t33 = *((unsigned int *)t30);
    t34 = (t33 & t32);
    t38 = (t34 != 0);
    if (t38 > 0)
        goto LAB97;

LAB98:
LAB99:    xsi_set_current_line(122, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2928);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB90;

LAB93:    t64 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB95;

LAB94:    *((unsigned int *)t30) = 1;
    goto LAB95;

LAB97:    xsi_set_current_line(121, ng0);
    t73 = ((char*)((ng1)));
    t74 = (t0 + 3248);
    xsi_vlogvar_wait_assign_value(t74, t73, 0, 0, 15, 0LL);
    goto LAB99;

}


extern void work_m_00000000003890680343_3877527149_init()
{
	static char *pe[] = {(void *)Initial_37_0,(void *)Cont_47_1,(void *)Always_49_2,(void *)Always_57_3};
	xsi_register_didat("work_m_00000000003890680343_3877527149", "isim/TESTSTSTE_isim_beh.exe.sim/work/m_00000000003890680343_3877527149.didat");
	xsi_register_executes(pe);
}
