/*
 * AeroPendulum_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&AeroPendulum_B.Step2), 0, 0, 10 }
  ,

  { (char_T *)(&AeroPendulum_DW.DiscreteFIRFilter1_states), 0, 0, 2 },

  { (char_T *)(&AeroPendulum_DW.StreamInput_PWORK[0]), 11, 0, 8 },

  { (char_T *)(&AeroPendulum_DW.DiscreteFIRFilter1_circBuf), 6, 0, 1 },

  { (char_T *)(&AeroPendulum_DW.EnabledSubsystem2_SubsysRanBC), 2, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&AeroPendulum_P.MAX), 0, 0, 13 },

  { (char_T *)(&AeroPendulum_P.PacketOutput_PacketID), 6, 0, 2 },

  { (char_T *)(&AeroPendulum_P.Constant1_Value[0]), 0, 0, 29 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] AeroPendulum_dt.h */
