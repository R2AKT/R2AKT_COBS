 /******************************************************************************
 *
 *    FILE NAME : r2akt_cobs.c
 *       AUTHOR : Sergey Dorozhkin (R2AKT)
 *         DATE : 08-may-2024
 *      VERSION : 0.0.1
 * MODIFICATION : 1
 *      PURPOSE : COBS library
 *          URL : https://github.com/R2AKT/r2akt_cobs
 *
 ******************************************************************************/
#ifndef R2AKT_COBS_H
	#define R2AKT_COBS_H

	#include <limits.h>
	#include <stdlib.h>
	#include <stdint.h>
	#include <stddef.h>

	#ifdef __cplusplus
		extern "C" {
	#endif
 /*****************************************************************************/

	size_t StuffData(uint8_t *dst, const uint8_t *src, size_t size);
	size_t DeStuffData(uint8_t *dst, const uint8_t *src, size_t size);

 /*****************************************************************************/
	#ifdef __cplusplus
		}           /* closing brace for extern "C" */
	#endif

#endif /* R2AKT_COBS_H */
 /************************************************************* END OF FILE ***/