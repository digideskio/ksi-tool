/**************************************************************************
 *
 * GUARDTIME CONFIDENTIAL
 *
 * Copyright (C) [2015] Guardtime, Inc
 * All Rights Reserved
 *
 * NOTICE:  All information contained herein is, and remains, the
 * property of Guardtime Inc and its suppliers, if any.
 * The intellectual and technical concepts contained herein are
 * proprietary to Guardtime Inc and its suppliers and may be
 * covered by U.S. and Foreign Patents and patents in process,
 * and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this
 * material is strictly forbidden unless prior written permission
 * is obtained from Guardtime Inc.
 * "Guardtime" and "KSI" are trademarks or registered trademarks of
 * Guardtime Inc.
 */

#ifndef API_WRAPPER_H
#define	API_WRAPPER_H

#include "ksitool_err.h"
#include <ksi/ksi.h>

#ifdef	__cplusplus
extern "C" {
#endif


	
#define ERR_CATCH_MSG(err, res, msg, ...) \
	if (res != KT_OK) { \
		ERR_TRCKR_add(err, res, __FILE__, __LINE__, msg, ##__VA_ARGS__); \
		goto cleanup; \
	}

#define ERR_APPEND_KSI_ERR(err, res, ref_err) \
		if (res == ref_err) { \
			ERR_TRCKR_add(err, res, __FILE__, __LINE__, "Error: %s", KSI_getErrorString(res)); \
		}

int KSITOOL_extendSignature(ERR_TRCKR *err, KSI_CTX *ctx, KSI_Signature *sig, KSI_Signature **ext);	
int KSITOOL_Signature_extendTo(ERR_TRCKR *err, const KSI_Signature *signature, KSI_CTX *ctx, KSI_Integer *to, KSI_Signature **extended);	
int KSITOOL_Signature_extend(ERR_TRCKR *err, const KSI_Signature *signature, KSI_CTX *ctx, const KSI_PublicationRecord *pubRec, KSI_Signature **extended);
int KSITOOL_RequestHandle_getExtendResponse(ERR_TRCKR *err, KSI_CTX *ctx, KSI_RequestHandle *handle, KSI_ExtendResp **resp);
int KSITOOL_Signature_verify(ERR_TRCKR *err, KSI_Signature *sig, KSI_CTX *ctx);
int KSITOOL_Signature_verifyOnline(ERR_TRCKR *err, KSI_Signature *sig, KSI_CTX *ctx);
int KSITOOL_Signature_verifyDataHash(ERR_TRCKR *err, KSI_Signature *sig, KSI_CTX *ctx, KSI_DataHash *docHash);
int KSITOOL_createSignature(ERR_TRCKR *err, KSI_CTX *ctx, KSI_DataHash *dataHash, KSI_Signature **sig);
int KSITOOL_receivePublicationsFile(ERR_TRCKR *err ,KSI_CTX *ctx, KSI_PublicationsFile **pubFile);
int KSITOOL_verifyPublicationsFile(ERR_TRCKR *err, KSI_CTX *ctx, KSI_PublicationsFile *pubfile);
void KSITOOL_KSI_ERRTrace_save(KSI_CTX *ctx);
const char *KSITOOL_KSI_ERRTrace_get(void);



#ifdef	__cplusplus
}
#endif

#endif	/* API_WRAPPER_H */
