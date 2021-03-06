/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (c) 2016, 2018, 2021, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __ASM_ETMV4X_H
#define __ASM_ETMV4X_H

#include <linux/types.h>


/* 32 bit register read for AArch32 */
#define trc_readl(reg)			RSYSL_##reg()
#define trc_readq(reg)			RSYSL_##reg()

/* 32 bit register write for AArch32 */
#define trc_write(val, reg)		WSYS_##reg(val)

#define MRC(op0, op1, crn, crm, op2)					    \
({									    \
uint32_t val;								    \
asm volatile("mrc p"#op0", "#op1", %0, "#crn", "#crm", "#op2 : "=r" (val)); \
val;									    \
})

#define MCR(val, op0, op1, crn, crm, op2)				    \
({									    \
asm volatile("mcr p"#op0", "#op1", %0, "#crn", "#crm", "#op2 : : "r" (val));\
})

/* Clock and Power Management Register */
#define RSYSL_CPMR_EL1()		MRC(15, 7, c15, c0, 5)
#define WSYS_CPMR_EL1(val)		MCR(val, 15, 7, c15, c0, 5)

/*
 * ETMv4 Registers
 *
 * Read only
 * ETMAUTHSTATUS, ETMDEVARCH, ETMDEVID, ETMIDRn[0-13], ETMOSLSR, ETMSTATR
 *
 * Write only
 * ETMOSLAR
 */
/* 32 bit registers */
#define RSYSL_ETMAUTHSTATUS()		MRC(14, 1, c7, c14, 6)
#define RSYSL_ETMAUXCTLR()		MRC(14, 1, c0, c6, 0)
#define RSYSL_ETMCCCTLR()		MRC(14, 1, c0, c14, 0)
#define RSYSL_ETMCIDCCTLR0()		MRC(14, 1, c3, c0, 2)
#define RSYSL_ETMCNTCTLR0()		MRC(14, 1, c0, c4, 5)
#define RSYSL_ETMCNTCTLR1()		MRC(14, 1, c0, c5, 5)
#define RSYSL_ETMCNTCTLR2()		MRC(14, 1, c0, c6, 5)
#define RSYSL_ETMCNTCTLR3()		MRC(14, 1, c0, c7, 5)
#define RSYSL_ETMCNTRLDVR0()		MRC(14, 1, c0, c0, 5)
#define RSYSL_ETMCNTRLDVR1()		MRC(14, 1, c0, c1, 5)
#define RSYSL_ETMCNTRLDVR2()		MRC(14, 1, c0, c2, 5)
#define RSYSL_ETMCNTRLDVR3()		MRC(14, 1, c0, c3, 5)
#define RSYSL_ETMCNTVR0()		MRC(14, 1, c0, c8, 5)
#define RSYSL_ETMCNTVR1()		MRC(14, 1, c0, c9, 5)
#define RSYSL_ETMCNTVR2()		MRC(14, 1, c0, c10, 5)
#define RSYSL_ETMCNTVR3()		MRC(14, 1, c0, c11, 5)
#define RSYSL_ETMCONFIGR()		MRC(14, 1, c0, c4, 0)
#define RSYSL_ETMDEVARCH()		MRC(14, 1, c7, c15, 6)
#define RSYSL_ETMDEVID()		MRC(14, 1, c7, c2, 7)
#define RSYSL_ETMEVENTCTL0R()		MRC(14, 1, c0, c8, 0)
#define RSYSL_ETMEVENTCTL1R()		MRC(14, 1, c0, c9, 0)
#define RSYSL_ETMEXTINSELR()		MRC(14, 1, c0, c8, 4)
#define RSYSL_ETMIDR0()			MRC(14, 1, c0, c8, 7)
#define RSYSL_ETMIDR1()			MRC(14, 1, c0, c9, 7)
#define RSYSL_ETMIDR10()		MRC(14, 1, c0, c2, 6)
#define RSYSL_ETMIDR11()		MRC(14, 1, c0, c3, 6)
#define RSYSL_ETMIDR12()		MRC(14, 1, c0, c4, 6)
#define RSYSL_ETMIDR13()		MRC(14, 1, c0, c5, 6)
#define RSYSL_ETMIDR2()			MRC(14, 1, c0, c10, 7)
#define RSYSL_ETMIDR3()			MRC(14, 1, c0, c11, 7)
#define RSYSL_ETMIDR4()			MRC(14, 1, c0, c12, 7)
#define RSYSL_ETMIDR5()			MRC(14, 1, c0, c13, 7)
#define RSYSL_ETMIDR6()			MRC(14, 1, c0, c14, 7)
#define RSYSL_ETMIDR7()			MRC(14, 1, c0, c15, 7)
#define RSYSL_ETMIDR8()			MRC(14, 1, c0, c0, 6)
#define RSYSL_ETMIDR9()			MRC(14, 1, c0, c1, 6)
#define RSYSL_ETMIMSPEC0()		MRC(14, 1, c0, c0, 7)
#define RSYSL_ETMOSLSR()		MRC(14, 1, c1, c1, 4)
#define RSYSL_ETMPRGCTLR()		MRC(14, 1, c0, c1, 0)
#define RSYSL_ETMRSCTLR10()		MRC(14, 1, c1, c10, 0)
#define RSYSL_ETMRSCTLR11()		MRC(14, 1, c1, c11, 0)
#define RSYSL_ETMRSCTLR12()		MRC(14, 1, c1, c12, 0)
#define RSYSL_ETMRSCTLR13()		MRC(14, 1, c1, c13, 0)
#define RSYSL_ETMRSCTLR14()		MRC(14, 1, c1, c14, 0)
#define RSYSL_ETMRSCTLR15()		MRC(14, 1, c1, c15, 0)
#define RSYSL_ETMRSCTLR2()		MRC(14, 1, c1, c2, 0)
#define RSYSL_ETMRSCTLR3()		MRC(14, 1, c1, c3, 0)
#define RSYSL_ETMRSCTLR4()		MRC(14, 1, c1, c4, 0)
#define RSYSL_ETMRSCTLR5()		MRC(14, 1, c1, c5, 0)
#define RSYSL_ETMRSCTLR6()		MRC(14, 1, c1, c6, 0)
#define RSYSL_ETMRSCTLR7()		MRC(14, 1, c1, c7, 0)
#define RSYSL_ETMRSCTLR8()		MRC(14, 1, c1, c8, 0)
#define RSYSL_ETMRSCTLR9()		MRC(14, 1, c1, c9, 0)
#define RSYSL_ETMRSCTLR16()		MRC(14, 1, c1, c0, 1)
#define RSYSL_ETMRSCTLR17()		MRC(14, 1, c1, c1, 1)
#define RSYSL_ETMRSCTLR18()		MRC(14, 1, c1, c2, 1)
#define RSYSL_ETMRSCTLR19()		MRC(14, 1, c1, c3, 1)
#define RSYSL_ETMRSCTLR20()		MRC(14, 1, c1, c4, 1)
#define RSYSL_ETMRSCTLR21()		MRC(14, 1, c1, c5, 1)
#define RSYSL_ETMRSCTLR22()		MRC(14, 1, c1, c6, 1)
#define RSYSL_ETMRSCTLR23()		MRC(14, 1, c1, c7, 1)
#define RSYSL_ETMRSCTLR24()		MRC(14, 1, c1, c8, 1)
#define RSYSL_ETMRSCTLR25()		MRC(14, 1, c1, c9, 1)
#define RSYSL_ETMRSCTLR26()		MRC(14, 1, c1, c10, 1)
#define RSYSL_ETMRSCTLR27()		MRC(14, 1, c1, c11, 1)
#define RSYSL_ETMRSCTLR28()		MRC(14, 1, c1, c12, 1)
#define RSYSL_ETMRSCTLR29()		MRC(14, 1, c1, c13, 1)
#define RSYSL_ETMRSCTLR30()		MRC(14, 1, c1, c14, 1)
#define RSYSL_ETMRSCTLR31()		MRC(14, 1, c1, c15, 1)
#define RSYSL_ETMSEQEVR0()		MRC(14, 1, c0, c0, 4)
#define RSYSL_ETMSEQEVR1()		MRC(14, 1, c0, c1, 4)
#define RSYSL_ETMSEQEVR2()		MRC(14, 1, c0, c2, 4)
#define RSYSL_ETMSEQRSTEVR()		MRC(14, 1, c0, c6, 4)
#define RSYSL_ETMSEQSTR()		MRC(14, 1, c0, c7, 4)
#define RSYSL_ETMSTALLCTLR()		MRC(14, 1, c0, c11, 0)
#define RSYSL_ETMSTATR()		MRC(14, 1, c0, c3, 0)
#define RSYSL_ETMSYNCPR()		MRC(14, 1, c0, c13, 0)
#define RSYSL_ETMTRACEIDR()		MRC(14, 1, c0, c0, 1)
#define RSYSL_ETMTSCTLR()		MRC(14, 1, c0, c12, 0)
#define RSYSL_ETMVICTLR()		MRC(14, 1, c0, c0, 2)
#define RSYSL_ETMVIIECTLR()		MRC(14, 1, c0, c1, 2)
#define RSYSL_ETMVISSCTLR()		MRC(14, 1, c0, c2, 2)
#define RSYSL_ETMSSCCR0()		MRC(14, 1, c1, c0, 2)
#define RSYSL_ETMSSCCR1()		MRC(14, 1, c1, c1, 2)
#define RSYSL_ETMSSCCR2()		MRC(14, 1, c1, c2, 2)
#define RSYSL_ETMSSCCR3()		MRC(14, 1, c1, c3, 2)
#define RSYSL_ETMSSCCR4()		MRC(14, 1, c1, c4, 2)
#define RSYSL_ETMSSCCR5()		MRC(14, 1, c1, c5, 2)
#define RSYSL_ETMSSCCR6()		MRC(14, 1, c1, c6, 2)
#define RSYSL_ETMSSCCR7()		MRC(14, 1, c1, c7, 2)
#define RSYSL_ETMSSCSR0()		MRC(14, 1, c1, c8, 2)
#define RSYSL_ETMSSCSR1()		MRC(14, 1, c1, c9, 2)
#define RSYSL_ETMSSCSR2()		MRC(14, 1, c1, c10, 2)
#define RSYSL_ETMSSCSR3()		MRC(14, 1, c1, c11, 2)
#define RSYSL_ETMSSCSR4()		MRC(14, 1, c1, c12, 2)
#define RSYSL_ETMSSCSR5()		MRC(14, 1, c1, c13, 2)
#define RSYSL_ETMSSCSR6()		MRC(14, 1, c1, c14, 2)
#define RSYSL_ETMSSCSR7()		MRC(14, 1, c1, c15, 2)
#define RSYSL_ETMSSPCICR0()		MRC(14, 1, c1, c0, 3)
#define RSYSL_ETMSSPCICR1()		MRC(14, 1, c1, c1, 3)
#define RSYSL_ETMSSPCICR2()		MRC(14, 1, c1, c2, 3)
#define RSYSL_ETMSSPCICR3()		MRC(14, 1, c1, c3, 3)
#define RSYSL_ETMSSPCICR4()		MRC(14, 1, c1, c4, 3)
#define RSYSL_ETMSSPCICR5()		MRC(14, 1, c1, c5, 3)
#define RSYSL_ETMSSPCICR6()		MRC(14, 1, c1, c6, 3)
#define RSYSL_ETMSSPCICR7()		MRC(14, 1, c1, c7, 3)

/*
 * 64 bit registers, ignore the upper 32bit
 * A read from a 32-bit register location using a 64-bit access result
 * in the upper 32bits being return as RES0.
 */
#define RSYSL_ETMACATR0()		MRC(14, 1, c2, c0, 2)
#define RSYSL_ETMACATR1()		MRC(14, 1, c2, c2, 2)
#define RSYSL_ETMACATR2()		MRC(14, 1, c2, c4, 2)
#define RSYSL_ETMACATR3()		MRC(14, 1, c2, c6, 2)
#define RSYSL_ETMACATR4()		MRC(14, 1, c2, c8, 2)
#define RSYSL_ETMACATR5()		MRC(14, 1, c2, c10, 2)
#define RSYSL_ETMACATR6()		MRC(14, 1, c2, c12, 2)
#define RSYSL_ETMACATR7()		MRC(14, 1, c2, c14, 2)
#define RSYSL_ETMACATR8()		MRC(14, 1, c2, c0, 3)
#define RSYSL_ETMACATR9()		MRC(14, 1, c2, c2, 3)
#define RSYSL_ETMACATR10()		MRC(14, 1, c2, c4, 3)
#define RSYSL_ETMACATR11()		MRC(14, 1, c2, c6, 3)
#define RSYSL_ETMACATR12()		MRC(14, 1, c2, c8, 3)
#define RSYSL_ETMACATR13()		MRC(14, 1, c2, c10, 3)
#define RSYSL_ETMACATR14()		MRC(14, 1, c2, c12, 3)
#define RSYSL_ETMACATR15()		MRC(14, 1, c2, c14, 3)
#define RSYSL_ETMCIDCVR0()		MRC(14, 1, c3, c0, 0)
#define RSYSL_ETMCIDCVR1()		MRC(14, 1, c3, c2, 0)
#define RSYSL_ETMCIDCVR2()		MRC(14, 1, c3, c4, 0)
#define RSYSL_ETMCIDCVR3()		MRC(14, 1, c3, c6, 0)
#define RSYSL_ETMCIDCVR4()		MRC(14, 1, c3, c8, 0)
#define RSYSL_ETMCIDCVR5()		MRC(14, 1, c3, c10, 0)
#define RSYSL_ETMCIDCVR6()		MRC(14, 1, c3, c12, 0)
#define RSYSL_ETMCIDCVR7()		MRC(14, 1, c3, c14, 0)
#define RSYSL_ETMACVR0()		MRC(14, 1, c2, c0, 0)
#define RSYSL_ETMACVR1()		MRC(14, 1, c2, c2, 0)
#define RSYSL_ETMACVR2()		MRC(14, 1, c2, c4, 0)
#define RSYSL_ETMACVR3()		MRC(14, 1, c2, c6, 0)
#define RSYSL_ETMACVR4()		MRC(14, 1, c2, c8, 0)
#define RSYSL_ETMACVR5()		MRC(14, 1, c2, c10, 0)
#define RSYSL_ETMACVR6()		MRC(14, 1, c2, c12, 0)
#define RSYSL_ETMACVR7()		MRC(14, 1, c2, c14, 0)
#define RSYSL_ETMACVR8()		MRC(14, 1, c2, c0, 1)
#define RSYSL_ETMACVR9()		MRC(14, 1, c2, c2, 1)
#define RSYSL_ETMACVR10()		MRC(14, 1, c2, c4, 1)
#define RSYSL_ETMACVR11()		MRC(14, 1, c2, c6, 1)
#define RSYSL_ETMACVR12()		MRC(14, 1, c2, c8, 1)
#define RSYSL_ETMACVR13()		MRC(14, 1, c2, c10, 1)
#define RSYSL_ETMACVR14()		MRC(14, 1, c2, c12, 1)
#define RSYSL_ETMACVR15()		MRC(14, 1, c2, c14, 1)
#define RSYSL_ETMVMIDCVR0()		MRC(14, 1, c3, c0, 1)
#define RSYSL_ETMVMIDCVR1()		MRC(14, 1, c3, c2, 1)
#define RSYSL_ETMVMIDCVR2()		MRC(14, 1, c3, c4, 1)
#define RSYSL_ETMVMIDCVR3()		MRC(14, 1, c3, c6, 1)
#define RSYSL_ETMVMIDCVR4()		MRC(14, 1, c3, c8, 1)
#define RSYSL_ETMVMIDCVR5()		MRC(14, 1, c3, c10, 1)
#define RSYSL_ETMVMIDCVR6()		MRC(14, 1, c3, c12, 1)
#define RSYSL_ETMVMIDCVR7()		MRC(14, 1, c3, c14, 1)
#define RSYSL_ETMDVCVR0()		MRC(14, 1, c2, c0, 4)
#define RSYSL_ETMDVCVR1()		MRC(14, 1, c2, c4, 4)
#define RSYSL_ETMDVCVR2()		MRC(14, 1, c2, c8, 4)
#define RSYSL_ETMDVCVR3()		MRC(14, 1, c2, c12, 4)
#define RSYSL_ETMDVCVR4()		MRC(14, 1, c2, c0, 5)
#define RSYSL_ETMDVCVR5()		MRC(14, 1, c2, c4, 5)
#define RSYSL_ETMDVCVR6()		MRC(14, 1, c2, c8, 5)
#define RSYSL_ETMDVCVR7()		MRC(14, 1, c2, c12, 5)
#define RSYSL_ETMDVCMR0()		MRC(14, 1, c2, c0, 6)
#define RSYSL_ETMDVCMR1()		MRC(14, 1, c2, c4, 6)
#define RSYSL_ETMDVCMR2()		MRC(14, 1, c2, c8, 6)
#define RSYSL_ETMDVCMR3()		MRC(14, 1, c2, c12, 6)
#define RSYSL_ETMDVCMR4()		MRC(14, 1, c2, c0, 7)
#define RSYSL_ETMDVCMR5()		MRC(14, 1, c2, c4, 7)
#define RSYSL_ETMDVCMR6()		MRC(14, 1, c2, c8, 7)
#define RSYSL_ETMDVCMR7()		MRC(14, 1, c2, c12, 7)

/*
 * 32 and 64 bit registers
 * A write to a 32-bit register location using a 64-bit access result
 * in the upper 32bit of access
 */
#define WSYS_ETMAUXCTLR(val)		MCR(val, 14, 1, c0, c6, 0)
#define WSYS_ETMACATR0(val)		MCR(val, 14, 1, c2, c0, 2)
#define WSYS_ETMACATR1(val)		MCR(val, 14, 1, c2, c2, 2)
#define WSYS_ETMACATR2(val)		MCR(val, 14, 1, c2, c4, 2)
#define WSYS_ETMACATR3(val)		MCR(val, 14, 1, c2, c6, 2)
#define WSYS_ETMACATR4(val)		MCR(val, 14, 1, c2, c8, 2)
#define WSYS_ETMACATR5(val)		MCR(val, 14, 1, c2, c10, 2)
#define WSYS_ETMACATR6(val)		MCR(val, 14, 1, c2, c12, 2)
#define WSYS_ETMACATR7(val)		MCR(val, 14, 1, c2, c14, 2)
#define WSYS_ETMACATR8(val)		MCR(val, 14, 1, c2, c0, 3)
#define WSYS_ETMACATR9(val)		MCR(val, 14, 1, c2, c2, 3)
#define WSYS_ETMACATR10(val)		MCR(val, 14, 1, c2, c4, 3)
#define WSYS_ETMACATR11(val)		MCR(val, 14, 1, c2, c6, 3)
#define WSYS_ETMACATR12(val)		MCR(val, 14, 1, c2, c8, 3)
#define WSYS_ETMACATR13(val)		MCR(val, 14, 1, c2, c10, 3)
#define WSYS_ETMACATR14(val)		MCR(val, 14, 1, c2, c12, 3)
#define WSYS_ETMACATR15(val)		MCR(val, 14, 1, c2, c14, 3)
#define WSYS_ETMACVR0(val)		MCR(val, 14, 1, c2, c0, 0)
#define WSYS_ETMACVR1(val)		MCR(val, 14, 1, c2, c2, 0)
#define WSYS_ETMACVR2(val)		MCR(val, 14, 1, c2, c4, 0)
#define WSYS_ETMACVR3(val)		MCR(val, 14, 1, c2, c6, 0)
#define WSYS_ETMACVR4(val)		MCR(val, 14, 1, c2, c8, 0)
#define WSYS_ETMACVR5(val)		MCR(val, 14, 1, c2, c10, 0)
#define WSYS_ETMACVR6(val)		MCR(val, 14, 1, c2, c12, 0)
#define WSYS_ETMACVR7(val)		MCR(val, 14, 1, c2, c14, 0)
#define WSYS_ETMACVR8(val)		MCR(val, 14, 1, c2, c0, 1)
#define WSYS_ETMACVR9(val)		MCR(val, 14, 1, c2, c2, 1)
#define WSYS_ETMACVR10(val)		MCR(val, 14, 1, c2, c4, 1)
#define WSYS_ETMACVR11(val)		MCR(val, 14, 1, c2, c6, 1)
#define WSYS_ETMACVR12(val)		MCR(val, 14, 1, c2, c8, 1)
#define WSYS_ETMACVR13(val)		MCR(val, 14, 1, c2, c10, 1)
#define WSYS_ETMACVR14(val)		MCR(val, 14, 1, c2, c12, 1)
#define WSYS_ETMACVR15(val)		MCR(val, 14, 1, c2, c14, 1)
#define WSYS_ETMCCCTLR(val)		MCR(val, 14, 1, c0, c14, 0)
#define WSYS_ETMCIDCCTLR0(val)		MCR(val, 14, 1, c3, c0, 2)
#define WSYS_ETMCIDCVR0(val)		MCR(val, 14, 1, c3, c0, 0)
#define WSYS_ETMCIDCVR1(val)		MCR(val, 14, 1, c3, c2, 0)
#define WSYS_ETMCIDCVR2(val)		MCR(val, 14, 1, c3, c4, 0)
#define WSYS_ETMCIDCVR3(val)		MCR(val, 14, 1, c3, c6, 0)
#define WSYS_ETMCIDCVR4(val)		MCR(val, 14, 1, c3, c8, 0)
#define WSYS_ETMCIDCVR5(val)		MCR(val, 14, 1, c3, c10, 0)
#define WSYS_ETMCIDCVR6(val)		MCR(val, 14, 1, c3, c12, 0)
#define WSYS_ETMCIDCVR7(val)		MCR(val, 14, 1, c3, c14, 0)
#define WSYS_ETMCNTCTLR0(val)		MCR(val, 14, 1, c0, c4, 5)
#define WSYS_ETMCNTCTLR1(val)		MCR(val, 14, 1, c0, c5, 5)
#define WSYS_ETMCNTCTLR2(val)		MCR(val, 14, 1, c0, c6, 5)
#define WSYS_ETMCNTCTLR3(val)		MCR(val, 14, 1, c0, c7, 5)
#define WSYS_ETMCNTRLDVR0(val)		MCR(val, 14, 1, c0, c0, 5)
#define WSYS_ETMCNTRLDVR1(val)		MCR(val, 14, 1, c0, c1, 5)
#define WSYS_ETMCNTRLDVR2(val)		MCR(val, 14, 1, c0, c2, 5)
#define WSYS_ETMCNTRLDVR3(val)		MCR(val, 14, 1, c0, c3, 5)
#define WSYS_ETMCNTVR0(val)		MCR(val, 14, 1, c0, c8, 5)
#define WSYS_ETMCNTVR1(val)		MCR(val, 14, 1, c0, c9, 5)
#define WSYS_ETMCNTVR2(val)		MCR(val, 14, 1, c0, c10, 5)
#define WSYS_ETMCNTVR3(val)		MCR(val, 14, 1, c0, c11, 5)
#define WSYS_ETMCONFIGR(val)		MCR(val, 14, 1, c0, c4, 0)
#define WSYS_ETMEVENTCTL0R(val)		MCR(val, 14, 1, c0, c8, 0)
#define WSYS_ETMEVENTCTL1R(val)		MCR(val, 14, 1, c0, c9, 0)
#define WSYS_ETMEXTINSELR(val)		MCR(val, 14, 1, c0, c8, 4)
#define WSYS_ETMIMSPEC0(val)		MCR(val, 14, 1, c0, c0, 7)
#define WSYS_ETMOSLAR(val)		MCR(val, 14, 1, c1, c0, 4)
#define WSYS_ETMPRGCTLR(val)		MCR(val, 14, 1, c0, c1, 0)
#define WSYS_ETMRSCTLR10(val)		MCR(val, 14, 1, c1, c10, 0)
#define WSYS_ETMRSCTLR11(val)		MCR(val, 14, 1, c1, c11, 0)
#define WSYS_ETMRSCTLR12(val)		MCR(val, 14, 1, c1, c12, 0)
#define WSYS_ETMRSCTLR13(val)		MCR(val, 14, 1, c1, c13, 0)
#define WSYS_ETMRSCTLR14(val)		MCR(val, 14, 1, c1, c14, 0)
#define WSYS_ETMRSCTLR15(val)		MCR(val, 14, 1, c1, c15, 0)
#define WSYS_ETMRSCTLR2(val)		MCR(val, 14, 1, c1, c2, 0)
#define WSYS_ETMRSCTLR3(val)		MCR(val, 14, 1, c1, c3, 0)
#define WSYS_ETMRSCTLR4(val)		MCR(val, 14, 1, c1, c4, 0)
#define WSYS_ETMRSCTLR5(val)		MCR(val, 14, 1, c1, c5, 0)
#define WSYS_ETMRSCTLR6(val)		MCR(val, 14, 1, c1, c6, 0)
#define WSYS_ETMRSCTLR7(val)		MCR(val, 14, 1, c1, c7, 0)
#define WSYS_ETMRSCTLR8(val)		MCR(val, 14, 1, c1, c8, 0)
#define WSYS_ETMRSCTLR9(val)		MCR(val, 14, 1, c1, c9, 0)
#define WSYS_ETMRSCTLR16(val)		MCR(val, 14, 1, c1, c0, 1)
#define WSYS_ETMRSCTLR17(val)		MCR(val, 14, 1, c1, c1, 1)
#define WSYS_ETMRSCTLR18(val)		MCR(val, 14, 1, c1, c2, 1)
#define WSYS_ETMRSCTLR19(val)		MCR(val, 14, 1, c1, c3, 1)
#define WSYS_ETMRSCTLR20(val)		MCR(val, 14, 1, c1, c4, 1)
#define WSYS_ETMRSCTLR21(val)		MCR(val, 14, 1, c1, c5, 1)
#define WSYS_ETMRSCTLR22(val)		MCR(val, 14, 1, c1, c6, 1)
#define WSYS_ETMRSCTLR23(val)		MCR(val, 14, 1, c1, c7, 1)
#define WSYS_ETMRSCTLR24(val)		MCR(val, 14, 1, c1, c8, 1)
#define WSYS_ETMRSCTLR25(val)		MCR(val, 14, 1, c1, c9, 1)
#define WSYS_ETMRSCTLR26(val)		MCR(val, 14, 1, c1, c10, 1)
#define WSYS_ETMRSCTLR27(val)		MCR(val, 14, 1, c1, c11, 1)
#define WSYS_ETMRSCTLR28(val)		MCR(val, 14, 1, c1, c12, 1)
#define WSYS_ETMRSCTLR29(val)		MCR(val, 14, 1, c1, c13, 1)
#define WSYS_ETMRSCTLR30(val)		MCR(val, 14, 1, c1, c14, 1)
#define WSYS_ETMRSCTLR31(val)		MCR(val, 14, 1, c1, c15, 1)
#define WSYS_ETMSEQEVR0(val)		MCR(val, 14, 1, c0, c0, 4)
#define WSYS_ETMSEQEVR1(val)		MCR(val, 14, 1, c0, c1, 4)
#define WSYS_ETMSEQEVR2(val)		MCR(val, 14, 1, c0, c2, 4)
#define WSYS_ETMSEQRSTEVR(val)		MCR(val, 14, 1, c0, c6, 4)
#define WSYS_ETMSEQSTR(val)		MCR(val, 14, 1, c0, c7, 4)
#define WSYS_ETMSTALLCTLR(val)		MCR(val, 14, 1, c0, c11, 0)
#define WSYS_ETMSYNCPR(val)		MCR(val, 14, 1, c0, c13, 0)
#define WSYS_ETMTRACEIDR(val)		MCR(val, 14, 1, c0, c0, 1)
#define WSYS_ETMTSCTLR(val)		MCR(val, 14, 1, c0, c12, 0)
#define WSYS_ETMVICTLR(val)		MCR(val, 14, 1, c0, c0, 2)
#define WSYS_ETMVIIECTLR(val)		MCR(val, 14, 1, c0, c1, 2)
#define WSYS_ETMVISSCTLR(val)		MCR(val, 14, 1, c0, c2, 2)
#define WSYS_ETMVMIDCVR0(val)		MCR(val, 14, 1, c3, c0, 1)
#define WSYS_ETMVMIDCVR1(val)		MCR(val, 14, 1, c3, c2, 1)
#define WSYS_ETMVMIDCVR2(val)		MCR(val, 14, 1, c3, c4, 1)
#define WSYS_ETMVMIDCVR3(val)		MCR(val, 14, 1, c3, c6, 1)
#define WSYS_ETMVMIDCVR4(val)		MCR(val, 14, 1, c3, c8, 1)
#define WSYS_ETMVMIDCVR5(val)		MCR(val, 14, 1, c3, c10, 1)
#define WSYS_ETMVMIDCVR6(val)		MCR(val, 14, 1, c3, c12, 1)
#define WSYS_ETMVMIDCVR7(val)		MCR(val, 14, 1, c3, c14, 1)
#define WSYS_ETMDVCVR0(val)		MCR(val, 14, 1, c2, c0, 4)
#define WSYS_ETMDVCVR1(val)		MCR(val, 14, 1, c2, c4, 4)
#define WSYS_ETMDVCVR2(val)		MCR(val, 14, 1, c2, c8, 4)
#define WSYS_ETMDVCVR3(val)		MCR(val, 14, 1, c2, c12, 4)
#define WSYS_ETMDVCVR4(val)		MCR(val, 14, 1, c2, c0, 5)
#define WSYS_ETMDVCVR5(val)		MCR(val, 14, 1, c2, c4, 5)
#define WSYS_ETMDVCVR6(val)		MCR(val, 14, 1, c2, c8, 5)
#define WSYS_ETMDVCVR7(val)		MCR(val, 14, 1, c2, c12, 5)
#define WSYS_ETMDVCMR0(val)		MCR(val, 14, 1, c2, c0, 6)
#define WSYS_ETMDVCMR1(val)		MCR(val, 14, 1, c2, c4, 6)
#define WSYS_ETMDVCMR2(val)		MCR(val, 14, 1, c2, c8, 6)
#define WSYS_ETMDVCMR3(val)		MCR(val, 14, 1, c2, c12, 6)
#define WSYS_ETMDVCMR4(val)		MCR(val, 14, 1, c2, c0, 7)
#define WSYS_ETMDVCMR5(val)		MCR(val, 14, 1, c2, c4, 7)
#define WSYS_ETMDVCMR6(val)		MCR(val, 14, 1, c2, c8, 7)
#define WSYS_ETMDVCMR7(val)		MCR(val, 14, 1, c2, c12, 7)
#define WSYS_ETMSSCCR0(val)		MCR(val, 14, 1, c1, c0, 2)
#define WSYS_ETMSSCCR1(val)		MCR(val, 14, 1, c1, c1, 2)
#define WSYS_ETMSSCCR2(val)		MCR(val, 14, 1, c1, c2, 2)
#define WSYS_ETMSSCCR3(val)		MCR(val, 14, 1, c1, c3, 2)
#define WSYS_ETMSSCCR4(val)		MCR(val, 14, 1, c1, c4, 2)
#define WSYS_ETMSSCCR5(val)		MCR(val, 14, 1, c1, c5, 2)
#define WSYS_ETMSSCCR6(val)		MCR(val, 14, 1, c1, c6, 2)
#define WSYS_ETMSSCCR7(val)		MCR(val, 14, 1, c1, c7, 2)
#define WSYS_ETMSSCSR0(val)		MCR(val, 14, 1, c1, c8, 2)
#define WSYS_ETMSSCSR1(val)		MCR(val, 14, 1, c1, c9, 2)
#define WSYS_ETMSSCSR2(val)		MCR(val, 14, 1, c1, c10, 2)
#define WSYS_ETMSSCSR3(val)		MCR(val, 14, 1, c1, c11, 2)
#define WSYS_ETMSSCSR4(val)		MCR(val, 14, 1, c1, c12, 2)
#define WSYS_ETMSSCSR5(val)		MCR(val, 14, 1, c1, c13, 2)
#define WSYS_ETMSSCSR6(val)		MCR(val, 14, 1, c1, c14, 2)
#define WSYS_ETMSSCSR7(val)		MCR(val, 14, 1, c1, c15, 2)
#define WSYS_ETMSSPCICR0(val)		MCR(val, 14, 1, c1, c0, 3)
#define WSYS_ETMSSPCICR1(val)		MCR(val, 14, 1, c1, c1, 3)
#define WSYS_ETMSSPCICR2(val)		MCR(val, 14, 1, c1, c2, 3)
#define WSYS_ETMSSPCICR3(val)		MCR(val, 14, 1, c1, c3, 3)
#define WSYS_ETMSSPCICR4(val)		MCR(val, 14, 1, c1, c4, 3)
#define WSYS_ETMSSPCICR5(val)		MCR(val, 14, 1, c1, c5, 3)
#define WSYS_ETMSSPCICR6(val)		MCR(val, 14, 1, c1, c6, 3)
#define WSYS_ETMSSPCICR7(val)		MCR(val, 14, 1, c1, c7, 3)

#endif
