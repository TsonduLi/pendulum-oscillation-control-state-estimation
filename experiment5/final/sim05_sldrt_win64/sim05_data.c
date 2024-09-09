/*
 * sim05_data.c
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

/* Block parameters (default storage) */
P_sim05_T sim05_P = {
  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_InputFilter
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_InputFilter
   * Referenced by: '<Root>/Encoder Input1'
   */
  0.0,

  /* Mask Parameter: EncoderInput_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input'
   */
  10.0,

  /* Mask Parameter: EncoderInput1_MaxMissedTicks
   * Referenced by: '<Root>/Encoder Input1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<Root>/Analog Output'
   */
  10.0,

  /* Mask Parameter: EncoderInput_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input'
   */
  0.0,

  /* Mask Parameter: EncoderInput1_YieldWhenWaiting
   * Referenced by: '<Root>/Encoder Input1'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Output'
   */
  0.0,

  /* Mask Parameter: EncoderInput_Channels
   * Referenced by: '<Root>/Encoder Input'
   */
  0,

  /* Mask Parameter: EncoderInput1_Channels
   * Referenced by: '<Root>/Encoder Input1'
   */
  1,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<Root>/Analog Output'
   */
  1,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<Root>/Analog Output'
   */
  0,

  /* Expression: 0.025
   * Referenced by: '<Root>/Gain2'
   */
  0.025,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant3'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { -48.0, -900.0 },

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { 0.0, 900.0 },

  /* Computed Parameter: Internal_A
   * Referenced by: '<S1>/Internal'
   */
  { -201.47489194050058, -18.436149256257405, 16.0 },

  /* Computed Parameter: Internal_B
   * Referenced by: '<S1>/Internal'
   */
  8.0,

  /* Computed Parameter: Internal_C
   * Referenced by: '<S1>/Internal'
   */
  { -9.0784928013085828, -6.34609375 },

  /* Expression: 0.0
   * Referenced by: '<S1>/Internal'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/On//off'
   */
  0.0,

  /* Expression: 360/9000
   * Referenced by: '<Root>/Gain Arm'
   */
  0.04,

  /* Expression: 1
   * Referenced by: '<Root>/Gain1'
   */
  1.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  { -23.680000000000003, -0.0 },

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  { -0.67716640000000017, 0.2738 },

  /* Computed Parameter: TransferFcn1_D
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  0.04048,

  /* Computed Parameter: TransferFcn4_A
   * Referenced by: '<Root>/Transfer Fcn4'
   */
  { -45.800000000000004, -0.0 },

  /* Computed Parameter: TransferFcn4_C
   * Referenced by: '<Root>/Transfer Fcn4'
   */
  { -4.5759000000000007, 2.281 },

  /* Computed Parameter: TransferFcn4_D
   * Referenced by: '<Root>/Transfer Fcn4'
   */
  0.1305,

  /* Expression: 90
   * Referenced by: '<Root>/Constant1'
   */
  90.0,

  /* Expression: 1
   * Referenced by: '<Root>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Saturation'
   */
  -1.0,

  /* Expression: 10
   * Referenced by: '<Root>/Gain'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 360/2000
   * Referenced by: '<Root>/Gain Pendulum'
   */
  0.18,

  /* Expression: 0
   * Referenced by: '<Root>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant6'
   */
  0.0
};
