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
static unsigned int ng3[] = {2U, 0U};
static int ng4[] = {0, 0};
static const char *ng5 = "READ";
static int ng6[] = {2, 0};
static const char *ng7 = "ADD";
static int ng8[] = {1, 0};
static const char *ng9 = "WRITE";
static int ng10[] = {3, 0};
static const char *ng11 = "JUMP";
static unsigned int ng12[] = {3U, 0U};
static unsigned int ng13[] = {9216U, 0U};



static void Initial_37_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(37, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2064);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Cont_43_1(char *t0)
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

LAB0:    t1 = (t0 + 4672U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 2544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 5600);
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
    t18 = (t0 + 5488);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Always_45_2(char *t0)
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

LAB0:    t1 = (t0 + 4920U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 5504);
    *((int *)t2) = 1;
    t3 = (t0 + 4952);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(46, ng0);

LAB5:    xsi_set_current_line(47, ng0);
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

LAB11:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 2864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1904);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 15);

LAB12:    goto LAB2;

LAB8:    t23 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(48, ng0);
    t30 = (t0 + 2704);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = (t0 + 1904);
    xsi_vlogvar_assign_value(t33, t32, 0, 0, 15);
    goto LAB12;

}

static void Always_53_3(char *t0)
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

LAB0:    t1 = (t0 + 5168U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 5520);
    *((int *)t2) = 1;
    t3 = (t0 + 5200);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(54, ng0);

LAB5:    xsi_set_current_line(56, ng0);

LAB6:    xsi_set_current_line(57, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 3344);
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

LAB12:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 3344);
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
        goto LAB18;

LAB15:    if (t18 != 0)
        goto LAB17;

LAB16:    *((unsigned int *)t6) = 1;

LAB18:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 3344);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
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
        goto LAB51;

LAB48:    if (t18 != 0)
        goto LAB50;

LAB49:    *((unsigned int *)t6) = 1;

LAB51:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB52;

LAB53:    xsi_set_current_line(96, ng0);
    t2 = (t0 + 3344);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng12)));
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
        goto LAB73;

LAB70:    if (t18 != 0)
        goto LAB72;

LAB71:    *((unsigned int *)t6) = 1;

LAB73:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB74;

LAB75:
LAB76:
LAB54:
LAB21:
LAB13:    xsi_set_current_line(119, ng0);
    t2 = (t0 + 3344);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 2, t4, 2, t5, 2);
    t7 = (t0 + 3344);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 2, 0LL);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 3024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 26, t4, 26, t5, 26);
    t7 = (t0 + 3024);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 26, 0LL);
    goto LAB2;

LAB9:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB10;

LAB11:    xsi_set_current_line(60, ng0);

LAB14:    goto LAB13;

LAB17:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB18;

LAB19:    xsi_set_current_line(65, ng0);

LAB22:    xsi_set_current_line(66, ng0);
    t28 = (t0 + 1344U);
    t29 = *((char **)t28);
    t28 = (t0 + 3184);
    xsi_vlogvar_wait_assign_value(t28, t29, 0, 0, 16, 0LL);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 1344U);
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
        goto LAB26;

LAB23:    if (t18 != 0)
        goto LAB25;

LAB24:    *((unsigned int *)t6) = 1;

LAB26:    memset(t30, 0, 8);
    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t8) != 0)
        goto LAB29;

LAB30:    t22 = (t30 + 4);
    t31 = *((unsigned int *)t30);
    t32 = (!(t31));
    t33 = *((unsigned int *)t22);
    t34 = (t32 || t33);
    if (t34 > 0)
        goto LAB31;

LAB32:    memcpy(t59, t30, 8);

LAB33:    t87 = (t59 + 4);
    t88 = *((unsigned int *)t87);
    t89 = (~(t88));
    t90 = *((unsigned int *)t59);
    t91 = (t90 & t89);
    t92 = (t91 != 0);
    if (t92 > 0)
        goto LAB45;

LAB46:
LAB47:    goto LAB21;

LAB25:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB26;

LAB27:    *((unsigned int *)t30) = 1;
    goto LAB30;

LAB29:    t21 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB30;

LAB31:    t28 = (t0 + 1344U);
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
        goto LAB37;

LAB34:    if (t47 != 0)
        goto LAB36;

LAB35:    *((unsigned int *)t35) = 1;

LAB37:    memset(t51, 0, 8);
    t52 = (t35 + 4);
    t53 = *((unsigned int *)t52);
    t54 = (~(t53));
    t55 = *((unsigned int *)t35);
    t56 = (t55 & t54);
    t57 = (t56 & 1U);
    if (t57 != 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t52) != 0)
        goto LAB40;

LAB41:    t60 = *((unsigned int *)t30);
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
        goto LAB42;

LAB43:
LAB44:    goto LAB33;

LAB36:    t50 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t50) = 1;
    goto LAB37;

LAB38:    *((unsigned int *)t51) = 1;
    goto LAB41;

LAB40:    t58 = (t51 + 4);
    *((unsigned int *)t51) = 1;
    *((unsigned int *)t58) = 1;
    goto LAB41;

LAB42:    t71 = *((unsigned int *)t59);
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
    goto LAB44;

LAB45:    xsi_set_current_line(68, ng0);
    t93 = ((char*)((ng2)));
    t94 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t94, t93, 0, 0, 1, 0LL);
    goto LAB47;

LAB50:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB51;

LAB52:    xsi_set_current_line(72, ng0);

LAB55:    xsi_set_current_line(73, ng0);
    t28 = (t0 + 3184);
    t29 = (t28 + 56U);
    t36 = *((char **)t29);

LAB56:    t37 = ((char*)((ng4)));
    t78 = xsi_vlog_unsigned_case_compare(t36, 16, t37, 32);
    if (t78 == 1)
        goto LAB57;

LAB58:    t2 = ((char*)((ng6)));
    t78 = xsi_vlog_unsigned_case_compare(t36, 16, t2, 32);
    if (t78 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng8)));
    t78 = xsi_vlog_unsigned_case_compare(t36, 16, t2, 32);
    if (t78 == 1)
        goto LAB61;

LAB62:    t2 = ((char*)((ng10)));
    t78 = xsi_vlog_unsigned_case_compare(t36, 16, t2, 32);
    if (t78 == 1)
        goto LAB63;

LAB64:
LAB65:    goto LAB54;

LAB57:    xsi_set_current_line(74, ng0);

LAB66:    xsi_set_current_line(77, ng0);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);
    goto LAB65;

LAB59:    xsi_set_current_line(79, ng0);

LAB67:    xsi_set_current_line(80, ng0);
    t3 = (t0 + 2544);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 16, t5, 16, t7, 16);
    t8 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t8, t6, 0, 0, 16, 0LL);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 2704);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 15, t4, 15, t5, 15);
    t7 = (t0 + 2704);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 15, 0LL);
    xsi_set_current_line(82, ng0);
    xsi_vlogfile_write(1, 0, 0, ng7, 1, t0);
    goto LAB65;

LAB61:    xsi_set_current_line(84, ng0);

LAB68:    xsi_set_current_line(87, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 2064);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(88, ng0);
    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    goto LAB65;

LAB63:    xsi_set_current_line(90, ng0);

LAB69:    xsi_set_current_line(91, ng0);
    xsi_vlogfile_write(1, 0, 0, ng11, 1, t0);
    goto LAB65;

LAB72:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB73;

LAB74:    xsi_set_current_line(97, ng0);

LAB77:    xsi_set_current_line(98, ng0);
    t28 = (t0 + 3184);
    t29 = (t28 + 56U);
    t37 = *((char **)t29);

LAB78:    t50 = ((char*)((ng4)));
    t78 = xsi_vlog_unsigned_case_compare(t37, 16, t50, 32);
    if (t78 == 1)
        goto LAB79;

LAB80:    t2 = ((char*)((ng6)));
    t78 = xsi_vlog_unsigned_case_compare(t37, 16, t2, 32);
    if (t78 == 1)
        goto LAB81;

LAB82:    t2 = ((char*)((ng8)));
    t78 = xsi_vlog_unsigned_case_compare(t37, 16, t2, 32);
    if (t78 == 1)
        goto LAB83;

LAB84:    t2 = ((char*)((ng10)));
    t78 = xsi_vlog_unsigned_case_compare(t37, 16, t2, 32);
    if (t78 == 1)
        goto LAB85;

LAB86:
LAB87:    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2384);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB76;

LAB79:    xsi_set_current_line(99, ng0);

LAB88:    xsi_set_current_line(100, ng0);
    t52 = (t0 + 1344U);
    t58 = *((char **)t52);
    t52 = (t0 + 2544);
    xsi_vlogvar_wait_assign_value(t52, t58, 0, 0, 16, 0LL);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 2864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 15, t4, 15, t5, 15);
    t7 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t7, t6, 0, 0, 15, 0LL);
    xsi_set_current_line(102, ng0);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);
    goto LAB87;

LAB81:    xsi_set_current_line(104, ng0);

LAB89:    xsi_set_current_line(105, ng0);
    t3 = (t0 + 2864);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 15, t5, 15, t7, 15);
    t8 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t8, t6, 0, 0, 15, 0LL);
    goto LAB87;

LAB83:    xsi_set_current_line(107, ng0);

LAB90:    xsi_set_current_line(108, ng0);
    t3 = (t0 + 2864);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t7 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 15, t5, 15, t7, 15);
    t8 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t8, t6, 0, 0, 15, 0LL);
    xsi_set_current_line(109, ng0);
    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    goto LAB87;

LAB85:    xsi_set_current_line(111, ng0);

LAB91:    xsi_set_current_line(112, ng0);
    t3 = ((char*)((ng13)));
    t4 = (t0 + 2864);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 15, 0LL);
    xsi_set_current_line(113, ng0);
    xsi_vlogfile_write(1, 0, 0, ng11, 1, t0);
    goto LAB87;

}


extern void work_m_00000000000762748931_3877527149_init()
{
	static char *pe[] = {(void *)Initial_37_0,(void *)Cont_43_1,(void *)Always_45_2,(void *)Always_53_3};
	xsi_register_didat("work_m_00000000000762748931_3877527149", "isim/TESTSTSTE_isim_beh.exe.sim/work/m_00000000000762748931_3877527149.didat");
	xsi_register_executes(pe);
}
