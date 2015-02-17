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

#ifndef GT_CMDCOMMON_H
#define	GT_CMDCOMMON_H


#ifdef _WIN32
#	ifndef snprintf
#		define snprintf _snprintf
#	endif
#	ifndef gmtime_r
#		define gmtime_r(time, resultp) gmtime_s(resultp, time)
#	endif
#	ifdef _DEBUG
#		define _CRTDBG_MAP_ALLOC
#		include <stdlib.h>
#		include <crtdbg.h>
#	endif
#endif

#define EXIT_INVALID_CL_PARAMETERS 3
#define EXIT_INVALID_FORMAT 4
#define EXIT_NETWORK_ERROR 5
#define EXIT_VERIFY_ERROR 6
/*Extending failure*/
#define EXIT_EXTEND_ERROR 7
/*Aggregation failure*/
#define EXIT_AGGRE_ERROR 8	
#define EXIT_IO_ERROR 9
#define EXIT_CRYPTO_ERROR 10
#define EXIT_HMAC_ERROR 11
#define EXIT_NO_PRIVILEGES 12
#define EXIT_OUT_OF_MEMORY 13
#define EXIT_AUTH_FAILURE 14

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef __cplusplus
typedef enum { false=0, true=1 } bool;
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* GTCMDCOMMON_H */