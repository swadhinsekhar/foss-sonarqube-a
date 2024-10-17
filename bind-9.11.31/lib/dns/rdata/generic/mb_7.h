/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, you can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * See the COPYRIGHT file distributed with this work for additional
 * information regarding copyright ownership.
 */

/* */
#ifndef GENERIC_MB_7_H
#define GENERIC_MB_7_H 1


typedef struct dns_rdata_mb {
	dns_rdatacommon_t	common;
	isc_mem_t		*mctx;
	dns_name_t		mb;
} dns_rdata_mb_t;

#endif /* GENERIC_MB_7_H */
