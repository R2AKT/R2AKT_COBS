 /******************************************************************************
 *
 *    FILE NAME : r2akt_cobs.cpp
 *       AUTHOR : Sergey Dorozhkin (R2AKT)
 *         DATE : 08-may-2024
 *      VERSION : 0.0.1
 * MODIFICATION : 1
 *      PURPOSE : COBS library
 *          URL : https://github.com/R2AKT/r2akt_cobs
 *
 ******************************************************************************/

#include "r2akt_cobs.h"
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

 /*****************************************************************************/

/*
 * StuffData byte stuffs "length" bytes of data
 * at the location pointed to by "ptr", writing
 * the output to the location pointed to by "dst".
 *
 * Returns the length of the encoded data.
 */

size_t StuffData(uint8_t *dst, const uint8_t *src, size_t size) {
	const uint8_t *start = dst, *end = src + size;
	uint8_t code, *code_ptr; /* Where to insert the leading count */

	//Stat block
    code_ptr = dst++;
    code = 1;

	while (src < end) {
		if (code != 0xFF) {
			uint8_t c = *src++;
			if (c != 0x0) {
				*dst++ = c;
				code++;
				continue;
			}
		}
		//Finish block
		*code_ptr = code;
		//Stat block
		code_ptr = dst++;
		code = 1;
	}
	*code_ptr = code;
	return dst - start;
}

 /*****************************************************************************/
/*
 * DeStuffData decodes "length" bytes of data at
 * the location pointed to by "ptr", writing the
 * output to the location pointed to by "dst".
 *
 * Returns the length of the decoded data
 * (which is guaranteed to be <= length).
 */
size_t DeStuffData(uint8_t *dst, const uint8_t *src, size_t size) {
	const uint8_t *start = dst, *end = src + size;
	uint8_t code = 0xFF, copy = 0x0;

	for (; src < end; copy--) {
		if (copy != 0x0) {
			*dst++ = *src++;
		} else {
			if (code != 0xFF)
				*dst++ = 0x0;
			copy = code = *src++;
			if (code == 0x0)
				break; /* Source length too long */
		}
	}
	return dst - start;
}

/************************************************************** END OF FILE ***/