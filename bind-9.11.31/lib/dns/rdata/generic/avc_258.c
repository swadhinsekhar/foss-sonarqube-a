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

#ifndef RDATA_GENERIC_AVC_258_C
#define RDATA_GENERIC_AVC_258_C

#define RRTYPE_AVC_ATTRIBUTES (0)

static inline isc_result_t
fromtext_avc(ARGS_FROMTEXT) {

	REQUIRE(type == dns_rdatatype_avc);

	UNUSED(type);
	UNUSED(rdclass);
	UNUSED(origin);
	UNUSED(options);
	UNUSED(callbacks);

	return (generic_fromtext_txt(rdclass, type, lexer, origin, options,
				     target, callbacks));
}

static inline isc_result_t
totext_avc(ARGS_TOTEXT) {

	UNUSED(tctx);

	REQUIRE(rdata->type == dns_rdatatype_avc);

	return (generic_totext_txt(rdata, tctx, target));
}

static inline isc_result_t
fromwire_avc(ARGS_FROMWIRE) {

	REQUIRE(type == dns_rdatatype_avc);

	UNUSED(type);
	UNUSED(dctx);
	UNUSED(rdclass);
	UNUSED(options);

	return (generic_fromwire_txt(rdclass, type, source, dctx, options,
				     target));
}

static inline isc_result_t
towire_avc(ARGS_TOWIRE) {

	REQUIRE(rdata->type == dns_rdatatype_avc);

	UNUSED(cctx);

	return (mem_tobuffer(target, rdata->data, rdata->length));
}

static inline int
compare_avc(ARGS_COMPARE) {
	isc_region_t r1;
	isc_region_t r2;

	REQUIRE(rdata1->type == rdata2->type);
	REQUIRE(rdata1->rdclass == rdata2->rdclass);
	REQUIRE(rdata1->type == dns_rdatatype_avc);

	dns_rdata_toregion(rdata1, &r1);
	dns_rdata_toregion(rdata2, &r2);
	return (isc_region_compare(&r1, &r2));
}

static inline isc_result_t
fromstruct_avc(ARGS_FROMSTRUCT) {

	REQUIRE(type == dns_rdatatype_avc);

	return (generic_fromstruct_txt(rdclass, type, source, target));
}

static inline isc_result_t
tostruct_avc(ARGS_TOSTRUCT) {
	dns_rdata_avc_t *avc;

	REQUIRE(((dns_rdata_avc_t *)target) != NULL);
	REQUIRE(rdata->type == dns_rdatatype_avc);

	avc = target;

	avc->common.rdclass = rdata->rdclass;
	avc->common.rdtype = rdata->type;
	ISC_LINK_INIT(&avc->common, link);

	return (generic_tostruct_txt(rdata, target, mctx));
}

static inline void
freestruct_avc(ARGS_FREESTRUCT) {
	REQUIRE(((dns_rdata_avc_t *)source) != NULL);
	REQUIRE(((dns_rdata_avc_t *)source)->common.rdtype == dns_rdatatype_avc);

	generic_freestruct_txt(source);
}

static inline isc_result_t
additionaldata_avc(ARGS_ADDLDATA) {
	REQUIRE(rdata->type == dns_rdatatype_avc);

	UNUSED(rdata);
	UNUSED(add);
	UNUSED(arg);

	return (ISC_R_SUCCESS);
}

static inline isc_result_t
digest_avc(ARGS_DIGEST) {
	isc_region_t r;

	REQUIRE(rdata->type == dns_rdatatype_avc);

	dns_rdata_toregion(rdata, &r);

	return ((digest)(arg, &r));
}

static inline bool
checkowner_avc(ARGS_CHECKOWNER) {

	REQUIRE(type == dns_rdatatype_avc);

	UNUSED(name);
	UNUSED(type);
	UNUSED(rdclass);
	UNUSED(wildcard);

	return (true);
}

static inline bool
checknames_avc(ARGS_CHECKNAMES) {

	REQUIRE(rdata->type == dns_rdatatype_avc);

	UNUSED(rdata);
	UNUSED(owner);
	UNUSED(bad);

	return (true);
}

static inline int
casecompare_avc(ARGS_COMPARE) {
	return (compare_avc(rdata1, rdata2));
}
#endif	/* RDATA_GENERIC_AVC_258_C */
