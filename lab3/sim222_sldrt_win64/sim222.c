/*
 * sim222.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sim222".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Mon May 15 15:53:57 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sim222.h"
#include "sim222_private.h"
#include "sim222_dt.h"

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
B_sim222_T sim222_B;

/* Continuous states */
X_sim222_T sim222_X;

/* Block states (default storage) */
DW_sim222_T sim222_DW;

/* Real-time model */
RT_MODEL_sim222_T sim222_M_;
RT_MODEL_sim222_T *const sim222_M = &sim222_M_;

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  sim222_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  sim222_output();
  sim222_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  sim222_output();
  sim222_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  sim222_output();
  sim222_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void sim222_output(void)
{
  /* local block i/o variables */
  real_T rtb_Abs;
  real_T u0;
  if (rtmIsMajorTimeStep(sim222_M)) {
    /* set solver stop time */
    if (!(sim222_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&sim222_M->solverInfo,
                            ((sim222_M->Timing.clockTickH0 + 1) *
        sim222_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&sim222_M->solverInfo, ((sim222_M->Timing.clockTick0
        + 1) * sim222_M->Timing.stepSize0 + sim222_M->Timing.clockTickH0 *
        sim222_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(sim222_M)) {
    sim222_M->Timing.t[0] = rtsiGetT(&sim222_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  sim222_B.TransferFcn = 0.0;
  sim222_B.TransferFcn += sim222_P.TransferFcn_C[0] *
    sim222_X.TransferFcn_CSTATE[0];
  sim222_B.TransferFcn += sim222_P.TransferFcn_C[1] *
    sim222_X.TransferFcn_CSTATE[1];
  if (rtmIsMajorTimeStep(sim222_M)) {
    /* S-Function (sldrtei): '<Root>/Encoder Input' */
    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 0;
      parm.infilter = sim222_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1, &sim222_P.EncoderInput_Channels,
                     &rtb_Abs, &parm);
    }

    /* Gain: '<Root>/Gain Arm' */
    sim222_B.GainArm = sim222_P.GainArm_Gain * rtb_Abs;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Sum'
   */
  sim222_B.Gain1 = (sim222_B.TransferFcn - sim222_B.GainArm) *
    sim222_P.Gain1_Gain;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn1'
   *  TransferFcn: '<Root>/Transfer Fcn4'
   */
  if (sim222_P.ManualSwitch_CurrentSetting == 1) {
    sim222_B.ManualSwitch = (sim222_P.TransferFcn1_C[0] *
      sim222_X.TransferFcn1_CSTATE[0] + sim222_P.TransferFcn1_C[1] *
      sim222_X.TransferFcn1_CSTATE[1]) + sim222_P.TransferFcn1_D *
      sim222_B.Gain1;
  } else {
    sim222_B.ManualSwitch = (sim222_P.TransferFcn4_C[0] *
      sim222_X.TransferFcn4_CSTATE[0] + sim222_P.TransferFcn4_C[1] *
      sim222_X.TransferFcn4_CSTATE[1]) + sim222_P.TransferFcn4_D *
      sim222_B.Gain1;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */
  if (rtmIsMajorTimeStep(sim222_M)) {
    /* Abs: '<Root>/Abs' */
    rtb_Abs = fabs(sim222_B.GainArm);

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant1'
     *  RelationalOperator: '<Root>/Relational Operator'
     */
    sim222_B.DataTypeConversion = (rtb_Abs < sim222_P.Constant1_Value);
  }

  /* Product: '<Root>/Product' */
  u0 = sim222_B.ManualSwitch * sim222_B.DataTypeConversion;

  /* Saturate: '<Root>/Saturation' */
  if (u0 > sim222_P.Saturation_UpperSat) {
    u0 = sim222_P.Saturation_UpperSat;
  } else {
    if (u0 < sim222_P.Saturation_LowerSat) {
      u0 = sim222_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Gain' */
  sim222_B.Gain = sim222_P.Gain_Gain * u0;
  if (rtmIsMajorTimeStep(sim222_M)) {
    /* S-Function (sldrtao): '<Root>/Analog Output' */
    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) sim222_P.AnalogOutput_RangeMode;
        parm.rangeidx = sim222_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &sim222_P.AnalogOutput_Channels, ((real_T*)
          (&sim222_B.Gain)), &parm);
      }
    }

    /* Constant: '<Root>/Constant' */
    sim222_B.Constant = sim222_P.Constant_Value;
  }
}

/* Model update function */
void sim222_update(void)
{
  if (rtmIsMajorTimeStep(sim222_M)) {
    rt_ertODEUpdateContinuousStates(&sim222_M->solverInfo);
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
  if (!(++sim222_M->Timing.clockTick0)) {
    ++sim222_M->Timing.clockTickH0;
  }

  sim222_M->Timing.t[0] = rtsiGetSolverStopTime(&sim222_M->solverInfo);

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
    if (!(++sim222_M->Timing.clockTick1)) {
      ++sim222_M->Timing.clockTickH1;
    }

    sim222_M->Timing.t[1] = sim222_M->Timing.clockTick1 *
      sim222_M->Timing.stepSize1 + sim222_M->Timing.clockTickH1 *
      sim222_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void sim222_derivatives(void)
{
  XDot_sim222_T *_rtXdot;
  _rtXdot = ((XDot_sim222_T *) sim222_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += sim222_P.TransferFcn_A[0] *
    sim222_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn_CSTATE[0] += sim222_P.TransferFcn_A[1] *
    sim222_X.TransferFcn_CSTATE[1];
  _rtXdot->TransferFcn_CSTATE[1] += sim222_X.TransferFcn_CSTATE[0];
  _rtXdot->TransferFcn_CSTATE[0] += sim222_B.Constant;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += sim222_P.TransferFcn1_A[0] *
    sim222_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += sim222_P.TransferFcn1_A[1] *
    sim222_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += sim222_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += sim222_B.Gain1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn4' */
  _rtXdot->TransferFcn4_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn4_CSTATE[0] += sim222_P.TransferFcn4_A[0] *
    sim222_X.TransferFcn4_CSTATE[0];
  _rtXdot->TransferFcn4_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn4_CSTATE[0] += sim222_P.TransferFcn4_A[1] *
    sim222_X.TransferFcn4_CSTATE[1];
  _rtXdot->TransferFcn4_CSTATE[1] += sim222_X.TransferFcn4_CSTATE[0];
  _rtXdot->TransferFcn4_CSTATE[0] += sim222_B.Gain1;
}

/* Model initialize function */
void sim222_initialize(void)
{
  /* Start for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) sim222_P.AnalogOutput_RangeMode;
      parm.rangeidx = sim222_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &sim222_P.AnalogOutput_Channels,
                     &sim222_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  sim222_X.TransferFcn_CSTATE[0] = 0.0;
  sim222_X.TransferFcn_CSTATE[1] = 0.0;

  /* InitializeConditions for S-Function (sldrtei): '<Root>/Encoder Input' */

  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 0;
    parm.infilter = sim222_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &sim222_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  sim222_X.TransferFcn1_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn4' */
  sim222_X.TransferFcn4_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  sim222_X.TransferFcn1_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn4' */
  sim222_X.TransferFcn4_CSTATE[1] = 0.0;
}

/* Model terminate function */
void sim222_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<Root>/Analog Output' */

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) sim222_P.AnalogOutput_RangeMode;
      parm.rangeidx = sim222_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &sim222_P.AnalogOutput_Channels,
                     &sim222_P.AnalogOutput_FinalValue, &parm);
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
  sim222_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  sim222_update();
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
  sim222_initialize();
}

void MdlTerminate(void)
{
  sim222_terminate();
}

/* Registration function */
RT_MODEL_sim222_T *sim222(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  sim222_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)sim222_M, 0,
                sizeof(RT_MODEL_sim222_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sim222_M->solverInfo, &sim222_M->Timing.simTimeStep);
    rtsiSetTPtr(&sim222_M->solverInfo, &rtmGetTPtr(sim222_M));
    rtsiSetStepSizePtr(&sim222_M->solverInfo, &sim222_M->Timing.stepSize0);
    rtsiSetdXPtr(&sim222_M->solverInfo, &sim222_M->derivs);
    rtsiSetContStatesPtr(&sim222_M->solverInfo, (real_T **)
                         &sim222_M->contStates);
    rtsiSetNumContStatesPtr(&sim222_M->solverInfo,
      &sim222_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&sim222_M->solverInfo,
      &sim222_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&sim222_M->solverInfo,
      &sim222_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&sim222_M->solverInfo,
      &sim222_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&sim222_M->solverInfo, (&rtmGetErrorStatus(sim222_M)));
    rtsiSetRTModelPtr(&sim222_M->solverInfo, sim222_M);
  }

  rtsiSetSimTimeStep(&sim222_M->solverInfo, MAJOR_TIME_STEP);
  sim222_M->intgData.y = sim222_M->odeY;
  sim222_M->intgData.f[0] = sim222_M->odeF[0];
  sim222_M->intgData.f[1] = sim222_M->odeF[1];
  sim222_M->intgData.f[2] = sim222_M->odeF[2];
  sim222_M->intgData.f[3] = sim222_M->odeF[3];
  sim222_M->contStates = ((real_T *) &sim222_X);
  rtsiSetSolverData(&sim222_M->solverInfo, (void *)&sim222_M->intgData);
  rtsiSetSolverName(&sim222_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = sim222_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    sim222_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    sim222_M->Timing.sampleTimes = (&sim222_M->Timing.sampleTimesArray[0]);
    sim222_M->Timing.offsetTimes = (&sim222_M->Timing.offsetTimesArray[0]);

    /* task periods */
    sim222_M->Timing.sampleTimes[0] = (0.0);
    sim222_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    sim222_M->Timing.offsetTimes[0] = (0.0);
    sim222_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(sim222_M, &sim222_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = sim222_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    sim222_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(sim222_M, -1);
  sim222_M->Timing.stepSize0 = 0.001;
  sim222_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  sim222_M->Sizes.checksums[0] = (999295750U);
  sim222_M->Sizes.checksums[1] = (4062643646U);
  sim222_M->Sizes.checksums[2] = (3612022183U);
  sim222_M->Sizes.checksums[3] = (3275223270U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    sim222_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(sim222_M->extModeInfo,
      &sim222_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sim222_M->extModeInfo, sim222_M->Sizes.checksums);
    rteiSetTPtr(sim222_M->extModeInfo, rtmGetTPtr(sim222_M));
  }

  sim222_M->solverInfoPtr = (&sim222_M->solverInfo);
  sim222_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&sim222_M->solverInfo, 0.001);
  rtsiSetSolverMode(&sim222_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  sim222_M->blockIO = ((void *) &sim222_B);
  (void) memset(((void *) &sim222_B), 0,
                sizeof(B_sim222_T));

  /* parameters */
  sim222_M->defaultParam = ((real_T *)&sim222_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &sim222_X;
    sim222_M->contStates = (x);
    (void) memset((void *)&sim222_X, 0,
                  sizeof(X_sim222_T));
  }

  /* states (dwork) */
  sim222_M->dwork = ((void *) &sim222_DW);
  (void) memset((void *)&sim222_DW, 0,
                sizeof(DW_sim222_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sim222_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  sim222_M->Sizes.numContStates = (6); /* Number of continuous states */
  sim222_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  sim222_M->Sizes.numY = (0);          /* Number of model outputs */
  sim222_M->Sizes.numU = (0);          /* Number of model inputs */
  sim222_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  sim222_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  sim222_M->Sizes.numBlocks = (22);    /* Number of blocks */
  sim222_M->Sizes.numBlockIO = (7);    /* Number of block outputs */
  sim222_M->Sizes.numBlockPrms = (33); /* Sum of parameter "widths" */
  return sim222_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
