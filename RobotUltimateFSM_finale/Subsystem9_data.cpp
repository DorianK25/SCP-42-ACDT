/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem9_data.c
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

/* Block parameters (default storage) */
P_Subsystem9_T Subsystem9_P = {
  /* Variable: G1
   * Referenced by:
   *   '<S6>/Gain'
   *   '<S7>/Gain'
   */
  1.0,

  /* Variable: Kb
   * Referenced by:
   *   '<S4>/Gain2'
   *   '<S5>/Gain2'
   */
  249.99999999999395,

  /* Variable: Ki
   * Referenced by:
   *   '<S4>/Gain'
   *   '<S5>/Gain'
   */
  -8.0000000000001936,

  /* Variable: Kx
   * Referenced by:
   *   '<S4>/Gain1'
   *   '<S5>/Gain1'
   */
  0.10000000000000073,

  /* Variable: L
   * Referenced by: '<S2>/Constant'
   */
  200.0,

  /* Variable: L1
   * Referenced by:
   *   '<S6>/Gain1'
   *   '<S7>/Gain1'
   */
  1.0,

  /* Variable: P
   * Referenced by: '<S3>/Constant'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Expression: 9
   * Referenced by: '<S4>/Saturation1'
   */
  9.0,

  /* Expression: -9
   * Referenced by: '<S4>/Saturation1'
   */
  -9.0,

  /* Expression: 400
   * Referenced by: '<S1>/Saturation'
   */
  400.0,

  /* Expression: -400
   * Referenced by: '<S1>/Saturation'
   */
  -400.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Expression: 9
   * Referenced by: '<S5>/Saturation1'
   */
  9.0,

  /* Expression: -9
   * Referenced by: '<S5>/Saturation1'
   */
  -9.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
