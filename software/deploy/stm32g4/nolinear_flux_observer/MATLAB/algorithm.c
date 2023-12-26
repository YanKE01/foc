/*
 * File: algorithm.c
 *
 * Code generated for Simulink model 'algorithm'.
 *
 * Model version                  : 4.33
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Dec 26 09:27:59 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "algorithm.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>
#include <stddef.h>
#include "arm_math.h"

/* Named constants for Chart: '<S3>/Chart1' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_OpenStage                   ((uint8_T)3U)
#define IN_RunStage                    ((uint8_T)4U)
#define IN_ThetaAlign                  ((uint8_T)5U)
#define NumBitsPerChar                 8U
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Exported block signals */
real32_T smo_we;                       /* '<S14>/Gain6' */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real32_T rt_modf_snf(real32_T u0, real32_T u1);
static void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                  real32_T rty_tABC[3]);

/* Forward declaration for local functions */
static void SystemCore_setup(dsp_simulink_MovingAverage *obj);
static void rate_scheduler(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Output and update for atomic system: '<S3>/SVPWM' */
static void SVPWM(real32_T rtu_Valpha, real32_T rtu_Vbeta, real32_T rtu_v_bus,
                  real32_T rty_tABC[3])
{
  real32_T rtb_Min;
  real32_T rtb_Sum1_c;
  real32_T rtb_Sum_a;

  /* Gain: '<S21>/Gain' */
  rtb_Min = -0.5F * rtu_Valpha;

  /* Gain: '<S21>/Gain1' */
  rtb_Sum1_c = 0.866025388F * rtu_Vbeta;

  /* Sum: '<S21>/Sum' */
  rtb_Sum_a = rtb_Min + rtb_Sum1_c;

  /* Sum: '<S21>/Sum1' */
  rtb_Sum1_c = rtb_Min - rtb_Sum1_c;

  /* Gain: '<S22>/Gain' incorporates:
   *  MinMax: '<S22>/Min'
   *  MinMax: '<S22>/Min1'
   *  Sum: '<S22>/Sum'
   */
  rtb_Min = (fminf(fminf(rtu_Valpha, rtb_Sum_a), rtb_Sum1_c) + fmaxf(fmaxf
              (rtu_Valpha, rtb_Sum_a), rtb_Sum1_c)) * -0.5F;

  /* Sum: '<S13>/Sum' */
  rty_tABC[0] = rtb_Min + rtu_Valpha;
  rty_tABC[1] = rtb_Min + rtb_Sum_a;
  rty_tABC[2] = rtb_Min + rtb_Sum1_c;

  /* Gain: '<S13>/PWM_HalfPeriod' incorporates:
   *  Constant: '<S13>/Constant'
   *  Gain: '<S13>/Gain'
   *  Product: '<S13>/Divide'
   *  Sum: '<S13>/Sum1'
   */
  rty_tABC[0] = (-rty_tABC[0] / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[1] = (-rty_tABC[1] / rtu_v_bus + 0.5F) * 8000.0F;
  rty_tABC[2] = (-rty_tABC[2] / rtu_v_bus + 0.5F) * 8000.0F;
}

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

static void SystemCore_setup(dsp_simulink_MovingAverage *obj)
{
  real32_T varargin_2;
  boolean_T flag;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  varargin_2 = obj->ForgettingFactor;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  flag = (obj->_pobj0.isInitialized == 1);
  if (flag) {
    obj->_pobj0.TunablePropsChanged = true;
  }

  obj->_pobj0.ForgettingFactor = varargin_2;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function */
void algorithm_step(void)
{
  g_dsp_internal_ExponentialMovin *obj;
  real_T rtb_Add1;
  real_T rtb_DeadZone;
  real_T rtb_IProdOut;
  real_T rtb_Sum;
  real32_T Integrator;
  real32_T pmLocal;
  real32_T rtb_Add1_j;
  real32_T rtb_Add3_f;
  real32_T rtb_Add4;
  real32_T rtb_Cos;
  real32_T rtb_DeadZone_b;
  real32_T rtb_Delay;
  real32_T rtb_Gain2_c;
  real32_T rtb_PLL_error;
  real32_T rtb_RateTransition1;
  real32_T rtb_Saturation;
  real32_T rtb_Saturation_k;
  uint32_T speed_loop_ELAPS_T;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T flag;

  /* Outputs for Atomic SubSystem: '<Root>/algorithm' */
  /* Delay: '<S24>/Delay' */
  rtb_Delay = rtDW.Delay_DSTATE;

  /* Gain: '<S15>/Gain2' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S15>/Add2'
   */
  rtb_Gain2_c = (rtU.ib - rtU.ic) * 0.577350259F;

  /* Sum: '<S14>/Add4' incorporates:
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator1'
   *  Gain: '<S14>/Gain3'
   */
  rtb_Add4 = rtDW.DiscreteTimeIntegrator1_DSTATE - 0.00535F * rtb_Gain2_c;

  /* Sum: '<S15>/Add1' incorporates:
   *  Gain: '<S15>/Gain'
   *  Gain: '<S15>/Gain1'
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   *  Sum: '<S15>/Add'
   */
  rtb_Add1_j = 0.666666687F * rtU.ia - (rtU.ib + rtU.ic) * 0.333333343F;

  /* Sum: '<S14>/Add3' incorporates:
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
   *  Gain: '<S14>/Gain2'
   */
  rtb_Add3_f = rtDW.DiscreteTimeIntegrator_DSTATE - 0.00535F * rtb_Add1_j;

  /* Sum: '<S23>/Sum2' incorporates:
   *  Delay: '<S24>/Delay'
   *  Product: '<S23>/Product2'
   *  Product: '<S23>/Product3'
   *  Trigonometry: '<S23>/Cos1'
   *  Trigonometry: '<S23>/Cos2'
   */
  rtb_PLL_error = cosf(rtDW.Delay_DSTATE) * rtb_Add4 - rtb_Add3_f * sinf
    (rtDW.Delay_DSTATE);

  /* Sum: '<S70>/Sum' incorporates:
   *  DiscreteIntegrator: '<S61>/Integrator'
   *  Product: '<S66>/PProd Out'
   */
  rtb_Saturation = rtb_PLL_error * 60000.0F + rtDW.Integrator_DSTATE_o;

  /* Saturate: '<S68>/Saturation' */
  if (rtb_Saturation > 2500.0F) {
    rtb_Saturation = 2500.0F;
  } else if (rtb_Saturation < -2500.0F) {
    rtb_Saturation = -2500.0F;
  }

  /* End of Saturate: '<S68>/Saturation' */

  /* Gain: '<S14>/Gain6' incorporates:
   *  Gain: '<S14>/Gain4'
   */
  smo_we = 0.25F * rtb_Saturation * 9.54929638F;

  /* RateTransition: '<S2>/Rate Transition1' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtb_RateTransition1 = smo_we;
  }

  /* End of RateTransition: '<S2>/Rate Transition1' */

  /* Chart: '<S3>/Chart1' incorporates:
   *  Inport: '<Root>/on_off'
   */
  if (rtDW.temporalCounter_i1 < 32767U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c7_algorithm == 0U) {
    rtDW.is_active_c7_algorithm = 1U;
    rtDW.is_c7_algorithm = IN_IDLE;
  } else {
    switch (rtDW.is_c7_algorithm) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 1000) {
        rtDW.is_c7_algorithm = IN_OpenStage;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.ZReset = 0.0F;
        rtDW.cnt = 0.0F;
      } else if (rtU.on_off == 0.0) {
        rtDW.is_c7_algorithm = IN_IDLE;
      } else {
        rtDW.Motor_state = 2.0F;
        rtDW.RestsSingal = 0.0;
      }
      break;

     case IN_IDLE:
      if (rtU.on_off == 1.0) {
        rtDW.is_c7_algorithm = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        rtDW.Motor_state = 1.0F;
        rtDW.RestsSingal = 0.0;
      }
      break;

     case IN_OpenStage:
      if (rtU.on_off == 0.0) {
        rtDW.is_c7_algorithm = IN_IDLE;
      } else if (rtDW.temporalCounter_i1 >= 30000) {
        rtDW.is_c7_algorithm = IN_ThetaAlign;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        if (rtDW.cnt == 1.0F) {
          rtDW.ZReset = 1.0F;
        }

        rtDW.cnt = 1.0F;
        rtDW.Motor_state = 3.0F;
        rtDW.RestsSingal = 0.0;
      }
      break;

     case IN_RunStage:
      if (rtU.on_off == 0.0) {
        rtDW.is_c7_algorithm = IN_IDLE;
      } else {
        rtDW.Motor_state = 5.0F;
        rtDW.RestsSingal = 1.0;
      }
      break;

     default:
      /* case IN_ThetaAlign: */
      if (rtDW.temporalCounter_i1 >= 5000) {
        rtDW.is_c7_algorithm = IN_RunStage;
      } else {
        rtDW.Motor_state = 4.0F;
        rtDW.RestsSingal = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* RateTransition: '<S2>/Rate Transition2' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (fcgen): '<S2>/Function-Call Generator' incorporates:
     *  SubSystem: '<S2>/speed_loop'
     */
    if (rtDW.speed_loop_RESET_ELAPS_T) {
      speed_loop_ELAPS_T = 0U;
    } else {
      speed_loop_ELAPS_T = rtM->Timing.clockTick1 - rtDW.speed_loop_PREV_T;
    }

    rtDW.speed_loop_PREV_T = rtM->Timing.clockTick1;
    rtDW.speed_loop_RESET_ELAPS_T = false;

    /* Sum: '<S4>/Sum' incorporates:
     *  Inport: '<Root>/speed_ref'
     */
    rtb_RateTransition1 = rtU.speed_ref - rtb_RateTransition1;

    /* DiscreteIntegrator: '<S214>/Integrator' */
    if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S214>/Integrator' */
      Integrator = rtDW.Integrator_DSTATE_oa;
    } else if ((rtDW.RestsSingal > 0.0) && (rtDW.Integrator_PrevResetState <= 0))
    {
      /* DiscreteIntegrator: '<S214>/Integrator' */
      Integrator = 0.0F;
    } else {
      /* DiscreteIntegrator: '<S214>/Integrator' */
      Integrator = (real32_T)(0.001 * (real_T)speed_loop_ELAPS_T
        * rtDW.Integrator_PREV_U) + rtDW.Integrator_DSTATE_oa;
    }

    /* End of DiscreteIntegrator: '<S214>/Integrator' */

    /* Sum: '<S223>/Sum' incorporates:
     *  Gain: '<S219>/Proportional Gain'
     */
    rtb_DeadZone_b = 0.003389F * rtb_RateTransition1 + Integrator;

    /* Saturate: '<S221>/Saturation' incorporates:
     *  DeadZone: '<S207>/DeadZone'
     */
    if (rtb_DeadZone_b > 3.0F) {
      /* Saturate: '<S221>/Saturation' */
      rtDW.Saturation = 3.0F;
      rtb_DeadZone_b -= 3.0F;
    } else {
      if (rtb_DeadZone_b < -3.0F) {
        /* Saturate: '<S221>/Saturation' */
        rtDW.Saturation = -3.0F;
      } else {
        /* Saturate: '<S221>/Saturation' */
        rtDW.Saturation = rtb_DeadZone_b;
      }

      if (rtb_DeadZone_b >= -3.0F) {
        rtb_DeadZone_b = 0.0F;
      } else {
        rtb_DeadZone_b -= -3.0F;
      }
    }

    /* End of Saturate: '<S221>/Saturation' */

    /* Gain: '<S211>/Integral Gain' */
    rtb_RateTransition1 *= 0.000144F;

    /* Update for DiscreteIntegrator: '<S214>/Integrator' */
    rtDW.Integrator_SYSTEM_ENABLE = 0U;
    rtDW.Integrator_DSTATE_oa = Integrator;
    if (rtDW.RestsSingal > 0.0) {
      rtDW.Integrator_PrevResetState = 1;
    } else if (rtDW.RestsSingal < 0.0) {
      rtDW.Integrator_PrevResetState = -1;
    } else if (rtDW.RestsSingal == 0.0) {
      rtDW.Integrator_PrevResetState = 0;
    } else {
      rtDW.Integrator_PrevResetState = 2;
    }

    /* Switch: '<S205>/Switch1' incorporates:
     *  Constant: '<S205>/Clamping_zero'
     *  Constant: '<S205>/Constant'
     *  Constant: '<S205>/Constant2'
     *  RelationalOperator: '<S205>/fix for DT propagation issue'
     */
    if (rtb_DeadZone_b > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    /* Switch: '<S205>/Switch2' incorporates:
     *  Constant: '<S205>/Clamping_zero'
     *  Constant: '<S205>/Constant3'
     *  Constant: '<S205>/Constant4'
     *  RelationalOperator: '<S205>/fix for DT propagation issue1'
     */
    if (rtb_RateTransition1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    /* Switch: '<S205>/Switch' incorporates:
     *  Constant: '<S205>/Clamping_zero'
     *  Logic: '<S205>/AND3'
     *  RelationalOperator: '<S205>/Equal1'
     *  RelationalOperator: '<S205>/Relational Operator'
     *  Switch: '<S205>/Switch1'
     *  Switch: '<S205>/Switch2'
     */
    if ((rtb_DeadZone_b != 0.0F) && (tmp == tmp_0)) {
      /* Update for DiscreteIntegrator: '<S214>/Integrator' incorporates:
       *  Constant: '<S205>/Constant1'
       */
      rtDW.Integrator_PREV_U = 0.0F;
    } else {
      /* Update for DiscreteIntegrator: '<S214>/Integrator' */
      rtDW.Integrator_PREV_U = rtb_RateTransition1;
    }

    /* End of Switch: '<S205>/Switch' */
    /* End of Outputs for S-Function (fcgen): '<S2>/Function-Call Generator' */

    /* RateTransition: '<S2>/Rate Transition3' */
    rtDW.RateTransition3 = rtDW.RateTransition3_Buffer0;
  }

  /* End of RateTransition: '<S2>/Rate Transition2' */

  /* SwitchCase: '<S3>/Switch Case' */
  switch ((int32_T)rtDW.Motor_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S7>/Constant'
     *  SignalConversion generated from: '<S7>/theta_fd'
     */
    rtDW.Merge = 0.0F;

    /* Merge: '<S3>/Merge1' incorporates:
     *  Constant: '<S7>/Constant1'
     *  SignalConversion generated from: '<S7>/iq_ref'
     */
    rtDW.Merge1 = 0.0F;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S8>/Constant'
     *  SignalConversion generated from: '<S8>/theta_fd'
     */
    rtDW.Merge = 0.0F;

    /* Merge: '<S3>/Merge1' incorporates:
     *  Constant: '<S8>/Constant1'
     *  SignalConversion generated from: '<S8>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    if ((rtDW.ZReset > 0.0F) && (rtDW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      rtDW.DiscreteTimeIntegrator_DSTATE_m = 0.0F;
    }

    rtb_RateTransition1 = rtDW.DiscreteTimeIntegrator_DSTATE_m;

    /* End of DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

    /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
    if ((rtDW.ZReset > 0.0F) && (rtDW.DiscreteTimeIntegrator1_PrevRes <= 0)) {
      rtDW.DiscreteTimeIntegrator1_DSTAT_o = 0.0F;
    }

    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S9>/Constant'
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator1'
     *  Math: '<S9>/Mod'
     */
    rtDW.Merge = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTAT_o, 6.28318548F);

    /* Merge: '<S3>/Merge1' incorporates:
     *  Constant: '<S9>/Constant2'
     *  SignalConversion generated from: '<S9>/iq_ref'
     */
    rtDW.Merge1 = 1.0F;

    /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_m += 0.0083775809F;
    if (rtDW.ZReset > 0.0F) {
      rtDW.DiscreteTimeIntegrator_PrevRese = 1;
    } else if (rtDW.ZReset < 0.0F) {
      rtDW.DiscreteTimeIntegrator_PrevRese = -1;
    } else if (rtDW.ZReset == 0.0F) {
      rtDW.DiscreteTimeIntegrator_PrevRese = 0;
    } else {
      rtDW.DiscreteTimeIntegrator_PrevRese = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTAT_o += 0.0001F * rtb_RateTransition1;
    if (rtDW.ZReset > 0.0F) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 1;
    } else if (rtDW.ZReset < 0.0F) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = -1;
    } else if (rtDW.ZReset == 0.0F) {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 0;
    } else {
      rtDW.DiscreteTimeIntegrator1_PrevRes = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S11>/Constant'
     *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
     *  Math: '<S11>/Mod'
     *  SignalConversion generated from: '<S11>/Theta_fd'
     */
    rtDW.Merge = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTAT_e, 6.28318548F);

    /* If: '<S11>/If' incorporates:
     *  Constant: '<S11>/Constant1'
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S11>/Constant4'
     *  Constant: '<S17>/Constant'
     *  Merge: '<S3>/Merge1'
     *  Product: '<S11>/Product1'
     *  SignalConversion generated from: '<S17>/Out1'
     *  Sum: '<S11>/Add'
     *  Sum: '<S11>/Add4'
     *  UnitDelay: '<S11>/Unit Delay'
     */
    if (rtDW.UnitDelay_DSTATE_d + 0.01F >= 1.0F) {
      /* Outputs for IfAction SubSystem: '<S11>/If Action Subsystem' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      rtb_RateTransition1 = 1.0F;

      /* End of Outputs for SubSystem: '<S11>/If Action Subsystem' */
    } else {
      rtb_RateTransition1 = rtDW.UnitDelay_DSTATE_d + 0.01F;
    }

    rtDW.Merge1 = 1.0F - rtb_RateTransition1 * 0.7F;

    /* End of If: '<S11>/If' */

    /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTAT_e += 0.0251327418F;

    /* Update for UnitDelay: '<S11>/Unit Delay' incorporates:
     *  Constant: '<S11>/Constant1'
     *  Sum: '<S11>/Add'
     */
    rtDW.UnitDelay_DSTATE_d += 0.01F;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  SignalConversion generated from: '<S10>/theta_Close'
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rtDW.Merge = rtDW.UnitDelay1_DSTATE;

    /* Merge: '<S3>/Merge1' incorporates:
     *  SignalConversion generated from: '<S10>/iq_CloseRef'
     */
    rtDW.Merge1 = rtDW.RateTransition3;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S3>/Switch Case' */

  /* Trigonometry: '<S3>/Cos' */
  rtb_Cos = arm_cos_f32(rtDW.Merge);

  /* Trigonometry: '<S3>/Sin' */
  rtb_Saturation_k = arm_sin_f32(rtDW.Merge);

  /* Sum: '<S16>/Sum' incorporates:
   *  Constant: '<S16>/id_ref'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   *  Sum: '<S12>/Add'
   */
  rtb_Sum = 0.0f - (rtb_Add1_j * rtb_Cos + rtb_Gain2_c * rtb_Saturation_k);

  /* Sum: '<S122>/Sum' incorporates:
   *  DiscreteIntegrator: '<S113>/Integrator'
   *  Product: '<S118>/PProd Out'
   */
  rtb_DeadZone = rtb_Sum * 0.10700000822544098 + rtDW.Integrator_DSTATE;

  /* Saturate: '<S120>/Saturation' */
  if (rtb_DeadZone > 12.470766067504883) {
    rtb_Add1 = 12.470766067504883;
  } else if (rtb_DeadZone < -12.470766067504883) {
    rtb_Add1 = -12.470766067504883;
  } else {
    rtb_Add1 = rtb_DeadZone;
  }

  /* End of Saturate: '<S120>/Saturation' */

  /* Sum: '<S16>/Sum1' incorporates:
   *  Product: '<S12>/Product2'
   *  Product: '<S12>/Product3'
   *  Sum: '<S12>/Add1'
   */
  rtb_RateTransition1 = rtDW.Merge1 - (rtb_Gain2_c * rtb_Cos - rtb_Add1_j *
    rtb_Saturation_k);

  /* Sum: '<S172>/Sum' incorporates:
   *  DiscreteIntegrator: '<S163>/Integrator'
   *  Product: '<S168>/PProd Out'
   */
  Integrator = rtb_RateTransition1 * 0.107000008F + rtDW.Integrator_DSTATE_p;

  /* Saturate: '<S170>/Saturation' */
  if (Integrator > 12.4707661F) {
    rtb_DeadZone_b = 12.4707661F;
  } else if (Integrator < -12.4707661F) {
    rtb_DeadZone_b = -12.4707661F;
  } else {
    rtb_DeadZone_b = Integrator;
  }

  /* End of Saturate: '<S170>/Saturation' */

  /* Sum: '<S5>/Add' incorporates:
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   */
  rtb_IProdOut = rtb_Add1 * rtb_Cos - rtb_DeadZone_b * rtb_Saturation_k;

  /* Sum: '<S5>/Add1' incorporates:
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   */
  rtb_Add1 = rtb_Add1 * rtb_Saturation_k + rtb_DeadZone_b * rtb_Cos;

  /* Outputs for Atomic SubSystem: '<S3>/SVPWM' */
  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  Inport: '<Root>/udc'
   *  Outport: '<Root>/tabc'
   */
  SVPWM((real32_T)rtb_IProdOut, (real32_T)rtb_Add1, rtU.udc, rtY.tabc);

  /* End of Outputs for SubSystem: '<S3>/SVPWM' */

  /* Sum: '<S14>/Add' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S14>/Gain'
   */
  rtb_Add1_j = (real32_T)rtb_IProdOut - 6.97F * rtb_Add1_j;

  /* Sum: '<S14>/Add2' incorporates:
   *  Math: '<S14>/Math Function'
   *  Math: '<S14>/Math Function2'
   *
   * About '<S14>/Math Function':
   *  Operator: magnitude^2
   *
   * About '<S14>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_DeadZone_b = (0.000285069429F - rtb_Add3_f * rtb_Add3_f) - rtb_Add4 *
    rtb_Add4;

  /* MATLABSystem: '<S14>/Moving Average' incorporates:
   *  Abs: '<S14>/Abs'
   */
  if (rtDW.obj.ForgettingFactor != 0.99F) {
    flag = (rtDW.obj.isInitialized == 1);
    if (flag) {
      rtDW.obj.TunablePropsChanged = true;
    }

    rtDW.obj.ForgettingFactor = 0.99F;
  }

  if (rtDW.obj.TunablePropsChanged) {
    rtDW.obj.TunablePropsChanged = false;
    obj = rtDW.obj.pStatistic;
    flag = (obj->isInitialized == 1);
    if (flag) {
      obj->TunablePropsChanged = true;
    }

    rtDW.obj.pStatistic->ForgettingFactor = rtDW.obj.ForgettingFactor;
  }

  obj = rtDW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pwN = 1.0F;
    obj->pmN = 0.0F;
    obj->plambda = obj->ForgettingFactor;
    obj->isSetupComplete = true;
    obj->TunablePropsChanged = false;
    obj->pwN = 1.0F;
    obj->pmN = 0.0F;
  }

  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->plambda = obj->ForgettingFactor;
  }

  rtb_Saturation_k = obj->pwN;
  pmLocal = obj->pmN;
  rtb_Cos = obj->plambda;
  pmLocal = (1.0F - 1.0F / rtb_Saturation_k) * pmLocal + 1.0F / rtb_Saturation_k
    * fabsf(rtb_Saturation);
  obj->pwN = rtb_Cos * rtb_Saturation_k + 1.0F;
  obj->pmN = pmLocal;

  /* Gain: '<S14>/Gain5' incorporates:
   *  MATLABSystem: '<S14>/Moving Average'
   */
  rtb_Saturation_k = 2000.0F * pmLocal;

  /* Saturate: '<S14>/Saturation' */
  if (rtb_Saturation_k > 5.0E+6F) {
    rtb_Saturation_k = 5.0E+6F;
  } else if (rtb_Saturation_k < 100000.0F) {
    rtb_Saturation_k = 100000.0F;
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* Sum: '<S24>/Sum1' incorporates:
   *  Delay: '<S24>/Delay'
   *  Gain: '<S24>/Ts'
   */
  rtb_Saturation = 0.0001F * rtb_Saturation + rtDW.Delay_DSTATE;

  /* DeadZone: '<S106>/DeadZone' */
  if (rtb_DeadZone > 12.470766067504883) {
    rtb_DeadZone -= 12.470766067504883;
  } else if (rtb_DeadZone >= -12.470766067504883) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= -12.470766067504883;
  }

  /* End of DeadZone: '<S106>/DeadZone' */

  /* Product: '<S110>/IProd Out' */
  rtb_IProdOut = rtb_Sum * 139.39999389648438;

  /* DeadZone: '<S156>/DeadZone' */
  if (Integrator > 12.4707661F) {
    Integrator -= 12.4707661F;
  } else if (Integrator >= -12.4707661F) {
    Integrator = 0.0F;
  } else {
    Integrator -= -12.4707661F;
  }

  /* End of DeadZone: '<S156>/DeadZone' */

  /* Product: '<S160>/IProd Out' */
  rtb_RateTransition1 *= 139.4F;

  /* If: '<S26>/If' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/Constant1'
   *  RelationalOperator: '<S26>/Relational Operator'
   *  RelationalOperator: '<S26>/Relational Operator1'
   */
  if (rtb_Saturation > 6.28318548F) {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* Update for Delay: '<S24>/Delay' incorporates:
     *  Constant: '<S28>/Constant'
     *  Sum: '<S28>/Sum'
     */
    rtDW.Delay_DSTATE = rtb_Saturation - 6.28318548F;

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem1' */
  } else if (rtb_Saturation < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* Update for Delay: '<S24>/Delay' incorporates:
     *  Constant: '<S27>/Constant'
     *  Sum: '<S27>/Sum'
     */
    rtDW.Delay_DSTATE = rtb_Saturation + 6.28318548F;

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* Update for Delay: '<S24>/Delay' incorporates:
     *  SignalConversion generated from: '<S29>/In1'
     */
    rtDW.Delay_DSTATE = rtb_Saturation;

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem2' */
  }

  /* End of If: '<S26>/If' */

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   *  Gain: '<S14>/Gain1'
   *  Product: '<S14>/Product1'
   *  Product: '<S14>/Product3'
   *  Sum: '<S14>/Add1'
   *  Sum: '<S14>/Add6'
   */
  rtDW.DiscreteTimeIntegrator1_DSTATE += (rtb_DeadZone_b * rtb_Add4 *
    rtb_Saturation_k + ((real32_T)rtb_Add1 - 6.97F * rtb_Gain2_c)) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product2'
   *  Sum: '<S14>/Add5'
   */
  rtDW.DiscreteTimeIntegrator_DSTATE += (rtb_DeadZone_b * rtb_Add3_f *
    rtb_Saturation_k + rtb_Add1_j) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S61>/Integrator' incorporates:
   *  Product: '<S58>/IProd Out'
   */
  rtDW.Integrator_DSTATE_o += rtb_PLL_error * 30000.0F * 0.0001F;

  /* Update for RateTransition: '<S2>/Rate Transition3' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW.RateTransition3_Buffer0 = rtDW.Saturation;
  }

  /* End of Update for RateTransition: '<S2>/Rate Transition3' */

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtb_Delay;

  /* Switch: '<S104>/Switch1' incorporates:
   *  Constant: '<S104>/Clamping_zero'
   *  Constant: '<S104>/Constant'
   *  Constant: '<S104>/Constant2'
   *  RelationalOperator: '<S104>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S104>/Switch2' incorporates:
   *  Constant: '<S104>/Clamping_zero'
   *  Constant: '<S104>/Constant3'
   *  Constant: '<S104>/Constant4'
   *  RelationalOperator: '<S104>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S104>/Switch' incorporates:
   *  Constant: '<S104>/Clamping_zero'
   *  Constant: '<S104>/Constant1'
   *  Logic: '<S104>/AND3'
   *  RelationalOperator: '<S104>/Equal1'
   *  RelationalOperator: '<S104>/Relational Operator'
   *  Switch: '<S104>/Switch1'
   *  Switch: '<S104>/Switch2'
   */
  if ((rtb_DeadZone != 0.0) && (tmp == tmp_0)) {
    rtb_IProdOut = 0.0;
  }

  /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
   *  Switch: '<S104>/Switch'
   */
  rtDW.Integrator_DSTATE += 0.0001 * rtb_IProdOut;

  /* Switch: '<S154>/Switch1' incorporates:
   *  Constant: '<S154>/Clamping_zero'
   *  Constant: '<S154>/Constant'
   *  Constant: '<S154>/Constant2'
   *  RelationalOperator: '<S154>/fix for DT propagation issue'
   */
  if (Integrator > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S154>/Switch2' incorporates:
   *  Constant: '<S154>/Clamping_zero'
   *  Constant: '<S154>/Constant3'
   *  Constant: '<S154>/Constant4'
   *  RelationalOperator: '<S154>/fix for DT propagation issue1'
   */
  if (rtb_RateTransition1 > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S154>/Switch' incorporates:
   *  Constant: '<S154>/Clamping_zero'
   *  Constant: '<S154>/Constant1'
   *  Logic: '<S154>/AND3'
   *  RelationalOperator: '<S154>/Equal1'
   *  RelationalOperator: '<S154>/Relational Operator'
   *  Switch: '<S154>/Switch1'
   *  Switch: '<S154>/Switch2'
   */
  if ((Integrator != 0.0F) && (tmp == tmp_0)) {
    rtb_RateTransition1 = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S163>/Integrator' incorporates:
   *  Switch: '<S154>/Switch'
   */
  rtDW.Integrator_DSTATE_p += 0.0001F * rtb_RateTransition1;

  /* End of Outputs for SubSystem: '<Root>/algorithm' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void algorithm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    g_dsp_internal_ExponentialMovin *obj;
    boolean_T flag;

    /* SystemInitialize for Atomic SubSystem: '<Root>/algorithm' */
    /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTATE = -0.011F;

    /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE = 0.011F;

    /* SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator' incorporates:
     *  SubSystem: '<S2>/speed_loop'
     */
    /* InitializeConditions for DiscreteIntegrator: '<S214>/Integrator' */
    rtDW.Integrator_PrevResetState = 2;

    /* End of SystemInitialize for S-Function (fcgen): '<S2>/Function-Call Generator' */

    /* SystemInitialize for IfAction SubSystem: '<S3>/If Action Subsystem2' */
    /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_PrevRes = 2;

    /* End of SystemInitialize for SubSystem: '<S3>/If Action Subsystem2' */

    /* Start for MATLABSystem: '<S14>/Moving Average' */
    rtDW.obj.isInitialized = 0;
    rtDW.obj.NumChannels = -1;
    rtDW.obj.FrameLength = -1;
    rtDW.obj.matlabCodegenIsDeleted = false;
    flag = (rtDW.obj.isInitialized == 1);
    if (flag) {
      rtDW.obj.TunablePropsChanged = true;
    }

    rtDW.obj.ForgettingFactor = 0.99F;
    SystemCore_setup(&rtDW.obj);

    /* End of Start for MATLABSystem: '<S14>/Moving Average' */

    /* InitializeConditions for MATLABSystem: '<S14>/Moving Average' */
    obj = rtDW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pwN = 1.0F;
      obj->pmN = 0.0F;
    }

    /* End of InitializeConditions for MATLABSystem: '<S14>/Moving Average' */
    /* End of SystemInitialize for SubSystem: '<Root>/algorithm' */

    /* Enable for Atomic SubSystem: '<Root>/algorithm' */
    /* Enable for S-Function (fcgen): '<S2>/Function-Call Generator' incorporates:
     *  SubSystem: '<S2>/speed_loop'
     */
    rtDW.speed_loop_RESET_ELAPS_T = true;

    /* Enable for DiscreteIntegrator: '<S214>/Integrator' */
    rtDW.Integrator_SYSTEM_ENABLE = 1U;

    /* End of Enable for S-Function (fcgen): '<S2>/Function-Call Generator' */
    /* End of Enable for SubSystem: '<Root>/algorithm' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
