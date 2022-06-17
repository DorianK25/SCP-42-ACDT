/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem9.h
 *
 * Code generated for Simulink model 'Subsystem9'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Jun 15 16:57:42 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (8-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Subsystem9_h_
#define RTW_HEADER_Subsystem9_h_
#include <math.h>
#ifndef Subsystem9_COMMON_INCLUDES_
#define Subsystem9_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Subsystem9_COMMON_INCLUDES_ */

#include "Subsystem9_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum3;                         /* '<S4>/Sum3' */
  real_T Sum3_m;                       /* '<S5>/Sum3' */
} B_Subsystem9_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S5>/Integrator' */
} X_Subsystem9_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S5>/Integrator' */
} XDot_Subsystem9_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S5>/Integrator' */
} XDis_Subsystem9_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T x;                            /* '<Root>/x+' */
  real_T y;                            /* '<Root>/y+' */
  real_T O;                            /* '<Root>/theta' */
  real_T x_f;                          /* '<Root>/x_actuel' */
  real_T y_i;                          /* '<Root>/y_actuel' */
  real_T vd;                           /* '<Root>/Vd' */
  real_T vg;                           /* '<Root>/Vg' */
} ExtU_Subsystem9_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Ud;                           /* '<Root>/Ud' */
  real_T Ug;                           /* '<Root>/Ug' */
} ExtY_Subsystem9_T;

/* Parameters (default storage) */
struct P_Subsystem9_T_ {
  real_T G1;                           /* Variable: G1
                                        * Referenced by:
                                        *   '<S6>/Gain'
                                        *   '<S7>/Gain'
                                        */
  real_T Kb;                           /* Variable: Kb
                                        * Referenced by:
                                        *   '<S4>/Gain2'
                                        *   '<S5>/Gain2'
                                        */
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by:
                                        *   '<S4>/Gain'
                                        *   '<S5>/Gain'
                                        */
  real_T Kx;                           /* Variable: Kx
                                        * Referenced by:
                                        *   '<S4>/Gain1'
                                        *   '<S5>/Gain1'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T L1;                           /* Variable: L1
                                        * Referenced by:
                                        *   '<S6>/Gain1'
                                        *   '<S7>/Gain1'
                                        */
  real_T P;                            /* Variable: P
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 9
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -9
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 400
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -400
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Integrator_IC_m;              /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T Saturation1_UpperSat_n;       /* Expression: 9
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -9
                                        * Referenced by: '<S5>/Saturation1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Subsystem9_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Subsystem9_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][2];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Subsystem9_T Subsystem9_P;

/* Block signals (default storage) */
extern B_Subsystem9_T Subsystem9_B;

/* Continuous states (default storage) */
extern X_Subsystem9_T Subsystem9_X;

/* External inputs (root inport signals with default storage) */
extern ExtU_Subsystem9_T Subsystem9_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Subsystem9_T Subsystem9_Y;

/* Model entry point functions */
extern void Subsystem9_initialize(void);
extern void Subsystem9_step(void);
extern void Subsystem9_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Subsystem9_T *const Subsystem9_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('convertiseur_C/Subsystem9')    - opens subsystem convertiseur_C/Subsystem9
 * hilite_system('convertiseur_C/Subsystem9/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'convertiseur_C'
 * '<S1>'   : 'convertiseur_C/Subsystem9'
 * '<S2>'   : 'convertiseur_C/Subsystem9/Subsystem'
 * '<S3>'   : 'convertiseur_C/Subsystem9/Subsystem1'
 * '<S4>'   : 'convertiseur_C/Subsystem9/Subsystem2'
 * '<S5>'   : 'convertiseur_C/Subsystem9/Subsystem3'
 * '<S6>'   : 'convertiseur_C/Subsystem9/Subsystem7'
 * '<S7>'   : 'convertiseur_C/Subsystem9/Subsystem8'
 */
#endif                                 /* RTW_HEADER_Subsystem9_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
