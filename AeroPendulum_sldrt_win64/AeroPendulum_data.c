/*
 * AeroPendulum_data.c
 *
 * Code generation for model "AeroPendulum".
 *
 * Model version              : 1.144
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Fri Nov  6 17:36:18 2020
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AeroPendulum.h"
#include "AeroPendulum_private.h"

/* Block parameters (default storage) */
P_AeroPendulum_T AeroPendulum_P = {
  /* Variable: MAX
   * Referenced by: '<S44>/Saturation'
   */
  110.0,

  /* Variable: MIN
   * Referenced by: '<S44>/Saturation'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForFilter
   * Referenced by: '<S32>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForIntegrator
   * Referenced by: '<S37>/Integrator'
   */
  0.0,

  /* Mask Parameter: Ramp2_InitialOutput
   * Referenced by: '<S7>/Constant1'
   */
  0.0,

  /* Mask Parameter: PacketOutput_MaxMissedTicks
   * Referenced by: '<S4>/Packet Output'
   */
  10.0,

  /* Mask Parameter: PacketOutput_MaxMissedTicks_k
   * Referenced by: '<S5>/Packet Output'
   */
  10.0,

  /* Mask Parameter: StreamInput_MaxMissedTicks
   * Referenced by: '<S1>/Stream Input'
   */
  10.0,

  /* Mask Parameter: PacketOutput_YieldWhenWaiting
   * Referenced by: '<S4>/Packet Output'
   */
  1.0,

  /* Mask Parameter: PacketOutput_YieldWhenWaiting_l
   * Referenced by: '<S5>/Packet Output'
   */
  0.0,

  /* Mask Parameter: StreamInput_YieldWhenWaiting
   * Referenced by: '<S1>/Stream Input'
   */
  0.0,

  /* Mask Parameter: Ramp2_slope
   * Referenced by: '<S7>/Step'
   */
  1.0,

  /* Mask Parameter: Ramp2_start
   * Referenced by:
   *   '<S7>/Constant'
   *   '<S7>/Step'
   */
  0.0,

  /* Mask Parameter: PacketOutput_PacketID
   * Referenced by: '<S4>/Packet Output'
   */
  1,

  /* Mask Parameter: PacketOutput_PacketID_m
   * Referenced by: '<S5>/Packet Output'
   */
  1,

  /* Expression: [50,52]
   * Referenced by: '<S4>/Constant1'
   */
  { 50.0, 52.0 },

  /* Expression: [13,10]
   * Referenced by: '<S4>/Constant2'
   */
  { 13.0, 10.0 },

  /* Expression: [13,10]
   * Referenced by: '<S5>/Constant1'
   */
  { 13.0, 10.0 },

  /* Expression: [40,42]
   * Referenced by: '<S5>/Constant2'
   */
  { 40.0, 42.0 },

  /* Expression: 1
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<S2>/Sine Wave2'
   */
  5.0,

  /* Expression: 20
   * Referenced by: '<S2>/Sine Wave2'
   */
  20.0,

  /* Expression: 0.5
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Step2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Step2'
   */
  1.0,

  /* Expression: 25
   * Referenced by: '<S2>/Step2'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S7>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete FIR Filter1'
   */
  0.0,

  /* Expression: [0.5 0.5]
   * Referenced by: '<S1>/Discrete FIR Filter1'
   */
  { 0.5, 0.5 },

  /* Expression: 2
   * Referenced by: '<S1>/Gain'
   */
  2.0,

  /* Expression: 5
   * Referenced by: '<Root>/P gain'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/D gain'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<Root>/N'
   */
  100.0,

  /* Expression: 0.8
   * Referenced by: '<Root>/OFF'
   */
  0.8,

  /* Expression: 0
   * Referenced by: '<Root>/I gain'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<S1>/Memory'
   */
  20.0,

  /* Expression: -1
   * Referenced by: '<S1>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Stop sim'
   */
  0.0
};
