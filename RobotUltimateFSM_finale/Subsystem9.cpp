/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem9.c
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

#include "Subsystem9.h"
#include "Subsystem9_private.h"

/* Block signals (default storage) */
B_Subsystem9_T Subsystem9_B;

/* Continuous states */
X_Subsystem9_T Subsystem9_X;

/* External inputs (root inport signals with default storage) */
ExtU_Subsystem9_T Subsystem9_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Subsystem9_T Subsystem9_Y;

/* Real-time model */
static RT_MODEL_Subsystem9_T Subsystem9_M_;
RT_MODEL_Subsystem9_T *const Subsystem9_M = &Subsystem9_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Subsystem9_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Subsystem9_step(void)
{
  real_T rtb_Cos;
  real_T rtb_Sum1_a;
  real_T rtb_Sum2;
  real_T rtb_Sum_g;
  real_T rtb_Sum_i;
  if (rtmIsMajorTimeStep(Subsystem9_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Subsystem9_M->solverInfo,
                          ((Subsystem9_M->Timing.clockTick0+1)*
      Subsystem9_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Subsystem9_M)) {
    Subsystem9_M->Timing.t[0] = rtsiGetT(&Subsystem9_M->solverInfo);
  }

  /* Sum: '<S4>/Sum1' incorporates:
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/Vd'
   *  Integrator: '<S4>/Integrator'
   */
  rtb_Sum_i = (0.0 - Subsystem9_P.Ki * Subsystem9_X.Integrator_CSTATE) -
    Subsystem9_P.Kx * Subsystem9_U.vd;

  /* Saturate: '<S4>/Saturation1' */
  if (rtb_Sum_i > Subsystem9_P.Saturation1_UpperSat) {
    /* Saturate: '<S4>/Saturation1' */
    Subsystem9_Y.Ud = Subsystem9_P.Saturation1_UpperSat;
  } else if (rtb_Sum_i < Subsystem9_P.Saturation1_LowerSat) {
    /* Saturate: '<S4>/Saturation1' */
    Subsystem9_Y.Ud = Subsystem9_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<S4>/Saturation1' */
    Subsystem9_Y.Ud = rtb_Sum_i;
  }

  /* End of Saturate: '<S4>/Saturation1' */

  /* Sum: '<S4>/Sum2' */
  rtb_Sum2 = Subsystem9_Y.Ud - rtb_Sum_i;

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Inport: '<Root>/x+'
   *  Inport: '<Root>/x_actuel'
   */
  rtb_Sum_i = Subsystem9_P.G1 * Subsystem9_U.x - Subsystem9_P.L1 *
    Subsystem9_U.x_f;

  /* Trigonometry: '<S2>/Cos' incorporates:
   *  Inport: '<Root>/theta'
   */
  rtb_Cos = cos(Subsystem9_U.O);

  /* Sum: '<S7>/Sum' incorporates:
   *  Gain: '<S7>/Gain'
   *  Gain: '<S7>/Gain1'
   *  Inport: '<Root>/y+'
   *  Inport: '<Root>/y_actuel'
   */
  rtb_Sum_g = Subsystem9_P.G1 * Subsystem9_U.y - Subsystem9_P.L1 *
    Subsystem9_U.y_i;

  /* Saturate: '<S5>/Saturation1' incorporates:
   *  Inport: '<Root>/theta'
   *  Trigonometry: '<S2>/Sin'
   */
  Subsystem9_Y.Ug = sin(Subsystem9_U.O);

  /* Sum: '<S2>/Sum' incorporates:
   *  Product: '<S2>/Product3'
   *  Product: '<S2>/Product4'
   */
  rtb_Sum1_a = rtb_Sum_i * rtb_Cos + rtb_Sum_g * Subsystem9_Y.Ug;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Sum1_a > Subsystem9_P.Saturation_UpperSat) {
    rtb_Sum1_a = Subsystem9_P.Saturation_UpperSat;
  } else {
    if (rtb_Sum1_a < Subsystem9_P.Saturation_LowerSat) {
      rtb_Sum1_a = Subsystem9_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* Saturate: '<S5>/Saturation1' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  Product: '<S2>/Divide'
   *  Product: '<S2>/Product1'
   *  Product: '<S2>/Product2'
   *  Product: '<S3>/Product'
   *  Sum: '<S2>/Sum1'
   */
  Subsystem9_Y.Ug = (rtb_Sum_g * rtb_Cos - rtb_Sum_i * Subsystem9_Y.Ug) /
    Subsystem9_P.L * Subsystem9_P.P;

  /* Sum: '<S4>/Sum3' incorporates:
   *  Gain: '<S4>/Gain2'
   *  Inport: '<Root>/Vd'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S4>/Sum'
   */
  Subsystem9_B.Sum3 = ((rtb_Sum1_a + Subsystem9_Y.Ug) - Subsystem9_U.vd) +
    Subsystem9_P.Kb * rtb_Sum2;

  /* Sum: '<S3>/Sum1' */
  rtb_Sum_i = rtb_Sum1_a - Subsystem9_Y.Ug;

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Inport: '<Root>/Vg'
   *  Integrator: '<S5>/Integrator'
   */
  rtb_Sum1_a = (0.0 - Subsystem9_P.Ki * Subsystem9_X.Integrator_CSTATE_l) -
    Subsystem9_P.Kx * Subsystem9_U.vg;

  /* Saturate: '<S5>/Saturation1' */
  if (rtb_Sum1_a > Subsystem9_P.Saturation1_UpperSat_n) {
    /* Saturate: '<S5>/Saturation1' */
    Subsystem9_Y.Ug = Subsystem9_P.Saturation1_UpperSat_n;
  } else if (rtb_Sum1_a < Subsystem9_P.Saturation1_LowerSat_n) {
    /* Saturate: '<S5>/Saturation1' */
    Subsystem9_Y.Ug = Subsystem9_P.Saturation1_LowerSat_n;
  } else {
    /* Saturate: '<S5>/Saturation1' */
    Subsystem9_Y.Ug = rtb_Sum1_a;
  }

  /* End of Saturate: '<S5>/Saturation1' */

  /* Sum: '<S5>/Sum3' incorporates:
   *  Gain: '<S5>/Gain2'
   *  Inport: '<Root>/Vg'
   *  Sum: '<S5>/Sum'
   *  Sum: '<S5>/Sum2'
   */
  Subsystem9_B.Sum3_m = (Subsystem9_Y.Ug - rtb_Sum1_a) * Subsystem9_P.Kb +
    (rtb_Sum_i - Subsystem9_U.vg);
  if (rtmIsMajorTimeStep(Subsystem9_M)) {
    rt_ertODEUpdateContinuousStates(&Subsystem9_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Subsystem9_M->Timing.clockTick0;
    Subsystem9_M->Timing.t[0] = rtsiGetSolverStopTime(&Subsystem9_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Subsystem9_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Subsystem9_derivatives(void)
{
  XDot_Subsystem9_T *_rtXdot;
  _rtXdot = ((XDot_Subsystem9_T *) Subsystem9_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = Subsystem9_B.Sum3;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_l = Subsystem9_B.Sum3_m;
}

/* Model initialize function */
void Subsystem9_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Subsystem9_M->solverInfo,
                          &Subsystem9_M->Timing.simTimeStep);
    rtsiSetTPtr(&Subsystem9_M->solverInfo, &rtmGetTPtr(Subsystem9_M));
    rtsiSetStepSizePtr(&Subsystem9_M->solverInfo,
                       &Subsystem9_M->Timing.stepSize0);
    rtsiSetdXPtr(&Subsystem9_M->solverInfo, &Subsystem9_M->derivs);
    rtsiSetContStatesPtr(&Subsystem9_M->solverInfo, (real_T **)
                         &Subsystem9_M->contStates);
    rtsiSetNumContStatesPtr(&Subsystem9_M->solverInfo,
      &Subsystem9_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Subsystem9_M->solverInfo,
      &Subsystem9_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Subsystem9_M->solverInfo,
      &Subsystem9_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Subsystem9_M->solverInfo,
      &Subsystem9_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Subsystem9_M->solverInfo, (&rtmGetErrorStatus
      (Subsystem9_M)));
    rtsiSetRTModelPtr(&Subsystem9_M->solverInfo, Subsystem9_M);
  }

  rtsiSetSimTimeStep(&Subsystem9_M->solverInfo, MAJOR_TIME_STEP);
  Subsystem9_M->intgData.f[0] = Subsystem9_M->odeF[0];
  Subsystem9_M->contStates = ((X_Subsystem9_T *) &Subsystem9_X);
  rtsiSetSolverData(&Subsystem9_M->solverInfo, (void *)&Subsystem9_M->intgData);
  rtsiSetSolverName(&Subsystem9_M->solverInfo,"ode1");
  rtmSetTPtr(Subsystem9_M, &Subsystem9_M->Timing.tArray[0]);
  Subsystem9_M->Timing.stepSize0 = 0.005;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  Subsystem9_X.Integrator_CSTATE = Subsystem9_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  Subsystem9_X.Integrator_CSTATE_l = Subsystem9_P.Integrator_IC_m;
}

/* Model terminate function */
void Subsystem9_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
