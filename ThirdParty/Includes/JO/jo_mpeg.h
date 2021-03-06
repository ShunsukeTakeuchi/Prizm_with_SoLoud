/* public domain Simple, Minimalistic, No Allocations MPEG writer - http://jonolick.com
 *
 * Latest revisions:
 * 	1.02 (22-03-2017) Fixed AC encoding bug. 
 *                    Fixed color space bug (thx r- lyeh!)
 * 	1.01 (18-10-2016) warning fixes
 * 	1.00 (25-09-2016) initial release
 *
 * Basic usage:
 *	char *frame = new char[width*height*4]; // 4 component. RGBX format, where X is unused 
 *	FILE *fp = fopen("foo.mpg", "wb");
 *	jo_write_mpeg(fp, frame, width, height, 60);  // frame 0
 *	jo_write_mpeg(fp, frame, width, height, 60);  // frame 1
 *	jo_write_mpeg(fp, frame, width, height, 60);  // frame 2
 *	...
 *	fclose(fp);
 *
 * Notes:
 * 	Only supports 24, 25, 30, 50, or 60 fps
 *
 * 	I don't know if decoders support changing of fps, or dimensions for each frame. 
 * 	Movie players *should* support it as the spec allows it, but ...
 *
 * 	MPEG-1/2 currently has no active patents as far as I am aware.
 * 	
 *	http://dvd.sourceforge.net/dvdinfo/mpeghdrs.html
 *	http://www.cs.cornell.edu/dali/api/mpegvideo-c.html
 * */

#ifndef JO_INCLUDE_MPEG_H
#define JO_INCLUDE_MPEG_H

#include <stdio.h>

// Returns false on failure
void jo_write_mpeg(FILE *fp, const unsigned char *rgbx, int width, int height, int fps);

#endif // JO_INCLUDE_MPEG_H