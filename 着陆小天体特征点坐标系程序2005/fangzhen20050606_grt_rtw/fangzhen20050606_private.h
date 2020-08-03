/*
 * fangzhen20050606_private.h
 *
 * Code generation for model "fangzhen20050606".
 *
 * Model version              : 1.221
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Fri Mar 10 19:19:15 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_fangzhen20050606_private_h_
#define RTW_HEADER_fangzhen20050606_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);

/* Exported functions */
extern void CIQW_kf_C(SimStruct *rts);
extern void CIRV_kf_C(SimStruct *rts);

/* private model entry point functions */
extern void fangzhen20050606_derivatives(void);

#endif                                 /* RTW_HEADER_fangzhen20050606_private_h_ */
