/**
 * Copyright (c) 2019 Western Digital Corporation or its affiliates.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * @file cpu_vcpu_sbi.h
 * @author Atish Patra (atish.patra@wdc.com)
 * @brief header file for SBI call handling
 */
#ifndef _CPU_VCPU_SBI_H__
#define _CPU_VCPU_SBI_H__

#include <vmm_types.h>

struct vmm_vcpu;
struct cpu_vcpu_trap;

#define CPU_VCPU_SBI_VERSION_MAJOR		0
#define CPU_VCPU_SBI_VERSION_MINOR		3
#define CPU_VCPU_SBI_IMPID			2

struct cpu_vcpu_sbi_extension {
	unsigned long extid_start;
	unsigned long extid_end;
	int (*handle)(struct vmm_vcpu *vcpu,
		      unsigned long ext_id, unsigned long func_id,
		      unsigned long *args, unsigned long *out_val,
		      struct cpu_vcpu_trap *out_trap);
};

const struct cpu_vcpu_sbi_extension *cpu_vcpu_sbi_find_extension(
						unsigned long ext_id);

int cpu_vcpu_sbi_ecall(struct vmm_vcpu *vcpu, ulong mcause,
		       arch_regs_t *regs);

#endif
