/*------------------------------------------------------------
 *                              CACTI 4.0
 *         Copyright 2005 Hewlett-Packard Development Corporation
 *                         All Rights Reserved
 *
 * Permission to use, copy, and modify this software and its documentation is
 * hereby granted only under the following terms and conditions.  Both the
 * above copyright notice and this permission notice must appear in all copies
 * of the software, derivative works or modified versions, and any portions
 * thereof, and both notices must appear in supporting documentation.
 *
 * Users of this software agree to the terms and conditions set forth herein,
 *and hereby grant back to Hewlett-Packard Company and its affiliated companies
 *("HP") a non-exclusive, unrestricted, royalty-free right and license under any
 *changes, enhancements or extensions  made to the core functions of the
 *software, including but not limited to those affording compatibility with
 *other hardware or software environments, but excluding applications which
 *incorporate this software. Users further agree to use their best efforts to
 *return to HP any such changes, enhancements or extensions that they make and
 *inform HP of noteworthy uses of this software.  Correspondence should be
 *provided to HP at:
 *
 *                       Director of Intellectual Property Licensing
 *                       Office of Strategy and Technology
 *                       Hewlett-Packard Company
 *                       1501 Page Mill Road
 *                       Palo Alto, California  94304
 *
 * This software may be distributed (but not offered for sale or transferred
 * for compensation) to third parties, provided such third parties agree to
 * abide by the terms and conditions of this notice.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND HP DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL HP
 * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 *------------------------------------------------------------*/

#ifndef LEAKAGE_H
#define LEAKAGE_H
#endif

#include <stdlib.h>

/*===================================================================*/

/*
 * The following are things you probably wouldn't want to change.
 */

/* .18 technology */

/* Common for all the Technology */
#define Bk 1.38066E-23   /* Boltzman Constant */
#define Qparam 1.602E-19 /* FIXME     */
#define Eox 3.5E-11

#define No_of_Samples 10
#define Tox_Std 0
#define Tech_Std 0
#define Vdd_Std 0
#define Vthn_Std 0
#define Vthp_Std 0

extern double Tkelvin;
extern double process_tech;
extern double tech_length0;
extern double M0n; /* Zero Bias Mobility for N-Type */
extern double M0p; /* Zero Bias Mobility for P-Type */
extern double Tox;
extern double Cox;      /* Gate Oxide Capacitance per unit area */
extern double Vnoff0;   /* Empirically Determined Model Parameter for N-Type */
                        /* FIX ME */
extern double Vpoff0;   /* Empirically Determined Model Parameter for P-Type */
extern double Nfix;     /* In the equation Voff = Vnoff0 +Nfix*(Vth0-Vthn) */
extern double Pfix;     /* In the equation Voff = Vpoff0 +Pfix*(Vth0-Vthp) */
extern double Vthn;     /* In the equation Voff = Vnoff0 +Nfix*(Vth0-Vthn) */
extern double Vthp;     /* In the equation Voff = Vpoff0 +Pfix*(Vth0-Vthp) */
extern double Vnthx;    /* In the Equation Vth = Vth0 +Vnthx*(T-300) */
extern double Vpthx;    /* In the Equation Vth = Vth0 +Vpthx*(T-300) */
extern double Vdd_init; /* Default Vdd. Can be Changed in leakage.c */
extern double Volt0;
extern double Na;   /* Empirical param for the Vdd fit */
extern double Nb;   /* Empirical param for the Vdd fit */
extern double Pa;   /* Empirical param for the Vdd fit */
extern double Pb;   /* Empirical param for the Vdd fit */
extern double NEta; /* Sub-threshold Swing Co-efficient N-Type */
extern double PEta; /* Sub-threshold Swing Co-efficient P-Type */

extern double L_nmos_d;   /* Adjusting Factor for Length */
extern double Tox_nmos_e; /* Adjusting Factor for Tox */
extern double L_pmos_d;   /* Adjusting Factor for Length */
extern double Tox_pmos_e; /* Adjusting Factor for Tox */

/* gate Vss */
extern double Vth0_gate_vss;
extern double aspect_gate_vss;

/*drowsy cache*/
extern double Vdd_low;

/*RBB*/
extern double k1_body_n;
extern double k1_body_p;
extern double vfi;

extern double VSB_NMOS;
extern double VSB_PMOS;
/* dual VT*/
extern double Vt_cell_nmos_high;
extern double Vt_cell_pmos_high;
extern double Vt_bit_nmos_low;
extern double Vt_bit_pmos_low;

/* Gate lekage for 70nm */
extern double nmos_unit_leakage;
extern double a_nmos_vdd;
extern double b_nmos_t;
extern double c_nmos_tox;

extern double pmos_unit_leakage;
extern double a_pmos_vdd;
extern double b_pmos_t;
extern double c_pmos_tox;

/* Precalculated Values for leakage */
extern double precalc_Vnthx, precalc_Vpthx;
extern double precalc_Vthermal, precalc_inv_nVthermal, precalc_inv_pVthermal;

extern double precalc_nparam2, precalc_pparam2;

extern double precalc_nparamf, precalc_pparamf;
extern double precalc_nparaml, precalc_pparaml;

extern int have_leakage_params;

/* Technology Length */

double nmos_ileakage(double aspect_ratio, double Volt, double Vth0,
                     double Tkelvin, double tox0);

double pmos_ileakage(double aspect_ratio, double Volt, double Vth0,
                     double Tkelvin, double tox0);

double nmos_ileakage_var(double aspect_ratio, double Volt, double Vth0,
                         double Tkelvin, double tox0, double tech_length);

double pmos_ileakage_var(double aspect_ratio, double Volt, double Vth0,
                         double Tkelvin, double tox0, double tech_length);

double box_mueller(double std_var, double value);

double simplified_cmos_leakage(double naspect_ratio, double paspect_ratio,
                               double nVth0, double pVth0, double *norm_nleak,
                               double *norm_pleak);

double simplified_nmos_leakage(double naspect_ratio, double nVth0);
double simplified_pmos_leakage(double paspect_ratio, double pVth0);

void precalc_leakage_params(double Volt, double Tkelvin, double tox0,
                            double tech_length);

void init_tech_params(double tech);

void init_tech_params_default_process(); // v4.1
