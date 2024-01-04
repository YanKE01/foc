/*
 * File: Algorithm.h
 *
 * Code generated for Simulink model 'Algorithm'.
 *
 * Model version                  : 5.159
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Jan  4 10:51:37 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Algorithm_h_
#define RTW_HEADER_Algorithm_h_
#ifndef Algorithm_COMMON_INCLUDES_
#define Algorithm_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Algorithm_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<S1>/ Switch_Counter' */
typedef struct {
    real32_T time;                     /* '<S1>/ Switch_Counter' */
    boolean_T time_not_empty;          /* '<S1>/ Switch_Counter' */
} DW_Switch_Counter;

/* Block signals and states (default storage) for system '<S1>/Current_PI_control' */
typedef struct {
    real32_T Integrator_DSTATE;        /* '<S47>/Integrator' */
    real32_T Integrator_DSTATE_c;      /* '<S95>/Integrator' */
} DW_Current_PI_control;

/* Block signals and states (default storage) for system '<S1>/IF_Current_Switch' */
typedef struct {
    real32_T real_Iq;                  /* '<S1>/IF_Current_Switch' */
    real32_T last_iq;                  /* '<S1>/IF_Current_Switch' */
    boolean_T real_Iq_not_empty;       /* '<S1>/IF_Current_Switch' */
} DW_IF_Current_Switch;

/* Block signals and states (default storage) for system '<S1>/IF_Theta_Switch' */
typedef struct {
    real32_T theta_comp;               /* '<S1>/IF_Theta_Switch' */
    real32_T last_error;               /* '<S1>/IF_Theta_Switch' */
    real32_T last_comp;                /* '<S1>/IF_Theta_Switch' */
    real32_T flag;                     /* '<S1>/IF_Theta_Switch' */
    boolean_T theta_give_not_empty;    /* '<S1>/IF_Theta_Switch' */
} DW_IF_Theta_Switch;

/* Block signals and states (default storage) for system '<S1>/LADRC_Control1' */
typedef struct {
    real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S9>/Discrete-Time Integrator3' */
    real32_T DiscreteTimeIntegrator4_DSTATE;/* '<S9>/Discrete-Time Integrator4' */
} DW_LADRC_Control1;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
    DW_LADRC_Control1 LADRC_Control1_b;/* '<S1>/LADRC_Control1' */
    DW_IF_Theta_Switch sf_IF_Theta_Switch;/* '<S1>/IF_Theta_Switch' */
    DW_IF_Current_Switch sf_IF_Current_Switch;/* '<S1>/IF_Current_Switch' */
    DW_Current_PI_control Current_PI_control_e;/* '<S1>/Current_PI_control' */
    DW_Switch_Counter sf_Switch_Counter;/* '<S1>/ Switch_Counter' */
    real32_T Add;                      /* '<S9>/Add' */
    real32_T Delay_DSTATE;             /* '<S126>/Delay' */
    real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S180>/Discrete-Time Integrator2' */
    real32_T DiscreteTimeIntegrator2_DSTAT_m;/* '<S181>/Discrete-Time Integrator2' */
    real32_T Integrator_DSTATE;        /* '<S163>/Integrator' */
    real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S180>/Discrete-Time Integrator3' */
    real32_T DiscreteTimeIntegrator4_DSTATE;/* '<S180>/Discrete-Time Integrator4' */
    real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S180>/Discrete-Time Integrator1' */
    real32_T DiscreteTimeIntegrator_DSTATE;/* '<S180>/Discrete-Time Integrator' */
    real32_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S181>/Discrete-Time Integrator1' */
    real32_T DiscreteTimeIntegrator3_DSTAT_n;/* '<S181>/Discrete-Time Integrator3' */
    real32_T DiscreteTimeIntegrator_DSTATE_p;/* '<S181>/Discrete-Time Integrator' */
    real32_T DiscreteTimeIntegrator_DSTATE_a;/* '<S113>/Discrete-Time Integrator' */
    real32_T UnitDelay_DSTATE;         /* '<S119>/Unit Delay' */
    real32_T DiscreteTimeIntegrator_DSTATE_f;/* '<S112>/Discrete-Time Integrator' */
    real32_T UnitDelay_DSTATE_a;       /* '<S114>/Unit Delay' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
    real32_T Iabc[3];                  /* '<Root>/Iabc' */
    real32_T Udc;                      /* '<Root>/Udc' */
    real32_T Ref_Id;                   /* '<Root>/Ref_Id' */
    real32_T Ref_Iq;                   /* '<Root>/Ref_Iq' */
    real32_T Ref_RPM;                  /* '<Root>/Ref_RPM' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
    real32_T Tabc[3];                  /* '<Root>/Tabc' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct LADRC_Para_tag {
    real32_T ADRC_times;               /* Referenced by:
                                        * '<S9>/Gain4'
                                        * '<S9>/Gain7'
                                        * '<S9>/Gain9'
                                        */
    real32_T b0;                       /* Referenced by:
                                        * '<S9>/Constant'
                                        * '<S9>/Gain5'
                                        */
    real32_T omega_c;                  /* Referenced by:
                                        * '<S9>/Gain2'
                                        * '<S9>/Gain3'
                                        * '<S9>/Gain6'
                                        * '<S9>/Gain8'
                                        */
} LADRC_Para_type;

typedef struct Obe_Para_tag {
    real32_T PLL_I;                    /* Referenced by:
                                        * '<S124>/Constant2'
                                        * '<S124>/Gain'
                                        * '<S124>/Gain1'
                                        */
    real32_T PLL_P;                    /* Referenced by: '<S124>/Constant1' */
} Obe_Para_type;

typedef struct Obe_data_tag {
    real32_T Obe_theta;                /* '<S126>/Delay' */
    real32_T Obe_omega;                /* '<S170>/Saturation' */
    real32_T Ref_Iq;                   /* '<S1>/Add' */
    real32_T Real_Iq;                  /* '<S1>/Park_Trans' */
} Obe_data_type;

typedef struct PI_Para_tag {
    real32_T current_bandwidth;        /* Referenced by:
                                        * '<S4>/Gain'
                                        * '<S4>/Gain1'
                                        * '<S4>/Gain2'
                                        * '<S4>/Gain3'
                                        */
} PI_Para_type;

typedef struct PMSM_Para_tag {
    real32_T Ls;                       /* Referenced by:
                                        * '<S4>/Constant1'
                                        * '<S4>/Constant2'
                                        * '<S125>/Gain1'
                                        * '<S125>/Gain2'
                                        */
    real32_T Rs;                       /* Referenced by:
                                        * '<S4>/Constant3'
                                        * '<S4>/Constant4'
                                        * '<S12>/Gain19'
                                        * '<S12>/Gain3'
                                        */
    real32_T flux;                     /* Referenced by:
                                        * '<S180>/Discrete-Time Integrator2'
                                        * '<S181>/Discrete-Time Integrator2'
                                        */
} PMSM_Para_type;

typedef struct SOSOIFOParam_tag {
    real32_T FLL_K;                    /* Referenced by: '<S180>/Gain3' */
    real32_T Min_FLL_omega;            /* Referenced by:
                                        * '<S180>/Constant'
                                        * '<S180>/Saturation'
                                        */
    real32_T Swich_time;               /* Referenced by:
                                        * '<S1>/Constant5'
                                        * '<S1>/Constant6'
                                        */
    real32_T tao;                      /* Referenced by: '<S180>/Gain2' */
} SOSOIFOParam_type;

/* Real-time Model Data Structure */
struct tag_RTM {
    const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Algorithm_initialize(void);
extern void Algorithm_step(void);

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern LADRC_Para_type LADRC_Para;
extern Obe_Para_type Obe_Para;
extern Obe_data_type Obe_data;
extern PI_Para_type PI_Para;
extern PMSM_Para_type PMSM_Para;
extern SOSOIFOParam_type SOSOIFOParam;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S113>/Scope' : Unused code path elimination
 * Block '<S113>/Scope1' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S1>/LPF' : Unused code path elimination
 * Block '<S125>/Scope' : Unused code path elimination
 * Block '<S12>/Scope' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope4' : Unused code path elimination
 * Block '<S1>/Scope5' : Unused code path elimination
 * Block '<S1>/Scope6' : Unused code path elimination
 * Block '<S1>/Scope7' : Unused code path elimination
 * Block '<S1>/Scope8' : Unused code path elimination
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
 * hilite_system('IF_Time_SOSOIFO/Algorithm')    - opens subsystem IF_Time_SOSOIFO/Algorithm
 * hilite_system('IF_Time_SOSOIFO/Algorithm/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'IF_Time_SOSOIFO'
 * '<S1>'   : 'IF_Time_SOSOIFO/Algorithm'
 * '<S2>'   : 'IF_Time_SOSOIFO/Algorithm/ Switch_Counter'
 * '<S3>'   : 'IF_Time_SOSOIFO/Algorithm/Clark_Trans'
 * '<S4>'   : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control'
 * '<S5>'   : 'IF_Time_SOSOIFO/Algorithm/IF_Current_Switch'
 * '<S6>'   : 'IF_Time_SOSOIFO/Algorithm/IF_Gen'
 * '<S7>'   : 'IF_Time_SOSOIFO/Algorithm/IF_Theta_Switch'
 * '<S8>'   : 'IF_Time_SOSOIFO/Algorithm/IF_theta_Select'
 * '<S9>'   : 'IF_Time_SOSOIFO/Algorithm/LADRC_Control1'
 * '<S10>'  : 'IF_Time_SOSOIFO/Algorithm/Park_Trans'
 * '<S11>'  : 'IF_Time_SOSOIFO/Algorithm/Park_Trans1'
 * '<S12>'  : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe'
 * '<S13>'  : 'IF_Time_SOSOIFO/Algorithm/SVPWM_By_Average_Zero_Injection'
 * '<S14>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller'
 * '<S15>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1'
 * '<S16>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Anti-windup'
 * '<S17>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/D Gain'
 * '<S18>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Filter'
 * '<S19>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Filter ICs'
 * '<S20>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/I Gain'
 * '<S21>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Ideal P Gain'
 * '<S22>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Ideal P Gain Fdbk'
 * '<S23>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Integrator'
 * '<S24>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Integrator ICs'
 * '<S25>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/N Copy'
 * '<S26>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/N Gain'
 * '<S27>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/P Copy'
 * '<S28>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Parallel P Gain'
 * '<S29>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Reset Signal'
 * '<S30>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Saturation'
 * '<S31>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Saturation Fdbk'
 * '<S32>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Sum'
 * '<S33>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Sum Fdbk'
 * '<S34>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Tracking Mode'
 * '<S35>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Tracking Mode Sum'
 * '<S36>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Tsamp - Integral'
 * '<S37>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Tsamp - Ngain'
 * '<S38>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/postSat Signal'
 * '<S39>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/preSat Signal'
 * '<S40>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Anti-windup/Passthrough'
 * '<S41>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/D Gain/Disabled'
 * '<S42>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Filter/Disabled'
 * '<S43>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Filter ICs/Disabled'
 * '<S44>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/I Gain/External Parameters'
 * '<S45>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Ideal P Gain/Passthrough'
 * '<S46>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Integrator/Discrete'
 * '<S48>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Integrator ICs/Internal IC'
 * '<S49>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/N Gain/Disabled'
 * '<S51>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/P Copy/Disabled'
 * '<S52>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Parallel P Gain/External Parameters'
 * '<S53>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Reset Signal/Disabled'
 * '<S54>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Saturation/Enabled'
 * '<S55>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Saturation Fdbk/Disabled'
 * '<S56>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Sum/Sum_PI'
 * '<S57>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Sum Fdbk/Disabled'
 * '<S58>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Tracking Mode/Disabled'
 * '<S59>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S61>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/postSat Signal/Forward_Path'
 * '<S63>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller/preSat Signal/Forward_Path'
 * '<S64>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Anti-windup'
 * '<S65>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/D Gain'
 * '<S66>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Filter'
 * '<S67>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Filter ICs'
 * '<S68>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/I Gain'
 * '<S69>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Ideal P Gain'
 * '<S70>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Ideal P Gain Fdbk'
 * '<S71>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Integrator'
 * '<S72>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Integrator ICs'
 * '<S73>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/N Copy'
 * '<S74>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/N Gain'
 * '<S75>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/P Copy'
 * '<S76>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Parallel P Gain'
 * '<S77>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Reset Signal'
 * '<S78>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Saturation'
 * '<S79>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Saturation Fdbk'
 * '<S80>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Sum'
 * '<S81>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Sum Fdbk'
 * '<S82>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Tracking Mode'
 * '<S83>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Tracking Mode Sum'
 * '<S84>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Tsamp - Integral'
 * '<S85>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Tsamp - Ngain'
 * '<S86>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/postSat Signal'
 * '<S87>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/preSat Signal'
 * '<S88>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Anti-windup/Passthrough'
 * '<S89>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/D Gain/Disabled'
 * '<S90>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Filter/Disabled'
 * '<S91>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Filter ICs/Disabled'
 * '<S92>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/I Gain/External Parameters'
 * '<S93>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Ideal P Gain/Passthrough'
 * '<S94>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Integrator/Discrete'
 * '<S96>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Integrator ICs/Internal IC'
 * '<S97>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S98>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/N Gain/Disabled'
 * '<S99>'  : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/P Copy/Disabled'
 * '<S100>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Parallel P Gain/External Parameters'
 * '<S101>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Reset Signal/Disabled'
 * '<S102>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Saturation/Enabled'
 * '<S103>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Saturation Fdbk/Disabled'
 * '<S104>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Sum/Sum_PI'
 * '<S105>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Sum Fdbk/Disabled'
 * '<S106>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Tracking Mode/Disabled'
 * '<S107>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S109>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/postSat Signal/Forward_Path'
 * '<S111>' : 'IF_Time_SOSOIFO/Algorithm/Current_PI_control/PID Controller1/preSat Signal/Forward_Path'
 * '<S112>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFneg'
 * '<S113>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFpos'
 * '<S114>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFneg/integrator'
 * '<S115>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFneg/integrator/RangeLimit'
 * '<S116>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFneg/integrator/RangeLimit/If Action Subsystem'
 * '<S117>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFneg/integrator/RangeLimit/If Action Subsystem1'
 * '<S118>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFneg/integrator/RangeLimit/If Action Subsystem2'
 * '<S119>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFpos/integrator'
 * '<S120>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFpos/integrator/RangeLimit'
 * '<S121>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFpos/integrator/RangeLimit/If Action Subsystem'
 * '<S122>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFpos/integrator/RangeLimit/If Action Subsystem1'
 * '<S123>' : 'IF_Time_SOSOIFO/Algorithm/IF_Gen/IFpos/integrator/RangeLimit/If Action Subsystem2'
 * '<S124>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL'
 * '<S125>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/SOSOIFO'
 * '<S126>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/Inte_Limit'
 * '<S127>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller'
 * '<S128>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/Inte_Limit/xianfu'
 * '<S129>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/Inte_Limit/xianfu/If Action Subsystem'
 * '<S130>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/Inte_Limit/xianfu/If Action Subsystem1'
 * '<S131>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/Inte_Limit/xianfu/If Action Subsystem2'
 * '<S132>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Anti-windup'
 * '<S133>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/D Gain'
 * '<S134>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Filter'
 * '<S135>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Filter ICs'
 * '<S136>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/I Gain'
 * '<S137>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Ideal P Gain'
 * '<S138>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S139>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Integrator'
 * '<S140>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Integrator ICs'
 * '<S141>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/N Copy'
 * '<S142>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/N Gain'
 * '<S143>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/P Copy'
 * '<S144>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Parallel P Gain'
 * '<S145>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Reset Signal'
 * '<S146>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Saturation'
 * '<S147>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Saturation Fdbk'
 * '<S148>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Sum'
 * '<S149>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Sum Fdbk'
 * '<S150>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Tracking Mode'
 * '<S151>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Tracking Mode Sum'
 * '<S152>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Tsamp - Integral'
 * '<S153>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Tsamp - Ngain'
 * '<S154>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/postSat Signal'
 * '<S155>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/preSat Signal'
 * '<S156>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S157>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/D Gain/Disabled'
 * '<S158>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Filter/Disabled'
 * '<S159>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Filter ICs/Disabled'
 * '<S160>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/I Gain/External Parameters'
 * '<S161>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S162>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S163>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Integrator/Discrete'
 * '<S164>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S165>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S166>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/N Gain/Disabled'
 * '<S167>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/P Copy/Disabled'
 * '<S168>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Parallel P Gain/External Parameters'
 * '<S169>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Reset Signal/Disabled'
 * '<S170>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Saturation/Enabled'
 * '<S171>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S172>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Sum/Sum_PI'
 * '<S173>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S174>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S175>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S176>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S177>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S178>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S179>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S180>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/SOSOIFO/SOSOGI_alpha'
 * '<S181>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/SOSOIFO/SOSOGI_beta'
 * '<S182>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/SOSOIFO/SOSOGI_alpha/If Action Subsystem'
 * '<S183>' : 'IF_Time_SOSOIFO/Algorithm/SOSOIFO Obe/SOSOIFO/SOSOGI_alpha/If Action Subsystem2'
 * '<S184>' : 'IF_Time_SOSOIFO/Algorithm/SVPWM_By_Average_Zero_Injection/Anti_Park_Trans'
 * '<S185>' : 'IF_Time_SOSOIFO/Algorithm/SVPWM_By_Average_Zero_Injection/SVPWM'
 * '<S186>' : 'IF_Time_SOSOIFO/Algorithm/SVPWM_By_Average_Zero_Injection/SVPWM/Anti_Clark_Trans'
 */
#endif                                 /* RTW_HEADER_Algorithm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
