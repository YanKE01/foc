/*
 * File: current_loop.h
 *
 * Code generated for Simulink model 'current_loop'.
 *
 * Model version                  : 5.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jan 17 10:16:04 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_current_loop_h_
#define RTW_HEADER_current_loop_h_
#ifndef current_loop_COMMON_INCLUDES_
#define current_loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* current_loop_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef struct_tag_CXAwhqoLBxgIPjox4Bhg1C
#define struct_tag_CXAwhqoLBxgIPjox4Bhg1C

struct tag_CXAwhqoLBxgIPjox4Bhg1C
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real32_T ForgettingFactor;
  real32_T pwN;
  real32_T pmN;
  real32_T plambda;
};

#endif                                 /* struct_tag_CXAwhqoLBxgIPjox4Bhg1C */

#ifndef typedef_h_dsp_internal_ExponentialMovin
#define typedef_h_dsp_internal_ExponentialMovin

typedef struct tag_CXAwhqoLBxgIPjox4Bhg1C h_dsp_internal_ExponentialMovin;

#endif                             /* typedef_h_dsp_internal_ExponentialMovin */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap
#define typedef_cell_wrap

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap;

#endif                                 /* typedef_cell_wrap */

#ifndef struct_tag_HpW7VuH0kykLtzsnHjK9hE
#define struct_tag_HpW7VuH0kykLtzsnHjK9hE

struct tag_HpW7VuH0kykLtzsnHjK9hE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap inputVarSize;
  real32_T ForgettingFactor;
  h_dsp_internal_ExponentialMovin *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  h_dsp_internal_ExponentialMovin _pobj0;
};

#endif                                 /* struct_tag_HpW7VuH0kykLtzsnHjK9hE */

#ifndef typedef_dsp_simulink_MovingAverage
#define typedef_dsp_simulink_MovingAverage

typedef struct tag_HpW7VuH0kykLtzsnHjK9hE dsp_simulink_MovingAverage;

#endif                                 /* typedef_dsp_simulink_MovingAverage */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage obj;      /* '<S14>/Moving Average' */
  real_T RestsSingal;                  /* '<S3>/Chart1' */
  real_T Integrator_DSTATE;            /* '<S113>/Integrator' */
  real32_T RateTransition3;            /* '<S2>/Rate Transition3' */
  real32_T Merge;                      /* '<S3>/Merge' */
  real32_T Merge1;                     /* '<S3>/Merge1' */
  real32_T Motor_state;                /* '<S3>/Chart1' */
  real32_T ZReset;                     /* '<S3>/Chart1' */
  real32_T Saturation;                 /* '<S221>/Saturation' */
  real32_T Delay_DSTATE;               /* '<S24>/Delay' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S14>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S14>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S61>/Integrator' */
  real32_T UnitDelay1_DSTATE;          /* '<S3>/Unit Delay1' */
  real32_T Integrator_DSTATE_p;        /* '<S163>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_e;/* '<S11>/Discrete-Time Integrator1' */
  real32_T UnitDelay_DSTATE_d;         /* '<S11>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S9>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o;/* '<S9>/Discrete-Time Integrator1' */
  real32_T Integrator_DSTATE_oa;       /* '<S214>/Integrator' */
  real32_T RateTransition3_Buffer0;    /* '<S2>/Rate Transition3' */
  real32_T cnt;                        /* '<S3>/Chart1' */
  real32_T Integrator_PREV_U;          /* '<S214>/Integrator' */
  uint32_T speed_loop_PREV_T;          /* '<S2>/speed_loop' */
  uint16_T temporalCounter_i1;         /* '<S3>/Chart1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S9>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S9>/Discrete-Time Integrator1' */
  int8_T Integrator_PrevResetState;    /* '<S214>/Integrator' */
  uint8_T is_active_c7_current_loop;   /* '<S3>/Chart1' */
  uint8_T is_c7_current_loop;          /* '<S3>/Chart1' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S214>/Integrator' */
  boolean_T speed_loop_RESET_ELAPS_T;  /* '<S2>/speed_loop' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T udc;                        /* '<Root>/udc' */
  real_T on_off;                       /* '<Root>/on_off' */
  real32_T speed_ref;                  /* '<Root>/speed_ref' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T tabc[3];                    /* '<Root>/tabc' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T smo_we;                /* '<S14>/Gain6' */

/* Model entry point functions */
extern void current_loop_initialize(void);
extern void current_loop_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<S11>/Add1' : Unused code path elimination
 * Block '<S11>/Add2' : Unused code path elimination
 * Block '<S11>/Constant3' : Unused code path elimination
 * Block '<S11>/Mod1' : Unused code path elimination
 * Block '<S11>/Product' : Unused code path elimination
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S11>/Scope1' : Unused code path elimination
 * Block '<S11>/Scope2' : Unused code path elimination
 * Block '<S11>/Scope3' : Unused code path elimination
 * Block '<S11>/Scope4' : Unused code path elimination
 * Block '<S2>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/Data Type Conversion1' : Eliminate redundant data type conversion
 */

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
 * hilite_system('euler_nfo/current_loop')    - opens subsystem euler_nfo/current_loop
 * hilite_system('euler_nfo/current_loop/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'euler_nfo'
 * '<S2>'   : 'euler_nfo/current_loop'
 * '<S3>'   : 'euler_nfo/current_loop/current_loop'
 * '<S4>'   : 'euler_nfo/current_loop/speed_loop'
 * '<S5>'   : 'euler_nfo/current_loop/current_loop/AntiPark'
 * '<S6>'   : 'euler_nfo/current_loop/current_loop/Chart1'
 * '<S7>'   : 'euler_nfo/current_loop/current_loop/If Action Subsystem'
 * '<S8>'   : 'euler_nfo/current_loop/current_loop/If Action Subsystem1'
 * '<S9>'   : 'euler_nfo/current_loop/current_loop/If Action Subsystem2'
 * '<S10>'  : 'euler_nfo/current_loop/current_loop/If Action Subsystem3'
 * '<S11>'  : 'euler_nfo/current_loop/current_loop/If Action Subsystem4'
 * '<S12>'  : 'euler_nfo/current_loop/current_loop/Park'
 * '<S13>'  : 'euler_nfo/current_loop/current_loop/SVPWM'
 * '<S14>'  : 'euler_nfo/current_loop/current_loop/Subsystem'
 * '<S15>'  : 'euler_nfo/current_loop/current_loop/clark'
 * '<S16>'  : 'euler_nfo/current_loop/current_loop/current_pi'
 * '<S17>'  : 'euler_nfo/current_loop/current_loop/If Action Subsystem4/If Action Subsystem'
 * '<S18>'  : 'euler_nfo/current_loop/current_loop/If Action Subsystem4/If Action Subsystem1'
 * '<S19>'  : 'euler_nfo/current_loop/current_loop/If Action Subsystem4/If Action Subsystem2'
 * '<S20>'  : 'euler_nfo/current_loop/current_loop/If Action Subsystem4/If Action Subsystem3'
 * '<S21>'  : 'euler_nfo/current_loop/current_loop/SVPWM/AntiClark'
 * '<S22>'  : 'euler_nfo/current_loop/current_loop/SVPWM/v0'
 * '<S23>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL'
 * '<S24>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/Inte_Limit'
 * '<S25>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller'
 * '<S26>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/Inte_Limit/xianfu'
 * '<S27>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/Inte_Limit/xianfu/If Action Subsystem'
 * '<S28>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/Inte_Limit/xianfu/If Action Subsystem1'
 * '<S29>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/Inte_Limit/xianfu/If Action Subsystem2'
 * '<S30>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Anti-windup'
 * '<S31>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/D Gain'
 * '<S32>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Filter'
 * '<S33>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Filter ICs'
 * '<S34>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/I Gain'
 * '<S35>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Ideal P Gain'
 * '<S36>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S37>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Integrator'
 * '<S38>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Integrator ICs'
 * '<S39>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/N Copy'
 * '<S40>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/N Gain'
 * '<S41>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/P Copy'
 * '<S42>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Parallel P Gain'
 * '<S43>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Reset Signal'
 * '<S44>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Saturation'
 * '<S45>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Saturation Fdbk'
 * '<S46>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Sum'
 * '<S47>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Sum Fdbk'
 * '<S48>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Tracking Mode'
 * '<S49>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Tracking Mode Sum'
 * '<S50>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Tsamp - Integral'
 * '<S51>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Tsamp - Ngain'
 * '<S52>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/postSat Signal'
 * '<S53>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/preSat Signal'
 * '<S54>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S55>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/D Gain/Disabled'
 * '<S56>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Filter/Disabled'
 * '<S57>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Filter ICs/Disabled'
 * '<S58>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/I Gain/External Parameters'
 * '<S59>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S60>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S61>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Integrator/Discrete'
 * '<S62>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S63>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S64>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/N Gain/Disabled'
 * '<S65>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/P Copy/Disabled'
 * '<S66>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Parallel P Gain/External Parameters'
 * '<S67>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Reset Signal/Disabled'
 * '<S68>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Saturation/Enabled'
 * '<S69>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S70>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Sum/Sum_PI'
 * '<S71>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S72>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S73>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S74>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S75>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S76>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S77>'  : 'euler_nfo/current_loop/current_loop/Subsystem/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S78>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller'
 * '<S79>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1'
 * '<S80>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Anti-windup'
 * '<S81>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/D Gain'
 * '<S82>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Filter'
 * '<S83>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Filter ICs'
 * '<S84>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/I Gain'
 * '<S85>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Ideal P Gain'
 * '<S86>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Ideal P Gain Fdbk'
 * '<S87>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Integrator'
 * '<S88>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Integrator ICs'
 * '<S89>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/N Copy'
 * '<S90>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/N Gain'
 * '<S91>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/P Copy'
 * '<S92>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Parallel P Gain'
 * '<S93>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Reset Signal'
 * '<S94>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Saturation'
 * '<S95>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Saturation Fdbk'
 * '<S96>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Sum'
 * '<S97>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Sum Fdbk'
 * '<S98>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Tracking Mode'
 * '<S99>'  : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Tracking Mode Sum'
 * '<S100>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Tsamp - Integral'
 * '<S101>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Tsamp - Ngain'
 * '<S102>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/postSat Signal'
 * '<S103>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/preSat Signal'
 * '<S104>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S105>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S106>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S107>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/D Gain/Disabled'
 * '<S108>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Filter/Disabled'
 * '<S109>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Filter ICs/Disabled'
 * '<S110>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/I Gain/External Parameters'
 * '<S111>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Ideal P Gain/Passthrough'
 * '<S112>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S113>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Integrator/Discrete'
 * '<S114>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Integrator ICs/Internal IC'
 * '<S115>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S116>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/N Gain/Disabled'
 * '<S117>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/P Copy/Disabled'
 * '<S118>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Parallel P Gain/External Parameters'
 * '<S119>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Reset Signal/Disabled'
 * '<S120>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Saturation/Enabled'
 * '<S121>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Saturation Fdbk/Disabled'
 * '<S122>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Sum/Sum_PI'
 * '<S123>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Sum Fdbk/Disabled'
 * '<S124>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Tracking Mode/Disabled'
 * '<S125>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S126>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S127>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S128>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/postSat Signal/Forward_Path'
 * '<S129>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller/preSat Signal/Forward_Path'
 * '<S130>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Anti-windup'
 * '<S131>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/D Gain'
 * '<S132>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Filter'
 * '<S133>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Filter ICs'
 * '<S134>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/I Gain'
 * '<S135>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Ideal P Gain'
 * '<S136>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Ideal P Gain Fdbk'
 * '<S137>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Integrator'
 * '<S138>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Integrator ICs'
 * '<S139>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/N Copy'
 * '<S140>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/N Gain'
 * '<S141>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/P Copy'
 * '<S142>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Parallel P Gain'
 * '<S143>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Reset Signal'
 * '<S144>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Saturation'
 * '<S145>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Saturation Fdbk'
 * '<S146>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Sum'
 * '<S147>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Sum Fdbk'
 * '<S148>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Tracking Mode'
 * '<S149>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Tracking Mode Sum'
 * '<S150>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Tsamp - Integral'
 * '<S151>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Tsamp - Ngain'
 * '<S152>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/postSat Signal'
 * '<S153>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/preSat Signal'
 * '<S154>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S155>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S156>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S157>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/D Gain/Disabled'
 * '<S158>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Filter/Disabled'
 * '<S159>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Filter ICs/Disabled'
 * '<S160>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/I Gain/External Parameters'
 * '<S161>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Ideal P Gain/Passthrough'
 * '<S162>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S163>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Integrator/Discrete'
 * '<S164>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Integrator ICs/Internal IC'
 * '<S165>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S166>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/N Gain/Disabled'
 * '<S167>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/P Copy/Disabled'
 * '<S168>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Parallel P Gain/External Parameters'
 * '<S169>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Reset Signal/Disabled'
 * '<S170>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Saturation/Enabled'
 * '<S171>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Saturation Fdbk/Disabled'
 * '<S172>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Sum/Sum_PI'
 * '<S173>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Sum Fdbk/Disabled'
 * '<S174>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Tracking Mode/Disabled'
 * '<S175>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S176>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S177>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S178>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/postSat Signal/Forward_Path'
 * '<S179>' : 'euler_nfo/current_loop/current_loop/current_pi/PID Controller1/preSat Signal/Forward_Path'
 * '<S180>' : 'euler_nfo/current_loop/speed_loop/PID Controller'
 * '<S181>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Anti-windup'
 * '<S182>' : 'euler_nfo/current_loop/speed_loop/PID Controller/D Gain'
 * '<S183>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Filter'
 * '<S184>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Filter ICs'
 * '<S185>' : 'euler_nfo/current_loop/speed_loop/PID Controller/I Gain'
 * '<S186>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Ideal P Gain'
 * '<S187>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Ideal P Gain Fdbk'
 * '<S188>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Integrator'
 * '<S189>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Integrator ICs'
 * '<S190>' : 'euler_nfo/current_loop/speed_loop/PID Controller/N Copy'
 * '<S191>' : 'euler_nfo/current_loop/speed_loop/PID Controller/N Gain'
 * '<S192>' : 'euler_nfo/current_loop/speed_loop/PID Controller/P Copy'
 * '<S193>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Parallel P Gain'
 * '<S194>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Reset Signal'
 * '<S195>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Saturation'
 * '<S196>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Saturation Fdbk'
 * '<S197>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Sum'
 * '<S198>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Sum Fdbk'
 * '<S199>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Tracking Mode'
 * '<S200>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Tracking Mode Sum'
 * '<S201>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Tsamp - Integral'
 * '<S202>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Tsamp - Ngain'
 * '<S203>' : 'euler_nfo/current_loop/speed_loop/PID Controller/postSat Signal'
 * '<S204>' : 'euler_nfo/current_loop/speed_loop/PID Controller/preSat Signal'
 * '<S205>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S206>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S207>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S208>' : 'euler_nfo/current_loop/speed_loop/PID Controller/D Gain/Disabled'
 * '<S209>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Filter/Disabled'
 * '<S210>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Filter ICs/Disabled'
 * '<S211>' : 'euler_nfo/current_loop/speed_loop/PID Controller/I Gain/Internal Parameters'
 * '<S212>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Ideal P Gain/Passthrough'
 * '<S213>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S214>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Integrator/Discrete'
 * '<S215>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Integrator ICs/Internal IC'
 * '<S216>' : 'euler_nfo/current_loop/speed_loop/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S217>' : 'euler_nfo/current_loop/speed_loop/PID Controller/N Gain/Disabled'
 * '<S218>' : 'euler_nfo/current_loop/speed_loop/PID Controller/P Copy/Disabled'
 * '<S219>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S220>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Reset Signal/External Reset'
 * '<S221>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Saturation/Enabled'
 * '<S222>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Saturation Fdbk/Disabled'
 * '<S223>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Sum/Sum_PI'
 * '<S224>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Sum Fdbk/Disabled'
 * '<S225>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Tracking Mode/Disabled'
 * '<S226>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S227>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S228>' : 'euler_nfo/current_loop/speed_loop/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S229>' : 'euler_nfo/current_loop/speed_loop/PID Controller/postSat Signal/Forward_Path'
 * '<S230>' : 'euler_nfo/current_loop/speed_loop/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_current_loop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
