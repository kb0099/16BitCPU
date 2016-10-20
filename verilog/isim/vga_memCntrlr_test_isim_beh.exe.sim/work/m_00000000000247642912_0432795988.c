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
static const char *ng0 = "//chips.eng.utah.edu/home/aupayne/16-bit_computer/verilog/vga_output.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {0, 0};



static void Initial_33_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(33, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3336);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 8);

LAB1:    return;
}

static void Initial_34_1(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(34, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 3496);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Initial_35_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(35, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 3656);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_47_3(char *t0)
{
    char t6[8];
    char t18[8];
    char t27[8];
    char t35[8];
    char t71[8];
    char t76[8];
    char t80[8];
    char t84[8];
    char t92[8];
    char t124[8];
    char t139[8];
    char t142[8];
    char t150[8];
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
    char *t73;
    char *t74;
    char *t75;
    unsigned int t77;
    char *t78;
    char *t79;
    char *t81;
    char *t82;
    char *t83;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    char *t96;
    char *t97;
    char *t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    char *t106;
    char *t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    int t116;
    int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    char *t131;
    char *t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;
    char *t137;
    char *t138;
    char *t140;
    char *t141;
    char *t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    char *t149;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    char *t154;
    char *t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    char *t164;
    char *t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    int t174;
    int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    char *t182;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    char *t188;
    char *t189;

LAB0:    t1 = (t0 + 5320U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 5640);
    *((int *)t2) = 1;
    t3 = (t0 + 5352);
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

LAB25:    xsi_set_current_line(53, ng0);

LAB28:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2776U);
    t3 = *((char **)t2);
    t2 = (t0 + 608);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    if (*((unsigned int *)t2) != 0)
        goto LAB30;

LAB29:    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB30;

LAB33:    if (*((unsigned int *)t3) < *((unsigned int *)t4))
        goto LAB32;

LAB31:    *((unsigned int *)t6) = 1;

LAB32:    memset(t18, 0, 8);
    t13 = (t6 + 4);
    t7 = *((unsigned int *)t13);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB34;

LAB35:    if (*((unsigned int *)t13) != 0)
        goto LAB36;

LAB37:    t20 = (t18 + 4);
    t14 = *((unsigned int *)t18);
    t15 = *((unsigned int *)t20);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB38;

LAB39:    memcpy(t71, t18, 8);

LAB40:    t73 = (t71 + 4);
    t61 = *((unsigned int *)t73);
    t62 = (~(t61));
    t64 = *((unsigned int *)t71);
    t65 = (t64 & t62);
    t66 = (t65 != 0);
    if (t66 > 0)
        goto LAB53;

LAB54:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3496);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB55:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2936U);
    t3 = *((char **)t2);
    t2 = (t0 + 1152);
    t4 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    if (*((unsigned int *)t2) != 0)
        goto LAB57;

LAB56:    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB57;

LAB60:    if (*((unsigned int *)t3) < *((unsigned int *)t4))
        goto LAB59;

LAB58:    *((unsigned int *)t6) = 1;

LAB59:    memset(t18, 0, 8);
    t13 = (t6 + 4);
    t7 = *((unsigned int *)t13);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB61;

LAB62:    if (*((unsigned int *)t13) != 0)
        goto LAB63;

LAB64:    t20 = (t18 + 4);
    t14 = *((unsigned int *)t18);
    t15 = *((unsigned int *)t20);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB65;

LAB66:    memcpy(t71, t18, 8);

LAB67:    t73 = (t71 + 4);
    t61 = *((unsigned int *)t73);
    t62 = (~(t61));
    t64 = *((unsigned int *)t71);
    t65 = (t64 & t62);
    t66 = (t65 != 0);
    if (t66 > 0)
        goto LAB80;

LAB81:    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3656);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB82:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2776U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    if (*((unsigned int *)t4) != 0)
        goto LAB84;

LAB83:    t5 = (t2 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB84;

LAB87:    if (*((unsigned int *)t3) < *((unsigned int *)t2))
        goto LAB86;

LAB85:    *((unsigned int *)t6) = 1;

LAB86:    memset(t18, 0, 8);
    t13 = (t6 + 4);
    t7 = *((unsigned int *)t13);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB88;

LAB89:    if (*((unsigned int *)t13) != 0)
        goto LAB90;

LAB91:    t20 = (t18 + 4);
    t14 = *((unsigned int *)t18);
    t15 = *((unsigned int *)t20);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB92;

LAB93:    memcpy(t71, t18, 8);

LAB94:    memset(t76, 0, 8);
    t73 = (t71 + 4);
    t61 = *((unsigned int *)t73);
    t62 = (~(t61));
    t64 = *((unsigned int *)t71);
    t65 = (t64 & t62);
    t66 = (t65 & 1U);
    if (t66 != 0)
        goto LAB107;

LAB108:    if (*((unsigned int *)t73) != 0)
        goto LAB109;

LAB110:    t75 = (t76 + 4);
    t67 = *((unsigned int *)t76);
    t68 = *((unsigned int *)t75);
    t77 = (t67 || t68);
    if (t77 > 0)
        goto LAB111;

LAB112:    memcpy(t92, t76, 8);

LAB113:    memset(t124, 0, 8);
    t125 = (t92 + 4);
    t126 = *((unsigned int *)t125);
    t127 = (~(t126));
    t128 = *((unsigned int *)t92);
    t129 = (t128 & t127);
    t130 = (t129 & 1U);
    if (t130 != 0)
        goto LAB126;

LAB127:    if (*((unsigned int *)t125) != 0)
        goto LAB128;

LAB129:    t132 = (t124 + 4);
    t133 = *((unsigned int *)t124);
    t134 = *((unsigned int *)t132);
    t135 = (t133 || t134);
    if (t135 > 0)
        goto LAB130;

LAB131:    memcpy(t150, t124, 8);

LAB132:    t182 = (t150 + 4);
    t183 = *((unsigned int *)t182);
    t184 = (~(t183));
    t185 = *((unsigned int *)t150);
    t186 = (t185 & t184);
    t187 = (t186 != 0);
    if (t187 > 0)
        goto LAB145;

LAB146:    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3336);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);

LAB147:
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

LAB24:    xsi_set_current_line(48, ng0);

LAB27:    xsi_set_current_line(49, ng0);
    t69 = ((char*)((ng1)));
    t70 = (t0 + 3336);
    xsi_vlogvar_wait_assign_value(t70, t69, 0, 0, 8, 0LL);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3496);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3656);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB26;

LAB30:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB32;

LAB34:    *((unsigned int *)t18) = 1;
    goto LAB37;

LAB36:    t19 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB37;

LAB38:    t26 = (t0 + 2776U);
    t28 = *((char **)t26);
    t26 = (t0 + 744);
    t34 = *((char **)t26);
    memset(t27, 0, 8);
    t26 = (t28 + 4);
    if (*((unsigned int *)t26) != 0)
        goto LAB42;

LAB41:    t39 = (t34 + 4);
    if (*((unsigned int *)t39) != 0)
        goto LAB42;

LAB45:    if (*((unsigned int *)t28) < *((unsigned int *)t34))
        goto LAB43;

LAB44:    memset(t35, 0, 8);
    t41 = (t27 + 4);
    t17 = *((unsigned int *)t41);
    t21 = (~(t17));
    t22 = *((unsigned int *)t27);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t41) != 0)
        goto LAB48;

LAB49:    t25 = *((unsigned int *)t18);
    t29 = *((unsigned int *)t35);
    t30 = (t25 & t29);
    *((unsigned int *)t71) = t30;
    t50 = (t18 + 4);
    t63 = (t35 + 4);
    t69 = (t71 + 4);
    t31 = *((unsigned int *)t50);
    t32 = *((unsigned int *)t63);
    t33 = (t31 | t32);
    *((unsigned int *)t69) = t33;
    t36 = *((unsigned int *)t69);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB40;

LAB42:    t40 = (t27 + 4);
    *((unsigned int *)t27) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB44;

LAB43:    *((unsigned int *)t27) = 1;
    goto LAB44;

LAB46:    *((unsigned int *)t35) = 1;
    goto LAB49;

LAB48:    t49 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB49;

LAB50:    t38 = *((unsigned int *)t71);
    t42 = *((unsigned int *)t69);
    *((unsigned int *)t71) = (t38 | t42);
    t70 = (t18 + 4);
    t72 = (t35 + 4);
    t43 = *((unsigned int *)t18);
    t44 = (~(t43));
    t45 = *((unsigned int *)t70);
    t46 = (~(t45));
    t47 = *((unsigned int *)t35);
    t48 = (~(t47));
    t51 = *((unsigned int *)t72);
    t52 = (~(t51));
    t54 = (t44 & t46);
    t58 = (t48 & t52);
    t53 = (~(t54));
    t55 = (~(t58));
    t56 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t56 & t53);
    t57 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t57 & t55);
    t59 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t59 & t53);
    t60 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t60 & t55);
    goto LAB52;

LAB53:    xsi_set_current_line(55, ng0);
    t74 = ((char*)((ng1)));
    t75 = (t0 + 3496);
    xsi_vlogvar_wait_assign_value(t75, t74, 0, 0, 1, 0LL);
    goto LAB55;

LAB57:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB59;

LAB61:    *((unsigned int *)t18) = 1;
    goto LAB64;

LAB63:    t19 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB64;

LAB65:    t26 = (t0 + 2936U);
    t28 = *((char **)t26);
    t26 = (t0 + 1288);
    t34 = *((char **)t26);
    memset(t27, 0, 8);
    t26 = (t28 + 4);
    if (*((unsigned int *)t26) != 0)
        goto LAB69;

LAB68:    t39 = (t34 + 4);
    if (*((unsigned int *)t39) != 0)
        goto LAB69;

LAB72:    if (*((unsigned int *)t28) < *((unsigned int *)t34))
        goto LAB70;

LAB71:    memset(t35, 0, 8);
    t41 = (t27 + 4);
    t17 = *((unsigned int *)t41);
    t21 = (~(t17));
    t22 = *((unsigned int *)t27);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB73;

LAB74:    if (*((unsigned int *)t41) != 0)
        goto LAB75;

LAB76:    t25 = *((unsigned int *)t18);
    t29 = *((unsigned int *)t35);
    t30 = (t25 & t29);
    *((unsigned int *)t71) = t30;
    t50 = (t18 + 4);
    t63 = (t35 + 4);
    t69 = (t71 + 4);
    t31 = *((unsigned int *)t50);
    t32 = *((unsigned int *)t63);
    t33 = (t31 | t32);
    *((unsigned int *)t69) = t33;
    t36 = *((unsigned int *)t69);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB77;

LAB78:
LAB79:    goto LAB67;

LAB69:    t40 = (t27 + 4);
    *((unsigned int *)t27) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB71;

LAB70:    *((unsigned int *)t27) = 1;
    goto LAB71;

LAB73:    *((unsigned int *)t35) = 1;
    goto LAB76;

LAB75:    t49 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB76;

LAB77:    t38 = *((unsigned int *)t71);
    t42 = *((unsigned int *)t69);
    *((unsigned int *)t71) = (t38 | t42);
    t70 = (t18 + 4);
    t72 = (t35 + 4);
    t43 = *((unsigned int *)t18);
    t44 = (~(t43));
    t45 = *((unsigned int *)t70);
    t46 = (~(t45));
    t47 = *((unsigned int *)t35);
    t48 = (~(t47));
    t51 = *((unsigned int *)t72);
    t52 = (~(t51));
    t54 = (t44 & t46);
    t58 = (t48 & t52);
    t53 = (~(t54));
    t55 = (~(t58));
    t56 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t56 & t53);
    t57 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t57 & t55);
    t59 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t59 & t53);
    t60 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t60 & t55);
    goto LAB79;

LAB80:    xsi_set_current_line(60, ng0);
    t74 = ((char*)((ng1)));
    t75 = (t0 + 3656);
    xsi_vlogvar_wait_assign_value(t75, t74, 0, 0, 1, 0LL);
    goto LAB82;

LAB84:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB86;

LAB88:    *((unsigned int *)t18) = 1;
    goto LAB91;

LAB90:    t19 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB91;

LAB92:    t26 = (t0 + 2776U);
    t28 = *((char **)t26);
    t26 = (t0 + 472);
    t34 = *((char **)t26);
    memset(t27, 0, 8);
    t26 = (t28 + 4);
    if (*((unsigned int *)t26) != 0)
        goto LAB96;

LAB95:    t39 = (t34 + 4);
    if (*((unsigned int *)t39) != 0)
        goto LAB96;

LAB99:    if (*((unsigned int *)t28) < *((unsigned int *)t34))
        goto LAB97;

LAB98:    memset(t35, 0, 8);
    t41 = (t27 + 4);
    t17 = *((unsigned int *)t41);
    t21 = (~(t17));
    t22 = *((unsigned int *)t27);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB100;

LAB101:    if (*((unsigned int *)t41) != 0)
        goto LAB102;

LAB103:    t25 = *((unsigned int *)t18);
    t29 = *((unsigned int *)t35);
    t30 = (t25 & t29);
    *((unsigned int *)t71) = t30;
    t50 = (t18 + 4);
    t63 = (t35 + 4);
    t69 = (t71 + 4);
    t31 = *((unsigned int *)t50);
    t32 = *((unsigned int *)t63);
    t33 = (t31 | t32);
    *((unsigned int *)t69) = t33;
    t36 = *((unsigned int *)t69);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB104;

LAB105:
LAB106:    goto LAB94;

LAB96:    t40 = (t27 + 4);
    *((unsigned int *)t27) = 1;
    *((unsigned int *)t40) = 1;
    goto LAB98;

LAB97:    *((unsigned int *)t27) = 1;
    goto LAB98;

LAB100:    *((unsigned int *)t35) = 1;
    goto LAB103;

LAB102:    t49 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB103;

LAB104:    t38 = *((unsigned int *)t71);
    t42 = *((unsigned int *)t69);
    *((unsigned int *)t71) = (t38 | t42);
    t70 = (t18 + 4);
    t72 = (t35 + 4);
    t43 = *((unsigned int *)t18);
    t44 = (~(t43));
    t45 = *((unsigned int *)t70);
    t46 = (~(t45));
    t47 = *((unsigned int *)t35);
    t48 = (~(t47));
    t51 = *((unsigned int *)t72);
    t52 = (~(t51));
    t54 = (t44 & t46);
    t58 = (t48 & t52);
    t53 = (~(t54));
    t55 = (~(t58));
    t56 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t56 & t53);
    t57 = *((unsigned int *)t69);
    *((unsigned int *)t69) = (t57 & t55);
    t59 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t59 & t53);
    t60 = *((unsigned int *)t71);
    *((unsigned int *)t71) = (t60 & t55);
    goto LAB106;

LAB107:    *((unsigned int *)t76) = 1;
    goto LAB110;

LAB109:    t74 = (t76 + 4);
    *((unsigned int *)t76) = 1;
    *((unsigned int *)t74) = 1;
    goto LAB110;

LAB111:    t78 = (t0 + 2936U);
    t79 = *((char **)t78);
    t78 = ((char*)((ng3)));
    memset(t80, 0, 8);
    t81 = (t79 + 4);
    if (*((unsigned int *)t81) != 0)
        goto LAB115;

LAB114:    t82 = (t78 + 4);
    if (*((unsigned int *)t82) != 0)
        goto LAB115;

LAB118:    if (*((unsigned int *)t79) < *((unsigned int *)t78))
        goto LAB117;

LAB116:    *((unsigned int *)t80) = 1;

LAB117:    memset(t84, 0, 8);
    t85 = (t80 + 4);
    t86 = *((unsigned int *)t85);
    t87 = (~(t86));
    t88 = *((unsigned int *)t80);
    t89 = (t88 & t87);
    t90 = (t89 & 1U);
    if (t90 != 0)
        goto LAB119;

LAB120:    if (*((unsigned int *)t85) != 0)
        goto LAB121;

LAB122:    t93 = *((unsigned int *)t76);
    t94 = *((unsigned int *)t84);
    t95 = (t93 & t94);
    *((unsigned int *)t92) = t95;
    t96 = (t76 + 4);
    t97 = (t84 + 4);
    t98 = (t92 + 4);
    t99 = *((unsigned int *)t96);
    t100 = *((unsigned int *)t97);
    t101 = (t99 | t100);
    *((unsigned int *)t98) = t101;
    t102 = *((unsigned int *)t98);
    t103 = (t102 != 0);
    if (t103 == 1)
        goto LAB123;

LAB124:
LAB125:    goto LAB113;

LAB115:    t83 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t83) = 1;
    goto LAB117;

LAB119:    *((unsigned int *)t84) = 1;
    goto LAB122;

LAB121:    t91 = (t84 + 4);
    *((unsigned int *)t84) = 1;
    *((unsigned int *)t91) = 1;
    goto LAB122;

LAB123:    t104 = *((unsigned int *)t92);
    t105 = *((unsigned int *)t98);
    *((unsigned int *)t92) = (t104 | t105);
    t106 = (t76 + 4);
    t107 = (t84 + 4);
    t108 = *((unsigned int *)t76);
    t109 = (~(t108));
    t110 = *((unsigned int *)t106);
    t111 = (~(t110));
    t112 = *((unsigned int *)t84);
    t113 = (~(t112));
    t114 = *((unsigned int *)t107);
    t115 = (~(t114));
    t116 = (t109 & t111);
    t117 = (t113 & t115);
    t118 = (~(t116));
    t119 = (~(t117));
    t120 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t120 & t118);
    t121 = *((unsigned int *)t98);
    *((unsigned int *)t98) = (t121 & t119);
    t122 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t122 & t118);
    t123 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t123 & t119);
    goto LAB125;

LAB126:    *((unsigned int *)t124) = 1;
    goto LAB129;

LAB128:    t131 = (t124 + 4);
    *((unsigned int *)t124) = 1;
    *((unsigned int *)t131) = 1;
    goto LAB129;

LAB130:    t136 = (t0 + 2936U);
    t137 = *((char **)t136);
    t136 = (t0 + 1016);
    t138 = *((char **)t136);
    memset(t139, 0, 8);
    t136 = (t137 + 4);
    if (*((unsigned int *)t136) != 0)
        goto LAB134;

LAB133:    t140 = (t138 + 4);
    if (*((unsigned int *)t140) != 0)
        goto LAB134;

LAB137:    if (*((unsigned int *)t137) < *((unsigned int *)t138))
        goto LAB135;

LAB136:    memset(t142, 0, 8);
    t143 = (t139 + 4);
    t144 = *((unsigned int *)t143);
    t145 = (~(t144));
    t146 = *((unsigned int *)t139);
    t147 = (t146 & t145);
    t148 = (t147 & 1U);
    if (t148 != 0)
        goto LAB138;

LAB139:    if (*((unsigned int *)t143) != 0)
        goto LAB140;

LAB141:    t151 = *((unsigned int *)t124);
    t152 = *((unsigned int *)t142);
    t153 = (t151 & t152);
    *((unsigned int *)t150) = t153;
    t154 = (t124 + 4);
    t155 = (t142 + 4);
    t156 = (t150 + 4);
    t157 = *((unsigned int *)t154);
    t158 = *((unsigned int *)t155);
    t159 = (t157 | t158);
    *((unsigned int *)t156) = t159;
    t160 = *((unsigned int *)t156);
    t161 = (t160 != 0);
    if (t161 == 1)
        goto LAB142;

LAB143:
LAB144:    goto LAB132;

LAB134:    t141 = (t139 + 4);
    *((unsigned int *)t139) = 1;
    *((unsigned int *)t141) = 1;
    goto LAB136;

LAB135:    *((unsigned int *)t139) = 1;
    goto LAB136;

LAB138:    *((unsigned int *)t142) = 1;
    goto LAB141;

LAB140:    t149 = (t142 + 4);
    *((unsigned int *)t142) = 1;
    *((unsigned int *)t149) = 1;
    goto LAB141;

LAB142:    t162 = *((unsigned int *)t150);
    t163 = *((unsigned int *)t156);
    *((unsigned int *)t150) = (t162 | t163);
    t164 = (t124 + 4);
    t165 = (t142 + 4);
    t166 = *((unsigned int *)t124);
    t167 = (~(t166));
    t168 = *((unsigned int *)t164);
    t169 = (~(t168));
    t170 = *((unsigned int *)t142);
    t171 = (~(t170));
    t172 = *((unsigned int *)t165);
    t173 = (~(t172));
    t174 = (t167 & t169);
    t175 = (t171 & t173);
    t176 = (~(t174));
    t177 = (~(t175));
    t178 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t178 & t176);
    t179 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t179 & t177);
    t180 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t180 & t176);
    t181 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t181 & t177);
    goto LAB144;

LAB145:    xsi_set_current_line(66, ng0);
    t188 = (t0 + 2616U);
    t189 = *((char **)t188);
    t188 = (t0 + 3336);
    xsi_vlogvar_wait_assign_value(t188, t189, 0, 0, 8, 0LL);
    goto LAB147;

}


extern void work_m_00000000000247642912_0432795988_init()
{
	static char *pe[] = {(void *)Initial_33_0,(void *)Initial_34_1,(void *)Initial_35_2,(void *)Always_47_3};
	xsi_register_didat("work_m_00000000000247642912_0432795988", "isim/vga_memCntrlr_test_isim_beh.exe.sim/work/m_00000000000247642912_0432795988.didat");
	xsi_register_executes(pe);
}
