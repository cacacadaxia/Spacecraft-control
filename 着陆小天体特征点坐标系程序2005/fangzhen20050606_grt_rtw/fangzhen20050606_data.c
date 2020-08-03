/*
 * fangzhen20050606_data.c
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

/* Block parameters (auto storage) */
Parameters_fangzhen20050606 fangzhen20050606_P = {
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S96>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S96>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S96>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S111>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S99>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S110>/Constant1'
                                        */

  /*  Expression: [0 1]
   * Referenced by: '<S110>/Constant2'
   */
  { 0.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S99>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S99>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S99>/Gain4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S116>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S100>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S115>/Constant1'
                                        */

  /*  Expression: [0 1]
   * Referenced by: '<S115>/Constant2'
   */
  { 0.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S100>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S100>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S100>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S106>/Constant'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S98>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S105>/Constant1'
                                        */

  /*  Expression: [0 1]
   * Referenced by: '<S105>/Constant2'
   */
  { 0.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S98>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S98>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S98>/Gain3'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<S143>/Constant1'
   */
  { 0.0, 0.0 },
  200.0,                               /* Expression: T
                                        * Referenced by: '<S143>/Constant2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S145>/Gain2'
                                        */
  -2.0,                                /* Expression: -2
                                        * Referenced by: '<S145>/Gain1'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<S145>/Gain4'
                                        */
  -6.0,                                /* Expression: -6
                                        * Referenced by: '<S146>/Gain1'
                                        */
  -4.0,                                /* Expression: -4
                                        * Referenced by: '<S146>/Gain2'
                                        */
  6.0,                                 /* Expression: 6
                                        * Referenced by: '<S146>/Gain4'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S146>/Gain5'
                                        */

  /*  Expression: Noise_gc
   * Referenced by: '<S87>/Noigc'
   */
  { 2.9088820866572161E-5, -2.9088820866572161E-5, 2.9088820866572161E-5 },

  /*  Expression: Wcc
   * Referenced by: '<S87>/Wcc'
   */
  { 0.2, 0.2, 0.2 },

  /*  Expression: AWcc
   * Referenced by: '<S87>/AWcc'
   */
  { 2.4240684055476797E-7, 2.4240684055476797E-7, 2.4240684055476797E-7 },

  /*  Expression: HBd0
   * Referenced by: '<S9>/Constant1'
   */
  { 0.064877378955133222, 0.055780722893738775, 0.07467914803433337 },

  /*  Expression: InvIBd
   * Referenced by: '<S9>/InvIBu'
   */
  { 0.010752695253791975, 9.4086093362909228E-6, 2.63792785129652E-9,
    9.4086093362909228E-6, 0.01250000954678651, 3.5046755738653758E-6,
    2.63792785129652E-9, 3.5046755738653758E-6, 0.009345795375142683 },

  /*  Expression: Wgmax
   * Referenced by: '<S87>/Wgmax'
   */
  { 0.17453292519943295, 0.17453292519943295, 0.17453292519943295 },

  /*  Expression: -Wgmax
   * Referenced by: '<S87>/Wgmax'
   */
  { -0.17453292519943295, -0.17453292519943295, -0.17453292519943295 },

  /*  Expression: [0 0 0]
   * Referenced by: '<S87>/Noign'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Noign_StdDev
   * Referenced by: '<S87>/Noign'
   */
  { 1.454441043328608E-5, 1.454441043328608E-5, 1.454441043328608E-5 },

  /*  Expression: [1859 2483 4682]
   * Referenced by: '<S87>/Noign'
   */
  { 1859.0, 2483.0, 4682.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S87>/Integrator'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: Qb0
   * Referenced by: '<S10>/Constant3'
   */
  { 1.0, 0.0, 0.0, 0.0 },
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S14>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S17>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S12>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S18>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S13>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S16>/Gain'
                                        */

  /*  Expression: r0
   * Referenced by: '<S36>/Integrator1'
   */
  { 100.0, -200.0, 1000.0 },

  /*  Expression: TA
   * Referenced by: '<S6>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: TB
   * Referenced by: '<S6>/Constant1'
   */
  { 500.0, 0.0, 0.0 },

  /*  Expression: TC
   * Referenced by: '<S6>/Constant2'
   */
  { 500.0, 500.0, 0.0 },

  /*  Expression: [0 0 0 0 0 0]
   * Referenced by: '<S85>/Random Number'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: RandomNumber_StdDev
   * Referenced by: '<S85>/Random Number'
   */
  { 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001 },

  /*  Expression: [15683 12482 12355 15000 12000 12000]
   * Referenced by: '<S85>/Random Number'
   */
  { 15683.0, 12482.0, 12355.0, 15000.0, 12000.0, 12000.0 },

  /*  Expression: [0 0 0]
   * Referenced by: '<S84>/Random Number'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: RandomNumber_StdDev_n
   * Referenced by: '<S84>/Random Number'
   */
  { 3.1622776601683795, 3.1622776601683795, 3.1622776601683795 },

  /*  Expression: [15683 12482 12355]
   * Referenced by: '<S84>/Random Number'
   */
  { 15683.0, 12482.0, 12355.0 },
  -0.02,                               /* Expression: f
                                        * Referenced by: '<S88>/Constant'
                                        */
  -0.02,                               /* Expression: f
                                        * Referenced by: '<S89>/Constant'
                                        */
  -0.02,                               /* Expression: f
                                        * Referenced by: '<S90>/Constant'
                                        */

  /*  Expression: [1 0 0 0]
   * Referenced by: '<S92>/Merge'
   */
  { 1.0, 0.0, 0.0, 0.0 },
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S57>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S60>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S55>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S61>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S56>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S59>/Gain'
                                        */
  100000.0,                            /* Expression: 100000
                                        * Referenced by: '<S53>/Constant4'
                                        */

  /*  Expression: rg0
   * Referenced by: '<S82>/Integrator1'
   */
  { 3.0, -104.0, 950.0 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S91>/Gain'
                                        */

  /*  Expression: vg0
   * Referenced by: '<S82>/Integrator'
   */
  { 0.0, -0.1, -0.4 },
  1.0E-10,                             /* Expression: 0.0000000001
                                        * Referenced by: '<S52>/Constant1'
                                        */
  200.0,                               /* Expression: T
                                        * Referenced by: '<S144>/T'
                                        */
  -6.0,                                /* Expression: -6
                                        * Referenced by: '<S147>/Gain'
                                        */

  /*  Expression: [0;0;0]
   * Referenced by: '<S52>/Constant5'
   */
  { 0.0, 0.0, 0.0 },
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<S147>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S150>/Gain1'
                                        */
  18.0,                                /* Expression: 18
                                        * Referenced by: '<S148>/Gain2'
                                        */
  48.0,                                /* Expression: 48
                                        * Referenced by: '<S148>/Gain3'
                                        */
  0.16666666666666666,                 /* Expression: 1/6
                                        * Referenced by: '<S150>/Gain3'
                                        */
  -12.0,                               /* Expression: -12
                                        * Referenced by: '<S149>/Gain2'
                                        */
  -36.0,                               /* Expression: -36
                                        * Referenced by: '<S149>/Gain3'
                                        */
  0.083333333333333329,                /* Expression: 1/12
                                        * Referenced by: '<S150>/Gain2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S151>/Gain3'
                                        */
  0.33333333333333331,                 /* Expression: 1/3
                                        * Referenced by: '<S151>/Gain1'
                                        */

  /*  Expression: Rtb
   * Referenced by: '<S53>/Constant3'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0;0;0]
   * Referenced by: '<S52>/Constant2'
   */
  { 0.0, 0.0, 0.0 },
  200.0,                               /* Expression: T
                                        * Referenced by: '<S52>/Constant3'
                                        */
  0.01,                                /* Expression: d
                                        * Referenced by: '<S78>/Constant'
                                        */
  -2.5,                                /* Expression: -1/2/a
                                        * Referenced by: '<S78>/Gain'
                                        */

  /*  Expression: [(2*a*a0/(a+a0)*b)^0.5;(2*a*a0/(a+a0)*b)^0.5;(2*a*a0/(a+a0)*b)^0.5]
   * Referenced by: '<S49>/Constant3'
   */
  { 0.0031622776601683794, 0.0031622776601683794, 0.0031622776601683794 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S49>/Gain'
                                        */
  6.2499999999999991,                  /* Expression: 1/2/a0
                                        * Referenced by: '<S78>/Gain1'
                                        */
  0.0099125,                           /* Expression: d-b
                                        * Referenced by: '<S78>/Constant1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S76>/Gain1'
                                        */
  -0.0099125,                          /* Expression: -d+b
                                        * Referenced by: '<S77>/Constant'
                                        */
  -6.2499999999999991,                 /* Expression: -1/2/a0
                                        * Referenced by: '<S77>/Gain'
                                        */
  2.5,                                 /* Expression: 1/2/a
                                        * Referenced by: '<S77>/Gain1'
                                        */
  -0.01,                               /* Expression: -d
                                        * Referenced by: '<S77>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S75>/Gain'
                                        */
  200.0,                               /* Expression: T
                                        * Referenced by: '<S49>/Constant'
                                        */

  /*  Expression: v0
   * Referenced by: '<S36>/Integrator'
   */
  { -0.1, 0.1, -0.3 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S35>/Gain2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain1'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain2'
                                        */

  /*  Expression: We
   * Referenced by: '<S3>/Constant'
   */
  { 7.35119524406047E-5, -0.00014477271107363239, 0.00028864924419934779 },

  /*  Expression: HWw0
   * Referenced by: '<S24>/Unit delay'
   */
  { 0.01, 0.01, 0.01, 0.01 },
  0.05,                                /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */

  /*  Expression: HWw0
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  { 0.01, 0.01, 0.01, 0.01 },

  /*  Expression: Hwmax
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  { 0.99997941361314291, 0.99997941361314291, 0.99997941361314291,
    0.99997941361314291 },

  /*  Expression: -Hwmax
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  { -0.99997941361314291, -0.99997941361314291, -0.99997941361314291,
    -0.99997941361314291 },

  /*  Expression: invJW
   * Referenced by: '<S25>/invJW'
   */
  { 575.97051030987211, 575.97051030987211, 575.97051030987211,
    575.97051030987211 },

  /*  Expression: JW
   * Referenced by: '<S24>/JW'
   */
  { 0.0017362, 0.0017362, 0.0017362, 0.0017362 },
  20.0,                                /* Expression: 20
                                        * Referenced by: '<S24>/1//T'
                                        */

  /*  Expression: DWN
   * Referenced by: '<S24>/DWN'
   */
  { 0.40827040594287317, 0.577287712085548, -0.70714508631982664,
    0.70714508631982664, 0.577287712085548, 0.40827040594287317,
    -0.40827040594287317, 0.577287712085548, 0.70714508631982664,
    -0.70714508631982664, 0.577287712085548, -0.40827040594287317 },

  /*  Expression: IW
   * Referenced by: '<S24>/IW'
   */
  { 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6 },

  /*  Expression: DWN
   * Referenced by: '<S24>/DWN2'
   */
  { 0.40827040594287317, 0.577287712085548, -0.70714508631982664,
    0.70714508631982664, 0.577287712085548, 0.40827040594287317,
    -0.40827040594287317, 0.577287712085548, 0.70714508631982664,
    -0.70714508631982664, 0.577287712085548, -0.40827040594287317 },

  /*  Expression: DWN
   * Referenced by: '<S24>/DWN1'
   */
  { 0.40827040594287317, 0.577287712085548, -0.70714508631982664,
    0.70714508631982664, 0.577287712085548, 0.40827040594287317,
    -0.40827040594287317, 0.577287712085548, 0.70714508631982664,
    -0.70714508631982664, 0.577287712085548, -0.40827040594287317 },

  /*  Expression: [0 0 0 0]
   * Referenced by: '<S25>/TWi'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: TWi_StdDev
   * Referenced by: '<S25>/TWi'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0 0]
   * Referenced by: '<S25>/TWi'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: CWw
   * Referenced by: '<S25>/CWw'
   */
  { 6.0E-5, 6.0E-5, 6.0E-5, 6.0E-5 },

  /*  Expression: [0 0 0 0]
   * Referenced by: '<S25>/Constant2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: TWf0
   * Referenced by: '<S25>/Tf0'
   */
  { 0.0003, 0.0003, 0.0003, 0.0003 },

  /*  Expression: [0 0 0]
   * Referenced by: '<S50>/Constant1'
   */
  { 0.0, 0.0, 0.0 },
  0.2,                                 /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                                        * Referenced by: '<S50>/Discrete-Time Integrator'
                                        */

  /*  Expression: Ki
   * Referenced by: '<S50>/Ki'
   */
  { 0.0503, 0.0503, 0.0503 },

  /*  Expression: [0.01, 0.01, 0.01]
   * Referenced by: '<S50>/Saturation'
   */
  { 0.01, 0.01, 0.01 },

  /*  Expression: [-0.01, -0.01, -0.01]
   * Referenced by: '<S50>/Saturation'
   */
  { -0.01, -0.01, -0.01 },

  /*  Expression: Kp
   * Referenced by: '<S50>/Kp'
   */
  { 7.0313, 6.0484, 8.0898 },

  /*  Expression: Kd
   * Referenced by: '<S50>/Kd'
   */
  { 19.2895, 16.6643, 22.1166 },

  /*  Expression: [-1 -1 -1]
   * Referenced by: '<S50>/Gain'
   */
  { -1.0, -1.0, -1.0 },

  /*  Expression: MWN
   * Referenced by: '<S50>/MWN'
   */
  { 0.3061696321371149, 0.53030135859615579, -0.3061696321371149,
    -0.53030135859615579, 0.43305962480447296, 0.43305962480447296,
    0.43305962480447296, 0.43305962480447296, -0.53030135859615579,
    0.3061696321371149, 0.53030135859615579, -0.3061696321371149 },

  /*  Expression: Tcmax
   * Referenced by: '<S25>/Saturation'
   */
  { 0.02, 0.02, 0.02, 0.02 },

  /*  Expression: -Tcmax
   * Referenced by: '<S25>/Saturation'
   */
  { -0.02, -0.02, -0.02, -0.02 },
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S10>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S10>/Gain1'
                                        */
  40.0,                                /* Expression: F
                                        * Referenced by: '<S1>/Gain'
                                        */
  200.0,                               /* Expression: m0
                                        * Referenced by: '<S36>/m0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Integrator2'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S36>/Constant2'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S36>/Constant'
                                        */
  0.06,                                /* Expression: 0.06
                                        * Referenced by: '<S36>/Constant1'
                                        */

  /*  Expression: Tl'
   * Referenced by: '<S38>/Matrix Gain'
   */
  { 0.95268911725390548, 0.23339191188721606, -0.19470917115432523,
    -0.19470917115432523, 0.96053049700144255, 0.19866933079506122,
    0.23339191188721606, -0.15135844804896667, 0.96053049700144255 },

  /*  Expression: R0
   * Referenced by: '<S38>/[0;0;R0]'
   */
  { -331.00559096235287, 337.73786235160406, 1632.9018449024522 },

  /*  Expression: Gl
   * Referenced by: '<S38>/Matrix Gain1'
   */
  { -0.5, -0.70710678118654746, 0.50000000000000011, 0.49999999999999989,
    -0.70710678118654757, -0.5, 0.70710678118654757, 0.0, 0.70710678118654746 },
  -4794.0,                             /* Expression: -Mu
                                        * Referenced by: '<S43>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S43>/Constant3'
                                        */
  3.0625E+6,                           /* Expression: re^2
                                        * Referenced by: '<S43>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S43>/Constant'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S43>/Gain'
                                        */
  -0.1695,                             /* Expression: 3*c20/2
                                        * Referenced by: '<S43>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S43>/Constant1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S43>/Gain2'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S43>/Gain3'
                                        */
  0.11880000000000002,                 /* Expression: 3*c22
                                        * Referenced by: '<S43>/Gain4'
                                        */
  -4794.0,                             /* Expression: -Mu
                                        * Referenced by: '<S44>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S44>/Constant3'
                                        */
  3.0625E+6,                           /* Expression: re^2
                                        * Referenced by: '<S44>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S44>/Constant'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S44>/Gain'
                                        */
  -0.1695,                             /* Expression: 3*c20/2
                                        * Referenced by: '<S44>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S44>/Constant1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S44>/Gain2'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S44>/Gain3'
                                        */
  0.11880000000000002,                 /* Expression: 3*c22
                                        * Referenced by: '<S44>/Gain4'
                                        */
  -4794.0,                             /* Expression: -Mu
                                        * Referenced by: '<S45>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S45>/Constant3'
                                        */
  3.0625E+6,                           /* Expression: re^2
                                        * Referenced by: '<S45>/Constant2'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S45>/Constant'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S45>/Gain'
                                        */
  -0.1695,                             /* Expression: 3*c20/2
                                        * Referenced by: '<S45>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S45>/Gain2'
                                        */
  0.59400000000000008,                 /* Expression: 15*c22
                                        * Referenced by: '<S45>/Gain4'
                                        */

  /*  Expression: Gl'
   * Referenced by: '<S38>/Matrix Gain2'
   */
  { -0.5, 0.49999999999999989, 0.70710678118654757, -0.70710678118654746,
    -0.70710678118654757, 0.0, 0.50000000000000011, -0.5, 0.70710678118654746 },

  /*  Expression: R0
   * Referenced by: '<S39>/R0'
   */
  { -331.00559096235287, 337.73786235160406, 1632.9018449024522 },

  /*  Expression: -A
   * Referenced by: '<S39>/Matrix Gain'
   */
  { 1.0427752404846414E-7, 1.064252465114227E-8, -2.1219169511598947E-8,
    1.064252465114227E-8, 8.8722393328484421E-8, 4.1788533632094536E-8,
    -2.1219169511598947E-8, 4.1788533632094536E-8, 2.6363145023239149E-8 },

  /*  Expression: -B
   * Referenced by: '<S37>/Matrix Gain'
   */
  { -0.0, -0.00057729848839869558, -0.00028954542214726478,
    0.00057729848839869558, -0.0, -0.00014702390488120941,
    0.00028954542214726478, 0.00014702390488120941, -0.0 },
  0.00034013605442176868,              /* Expression: 1/Isp
                                        * Referenced by: '<S36>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S72>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S70>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S69>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain1'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S138>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S136>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S135>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S51>/Gain1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S121>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S122>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S123>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S125>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S126>/Gain'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S127>/Gain'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S82>/Random Number'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: RandomNumber_StdDev_k
   * Referenced by: '<S82>/Random Number'
   */
  { 0.011038568747804218, 0.011038568747804218, 0.011038568747804218 },

  /*  Expression: [15683 12482 12355]
   * Referenced by: '<S82>/Random Number'
   */
  { 15683.0, 12482.0, 12355.0 },

  /*  Expression: [0 0 0]
   * Referenced by: '<S82>/cp'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0 0]
   * Referenced by: '<S87>/Noign1'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: Noign1_StdDev
   * Referenced by: '<S87>/Noign1'
   */
  { 1.0E-10, 1.0E-10, 1.0E-10 },

  /*  Expression: [4983 1983 6943]
   * Referenced by: '<S87>/Noign1'
   */
  { 4983.0, 1983.0, 6943.0 }
};
