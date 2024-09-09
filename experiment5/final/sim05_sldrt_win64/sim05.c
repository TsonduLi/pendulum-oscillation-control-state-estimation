/*
 * sim05.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sim05".
 *
 * Model version              : 1.11
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Mon Jun 12 15:51:32 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sim05.h"
#include "sim05_private.h"
#include "sim05_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  0.0,
  0.0,
  0.0,
  2.0,
  2.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6221", 4294967295U, 5, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_sim05_T sim05_B;

/* Continuous states */
X_sim05_T sim05_X;

/* Block states (default storage) */
DW_sim05_T sim05_DW;

/* Real-time model */
RT_MODEL_sim05_T sim05_M_;
RT_MODEL_sim05_T *const sim05_M = &sim05_M_;

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
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  sim05_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  sim05_output();
  sim05_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  sim05_output();
  sim05_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  sim05_output();
  sim05_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void sim05_output(void)
{
  /* local block i/o variables */
  real_T rtb_EncoderInput1;
  real_T rtb_Abs;
  real_T rtb_Saturation;
  if (rtmIsMajorTimeStep(sim05_M)) {
    /* set solver stop time */
    if (!(sim05_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&sim05_M->solverInfo, ((sim05_M->Timing.clockTickH0
        + 1) * sim05_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&sim05_M->solverInfo, ((sim05_M->Timing.clockTick0 +
        1) * sim05_M->Timing.stepSize0 + sim05_M->Timing.clockTickH0 *
        sim05_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(sim05_M)) {
    sim05_M->Timing.t[0] = rtsiGetT(&sim05_M->solverInfo);
  }

  /* Gain: '<Root>/On//off' incorporates:
   *  StateSpace: '<S1>/Internal'
   */
  sim05_B.Onoff = (sim05_P.Internal_C[0] * sim05_X.Internal_CSTATE[0] +
                   sim05_P.Internal_C[1] * sim05_X.Internal_CSTATE[1]) *
    sim05_P.Onoff_Gain;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  TransferFcn: '<Root>/Transfer Fcn'
   */
  sim05_B.Sum1 = ((sim05_P.TransferFcn_C[0] * sim05_X.TransferFcn_CSTATE[0] +
                   sim05_P.TransferFcn_C[1] * sim05_X.TransferFcn_CSTATE[1]) +
                  sim05_P.Constant2_Value) + sim05_B.Onoff;
  if (rtmIsMajorTimeStep(sim05_M)) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = sim05_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &sim05_P.EncoderInput_Channels,
                     &rtb_Abs, &parm);
    }

    /* S-Function (sldrtei): '<Root>/Encoder Input1' */
    /* S-Function Block: <Root>/Encoder Input1 */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = sim05_P.EncoderInput1_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &sim05_P.EncoderInput1_Channels,
                     &rtb_EncoderInput1, &parm);
    }

    /* Gain: '<Root>/Gain Arm' */
    sim05_B.GainArm = sim05_P.GainArm_Gain * rtb_Abs;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Sum'
   */
  sim05_B.Gain1 = (sim05_B.Sum1 - sim05_B.GainArm) * sim05_P.Gain1_Gain;

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Gain: '<Root>/Gain2'
   *  TransferFcn: '<Root>/Transfer Fcn1'
   *  TransferFcn: '<Root>/Transfer Fcn4'
   */
  switch ((int32_T)sim05_P.Constant3_Value) {
   case 1:
    rtb_Saturation = sim05_P.Gain2_Gain * sim05_B.Gain1;
    break;

   case 2:
    rtb_Saturation = (sim05_P.TransferFcn1_C[0] * sim05_X.TransferFcn1_CSTATE[0]
                      + sim05_P.TransferFcn1_C[1] * sim05_X.TransferFcn1_CSTATE
                      [1]) + sim05_P.TransferFcn1_D * sim05_B.Gain1;
    break;

   default:
    rtb_Saturation = (sim05_P.TransferFcn4_C[0] * sim05_X.TransferFcn4_CSTATE[0]
                      + sim05_P.TransferFcn4_C[1] * sim05_X.TransferFcn4_CSTATE
                      [1]) + sim05_P.TransferFcn4_D * sim05_B.Gain1;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  sim05_B.Sum2 = sim05_P.Constant4_Value + rtb_Saturation;
  if (rtmIsMajorTimeStep(sim05_M)) {
    /* Abs: '<Root>/Abs' */
    rtb_Abs = fabs(sim05_B.GainArm);

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant1'
     *  RelationalOperator: '<Root>/Relational Operator'
     */
    sim05_B.DataTypeConversion = (rtb_Abs < sim05_P.Constant1_Value);
  }

  /* Product: '<Root>/Product' */
  rtb_Saturation = sim05_B.Sum2 * sim05_B.DataTypeConversion;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation > sim05_P.Saturation_UpperSat) {
    rtb_Saturation = sim05_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < sim05_P.Saturation_LowerSat) {
      rtb_Saturation = sim05_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain' */
  sim05_B.Gain = sim05_P.Gain_Gain * rtb_Saturation;
  if (rtmIsMajorTimeStep(sim05_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) sim05_P.AnalogOutput_RangeMode;
        parm.rangeidx = sim05_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &sim05_P.AnalogOutput_Channels, ((real_T*) (&sim05_B.Gain)),
                       &parm);
      }
    }

    /* Constant: '<Root>/Constant' */
    sim05_B.Constant = sim05_P.Constant_Value;

    /* Gain: '<Root>/Gain Pendulum' */
    sim05_B.GainPendulum = sim05_P.GainPendulum_Gain * rtb_EncoderInput1;

    /* Sum: '<Root>/Sum4' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Constant: '<Root>/Constant6'
     *  Sum: '<Root>/Sum3'
     */
    sim05_B.Sum4 = sim05_P.Constant6_Value - (sim05_B.GainPendulum -
      sim05_P.Constant5_Value);
  }
}

/* Model update function */
void sim05_update(void)
{
  if (rtmIsMajorTimeStep(sim05_M)) {
    rt_ertODEUpdateContinuousStates(&sim05_M->solverInfo);
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
  if (!(++sim05_M->Timing.clockTick0)) {
    ++sim05_M->Timing.clockTickH0;
  }

  sim05_M->Timing.t[0] = rtsiGetSolverStopTime(&sim05_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++sim05_M->Timing.clockTick1)) {
      ++sim05_M->Timing.clockTickH1;
    }

    sim05_M->Timing.t[1] = sim05_M->Timing.clockTick1 *
      sim05_M->Timing.stepSize1 + sim05_M->Timing.clockTickH1 *
      sim05_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void sim05_derivatives(void)
{
  XDot_sim05_T *_rtXdot;
  _rtXdot = ((XDot_sim05_T *) sim05_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += sim05_P.TransferFcn_A[0] *
    sim05_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += sim05_P.TransferFcn_A[1] *
    sim05_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += sim05_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += sim05_B.Constant;

  /* Derivatives for StateSpace: '<S1>/Internal' */
  _rtXdot->Internal_CSTATE[0] = 0.0;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += sim05_P.TransferFcn1_A[0] *
    sim05_X.TransferFcn1_CSTATE[0];

  /* Derivatives for StateSpace: '<S1>/Internal' */
  _rtXdot->Internal_CSTATE[1] = 0.0;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += sim05_P.TransferFcn1_A[1] *
    sim05_X.TransferFcn1_CSTATE[1];

  /* Derivatives for StateSpace: '<S1>/Internal' */
  _rtXdot->Internal_CSTATE[0] += sim05_P.Internal_A[0] *
    sim05_X.Internal_CSTATE[0];
  _rtXdot->Internal_CSTATE[0] += sim05_P.Internal_A[1] *
    sim05_X.Internal_CSTATE[1];
  _rtXdot->Internal_CSTATE[1] += sim05_P.Internal_A[2] *
    sim05_X.Internal_CSTATE[0];
  _rtXdot->Internal_CSTATE[0] += sim05_P.Internal_B * sim05_B.Sum4;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[1] += sim05_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += sim05_B.Gain1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn4' */
  _rtXdot->TransferFcn4_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn4_CSTATE[0] += sim05_P.TransferFcn4_A[0] *
    sim05_X.TransferFcn4_CSTATE[0];
  _rtXdot->TransferFcn4_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn4_CSTATE[0] += sim05_P.TransferFcn4_A[1] *
    sim05_X.TransferFcn4_CSTATE[1];
  _rtXdot->TransferFcn4_CSTATE[1] += sim05_X.TransferFcn4_CSTATE[0];
  _rtXdot->TransferFcn4_CSTATE[0] += sim05_B.Gain1;
}

/* Model initialize function */
void sim05_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) sim05_P.AnalogOutput_RangeMode;
      parm.rangeidx = sim05_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &sim05_P.AnalogOutput_Channels,
                     &sim05_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  sim05_X.TransferFcn_CSTATE[0] = 0.0;

  /* InitializeConditions for StateSpace: '<S1>/Internal' */
  sim05_X.Internal_CSTATE[0] = sim05_P.Internal_InitialCondition;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  sim05_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for StateSpace: '<S1>/Internal' */
  sim05_X.Internal_CSTATE[1] = sim05_P.Internal_InitialCondition;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = sim05_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &sim05_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input1' */

  /* S-Function Block: <Root>/Encoder Input1 */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = sim05_P.EncoderInput1_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &sim05_P.EncoderInput1_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  sim05_X.TransferFcn1_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn4' */
  sim05_X.TransferFcn4_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  sim05_X.TransferFcn1_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn4' */
  sim05_X.TransferFcn4_CSTATE[1] = 0.0;
}

/* Model terminate function */
void sim05_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) sim05_P.AnalogOutput_RangeMode;
      parm.rangeidx = sim05_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &sim05_P.AnalogOutput_Channels,
                     &sim05_P.AnalogOutput_FinalValue, &parm);
    }
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
  sim05_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  sim05_update();
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
  sim05_initialize();
}

void MdlTerminate(void)
{
  sim05_terminate();
}

/* Registration function */
RT_MODEL_sim05_T *sim05(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  sim05_P.EncoderInput_InputFilter = rtInf;
  sim05_P.EncoderInput1_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)sim05_M, 0,
                sizeof(RT_MODEL_sim05_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sim05_M->solverInfo, &sim05_M->Timing.simTimeStep);
    rtsiSetTPtr(&sim05_M->solverInfo, &rtmGetTPtr(sim05_M));
    rtsiSetStepSizePtr(&sim05_M->solverInfo, &sim05_M->Timing.stepSize0);
    rtsiSetdXPtr(&sim05_M->solverInfo, &sim05_M->derivs);
    rtsiSetContStatesPtr(&sim05_M->solverInfo, (real_T **) &sim05_M->contStates);
    rtsiSetNumContStatesPtr(&sim05_M->solverInfo, &sim05_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&sim05_M->solverInfo,
      &sim05_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&sim05_M->solverInfo,
      &sim05_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&sim05_M->solverInfo,
      &sim05_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&sim05_M->solverInfo, (&rtmGetErrorStatus(sim05_M)));
    rtsiSetRTModelPtr(&sim05_M->solverInfo, sim05_M);
  }

  rtsiSetSimTimeStep(&sim05_M->solverInfo, MAJOR_TIME_STEP);
  sim05_M->intgData.y = sim05_M->odeY;
  sim05_M->intgData.f[0] = sim05_M->odeF[0];
  sim05_M->intgData.f[1] = sim05_M->odeF[1];
  sim05_M->intgData.f[2] = sim05_M->odeF[2];
  sim05_M->intgData.f[3] = sim05_M->odeF[3];
  sim05_M->contStates = ((real_T *) &sim05_X);
  rtsiSetSolverData(&sim05_M->solverInfo, (void *)&sim05_M->intgData);
  rtsiSetSolverName(&sim05_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = sim05_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    sim05_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    sim05_M->Timing.sampleTimes = (&sim05_M->Timing.sampleTimesArray[0]);
    sim05_M->Timing.offsetTimes = (&sim05_M->Timing.offsetTimesArray[0]);

    /* task periods */
    sim05_M->Timing.sampleTimes[0] = (0.0);
    sim05_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    sim05_M->Timing.offsetTimes[0] = (0.0);
    sim05_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(sim05_M, &sim05_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = sim05_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    sim05_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(sim05_M, -1);
  sim05_M->Timing.stepSize0 = 0.001;
  sim05_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  sim05_M->Sizes.checksums[0] = (1516413014U);
  sim05_M->Sizes.checksums[1] = (4001749507U);
  sim05_M->Sizes.checksums[2] = (1072173849U);
  sim05_M->Sizes.checksums[3] = (2883279561U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    sim05_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(sim05_M->extModeInfo,
      &sim05_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sim05_M->extModeInfo, sim05_M->Sizes.checksums);
    rteiSetTPtr(sim05_M->extModeInfo, rtmGetTPtr(sim05_M));
  }

  sim05_M->solverInfoPtr = (&sim05_M->solverInfo);
  sim05_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&sim05_M->solverInfo, 0.001);
  rtsiSetSolverMode(&sim05_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  sim05_M->blockIO = ((void *) &sim05_B);
  (void) memset(((void *) &sim05_B), 0,
                sizeof(B_sim05_T));

  /* parameters */
  sim05_M->defaultParam = ((real_T *)&sim05_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &sim05_X;
    sim05_M->contStates = (x);
    (void) memset((void *)&sim05_X, 0,
                  sizeof(X_sim05_T));
  }

  /* states (dwork) */
  sim05_M->dwork = ((void *) &sim05_DW);
  (void) memset((void *)&sim05_DW, 0,
                sizeof(DW_sim05_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sim05_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  sim05_M->Sizes.numContStates = (8);  /* Number of continuous states */
  sim05_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  sim05_M->Sizes.numY = (0);           /* Number of model outputs */
  sim05_M->Sizes.numU = (0);           /* Number of model inputs */
  sim05_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  sim05_M->Sizes.numSampTimes = (2);   /* Number of sample times */
  sim05_M->Sizes.numBlocks = (40);     /* Number of blocks */
  sim05_M->Sizes.numBlockIO = (10);    /* Number of block outputs */
  sim05_M->Sizes.numBlockPrms = (51);  /* Sum of parameter "widths" */
  return sim05_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
