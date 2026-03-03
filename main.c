/*------------------------------------------------------------
 *                              CACTI 3.0
 *               Copyright 2002 Compaq Computer Corporation
 *                         All Rights Reserved
 *
 * Permission to use, copy, and modify this software and its documentation is
 * hereby granted only under the following terms and conditions.  Both the
 * above copyright notice and this permission notice must appear in all copies
 * of the software, derivative works or modified versions, and any portions
 * thereof, and both notices must appear in supporting documentation.
 *
 * Users of this software agree to the terms and conditions set forth herein,
 * and hereby grant back to Compaq a non-exclusive, unrestricted, royalty-
 * free right and license under any changes, enhancements or extensions
 * made to the core functions of the software, including but not limited to
 * those affording compatibility with other hardware or software
 * environments, but excluding applications which incorporate this software.
 * Users further agree to use their best efforts to return to Compaq any
 * such changes, enhancements or extensions that they make and inform Compaq
 * of noteworthy uses of this software.  Correspondence should be provided
 * to Compaq at:
 *
 *                       Director of Licensing
 *                       Western Research Laboratory
 *                       Compaq Computer Corporation
 *                       250 University Avenue
 *                       Palo Alto, California  94301
 *
 * This software may be distributed (but not offered for sale or transferred
 * for compensation) to third parties, provided such third parties agree to
 * abide by the terms and conditions of this notice.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND COMPAQ COMPUTER CORP. DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL COMPAQ COMPUTER
 * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 *------------------------------------------------------------*/

#include "def.h"
#include "areadef.h"
#include "stdio.h"



/*------------------------------------------------------------------------------*/
      
main(argc,argv)
int argc;
char *argv[];
{
    result_type result;
    arearesult_type arearesult;
    area_type arearesult_subbanked;
    parameter_type parameters;
    double NSubbanks;

    if (input_data(argc,argv,&parameters,&NSubbanks) == ERROR) exit(0);

    calculate_time(&result,&arearesult,&arearesult_subbanked,&parameters,&NSubbanks);
    output_data(&result,&arearesult,&arearesult_subbanked,&parameters,&NSubbanks);
}
