/*
 * libxt_GLBREDIRECT: iptables target for GLB proxy alternate fallback
 * Copyright (c) 2015 Theo Julienne <theo@github.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <stdbool.h>
#include <stdio.h>

// hacks for precise, because the system linux/asm includes don't match the trusty kernel
#define _ASM_X86_POSIX_TYPES_64_H
#include "asm-generic/posix_types.h"

#include <xtables.h>
#include "ipt_glbredirect.h"

static void GLBREDIRECT_help(void)
{
	printf(
"GLBREDIRECT target options:\n"
"  none\n");
}

static const struct xt_option_entry GLBREDIRECT_opts[] = {
	XTOPT_TABLEEND,
};

static void GLBREDIRECT_parse(struct xt_option_call *cb)
{
	xtables_option_parse(cb);
}

static void GLBREDIRECT_check(struct xt_fcheck_call *cb)
{
}

static void GLBREDIRECT_print(const void *ip, const struct xt_entry_target *target,
                           int numeric)
{
	const struct ipt_proxyalt_info *info =
		(const struct ipt_proxyalt_info *)target->data;

	printf(" GLBREDIRECT ");
}

static void GLBREDIRECT_save(const void *ip, const struct xt_entry_target *target)
{

}

static struct xtables_target glbredirect_tg_reg = {
	.family        = NFPROTO_UNSPEC,
	.name          = "GLBREDIRECT",
	.version       = XTABLES_VERSION,
	.revision      = 0,
	.size          = XT_ALIGN(sizeof(struct ipt_glbredirect_info)),
	.userspacesize = XT_ALIGN(sizeof(struct ipt_glbredirect_info)),
	.help          = GLBREDIRECT_help,
	.print         = GLBREDIRECT_print,
	.save          = GLBREDIRECT_save,
	.x6_parse      = GLBREDIRECT_parse,
	.x6_fcheck     = GLBREDIRECT_check,
	.x6_options    = GLBREDIRECT_opts,
};

void _init(void)
{
	xtables_register_target(&glbredirect_tg_reg);
}