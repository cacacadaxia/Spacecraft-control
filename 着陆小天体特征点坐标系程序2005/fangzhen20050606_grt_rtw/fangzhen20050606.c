/*
 * fangzhen20050606.c
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
#include "fangzhen20050606.h"
#include "fangzhen20050606_private.h"

/* Block signals (auto storage) */
BlockIO_fangzhen20050606 fangzhen20050606_B;

/* Continuous states */
ContinuousStates_fangzhen20050606 fangzhen20050606_X;

/* Block states (auto storage) */
D_Work_fangzhen20050606 fangzhen20050606_DWork;

/* Real-time model */
RT_MODEL_fangzhen20050606 fangzhen20050606_M_;
RT_MODEL_fangzhen20050606 *const fangzhen20050606_M = &fangzhen20050606_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (fangzhen20050606_M->Timing.TaskCounters.TID[2])++;
  if ((fangzhen20050606_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.2s, 0.0s] */
    fangzhen20050606_M->Timing.TaskCounters.TID[2] = 0;
  }

  fangzhen20050606_M->Timing.sampleHits[2] =
    (fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0);
  (fangzhen20050606_M->Timing.TaskCounters.TID[3])++;
  if ((fangzhen20050606_M->Timing.TaskCounters.TID[3]) > 9) {/* Sample time: [0.5s, 0.0s] */
    fangzhen20050606_M->Timing.TaskCounters.TID[3] = 0;
  }

  fangzhen20050606_M->Timing.sampleHits[3] =
    (fangzhen20050606_M->Timing.TaskCounters.TID[3] == 0);
  (fangzhen20050606_M->Timing.TaskCounters.TID[4])++;
  if ((fangzhen20050606_M->Timing.TaskCounters.TID[4]) > 39) {/* Sample time: [2.0s, 0.0s] */
    fangzhen20050606_M->Timing.TaskCounters.TID[4] = 0;
  }

  fangzhen20050606_M->Timing.sampleHits[4] =
    (fangzhen20050606_M->Timing.TaskCounters.TID[4] == 0);
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 23;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  fangzhen20050606_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  fangzhen20050606_output();
  fangzhen20050606_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  fangzhen20050606_output();
  fangzhen20050606_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  fangzhen20050606_output();
  fangzhen20050606_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  return sqrt(-2.0 * log(si) / si) * sr;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u;
  int32_T u_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u = 1;
    } else {
      u = -1;
    }

    if (u1 > 0.0) {
      u_0 = 1;
    } else {
      u_0 = -1;
    }

    y = atan2((real_T)u, (real_T)u_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void fangzhen20050606_output(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T rtb_Switch[3];
  real_T rtb_Integrator[4];
  real_T rtb_TmpSignalConversionAtToWork[7];
  real_T rtb_Integrator1[3];
  real_T rtb_TmpSignalConversionAtToWo_o[6];
  real_T rtb_TmpSignalConversionAtToW_of[13];
  real_T rtb_Sum2_fk;
  real_T rtb_Gain_in[3];
  real_T rtb_Sum1_a[4];
  real_T rtb_Pitch;
  real_T rtb_Product_dn;
  real_T rtb_Yaw;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_RelationalOperator1;
  boolean_T rtb_LogicalOperator1;
  real_T rtb_AWcc[3];
  real_T rtb_Product_ht[3];
  real_T rtb_Roll;
  real_T rtb_Product2_bk;
  real_T rtb_Product1_jh;
  real_T rtb_MatrixGain2[3];
  real_T rtb_MatrixGain_k[3];
  real_T rtb_Sum2_l[3];
  real_T rtb_Add;
  int8_T rtAction;
  real_T rtb_Product1_ck;
  boolean_T rtb_RelationalOperator_l;
  real_T rtb_VectorConcatenate[9];
  real_T rtb_Gain1_nt;
  real_T rtb_MathFunction_n[9];
  int32_T i;
  real_T tmp[9];
  real_T tmp_0[4];
  real_T tmp_1[3];
  boolean_T rtb_AND1_idx;
  boolean_T rtb_AND1_idx_0;
  real_T rtb_Product_by_idx;
  real_T rtb_Product_by_idx_0;
  real_T rtb_Product_by_idx_1;
  real_T rtb_Product_by_idx_2;
  real_T rtb_Product_by_idx_3;
  real_T rtb_Product_by_idx_4;
  if (rtmIsMajorTimeStep(fangzhen20050606_M)) {
    /* set solver stop time */
    if (!(fangzhen20050606_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&fangzhen20050606_M->solverInfo,
                            ((fangzhen20050606_M->Timing.clockTickH0 + 1) *
        fangzhen20050606_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&fangzhen20050606_M->solverInfo,
                            ((fangzhen20050606_M->Timing.clockTick0 + 1) *
        fangzhen20050606_M->Timing.stepSize0 +
        fangzhen20050606_M->Timing.clockTickH0 *
        fangzhen20050606_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(fangzhen20050606_M)) {
    fangzhen20050606_M->Timing.t[0] = rtsiGetT(&fangzhen20050606_M->solverInfo);
  }

  /* Clock: '<Root>/Clock' */
  fangzhen20050606_B.Clock = fangzhen20050606_M->Timing.t[0];

  /* Clock: '<S87>/Clock' */
  rtb_Pitch = fangzhen20050606_M->Timing.t[0];

  /* Gain: '<S87>/Wcc' */
  rtb_Integrator1[0] = fangzhen20050606_P.Wcc_Gain[0] * rtb_Pitch;
  rtb_Integrator1[1] = fangzhen20050606_P.Wcc_Gain[1] * rtb_Pitch;
  rtb_Integrator1[2] = fangzhen20050606_P.Wcc_Gain[2] * rtb_Pitch;

  /* Gain: '<S87>/AWcc' incorporates:
   *  Trigonometry: '<S87>/Trigonometric Function'
   */
  rtb_AWcc[0] = fangzhen20050606_P.AWcc_Gain[0] * sin(rtb_Integrator1[0]);
  rtb_AWcc[1] = fangzhen20050606_P.AWcc_Gain[1] * sin(rtb_Integrator1[1]);
  rtb_AWcc[2] = fangzhen20050606_P.AWcc_Gain[2] * sin(rtb_Integrator1[2]);
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S9>/Constant1' */
    fangzhen20050606_B.Constant1[0] = fangzhen20050606_P.Constant1_Value_k[0];
    fangzhen20050606_B.Constant1[1] = fangzhen20050606_P.Constant1_Value_k[1];
    fangzhen20050606_B.Constant1[2] = fangzhen20050606_P.Constant1_Value_k[2];
  }

  /* Integrator: '<S9>/Integrator1' */
  if (fangzhen20050606_DWork.Integrator1_IWORK.IcNeedsLoading) {
    fangzhen20050606_X.Integrator1_CSTATE[0] = fangzhen20050606_B.Constant1[0];
    fangzhen20050606_X.Integrator1_CSTATE[1] = fangzhen20050606_B.Constant1[1];
    fangzhen20050606_X.Integrator1_CSTATE[2] = fangzhen20050606_B.Constant1[2];
  }

  rtb_Integrator1[0] = fangzhen20050606_X.Integrator1_CSTATE[0];
  rtb_Integrator1[1] = fangzhen20050606_X.Integrator1_CSTATE[1];
  rtb_Integrator1[2] = fangzhen20050606_X.Integrator1_CSTATE[2];

  /* Gain: '<S9>/InvIBu' */
  for (i = 0; i < 3; i++) {
    rtb_Product_ht[i] = fangzhen20050606_P.InvIBu_Gain[i + 6] * rtb_Integrator1
      [2] + (fangzhen20050606_P.InvIBu_Gain[i + 3] * rtb_Integrator1[1] +
             fangzhen20050606_P.InvIBu_Gain[i] * rtb_Integrator1[0]);
  }

  /* End of Gain: '<S9>/InvIBu' */
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* RandomNumber: '<S87>/Noign' */
    fangzhen20050606_B.Noign[0] = fangzhen20050606_DWork.NextOutput[0];
    fangzhen20050606_B.Noign[1] = fangzhen20050606_DWork.NextOutput[1];
    fangzhen20050606_B.Noign[2] = fangzhen20050606_DWork.NextOutput[2];
  }

  /* Saturate: '<S87>/Wgmax' */
  if (rtb_Product_ht[0] >= fangzhen20050606_P.Wgmax_UpperSat[0]) {
    rtb_Add = fangzhen20050606_P.Wgmax_UpperSat[0];
  } else if (rtb_Product_ht[0] <= fangzhen20050606_P.Wgmax_LowerSat[0]) {
    rtb_Add = fangzhen20050606_P.Wgmax_LowerSat[0];
  } else {
    rtb_Add = rtb_Product_ht[0];
  }

  /* Sum: '<S87>/Sum' incorporates:
   *  Constant: '<S87>/Noigc'
   *  Integrator: '<S87>/Integrator'
   *  Saturate: '<S87>/Wgmax'
   */
  fangzhen20050606_B.Sum[0] = (((fangzhen20050606_P.Noigc_Value[0] + rtb_AWcc[0])
    + rtb_Add) + fangzhen20050606_B.Noign[0]) +
    fangzhen20050606_X.Integrator_CSTATE[0];

  /* Saturate: '<S87>/Wgmax' */
  if (rtb_Product_ht[1] >= fangzhen20050606_P.Wgmax_UpperSat[1]) {
    rtb_Add = fangzhen20050606_P.Wgmax_UpperSat[1];
  } else if (rtb_Product_ht[1] <= fangzhen20050606_P.Wgmax_LowerSat[1]) {
    rtb_Add = fangzhen20050606_P.Wgmax_LowerSat[1];
  } else {
    rtb_Add = rtb_Product_ht[1];
  }

  /* Sum: '<S87>/Sum' incorporates:
   *  Constant: '<S87>/Noigc'
   *  Integrator: '<S87>/Integrator'
   *  Saturate: '<S87>/Wgmax'
   */
  fangzhen20050606_B.Sum[1] = (((fangzhen20050606_P.Noigc_Value[1] + rtb_AWcc[1])
    + rtb_Add) + fangzhen20050606_B.Noign[1]) +
    fangzhen20050606_X.Integrator_CSTATE[1];

  /* Saturate: '<S87>/Wgmax' */
  if (rtb_Product_ht[2] >= fangzhen20050606_P.Wgmax_UpperSat[2]) {
    rtb_Add = fangzhen20050606_P.Wgmax_UpperSat[2];
  } else if (rtb_Product_ht[2] <= fangzhen20050606_P.Wgmax_LowerSat[2]) {
    rtb_Add = fangzhen20050606_P.Wgmax_LowerSat[2];
  } else {
    rtb_Add = rtb_Product_ht[2];
  }

  /* Sum: '<S87>/Sum' incorporates:
   *  Constant: '<S87>/Noigc'
   *  Integrator: '<S87>/Integrator'
   *  Saturate: '<S87>/Wgmax'
   */
  fangzhen20050606_B.Sum[2] = (((fangzhen20050606_P.Noigc_Value[2] + rtb_AWcc[2])
    + rtb_Add) + fangzhen20050606_B.Noign[2]) +
    fangzhen20050606_X.Integrator_CSTATE[2];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S10>/Constant3' */
    fangzhen20050606_B.Constant3[0] = fangzhen20050606_P.Constant3_Value[0];
    fangzhen20050606_B.Constant3[1] = fangzhen20050606_P.Constant3_Value[1];
    fangzhen20050606_B.Constant3[2] = fangzhen20050606_P.Constant3_Value[2];
    fangzhen20050606_B.Constant3[3] = fangzhen20050606_P.Constant3_Value[3];
  }

  /* Integrator: '<S10>/Integrator' */
  if (fangzhen20050606_DWork.Integrator_IWORK.IcNeedsLoading) {
    fangzhen20050606_X.Integrator_CSTATE_a[0] = fangzhen20050606_B.Constant3[0];
    fangzhen20050606_X.Integrator_CSTATE_a[1] = fangzhen20050606_B.Constant3[1];
    fangzhen20050606_X.Integrator_CSTATE_a[2] = fangzhen20050606_B.Constant3[2];
    fangzhen20050606_X.Integrator_CSTATE_a[3] = fangzhen20050606_B.Constant3[3];
  }

  rtb_Integrator[0] = fangzhen20050606_X.Integrator_CSTATE_a[0];
  rtb_Integrator[1] = fangzhen20050606_X.Integrator_CSTATE_a[1];
  rtb_Integrator[2] = fangzhen20050606_X.Integrator_CSTATE_a[2];
  rtb_Integrator[3] = fangzhen20050606_X.Integrator_CSTATE_a[3];

  /* Sum: '<S23>/Sum' incorporates:
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   *  Product: '<S23>/Product2'
   *  Product: '<S23>/Product3'
   */
  rtb_Pitch = ((rtb_Integrator[0] * rtb_Integrator[0] + rtb_Integrator[1] *
                rtb_Integrator[1]) + rtb_Integrator[2] * rtb_Integrator[2]) +
    rtb_Integrator[3] * rtb_Integrator[3];

  /* Sqrt: '<S22>/sqrt' */
  rtb_Pitch = sqrt(rtb_Pitch);

  /* Product: '<S21>/Product' */
  rtb_Roll = rtb_Integrator[0] / rtb_Pitch;

  /* Product: '<S21>/Product1' */
  rtb_Product2_bk = rtb_Integrator[1] / rtb_Pitch;

  /* Product: '<S21>/Product2' */
  rtb_Product1_jh = rtb_Integrator[2] / rtb_Pitch;

  /* Product: '<S21>/Product3' */
  rtb_Pitch = rtb_Integrator[3] / rtb_Pitch;

  /* Sum: '<S11>/Sum' incorporates:
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   */
  fangzhen20050606_B.VectorConcatenate[0] = ((rtb_Roll * rtb_Roll +
    rtb_Product2_bk * rtb_Product2_bk) - rtb_Product1_jh * rtb_Product1_jh) -
    rtb_Pitch * rtb_Pitch;

  /* Gain: '<S14>/Gain' incorporates:
   *  Product: '<S14>/Product2'
   *  Product: '<S14>/Product3'
   *  Sum: '<S14>/Sum'
   */
  fangzhen20050606_B.VectorConcatenate[1] = (rtb_Product2_bk * rtb_Product1_jh -
    rtb_Pitch * rtb_Roll) * fangzhen20050606_P.Gain_Gain_k;

  /* Gain: '<S17>/Gain' incorporates:
   *  Product: '<S17>/Product1'
   *  Product: '<S17>/Product2'
   *  Sum: '<S17>/Sum'
   */
  fangzhen20050606_B.VectorConcatenate[2] = (rtb_Roll * rtb_Product1_jh +
    rtb_Product2_bk * rtb_Pitch) * fangzhen20050606_P.Gain_Gain_ab;

  /* Gain: '<S12>/Gain' incorporates:
   *  Product: '<S12>/Product2'
   *  Product: '<S12>/Product3'
   *  Sum: '<S12>/Sum'
   */
  fangzhen20050606_B.VectorConcatenate[3] = (rtb_Pitch * rtb_Roll +
    rtb_Product2_bk * rtb_Product1_jh) * fangzhen20050606_P.Gain_Gain_c;

  /* Sum: '<S15>/Sum' incorporates:
   *  Product: '<S15>/Product'
   *  Product: '<S15>/Product1'
   *  Product: '<S15>/Product2'
   *  Product: '<S15>/Product3'
   */
  fangzhen20050606_B.VectorConcatenate[4] = ((rtb_Roll * rtb_Roll -
    rtb_Product2_bk * rtb_Product2_bk) + rtb_Product1_jh * rtb_Product1_jh) -
    rtb_Pitch * rtb_Pitch;

  /* Gain: '<S18>/Gain' incorporates:
   *  Product: '<S18>/Product1'
   *  Product: '<S18>/Product2'
   *  Sum: '<S18>/Sum'
   */
  fangzhen20050606_B.VectorConcatenate[5] = (rtb_Product1_jh * rtb_Pitch -
    rtb_Roll * rtb_Product2_bk) * fangzhen20050606_P.Gain_Gain_g;

  /* Gain: '<S13>/Gain' incorporates:
   *  Product: '<S13>/Product1'
   *  Product: '<S13>/Product2'
   *  Sum: '<S13>/Sum'
   */
  fangzhen20050606_B.VectorConcatenate[6] = (rtb_Product2_bk * rtb_Pitch -
    rtb_Roll * rtb_Product1_jh) * fangzhen20050606_P.Gain_Gain_f;

  /* Gain: '<S16>/Gain' incorporates:
   *  Product: '<S16>/Product1'
   *  Product: '<S16>/Product2'
   *  Sum: '<S16>/Sum'
   */
  fangzhen20050606_B.VectorConcatenate[7] = (rtb_Roll * rtb_Product2_bk +
    rtb_Product1_jh * rtb_Pitch) * fangzhen20050606_P.Gain_Gain_b;

  /* Sum: '<S19>/Sum' incorporates:
   *  Product: '<S19>/Product'
   *  Product: '<S19>/Product1'
   *  Product: '<S19>/Product2'
   *  Product: '<S19>/Product3'
   */
  fangzhen20050606_B.VectorConcatenate[8] = ((rtb_Roll * rtb_Roll -
    rtb_Product2_bk * rtb_Product2_bk) - rtb_Product1_jh * rtb_Product1_jh) +
    rtb_Pitch * rtb_Pitch;

  /* Integrator: '<S36>/Integrator1' */
  fangzhen20050606_B.Integrator1[0] = fangzhen20050606_X.Integrator1_CSTATE_g[0];
  fangzhen20050606_B.Integrator1[1] = fangzhen20050606_X.Integrator1_CSTATE_g[1];
  fangzhen20050606_B.Integrator1[2] = fangzhen20050606_X.Integrator1_CSTATE_g[2];

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant'
   */
  rtb_AWcc[0] = fangzhen20050606_P.Constant_Value_f[0] -
    fangzhen20050606_B.Integrator1[0];
  rtb_AWcc[1] = fangzhen20050606_P.Constant_Value_f[1] -
    fangzhen20050606_B.Integrator1[1];
  rtb_AWcc[2] = fangzhen20050606_P.Constant_Value_f[2] -
    fangzhen20050606_B.Integrator1[2];

  /* Product: '<S6>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_MatrixGain2[i] = fangzhen20050606_B.VectorConcatenate[i + 6] * rtb_AWcc
      [2] + (fangzhen20050606_B.VectorConcatenate[i + 3] * rtb_AWcc[1] +
             fangzhen20050606_B.VectorConcatenate[i] * rtb_AWcc[0]);
  }

  /* End of Product: '<S6>/Product' */

  /* Fcn: '<S6>/Fcn' */
  rtb_Product1_jh = -0.02 * rtb_MatrixGain2[0] / rtb_MatrixGain2[2];

  /* Fcn: '<S6>/Fcn3' */
  rtb_Product2_bk = -0.02 * rtb_MatrixGain2[1] / rtb_MatrixGain2[2];

  /* Sum: '<S6>/Sum1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  rtb_MatrixGain2[0] = fangzhen20050606_P.Constant1_Value_f[0] -
    fangzhen20050606_B.Integrator1[0];
  rtb_MatrixGain2[1] = fangzhen20050606_P.Constant1_Value_f[1] -
    fangzhen20050606_B.Integrator1[1];
  rtb_MatrixGain2[2] = fangzhen20050606_P.Constant1_Value_f[2] -
    fangzhen20050606_B.Integrator1[2];

  /* Product: '<S6>/Product1' */
  for (i = 0; i < 3; i++) {
    rtb_MatrixGain_k[i] = fangzhen20050606_B.VectorConcatenate[i + 6] *
      rtb_MatrixGain2[2] + (fangzhen20050606_B.VectorConcatenate[i + 3] *
      rtb_MatrixGain2[1] + fangzhen20050606_B.VectorConcatenate[i] *
      rtb_MatrixGain2[0]);
  }

  /* End of Product: '<S6>/Product1' */

  /* Fcn: '<S6>/Fcn1' */
  rtb_Roll = -0.02 * rtb_MatrixGain_k[0] / rtb_MatrixGain_k[2];

  /* Fcn: '<S6>/Fcn4' */
  rtb_Pitch = -0.02 * rtb_MatrixGain_k[1] / rtb_MatrixGain_k[2];

  /* Sum: '<S6>/Sum2' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  rtb_MatrixGain_k[0] = fangzhen20050606_P.Constant2_Value_g[0] -
    fangzhen20050606_B.Integrator1[0];
  rtb_MatrixGain_k[1] = fangzhen20050606_P.Constant2_Value_g[1] -
    fangzhen20050606_B.Integrator1[1];
  rtb_MatrixGain_k[2] = fangzhen20050606_P.Constant2_Value_g[2] -
    fangzhen20050606_B.Integrator1[2];

  /* Product: '<S6>/Product2' */
  for (i = 0; i < 3; i++) {
    rtb_Sum2_l[i] = fangzhen20050606_B.VectorConcatenate[i + 6] *
      rtb_MatrixGain_k[2] + (fangzhen20050606_B.VectorConcatenate[i + 3] *
      rtb_MatrixGain_k[1] + fangzhen20050606_B.VectorConcatenate[i] *
      rtb_MatrixGain_k[0]);
  }

  /* End of Product: '<S6>/Product2' */

  /* Fcn: '<S6>/Fcn2' */
  rtb_Product_dn = -0.02 * rtb_Sum2_l[0] / rtb_Sum2_l[2];

  /* Fcn: '<S6>/Fcn5' */
  rtb_Yaw = -0.02 * rtb_Sum2_l[1] / rtb_Sum2_l[2];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* RandomNumber: '<S85>/Random Number' */
    for (i = 0; i < 6; i++) {
      fangzhen20050606_B.RandomNumber[i] = fangzhen20050606_DWork.NextOutput_m[i];
    }

    /* End of RandomNumber: '<S85>/Random Number' */
  }

  /* Sum: '<S85>/Sum6' */
  rtb_Product_by_idx_2 = rtb_Product1_jh + fangzhen20050606_B.RandomNumber[0];
  rtb_Product_by_idx_1 = rtb_Product2_bk + fangzhen20050606_B.RandomNumber[1];
  rtb_Product_by_idx_4 = rtb_Roll + fangzhen20050606_B.RandomNumber[2];
  rtb_Product_by_idx_0 = rtb_Pitch + fangzhen20050606_B.RandomNumber[3];
  rtb_Product_by_idx = rtb_Product_dn + fangzhen20050606_B.RandomNumber[4];
  rtb_Product_by_idx_3 = rtb_Yaw + fangzhen20050606_B.RandomNumber[5];

  /* Fcn: '<S6>/Fcn6' */
  rtb_Gain1_nt = (rt_powd_snf(rtb_AWcc[0], 2.0) + rt_powd_snf(rtb_AWcc[1], 2.0))
    + rt_powd_snf(rtb_AWcc[2], 2.0);
  if (rtb_Gain1_nt < 0.0) {
    rtb_Yaw = -rt_powd_snf(-rtb_Gain1_nt, 0.5);
  } else {
    rtb_Yaw = rt_powd_snf(rtb_Gain1_nt, 0.5);
  }

  /* End of Fcn: '<S6>/Fcn6' */

  /* Fcn: '<S6>/Fcn7' */
  rtb_Gain1_nt = (rt_powd_snf(rtb_MatrixGain2[0], 2.0) + rt_powd_snf
                  (rtb_MatrixGain2[1], 2.0)) + rt_powd_snf(rtb_MatrixGain2[2],
    2.0);
  if (rtb_Gain1_nt < 0.0) {
    rtb_Product_dn = -rt_powd_snf(-rtb_Gain1_nt, 0.5);
  } else {
    rtb_Product_dn = rt_powd_snf(rtb_Gain1_nt, 0.5);
  }

  /* End of Fcn: '<S6>/Fcn7' */

  /* Fcn: '<S6>/Fcn8' */
  rtb_Gain1_nt = (rt_powd_snf(rtb_MatrixGain_k[0], 2.0) + rt_powd_snf
                  (rtb_MatrixGain_k[1], 2.0)) + rt_powd_snf(rtb_MatrixGain_k[2],
    2.0);
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* RandomNumber: '<S84>/Random Number' */
    fangzhen20050606_B.RandomNumber_i[0] = fangzhen20050606_DWork.NextOutput_p[0];
    fangzhen20050606_B.RandomNumber_i[1] = fangzhen20050606_DWork.NextOutput_p[1];
    fangzhen20050606_B.RandomNumber_i[2] = fangzhen20050606_DWork.NextOutput_p[2];
  }

  /* Abs: '<S84>/Abs' incorporates:
   *  Sum: '<S84>/Sum6'
   */
  rtb_Sum2_l[0] = fabs(rtb_Yaw + fangzhen20050606_B.RandomNumber_i[0]);
  rtb_Sum2_l[1] = fabs(rtb_Product_dn + fangzhen20050606_B.RandomNumber_i[1]);

  /* Fcn: '<S6>/Fcn8' */
  if (rtb_Gain1_nt < 0.0) {
    rtb_Add = -rt_powd_snf(-rtb_Gain1_nt, 0.5);
  } else {
    rtb_Add = rt_powd_snf(rtb_Gain1_nt, 0.5);
  }

  /* Fcn: '<S88>/Fcn1' */
  rtb_Yaw = rtb_Product_by_idx_2;

  /* Fcn: '<S88>/Fcn2' */
  rtb_Product_dn = rtb_Product_by_idx_1;

  /* Fcn: '<S88>/Fcn' */
  rtb_Gain1_nt = (rt_powd_snf(rtb_Product_by_idx_2, 2.0) + rt_powd_snf
                  (rtb_Product_by_idx_1, 2.0)) + 0.0004;
  if (rtb_Gain1_nt < 0.0) {
    rtb_Gain1_nt = -rt_powd_snf(-rtb_Gain1_nt, 0.5);
  } else {
    rtb_Gain1_nt = rt_powd_snf(rtb_Gain1_nt, 0.5);
  }

  rtb_Product1_jh = rtb_Sum2_l[0] / rtb_Gain1_nt;

  /* End of Fcn: '<S88>/Fcn' */

  /* Product: '<S88>/Product' incorporates:
   *  Constant: '<S88>/Constant'
   */
  rtb_MatrixGain_k[0] = rtb_Yaw * rtb_Product1_jh;
  rtb_MatrixGain_k[1] = rtb_Product_dn * rtb_Product1_jh;
  rtb_MatrixGain_k[2] = fangzhen20050606_P.Constant_Value_p * rtb_Product1_jh;

  /* Fcn: '<S89>/Fcn1' */
  rtb_Yaw = rtb_Product_by_idx_4;

  /* Fcn: '<S89>/Fcn2' */
  rtb_Product_dn = rtb_Product_by_idx_0;

  /* Fcn: '<S89>/Fcn' */
  rtb_Gain1_nt = (rt_powd_snf(rtb_Product_by_idx_4, 2.0) + rt_powd_snf
                  (rtb_Product_by_idx_0, 2.0)) + 0.0004;
  if (rtb_Gain1_nt < 0.0) {
    rtb_Gain1_nt = -rt_powd_snf(-rtb_Gain1_nt, 0.5);
  } else {
    rtb_Gain1_nt = rt_powd_snf(rtb_Gain1_nt, 0.5);
  }

  rtb_Product1_jh = rtb_Sum2_l[1] / rtb_Gain1_nt;

  /* End of Fcn: '<S89>/Fcn' */

  /* Sum: '<S91>/Sum' incorporates:
   *  Constant: '<S89>/Constant'
   *  Product: '<S89>/Product'
   */
  rtb_MatrixGain2[0] = rtb_Yaw * rtb_Product1_jh - rtb_MatrixGain_k[0];
  rtb_MatrixGain2[1] = rtb_Product_dn * rtb_Product1_jh - rtb_MatrixGain_k[1];
  rtb_MatrixGain2[2] = fangzhen20050606_P.Constant_Value_m * rtb_Product1_jh -
    rtb_MatrixGain_k[2];

  /* Fcn: '<S91>/Fcn' */
  rtb_Gain1_nt = (rt_powd_snf(rtb_MatrixGain2[0], 2.0) + rt_powd_snf
                  (rtb_MatrixGain2[1], 2.0)) + rt_powd_snf(rtb_MatrixGain2[2],
    2.0);
  if (rtb_Gain1_nt < 0.0) {
    rtb_Gain1_nt = -rt_powd_snf(-rtb_Gain1_nt, -0.5);
  } else {
    rtb_Gain1_nt = rt_powd_snf(rtb_Gain1_nt, -0.5);
  }

  /* Product: '<S91>/e1' incorporates:
   *  Fcn: '<S91>/Fcn'
   */
  fangzhen20050606_B.e1[0] = rtb_MatrixGain2[0] * rtb_Gain1_nt;
  fangzhen20050606_B.e1[1] = rtb_MatrixGain2[1] * rtb_Gain1_nt;
  fangzhen20050606_B.e1[2] = rtb_MatrixGain2[2] * rtb_Gain1_nt;

  /* Fcn: '<S90>/Fcn1' */
  rtb_Yaw = rtb_Product_by_idx;

  /* Fcn: '<S90>/Fcn2' */
  rtb_Product_dn = rtb_Product_by_idx_3;

  /* Fcn: '<S90>/Fcn' incorporates:
   *  Abs: '<S84>/Abs'
   *  Sum: '<S84>/Sum6'
   */
  rtb_Gain1_nt = (rt_powd_snf(rtb_Product_by_idx, 2.0) + rt_powd_snf
                  (rtb_Product_by_idx_3, 2.0)) + 0.0004;
  if (rtb_Gain1_nt < 0.0) {
    rtb_Gain1_nt = -rt_powd_snf(-rtb_Gain1_nt, 0.5);
  } else {
    rtb_Gain1_nt = rt_powd_snf(rtb_Gain1_nt, 0.5);
  }

  rtb_Product1_jh = fabs(rtb_Add + fangzhen20050606_B.RandomNumber_i[2]) /
    rtb_Gain1_nt;

  /* End of Fcn: '<S90>/Fcn' */

  /* Sum: '<S91>/Sum1' incorporates:
   *  Constant: '<S90>/Constant'
   *  Product: '<S90>/Product'
   */
  rtb_Sum2_l[0] = rtb_Yaw * rtb_Product1_jh - rtb_MatrixGain_k[0];
  rtb_Sum2_l[1] = rtb_Product_dn * rtb_Product1_jh - rtb_MatrixGain_k[1];
  rtb_Sum2_l[2] = fangzhen20050606_P.Constant_Value_i * rtb_Product1_jh -
    rtb_MatrixGain_k[2];

  /* Sum: '<S93>/Sum' incorporates:
   *  Product: '<S93>/Product'
   *  Product: '<S93>/Product1'
   */
  rtb_MatrixGain2[0] = fangzhen20050606_B.e1[1] * rtb_Sum2_l[2] -
    fangzhen20050606_B.e1[2] * rtb_Sum2_l[1];
  rtb_MatrixGain2[1] = fangzhen20050606_B.e1[2] * rtb_Sum2_l[0] -
    fangzhen20050606_B.e1[0] * rtb_Sum2_l[2];
  rtb_MatrixGain2[2] = fangzhen20050606_B.e1[0] * rtb_Sum2_l[1] -
    fangzhen20050606_B.e1[1] * rtb_Sum2_l[0];

  /* Fcn: '<S91>/Fcn1' */
  rtb_Gain1_nt = (rt_powd_snf(rtb_MatrixGain2[0], 2.0) + rt_powd_snf
                  (rtb_MatrixGain2[1], 2.0)) + rt_powd_snf(rtb_MatrixGain2[2],
    2.0);
  if (rtb_Gain1_nt < 0.0) {
    rtb_Gain1_nt = -rt_powd_snf(-rtb_Gain1_nt, -0.5);
  } else {
    rtb_Gain1_nt = rt_powd_snf(rtb_Gain1_nt, -0.5);
  }

  /* Product: '<S91>/e3' incorporates:
   *  Fcn: '<S91>/Fcn1'
   */
  fangzhen20050606_B.e3[0] = rtb_MatrixGain2[0] * rtb_Gain1_nt;
  fangzhen20050606_B.e3[1] = rtb_MatrixGain2[1] * rtb_Gain1_nt;
  fangzhen20050606_B.e3[2] = rtb_MatrixGain2[2] * rtb_Gain1_nt;

  /* Sum: '<S94>/Sum' incorporates:
   *  Product: '<S94>/Product'
   *  Product: '<S94>/Product1'
   */
  fangzhen20050606_B.Sum_o[0] = fangzhen20050606_B.e3[1] *
    fangzhen20050606_B.e1[2] - fangzhen20050606_B.e3[2] * fangzhen20050606_B.e1
    [1];
  fangzhen20050606_B.Sum_o[1] = fangzhen20050606_B.e3[2] *
    fangzhen20050606_B.e1[0] - fangzhen20050606_B.e3[0] * fangzhen20050606_B.e1
    [2];
  fangzhen20050606_B.Sum_o[2] = fangzhen20050606_B.e3[0] *
    fangzhen20050606_B.e1[1] - fangzhen20050606_B.e3[1] * fangzhen20050606_B.e1
    [0];

  /* Sum: '<S97>/Add' */
  rtb_AWcc[0] = fangzhen20050606_B.e1[0];
  rtb_AWcc[1] = fangzhen20050606_B.Sum_o[1];
  rtb_AWcc[2] = fangzhen20050606_B.e3[2];
  rtb_Add = (fangzhen20050606_B.e1[0] + fangzhen20050606_B.Sum_o[1]) +
    fangzhen20050606_B.e3[2];

  /* If: '<S92>/If' */
  if (rtmIsMajorTimeStep(fangzhen20050606_M)) {
    if (rtb_Add > 0.0) {
      rtAction = 0;
    } else {
      rtAction = 1;
    }

    fangzhen20050606_DWork.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = fangzhen20050606_DWork.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S92>/Positive Trace' incorporates:
     *  ActionPort: '<S96>/Action Port'
     */
    /* Sqrt: '<S96>/sqrt' incorporates:
     *  Constant: '<S96>/Constant'
     *  Sum: '<S96>/Sum'
     */
    rtb_Gain1_nt = sqrt(rtb_Add + fangzhen20050606_P.Constant_Value);

    /* Gain: '<S96>/Gain' */
    fangzhen20050606_B.Merge[0] = fangzhen20050606_P.Gain_Gain * rtb_Gain1_nt;

    /* Gain: '<S96>/Gain1' */
    rtb_Gain1_nt *= fangzhen20050606_P.Gain1_Gain;

    /* Product: '<S96>/Product' incorporates:
     *  Sum: '<S117>/Add'
     *  Sum: '<S118>/Add'
     *  Sum: '<S119>/Add'
     */
    fangzhen20050606_B.Merge[1] = (fangzhen20050606_B.e3[1] -
      fangzhen20050606_B.Sum_o[2]) / rtb_Gain1_nt;
    fangzhen20050606_B.Merge[2] = (fangzhen20050606_B.e1[2] -
      fangzhen20050606_B.e3[0]) / rtb_Gain1_nt;
    fangzhen20050606_B.Merge[3] = (fangzhen20050606_B.Sum_o[0] -
      fangzhen20050606_B.e1[1]) / rtb_Gain1_nt;

    /* End of Outputs for SubSystem: '<S92>/Positive Trace' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S92>/Negative Trace' incorporates:
     *  ActionPort: '<S95>/Action Port'
     */
    /* If: '<S95>/Find Maximum Diagonal Value' */
    if (rtmIsMajorTimeStep(fangzhen20050606_M)) {
      if ((fangzhen20050606_B.Sum_o[1] > fangzhen20050606_B.e1[0]) &&
          (fangzhen20050606_B.Sum_o[1] > fangzhen20050606_B.e3[2])) {
        rtAction = 0;
      } else if (fangzhen20050606_B.e3[2] > fangzhen20050606_B.e1[0]) {
        rtAction = 1;
      } else {
        rtAction = 2;
      }

      fangzhen20050606_DWork.FindMaximumDiagonalValue_Active = rtAction;
    } else {
      rtAction = fangzhen20050606_DWork.FindMaximumDiagonalValue_Active;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S95>/Maximum Value at DCM(2,2)' incorporates:
       *  ActionPort: '<S99>/Action Port'
       */
      /* Sqrt: '<S99>/sqrt' incorporates:
       *  Constant: '<S111>/Constant'
       *  Sum: '<S111>/Add'
       */
      rtb_Gain1_nt = sqrt(((fangzhen20050606_B.Sum_o[1] - fangzhen20050606_B.e1
                            [0]) - fangzhen20050606_B.e3[2]) +
                          fangzhen20050606_P.Constant_Value_k);

      /* Gain: '<S99>/Gain' */
      fangzhen20050606_B.Merge[2] = fangzhen20050606_P.Gain_Gain_n *
        rtb_Gain1_nt;

      /* Switch: '<S110>/Switch' incorporates:
       *  Constant: '<S110>/Constant1'
       *  Constant: '<S110>/Constant2'
       */
      if (rtb_Gain1_nt != 0.0) {
        rtb_Add = fangzhen20050606_P.Constant1_Value;
      } else {
        rtb_Add = fangzhen20050606_P.Constant2_Value[0];
        rtb_Gain1_nt = fangzhen20050606_P.Constant2_Value[1];
      }

      /* End of Switch: '<S110>/Switch' */

      /* Product: '<S110>/Product' */
      rtb_Gain1_nt = rtb_Add / rtb_Gain1_nt;

      /* Product: '<S99>/Product' incorporates:
       *  Sum: '<S107>/Add'
       *  Sum: '<S108>/Add'
       *  Sum: '<S109>/Add'
       */
      rtb_AWcc[0] = (fangzhen20050606_B.e1[1] + fangzhen20050606_B.Sum_o[0]) *
        rtb_Gain1_nt;
      rtb_AWcc[1] = (fangzhen20050606_B.Sum_o[2] + fangzhen20050606_B.e3[1]) *
        rtb_Gain1_nt;
      rtb_AWcc[2] = (fangzhen20050606_B.e1[2] - fangzhen20050606_B.e3[0]) *
        rtb_Gain1_nt;

      /* Gain: '<S99>/Gain1' */
      fangzhen20050606_B.Merge[1] = fangzhen20050606_P.Gain1_Gain_m * rtb_AWcc[0];

      /* Gain: '<S99>/Gain3' */
      fangzhen20050606_B.Merge[3] = fangzhen20050606_P.Gain3_Gain * rtb_AWcc[1];

      /* Gain: '<S99>/Gain4' */
      fangzhen20050606_B.Merge[0] = fangzhen20050606_P.Gain4_Gain * rtb_AWcc[2];

      /* End of Outputs for SubSystem: '<S95>/Maximum Value at DCM(2,2)' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S95>/Maximum Value at DCM(3,3)' incorporates:
       *  ActionPort: '<S100>/Action Port'
       */
      /* Sqrt: '<S100>/sqrt' incorporates:
       *  Constant: '<S116>/Constant'
       *  Sum: '<S116>/Add'
       */
      rtb_Gain1_nt = sqrt(((fangzhen20050606_B.e3[2] - fangzhen20050606_B.e1[0])
                           - fangzhen20050606_B.Sum_o[1]) +
                          fangzhen20050606_P.Constant_Value_kg);

      /* Gain: '<S100>/Gain' */
      fangzhen20050606_B.Merge[3] = fangzhen20050606_P.Gain_Gain_h *
        rtb_Gain1_nt;

      /* Switch: '<S115>/Switch' incorporates:
       *  Constant: '<S115>/Constant1'
       *  Constant: '<S115>/Constant2'
       */
      if (rtb_Gain1_nt != 0.0) {
        rtb_Add = fangzhen20050606_P.Constant1_Value_o;
      } else {
        rtb_Add = fangzhen20050606_P.Constant2_Value_i[0];
        rtb_Gain1_nt = fangzhen20050606_P.Constant2_Value_i[1];
      }

      /* End of Switch: '<S115>/Switch' */

      /* Product: '<S115>/Product' */
      rtb_Gain1_nt = rtb_Add / rtb_Gain1_nt;

      /* Product: '<S100>/Product' incorporates:
       *  Sum: '<S112>/Add'
       *  Sum: '<S113>/Add'
       *  Sum: '<S114>/Add'
       */
      rtb_AWcc[0] = (fangzhen20050606_B.e1[2] + fangzhen20050606_B.e3[0]) *
        rtb_Gain1_nt;
      rtb_AWcc[1] = (fangzhen20050606_B.Sum_o[2] + fangzhen20050606_B.e3[1]) *
        rtb_Gain1_nt;
      rtb_AWcc[2] = (fangzhen20050606_B.Sum_o[0] - fangzhen20050606_B.e1[1]) *
        rtb_Gain1_nt;

      /* Gain: '<S100>/Gain1' */
      fangzhen20050606_B.Merge[1] = fangzhen20050606_P.Gain1_Gain_a * rtb_AWcc[0];

      /* Gain: '<S100>/Gain2' */
      fangzhen20050606_B.Merge[2] = fangzhen20050606_P.Gain2_Gain * rtb_AWcc[1];

      /* Gain: '<S100>/Gain3' */
      fangzhen20050606_B.Merge[0] = fangzhen20050606_P.Gain3_Gain_o * rtb_AWcc[2];

      /* End of Outputs for SubSystem: '<S95>/Maximum Value at DCM(3,3)' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S95>/Maximum Value at DCM(1,1)' incorporates:
       *  ActionPort: '<S98>/Action Port'
       */
      /* Sqrt: '<S98>/sqrt' incorporates:
       *  Constant: '<S106>/Constant'
       *  Sum: '<S106>/Add'
       */
      rtb_Gain1_nt = sqrt(((fangzhen20050606_B.e1[0] - fangzhen20050606_B.Sum_o
                            [1]) - fangzhen20050606_B.e3[2]) +
                          fangzhen20050606_P.Constant_Value_l);

      /* Gain: '<S98>/Gain' */
      fangzhen20050606_B.Merge[1] = fangzhen20050606_P.Gain_Gain_a *
        rtb_Gain1_nt;

      /* Switch: '<S105>/Switch' incorporates:
       *  Constant: '<S105>/Constant1'
       *  Constant: '<S105>/Constant2'
       */
      if (rtb_Gain1_nt != 0.0) {
        rtb_Add = fangzhen20050606_P.Constant1_Value_b;
      } else {
        rtb_Add = fangzhen20050606_P.Constant2_Value_p[0];
        rtb_Gain1_nt = fangzhen20050606_P.Constant2_Value_p[1];
      }

      /* End of Switch: '<S105>/Switch' */

      /* Product: '<S105>/Product' */
      rtb_Gain1_nt = rtb_Add / rtb_Gain1_nt;

      /* Product: '<S98>/Product' incorporates:
       *  Sum: '<S102>/Add'
       *  Sum: '<S103>/Add'
       *  Sum: '<S104>/Add'
       */
      rtb_AWcc[0] = (fangzhen20050606_B.e1[1] + fangzhen20050606_B.Sum_o[0]) *
        rtb_Gain1_nt;
      rtb_AWcc[1] = (fangzhen20050606_B.e1[2] + fangzhen20050606_B.e3[0]) *
        rtb_Gain1_nt;
      rtb_AWcc[2] = (fangzhen20050606_B.e3[1] - fangzhen20050606_B.Sum_o[2]) *
        rtb_Gain1_nt;

      /* Gain: '<S98>/Gain1' */
      fangzhen20050606_B.Merge[2] = fangzhen20050606_P.Gain1_Gain_j * rtb_AWcc[0];

      /* Gain: '<S98>/Gain2' */
      fangzhen20050606_B.Merge[3] = fangzhen20050606_P.Gain2_Gain_l * rtb_AWcc[1];

      /* Gain: '<S98>/Gain3' */
      fangzhen20050606_B.Merge[0] = fangzhen20050606_P.Gain3_Gain_k * rtb_AWcc[2];

      /* End of Outputs for SubSystem: '<S95>/Maximum Value at DCM(1,1)' */
      break;
    }

    /* End of If: '<S95>/Find Maximum Diagonal Value' */
    /* End of Outputs for SubSystem: '<S92>/Negative Trace' */
    break;
  }

  /* End of If: '<S92>/If' */

  /* Level2 S-Function Block: '<S83>/S-Function' (CIQW_kf_C) */
  {
    SimStruct *rts = fangzhen20050606_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sqrt: '<S65>/sqrt' incorporates:
     *  Product: '<S66>/Product'
     *  Product: '<S66>/Product1'
     *  Product: '<S66>/Product2'
     *  Product: '<S66>/Product3'
     *  Sum: '<S66>/Sum'
     */
    rtb_Gain1_nt = sqrt(((fangzhen20050606_B.SFunction[0] *
                          fangzhen20050606_B.SFunction[0] +
                          fangzhen20050606_B.SFunction[1] *
                          fangzhen20050606_B.SFunction[1]) +
                         fangzhen20050606_B.SFunction[2] *
                         fangzhen20050606_B.SFunction[2]) +
                        fangzhen20050606_B.SFunction[3] *
                        fangzhen20050606_B.SFunction[3]);

    /* Product: '<S64>/Product' */
    rtb_Product1_ck = fangzhen20050606_B.SFunction[0] / rtb_Gain1_nt;

    /* Product: '<S64>/Product1' */
    rtb_Roll = fangzhen20050606_B.SFunction[1] / rtb_Gain1_nt;

    /* Product: '<S64>/Product2' */
    rtb_Product2_bk = fangzhen20050606_B.SFunction[2] / rtb_Gain1_nt;

    /* Product: '<S64>/Product3' */
    rtb_Gain1_nt = fangzhen20050606_B.SFunction[3] / rtb_Gain1_nt;

    /* Sum: '<S54>/Sum' incorporates:
     *  Product: '<S54>/Product'
     *  Product: '<S54>/Product1'
     *  Product: '<S54>/Product2'
     *  Product: '<S54>/Product3'
     */
    fangzhen20050606_B.VectorConcatenate_p[0] = ((rtb_Product1_ck *
      rtb_Product1_ck + rtb_Roll * rtb_Roll) - rtb_Product2_bk * rtb_Product2_bk)
      - rtb_Gain1_nt * rtb_Gain1_nt;

    /* Gain: '<S57>/Gain' incorporates:
     *  Product: '<S57>/Product2'
     *  Product: '<S57>/Product3'
     *  Sum: '<S57>/Sum'
     */
    fangzhen20050606_B.VectorConcatenate_p[1] = (rtb_Roll * rtb_Product2_bk -
      rtb_Gain1_nt * rtb_Product1_ck) * fangzhen20050606_P.Gain_Gain_m;

    /* Gain: '<S60>/Gain' incorporates:
     *  Product: '<S60>/Product1'
     *  Product: '<S60>/Product2'
     *  Sum: '<S60>/Sum'
     */
    fangzhen20050606_B.VectorConcatenate_p[2] = (rtb_Product1_ck *
      rtb_Product2_bk + rtb_Roll * rtb_Gain1_nt) *
      fangzhen20050606_P.Gain_Gain_hx;

    /* Gain: '<S55>/Gain' incorporates:
     *  Product: '<S55>/Product2'
     *  Product: '<S55>/Product3'
     *  Sum: '<S55>/Sum'
     */
    fangzhen20050606_B.VectorConcatenate_p[3] = (rtb_Gain1_nt * rtb_Product1_ck
      + rtb_Roll * rtb_Product2_bk) * fangzhen20050606_P.Gain_Gain_ml;

    /* Sum: '<S58>/Sum' incorporates:
     *  Product: '<S58>/Product'
     *  Product: '<S58>/Product1'
     *  Product: '<S58>/Product2'
     *  Product: '<S58>/Product3'
     */
    fangzhen20050606_B.VectorConcatenate_p[4] = ((rtb_Product1_ck *
      rtb_Product1_ck - rtb_Roll * rtb_Roll) + rtb_Product2_bk * rtb_Product2_bk)
      - rtb_Gain1_nt * rtb_Gain1_nt;

    /* Gain: '<S61>/Gain' incorporates:
     *  Product: '<S61>/Product1'
     *  Product: '<S61>/Product2'
     *  Sum: '<S61>/Sum'
     */
    fangzhen20050606_B.VectorConcatenate_p[5] = (rtb_Product2_bk * rtb_Gain1_nt
      - rtb_Product1_ck * rtb_Roll) * fangzhen20050606_P.Gain_Gain_p;

    /* Gain: '<S56>/Gain' incorporates:
     *  Product: '<S56>/Product1'
     *  Product: '<S56>/Product2'
     *  Sum: '<S56>/Sum'
     */
    fangzhen20050606_B.VectorConcatenate_p[6] = (rtb_Roll * rtb_Gain1_nt -
      rtb_Product1_ck * rtb_Product2_bk) * fangzhen20050606_P.Gain_Gain_l;

    /* Gain: '<S59>/Gain' incorporates:
     *  Product: '<S59>/Product1'
     *  Product: '<S59>/Product2'
     *  Sum: '<S59>/Sum'
     */
    fangzhen20050606_B.VectorConcatenate_p[7] = (rtb_Product1_ck * rtb_Roll +
      rtb_Product2_bk * rtb_Gain1_nt) * fangzhen20050606_P.Gain_Gain_j;

    /* Sum: '<S62>/Sum' incorporates:
     *  Product: '<S62>/Product'
     *  Product: '<S62>/Product1'
     *  Product: '<S62>/Product2'
     *  Product: '<S62>/Product3'
     */
    fangzhen20050606_B.VectorConcatenate_p[8] = ((rtb_Product1_ck *
      rtb_Product1_ck - rtb_Roll * rtb_Roll) - rtb_Product2_bk * rtb_Product2_bk)
      + rtb_Gain1_nt * rtb_Gain1_nt;
  }

  /* Clock: '<S53>/Clock2' */
  rtb_Yaw = fangzhen20050606_M->Timing.t[0];

  /* RelationalOperator: '<S53>/Relational Operator' incorporates:
   *  Constant: '<S53>/Constant4'
   */
  rtb_RelationalOperator = (rtb_Yaw >= fangzhen20050606_P.Constant4_Value);

  /* DataTypeConversion: '<S52>/Data Type Conversion' incorporates:
   *  Logic: '<S52>/Logical Operator'
   */
  rtb_Yaw = (real_T)!rtb_RelationalOperator;

  /* Integrator: '<S82>/Integrator1' */
  fangzhen20050606_B.Integrator1_p[0] = fangzhen20050606_X.Integrator1_CSTATE_l
    [0];
  fangzhen20050606_B.Integrator1_p[1] = fangzhen20050606_X.Integrator1_CSTATE_l
    [1];
  fangzhen20050606_B.Integrator1_p[2] = fangzhen20050606_X.Integrator1_CSTATE_l
    [2];

  /* Gain: '<S91>/Gain' */
  rtb_MatrixGain_k[0] *= fangzhen20050606_P.Gain_Gain_ac;
  rtb_MatrixGain_k[1] *= fangzhen20050606_P.Gain_Gain_ac;
  rtb_Add = fangzhen20050606_P.Gain_Gain_ac * rtb_MatrixGain_k[2];

  /* SignalConversion: '<S91>/TmpSignal ConversionAtMath FunctionInport1' */
  tmp[0] = fangzhen20050606_B.e1[0];
  tmp[1] = fangzhen20050606_B.e1[1];
  tmp[2] = fangzhen20050606_B.e1[2];
  tmp[3] = fangzhen20050606_B.Sum_o[0];
  tmp[4] = fangzhen20050606_B.Sum_o[1];
  tmp[5] = fangzhen20050606_B.Sum_o[2];
  tmp[6] = fangzhen20050606_B.e3[0];
  tmp[7] = fangzhen20050606_B.e3[1];
  tmp[8] = fangzhen20050606_B.e3[2];

  /* Product: '<S91>/e5' incorporates:
   *  SignalConversion: '<S91>/TmpSignal ConversionAtMath FunctionInport1'
   */
  for (i = 0; i < 3; i++) {
    fangzhen20050606_B.e5[i] = 0.0;
    fangzhen20050606_B.e5[i] += tmp[3 * i] * rtb_MatrixGain_k[0];
    fangzhen20050606_B.e5[i] += tmp[3 * i + 1] * rtb_MatrixGain_k[1];
    fangzhen20050606_B.e5[i] += tmp[3 * i + 2] * rtb_Add;
  }

  /* End of Product: '<S91>/e5' */

  /* Level2 S-Function Block: '<S86>/S-Function' (CIRV_kf_C) */
  {
    SimStruct *rts = fangzhen20050606_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S86>/Sum4' */
  fangzhen20050606_B.Sum4[0] = fangzhen20050606_B.Integrator1_p[0] -
    fangzhen20050606_B.SFunction_k[0];
  fangzhen20050606_B.Sum4[1] = fangzhen20050606_B.Integrator1_p[1] -
    fangzhen20050606_B.SFunction_k[1];
  fangzhen20050606_B.Sum4[2] = fangzhen20050606_B.Integrator1_p[2] -
    fangzhen20050606_B.SFunction_k[2];

  /* Integrator: '<S82>/Integrator' */
  fangzhen20050606_B.Integrator[0] = fangzhen20050606_X.Integrator_CSTATE_d[0];
  fangzhen20050606_B.Integrator[1] = fangzhen20050606_X.Integrator_CSTATE_d[1];
  fangzhen20050606_B.Integrator[2] = fangzhen20050606_X.Integrator_CSTATE_d[2];

  /* Sum: '<S86>/Sum1' */
  fangzhen20050606_B.Sum1[0] = fangzhen20050606_B.Integrator[0] -
    fangzhen20050606_B.SFunction_k[3];
  fangzhen20050606_B.Sum1[1] = fangzhen20050606_B.Integrator[1] -
    fangzhen20050606_B.SFunction_k[4];
  fangzhen20050606_B.Sum1[2] = fangzhen20050606_B.Integrator[2] -
    fangzhen20050606_B.SFunction_k[5];

  /* Clock: '<S52>/Clock1' */
  rtb_Product_dn = fangzhen20050606_M->Timing.t[0];

  /* RelationalOperator: '<S52>/Relational Operator1' incorporates:
   *  Constant: '<S52>/Constant1'
   */
  rtb_RelationalOperator1 = (rtb_Product_dn <=
    fangzhen20050606_P.Constant1_Value_p);

  /* Outputs for Enabled SubSystem: '<S52>/Subsystem2' incorporates:
   *  EnablePort: '<S142>/Enable'
   */
  if ((rtmIsMajorTimeStep(fangzhen20050606_M) &&
       fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) &&
      rtmIsMajorTimeStep(fangzhen20050606_M)) {
    if (rtb_RelationalOperator1) {
      if (!fangzhen20050606_DWork.Subsystem2_MODE) {
        fangzhen20050606_DWork.Subsystem2_MODE = TRUE;
      }
    } else {
      if (fangzhen20050606_DWork.Subsystem2_MODE) {
        fangzhen20050606_DWork.Subsystem2_MODE = FALSE;
      }
    }
  }

  if (fangzhen20050606_DWork.Subsystem2_MODE) {
    /* Inport: '<S142>/In1' */
    fangzhen20050606_B.In1[0] = fangzhen20050606_B.Sum4[0];
    fangzhen20050606_B.In1[1] = fangzhen20050606_B.Sum4[1];
    fangzhen20050606_B.In1[2] = fangzhen20050606_B.Sum4[2];
    fangzhen20050606_B.In1[3] = fangzhen20050606_B.Sum1[0];
    fangzhen20050606_B.In1[4] = fangzhen20050606_B.Sum1[1];
    fangzhen20050606_B.In1[5] = fangzhen20050606_B.Sum1[2];
  }

  /* End of Outputs for SubSystem: '<S52>/Subsystem2' */
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S147>/Math Function' incorporates:
     *  Constant: '<S144>/T'
     *
     * About '<S147>/Math Function':
     *  Operator: magnitude^2
     */
    fangzhen20050606_B.MathFunction = fangzhen20050606_P.T_Value *
      fangzhen20050606_P.T_Value;
  }

  /* Sum: '<S147>/Sum' incorporates:
   *  Constant: '<S144>/T'
   *  Constant: '<S52>/Constant5'
   *  Gain: '<S147>/Gain'
   *  Gain: '<S147>/Gain1'
   *  Product: '<S147>/Product'
   *  Product: '<S147>/Product1'
   *  Sum: '<S147>/Sum1'
   */
  rtb_Sum2_l[0] = (fangzhen20050606_B.In1[0] -
                   fangzhen20050606_P.Constant5_Value[0]) /
    fangzhen20050606_B.MathFunction * fangzhen20050606_P.Gain1_Gain_n +
    fangzhen20050606_B.In1[3] / fangzhen20050606_P.T_Value *
    fangzhen20050606_P.Gain_Gain_o;
  rtb_Sum2_l[1] = (fangzhen20050606_B.In1[1] -
                   fangzhen20050606_P.Constant5_Value[1]) /
    fangzhen20050606_B.MathFunction * fangzhen20050606_P.Gain1_Gain_n +
    fangzhen20050606_B.In1[4] / fangzhen20050606_P.T_Value *
    fangzhen20050606_P.Gain_Gain_o;
  rtb_Sum2_l[2] = (fangzhen20050606_B.In1[2] -
                   fangzhen20050606_P.Constant5_Value[2]) /
    fangzhen20050606_B.MathFunction * fangzhen20050606_P.Gain1_Gain_n +
    fangzhen20050606_B.In1[5] / fangzhen20050606_P.T_Value *
    fangzhen20050606_P.Gain_Gain_o;

  /* Clock: '<S144>/Clock' */
  rtb_Product_dn = fangzhen20050606_M->Timing.t[0];

  /* Math: '<S150>/Math Function1'
   *
   * About '<S150>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Product1_jh = rtb_Product_dn * rtb_Product_dn;
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S148>/Math Function1' incorporates:
     *  Constant: '<S144>/T'
     *
     * About '<S148>/Math Function1':
     *  Operator: magnitude^2
     */
    fangzhen20050606_B.MathFunction1 = fangzhen20050606_P.T_Value *
      fangzhen20050606_P.T_Value;

    /* Product: '<S148>/Product3' incorporates:
     *  Constant: '<S144>/T'
     */
    fangzhen20050606_B.Product3 = fangzhen20050606_B.MathFunction1 *
      fangzhen20050606_P.T_Value;
  }

  /* Sum: '<S148>/Sum1' incorporates:
   *  Constant: '<S52>/Constant5'
   *  Gain: '<S148>/Gain2'
   *  Gain: '<S148>/Gain3'
   *  Product: '<S148>/Product2'
   *  Product: '<S148>/Product4'
   *  Sum: '<S148>/Sum2'
   */
  rtb_MatrixGain_k[0] = 1.0 / fangzhen20050606_B.Product3 *
    (fangzhen20050606_B.In1[0] - fangzhen20050606_P.Constant5_Value[0]) *
    fangzhen20050606_P.Gain3_Gain_j + fangzhen20050606_B.In1[3] /
    fangzhen20050606_B.MathFunction1 * fangzhen20050606_P.Gain2_Gain_g;
  rtb_MatrixGain_k[1] = 1.0 / fangzhen20050606_B.Product3 *
    (fangzhen20050606_B.In1[1] - fangzhen20050606_P.Constant5_Value[1]) *
    fangzhen20050606_P.Gain3_Gain_j + fangzhen20050606_B.In1[4] /
    fangzhen20050606_B.MathFunction1 * fangzhen20050606_P.Gain2_Gain_g;
  rtb_MatrixGain_k[2] = 1.0 / fangzhen20050606_B.Product3 *
    (fangzhen20050606_B.In1[2] - fangzhen20050606_P.Constant5_Value[2]) *
    fangzhen20050606_P.Gain3_Gain_j + fangzhen20050606_B.In1[5] /
    fangzhen20050606_B.MathFunction1 * fangzhen20050606_P.Gain2_Gain_g;

  /* Product: '<S150>/Product2' */
  rtb_Product1_ck = rtb_Product1_jh * rtb_Product_dn;
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Math: '<S149>/Math Function1' incorporates:
     *  Constant: '<S144>/T'
     *
     * About '<S149>/Math Function1':
     *  Operator: magnitude^2
     */
    rtb_Add = fangzhen20050606_P.T_Value * fangzhen20050606_P.T_Value;

    /* Product: '<S149>/Product3' incorporates:
     *  Constant: '<S144>/T'
     */
    fangzhen20050606_B.Product3_l = rtb_Add * fangzhen20050606_P.T_Value;

    /* Product: '<S149>/Product4' */
    fangzhen20050606_B.Product4 = rtb_Add * rtb_Add;
  }

  /* Sum: '<S149>/Sum1' incorporates:
   *  Constant: '<S52>/Constant5'
   *  Gain: '<S149>/Gain2'
   *  Gain: '<S149>/Gain3'
   *  Product: '<S149>/Product2'
   *  Product: '<S149>/Product5'
   *  Sum: '<S149>/Sum2'
   */
  rtb_MatrixGain2[0] = 1.0 / fangzhen20050606_B.Product4 *
    (fangzhen20050606_B.In1[0] - fangzhen20050606_P.Constant5_Value[0]) *
    fangzhen20050606_P.Gain3_Gain_d3 + fangzhen20050606_B.In1[3] /
    fangzhen20050606_B.Product3_l * fangzhen20050606_P.Gain2_Gain_f;
  rtb_MatrixGain2[1] = 1.0 / fangzhen20050606_B.Product4 *
    (fangzhen20050606_B.In1[1] - fangzhen20050606_P.Constant5_Value[1]) *
    fangzhen20050606_P.Gain3_Gain_d3 + fangzhen20050606_B.In1[4] /
    fangzhen20050606_B.Product3_l * fangzhen20050606_P.Gain2_Gain_f;
  rtb_MatrixGain2[2] = 1.0 / fangzhen20050606_B.Product4 *
    (fangzhen20050606_B.In1[2] - fangzhen20050606_P.Constant5_Value[2]) *
    fangzhen20050606_P.Gain3_Gain_d3 + fangzhen20050606_B.In1[5] /
    fangzhen20050606_B.Product3_l * fangzhen20050606_P.Gain2_Gain_f;

  /* Product: '<S150>/Product4' */
  rtb_Gain1_nt = rtb_Product1_jh * rtb_Product1_jh;

  /* Sum: '<S150>/Sum1' incorporates:
   *  Gain: '<S150>/Gain1'
   *  Gain: '<S150>/Gain2'
   *  Gain: '<S150>/Gain3'
   *  Product: '<S150>/Product1'
   *  Product: '<S150>/Product3'
   *  Product: '<S150>/Product6'
   *  Product: '<S150>/Product7'
   */
  fangzhen20050606_B.Sum1_j[0] = (((rtb_Sum2_l[0] * rtb_Product1_jh *
    fangzhen20050606_P.Gain1_Gain_ni + rtb_MatrixGain_k[0] * rtb_Product1_ck *
    fangzhen20050606_P.Gain3_Gain_d) + rtb_MatrixGain2[0] * rtb_Gain1_nt *
    fangzhen20050606_P.Gain2_Gain_i) + rtb_Product_dn * fangzhen20050606_B.In1[3])
    + fangzhen20050606_B.In1[0];
  fangzhen20050606_B.Sum1_j[1] = (((rtb_Sum2_l[1] * rtb_Product1_jh *
    fangzhen20050606_P.Gain1_Gain_ni + rtb_MatrixGain_k[1] * rtb_Product1_ck *
    fangzhen20050606_P.Gain3_Gain_d) + rtb_MatrixGain2[1] * rtb_Gain1_nt *
    fangzhen20050606_P.Gain2_Gain_i) + rtb_Product_dn * fangzhen20050606_B.In1[4])
    + fangzhen20050606_B.In1[1];
  fangzhen20050606_B.Sum1_j[2] = (((rtb_Sum2_l[2] * rtb_Product1_jh *
    fangzhen20050606_P.Gain1_Gain_ni + rtb_MatrixGain_k[2] * rtb_Product1_ck *
    fangzhen20050606_P.Gain3_Gain_d) + rtb_MatrixGain2[2] * rtb_Gain1_nt *
    fangzhen20050606_P.Gain2_Gain_i) + rtb_Product_dn * fangzhen20050606_B.In1[5])
    + fangzhen20050606_B.In1[2];

  /* Math: '<S151>/Math Function1'
   *
   * About '<S151>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Product1_jh = rtb_Product_dn * rtb_Product_dn;

  /* Product: '<S151>/Product5' */
  rtb_Gain1_nt = rtb_Product1_jh * rtb_Product_dn;

  /* Sum: '<S151>/Sum1' incorporates:
   *  Gain: '<S151>/Gain1'
   *  Gain: '<S151>/Gain3'
   *  Product: '<S151>/Product1'
   *  Product: '<S151>/Product3'
   *  Product: '<S151>/Product4'
   */
  fangzhen20050606_B.Sum1_a[0] = ((rtb_MatrixGain_k[0] * rtb_Product1_jh *
    fangzhen20050606_P.Gain3_Gain_c + rtb_Sum2_l[0] * rtb_Product_dn) +
    rtb_MatrixGain2[0] * rtb_Gain1_nt * fangzhen20050606_P.Gain1_Gain_dz) +
    fangzhen20050606_B.In1[3];
  fangzhen20050606_B.Sum1_a[1] = ((rtb_MatrixGain_k[1] * rtb_Product1_jh *
    fangzhen20050606_P.Gain3_Gain_c + rtb_Sum2_l[1] * rtb_Product_dn) +
    rtb_MatrixGain2[1] * rtb_Gain1_nt * fangzhen20050606_P.Gain1_Gain_dz) +
    fangzhen20050606_B.In1[4];
  fangzhen20050606_B.Sum1_a[2] = ((rtb_MatrixGain_k[2] * rtb_Product1_jh *
    fangzhen20050606_P.Gain3_Gain_c + rtb_Sum2_l[2] * rtb_Product_dn) +
    rtb_MatrixGain2[2] * rtb_Gain1_nt * fangzhen20050606_P.Gain1_Gain_dz) +
    fangzhen20050606_B.In1[5];

  /* Product: '<S52>/Product' */
  rtb_Product_by_idx_2 = rtb_Yaw * fangzhen20050606_B.Sum1_j[0];
  rtb_Product_by_idx_1 = rtb_Yaw * fangzhen20050606_B.Sum1_j[1];
  rtb_Product_by_idx_4 = rtb_Yaw * fangzhen20050606_B.Sum1_j[2];
  rtb_Product_by_idx_0 = rtb_Yaw * fangzhen20050606_B.Sum1_a[0];
  rtb_Product_by_idx = rtb_Yaw * fangzhen20050606_B.Sum1_a[1];
  rtb_Product_by_idx_3 = rtb_Yaw * fangzhen20050606_B.Sum1_a[2];

  /* DataTypeConversion: '<S52>/Data Type Conversion1' */
  rtb_Yaw = (real_T)rtb_RelationalOperator;

  /* Clock: '<S52>/Clock' */
  rtb_Clock = fangzhen20050606_M->Timing.t[0];

  /* Logic: '<S52>/Logical Operator1' */
  rtb_LogicalOperator1 = !rtb_RelationalOperator;

  /* Outputs for Enabled SubSystem: '<S52>/Subsystem' incorporates:
   *  EnablePort: '<S141>/Enable'
   */
  if ((rtmIsMajorTimeStep(fangzhen20050606_M) &&
       fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) &&
      rtmIsMajorTimeStep(fangzhen20050606_M)) {
    if (rtb_LogicalOperator1) {
      if (!fangzhen20050606_DWork.Subsystem_MODE) {
        fangzhen20050606_DWork.Subsystem_MODE = TRUE;
      }
    } else {
      if (fangzhen20050606_DWork.Subsystem_MODE) {
        fangzhen20050606_DWork.Subsystem_MODE = FALSE;
      }
    }
  }

  if (fangzhen20050606_DWork.Subsystem_MODE) {
    /* Inport: '<S141>/In1' */
    fangzhen20050606_B.In1_p[0] = fangzhen20050606_B.Sum4[0];
    fangzhen20050606_B.In1_p[1] = fangzhen20050606_B.Sum4[1];
    fangzhen20050606_B.In1_p[2] = fangzhen20050606_B.Sum4[2];
    fangzhen20050606_B.In1_p[3] = fangzhen20050606_B.Sum1[0];
    fangzhen20050606_B.In1_p[4] = fangzhen20050606_B.Sum1[1];
    fangzhen20050606_B.In1_p[5] = fangzhen20050606_B.Sum1[2];
    fangzhen20050606_B.In1_p[6] = rtb_Clock;
  }

  /* End of Outputs for SubSystem: '<S52>/Subsystem' */

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant2'
   *  Constant: '<S53>/Constant3'
   */
  if (rtb_RelationalOperator) {
    rtb_Switch[0] = fangzhen20050606_P.Constant3_Value_n[0];
    rtb_Switch[1] = fangzhen20050606_P.Constant3_Value_n[1];
    rtb_Switch[2] = fangzhen20050606_P.Constant3_Value_n[2];
  } else {
    rtb_Switch[0] = fangzhen20050606_P.Constant2_Value_l[0];
    rtb_Switch[1] = fangzhen20050606_P.Constant2_Value_l[1];
    rtb_Switch[2] = fangzhen20050606_P.Constant2_Value_l[2];
  }

  /* End of Switch: '<S52>/Switch' */

  /* Outputs for Enabled SubSystem: '<S52>/轨迹制导2' incorporates:
   *  EnablePort: '<S143>/Enable'
   */
  if ((rtmIsMajorTimeStep(fangzhen20050606_M) &&
       fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) &&
      rtmIsMajorTimeStep(fangzhen20050606_M)) {
    if (rtb_RelationalOperator) {
      if (!fangzhen20050606_DWork.u_MODE) {
        fangzhen20050606_DWork.u_MODE = TRUE;
      }
    } else {
      if (fangzhen20050606_DWork.u_MODE) {
        fangzhen20050606_DWork.u_MODE = FALSE;
      }
    }
  }

  if (fangzhen20050606_DWork.u_MODE) {
    /* Clock: '<S143>/Clock' */
    rtb_Sum2_fk = fangzhen20050606_M->Timing.t[0];
    if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
        fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S143>/Constant1' */
      fangzhen20050606_B.Constant1_b[0] = fangzhen20050606_P.Constant1_Value_j[0];
      fangzhen20050606_B.Constant1_b[1] = fangzhen20050606_P.Constant1_Value_j[1];
    }

    /* Inport: '<S143>/Rt' */
    fangzhen20050606_B.Rt[0] = rtb_Switch[0];
    fangzhen20050606_B.Rt[1] = rtb_Switch[1];
    fangzhen20050606_B.Rt[2] = rtb_Switch[2];

    /* Sum: '<S143>/Sum1' incorporates:
     *  Constant: '<S143>/Constant2'
     */
    rtb_Add = fangzhen20050606_P.Constant2_Value_o - fangzhen20050606_B.In1_p[6];

    /* Sum: '<S143>/Sum2' */
    rtb_Sum2_fk -= fangzhen20050606_B.In1_p[6];

    /* Sum: '<S143>/Sum3' */
    rtb_Roll = fangzhen20050606_B.In1_p[2] + fangzhen20050606_B.Rt[2];

    /* Math: '<S145>/Math Function1'
     *
     * About '<S145>/Math Function1':
     *  Operator: magnitude^2
     */
    rtb_Gain1_nt = rtb_Sum2_fk * rtb_Sum2_fk;

    /* Math: '<S145>/Math Function2'
     *
     * About '<S145>/Math Function2':
     *  Operator: magnitude^2
     */
    rtb_Product2_bk = rtb_Add * rtb_Add;

    /* Sum: '<S143>/Sum4' incorporates:
     *  Gain: '<S145>/Gain1'
     *  Gain: '<S145>/Gain2'
     *  Gain: '<S145>/Gain4'
     *  Product: '<S145>/Product1'
     *  Product: '<S145>/Product2'
     *  Product: '<S145>/Product3'
     *  Product: '<S145>/Product4'
     *  Product: '<S145>/Product6'
     *  Product: '<S145>/Product7'
     *  Product: '<S145>/Product8'
     *  Sum: '<S145>/Sum1'
     *  Sum: '<S145>/Sum2'
     *  Sum: '<S145>/Sum3'
     */
    fangzhen20050606_B.Sum4_a = ((((fangzhen20050606_B.In1_p[5] * rtb_Add +
      fangzhen20050606_P.Gain2_Gain_a * rtb_Roll) * (rtb_Sum2_fk * rtb_Gain1_nt)
      / (rtb_Product2_bk * rtb_Add) + rtb_Sum2_fk * fangzhen20050606_B.In1_p[5])
      + (fangzhen20050606_B.In1_p[5] * rtb_Add * fangzhen20050606_P.Gain1_Gain_d
         + fangzhen20050606_P.Gain4_Gain_c * rtb_Roll) * rtb_Gain1_nt /
      rtb_Product2_bk) + rtb_Roll) - fangzhen20050606_B.Rt[2];

    /* Product: '<S146>/Product1' */
    rtb_Product2_bk = rtb_Add * fangzhen20050606_B.In1_p[5];

    /* Gain: '<S146>/Gain2' */
    rtb_Gain1_nt = fangzhen20050606_P.Gain2_Gain_j * rtb_Product2_bk;

    /* Gain: '<S146>/Gain5' */
    rtb_Product1_ck = fangzhen20050606_P.Gain5_Gain * rtb_Product2_bk;

    /* Math: '<S146>/Math Function4'
     *
     * About '<S146>/Math Function4':
     *  Operator: magnitude^2
     */
    rtb_Product2_bk = rtb_Add * rtb_Add;

    /* Sum: '<S146>/Sum1' incorporates:
     *  Gain: '<S146>/Gain1'
     *  Gain: '<S146>/Gain4'
     *  Math: '<S146>/Math Function1'
     *  Product: '<S146>/Product2'
     *  Product: '<S146>/Product5'
     *  Product: '<S146>/Product9'
     *  Sum: '<S146>/Sum2'
     *  Sum: '<S146>/Sum3'
     *
     * About '<S146>/Math Function1':
     *  Operator: magnitude^2
     */
    fangzhen20050606_B.Sum1_pf = ((fangzhen20050606_P.Gain4_Gain_e * rtb_Roll +
      rtb_Product1_ck) * (rtb_Sum2_fk * rtb_Sum2_fk) / (rtb_Add *
      rtb_Product2_bk) + (fangzhen20050606_P.Gain1_Gain_p * rtb_Roll +
                          rtb_Gain1_nt) * rtb_Sum2_fk / rtb_Product2_bk) +
      fangzhen20050606_B.In1_p[5];
  }

  /* End of Outputs for SubSystem: '<S52>/轨迹制导2' */

  /* Sum: '<S52>/Sum' incorporates:
   *  Product: '<S52>/Product1'
   */
  fangzhen20050606_B.Sum_oq[0] = rtb_Yaw * fangzhen20050606_B.Rt[0] +
    rtb_Product_by_idx_2;
  fangzhen20050606_B.Sum_oq[1] = rtb_Yaw * fangzhen20050606_B.Rt[1] +
    rtb_Product_by_idx_1;
  fangzhen20050606_B.Sum_oq[2] = rtb_Yaw * fangzhen20050606_B.Sum4_a +
    rtb_Product_by_idx_4;
  fangzhen20050606_B.Sum_oq[3] = rtb_Yaw * fangzhen20050606_B.Constant1_b[0] +
    rtb_Product_by_idx_0;
  fangzhen20050606_B.Sum_oq[4] = rtb_Yaw * fangzhen20050606_B.Constant1_b[1] +
    rtb_Product_by_idx;
  fangzhen20050606_B.Sum_oq[5] = rtb_Yaw * fangzhen20050606_B.Sum1_pf +
    rtb_Product_by_idx_3;

  /* Clock: '<S52>/Clock2' */
  rtb_Yaw = fangzhen20050606_M->Timing.t[0];

  /* RelationalOperator: '<S52>/Relational Operator2' incorporates:
   *  Constant: '<S52>/Constant3'
   */
  rtb_RelationalOperator_l = (rtb_Yaw < fangzhen20050606_P.Constant3_Value_m);

  /* Product: '<S52>/Product2' */
  for (i = 0; i < 6; i++) {
    fangzhen20050606_B.Product2[i] = fangzhen20050606_B.Sum_oq[i] * (real_T)
      rtb_RelationalOperator_l;
  }

  /* End of Product: '<S52>/Product2' */

  /* Sum: '<S2>/Sum' */
  fangzhen20050606_B.Sum_h[0] = fangzhen20050606_B.Sum4[0] -
    fangzhen20050606_B.Product2[0];
  fangzhen20050606_B.Sum_h[1] = fangzhen20050606_B.Sum4[1] -
    fangzhen20050606_B.Product2[1];
  fangzhen20050606_B.Sum_h[2] = fangzhen20050606_B.Sum4[2] -
    fangzhen20050606_B.Product2[2];
  fangzhen20050606_B.Sum_h[3] = fangzhen20050606_B.Sum1[0] -
    fangzhen20050606_B.Product2[3];
  fangzhen20050606_B.Sum_h[4] = fangzhen20050606_B.Sum1[1] -
    fangzhen20050606_B.Product2[4];
  fangzhen20050606_B.Sum_h[5] = fangzhen20050606_B.Sum1[2] -
    fangzhen20050606_B.Product2[5];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* ZeroOrderHold: '<S49>/Zero-Order Hold' */
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtToWo_o[i] = fangzhen20050606_B.Sum_h[i];
    }

    /* End of ZeroOrderHold: '<S49>/Zero-Order Hold' */

    /* Product: '<S49>/Product' */
    for (i = 0; i < 3; i++) {
      rtb_AWcc[i] = fangzhen20050606_B.VectorConcatenate_p[i + 6] *
        rtb_TmpSignalConversionAtToWo_o[2] +
        (fangzhen20050606_B.VectorConcatenate_p[i + 3] *
         rtb_TmpSignalConversionAtToWo_o[1] +
         fangzhen20050606_B.VectorConcatenate_p[i] *
         rtb_TmpSignalConversionAtToWo_o[0]);
    }

    /* End of Product: '<S49>/Product' */

    /* Product: '<S49>/Product2' */
    for (i = 0; i < 3; i++) {
      rtb_MatrixGain2[i] = fangzhen20050606_B.VectorConcatenate_p[i + 6] *
        rtb_TmpSignalConversionAtToWo_o[5] +
        (fangzhen20050606_B.VectorConcatenate_p[i + 3] *
         rtb_TmpSignalConversionAtToWo_o[4] +
         fangzhen20050606_B.VectorConcatenate_p[i] *
         rtb_TmpSignalConversionAtToWo_o[3]);
    }

    /* End of Product: '<S49>/Product2' */

    /* Math: '<S78>/Math Function'
     *
     * About '<S78>/Math Function':
     *  Operator: magnitude^2
     */
    rtb_Gain_in[0] = rtb_MatrixGain2[0] * rtb_MatrixGain2[0];
    rtb_Gain_in[1] = rtb_MatrixGain2[1] * rtb_MatrixGain2[1];
    rtb_Gain_in[2] = rtb_MatrixGain2[2] * rtb_MatrixGain2[2];

    /* RelationalOperator: '<S49>/Relational Operator3' incorporates:
     *  Constant: '<S49>/Constant3'
     *  Gain: '<S49>/Gain'
     */
    rtb_RelationalOperator_l = (rtb_MatrixGain2[0] >=
      fangzhen20050606_P.Gain_Gain_jf * fangzhen20050606_P.Constant3_Value_c[0]);
    rtb_AND1_idx_0 = (rtb_MatrixGain2[1] >= fangzhen20050606_P.Gain_Gain_jf *
                      fangzhen20050606_P.Constant3_Value_c[1]);
    rtb_AND1_idx = (rtb_MatrixGain2[2] >= fangzhen20050606_P.Gain_Gain_jf *
                    fangzhen20050606_P.Constant3_Value_c[2]);

    /* Sum: '<S76>/Sum1' incorporates:
     *  Constant: '<S78>/Constant'
     *  Constant: '<S78>/Constant1'
     *  Gain: '<S78>/Gain'
     *  Gain: '<S78>/Gain1'
     *  Logic: '<S76>/AND'
     *  Logic: '<S76>/AND1'
     *  Logic: '<S76>/NOT'
     *  RelationalOperator: '<S76>/Relational Operator1'
     *  RelationalOperator: '<S76>/Relational Operator2'
     *  Sum: '<S78>/Sum'
     *  Sum: '<S78>/Sum1'
     */
    rtb_Gain_in[0] = (real_T)((rtb_AWcc[0] >= fangzhen20050606_P.Gain_Gain_e *
      rtb_Gain_in[0] + fangzhen20050606_P.Constant_Value_m3) &&
      rtb_RelationalOperator_l) + (real_T)((rtb_AWcc[0] >
      fangzhen20050606_P.Gain1_Gain_g * rtb_Gain_in[0] +
      fangzhen20050606_P.Constant1_Value_e) && (!rtb_RelationalOperator_l));
    rtb_Gain_in[1] = (real_T)((rtb_AWcc[1] >= fangzhen20050606_P.Gain_Gain_e *
      rtb_Gain_in[1] + fangzhen20050606_P.Constant_Value_m3) && rtb_AND1_idx_0)
      + (real_T)((rtb_AWcc[1] > fangzhen20050606_P.Gain1_Gain_g * rtb_Gain_in[1]
                  + fangzhen20050606_P.Constant1_Value_e) && (!rtb_AND1_idx_0));
    rtb_Gain_in[2] = (real_T)((rtb_AWcc[2] >= fangzhen20050606_P.Gain_Gain_e *
      rtb_Gain_in[2] + fangzhen20050606_P.Constant_Value_m3) && rtb_AND1_idx) +
      (real_T)((rtb_AWcc[2] > fangzhen20050606_P.Gain1_Gain_g * rtb_Gain_in[2] +
                fangzhen20050606_P.Constant1_Value_e) && (!rtb_AND1_idx));

    /* Gain: '<S76>/Gain1' */
    rtb_Sum2_l[0] = fangzhen20050606_P.Gain1_Gain_gz * rtb_Gain_in[0];
    rtb_Sum2_l[1] = fangzhen20050606_P.Gain1_Gain_gz * rtb_Gain_in[1];
    rtb_Sum2_l[2] = fangzhen20050606_P.Gain1_Gain_gz * rtb_Gain_in[2];

    /* Math: '<S77>/Math Function'
     *
     * About '<S77>/Math Function':
     *  Operator: magnitude^2
     */
    rtb_Gain_in[0] = rtb_MatrixGain2[0] * rtb_MatrixGain2[0];
    rtb_Gain_in[1] = rtb_MatrixGain2[1] * rtb_MatrixGain2[1];
    rtb_Gain_in[2] = rtb_MatrixGain2[2] * rtb_MatrixGain2[2];

    /* RelationalOperator: '<S49>/Relational Operator4' incorporates:
     *  Constant: '<S49>/Constant3'
     */
    rtb_RelationalOperator_l = (rtb_MatrixGain2[0] >=
      fangzhen20050606_P.Constant3_Value_c[0]);
    rtb_AND1_idx_0 = (rtb_MatrixGain2[1] >=
                      fangzhen20050606_P.Constant3_Value_c[1]);
    rtb_AND1_idx = (rtb_MatrixGain2[2] >= fangzhen20050606_P.Constant3_Value_c[2]);

    /* Sum: '<S75>/Sum1' incorporates:
     *  Constant: '<S77>/Constant'
     *  Constant: '<S77>/Constant1'
     *  Gain: '<S77>/Gain'
     *  Gain: '<S77>/Gain1'
     *  Logic: '<S75>/AND'
     *  Logic: '<S75>/AND1'
     *  Logic: '<S75>/NOT'
     *  RelationalOperator: '<S75>/Relational Operator1'
     *  RelationalOperator: '<S75>/Relational Operator2'
     *  Sum: '<S77>/Sum'
     *  Sum: '<S77>/Sum1'
     */
    rtb_Gain_in[0] = (real_T)((rtb_AWcc[0] <= fangzhen20050606_P.Gain_Gain_ei *
      rtb_Gain_in[0] + fangzhen20050606_P.Constant_Value_fr) &&
      rtb_RelationalOperator_l) + (real_T)((rtb_AWcc[0] <
      fangzhen20050606_P.Gain1_Gain_gw * rtb_Gain_in[0] +
      fangzhen20050606_P.Constant1_Value_fs) && (!rtb_RelationalOperator_l));
    rtb_Gain_in[1] = (real_T)((rtb_AWcc[1] <= fangzhen20050606_P.Gain_Gain_ei *
      rtb_Gain_in[1] + fangzhen20050606_P.Constant_Value_fr) && rtb_AND1_idx_0)
      + (real_T)((rtb_AWcc[1] < fangzhen20050606_P.Gain1_Gain_gw * rtb_Gain_in[1]
                  + fangzhen20050606_P.Constant1_Value_fs) && (!rtb_AND1_idx_0));
    rtb_Gain_in[2] = (real_T)((rtb_AWcc[2] <= fangzhen20050606_P.Gain_Gain_ei *
      rtb_Gain_in[2] + fangzhen20050606_P.Constant_Value_fr) && rtb_AND1_idx) +
      (real_T)((rtb_AWcc[2] < fangzhen20050606_P.Gain1_Gain_gw * rtb_Gain_in[2]
                + fangzhen20050606_P.Constant1_Value_fs) && (!rtb_AND1_idx));

    /* Sum: '<S49>/Sum1' incorporates:
     *  Gain: '<S75>/Gain'
     */
    fangzhen20050606_B.Sum1_m[0] = fangzhen20050606_P.Gain_Gain_i * rtb_Gain_in
      [0] + rtb_Sum2_l[0];
    fangzhen20050606_B.Sum1_m[1] = fangzhen20050606_P.Gain_Gain_i * rtb_Gain_in
      [1] + rtb_Sum2_l[1];
    fangzhen20050606_B.Sum1_m[2] = fangzhen20050606_P.Gain_Gain_i * rtb_Gain_in
      [2] + rtb_Sum2_l[2];
  }

  /* Clock: '<S49>/Clock' */
  rtb_Yaw = fangzhen20050606_M->Timing.t[0];

  /* RelationalOperator: '<S49>/Relational Operator' incorporates:
   *  Constant: '<S49>/Constant'
   */
  rtb_RelationalOperator_l = (rtb_Yaw <= fangzhen20050606_P.Constant_Value_d);

  /* Product: '<S49>/Product3' */
  fangzhen20050606_B.Product3_f[0] = fangzhen20050606_B.Sum1_m[0] * (real_T)
    rtb_RelationalOperator_l;
  fangzhen20050606_B.Product3_f[1] = fangzhen20050606_B.Sum1_m[1] * (real_T)
    rtb_RelationalOperator_l;
  fangzhen20050606_B.Product3_f[2] = fangzhen20050606_B.Sum1_m[2] * (real_T)
    rtb_RelationalOperator_l;
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo WorkspaceInport1' */
    rtb_Sum1_a[0] = fangzhen20050606_B.Clock;
    rtb_Sum1_a[1] = fangzhen20050606_B.Product3_f[0];
    rtb_Sum1_a[2] = fangzhen20050606_B.Product3_f[1];
    rtb_Sum1_a[3] = fangzhen20050606_B.Product3_f[2];

    /* ToWorkspace: '<Root>/To Workspace' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (fangzhen20050606_DWork.ToWorkspace_PWORK.LoggedData),
                    rtb_Sum1_a, 0);
  }

  /* Integrator: '<S36>/Integrator' */
  fangzhen20050606_B.Integrator_n[0] = fangzhen20050606_X.Integrator_CSTATE_do[0];
  fangzhen20050606_B.Integrator_n[1] = fangzhen20050606_X.Integrator_CSTATE_do[1];
  fangzhen20050606_B.Integrator_n[2] = fangzhen20050606_X.Integrator_CSTATE_do[2];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Trigonometry: '<S4>/Trigonometric Function1' */
  rtb_Yaw = rt_atan2d_snf(fangzhen20050606_B.VectorConcatenate[7],
    fangzhen20050606_B.VectorConcatenate[8]);

  /* Gain: '<S35>/Gain2' */
  rtb_Add = fangzhen20050606_P.Gain2_Gain_aj *
    fangzhen20050606_B.VectorConcatenate[6];

  /* Trigonometry: '<S4>/Trigonometric Function2' */
  if (rtb_Add >= 1.0) {
    rtb_Add = 1.0;
  } else {
    if (rtb_Add <= -1.0) {
      rtb_Add = -1.0;
    }
  }

  rtb_Product_dn = asin(rtb_Add);

  /* End of Trigonometry: '<S4>/Trigonometric Function2' */

  /* Gain: '<S1>/Gain1' incorporates:
   *  Trigonometry: '<S4>/Trigonometric Function3'
   */
  fangzhen20050606_B.Gain1[0] = fangzhen20050606_P.Gain1_Gain_mr * rtb_Yaw;
  fangzhen20050606_B.Gain1[1] = fangzhen20050606_P.Gain1_Gain_mr *
    rtb_Product_dn;
  fangzhen20050606_B.Gain1[2] = fangzhen20050606_P.Gain1_Gain_mr * rt_atan2d_snf
    (fangzhen20050606_B.VectorConcatenate[3],
     fangzhen20050606_B.VectorConcatenate[0]);
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Clock: '<S1>/Clock' */
  fangzhen20050606_B.Clock_o = fangzhen20050606_M->Timing.t[0];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion: '<S1>/TmpSignal ConversionAtTo WorkspaceInport1' */
    rtb_TmpSignalConversionAtToWork[0] = fangzhen20050606_B.Clock_o;
    rtb_TmpSignalConversionAtToWork[1] = fangzhen20050606_B.Integrator1[0];
    rtb_TmpSignalConversionAtToWork[2] = fangzhen20050606_B.Integrator1[1];
    rtb_TmpSignalConversionAtToWork[3] = fangzhen20050606_B.Integrator1[2];
    rtb_TmpSignalConversionAtToWork[4] = fangzhen20050606_B.Integrator_n[0];
    rtb_TmpSignalConversionAtToWork[5] = fangzhen20050606_B.Integrator_n[1];
    rtb_TmpSignalConversionAtToWork[6] = fangzhen20050606_B.Integrator_n[2];

    /* ToWorkspace: '<S1>/To Workspace' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (fangzhen20050606_DWork.ToWorkspace_PWORK_c.LoggedData),
                    rtb_TmpSignalConversionAtToWork, 0);
  }

  /* Clock: '<S1>/Clock1' */
  fangzhen20050606_B.Clock1 = fangzhen20050606_M->Timing.t[0];

  /* Gain: '<S1>/Gain2' */
  fangzhen20050606_B.Gain2[0] = fangzhen20050606_P.Gain2_Gain_k *
    rtb_Product_ht[0];
  fangzhen20050606_B.Gain2[1] = fangzhen20050606_P.Gain2_Gain_k *
    rtb_Product_ht[1];
  fangzhen20050606_B.Gain2[2] = fangzhen20050606_P.Gain2_Gain_k *
    rtb_Product_ht[2];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion: '<S1>/TmpSignal ConversionAtTo Workspace1Inport1' */
    rtb_TmpSignalConversionAtToW_of[0] = fangzhen20050606_B.Clock1;
    rtb_TmpSignalConversionAtToW_of[1] = fangzhen20050606_B.Integrator1[0];
    rtb_TmpSignalConversionAtToW_of[2] = fangzhen20050606_B.Integrator1[1];
    rtb_TmpSignalConversionAtToW_of[3] = fangzhen20050606_B.Integrator1[2];
    rtb_TmpSignalConversionAtToW_of[4] = fangzhen20050606_B.Integrator_n[0];
    rtb_TmpSignalConversionAtToW_of[5] = fangzhen20050606_B.Integrator_n[1];
    rtb_TmpSignalConversionAtToW_of[6] = fangzhen20050606_B.Integrator_n[2];
    rtb_TmpSignalConversionAtToW_of[7] = fangzhen20050606_B.Gain1[0];
    rtb_TmpSignalConversionAtToW_of[8] = fangzhen20050606_B.Gain1[1];
    rtb_TmpSignalConversionAtToW_of[9] = fangzhen20050606_B.Gain1[2];
    rtb_TmpSignalConversionAtToW_of[10] = fangzhen20050606_B.Gain2[0];
    rtb_TmpSignalConversionAtToW_of[11] = fangzhen20050606_B.Gain2[1];
    rtb_TmpSignalConversionAtToW_of[12] = fangzhen20050606_B.Gain2[2];

    /* ToWorkspace: '<S1>/To Workspace1' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (fangzhen20050606_DWork.ToWorkspace1_PWORK.LoggedData),
                    rtb_TmpSignalConversionAtToW_of, 0);
  }

  /* Sum: '<S3>/Sum1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Product: '<S3>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum2_l[i] = rtb_Product_ht[i] - ((fangzhen20050606_B.VectorConcatenate[i
      + 3] * fangzhen20050606_P.Constant_Value_a[1] +
      fangzhen20050606_B.VectorConcatenate[i] *
      fangzhen20050606_P.Constant_Value_a[0]) +
      fangzhen20050606_B.VectorConcatenate[i + 6] *
      fangzhen20050606_P.Constant_Value_a[2]);
  }

  /* End of Sum: '<S3>/Sum1' */
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    rtb_Sum1_a[0] = fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[0];
    rtb_Sum1_a[1] = fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[1];
    rtb_Sum1_a[2] = fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[2];
    rtb_Sum1_a[3] = fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[3];

    /* Gain: '<S25>/invJW' */
    fangzhen20050606_B.invJW[0] = fangzhen20050606_P.invJW_Gain[0] * rtb_Sum1_a
      [0];
    fangzhen20050606_B.invJW[1] = fangzhen20050606_P.invJW_Gain[1] * rtb_Sum1_a
      [1];
    fangzhen20050606_B.invJW[2] = fangzhen20050606_P.invJW_Gain[2] * rtb_Sum1_a
      [2];
    fangzhen20050606_B.invJW[3] = fangzhen20050606_P.invJW_Gain[3] * rtb_Sum1_a
      [3];

    /* Gain: '<S24>/JW' */
    fangzhen20050606_B.JW[0] = fangzhen20050606_P.JW_Gain[0] *
      fangzhen20050606_B.invJW[0];
    fangzhen20050606_B.JW[1] = fangzhen20050606_P.JW_Gain[1] *
      fangzhen20050606_B.invJW[1];
    fangzhen20050606_B.JW[2] = fangzhen20050606_P.JW_Gain[2] *
      fangzhen20050606_B.invJW[2];
    fangzhen20050606_B.JW[3] = fangzhen20050606_P.JW_Gain[3] *
      fangzhen20050606_B.invJW[3];

    /* Sum: '<S24>/Sum' incorporates:
     *  UnitDelay: '<S24>/Unit delay'
     */
    rtb_Sum1_a[0] = fangzhen20050606_DWork.Unitdelay_DSTATE[0] -
      fangzhen20050606_B.JW[0];
    rtb_Sum1_a[1] = fangzhen20050606_DWork.Unitdelay_DSTATE[1] -
      fangzhen20050606_B.JW[1];
    rtb_Sum1_a[2] = fangzhen20050606_DWork.Unitdelay_DSTATE[2] -
      fangzhen20050606_B.JW[2];
    rtb_Sum1_a[3] = fangzhen20050606_DWork.Unitdelay_DSTATE[3] -
      fangzhen20050606_B.JW[3];

    /* Gain: '<S24>/1//T' */
    rtb_Sum1_a[0] *= fangzhen20050606_P.T_Gain;
    rtb_Sum1_a[1] *= fangzhen20050606_P.T_Gain;
    rtb_Sum1_a[2] *= fangzhen20050606_P.T_Gain;
    rtb_Sum1_a[3] *= fangzhen20050606_P.T_Gain;

    /* Gain: '<S24>/DWN' */
    for (i = 0; i < 3; i++) {
      fangzhen20050606_B.DWN[i] = 0.0;
      fangzhen20050606_B.DWN[i] += fangzhen20050606_P.DWN_Gain[i] * rtb_Sum1_a[0];
      fangzhen20050606_B.DWN[i] += fangzhen20050606_P.DWN_Gain[i + 3] *
        rtb_Sum1_a[1];
      fangzhen20050606_B.DWN[i] += fangzhen20050606_P.DWN_Gain[i + 6] *
        rtb_Sum1_a[2];
      fangzhen20050606_B.DWN[i] += fangzhen20050606_P.DWN_Gain[i + 9] *
        rtb_Sum1_a[3];
    }

    /* End of Gain: '<S24>/DWN' */

    /* Gain: '<S24>/IW' incorporates:
     *  Product: '<S24>/Product1'
     */
    fangzhen20050606_B.IW[0] = fangzhen20050606_B.invJW[0] *
      fangzhen20050606_B.invJW[0] * fangzhen20050606_P.IW_Gain[0];
    fangzhen20050606_B.IW[1] = fangzhen20050606_B.invJW[1] *
      fangzhen20050606_B.invJW[1] * fangzhen20050606_P.IW_Gain[1];
    fangzhen20050606_B.IW[2] = fangzhen20050606_B.invJW[2] *
      fangzhen20050606_B.invJW[2] * fangzhen20050606_P.IW_Gain[2];
    fangzhen20050606_B.IW[3] = fangzhen20050606_B.invJW[3] *
      fangzhen20050606_B.invJW[3] * fangzhen20050606_P.IW_Gain[3];
  }

  /* Clock: '<S24>/Clock' */
  rtb_Yaw = fangzhen20050606_M->Timing.t[0];

  /* Product: '<S24>/Product2' incorporates:
   *  Gain: '<S24>/DWN2'
   *  Product: '<S24>/Product'
   */
  rtb_Add = cos(rtb_Yaw * fangzhen20050606_B.invJW[0]) * fangzhen20050606_B.IW[0];
  rtb_Product1_jh = cos(rtb_Yaw * fangzhen20050606_B.invJW[1]) *
    fangzhen20050606_B.IW[1];
  rtb_Product_by_idx_2 = cos(rtb_Yaw * fangzhen20050606_B.invJW[2]) *
    fangzhen20050606_B.IW[2];
  rtb_Product_by_idx_1 = cos(rtb_Yaw * fangzhen20050606_B.invJW[3]) *
    fangzhen20050606_B.IW[3];

  /* Gain: '<S24>/DWN2' */
  for (i = 0; i < 3; i++) {
    fangzhen20050606_B.DWN2[i] = 0.0;
    fangzhen20050606_B.DWN2[i] += fangzhen20050606_P.DWN2_Gain[i] * rtb_Add;
    fangzhen20050606_B.DWN2[i] += fangzhen20050606_P.DWN2_Gain[i + 3] *
      rtb_Product1_jh;
    fangzhen20050606_B.DWN2[i] += fangzhen20050606_P.DWN2_Gain[i + 6] *
      rtb_Product_by_idx_2;
    fangzhen20050606_B.DWN2[i] += fangzhen20050606_P.DWN2_Gain[i + 9] *
      rtb_Product_by_idx_1;
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S24>/DWN1' */
    for (i = 0; i < 3; i++) {
      fangzhen20050606_B.DWN1[i] = 0.0;
      fangzhen20050606_B.DWN1[i] += fangzhen20050606_P.DWN1_Gain[i] *
        fangzhen20050606_B.JW[0];
      fangzhen20050606_B.DWN1[i] += fangzhen20050606_P.DWN1_Gain[i + 3] *
        fangzhen20050606_B.JW[1];
      fangzhen20050606_B.DWN1[i] += fangzhen20050606_P.DWN1_Gain[i + 6] *
        fangzhen20050606_B.JW[2];
      fangzhen20050606_B.DWN1[i] += fangzhen20050606_P.DWN1_Gain[i + 9] *
        fangzhen20050606_B.JW[3];
    }

    /* End of Gain: '<S24>/DWN1' */
  }

  /* Sum: '<S26>/Sum' incorporates:
   *  Product: '<S26>/Product'
   *  Product: '<S26>/Product1'
   */
  fangzhen20050606_B.Sum_e[0] = fangzhen20050606_B.DWN1[1] * rtb_Product_ht[2] -
    fangzhen20050606_B.DWN1[2] * rtb_Product_ht[1];
  fangzhen20050606_B.Sum_e[1] = fangzhen20050606_B.DWN1[2] * rtb_Product_ht[0] -
    fangzhen20050606_B.DWN1[0] * rtb_Product_ht[2];
  fangzhen20050606_B.Sum_e[2] = fangzhen20050606_B.DWN1[0] * rtb_Product_ht[1] -
    fangzhen20050606_B.DWN1[1] * rtb_Product_ht[0];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Sum: '<S24>/Sum1' */
  rtb_AWcc[0] = (fangzhen20050606_B.DWN[0] + fangzhen20050606_B.Sum_e[0]) +
    fangzhen20050606_B.DWN2[0];
  rtb_AWcc[1] = (fangzhen20050606_B.DWN[1] + fangzhen20050606_B.Sum_e[1]) +
    fangzhen20050606_B.DWN2[1];
  rtb_AWcc[2] = (fangzhen20050606_B.DWN[2] + fangzhen20050606_B.Sum_e[2]) +
    fangzhen20050606_B.DWN2[2];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* RandomNumber: '<S25>/TWi' */
    rtb_Sum1_a[0] = fangzhen20050606_DWork.NextOutput_c[0];
    rtb_Sum1_a[1] = fangzhen20050606_DWork.NextOutput_c[1];
    rtb_Sum1_a[2] = fangzhen20050606_DWork.NextOutput_c[2];
    rtb_Sum1_a[3] = fangzhen20050606_DWork.NextOutput_c[3];

    /* Sum: '<S25>/Sum1' incorporates:
     *  Constant: '<S25>/Constant2'
     *  DataTypeConversion: '<S25>/Data Type Conversion1'
     *  DataTypeConversion: '<S25>/Data Type Conversion2'
     *  Gain: '<S25>/CWw'
     *  Gain: '<S25>/Tf0'
     *  RelationalOperator: '<S25>/Relational Operator'
     *  RelationalOperator: '<S25>/Relational Operator1'
     *  Sum: '<S25>/Sum2'
     */
    rtb_Sum1_a[0] = (rtb_Sum1_a[0] - fangzhen20050606_P.CWw_Gain[0] *
                     fangzhen20050606_B.invJW[0]) - ((real_T)
      (fangzhen20050606_B.invJW[0] > fangzhen20050606_P.Constant2_Value_op[0]) -
      (real_T)(fangzhen20050606_B.invJW[0] <
               fangzhen20050606_P.Constant2_Value_op[0])) *
      fangzhen20050606_P.Tf0_Gain[0];
    rtb_Sum1_a[1] = (rtb_Sum1_a[1] - fangzhen20050606_P.CWw_Gain[1] *
                     fangzhen20050606_B.invJW[1]) - ((real_T)
      (fangzhen20050606_B.invJW[1] > fangzhen20050606_P.Constant2_Value_op[1]) -
      (real_T)(fangzhen20050606_B.invJW[1] <
               fangzhen20050606_P.Constant2_Value_op[1])) *
      fangzhen20050606_P.Tf0_Gain[1];
    rtb_Sum1_a[2] = (rtb_Sum1_a[2] - fangzhen20050606_P.CWw_Gain[2] *
                     fangzhen20050606_B.invJW[2]) - ((real_T)
      (fangzhen20050606_B.invJW[2] > fangzhen20050606_P.Constant2_Value_op[2]) -
      (real_T)(fangzhen20050606_B.invJW[2] <
               fangzhen20050606_P.Constant2_Value_op[2])) *
      fangzhen20050606_P.Tf0_Gain[2];
    rtb_Sum1_a[3] = (rtb_Sum1_a[3] - fangzhen20050606_P.CWw_Gain[3] *
                     fangzhen20050606_B.invJW[3]) - ((real_T)
      (fangzhen20050606_B.invJW[3] > fangzhen20050606_P.Constant2_Value_op[3]) -
      (real_T)(fangzhen20050606_B.invJW[3] <
               fangzhen20050606_P.Constant2_Value_op[3])) *
      fangzhen20050606_P.Tf0_Gain[3];

    /* Constant: '<S50>/Constant1' */
    fangzhen20050606_B.Constant1_e[0] = fangzhen20050606_P.Constant1_Value_j5[0];
    fangzhen20050606_B.Constant1_e[1] = fangzhen20050606_P.Constant1_Value_j5[1];
    fangzhen20050606_B.Constant1_e[2] = fangzhen20050606_P.Constant1_Value_j5[2];
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0) {
    /* Signum: '<S50>/Sign' */
    if (fangzhen20050606_B.SFunction[0] < 0.0) {
      rtb_Gain1_nt = -1.0;
    } else if (fangzhen20050606_B.SFunction[0] > 0.0) {
      rtb_Gain1_nt = 1.0;
    } else if (fangzhen20050606_B.SFunction[0] == 0.0) {
      rtb_Gain1_nt = 0.0;
    } else {
      rtb_Gain1_nt = fangzhen20050606_B.SFunction[0];
    }

    /* End of Signum: '<S50>/Sign' */

    /* Product: '<S50>/Product5' */
    fangzhen20050606_B.Product5[0] = rtb_Gain1_nt *
      fangzhen20050606_B.SFunction[1];
    fangzhen20050606_B.Product5[1] = rtb_Gain1_nt *
      fangzhen20050606_B.SFunction[2];
    fangzhen20050606_B.Product5[2] = rtb_Gain1_nt *
      fangzhen20050606_B.SFunction[3];
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S50>/Sum' */
    fangzhen20050606_B.Sum_c[0] = fangzhen20050606_B.Constant1_e[0] -
      fangzhen20050606_B.Product5[0];
    fangzhen20050606_B.Sum_c[1] = fangzhen20050606_B.Constant1_e[1] -
      fangzhen20050606_B.Product5[1];
    fangzhen20050606_B.Sum_c[2] = fangzhen20050606_B.Constant1_e[2] -
      fangzhen20050606_B.Product5[2];
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0) {
    /* DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */
    if (fangzhen20050606_DWork.DiscreteTimeIntegrator_SYSTEM_E != 0) {
      fangzhen20050606_B.DiscreteTimeIntegrator[0] =
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[0];
      fangzhen20050606_B.DiscreteTimeIntegrator[1] =
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[1];
      fangzhen20050606_B.DiscreteTimeIntegrator[2] =
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[2];
    } else {
      fangzhen20050606_B.DiscreteTimeIntegrator[0] =
        fangzhen20050606_P.DiscreteTimeIntegrator_gainva_c *
        fangzhen20050606_B.Sum_c[0] +
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[0];
      fangzhen20050606_B.DiscreteTimeIntegrator[1] =
        fangzhen20050606_P.DiscreteTimeIntegrator_gainva_c *
        fangzhen20050606_B.Sum_c[1] +
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[1];
      fangzhen20050606_B.DiscreteTimeIntegrator[2] =
        fangzhen20050606_P.DiscreteTimeIntegrator_gainva_c *
        fangzhen20050606_B.Sum_c[2] +
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[2];
    }

    /* End of DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */

    /* Gain: '<S50>/Ki' */
    rtb_Add = fangzhen20050606_P.Ki_Gain[0] *
      fangzhen20050606_B.DiscreteTimeIntegrator[0];

    /* Saturate: '<S50>/Saturation' */
    if (rtb_Add >= fangzhen20050606_P.Saturation_UpperSat[0]) {
      fangzhen20050606_B.Saturation[0] = fangzhen20050606_P.Saturation_UpperSat
        [0];
    } else if (rtb_Add <= fangzhen20050606_P.Saturation_LowerSat[0]) {
      fangzhen20050606_B.Saturation[0] = fangzhen20050606_P.Saturation_LowerSat
        [0];
    } else {
      fangzhen20050606_B.Saturation[0] = rtb_Add;
    }

    /* Gain: '<S50>/Ki' */
    rtb_Add = fangzhen20050606_P.Ki_Gain[1] *
      fangzhen20050606_B.DiscreteTimeIntegrator[1];

    /* Saturate: '<S50>/Saturation' */
    if (rtb_Add >= fangzhen20050606_P.Saturation_UpperSat[1]) {
      fangzhen20050606_B.Saturation[1] = fangzhen20050606_P.Saturation_UpperSat
        [1];
    } else if (rtb_Add <= fangzhen20050606_P.Saturation_LowerSat[1]) {
      fangzhen20050606_B.Saturation[1] = fangzhen20050606_P.Saturation_LowerSat
        [1];
    } else {
      fangzhen20050606_B.Saturation[1] = rtb_Add;
    }

    /* Gain: '<S50>/Ki' */
    rtb_Add = fangzhen20050606_P.Ki_Gain[2] *
      fangzhen20050606_B.DiscreteTimeIntegrator[2];

    /* Saturate: '<S50>/Saturation' */
    if (rtb_Add >= fangzhen20050606_P.Saturation_UpperSat[2]) {
      fangzhen20050606_B.Saturation[2] = fangzhen20050606_P.Saturation_UpperSat
        [2];
    } else if (rtb_Add <= fangzhen20050606_P.Saturation_LowerSat[2]) {
      fangzhen20050606_B.Saturation[2] = fangzhen20050606_P.Saturation_LowerSat
        [2];
    } else {
      fangzhen20050606_B.Saturation[2] = rtb_Add;
    }
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S50>/Gain' incorporates:
     *  Gain: '<S50>/Kd'
     *  Gain: '<S50>/Kp'
     *  Sum: '<S50>/Sum1'
     *  Sum: '<S50>/Sum2'
     */
    rtb_Gain_in[0] = ((fangzhen20050606_P.Kp_Gain[0] * fangzhen20050606_B.Sum_c
                       [0] + fangzhen20050606_B.Saturation[0]) +
                      (fangzhen20050606_B.Constant1_e[0] -
                       fangzhen20050606_B.SFunction[4]) *
                      fangzhen20050606_P.Kd_Gain[0]) *
      fangzhen20050606_P.Gain_Gain_c2[0];
    rtb_Gain_in[1] = ((fangzhen20050606_P.Kp_Gain[1] * fangzhen20050606_B.Sum_c
                       [1] + fangzhen20050606_B.Saturation[1]) +
                      (fangzhen20050606_B.Constant1_e[1] -
                       fangzhen20050606_B.SFunction[5]) *
                      fangzhen20050606_P.Kd_Gain[1]) *
      fangzhen20050606_P.Gain_Gain_c2[1];
    rtb_Gain_in[2] = ((fangzhen20050606_P.Kp_Gain[2] * fangzhen20050606_B.Sum_c
                       [2] + fangzhen20050606_B.Saturation[2]) +
                      (fangzhen20050606_B.Constant1_e[2] -
                       fangzhen20050606_B.SFunction[6]) *
                      fangzhen20050606_P.Kd_Gain[2]) *
      fangzhen20050606_P.Gain_Gain_c2[2];

    /* Gain: '<S50>/MWN' incorporates:
     *  Saturate: '<S25>/Saturation'
     */
    for (i = 0; i < 4; i++) {
      tmp_0[i] = fangzhen20050606_P.MWN_Gain[i + 8] * rtb_Gain_in[2] +
        (fangzhen20050606_P.MWN_Gain[i + 4] * rtb_Gain_in[1] +
         fangzhen20050606_P.MWN_Gain[i] * rtb_Gain_in[0]);
    }

    /* Sum: '<S25>/Sum' incorporates:
     *  Gain: '<S50>/MWN'
     *  Saturate: '<S25>/Saturation'
     */
    if (tmp_0[0] >= fangzhen20050606_P.Saturation_UpperSat_a[0]) {
      rtb_Add = fangzhen20050606_P.Saturation_UpperSat_a[0];
    } else if (tmp_0[0] <= fangzhen20050606_P.Saturation_LowerSat_o[0]) {
      rtb_Add = fangzhen20050606_P.Saturation_LowerSat_o[0];
    } else {
      rtb_Add = tmp_0[0];
    }

    fangzhen20050606_B.Sum_p[0] = rtb_Add + rtb_Sum1_a[0];
    if (tmp_0[1] >= fangzhen20050606_P.Saturation_UpperSat_a[1]) {
      rtb_Add = fangzhen20050606_P.Saturation_UpperSat_a[1];
    } else if (tmp_0[1] <= fangzhen20050606_P.Saturation_LowerSat_o[1]) {
      rtb_Add = fangzhen20050606_P.Saturation_LowerSat_o[1];
    } else {
      rtb_Add = tmp_0[1];
    }

    fangzhen20050606_B.Sum_p[1] = rtb_Add + rtb_Sum1_a[1];
    if (tmp_0[2] >= fangzhen20050606_P.Saturation_UpperSat_a[2]) {
      rtb_Add = fangzhen20050606_P.Saturation_UpperSat_a[2];
    } else if (tmp_0[2] <= fangzhen20050606_P.Saturation_LowerSat_o[2]) {
      rtb_Add = fangzhen20050606_P.Saturation_LowerSat_o[2];
    } else {
      rtb_Add = tmp_0[2];
    }

    fangzhen20050606_B.Sum_p[2] = rtb_Add + rtb_Sum1_a[2];
    if (tmp_0[3] >= fangzhen20050606_P.Saturation_UpperSat_a[3]) {
      rtb_Add = fangzhen20050606_P.Saturation_UpperSat_a[3];
    } else if (tmp_0[3] <= fangzhen20050606_P.Saturation_LowerSat_o[3]) {
      rtb_Add = fangzhen20050606_P.Saturation_LowerSat_o[3];
    } else {
      rtb_Add = tmp_0[3];
    }

    fangzhen20050606_B.Sum_p[3] = rtb_Add + rtb_Sum1_a[3];

    /* End of Sum: '<S25>/Sum' */
  }

  /* Sum: '<S9>/Sum1' incorporates:
   *  Product: '<S27>/Product'
   *  Product: '<S27>/Product1'
   *  Sum: '<S27>/Sum'
   */
  fangzhen20050606_B.Sum1_p[0] = rtb_AWcc[0] - (rtb_Product_ht[1] *
    rtb_Integrator1[2] - rtb_Product_ht[2] * rtb_Integrator1[1]);
  fangzhen20050606_B.Sum1_p[1] = rtb_AWcc[1] - (rtb_Product_ht[2] *
    rtb_Integrator1[0] - rtb_Product_ht[0] * rtb_Integrator1[2]);
  fangzhen20050606_B.Sum1_p[2] = rtb_AWcc[2] - (rtb_Product_ht[0] *
    rtb_Integrator1[1] - rtb_Product_ht[1] * rtb_Integrator1[0]);

  /* Product: '<S29>/i x j' */
  rtb_Yaw = rtb_Integrator[1] * rtb_Sum2_l[1];

  /* Product: '<S29>/j x k' */
  rtb_Product_dn = rtb_Integrator[2] * rtb_Sum2_l[2];

  /* Product: '<S30>/k x j' */
  rtb_Pitch = rtb_Integrator[3] * rtb_Sum2_l[1];

  /* Sum: '<S28>/Sum' incorporates:
   *  Product: '<S29>/k x i'
   *  Product: '<S30>/i x k'
   *  Product: '<S30>/j x i'
   */
  rtb_MatrixGain_k[0] = rtb_Product_dn - rtb_Pitch;
  rtb_MatrixGain_k[1] = rtb_Integrator[3] * rtb_Sum2_l[0] - rtb_Integrator[1] *
    rtb_Sum2_l[2];
  rtb_MatrixGain_k[2] = rtb_Yaw - rtb_Integrator[2] * rtb_Sum2_l[0];

  /* DotProduct: '<S10>/Dot Product' */
  rtb_Yaw = (rtb_Sum2_l[0] * rtb_Integrator[1] + rtb_Sum2_l[1] * rtb_Integrator
             [2]) + rtb_Sum2_l[2] * rtb_Integrator[3];

  /* Gain: '<S10>/Gain' */
  fangzhen20050606_B.Gain = fangzhen20050606_P.Gain_Gain_d * rtb_Yaw;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Product: '<S10>/Product'
   *  Sum: '<S10>/Sum1'
   */
  fangzhen20050606_B.Gain1_a[0] = (rtb_Integrator[0] * rtb_Sum2_l[0] +
    rtb_MatrixGain_k[0]) * fangzhen20050606_P.Gain1_Gain_c;
  fangzhen20050606_B.Gain1_a[1] = (rtb_Integrator[0] * rtb_Sum2_l[1] +
    rtb_MatrixGain_k[1]) * fangzhen20050606_P.Gain1_Gain_c;
  fangzhen20050606_B.Gain1_a[2] = (rtb_Integrator[0] * rtb_Sum2_l[2] +
    rtb_MatrixGain_k[2]) * fangzhen20050606_P.Gain1_Gain_c;

  /* Gain: '<S1>/Gain' */
  rtb_Sum2_l[0] = fangzhen20050606_P.Gain_Gain_cs *
    fangzhen20050606_B.Product3_f[0];
  rtb_Sum2_l[1] = fangzhen20050606_P.Gain_Gain_cs *
    fangzhen20050606_B.Product3_f[1];
  rtb_Sum2_l[2] = fangzhen20050606_P.Gain_Gain_cs *
    fangzhen20050606_B.Product3_f[2];

  /* Math: '<S1>/Math Function' */
  for (i = 0; i < 3; i++) {
    rtb_MathFunction_n[3 * i] = fangzhen20050606_B.VectorConcatenate[i];
    rtb_MathFunction_n[1 + 3 * i] = fangzhen20050606_B.VectorConcatenate[i + 3];
    rtb_MathFunction_n[2 + 3 * i] = fangzhen20050606_B.VectorConcatenate[i + 6];
  }

  /* End of Math: '<S1>/Math Function' */

  /* Integrator: '<S36>/Integrator2' */
  rtb_Yaw = fangzhen20050606_X.Integrator2_CSTATE;

  /* Sum: '<S36>/Sum2' incorporates:
   *  Constant: '<S36>/m0'
   */
  fangzhen20050606_B.Sum2 = fangzhen20050606_P.m0_Value - rtb_Yaw;
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Abs: '<S36>/Abs1' */
  rtb_Yaw = fabs(fangzhen20050606_B.Integrator_n[2]);

  /* Logic: '<S36>/Logical Operator1' incorporates:
   *  Constant: '<S36>/Constant'
   *  Constant: '<S36>/Constant1'
   *  Constant: '<S36>/Constant2'
   *  Logic: '<S36>/Logical Operator'
   *  RelationalOperator: '<S36>/Relational Operator'
   *  RelationalOperator: '<S36>/Relational Operator1'
   *  RelationalOperator: '<S36>/Relational Operator2'
   */
  fangzhen20050606_B.LogicalOperator1 = ((fangzhen20050606_B.Integrator1[2] <=
    fangzhen20050606_P.Constant2_Value_d) || ((fangzhen20050606_B.Integrator1[2]
    <= fangzhen20050606_P.Constant_Value_lv) && (rtb_Yaw <=
    fangzhen20050606_P.Constant1_Value_h)));

  /* Stop: '<S36>/Stop Simulation' */
  if ((rtmIsMajorTimeStep(fangzhen20050606_M) &&
       fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) &&
      fangzhen20050606_B.LogicalOperator1) {
    rtmSetStopRequested(fangzhen20050606_M, 1);
  }

  /* End of Stop: '<S36>/Stop Simulation' */

  /* Sum: '<S38>/Sum' incorporates:
   *  Constant: '<S38>/[0;0;R0]'
   *  Gain: '<S38>/Matrix Gain'
   *  Gain: '<S38>/Matrix Gain1'
   */
  for (i = 0; i < 3; i++) {
    tmp_1[i] = ((fangzhen20050606_P.MatrixGain_Gain[i + 3] *
                 fangzhen20050606_B.Integrator1[1] +
                 fangzhen20050606_P.MatrixGain_Gain[i] *
                 fangzhen20050606_B.Integrator1[0]) +
                fangzhen20050606_P.MatrixGain_Gain[i + 6] *
                fangzhen20050606_B.Integrator1[2]) +
      fangzhen20050606_P.u0R0_Value[i];
  }

  /* End of Sum: '<S38>/Sum' */

  /* Gain: '<S38>/Matrix Gain1' */
  for (i = 0; i < 3; i++) {
    rtb_MatrixGain2[i] = fangzhen20050606_P.MatrixGain1_Gain[i + 6] * tmp_1[2] +
      (fangzhen20050606_P.MatrixGain1_Gain[i + 3] * tmp_1[1] +
       fangzhen20050606_P.MatrixGain1_Gain[i] * tmp_1[0]);
  }

  /* Trigonometry: '<S42>/Trigonometric Function' incorporates:
   *  Product: '<S42>/Product'
   */
  rtb_Yaw = atan(rtb_MatrixGain2[1] / rtb_MatrixGain2[0]);

  /* Trigonometry: '<S43>/Trigonometric Function' */
  rtb_Product_dn = sin(rtb_Yaw);

  /* Gain: '<S43>/Gain1' incorporates:
   *  Constant: '<S43>/Constant'
   *  Gain: '<S43>/Gain'
   *  Math: '<S43>/Math Function'
   *  Sum: '<S43>/Sum'
   *
   * About '<S43>/Math Function':
   *  Operator: magnitude^2
   */
  rtb_Gain1_nt = (fangzhen20050606_P.Constant_Value_n - rtb_Product_dn *
                  rtb_Product_dn * fangzhen20050606_P.Gain_Gain_ju) *
    fangzhen20050606_P.Gain1_Gain_h;

  /* Trigonometry: '<S43>/Trigonometric Function1' */
  rtb_Product_dn = cos(rtb_Yaw);

  /* Math: '<S43>/Math Function1'
   *
   * About '<S43>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Product1_ck = rtb_Product_dn * rtb_Product_dn;

  /* Sum: '<S46>/Sum' incorporates:
   *  Math: '<S46>/Math Function1'
   *  Math: '<S46>/Math Function2'
   *  Math: '<S46>/Math Function3'
   *
   * About '<S46>/Math Function1':
   *  Operator: magnitude^2
   *
   * About '<S46>/Math Function2':
   *  Operator: magnitude^2
   *
   * About '<S46>/Math Function3':
   *  Operator: magnitude^2
   */
  rtb_Product_dn = (rtb_MatrixGain2[0] * rtb_MatrixGain2[0] + rtb_MatrixGain2[1]
                    * rtb_MatrixGain2[1]) + rtb_MatrixGain2[2] *
    rtb_MatrixGain2[2];

  /* Math: '<S46>/Math Function'
   *
   * About '<S46>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Product_dn < 0.0) {
    rtb_Product_dn = -sqrt(fabs(rtb_Product_dn));
  } else {
    rtb_Product_dn = sqrt(rtb_Product_dn);
  }

  /* End of Math: '<S46>/Math Function' */

  /* Product: '<S41>/Product' */
  rtb_Add = rtb_MatrixGain2[2] / rtb_Product_dn;

  /* Trigonometry: '<S41>/Trigonometric Function' */
  if (rtb_Add >= 1.0) {
    rtb_Add = 1.0;
  } else {
    if (rtb_Add <= -1.0) {
      rtb_Add = -1.0;
    }
  }

  rtb_Product1_jh = asin(rtb_Add);

  /* End of Trigonometry: '<S41>/Trigonometric Function' */

  /* Math: '<S43>/Math Function2'
   *
   * About '<S43>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_Product2_bk = rtb_Product_dn * rtb_Product_dn;

  /* Product: '<S43>/Product2' incorporates:
   *  Constant: '<S43>/Constant1'
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant3'
   *  Constant: '<S43>/Constant4'
   *  Gain: '<S43>/Gain2'
   *  Gain: '<S43>/Gain3'
   *  Gain: '<S43>/Gain4'
   *  Product: '<S43>/Product'
   *  Product: '<S43>/Product1'
   *  Product: '<S43>/Product3'
   *  Sum: '<S43>/Sum1'
   *  Sum: '<S43>/Sum2'
   *  Sum: '<S43>/Sum3'
   *  Trigonometry: '<S43>/Trigonometric Function2'
   */
  rtb_Product2_bk = (fangzhen20050606_P.Constant3_Value_f -
                     ((fangzhen20050606_P.Constant1_Value_eb - cos
                       (fangzhen20050606_P.Gain2_Gain_p * rtb_Product1_jh) *
                       rtb_Product1_ck * fangzhen20050606_P.Gain3_Gain_dv) *
                      fangzhen20050606_P.Gain4_Gain_f + rtb_Gain1_nt) *
                     fangzhen20050606_P.Constant2_Value_f / rtb_Product2_bk) *
    (rtb_MatrixGain2[0] * fangzhen20050606_P.Constant4_Value_d) /
    (rtb_Product2_bk * rtb_Product_dn);

  /* Trigonometry: '<S44>/Trigonometric Function' */
  rtb_Roll = sin(rtb_Yaw);

  /* Gain: '<S44>/Gain1' incorporates:
   *  Constant: '<S44>/Constant'
   *  Gain: '<S44>/Gain'
   *  Math: '<S44>/Math Function'
   *  Sum: '<S44>/Sum'
   *
   * About '<S44>/Math Function':
   *  Operator: magnitude^2
   */
  rtb_Gain1_nt = (fangzhen20050606_P.Constant_Value_o - rtb_Roll * rtb_Roll *
                  fangzhen20050606_P.Gain_Gain_jw) *
    fangzhen20050606_P.Gain1_Gain_i;

  /* Trigonometry: '<S44>/Trigonometric Function1' */
  rtb_Roll = cos(rtb_Yaw);

  /* Math: '<S44>/Math Function1'
   *
   * About '<S44>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Product1_ck = rtb_Roll * rtb_Roll;

  /* Math: '<S44>/Math Function2'
   *
   * About '<S44>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_Roll = rtb_Product_dn * rtb_Product_dn;

  /* Product: '<S44>/Product2' incorporates:
   *  Constant: '<S44>/Constant1'
   *  Constant: '<S44>/Constant2'
   *  Constant: '<S44>/Constant3'
   *  Constant: '<S44>/Constant4'
   *  Gain: '<S44>/Gain2'
   *  Gain: '<S44>/Gain3'
   *  Gain: '<S44>/Gain4'
   *  Product: '<S44>/Product'
   *  Product: '<S44>/Product1'
   *  Product: '<S44>/Product3'
   *  Sum: '<S44>/Sum1'
   *  Sum: '<S44>/Sum2'
   *  Sum: '<S44>/Sum3'
   *  Trigonometry: '<S44>/Trigonometric Function2'
   */
  rtb_Roll = (fangzhen20050606_P.Constant3_Value_cb - (rtb_Gain1_nt - (cos
    (fangzhen20050606_P.Gain2_Gain_gy * rtb_Product1_jh) * rtb_Product1_ck *
    fangzhen20050606_P.Gain3_Gain_om + fangzhen20050606_P.Constant1_Value_g) *
    fangzhen20050606_P.Gain4_Gain_a) * fangzhen20050606_P.Constant2_Value_pw /
              rtb_Roll) * (fangzhen20050606_P.Constant4_Value_a *
    rtb_MatrixGain2[1]) / (rtb_Roll * rtb_Product_dn);

  /* Trigonometry: '<S45>/Trigonometric Function' */
  rtb_Pitch = sin(rtb_Yaw);

  /* Trigonometry: '<S45>/Trigonometric Function1' */
  rtb_Yaw = cos(rtb_Yaw);

  /* Gain: '<S45>/Gain4' incorporates:
   *  Gain: '<S45>/Gain2'
   *  Math: '<S45>/Math Function1'
   *  Product: '<S45>/Product'
   *  Trigonometry: '<S45>/Trigonometric Function2'
   *
   * About '<S45>/Math Function1':
   *  Operator: magnitude^2
   */
  rtb_Gain1_nt = rtb_Yaw * rtb_Yaw * cos(fangzhen20050606_P.Gain2_Gain_pd *
    rtb_Product1_jh) * fangzhen20050606_P.Gain4_Gain_o;

  /* Math: '<S45>/Math Function2'
   *
   * About '<S45>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_Yaw = rtb_Product_dn * rtb_Product_dn;

  /* Product: '<S45>/Product2' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S45>/Constant2'
   *  Constant: '<S45>/Constant3'
   *  Constant: '<S45>/Constant4'
   *  Gain: '<S45>/Gain'
   *  Gain: '<S45>/Gain1'
   *  Math: '<S45>/Math Function'
   *  Product: '<S45>/Product1'
   *  Product: '<S45>/Product3'
   *  Sum: '<S45>/Sum'
   *  Sum: '<S45>/Sum1'
   *  Sum: '<S45>/Sum3'
   *
   * About '<S45>/Math Function':
   *  Operator: magnitude^2
   */
  rtb_Yaw = (fangzhen20050606_P.Constant3_Value_g -
             ((fangzhen20050606_P.Constant_Value_e - rtb_Pitch * rtb_Pitch *
               fangzhen20050606_P.Gain_Gain_jh) *
              fangzhen20050606_P.Gain1_Gain_o - rtb_Gain1_nt) *
             fangzhen20050606_P.Constant2_Value_n / rtb_Yaw) *
    (fangzhen20050606_P.Constant4_Value_de * rtb_MatrixGain2[2]) / (rtb_Yaw *
    rtb_Product_dn);

  /* Gain: '<S38>/Matrix Gain2' incorporates:
   *  SignalConversion: '<S38>/TmpSignal ConversionAtMatrix Gain2Inport1'
   */
  for (i = 0; i < 3; i++) {
    rtb_MatrixGain2[i] = fangzhen20050606_P.MatrixGain2_Gain[i + 6] * rtb_Yaw +
      (fangzhen20050606_P.MatrixGain2_Gain[i + 3] * rtb_Roll +
       fangzhen20050606_P.MatrixGain2_Gain[i] * rtb_Product2_bk);
  }

  /* End of Gain: '<S38>/Matrix Gain2' */

  /* Sum: '<S39>/Sum' incorporates:
   *  Constant: '<S39>/R0'
   *  Gain: '<S39>/Matrix Gain'
   */
  rtb_Add = fangzhen20050606_B.Integrator1[0] + fangzhen20050606_P.R0_Value[0];
  rtb_Product1_jh = fangzhen20050606_B.Integrator1[1] +
    fangzhen20050606_P.R0_Value[1];
  rtb_Product_by_idx_2 = fangzhen20050606_B.Integrator1[2] +
    fangzhen20050606_P.R0_Value[2];

  /* Gain: '<S39>/Matrix Gain' */
  for (i = 0; i < 3; i++) {
    rtb_AWcc[i] = fangzhen20050606_P.MatrixGain_Gain_o[i + 6] *
      rtb_Product_by_idx_2 + (fangzhen20050606_P.MatrixGain_Gain_o[i + 3] *
      rtb_Product1_jh + fangzhen20050606_P.MatrixGain_Gain_o[i] * rtb_Add);
  }

  /* Gain: '<S37>/Matrix Gain' */
  for (i = 0; i < 3; i++) {
    rtb_MatrixGain_k[i] = fangzhen20050606_P.MatrixGain_Gain_n[i + 6] *
      fangzhen20050606_B.Integrator_n[2] +
      (fangzhen20050606_P.MatrixGain_Gain_n[i + 3] *
       fangzhen20050606_B.Integrator_n[1] +
       fangzhen20050606_P.MatrixGain_Gain_n[i] *
       fangzhen20050606_B.Integrator_n[0]);
  }

  /* End of Gain: '<S37>/Matrix Gain' */

  /* Sum: '<S36>/Sum1' */
  fangzhen20050606_B.Sum1_o[0] = (rtb_MatrixGain2[0] + rtb_AWcc[0]) +
    rtb_MatrixGain_k[0];
  fangzhen20050606_B.Sum1_o[1] = (rtb_MatrixGain2[1] + rtb_AWcc[1]) +
    rtb_MatrixGain_k[1];
  fangzhen20050606_B.Sum1_o[2] = (rtb_MatrixGain2[2] + rtb_AWcc[2]) +
    rtb_MatrixGain_k[2];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Product: '<S1>/Product1' */
  for (i = 0; i < 3; i++) {
    rtb_Product_ht[i] = rtb_MathFunction_n[i + 6] * rtb_Sum2_l[2] +
      (rtb_MathFunction_n[i + 3] * rtb_Sum2_l[1] + rtb_MathFunction_n[i] *
       rtb_Sum2_l[0]);
  }

  /* End of Product: '<S1>/Product1' */

  /* Gain: '<S36>/Gain' incorporates:
   *  Abs: '<S36>/Abs'
   */
  rtb_Sum2_l[0] = fangzhen20050606_P.Gain_Gain_ae * fabs(rtb_Product_ht[0]);
  rtb_Sum2_l[1] = fangzhen20050606_P.Gain_Gain_ae * fabs(rtb_Product_ht[1]);
  rtb_Sum2_l[2] = fangzhen20050606_P.Gain_Gain_ae * fabs(rtb_Product_ht[2]);

  /* Product: '<S36>/Product' */
  rtb_Add = 1.0 / fangzhen20050606_B.Sum2;
  rtb_Product_ht[0] *= rtb_Add;
  rtb_Product_ht[1] *= rtb_Add;
  rtb_Add *= rtb_Product_ht[2];

  /* Sum: '<S36>/Sum' */
  fangzhen20050606_B.Sum_b[0] = ((rtb_Product_ht[0] + rtb_MatrixGain2[0]) +
    rtb_AWcc[0]) + rtb_MatrixGain_k[0];
  fangzhen20050606_B.Sum_b[1] = ((rtb_Product_ht[1] + rtb_MatrixGain2[1]) +
    rtb_AWcc[1]) + rtb_MatrixGain_k[1];
  fangzhen20050606_B.Sum_b[2] = ((rtb_Add + rtb_MatrixGain2[2]) + rtb_AWcc[2]) +
    rtb_MatrixGain_k[2];

  /* Sum: '<S36>/Sum3' */
  fangzhen20050606_B.Sum3 = (rtb_Sum2_l[0] + rtb_Sum2_l[1]) + rtb_Sum2_l[2];

  /* Product: '<S1>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_Sum2_l[i] = fangzhen20050606_B.VectorConcatenate[i + 6] * rtb_Add +
      (fangzhen20050606_B.VectorConcatenate[i + 3] * rtb_Product_ht[1] +
       fangzhen20050606_B.VectorConcatenate[i] * rtb_Product_ht[0]);
  }

  /* End of Product: '<S1>/Product' */
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sqrt: '<S73>/sqrt' incorporates:
     *  Product: '<S74>/Product'
     *  Product: '<S74>/Product1'
     *  Product: '<S74>/Product2'
     *  Product: '<S74>/Product3'
     *  Sum: '<S74>/Sum'
     */
    rtb_Product2_bk = sqrt(((fangzhen20050606_B.SFunction[0] *
      fangzhen20050606_B.SFunction[0] + fangzhen20050606_B.SFunction[1] *
      fangzhen20050606_B.SFunction[1]) + fangzhen20050606_B.SFunction[2] *
      fangzhen20050606_B.SFunction[2]) + fangzhen20050606_B.SFunction[3] *
      fangzhen20050606_B.SFunction[3]);

    /* Product: '<S67>/Product' */
    rtb_Roll = fangzhen20050606_B.SFunction[0] / rtb_Product2_bk;

    /* Product: '<S67>/Product1' */
    rtb_Product1_ck = fangzhen20050606_B.SFunction[1] / rtb_Product2_bk;

    /* Product: '<S67>/Product2' */
    rtb_Gain1_nt = fangzhen20050606_B.SFunction[2] / rtb_Product2_bk;

    /* Product: '<S67>/Product3' */
    rtb_Product2_bk = fangzhen20050606_B.SFunction[3] / rtb_Product2_bk;

    /* Gain: '<S2>/Gain1' incorporates:
     *  Gain: '<S72>/Gain'
     *  Product: '<S71>/Product'
     *  Product: '<S71>/Product1'
     *  Product: '<S71>/Product2'
     *  Product: '<S71>/Product3'
     *  Product: '<S72>/Product1'
     *  Product: '<S72>/Product2'
     *  Sum: '<S71>/Sum'
     *  Sum: '<S72>/Sum'
     *  Trigonometry: '<S48>/Trigonometric Function1'
     */
    fangzhen20050606_B.Gain1_c[0] = rt_atan2d_snf((rtb_Roll * rtb_Product1_ck +
      rtb_Gain1_nt * rtb_Product2_bk) * fangzhen20050606_P.Gain_Gain_if,
      ((rtb_Roll * rtb_Roll - rtb_Product1_ck * rtb_Product1_ck) - rtb_Gain1_nt *
       rtb_Gain1_nt) + rtb_Product2_bk * rtb_Product2_bk) *
      fangzhen20050606_P.Gain1_Gain_j1;

    /* Gain: '<S70>/Gain' incorporates:
     *  Product: '<S70>/Product1'
     *  Product: '<S70>/Product2'
     *  Sum: '<S70>/Sum'
     */
    rtb_Add = (rtb_Roll * rtb_Gain1_nt - rtb_Product1_ck * rtb_Product2_bk) *
      fangzhen20050606_P.Gain_Gain_ib;

    /* Trigonometry: '<S48>/Trigonometric Function2' */
    if (rtb_Add >= 1.0) {
      rtb_Add = 1.0;
    } else {
      if (rtb_Add <= -1.0) {
        rtb_Add = -1.0;
      }
    }

    /* Gain: '<S2>/Gain1' incorporates:
     *  Gain: '<S69>/Gain'
     *  Product: '<S68>/Product'
     *  Product: '<S68>/Product1'
     *  Product: '<S68>/Product2'
     *  Product: '<S68>/Product3'
     *  Product: '<S69>/Product2'
     *  Product: '<S69>/Product3'
     *  Sum: '<S68>/Sum'
     *  Sum: '<S69>/Sum'
     *  Trigonometry: '<S48>/Trigonometric Function2'
     *  Trigonometry: '<S48>/Trigonometric Function3'
     */
    fangzhen20050606_B.Gain1_c[1] = fangzhen20050606_P.Gain1_Gain_j1 * asin
      (rtb_Add);
    fangzhen20050606_B.Gain1_c[2] = rt_atan2d_snf((rtb_Product2_bk * rtb_Roll +
      rtb_Product1_ck * rtb_Gain1_nt) * fangzhen20050606_P.Gain_Gain_gj,
      ((rtb_Roll * rtb_Roll + rtb_Product1_ck * rtb_Product1_ck) - rtb_Gain1_nt *
       rtb_Gain1_nt) - rtb_Product2_bk * rtb_Product2_bk) *
      fangzhen20050606_P.Gain1_Gain_j1;
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Clock: '<S2>/Clock' */
  fangzhen20050606_B.Clock_a = fangzhen20050606_M->Timing.t[0];
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S2>/Gain2' */
    fangzhen20050606_B.Gain2_d[0] = fangzhen20050606_P.Gain2_Gain_fq *
      fangzhen20050606_B.SFunction[4];
    fangzhen20050606_B.Gain2_d[1] = fangzhen20050606_P.Gain2_Gain_fq *
      fangzhen20050606_B.SFunction[5];
    fangzhen20050606_B.Gain2_d[2] = fangzhen20050606_P.Gain2_Gain_fq *
      fangzhen20050606_B.SFunction[6];
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion: '<S2>/TmpSignal ConversionAtTo WorkspaceInport1' */
    rtb_TmpSignalConversionAtToW_of[0] = fangzhen20050606_B.Clock_a;
    rtb_TmpSignalConversionAtToW_of[1] = fangzhen20050606_B.Sum4[0];
    rtb_TmpSignalConversionAtToW_of[2] = fangzhen20050606_B.Sum4[1];
    rtb_TmpSignalConversionAtToW_of[3] = fangzhen20050606_B.Sum4[2];
    rtb_TmpSignalConversionAtToW_of[4] = fangzhen20050606_B.Sum1[0];
    rtb_TmpSignalConversionAtToW_of[5] = fangzhen20050606_B.Sum1[1];
    rtb_TmpSignalConversionAtToW_of[6] = fangzhen20050606_B.Sum1[2];
    rtb_TmpSignalConversionAtToW_of[7] = fangzhen20050606_B.Gain1_c[0];
    rtb_TmpSignalConversionAtToW_of[8] = fangzhen20050606_B.Gain1_c[1];
    rtb_TmpSignalConversionAtToW_of[9] = fangzhen20050606_B.Gain1_c[2];
    rtb_TmpSignalConversionAtToW_of[10] = fangzhen20050606_B.Gain2_d[0];
    rtb_TmpSignalConversionAtToW_of[11] = fangzhen20050606_B.Gain2_d[1];
    rtb_TmpSignalConversionAtToW_of[12] = fangzhen20050606_B.Gain2_d[2];

    /* ToWorkspace: '<S2>/To Workspace' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (fangzhen20050606_DWork.ToWorkspace_PWORK_i.LoggedData),
                    rtb_TmpSignalConversionAtToW_of, 0);

    /* ToWorkspace: '<S2>/To Workspace1' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (fangzhen20050606_DWork.ToWorkspace1_PWORK_j.LoggedData),
                    fangzhen20050606_B.Product2, 0);
  }

  /* Sum: '<S140>/Sum' incorporates:
   *  Product: '<S140>/Product'
   *  Product: '<S140>/Product1'
   *  Product: '<S140>/Product2'
   *  Product: '<S140>/Product3'
   */
  rtb_Yaw = ((fangzhen20050606_B.Merge[0] * fangzhen20050606_B.Merge[0] +
              fangzhen20050606_B.Merge[1] * fangzhen20050606_B.Merge[1]) +
             fangzhen20050606_B.Merge[2] * fangzhen20050606_B.Merge[2]) +
    fangzhen20050606_B.Merge[3] * fangzhen20050606_B.Merge[3];

  /* Sqrt: '<S139>/sqrt' */
  rtb_Yaw = sqrt(rtb_Yaw);

  /* Product: '<S133>/Product' */
  rtb_Product_dn = fangzhen20050606_B.Merge[0] / rtb_Yaw;

  /* Product: '<S133>/Product1' */
  rtb_Product1_jh = fangzhen20050606_B.Merge[1] / rtb_Yaw;

  /* Product: '<S133>/Product2' */
  rtb_Product2_bk = fangzhen20050606_B.Merge[2] / rtb_Yaw;

  /* Product: '<S133>/Product3' */
  rtb_Yaw = fangzhen20050606_B.Merge[3] / rtb_Yaw;

  /* Product: '<S138>/Product2' */
  rtb_Gain1_nt = rtb_Product2_bk * rtb_Yaw;

  /* Sum: '<S137>/Sum' incorporates:
   *  Product: '<S137>/Product'
   *  Product: '<S137>/Product1'
   *  Product: '<S137>/Product2'
   *  Product: '<S137>/Product3'
   */
  rtb_Product1_ck = ((rtb_Product_dn * rtb_Product_dn - rtb_Product1_jh *
                      rtb_Product1_jh) - rtb_Product2_bk * rtb_Product2_bk) +
    rtb_Yaw * rtb_Yaw;

  /* Gain: '<S136>/Gain' incorporates:
   *  Product: '<S136>/Product1'
   *  Product: '<S136>/Product2'
   *  Sum: '<S136>/Sum'
   */
  rtb_Add = (rtb_Product_dn * rtb_Product2_bk - rtb_Product1_jh * rtb_Yaw) *
    fangzhen20050606_P.Gain_Gain_ae0;

  /* Trigonometry: '<S81>/Trigonometric Function2' */
  if (rtb_Add >= 1.0) {
    rtb_Add = 1.0;
  } else {
    if (rtb_Add <= -1.0) {
      rtb_Add = -1.0;
    }
  }

  rtb_Pitch = asin(rtb_Add);

  /* End of Trigonometry: '<S81>/Trigonometric Function2' */

  /* Trigonometry: '<S81>/Trigonometric Function3' incorporates:
   *  Gain: '<S135>/Gain'
   *  Product: '<S134>/Product'
   *  Product: '<S134>/Product1'
   *  Product: '<S134>/Product2'
   *  Product: '<S134>/Product3'
   *  Product: '<S135>/Product2'
   *  Product: '<S135>/Product3'
   *  Sum: '<S134>/Sum'
   *  Sum: '<S135>/Sum'
   */
  rtb_Yaw = rt_atan2d_snf((rtb_Yaw * rtb_Product_dn + rtb_Product1_jh *
    rtb_Product2_bk) * fangzhen20050606_P.Gain_Gain_jk, ((rtb_Product_dn *
    rtb_Product_dn + rtb_Product1_jh * rtb_Product1_jh) - rtb_Product2_bk *
    rtb_Product2_bk) - rtb_Yaw * rtb_Yaw);

  /* Gain: '<S51>/Gain1' incorporates:
   *  Gain: '<S138>/Gain'
   *  Product: '<S138>/Product1'
   *  Sum: '<S138>/Sum'
   *  Trigonometry: '<S81>/Trigonometric Function1'
   */
  fangzhen20050606_B.Gain1_f[0] = rt_atan2d_snf((rtb_Product_dn *
    rtb_Product1_jh + rtb_Gain1_nt) * fangzhen20050606_P.Gain_Gain_lv,
    rtb_Product1_ck) * fangzhen20050606_P.Gain1_Gain_e;
  fangzhen20050606_B.Gain1_f[1] = fangzhen20050606_P.Gain1_Gain_e * rtb_Pitch;
  fangzhen20050606_B.Gain1_f[2] = fangzhen20050606_P.Gain1_Gain_e * rtb_Yaw;
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* ToWorkspace: '<S51>/To Workspace' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (fangzhen20050606_DWork.ToWorkspace_PWORK_m.LoggedData),
                    fangzhen20050606_B.Gain1_f, 0);

    /* ToWorkspace: '<S51>/To Workspace1' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (fangzhen20050606_DWork.ToWorkspace1_PWORK_o.LoggedData),
                    fangzhen20050606_B.e5, 0);
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0) {
    /* Sqrt: '<S131>/sqrt' incorporates:
     *  Product: '<S132>/Product'
     *  Product: '<S132>/Product1'
     *  Product: '<S132>/Product2'
     *  Product: '<S132>/Product3'
     *  Sum: '<S132>/Sum'
     */
    rtb_Gain1_nt = sqrt(((fangzhen20050606_B.SFunction[0] *
                          fangzhen20050606_B.SFunction[0] +
                          fangzhen20050606_B.SFunction[1] *
                          fangzhen20050606_B.SFunction[1]) +
                         fangzhen20050606_B.SFunction[2] *
                         fangzhen20050606_B.SFunction[2]) +
                        fangzhen20050606_B.SFunction[3] *
                        fangzhen20050606_B.SFunction[3]);

    /* Product: '<S130>/Product3' */
    rtb_Product1_ck = fangzhen20050606_B.SFunction[3] / rtb_Gain1_nt;

    /* Product: '<S130>/Product2' */
    rtb_Product2_bk = fangzhen20050606_B.SFunction[2] / rtb_Gain1_nt;

    /* Product: '<S130>/Product1' */
    rtb_Roll = fangzhen20050606_B.SFunction[1] / rtb_Gain1_nt;

    /* Product: '<S130>/Product' */
    rtb_Gain1_nt = fangzhen20050606_B.SFunction[0] / rtb_Gain1_nt;

    /* Sum: '<S120>/Sum' incorporates:
     *  Product: '<S120>/Product'
     *  Product: '<S120>/Product1'
     *  Product: '<S120>/Product2'
     *  Product: '<S120>/Product3'
     */
    rtb_VectorConcatenate[0] = ((rtb_Gain1_nt * rtb_Gain1_nt + rtb_Roll *
      rtb_Roll) - rtb_Product2_bk * rtb_Product2_bk) - rtb_Product1_ck *
      rtb_Product1_ck;

    /* Gain: '<S121>/Gain' incorporates:
     *  Product: '<S121>/Product2'
     *  Product: '<S121>/Product3'
     *  Sum: '<S121>/Sum'
     */
    rtb_VectorConcatenate[3] = (rtb_Product1_ck * rtb_Gain1_nt + rtb_Roll *
      rtb_Product2_bk) * fangzhen20050606_P.Gain_Gain_j5;

    /* Gain: '<S122>/Gain' incorporates:
     *  Product: '<S122>/Product1'
     *  Product: '<S122>/Product2'
     *  Sum: '<S122>/Sum'
     */
    rtb_VectorConcatenate[6] = (rtb_Roll * rtb_Product1_ck - rtb_Gain1_nt *
      rtb_Product2_bk) * fangzhen20050606_P.Gain_Gain_li;

    /* Gain: '<S123>/Gain' incorporates:
     *  Product: '<S123>/Product2'
     *  Product: '<S123>/Product3'
     *  Sum: '<S123>/Sum'
     */
    rtb_VectorConcatenate[1] = (rtb_Roll * rtb_Product2_bk - rtb_Product1_ck *
      rtb_Gain1_nt) * fangzhen20050606_P.Gain_Gain_dl;

    /* Sum: '<S124>/Sum' incorporates:
     *  Product: '<S124>/Product'
     *  Product: '<S124>/Product1'
     *  Product: '<S124>/Product2'
     *  Product: '<S124>/Product3'
     */
    rtb_VectorConcatenate[4] = ((rtb_Gain1_nt * rtb_Gain1_nt - rtb_Roll *
      rtb_Roll) + rtb_Product2_bk * rtb_Product2_bk) - rtb_Product1_ck *
      rtb_Product1_ck;

    /* Gain: '<S125>/Gain' incorporates:
     *  Product: '<S125>/Product1'
     *  Product: '<S125>/Product2'
     *  Sum: '<S125>/Sum'
     */
    rtb_VectorConcatenate[7] = (rtb_Gain1_nt * rtb_Roll + rtb_Product2_bk *
      rtb_Product1_ck) * fangzhen20050606_P.Gain_Gain_nd;

    /* Gain: '<S126>/Gain' incorporates:
     *  Product: '<S126>/Product1'
     *  Product: '<S126>/Product2'
     *  Sum: '<S126>/Sum'
     */
    rtb_VectorConcatenate[2] = (rtb_Gain1_nt * rtb_Product2_bk + rtb_Roll *
      rtb_Product1_ck) * fangzhen20050606_P.Gain_Gain_mz;

    /* Gain: '<S127>/Gain' incorporates:
     *  Product: '<S127>/Product1'
     *  Product: '<S127>/Product2'
     *  Sum: '<S127>/Sum'
     */
    rtb_VectorConcatenate[5] = (rtb_Product2_bk * rtb_Product1_ck - rtb_Gain1_nt
      * rtb_Roll) * fangzhen20050606_P.Gain_Gain_a4;

    /* Sum: '<S128>/Sum' incorporates:
     *  Product: '<S128>/Product'
     *  Product: '<S128>/Product1'
     *  Product: '<S128>/Product2'
     *  Product: '<S128>/Product3'
     */
    rtb_VectorConcatenate[8] = ((rtb_Gain1_nt * rtb_Gain1_nt - rtb_Roll *
      rtb_Roll) - rtb_Product2_bk * rtb_Product2_bk) + rtb_Product1_ck *
      rtb_Product1_ck;
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0) {
    /* Math: '<S82>/Math Function' */
    for (i = 0; i < 3; i++) {
      fangzhen20050606_B.MathFunction_k[3 * i] = rtb_VectorConcatenate[i];
      fangzhen20050606_B.MathFunction_k[1 + 3 * i] = rtb_VectorConcatenate[i + 3];
      fangzhen20050606_B.MathFunction_k[2 + 3 * i] = rtb_VectorConcatenate[i + 6];
    }

    /* End of Math: '<S82>/Math Function' */
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* RandomNumber: '<S82>/Random Number' */
    fangzhen20050606_B.RandomNumber_i1[0] = fangzhen20050606_DWork.NextOutput_n
      [0];
    fangzhen20050606_B.RandomNumber_i1[1] = fangzhen20050606_DWork.NextOutput_n
      [1];
    fangzhen20050606_B.RandomNumber_i1[2] = fangzhen20050606_DWork.NextOutput_n
      [2];
  }

  /* Sum: '<S82>/Sum2' incorporates:
   *  Constant: '<S82>/cp'
   */
  rtb_Sum2_l[0] = (rtb_Sum2_l[0] + fangzhen20050606_B.RandomNumber_i1[0]) +
    fangzhen20050606_P.cp_Value[0];
  rtb_Sum2_l[1] = (rtb_Sum2_l[1] + fangzhen20050606_B.RandomNumber_i1[1]) +
    fangzhen20050606_P.cp_Value[1];
  rtb_Add = (rtb_Sum2_l[2] + fangzhen20050606_B.RandomNumber_i1[2]) +
    fangzhen20050606_P.cp_Value[2];

  /* Product: '<S82>/Product1' */
  for (i = 0; i < 3; i++) {
    fangzhen20050606_B.Product1[i] = 0.0;
    fangzhen20050606_B.Product1[i] += fangzhen20050606_B.MathFunction_k[i] *
      rtb_Sum2_l[0];
    fangzhen20050606_B.Product1[i] += fangzhen20050606_B.MathFunction_k[i + 3] *
      rtb_Sum2_l[1];
    fangzhen20050606_B.Product1[i] += fangzhen20050606_B.MathFunction_k[i + 6] *
      rtb_Add;
  }

  /* End of Product: '<S82>/Product1' */
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* RandomNumber: '<S87>/Noign1' */
    fangzhen20050606_B.Noign1[0] = fangzhen20050606_DWork.NextOutput_nz[0];
    fangzhen20050606_B.Noign1[1] = fangzhen20050606_DWork.NextOutput_nz[1];
    fangzhen20050606_B.Noign1[2] = fangzhen20050606_DWork.NextOutput_nz[2];

    /* SignalConversion: '<S52>/TmpSignal ConversionAtTo WorkspaceInport1' */
    rtb_TmpSignalConversionAtToWo_o[0] = fangzhen20050606_B.Sum1_j[0];
    rtb_TmpSignalConversionAtToWo_o[1] = fangzhen20050606_B.Sum1_j[1];
    rtb_TmpSignalConversionAtToWo_o[2] = fangzhen20050606_B.Sum1_j[2];
    rtb_TmpSignalConversionAtToWo_o[3] = fangzhen20050606_B.Sum1_a[0];
    rtb_TmpSignalConversionAtToWo_o[4] = fangzhen20050606_B.Sum1_a[1];
    rtb_TmpSignalConversionAtToWo_o[5] = fangzhen20050606_B.Sum1_a[2];

    /* ToWorkspace: '<S52>/To Workspace' */
    rt_UpdateLogVar((LogVar *)(LogVar*)
                    (fangzhen20050606_DWork.ToWorkspace_PWORK_o.LoggedData),
                    rtb_TmpSignalConversionAtToWo_o, 0);
  }
}

/* Model update function */
void fangzhen20050606_update(void)
{
  int32_T loopVar_i;

  /* Update for Integrator: '<S9>/Integrator1' */
  fangzhen20050606_DWork.Integrator1_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for RandomNumber: '<S87>/Noign' */
    fangzhen20050606_DWork.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed[0]) * fangzhen20050606_P.Noign_StdDev[0]
      + fangzhen20050606_P.Noign_Mean[0];
    fangzhen20050606_DWork.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed[1]) * fangzhen20050606_P.Noign_StdDev[1]
      + fangzhen20050606_P.Noign_Mean[1];
    fangzhen20050606_DWork.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed[2]) * fangzhen20050606_P.Noign_StdDev[2]
      + fangzhen20050606_P.Noign_Mean[2];
  }

  /* Update for Integrator: '<S10>/Integrator' */
  fangzhen20050606_DWork.Integrator_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for RandomNumber: '<S85>/Random Number' */
    for (loopVar_i = 0; loopVar_i < 6; loopVar_i++) {
      fangzhen20050606_DWork.NextOutput_m[loopVar_i] =
        rt_nrand_Upu32_Yd_f_pw_snf(&fangzhen20050606_DWork.RandSeed_j[loopVar_i])
        * fangzhen20050606_P.RandomNumber_StdDev[loopVar_i] +
        fangzhen20050606_P.RandomNumber_Mean[loopVar_i];
    }

    /* End of Update for RandomNumber: '<S85>/Random Number' */

    /* Update for RandomNumber: '<S84>/Random Number' */
    fangzhen20050606_DWork.NextOutput_p[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i[0]) *
      fangzhen20050606_P.RandomNumber_StdDev_n[0] +
      fangzhen20050606_P.RandomNumber_Mean_k[0];
    fangzhen20050606_DWork.NextOutput_p[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i[1]) *
      fangzhen20050606_P.RandomNumber_StdDev_n[1] +
      fangzhen20050606_P.RandomNumber_Mean_k[1];
    fangzhen20050606_DWork.NextOutput_p[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i[2]) *
      fangzhen20050606_P.RandomNumber_StdDev_n[2] +
      fangzhen20050606_P.RandomNumber_Mean_k[2];
  }

  /* Level2 S-Function Block: '<S83>/S-Function' (CIQW_kf_C) */
  {
    SimStruct *rts = fangzhen20050606_M->childSfunctions[0];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S86>/S-Function' (CIRV_kf_C) */
  {
    SimStruct *rts = fangzhen20050606_M->childSfunctions[1];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S24>/Unit delay' */
    fangzhen20050606_DWork.Unitdelay_DSTATE[0] = fangzhen20050606_B.JW[0];
    fangzhen20050606_DWork.Unitdelay_DSTATE[1] = fangzhen20050606_B.JW[1];
    fangzhen20050606_DWork.Unitdelay_DSTATE[2] = fangzhen20050606_B.JW[2];
    fangzhen20050606_DWork.Unitdelay_DSTATE[3] = fangzhen20050606_B.JW[3];

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[0] +=
      fangzhen20050606_P.DiscreteTimeIntegrator_gainval *
      fangzhen20050606_B.Sum_p[0];
    fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[1] +=
      fangzhen20050606_P.DiscreteTimeIntegrator_gainval *
      fangzhen20050606_B.Sum_p[1];
    fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[2] +=
      fangzhen20050606_P.DiscreteTimeIntegrator_gainval *
      fangzhen20050606_B.Sum_p[2];
    fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[3] +=
      fangzhen20050606_P.DiscreteTimeIntegrator_gainval *
      fangzhen20050606_B.Sum_p[3];
    if (fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[0] >=
        fangzhen20050606_P.DiscreteTimeIntegrator_UpperSat[0]) {
      fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[0] =
        fangzhen20050606_P.DiscreteTimeIntegrator_UpperSat[0];
    } else {
      if (fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[0] <=
          fangzhen20050606_P.DiscreteTimeIntegrator_LowerSat[0]) {
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[0] =
          fangzhen20050606_P.DiscreteTimeIntegrator_LowerSat[0];
      }
    }

    if (fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[1] >=
        fangzhen20050606_P.DiscreteTimeIntegrator_UpperSat[1]) {
      fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[1] =
        fangzhen20050606_P.DiscreteTimeIntegrator_UpperSat[1];
    } else {
      if (fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[1] <=
          fangzhen20050606_P.DiscreteTimeIntegrator_LowerSat[1]) {
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[1] =
          fangzhen20050606_P.DiscreteTimeIntegrator_LowerSat[1];
      }
    }

    if (fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[2] >=
        fangzhen20050606_P.DiscreteTimeIntegrator_UpperSat[2]) {
      fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[2] =
        fangzhen20050606_P.DiscreteTimeIntegrator_UpperSat[2];
    } else {
      if (fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[2] <=
          fangzhen20050606_P.DiscreteTimeIntegrator_LowerSat[2]) {
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[2] =
          fangzhen20050606_P.DiscreteTimeIntegrator_LowerSat[2];
      }
    }

    if (fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[3] >=
        fangzhen20050606_P.DiscreteTimeIntegrator_UpperSat[3]) {
      fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[3] =
        fangzhen20050606_P.DiscreteTimeIntegrator_UpperSat[3];
    } else {
      if (fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[3] <=
          fangzhen20050606_P.DiscreteTimeIntegrator_LowerSat[3]) {
        fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[3] =
          fangzhen20050606_P.DiscreteTimeIntegrator_LowerSat[3];
      }
    }

    /* End of Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */

    /* Update for RandomNumber: '<S25>/TWi' */
    fangzhen20050606_DWork.NextOutput_c[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_f[0]) * fangzhen20050606_P.TWi_StdDev[0]
      + fangzhen20050606_P.TWi_Mean[0];
    fangzhen20050606_DWork.NextOutput_c[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_f[1]) * fangzhen20050606_P.TWi_StdDev[1]
      + fangzhen20050606_P.TWi_Mean[1];
    fangzhen20050606_DWork.NextOutput_c[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_f[2]) * fangzhen20050606_P.TWi_StdDev[2]
      + fangzhen20050606_P.TWi_Mean[2];
    fangzhen20050606_DWork.NextOutput_c[3] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_f[3]) * fangzhen20050606_P.TWi_StdDev[3]
      + fangzhen20050606_P.TWi_Mean[3];
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */
    fangzhen20050606_DWork.DiscreteTimeIntegrator_SYSTEM_E = 0U;
    fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[0] =
      fangzhen20050606_B.DiscreteTimeIntegrator[0];
    fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[1] =
      fangzhen20050606_B.DiscreteTimeIntegrator[1];
    fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[2] =
      fangzhen20050606_B.DiscreteTimeIntegrator[2];
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for RandomNumber: '<S82>/Random Number' */
    fangzhen20050606_DWork.NextOutput_n[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_g[0]) *
      fangzhen20050606_P.RandomNumber_StdDev_k[0] +
      fangzhen20050606_P.RandomNumber_Mean_a[0];
    fangzhen20050606_DWork.NextOutput_n[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_g[1]) *
      fangzhen20050606_P.RandomNumber_StdDev_k[1] +
      fangzhen20050606_P.RandomNumber_Mean_a[1];
    fangzhen20050606_DWork.NextOutput_n[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_g[2]) *
      fangzhen20050606_P.RandomNumber_StdDev_k[2] +
      fangzhen20050606_P.RandomNumber_Mean_a[2];

    /* Update for RandomNumber: '<S87>/Noign1' */
    fangzhen20050606_DWork.NextOutput_nz[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i2[0]) *
      fangzhen20050606_P.Noign1_StdDev[0] + fangzhen20050606_P.Noign1_Mean[0];
    fangzhen20050606_DWork.NextOutput_nz[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i2[1]) *
      fangzhen20050606_P.Noign1_StdDev[1] + fangzhen20050606_P.Noign1_Mean[1];
    fangzhen20050606_DWork.NextOutput_nz[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i2[2]) *
      fangzhen20050606_P.Noign1_StdDev[2] + fangzhen20050606_P.Noign1_Mean[2];
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M)) {
    rt_ertODEUpdateContinuousStates(&fangzhen20050606_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++fangzhen20050606_M->Timing.clockTick0)) {
    ++fangzhen20050606_M->Timing.clockTickH0;
  }

  fangzhen20050606_M->Timing.t[0] = rtsiGetSolverStopTime
    (&fangzhen20050606_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++fangzhen20050606_M->Timing.clockTick1)) {
      ++fangzhen20050606_M->Timing.clockTickH1;
    }

    fangzhen20050606_M->Timing.t[1] = fangzhen20050606_M->Timing.clockTick1 *
      fangzhen20050606_M->Timing.stepSize1 +
      fangzhen20050606_M->Timing.clockTickH1 *
      fangzhen20050606_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++fangzhen20050606_M->Timing.clockTick2)) {
      ++fangzhen20050606_M->Timing.clockTickH2;
    }

    fangzhen20050606_M->Timing.t[2] = fangzhen20050606_M->Timing.clockTick2 *
      fangzhen20050606_M->Timing.stepSize2 +
      fangzhen20050606_M->Timing.clockTickH2 *
      fangzhen20050606_M->Timing.stepSize2 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [0.5s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++fangzhen20050606_M->Timing.clockTick3)) {
      ++fangzhen20050606_M->Timing.clockTickH3;
    }

    fangzhen20050606_M->Timing.t[3] = fangzhen20050606_M->Timing.clockTick3 *
      fangzhen20050606_M->Timing.stepSize3 +
      fangzhen20050606_M->Timing.clockTickH3 *
      fangzhen20050606_M->Timing.stepSize3 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(fangzhen20050606_M) &&
      fangzhen20050606_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update absolute timer for sample time: [2.0s, 0.0s] */
    /* The "clockTick4" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick4"
     * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick4 and the high bits
     * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++fangzhen20050606_M->Timing.clockTick4)) {
      ++fangzhen20050606_M->Timing.clockTickH4;
    }

    fangzhen20050606_M->Timing.t[4] = fangzhen20050606_M->Timing.clockTick4 *
      fangzhen20050606_M->Timing.stepSize4 +
      fangzhen20050606_M->Timing.clockTickH4 *
      fangzhen20050606_M->Timing.stepSize4 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void fangzhen20050606_derivatives(void)
{
  StateDerivatives_fangzhen20050606 *_rtXdot;
  _rtXdot = ((StateDerivatives_fangzhen20050606 *)
             fangzhen20050606_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  {
    ((StateDerivatives_fangzhen20050606 *) fangzhen20050606_M->ModelData.derivs
      )->Integrator1_CSTATE[0] = fangzhen20050606_B.Sum1_p[0];
    ((StateDerivatives_fangzhen20050606 *) fangzhen20050606_M->ModelData.derivs
      )->Integrator1_CSTATE[1] = fangzhen20050606_B.Sum1_p[1];
    ((StateDerivatives_fangzhen20050606 *) fangzhen20050606_M->ModelData.derivs
      )->Integrator1_CSTATE[2] = fangzhen20050606_B.Sum1_p[2];
  }

  /* Derivatives for Integrator: '<S87>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = fangzhen20050606_B.Noign1[0];
  _rtXdot->Integrator_CSTATE[1] = fangzhen20050606_B.Noign1[1];
  _rtXdot->Integrator_CSTATE[2] = fangzhen20050606_B.Noign1[2];

  /* Derivatives for Integrator: '<S10>/Integrator' */
  {
    ((StateDerivatives_fangzhen20050606 *) fangzhen20050606_M->ModelData.derivs
      )->Integrator_CSTATE_a[0] = fangzhen20050606_B.Gain;
    ((StateDerivatives_fangzhen20050606 *) fangzhen20050606_M->ModelData.derivs
      )->Integrator_CSTATE_a[1] = fangzhen20050606_B.Gain1_a[0];
    ((StateDerivatives_fangzhen20050606 *) fangzhen20050606_M->ModelData.derivs
      )->Integrator_CSTATE_a[2] = fangzhen20050606_B.Gain1_a[1];
    ((StateDerivatives_fangzhen20050606 *) fangzhen20050606_M->ModelData.derivs
      )->Integrator_CSTATE_a[3] = fangzhen20050606_B.Gain1_a[2];
  }

  /* Derivatives for Integrator: '<S36>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[0] = fangzhen20050606_B.Integrator_n[0];
  _rtXdot->Integrator1_CSTATE_g[1] = fangzhen20050606_B.Integrator_n[1];
  _rtXdot->Integrator1_CSTATE_g[2] = fangzhen20050606_B.Integrator_n[2];

  /* Derivatives for Integrator: '<S82>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_l[0] = fangzhen20050606_B.Integrator[0];
  _rtXdot->Integrator1_CSTATE_l[1] = fangzhen20050606_B.Integrator[1];
  _rtXdot->Integrator1_CSTATE_l[2] = fangzhen20050606_B.Integrator[2];

  /* Derivatives for Integrator: '<S82>/Integrator' */
  _rtXdot->Integrator_CSTATE_d[0] = fangzhen20050606_B.Product1[0];
  _rtXdot->Integrator_CSTATE_d[1] = fangzhen20050606_B.Product1[1];
  _rtXdot->Integrator_CSTATE_d[2] = fangzhen20050606_B.Product1[2];

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE_do[0] = fangzhen20050606_B.Sum_b[0];
  _rtXdot->Integrator_CSTATE_do[1] = fangzhen20050606_B.Sum_b[1];
  _rtXdot->Integrator_CSTATE_do[2] = fangzhen20050606_B.Sum_b[2];

  /* Derivatives for Integrator: '<S36>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = fangzhen20050606_B.Sum3;
}

/* Model initialize function */
void fangzhen20050606_initialize(void)
{
  {
    int32_T loopVar_i;
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* Start for Constant: '<S9>/Constant1' */
    fangzhen20050606_B.Constant1[0] = fangzhen20050606_P.Constant1_Value_k[0];
    fangzhen20050606_B.Constant1[1] = fangzhen20050606_P.Constant1_Value_k[1];
    fangzhen20050606_B.Constant1[2] = fangzhen20050606_P.Constant1_Value_k[2];

    /* Start for RandomNumber: '<S87>/Noign' */
    tmp = floor(fangzhen20050606_P.Noign_Seed[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed[0] = tseed;
    fangzhen20050606_DWork.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed[0]) * fangzhen20050606_P.Noign_StdDev[0]
      + fangzhen20050606_P.Noign_Mean[0];
    tmp = floor(fangzhen20050606_P.Noign_Seed[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed[1] = tseed;
    fangzhen20050606_DWork.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed[1]) * fangzhen20050606_P.Noign_StdDev[1]
      + fangzhen20050606_P.Noign_Mean[1];
    tmp = floor(fangzhen20050606_P.Noign_Seed[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed[2] = tseed;
    fangzhen20050606_DWork.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed[2]) * fangzhen20050606_P.Noign_StdDev[2]
      + fangzhen20050606_P.Noign_Mean[2];

    /* End of Start for RandomNumber: '<S87>/Noign' */

    /* Start for Constant: '<S10>/Constant3' */
    fangzhen20050606_B.Constant3[0] = fangzhen20050606_P.Constant3_Value[0];
    fangzhen20050606_B.Constant3[1] = fangzhen20050606_P.Constant3_Value[1];
    fangzhen20050606_B.Constant3[2] = fangzhen20050606_P.Constant3_Value[2];
    fangzhen20050606_B.Constant3[3] = fangzhen20050606_P.Constant3_Value[3];

    /* Start for RandomNumber: '<S85>/Random Number' */
    for (loopVar_i = 0; loopVar_i < 6; loopVar_i++) {
      tmp = floor(fangzhen20050606_P.RandomNumber_Seed[loopVar_i]);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 4.294967296E+9);
      }

      tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
      r = (int32_T)(tseed >> 16U);
      t = (int32_T)(tseed & 32768U);
      tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) +
               (uint32_T)t) + (uint32_T)r;
      if (tseed < 1U) {
        tseed = 1144108930U;
      } else {
        if (tseed > 2147483646U) {
          tseed = 2147483646U;
        }
      }

      fangzhen20050606_DWork.RandSeed_j[loopVar_i] = tseed;
      fangzhen20050606_DWork.NextOutput_m[loopVar_i] =
        rt_nrand_Upu32_Yd_f_pw_snf(&fangzhen20050606_DWork.RandSeed_j[loopVar_i])
        * fangzhen20050606_P.RandomNumber_StdDev[loopVar_i] +
        fangzhen20050606_P.RandomNumber_Mean[loopVar_i];
    }

    /* End of Start for RandomNumber: '<S85>/Random Number' */

    /* Start for RandomNumber: '<S84>/Random Number' */
    tmp = floor(fangzhen20050606_P.RandomNumber_Seed_k[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_i[0] = tseed;
    fangzhen20050606_DWork.NextOutput_p[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i[0]) *
      fangzhen20050606_P.RandomNumber_StdDev_n[0] +
      fangzhen20050606_P.RandomNumber_Mean_k[0];
    tmp = floor(fangzhen20050606_P.RandomNumber_Seed_k[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_i[1] = tseed;
    fangzhen20050606_DWork.NextOutput_p[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i[1]) *
      fangzhen20050606_P.RandomNumber_StdDev_n[1] +
      fangzhen20050606_P.RandomNumber_Mean_k[1];
    tmp = floor(fangzhen20050606_P.RandomNumber_Seed_k[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_i[2] = tseed;
    fangzhen20050606_DWork.NextOutput_p[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i[2]) *
      fangzhen20050606_P.RandomNumber_StdDev_n[2] +
      fangzhen20050606_P.RandomNumber_Mean_k[2];

    /* End of Start for RandomNumber: '<S84>/Random Number' */

    /* Start for If: '<S92>/If' */
    fangzhen20050606_DWork.If_ActiveSubsystem = -1;

    /* Start for IfAction SubSystem: '<S92>/Negative Trace' */
    /* Start for If: '<S95>/Find Maximum Diagonal Value' */
    fangzhen20050606_DWork.FindMaximumDiagonalValue_Active = -1;

    /* End of Start for SubSystem: '<S92>/Negative Trace' */
    /* Start for ToWorkspace: '<Root>/To Workspace' */
    {
      int_T dimensions[1] = { 4 };

      fangzhen20050606_DWork.ToWorkspace_PWORK.LoggedData = rt_CreateLogVar(
        fangzhen20050606_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(fangzhen20050606_M),
        fangzhen20050606_M->Timing.stepSize0,
        (&rtmGetErrorStatus(fangzhen20050606_M)),
        "landRV1",
        SS_DOUBLE,
        0,
        0,
        0,
        4,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        (NULL),
        0,
        1,
        0.05,
        1);
      if (fangzhen20050606_DWork.ToWorkspace_PWORK.LoggedData == (NULL))
        return;
    }

    /* Start for ToWorkspace: '<S1>/To Workspace' */
    {
      int_T dimensions[1] = { 7 };

      fangzhen20050606_DWork.ToWorkspace_PWORK_c.LoggedData = rt_CreateLogVar(
        fangzhen20050606_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(fangzhen20050606_M),
        fangzhen20050606_M->Timing.stepSize0,
        (&rtmGetErrorStatus(fangzhen20050606_M)),
        "landRV",
        SS_DOUBLE,
        0,
        0,
        0,
        7,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        (NULL),
        0,
        1,
        0.05,
        1);
      if (fangzhen20050606_DWork.ToWorkspace_PWORK_c.LoggedData == (NULL))
        return;
    }

    /* Start for ToWorkspace: '<S1>/To Workspace1' */
    {
      int_T dimensions[1] = { 13 };

      fangzhen20050606_DWork.ToWorkspace1_PWORK.LoggedData = rt_CreateLogVar(
        fangzhen20050606_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(fangzhen20050606_M),
        fangzhen20050606_M->Timing.stepSize0,
        (&rtmGetErrorStatus(fangzhen20050606_M)),
        "simout1",
        SS_DOUBLE,
        0,
        0,
        0,
        13,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        (NULL),
        0,
        1,
        0.05,
        1);
      if (fangzhen20050606_DWork.ToWorkspace1_PWORK.LoggedData == (NULL))
        return;
    }

    /* Start for RandomNumber: '<S25>/TWi' */
    tmp = floor(fangzhen20050606_P.TWi_Seed[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_f[0] = tseed;
    fangzhen20050606_DWork.NextOutput_c[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_f[0]) * fangzhen20050606_P.TWi_StdDev[0]
      + fangzhen20050606_P.TWi_Mean[0];
    tmp = floor(fangzhen20050606_P.TWi_Seed[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_f[1] = tseed;
    fangzhen20050606_DWork.NextOutput_c[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_f[1]) * fangzhen20050606_P.TWi_StdDev[1]
      + fangzhen20050606_P.TWi_Mean[1];
    tmp = floor(fangzhen20050606_P.TWi_Seed[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_f[2] = tseed;
    fangzhen20050606_DWork.NextOutput_c[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_f[2]) * fangzhen20050606_P.TWi_StdDev[2]
      + fangzhen20050606_P.TWi_Mean[2];
    tmp = floor(fangzhen20050606_P.TWi_Seed[3]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_f[3] = tseed;
    fangzhen20050606_DWork.NextOutput_c[3] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_f[3]) * fangzhen20050606_P.TWi_StdDev[3]
      + fangzhen20050606_P.TWi_Mean[3];

    /* End of Start for RandomNumber: '<S25>/TWi' */
    /* Start for Constant: '<S50>/Constant1' */
    fangzhen20050606_B.Constant1_e[0] = fangzhen20050606_P.Constant1_Value_j5[0];
    fangzhen20050606_B.Constant1_e[1] = fangzhen20050606_P.Constant1_Value_j5[1];
    fangzhen20050606_B.Constant1_e[2] = fangzhen20050606_P.Constant1_Value_j5[2];

    /* Start for ToWorkspace: '<S2>/To Workspace' */
    {
      int_T dimensions[1] = { 13 };

      fangzhen20050606_DWork.ToWorkspace_PWORK_i.LoggedData = rt_CreateLogVar(
        fangzhen20050606_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(fangzhen20050606_M),
        fangzhen20050606_M->Timing.stepSize0,
        (&rtmGetErrorStatus(fangzhen20050606_M)),
        "simout",
        SS_DOUBLE,
        0,
        0,
        0,
        13,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        (NULL),
        0,
        1,
        0.05,
        1);
      if (fangzhen20050606_DWork.ToWorkspace_PWORK_i.LoggedData == (NULL))
        return;
    }

    /* Start for ToWorkspace: '<S2>/To Workspace1' */
    {
      int_T dimensions[1] = { 6 };

      fangzhen20050606_DWork.ToWorkspace1_PWORK_j.LoggedData = rt_CreateLogVar(
        fangzhen20050606_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(fangzhen20050606_M),
        fangzhen20050606_M->Timing.stepSize0,
        (&rtmGetErrorStatus(fangzhen20050606_M)),
        "landRV2",
        SS_DOUBLE,
        0,
        0,
        0,
        6,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        (NULL),
        0,
        1,
        0.05,
        1);
      if (fangzhen20050606_DWork.ToWorkspace1_PWORK_j.LoggedData == (NULL))
        return;
    }

    /* Start for ToWorkspace: '<S51>/To Workspace' */
    {
      int_T dimensions[1] = { 3 };

      fangzhen20050606_DWork.ToWorkspace_PWORK_m.LoggedData = rt_CreateLogVar(
        fangzhen20050606_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(fangzhen20050606_M),
        fangzhen20050606_M->Timing.stepSize0,
        (&rtmGetErrorStatus(fangzhen20050606_M)),
        "simout2",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        (NULL),
        0,
        1,
        0.05,
        1);
      if (fangzhen20050606_DWork.ToWorkspace_PWORK_m.LoggedData == (NULL))
        return;
    }

    /* Start for ToWorkspace: '<S51>/To Workspace1' */
    {
      int_T dimensions[1] = { 3 };

      fangzhen20050606_DWork.ToWorkspace1_PWORK_o.LoggedData = rt_CreateLogVar(
        fangzhen20050606_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(fangzhen20050606_M),
        fangzhen20050606_M->Timing.stepSize0,
        (&rtmGetErrorStatus(fangzhen20050606_M)),
        "simout3",
        SS_DOUBLE,
        0,
        0,
        0,
        3,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        (NULL),
        0,
        1,
        0.05,
        1);
      if (fangzhen20050606_DWork.ToWorkspace1_PWORK_o.LoggedData == (NULL))
        return;
    }

    /* Start for RandomNumber: '<S82>/Random Number' */
    tmp = floor(fangzhen20050606_P.RandomNumber_Seed_c[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_g[0] = tseed;
    fangzhen20050606_DWork.NextOutput_n[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_g[0]) *
      fangzhen20050606_P.RandomNumber_StdDev_k[0] +
      fangzhen20050606_P.RandomNumber_Mean_a[0];
    tmp = floor(fangzhen20050606_P.RandomNumber_Seed_c[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_g[1] = tseed;
    fangzhen20050606_DWork.NextOutput_n[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_g[1]) *
      fangzhen20050606_P.RandomNumber_StdDev_k[1] +
      fangzhen20050606_P.RandomNumber_Mean_a[1];
    tmp = floor(fangzhen20050606_P.RandomNumber_Seed_c[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_g[2] = tseed;
    fangzhen20050606_DWork.NextOutput_n[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_g[2]) *
      fangzhen20050606_P.RandomNumber_StdDev_k[2] +
      fangzhen20050606_P.RandomNumber_Mean_a[2];

    /* End of Start for RandomNumber: '<S82>/Random Number' */
    /* Start for RandomNumber: '<S87>/Noign1' */
    tmp = floor(fangzhen20050606_P.Noign1_Seed[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_i2[0] = tseed;
    fangzhen20050606_DWork.NextOutput_nz[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i2[0]) *
      fangzhen20050606_P.Noign1_StdDev[0] + fangzhen20050606_P.Noign1_Mean[0];
    tmp = floor(fangzhen20050606_P.Noign1_Seed[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_i2[1] = tseed;
    fangzhen20050606_DWork.NextOutput_nz[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i2[1]) *
      fangzhen20050606_P.Noign1_StdDev[1] + fangzhen20050606_P.Noign1_Mean[1];
    tmp = floor(fangzhen20050606_P.Noign1_Seed[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    fangzhen20050606_DWork.RandSeed_i2[2] = tseed;
    fangzhen20050606_DWork.NextOutput_nz[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&fangzhen20050606_DWork.RandSeed_i2[2]) *
      fangzhen20050606_P.Noign1_StdDev[2] + fangzhen20050606_P.Noign1_Mean[2];

    /* End of Start for RandomNumber: '<S87>/Noign1' */
    /* Start for ToWorkspace: '<S52>/To Workspace' */
    {
      int_T dimensions[1] = { 6 };

      fangzhen20050606_DWork.ToWorkspace_PWORK_o.LoggedData = rt_CreateLogVar(
        fangzhen20050606_M->rtwLogInfo,
        0.0,
        rtmGetTFinal(fangzhen20050606_M),
        fangzhen20050606_M->Timing.stepSize0,
        (&rtmGetErrorStatus(fangzhen20050606_M)),
        "R1",
        SS_DOUBLE,
        0,
        0,
        0,
        6,
        1,
        dimensions,
        NO_LOGVALDIMS,
        (NULL),
        (NULL),
        0,
        1,
        0.05,
        1);
      if (fangzhen20050606_DWork.ToWorkspace_PWORK_o.LoggedData == (NULL))
        return;
    }
  }

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  if (rtmIsFirstInitCond(fangzhen20050606_M)) {
    fangzhen20050606_X.Integrator1_CSTATE[0] = 0.064877378955133222;
    fangzhen20050606_X.Integrator1_CSTATE[1] = 0.055780722893738775;
    fangzhen20050606_X.Integrator1_CSTATE[2] = 0.07467914803433337;
  }

  fangzhen20050606_DWork.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S87>/Integrator' */
  fangzhen20050606_X.Integrator_CSTATE[0] = fangzhen20050606_P.Integrator_IC[0];
  fangzhen20050606_X.Integrator_CSTATE[1] = fangzhen20050606_P.Integrator_IC[1];
  fangzhen20050606_X.Integrator_CSTATE[2] = fangzhen20050606_P.Integrator_IC[2];

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  if (rtmIsFirstInitCond(fangzhen20050606_M)) {
    fangzhen20050606_X.Integrator_CSTATE_a[0] = 1.0;
    fangzhen20050606_X.Integrator_CSTATE_a[1] = 0.0;
    fangzhen20050606_X.Integrator_CSTATE_a[2] = 0.0;
    fangzhen20050606_X.Integrator_CSTATE_a[3] = 0.0;
  }

  fangzhen20050606_DWork.Integrator_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S36>/Integrator1' */
  fangzhen20050606_X.Integrator1_CSTATE_g[0] =
    fangzhen20050606_P.Integrator1_IC[0];
  fangzhen20050606_X.Integrator1_CSTATE_g[1] =
    fangzhen20050606_P.Integrator1_IC[1];
  fangzhen20050606_X.Integrator1_CSTATE_g[2] =
    fangzhen20050606_P.Integrator1_IC[2];

  /* InitializeConditions for Merge: '<S92>/Merge' */
  if (rtmIsFirstInitCond(fangzhen20050606_M)) {
    fangzhen20050606_B.Merge[0] = fangzhen20050606_P.Merge_InitialOutput[0];
    fangzhen20050606_B.Merge[1] = fangzhen20050606_P.Merge_InitialOutput[1];
    fangzhen20050606_B.Merge[2] = fangzhen20050606_P.Merge_InitialOutput[2];
    fangzhen20050606_B.Merge[3] = fangzhen20050606_P.Merge_InitialOutput[3];
  }

  /* End of InitializeConditions for Merge: '<S92>/Merge' */
  /* Level2 S-Function Block: '<S83>/S-Function' (CIQW_kf_C) */
  {
    SimStruct *rts = fangzhen20050606_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S82>/Integrator1' */
  fangzhen20050606_X.Integrator1_CSTATE_l[0] =
    fangzhen20050606_P.Integrator1_IC_m[0];
  fangzhen20050606_X.Integrator1_CSTATE_l[1] =
    fangzhen20050606_P.Integrator1_IC_m[1];
  fangzhen20050606_X.Integrator1_CSTATE_l[2] =
    fangzhen20050606_P.Integrator1_IC_m[2];

  /* Level2 S-Function Block: '<S86>/S-Function' (CIRV_kf_C) */
  {
    SimStruct *rts = fangzhen20050606_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S82>/Integrator' */
  fangzhen20050606_X.Integrator_CSTATE_d[0] =
    fangzhen20050606_P.Integrator_IC_k[0];
  fangzhen20050606_X.Integrator_CSTATE_d[1] =
    fangzhen20050606_P.Integrator_IC_k[1];
  fangzhen20050606_X.Integrator_CSTATE_d[2] =
    fangzhen20050606_P.Integrator_IC_k[2];

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  fangzhen20050606_X.Integrator_CSTATE_do[0] =
    fangzhen20050606_P.Integrator_IC_e[0];
  fangzhen20050606_X.Integrator_CSTATE_do[1] =
    fangzhen20050606_P.Integrator_IC_e[1];
  fangzhen20050606_X.Integrator_CSTATE_do[2] =
    fangzhen20050606_P.Integrator_IC_e[2];

  /* InitializeConditions for UnitDelay: '<S24>/Unit delay' */
  fangzhen20050606_DWork.Unitdelay_DSTATE[0] =
    fangzhen20050606_P.Unitdelay_InitialCondition[0];
  fangzhen20050606_DWork.Unitdelay_DSTATE[1] =
    fangzhen20050606_P.Unitdelay_InitialCondition[1];
  fangzhen20050606_DWork.Unitdelay_DSTATE[2] =
    fangzhen20050606_P.Unitdelay_InitialCondition[2];
  fangzhen20050606_DWork.Unitdelay_DSTATE[3] =
    fangzhen20050606_P.Unitdelay_InitialCondition[3];

  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[0] =
    fangzhen20050606_P.DiscreteTimeIntegrator_IC[0];
  fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[1] =
    fangzhen20050606_P.DiscreteTimeIntegrator_IC[1];
  fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[2] =
    fangzhen20050606_P.DiscreteTimeIntegrator_IC[2];
  fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE[3] =
    fangzhen20050606_P.DiscreteTimeIntegrator_IC[3];

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */
  fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[0] =
    fangzhen20050606_B.Constant1_e[0];
  fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[1] =
    fangzhen20050606_B.Constant1_e[1];
  fangzhen20050606_DWork.DiscreteTimeIntegrator_DSTATE_i[2] =
    fangzhen20050606_B.Constant1_e[2];

  /* InitializeConditions for Integrator: '<S36>/Integrator2' */
  fangzhen20050606_X.Integrator2_CSTATE = fangzhen20050606_P.Integrator2_IC;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(fangzhen20050606_M)) {
    rtmSetFirstInitCond(fangzhen20050606_M, 0);
  }

  /* Enable for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */
  fangzhen20050606_DWork.DiscreteTimeIntegrator_SYSTEM_E = 1U;
}

/* Model terminate function */
void fangzhen20050606_terminate(void)
{
  /* Level2 S-Function Block: '<S83>/S-Function' (CIQW_kf_C) */
  {
    SimStruct *rts = fangzhen20050606_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S86>/S-Function' (CIRV_kf_C) */
  {
    SimStruct *rts = fangzhen20050606_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  fangzhen20050606_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  fangzhen20050606_update();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  fangzhen20050606_initialize();
}

void MdlTerminate(void)
{
  fangzhen20050606_terminate();
}

RT_MODEL_fangzhen20050606 *fangzhen20050606(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)fangzhen20050606_M, 0,
                sizeof(RT_MODEL_fangzhen20050606));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&fangzhen20050606_M->solverInfo,
                          &fangzhen20050606_M->Timing.simTimeStep);
    rtsiSetTPtr(&fangzhen20050606_M->solverInfo, &rtmGetTPtr(fangzhen20050606_M));
    rtsiSetStepSizePtr(&fangzhen20050606_M->solverInfo,
                       &fangzhen20050606_M->Timing.stepSize0);
    rtsiSetdXPtr(&fangzhen20050606_M->solverInfo,
                 &fangzhen20050606_M->ModelData.derivs);
    rtsiSetContStatesPtr(&fangzhen20050606_M->solverInfo,
                         &fangzhen20050606_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&fangzhen20050606_M->solverInfo,
      &fangzhen20050606_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&fangzhen20050606_M->solverInfo, (&rtmGetErrorStatus
      (fangzhen20050606_M)));
    rtsiSetRTModelPtr(&fangzhen20050606_M->solverInfo, fangzhen20050606_M);
  }

  rtsiSetSimTimeStep(&fangzhen20050606_M->solverInfo, MAJOR_TIME_STEP);
  fangzhen20050606_M->ModelData.intgData.y = fangzhen20050606_M->ModelData.odeY;
  fangzhen20050606_M->ModelData.intgData.f[0] =
    fangzhen20050606_M->ModelData.odeF[0];
  fangzhen20050606_M->ModelData.intgData.f[1] =
    fangzhen20050606_M->ModelData.odeF[1];
  fangzhen20050606_M->ModelData.intgData.f[2] =
    fangzhen20050606_M->ModelData.odeF[2];
  fangzhen20050606_M->ModelData.intgData.f[3] =
    fangzhen20050606_M->ModelData.odeF[3];
  fangzhen20050606_M->ModelData.contStates = ((real_T *) &fangzhen20050606_X);
  rtsiSetSolverData(&fangzhen20050606_M->solverInfo, (void *)
                    &fangzhen20050606_M->ModelData.intgData);
  rtsiSetSolverName(&fangzhen20050606_M->solverInfo,"ode4");
  fangzhen20050606_M->solverInfoPtr = (&fangzhen20050606_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = fangzhen20050606_M->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlTsMap[i] = i;
    }

    fangzhen20050606_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    fangzhen20050606_M->Timing.sampleTimes =
      (&fangzhen20050606_M->Timing.sampleTimesArray[0]);
    fangzhen20050606_M->Timing.offsetTimes =
      (&fangzhen20050606_M->Timing.offsetTimesArray[0]);

    /* task periods */
    fangzhen20050606_M->Timing.sampleTimes[0] = (0.0);
    fangzhen20050606_M->Timing.sampleTimes[1] = (0.05);
    fangzhen20050606_M->Timing.sampleTimes[2] = (0.2);
    fangzhen20050606_M->Timing.sampleTimes[3] = (0.5);
    fangzhen20050606_M->Timing.sampleTimes[4] = (2.0);

    /* task offsets */
    fangzhen20050606_M->Timing.offsetTimes[0] = (0.0);
    fangzhen20050606_M->Timing.offsetTimes[1] = (0.0);
    fangzhen20050606_M->Timing.offsetTimes[2] = (0.0);
    fangzhen20050606_M->Timing.offsetTimes[3] = (0.0);
    fangzhen20050606_M->Timing.offsetTimes[4] = (0.0);
  }

  rtmSetTPtr(fangzhen20050606_M, &fangzhen20050606_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = fangzhen20050606_M->Timing.sampleHitArray;
    int_T i;
    for (i = 0; i < 5; i++) {
      mdlSampleHits[i] = 1;
    }

    fangzhen20050606_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(fangzhen20050606_M, 1200.0);
  fangzhen20050606_M->Timing.stepSize0 = 0.05;
  fangzhen20050606_M->Timing.stepSize1 = 0.05;
  fangzhen20050606_M->Timing.stepSize2 = 0.2;
  fangzhen20050606_M->Timing.stepSize3 = 0.5;
  fangzhen20050606_M->Timing.stepSize4 = 2.0;
  rtmSetFirstInitCond(fangzhen20050606_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    fangzhen20050606_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(fangzhen20050606_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(fangzhen20050606_M->rtwLogInfo, (NULL));
    rtliSetLogT(fangzhen20050606_M->rtwLogInfo, "tout");
    rtliSetLogX(fangzhen20050606_M->rtwLogInfo, "");
    rtliSetLogXFinal(fangzhen20050606_M->rtwLogInfo, "");
    rtliSetSigLog(fangzhen20050606_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(fangzhen20050606_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(fangzhen20050606_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(fangzhen20050606_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(fangzhen20050606_M->rtwLogInfo, 1);
    rtliSetLogY(fangzhen20050606_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(fangzhen20050606_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(fangzhen20050606_M->rtwLogInfo, (NULL));
  }

  fangzhen20050606_M->solverInfoPtr = (&fangzhen20050606_M->solverInfo);
  fangzhen20050606_M->Timing.stepSize = (0.05);
  rtsiSetFixedStepSize(&fangzhen20050606_M->solverInfo, 0.05);
  rtsiSetSolverMode(&fangzhen20050606_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  fangzhen20050606_M->ModelData.blockIO = ((void *) &fangzhen20050606_B);
  (void) memset(((void *) &fangzhen20050606_B), 0,
                sizeof(BlockIO_fangzhen20050606));

  /* parameters */
  fangzhen20050606_M->ModelData.defaultParam = ((real_T *)&fangzhen20050606_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &fangzhen20050606_X;
    fangzhen20050606_M->ModelData.contStates = (x);
    (void) memset((void *)&fangzhen20050606_X, 0,
                  sizeof(ContinuousStates_fangzhen20050606));
  }

  /* states (dwork) */
  fangzhen20050606_M->Work.dwork = ((void *) &fangzhen20050606_DWork);
  (void) memset((void *)&fangzhen20050606_DWork, 0,
                sizeof(D_Work_fangzhen20050606));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &fangzhen20050606_M->NonInlinedSFcns.sfcnInfo;
    fangzhen20050606_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(fangzhen20050606_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &fangzhen20050606_M->Sizes.numSampTimes);
    fangzhen20050606_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (fangzhen20050606_M)[0]);
    fangzhen20050606_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (fangzhen20050606_M)[1]);
    fangzhen20050606_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr
      (fangzhen20050606_M)[2]);
    fangzhen20050606_M->NonInlinedSFcns.taskTimePtrs[3] = &(rtmGetTPtr
      (fangzhen20050606_M)[3]);
    fangzhen20050606_M->NonInlinedSFcns.taskTimePtrs[4] = &(rtmGetTPtr
      (fangzhen20050606_M)[4]);
    rtssSetTPtrPtr(sfcnInfo,fangzhen20050606_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(fangzhen20050606_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(fangzhen20050606_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (fangzhen20050606_M));
    rtssSetStepSizePtr(sfcnInfo, &fangzhen20050606_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(fangzhen20050606_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &fangzhen20050606_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &fangzhen20050606_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &fangzhen20050606_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &fangzhen20050606_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &fangzhen20050606_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &fangzhen20050606_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &fangzhen20050606_M->solverInfoPtr);
  }

  fangzhen20050606_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&fangzhen20050606_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    fangzhen20050606_M->childSfunctions =
      (&fangzhen20050606_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    fangzhen20050606_M->childSfunctions[0] =
      (&fangzhen20050606_M->NonInlinedSFcns.childSFunctions[0]);
    fangzhen20050606_M->childSfunctions[1] =
      (&fangzhen20050606_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: fangzhen20050606/<S83>/S-Function (CIQW_kf_C) */
    {
      SimStruct *rts = fangzhen20050606_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = fangzhen20050606_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = fangzhen20050606_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = fangzhen20050606_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*2);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*2);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &fangzhen20050606_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, fangzhen20050606_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &fangzhen20050606_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &fangzhen20050606_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &fangzhen20050606_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &fangzhen20050606_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &fangzhen20050606_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &fangzhen20050606_B.Merge[0];
          sfcnUPtrs[1] = &fangzhen20050606_B.Merge[1];
          sfcnUPtrs[2] = &fangzhen20050606_B.Merge[2];
          sfcnUPtrs[3] = &fangzhen20050606_B.Merge[3];
          sfcnUPtrs[4] = &fangzhen20050606_B.Sum[0];
          sfcnUPtrs[5] = &fangzhen20050606_B.Sum[1];
          sfcnUPtrs[6] = &fangzhen20050606_B.Sum[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 7);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &fangzhen20050606_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 7);
          ssSetOutputPortSignal(rts, 0, ((real_T *) fangzhen20050606_B.SFunction));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &fangzhen20050606_DWork.SFunction_DSTATE[0]);

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "fangzhen20050606/GNC System/导航与滤波/姿态融合/S-Function");
      ssSetRTModel(rts,fangzhen20050606_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &fangzhen20050606_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &fangzhen20050606_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* DSTATE */
        ssSetDWorkWidth(rts, 0, 7);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &fangzhen20050606_DWork.SFunction_DSTATE[0]);
      }

      /* registration */
      CIQW_kf_C(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 2.0);
      ssSetOffsetTime(rts, 0, 0.0);
      ssSetSampleTime(rts, 1, 0.2);
      ssSetOffsetTime(rts, 1, 0.0);
      sfcnTsMap[0] = 4;
      sfcnTsMap[1] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: fangzhen20050606/<S86>/S-Function (CIRV_kf_C) */
    {
      SimStruct *rts = fangzhen20050606_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = fangzhen20050606_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = fangzhen20050606_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = fangzhen20050606_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*2);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*2);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &fangzhen20050606_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, fangzhen20050606_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &fangzhen20050606_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &fangzhen20050606_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &fangzhen20050606_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &fangzhen20050606_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &fangzhen20050606_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &fangzhen20050606_B.Integrator1_p[0];
          sfcnUPtrs[1] = &fangzhen20050606_B.Integrator1_p[1];
          sfcnUPtrs[2] = &fangzhen20050606_B.Integrator1_p[2];
          sfcnUPtrs[3] = &fangzhen20050606_B.e5[0];
          sfcnUPtrs[4] = &fangzhen20050606_B.e5[1];
          sfcnUPtrs[5] = &fangzhen20050606_B.e5[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 6);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &fangzhen20050606_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 6);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            fangzhen20050606_B.SFunction_k));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *)
                      &fangzhen20050606_DWork.SFunction_DSTATE_h[0]);

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "fangzhen20050606/GNC System/导航与滤波/轨道融合/S-Function");
      ssSetRTModel(rts,fangzhen20050606_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &fangzhen20050606_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &fangzhen20050606_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* DSTATE */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWorkUsedAsDState(rts, 0, 1);
        ssSetDWork(rts, 0, &fangzhen20050606_DWork.SFunction_DSTATE_h[0]);
      }

      /* registration */
      CIRV_kf_C(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.5);
      ssSetOffsetTime(rts, 0, 0.0);
      ssSetSampleTime(rts, 1, 0.05);
      ssSetOffsetTime(rts, 1, 0.0);
      sfcnTsMap[0] = 3;
      sfcnTsMap[1] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  fangzhen20050606_M->Sizes.numContStates = (23);/* Number of continuous states */
  fangzhen20050606_M->Sizes.numY = (0);/* Number of model outputs */
  fangzhen20050606_M->Sizes.numU = (0);/* Number of model inputs */
  fangzhen20050606_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  fangzhen20050606_M->Sizes.numSampTimes = (5);/* Number of sample times */
  fangzhen20050606_M->Sizes.numBlocks = (741);/* Number of blocks */
  fangzhen20050606_M->Sizes.numBlockIO = (73);/* Number of block outputs */
  fangzhen20050606_M->Sizes.numBlockPrms = (449);/* Sum of parameter "widths" */
  return fangzhen20050606_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
