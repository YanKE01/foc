/*
 * File: Algorithm.h
 *
 * Code generated for Simulink model 'Algorithm'.
 *
 * Model version                  : 6.17
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Feb 12 22:53:47 2024
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

/* Block signals and states (default storage) for system '<S2>/Current_PI_control' */
typedef struct {
    real32_T Integrator_DSTATE;        /* '<S44>/Integrator' */
    real32_T Integrator_DSTATE_c;      /* '<S92>/Integrator' */
} DW_Current_PI_control;

/* Block signals and states (default storage) for system '<S7>/Forward_theta' */
typedef struct {
    real32_T DiscreteTimeIntegrator_DSTATE;/* '<S158>/Discrete-Time Integrator' */
    real32_T UnitDelay_DSTATE;         /* '<S159>/Unit Delay' */
    real32_T DiscreteTimeIntegrator_PREV_U;/* '<S158>/Discrete-Time Integrator' */
    uint32_T Forward_theta_PREV_T;     /* '<S7>/Forward_theta' */
    uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S158>/Discrete-Time Integrator' */
    boolean_T Forward_theta_RESET_ELAPS_T;/* '<S7>/Forward_theta' */
} DW_Forward_theta;

/* Block signals and states (default storage) for system '<S3>/Over_judge' */
typedef struct {
    boolean_T Relay_Mode;              /* '<S225>/Relay' */
} DW_Over_judge;

/* Block signals and states (default storage) for system '<S3>/Low_judge' */
typedef struct {
    boolean_T Relay_Mode;              /* '<S224>/Relay' */
} DW_Low_judge;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
    DW_Low_judge Low_judge_l;          /* '<S3>/Low_judge' */
    DW_Over_judge Over_judge_d;        /* '<S3>/Over_judge' */
    DW_Forward_theta Forward_theta_p;  /* '<S7>/Forward_theta' */
    DW_Current_PI_control Current_PI_control_e;/* '<S2>/Current_PI_control' */
    real_T Go;                         /* '<S1>/Chart1' */
    real_T UnitDelay4_DSTATE;          /* '<S8>/Unit Delay4' */
    real_T UnitDelay6_DSTATE;          /* '<S8>/Unit Delay6' */
    real_T UnitDelay5_DSTATE;          /* '<S8>/Unit Delay5' */
    real_T UnitDelay7_DSTATE;          /* '<S8>/Unit Delay7' */
    real32_T Use_Theta;                /* '<S2>/IF_Switch_Logical' */
    real32_T Iq_out;                   /* '<S2>/IF_Switch_Logical' */
    real32_T enable;                   /* '<S2>/IF_Switch_Logical' */
    real32_T Saturation_p;             /* '<S148>/Saturation' */
    real32_T UnitDelay_DSTATE;         /* '<S166>/Unit Delay' */
    real32_T Integrator_DSTATE;        /* '<S200>/Integrator' */
    real32_T DiscreteFilter2_states;   /* '<S164>/Discrete Filter2' */
    real32_T Integrator_DSTATE_p;      /* '<S141>/Integrator' */
    real32_T direction;                /* '<S2>/IF_Switch_Logical' */
    real32_T omega1;                   /* '<S2>/IF_Switch_Logical' */
    real32_T omega2;                   /* '<S2>/IF_Switch_Logical' */
    real32_T Iq_keep;                  /* '<S2>/IF_Switch_Logical' */
    uint8_T is_active_c2_Algorithm;    /* '<S1>/Chart1' */
    uint8_T is_c2_Algorithm;           /* '<S1>/Chart1' */
    uint8_T is_active_c3_Algorithm;    /* '<S2>/IF_Switch_Logical' */
    uint8_T is_c3_Algorithm;           /* '<S2>/IF_Switch_Logical' */
    uint8_T is_Backward;               /* '<S2>/IF_Switch_Logical' */
    uint8_T is_Forward;                /* '<S2>/IF_Switch_Logical' */
    boolean_T Algorithm_MODE;          /* '<S1>/Algorithm' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
    real32_T Iabc[3];                  /* '<Root>/Iabc' */
    real32_T Real_Theta;               /* '<Root>/Real_Theta' */
    real32_T Udc;                      /* '<Root>/Udc' */
    real32_T Ref_Id;                   /* '<Root>/Ref_Id' */
    real32_T Ref_Iq;                   /* '<Root>/Ref_Iq' */
    real32_T Ref_RPM;                  /* '<Root>/Ref_RPM' */
    real32_T Go_Flag;                  /* '<Root>/Go_Flag' */
    real_T CCR;                        /* '<Root>/CCR' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
    real32_T Tabc[3];                  /* '<Root>/Tabc' */
    real32_T obe;                      /* '<Root>/obe' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct ERROR_State_tag {
    real32_T Low_V;                    /* '<S1>/Chart1' */
    real32_T Over_V;                   /* '<S1>/Chart1' */
    real32_T STOP;                     /* '<S1>/Chart1' */
} ERROR_State_type;

typedef struct PI_Para_tag {
    real32_T current_bandwidth;        /* Referenced by:
                                        * '<S5>/Gain'
                                        * '<S5>/Gain1'
                                        * '<S5>/Gain2'
                                        * '<S5>/Gain3'
                                        */
} PI_Para_type;

typedef struct PLL_tag {
    real32_T PLL_KI;                 /* Referenced by: '<S197>/Integral Gain' */
    real32_T PLL_KP;             /* Referenced by: '<S205>/Proportional Gain' */
} PLL_type;

typedef struct PMSM_Para_tag {
    real_T flux;                       /* Referenced by:
                                        * '<S8>/Constant1'
                                        * '<S8>/Gain11'
                                        * '<S8>/Gain12'
                                        */
} PMSM_Para_type;

typedef struct SOSOIFOParam_tag {
    real32_T IF_Initial;               /* Referenced by: '<S158>/Constant' */
} SOSOIFOParam_type;

typedef struct SPEED_tag {
    real32_T SPEED_KI;               /* Referenced by: '<S138>/Integral Gain' */
    real32_T SPEED_KP;           /* Referenced by: '<S146>/Proportional Gain' */
} SPEED_type;

/* Real-time Model Data Structure */
struct tag_RTM {
    const char_T * volatile errorStatus;

    /*
     * Timing:
     * The following substructure contains information regarding
     * the timing information for the model.
     */
    struct {
        uint32_T clockTick0;
    } Timing;
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
extern ERROR_State_type ERROR_State;
extern PI_Para_type PI_Para;
extern PLL_type PLL;
extern PMSM_Para_type PMSM_Para;
extern SOSOIFOParam_type SOSOIFOParam;
extern SPEED_type SPEED;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S164>/Scope' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S8>/Scope3' : Unused code path elimination
 * Block '<S8>/Scope4' : Unused code path elimination
 * Block '<S8>/Scope5' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
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
 * hilite_system('NolinearObserver/Algorithm')    - opens subsystem NolinearObserver/Algorithm
 * hilite_system('NolinearObserver/Algorithm/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'NolinearObserver'
 * '<S1>'   : 'NolinearObserver/Algorithm'
 * '<S2>'   : 'NolinearObserver/Algorithm/Algorithm'
 * '<S3>'   : 'NolinearObserver/Algorithm/Chart1'
 * '<S4>'   : 'NolinearObserver/Algorithm/Algorithm/Clark_Trans'
 * '<S5>'   : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control'
 * '<S6>'   : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem'
 * '<S7>'   : 'NolinearObserver/Algorithm/Algorithm/IF_Switch_Logical'
 * '<S8>'   : 'NolinearObserver/Algorithm/Algorithm/NFO'
 * '<S9>'   : 'NolinearObserver/Algorithm/Algorithm/Park_Trans'
 * '<S10>'  : 'NolinearObserver/Algorithm/Algorithm/SVPWM_By_Average_Zero_Injection'
 * '<S11>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller'
 * '<S12>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1'
 * '<S13>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Anti-windup'
 * '<S14>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/D Gain'
 * '<S15>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Filter'
 * '<S16>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Filter ICs'
 * '<S17>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/I Gain'
 * '<S18>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Ideal P Gain'
 * '<S19>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Ideal P Gain Fdbk'
 * '<S20>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Integrator'
 * '<S21>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Integrator ICs'
 * '<S22>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/N Copy'
 * '<S23>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/N Gain'
 * '<S24>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/P Copy'
 * '<S25>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Parallel P Gain'
 * '<S26>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Reset Signal'
 * '<S27>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Saturation'
 * '<S28>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Saturation Fdbk'
 * '<S29>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Sum'
 * '<S30>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Sum Fdbk'
 * '<S31>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Tracking Mode'
 * '<S32>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Tracking Mode Sum'
 * '<S33>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Tsamp - Integral'
 * '<S34>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Tsamp - Ngain'
 * '<S35>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/postSat Signal'
 * '<S36>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/preSat Signal'
 * '<S37>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Anti-windup/Passthrough'
 * '<S38>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/D Gain/Disabled'
 * '<S39>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Filter/Disabled'
 * '<S40>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Filter ICs/Disabled'
 * '<S41>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/I Gain/External Parameters'
 * '<S42>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Ideal P Gain/Passthrough'
 * '<S43>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Integrator/Discrete'
 * '<S45>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Integrator ICs/Internal IC'
 * '<S46>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S47>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/N Gain/Disabled'
 * '<S48>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/P Copy/Disabled'
 * '<S49>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Parallel P Gain/External Parameters'
 * '<S50>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Reset Signal/Disabled'
 * '<S51>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Saturation/Enabled'
 * '<S52>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Saturation Fdbk/Disabled'
 * '<S53>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Sum/Sum_PI'
 * '<S54>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Sum Fdbk/Disabled'
 * '<S55>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Tracking Mode/Disabled'
 * '<S56>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S58>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/postSat Signal/Forward_Path'
 * '<S60>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller/preSat Signal/Forward_Path'
 * '<S61>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Anti-windup'
 * '<S62>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/D Gain'
 * '<S63>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Filter'
 * '<S64>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Filter ICs'
 * '<S65>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/I Gain'
 * '<S66>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Ideal P Gain'
 * '<S67>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Ideal P Gain Fdbk'
 * '<S68>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Integrator'
 * '<S69>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Integrator ICs'
 * '<S70>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/N Copy'
 * '<S71>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/N Gain'
 * '<S72>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/P Copy'
 * '<S73>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Parallel P Gain'
 * '<S74>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Reset Signal'
 * '<S75>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Saturation'
 * '<S76>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Saturation Fdbk'
 * '<S77>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Sum'
 * '<S78>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Sum Fdbk'
 * '<S79>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Tracking Mode'
 * '<S80>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Tracking Mode Sum'
 * '<S81>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Tsamp - Integral'
 * '<S82>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Tsamp - Ngain'
 * '<S83>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/postSat Signal'
 * '<S84>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/preSat Signal'
 * '<S85>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Anti-windup/Passthrough'
 * '<S86>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/D Gain/Disabled'
 * '<S87>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Filter/Disabled'
 * '<S88>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Filter ICs/Disabled'
 * '<S89>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/I Gain/External Parameters'
 * '<S90>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Ideal P Gain/Passthrough'
 * '<S91>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S92>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Integrator/Discrete'
 * '<S93>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Integrator ICs/Internal IC'
 * '<S94>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S95>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/N Gain/Disabled'
 * '<S96>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/P Copy/Disabled'
 * '<S97>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Parallel P Gain/External Parameters'
 * '<S98>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Reset Signal/Disabled'
 * '<S99>'  : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Saturation/Enabled'
 * '<S100>' : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Saturation Fdbk/Disabled'
 * '<S101>' : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Sum/Sum_PI'
 * '<S102>' : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Sum Fdbk/Disabled'
 * '<S103>' : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Tracking Mode/Disabled'
 * '<S104>' : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S105>' : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S106>' : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S107>' : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/postSat Signal/Forward_Path'
 * '<S108>' : 'NolinearObserver/Algorithm/Algorithm/Current_PI_control/PID Controller1/preSat Signal/Forward_Path'
 * '<S109>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller'
 * '<S110>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Anti-windup'
 * '<S111>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/D Gain'
 * '<S112>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Filter'
 * '<S113>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Filter ICs'
 * '<S114>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/I Gain'
 * '<S115>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Ideal P Gain'
 * '<S116>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S117>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Integrator'
 * '<S118>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Integrator ICs'
 * '<S119>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/N Copy'
 * '<S120>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/N Gain'
 * '<S121>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/P Copy'
 * '<S122>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Parallel P Gain'
 * '<S123>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Reset Signal'
 * '<S124>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Saturation'
 * '<S125>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Saturation Fdbk'
 * '<S126>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Sum'
 * '<S127>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Sum Fdbk'
 * '<S128>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Tracking Mode'
 * '<S129>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Tracking Mode Sum'
 * '<S130>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Tsamp - Integral'
 * '<S131>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Tsamp - Ngain'
 * '<S132>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/postSat Signal'
 * '<S133>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/preSat Signal'
 * '<S134>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Anti-windup/Passthrough'
 * '<S135>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/D Gain/Disabled'
 * '<S136>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Filter/Disabled'
 * '<S137>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Filter ICs/Disabled'
 * '<S138>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S139>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S140>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S141>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Integrator/Discrete'
 * '<S142>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S143>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S144>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/N Gain/Disabled'
 * '<S145>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/P Copy/Disabled'
 * '<S146>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S147>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S148>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Saturation/Enabled'
 * '<S149>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S150>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Sum/Sum_PI'
 * '<S151>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S152>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S153>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S154>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S155>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S156>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S157>' : 'NolinearObserver/Algorithm/Algorithm/Enabled Subsystem/PID Controller/preSat Signal/Forward_Path'
 * '<S158>' : 'NolinearObserver/Algorithm/Algorithm/IF_Switch_Logical/Forward_theta'
 * '<S159>' : 'NolinearObserver/Algorithm/Algorithm/IF_Switch_Logical/Forward_theta/integrator'
 * '<S160>' : 'NolinearObserver/Algorithm/Algorithm/IF_Switch_Logical/Forward_theta/integrator/RangeLimit'
 * '<S161>' : 'NolinearObserver/Algorithm/Algorithm/IF_Switch_Logical/Forward_theta/integrator/RangeLimit/If Action Subsystem'
 * '<S162>' : 'NolinearObserver/Algorithm/Algorithm/IF_Switch_Logical/Forward_theta/integrator/RangeLimit/If Action Subsystem1'
 * '<S163>' : 'NolinearObserver/Algorithm/Algorithm/IF_Switch_Logical/Forward_theta/integrator/RangeLimit/If Action Subsystem2'
 * '<S164>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL'
 * '<S165>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller'
 * '<S166>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/SpeedToTheta'
 * '<S167>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Anti-windup'
 * '<S168>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/D Gain'
 * '<S169>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Filter'
 * '<S170>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Filter ICs'
 * '<S171>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/I Gain'
 * '<S172>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Ideal P Gain'
 * '<S173>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S174>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Integrator'
 * '<S175>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Integrator ICs'
 * '<S176>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/N Copy'
 * '<S177>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/N Gain'
 * '<S178>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/P Copy'
 * '<S179>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Parallel P Gain'
 * '<S180>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Reset Signal'
 * '<S181>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Saturation'
 * '<S182>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Saturation Fdbk'
 * '<S183>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Sum'
 * '<S184>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Sum Fdbk'
 * '<S185>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Tracking Mode'
 * '<S186>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Tracking Mode Sum'
 * '<S187>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Tsamp - Integral'
 * '<S188>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Tsamp - Ngain'
 * '<S189>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/postSat Signal'
 * '<S190>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/preSat Signal'
 * '<S191>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S192>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S193>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S194>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/D Gain/Disabled'
 * '<S195>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Filter/Disabled'
 * '<S196>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Filter ICs/Disabled'
 * '<S197>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S198>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S199>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S200>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Integrator/Discrete'
 * '<S201>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S202>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S203>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/N Gain/Disabled'
 * '<S204>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/P Copy/Disabled'
 * '<S205>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S206>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Reset Signal/Disabled'
 * '<S207>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Saturation/Enabled'
 * '<S208>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S209>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Sum/Sum_PI'
 * '<S210>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S211>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S212>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S213>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S214>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S215>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S216>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S217>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/SpeedToTheta/Angle_Limit'
 * '<S218>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/SpeedToTheta/Angle_Limit/If Action Subsystem'
 * '<S219>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/SpeedToTheta/Angle_Limit/If Action Subsystem1'
 * '<S220>' : 'NolinearObserver/Algorithm/Algorithm/NFO/PLL/SpeedToTheta/Angle_Limit/If Action Subsystem2'
 * '<S221>' : 'NolinearObserver/Algorithm/Algorithm/SVPWM_By_Average_Zero_Injection/Anti_Park_Trans'
 * '<S222>' : 'NolinearObserver/Algorithm/Algorithm/SVPWM_By_Average_Zero_Injection/SVPWM'
 * '<S223>' : 'NolinearObserver/Algorithm/Algorithm/SVPWM_By_Average_Zero_Injection/SVPWM/Anti_Clark_Trans'
 * '<S224>' : 'NolinearObserver/Algorithm/Chart1/Low_judge'
 * '<S225>' : 'NolinearObserver/Algorithm/Chart1/Over_judge'
 */
#endif                                 /* RTW_HEADER_Algorithm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
