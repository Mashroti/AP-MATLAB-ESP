/*
 * AeroPendulum.c
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
#include "AeroPendulum_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  115200.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.025, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/Serial_Port", 5U, 8, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_AeroPendulum_T AeroPendulum_B;

/* Continuous states */
X_AeroPendulum_T AeroPendulum_X;

/* Block states (default storage) */
DW_AeroPendulum_T AeroPendulum_DW;

/* Real-time model */
RT_MODEL_AeroPendulum_T AeroPendulum_M_;
RT_MODEL_AeroPendulum_T *const AeroPendulum_M = &AeroPendulum_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  AeroPendulum_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  AeroPendulum_output();
  AeroPendulum_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  AeroPendulum_output();
  AeroPendulum_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  AeroPendulum_output();
  AeroPendulum_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  AeroPendulum_output();
  AeroPendulum_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  AeroPendulum_output();
  AeroPendulum_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void AeroPendulum_output(void)
{
  real_T currentTime_tmp;
  if (rtmIsMajorTimeStep(AeroPendulum_M)) {
    /* set solver stop time */
    if (!(AeroPendulum_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&AeroPendulum_M->solverInfo,
                            ((AeroPendulum_M->Timing.clockTickH0 + 1) *
        AeroPendulum_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&AeroPendulum_M->solverInfo,
                            ((AeroPendulum_M->Timing.clockTick0 + 1) *
        AeroPendulum_M->Timing.stepSize0 + AeroPendulum_M->Timing.clockTickH0 *
        AeroPendulum_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(AeroPendulum_M)) {
    AeroPendulum_M->Timing.t[0] = rtsiGetT(&AeroPendulum_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(AeroPendulum_DW.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(AeroPendulum_DW.EnabledSubsystem2_SubsysRanBC);
  if (rtmIsMajorTimeStep(AeroPendulum_M)) {
    /* Step: '<S2>/Step2' */
    if (AeroPendulum_M->Timing.t[1] < AeroPendulum_P.Step2_Time) {
      AeroPendulum_B.Step2 = AeroPendulum_P.Step2_Y0;
    } else {
      AeroPendulum_B.Step2 = AeroPendulum_P.Step2_YFinal;
    }

    /* End of Step: '<S2>/Step2' */
  }

  /* Step: '<S7>/Step' incorporates:
   *  Sin: '<S2>/Sine Wave2'
   */
  currentTime_tmp = AeroPendulum_M->Timing.t[0];

  /* MultiPortSwitch: '<S2>/Index Vector' incorporates:
   *  Clock: '<S7>/Clock'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Product: '<S7>/Product'
   *  Sin: '<S2>/Sine Wave2'
   *  Sum: '<S7>/Output'
   *  Sum: '<S7>/Sum'
   */
  switch ((int32_T)AeroPendulum_P.Constant_Value) {
   case 0:
    AeroPendulum_B.IndexVector = sin(AeroPendulum_P.SineWave2_Freq *
      currentTime_tmp + AeroPendulum_P.SineWave2_Phase) *
      AeroPendulum_P.SineWave2_Amp + AeroPendulum_P.SineWave2_Bias;
    break;

   case 1:
    AeroPendulum_B.IndexVector = AeroPendulum_B.Step2;
    break;

   default:
    /* Step: '<S7>/Step' */
    if (currentTime_tmp < AeroPendulum_P.Ramp2_start) {
      currentTime_tmp = AeroPendulum_P.Step_Y0;
    } else {
      currentTime_tmp = AeroPendulum_P.Ramp2_slope;
    }

    AeroPendulum_B.IndexVector = (AeroPendulum_M->Timing.t[0] -
      AeroPendulum_P.Ramp2_start) * currentTime_tmp +
      AeroPendulum_P.Ramp2_InitialOutput;
    break;
  }

  /* End of MultiPortSwitch: '<S2>/Index Vector' */
  if (rtmIsMajorTimeStep(AeroPendulum_M)) {
    /* S-Function (sldrtsi): '<S1>/Stream Input' */
    /* S-Function Block: <S1>/Stream Input */
    {
      char indata[329U];
      int status;
      const char* terminators = "\r\0\n\0";
      memset(indata, 0, sizeof(indata));
      status = RTBIO_DriverIO(0, STREAMINPUT, IOREADWITHRESET, 328U, NULL,
        (double*) indata, terminators);
      if (status & 0x1) {
        real32_T var0 = 0;
        sscanf(indata, "%e", &var0);
        AeroPendulum_B.StreamInput = (real_T) var0;
      }
    }

    /* Gain: '<S1>/Gain' incorporates:
     *  DiscreteFir: '<S1>/Discrete FIR Filter1'
     */
    AeroPendulum_B.Gain = (AeroPendulum_B.StreamInput +
      AeroPendulum_DW.DiscreteFIRFilter1_states) *
      AeroPendulum_P.DiscreteFIRFilter1_Coefficients[0] *
      AeroPendulum_P.Gain_Gain;
  }

  /* Sum: '<Root>/Sum1' */
  AeroPendulum_B.Sum1 = AeroPendulum_B.IndexVector - AeroPendulum_B.Gain;

  /* Product: '<S40>/NProd Out' incorporates:
   *  Constant: '<Root>/D gain'
   *  Constant: '<Root>/N'
   *  Integrator: '<S32>/Filter'
   *  Product: '<S31>/DProd Out'
   *  Sum: '<S32>/SumD'
   */
  AeroPendulum_B.NProdOut = (AeroPendulum_B.Sum1 * AeroPendulum_P.Dgain_Value -
    AeroPendulum_X.Filter_CSTATE) * AeroPendulum_P.N_Value;

  /* Sum: '<S46>/Sum' incorporates:
   *  Constant: '<Root>/P gain'
   *  Integrator: '<S37>/Integrator'
   *  Product: '<S42>/PProd Out'
   */
  currentTime_tmp = (AeroPendulum_B.Sum1 * AeroPendulum_P.Pgain_Value +
                     AeroPendulum_X.Integrator_CSTATE) + AeroPendulum_B.NProdOut;

  /* Saturate: '<S44>/Saturation' */
  if (currentTime_tmp > AeroPendulum_P.MAX) {
    currentTime_tmp = AeroPendulum_P.MAX;
  } else {
    if (currentTime_tmp < AeroPendulum_P.MIN) {
      currentTime_tmp = AeroPendulum_P.MIN;
    }
  }

  /* End of Saturate: '<S44>/Saturation' */

  /* Gain: '<Root>/OFF' */
  AeroPendulum_B.OFF = AeroPendulum_P.OFF_Gain * currentTime_tmp;
  if (rtmIsMajorTimeStep(AeroPendulum_M)) {
    /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
     *  Memory: '<S1>/Memory'
     */
    /* MATLAB Function 'MySystem/MATLAB Function': '<S6>:1' */
    /* '<S6>:1:3' */
    AeroPendulum_B.y = AeroPendulum_DW.Memory_PreviousInput;
    if (AeroPendulum_DW.Memory_PreviousInput == 20.0) {
      /* '<S6>:1:4' */
      /* '<S6>:1:5' */
      AeroPendulum_B.y = -20.0;
    } else {
      if (AeroPendulum_DW.Memory_PreviousInput == -20.0) {
        /* '<S6>:1:6' */
        /* '<S6>:1:7' */
        AeroPendulum_B.y = 20.0;
      }
    }

    /* End of MATLAB Function: '<S1>/MATLAB Function' */

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    if (AeroPendulum_B.y > 0.0) {
      /* S-Function (sldrtpo): '<S4>/Packet Output' incorporates:
       *  Constant: '<S4>/Constant1'
       *  Constant: '<S4>/Constant2'
       */
      /* S-Function Block: <S4>/Packet Output */

      /* no code required */
      if (rtmIsMajorTimeStep(AeroPendulum_M)) {
        srUpdateBC(AeroPendulum_DW.EnabledSubsystem_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem' */

    /* Gain: '<S1>/Gain1' */
    AeroPendulum_B.Gain1 = AeroPendulum_P.Gain1_Gain * AeroPendulum_B.y;

    /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem2' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    if (AeroPendulum_B.Gain1 > 0.0) {
      /* S-Function (sldrtpo): '<S5>/Packet Output' incorporates:
       *  Constant: '<S5>/Constant1'
       *  Constant: '<S5>/Constant2'
       */
      /* S-Function Block: <S5>/Packet Output */

      /* no code required */
      if (rtmIsMajorTimeStep(AeroPendulum_M)) {
        srUpdateBC(AeroPendulum_DW.EnabledSubsystem2_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem2' */

    /* Stop: '<S1>/Stop Simulation' incorporates:
     *  Constant: '<S1>/Stop sim'
     */
    if (AeroPendulum_P.Stopsim_Value != 0.0) {
      rtmSetStopRequested(AeroPendulum_M, 1);
    }

    /* End of Stop: '<S1>/Stop Simulation' */
  }

  /* Product: '<S34>/IProd Out' incorporates:
   *  Constant: '<Root>/I gain'
   */
  AeroPendulum_B.IProdOut = AeroPendulum_B.Sum1 * AeroPendulum_P.Igain_Value;
}

/* Model update function */
void AeroPendulum_update(void)
{
  if (rtmIsMajorTimeStep(AeroPendulum_M)) {
    /* Update for DiscreteFir: '<S1>/Discrete FIR Filter1' */
    AeroPendulum_DW.DiscreteFIRFilter1_circBuf--;
    if (AeroPendulum_DW.DiscreteFIRFilter1_circBuf < 0) {
      AeroPendulum_DW.DiscreteFIRFilter1_circBuf = 0;
    }

    AeroPendulum_DW.DiscreteFIRFilter1_states = AeroPendulum_B.StreamInput;

    /* End of Update for DiscreteFir: '<S1>/Discrete FIR Filter1' */

    /* Update for Memory: '<S1>/Memory' */
    AeroPendulum_DW.Memory_PreviousInput = AeroPendulum_B.y;

    /* Update for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S4>/Enable'
     */
    if (AeroPendulum_B.y > 0.0) {
      /* Update for S-Function (sldrtpo): '<S4>/Packet Output' incorporates:
       *  Constant: '<S4>/Constant1'
       *  Constant: '<S4>/Constant2'
       */

      /* S-Function Block: <S4>/Packet Output */
      {
        uint8_T outdata[4U];
        RTWin_ANYTYPEPTR outdp;
        outdp.p_uint8_T = outdata;

        {
          real_T pktin = (AeroPendulum_P.Constant1_Value[0]);
          int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
            MIN_int8_T : (int8_T) pktin);
          *outdp.p_int8_T++ = pktout;
        }

        {
          real_T pktin = (AeroPendulum_P.Constant1_Value[1]);
          int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
            MIN_int8_T : (int8_T) pktin);
          *outdp.p_int8_T++ = pktout;
        }

        {
          real_T pktin = (AeroPendulum_P.Constant2_Value[0]);
          int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
            MIN_int8_T : (int8_T) pktin);
          *outdp.p_int8_T++ = pktout;
        }

        {
          real_T pktin = (AeroPendulum_P.Constant2_Value[1]);
          int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
            MIN_int8_T : (int8_T) pktin);
          *outdp.p_int8_T++ = pktout;
        }

        RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 4U,
                       &AeroPendulum_P.PacketOutput_PacketID, (double*) outdata,
                       NULL);
      }
    }

    /* End of Update for SubSystem: '<S1>/Enabled Subsystem' */

    /* Update for Enabled SubSystem: '<S1>/Enabled Subsystem2' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    if (AeroPendulum_B.Gain1 > 0.0) {
      /* Update for S-Function (sldrtpo): '<S5>/Packet Output' incorporates:
       *  Constant: '<S5>/Constant1'
       *  Constant: '<S5>/Constant2'
       */

      /* S-Function Block: <S5>/Packet Output */
      {
        uint8_T outdata[12U];
        RTWin_ANYTYPEPTR outdp;
        outdp.p_uint8_T = outdata;

        {
          real_T pktin = (AeroPendulum_P.Constant2_Value_m[0]);
          int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
            MIN_int8_T : (int8_T) pktin);
          *outdp.p_int8_T++ = pktout;
        }

        {
          real_T pktin = (AeroPendulum_P.Constant2_Value_m[1]);
          int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
            MIN_int8_T : (int8_T) pktin);
          *outdp.p_int8_T++ = pktout;
        }

        {
          real_T pktout = AeroPendulum_B.OFF;
          *outdp.p_real_T++ = pktout;
        }

        {
          real_T pktin = (AeroPendulum_P.Constant1_Value_h[0]);
          int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
            MIN_int8_T : (int8_T) pktin);
          *outdp.p_int8_T++ = pktout;
        }

        {
          real_T pktin = (AeroPendulum_P.Constant1_Value_h[1]);
          int8_T pktout = pktin>=MAX_int8_T ? MAX_int8_T : (pktin<=MIN_int8_T ?
            MIN_int8_T : (int8_T) pktin);
          *outdp.p_int8_T++ = pktout;
        }

        RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 12U,
                       &AeroPendulum_P.PacketOutput_PacketID_m, (double*)
                       outdata, NULL);
      }
    }

    /* End of Update for SubSystem: '<S1>/Enabled Subsystem2' */
  }

  if (rtmIsMajorTimeStep(AeroPendulum_M)) {
    rt_ertODEUpdateContinuousStates(&AeroPendulum_M->solverInfo);
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
  if (!(++AeroPendulum_M->Timing.clockTick0)) {
    ++AeroPendulum_M->Timing.clockTickH0;
  }

  AeroPendulum_M->Timing.t[0] = rtsiGetSolverStopTime
    (&AeroPendulum_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.025s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++AeroPendulum_M->Timing.clockTick1)) {
      ++AeroPendulum_M->Timing.clockTickH1;
    }

    AeroPendulum_M->Timing.t[1] = AeroPendulum_M->Timing.clockTick1 *
      AeroPendulum_M->Timing.stepSize1 + AeroPendulum_M->Timing.clockTickH1 *
      AeroPendulum_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void AeroPendulum_derivatives(void)
{
  XDot_AeroPendulum_T *_rtXdot;
  _rtXdot = ((XDot_AeroPendulum_T *) AeroPendulum_M->derivs);

  /* Derivatives for Integrator: '<S37>/Integrator' */
  _rtXdot->Integrator_CSTATE = AeroPendulum_B.IProdOut;

  /* Derivatives for Integrator: '<S32>/Filter' */
  _rtXdot->Filter_CSTATE = AeroPendulum_B.NProdOut;
}

/* Model initialize function */
void AeroPendulum_initialize(void)
{
  /* Start for Enabled SubSystem: '<S1>/Enabled Subsystem' */

  /* Start for S-Function (sldrtpo): '<S4>/Packet Output' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */

  /* S-Function Block: <S4>/Packet Output */
  /* no initial value should be set */

  /* End of Start for SubSystem: '<S1>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S1>/Enabled Subsystem2' */

  /* Start for S-Function (sldrtpo): '<S5>/Packet Output' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* S-Function Block: <S5>/Packet Output */
  /* no initial value should be set */

  /* End of Start for SubSystem: '<S1>/Enabled Subsystem2' */

  /* InitializeConditions for DiscreteFir: '<S1>/Discrete FIR Filter1' */
  AeroPendulum_DW.DiscreteFIRFilter1_circBuf = 0;
  AeroPendulum_DW.DiscreteFIRFilter1_states =
    AeroPendulum_P.DiscreteFIRFilter1_InitialStates;

  /* InitializeConditions for Integrator: '<S37>/Integrator' */
  AeroPendulum_X.Integrator_CSTATE =
    AeroPendulum_P.PIDController_InitialConditionForIntegrator;

  /* InitializeConditions for Integrator: '<S32>/Filter' */
  AeroPendulum_X.Filter_CSTATE =
    AeroPendulum_P.PIDController_InitialConditionForFilter;

  /* InitializeConditions for Memory: '<S1>/Memory' */
  AeroPendulum_DW.Memory_PreviousInput = AeroPendulum_P.Memory_InitialCondition;
}

/* Model terminate function */
void AeroPendulum_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S1>/Enabled Subsystem' */

  /* Terminate for S-Function (sldrtpo): '<S4>/Packet Output' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */

  /* S-Function Block: <S4>/Packet Output */
  /* no initial value should be set */

  /* End of Terminate for SubSystem: '<S1>/Enabled Subsystem' */

  /* Terminate for Enabled SubSystem: '<S1>/Enabled Subsystem2' */

  /* Terminate for S-Function (sldrtpo): '<S5>/Packet Output' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   */

  /* S-Function Block: <S5>/Packet Output */
  /* no initial value should be set */

  /* End of Terminate for SubSystem: '<S1>/Enabled Subsystem2' */
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
  AeroPendulum_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  AeroPendulum_update();
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
  AeroPendulum_initialize();
}

void MdlTerminate(void)
{
  AeroPendulum_terminate();
}

/* Registration function */
RT_MODEL_AeroPendulum_T *AeroPendulum(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)AeroPendulum_M, 0,
                sizeof(RT_MODEL_AeroPendulum_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&AeroPendulum_M->solverInfo,
                          &AeroPendulum_M->Timing.simTimeStep);
    rtsiSetTPtr(&AeroPendulum_M->solverInfo, &rtmGetTPtr(AeroPendulum_M));
    rtsiSetStepSizePtr(&AeroPendulum_M->solverInfo,
                       &AeroPendulum_M->Timing.stepSize0);
    rtsiSetdXPtr(&AeroPendulum_M->solverInfo, &AeroPendulum_M->derivs);
    rtsiSetContStatesPtr(&AeroPendulum_M->solverInfo, (real_T **)
                         &AeroPendulum_M->contStates);
    rtsiSetNumContStatesPtr(&AeroPendulum_M->solverInfo,
      &AeroPendulum_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&AeroPendulum_M->solverInfo,
      &AeroPendulum_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&AeroPendulum_M->solverInfo,
      &AeroPendulum_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&AeroPendulum_M->solverInfo,
      &AeroPendulum_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&AeroPendulum_M->solverInfo, (&rtmGetErrorStatus
      (AeroPendulum_M)));
    rtsiSetRTModelPtr(&AeroPendulum_M->solverInfo, AeroPendulum_M);
  }

  rtsiSetSimTimeStep(&AeroPendulum_M->solverInfo, MAJOR_TIME_STEP);
  AeroPendulum_M->intgData.y = AeroPendulum_M->odeY;
  AeroPendulum_M->intgData.f[0] = AeroPendulum_M->odeF[0];
  AeroPendulum_M->intgData.f[1] = AeroPendulum_M->odeF[1];
  AeroPendulum_M->intgData.f[2] = AeroPendulum_M->odeF[2];
  AeroPendulum_M->intgData.f[3] = AeroPendulum_M->odeF[3];
  AeroPendulum_M->intgData.f[4] = AeroPendulum_M->odeF[4];
  AeroPendulum_M->intgData.f[5] = AeroPendulum_M->odeF[5];
  AeroPendulum_M->contStates = ((real_T *) &AeroPendulum_X);
  rtsiSetSolverData(&AeroPendulum_M->solverInfo, (void *)
                    &AeroPendulum_M->intgData);
  rtsiSetSolverName(&AeroPendulum_M->solverInfo,"ode5");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = AeroPendulum_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    AeroPendulum_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    AeroPendulum_M->Timing.sampleTimes =
      (&AeroPendulum_M->Timing.sampleTimesArray[0]);
    AeroPendulum_M->Timing.offsetTimes =
      (&AeroPendulum_M->Timing.offsetTimesArray[0]);

    /* task periods */
    AeroPendulum_M->Timing.sampleTimes[0] = (0.0);
    AeroPendulum_M->Timing.sampleTimes[1] = (0.025);

    /* task offsets */
    AeroPendulum_M->Timing.offsetTimes[0] = (0.0);
    AeroPendulum_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(AeroPendulum_M, &AeroPendulum_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = AeroPendulum_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    AeroPendulum_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(AeroPendulum_M, -1);
  AeroPendulum_M->Timing.stepSize0 = 0.025;
  AeroPendulum_M->Timing.stepSize1 = 0.025;

  /* External mode info */
  AeroPendulum_M->Sizes.checksums[0] = (3759554766U);
  AeroPendulum_M->Sizes.checksums[1] = (883985094U);
  AeroPendulum_M->Sizes.checksums[2] = (1094181789U);
  AeroPendulum_M->Sizes.checksums[3] = (3668168831U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    AeroPendulum_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&AeroPendulum_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&AeroPendulum_DW.EnabledSubsystem2_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(AeroPendulum_M->extModeInfo,
      &AeroPendulum_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AeroPendulum_M->extModeInfo,
                        AeroPendulum_M->Sizes.checksums);
    rteiSetTPtr(AeroPendulum_M->extModeInfo, rtmGetTPtr(AeroPendulum_M));
  }

  AeroPendulum_M->solverInfoPtr = (&AeroPendulum_M->solverInfo);
  AeroPendulum_M->Timing.stepSize = (0.025);
  rtsiSetFixedStepSize(&AeroPendulum_M->solverInfo, 0.025);
  rtsiSetSolverMode(&AeroPendulum_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  AeroPendulum_M->blockIO = ((void *) &AeroPendulum_B);
  (void) memset(((void *) &AeroPendulum_B), 0,
                sizeof(B_AeroPendulum_T));

  /* parameters */
  AeroPendulum_M->defaultParam = ((real_T *)&AeroPendulum_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &AeroPendulum_X;
    AeroPendulum_M->contStates = (x);
    (void) memset((void *)&AeroPendulum_X, 0,
                  sizeof(X_AeroPendulum_T));
  }

  /* states (dwork) */
  AeroPendulum_M->dwork = ((void *) &AeroPendulum_DW);
  (void) memset((void *)&AeroPendulum_DW, 0,
                sizeof(DW_AeroPendulum_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    AeroPendulum_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  AeroPendulum_M->Sizes.numContStates = (2);/* Number of continuous states */
  AeroPendulum_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  AeroPendulum_M->Sizes.numY = (0);    /* Number of model outputs */
  AeroPendulum_M->Sizes.numU = (0);    /* Number of model inputs */
  AeroPendulum_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  AeroPendulum_M->Sizes.numSampTimes = (2);/* Number of sample times */
  AeroPendulum_M->Sizes.numBlocks = (47);/* Number of blocks */
  AeroPendulum_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  AeroPendulum_M->Sizes.numBlockPrms = (44);/* Sum of parameter "widths" */
  return AeroPendulum_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
