/*
 * File: Algorithm.c
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

#include "Algorithm.h"
#include "rtwtypes.h"
#include <math.h>
#include "mw_cmsis.h"

/* Named constants for Chart: '<S2>/IF_Switch_Logical' */
#define IN_Backward                    ((uint8_T)1U)
#define IN_Forward                     ((uint8_T)2U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_Speed_interve               ((uint8_T)3U)
#define IN_Speed_interve1              ((uint8_T)4U)
#define IN_Swich_over                  ((uint8_T)1U)
#define IN_direction_judge             ((uint8_T)5U)
#define IN_tcos_state1                 ((uint8_T)2U)
#define IN_tcos_state2                 ((uint8_T)3U)

/* Named constants for Chart: '<S1>/Chart1' */
#define IN_None                        ((uint8_T)1U)
#define IN_Out                         ((uint8_T)2U)

/* Exported data definition */

/* Definition for custom storage class: Struct */
ERROR_State_type ERROR_State;
PI_Para_type PI_Para = {
    /* current_bandwidth */
    2216.0F
};

PLL_type PLL = {
    /* PLL_KI */
    20000.0F,

    /* PLL_KP */
    500.0F
};

PMSM_Para_type PMSM_Para = {
    /* flux */
    0.0065
};

SOSOIFOParam_type SOSOIFOParam = {
    /* IF_Initial */
    30.0F
};

SPEED_type SPEED = {
    /* SPEED_KI */
    0.03F,

    /* SPEED_KP */
    0.004F
};

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void Clark_Trans(real32_T rtu_Ia, real32_T rtu_Ib, real32_T rtu_Ic,
                        real32_T *rty_I_alpha, real32_T *rty_I_beta);
static void Current_PI_control(real32_T rtu_refD, real32_T rtu_realD, real32_T
    rtu_refQ, real32_T rtu_realQ, real32_T *rty_Ud, real32_T *rty_Uq,
    DW_Current_PI_control *localDW);
static void Forward_theta_Enable(DW_Forward_theta *localDW);
static void Forward_theta(RT_MODEL * const rtM, real32_T rtu_direction, real32_T
    *rty_IF_theta, real32_T *rty_IF_omega, DW_Forward_theta *localDW);
static void Park_Trans(real32_T rtu_alpha, real32_T rtu_beta, const real32_T
                       rtu_SinCos[2], real32_T *rty_u_d, real32_T *rty_u_q);
static void SVPWM_By_Average_Zero_Injection(real32_T rtu_d, real32_T rtu_q,
    const real32_T rtu_SinCos[2], real32_T rtu_Udc, real_T rtu_CCR, real32_T
    rtyyy_TaTbTc[3], real32_T *rty_U_alpha, real32_T *rty_U_beta);
static void Over_judge(real32_T rtu_Input, real32_T *rty_Out, DW_Over_judge
                       *localDW);
static void Low_judge(real32_T rtu_Input, real32_T *rty_Out, DW_Low_judge
                      *localDW);

/* Output and update for atomic system: '<S2>/Clark_Trans' */
static void Clark_Trans(real32_T rtu_Ia, real32_T rtu_Ib, real32_T rtu_Ic,
                        real32_T *rty_I_alpha, real32_T *rty_I_beta)
{
    /* Sum: '<S4>/Add1' */
    *rty_I_alpha = rtu_Ib + rtu_Ic;

    /* Gain: '<S4>/Gain' */
    *rty_I_alpha *= 0.5F;

    /* Sum: '<S4>/Add' */
    *rty_I_alpha = rtu_Ia - *rty_I_alpha;

    /* Gain: '<S4>/Gain2' */
    *rty_I_alpha *= 0.666666687F;

    /* Sum: '<S4>/Add2' */
    *rty_I_beta = rtu_Ib - rtu_Ic;

    /* Gain: '<S4>/Gain1' */
    *rty_I_beta *= 0.577350259F;
}

/* Output and update for atomic system: '<S2>/Current_PI_control' */
static void Current_PI_control(real32_T rtu_refD, real32_T rtu_realD, real32_T
    rtu_refQ, real32_T rtu_realQ, real32_T *rty_Ud, real32_T *rty_Uq,
    DW_Current_PI_control *localDW)
{
    real32_T rtb_IProdOut;
    real32_T rtb_Sum_g;

    /* Sum: '<S5>/Sum1' */
    rtb_Sum_g = rtu_refD - rtu_realD;

    /* Sum: '<S53>/Sum' incorporates:
     *  Constant: '<S5>/Constant1'
     *  DiscreteIntegrator: '<S44>/Integrator'
     *  Gain: '<S5>/Gain'
     *  Product: '<S49>/PProd Out'
     */
    *rty_Ud = PI_Para.current_bandwidth * 8.5E-5F * rtb_Sum_g +
        localDW->Integrator_DSTATE;

    /* Saturate: '<S51>/Saturation' */
    if (*rty_Ud > 10.0F) {
        *rty_Ud = 10.0F;
    } else if (*rty_Ud < -10.0F) {
        *rty_Ud = -10.0F;
    }

    /* End of Saturate: '<S51>/Saturation' */

    /* Product: '<S41>/IProd Out' incorporates:
     *  Constant: '<S5>/Constant3'
     *  Gain: '<S5>/Gain1'
     */
    rtb_IProdOut = PI_Para.current_bandwidth * 0.03F * rtb_Sum_g;

    /* Sum: '<S5>/Sum' */
    rtb_Sum_g = rtu_refQ - rtu_realQ;

    /* Sum: '<S101>/Sum' incorporates:
     *  Constant: '<S5>/Constant2'
     *  DiscreteIntegrator: '<S92>/Integrator'
     *  Gain: '<S5>/Gain2'
     *  Product: '<S97>/PProd Out'
     */
    *rty_Uq = PI_Para.current_bandwidth * 8.5E-5F * rtb_Sum_g +
        localDW->Integrator_DSTATE_c;

    /* Saturate: '<S99>/Saturation' */
    if (*rty_Uq > 10.0F) {
        *rty_Uq = 10.0F;
    } else if (*rty_Uq < -10.0F) {
        *rty_Uq = -10.0F;
    }

    /* End of Saturate: '<S99>/Saturation' */

    /* Update for DiscreteIntegrator: '<S44>/Integrator' */
    localDW->Integrator_DSTATE += 0.0001F * rtb_IProdOut;

    /* Update for DiscreteIntegrator: '<S92>/Integrator' incorporates:
     *  Constant: '<S5>/Constant4'
     *  Gain: '<S5>/Gain3'
     *  Product: '<S89>/IProd Out'
     */
    localDW->Integrator_DSTATE_c += PI_Para.current_bandwidth * 0.03F *
        rtb_Sum_g * 0.0001F;
}

/* Enable for function-call system: '<S7>/Forward_theta' */
static void Forward_theta_Enable(DW_Forward_theta *localDW)
{
    localDW->Forward_theta_RESET_ELAPS_T = true;

    /* Enable for DiscreteIntegrator: '<S158>/Discrete-Time Integrator' */
    localDW->DiscreteTimeIntegrator_SYSTEM_E = 1U;
}

/* Output and update for function-call system: '<S7>/Forward_theta' */
static void Forward_theta(RT_MODEL * const rtM, real32_T rtu_direction, real32_T
    *rty_IF_theta, real32_T *rty_IF_omega, DW_Forward_theta *localDW)
{
    real32_T DiscreteTimeIntegrator;
    real32_T rtb_yk;
    uint32_T Forward_theta_ELAPS_T;
    if (localDW->Forward_theta_RESET_ELAPS_T) {
        Forward_theta_ELAPS_T = 0U;
    } else {
        Forward_theta_ELAPS_T = rtM->Timing.clockTick0 -
            localDW->Forward_theta_PREV_T;
    }

    localDW->Forward_theta_PREV_T = rtM->Timing.clockTick0;
    localDW->Forward_theta_RESET_ELAPS_T = false;

    /* DiscreteIntegrator: '<S158>/Discrete-Time Integrator' */
    if (localDW->DiscreteTimeIntegrator_SYSTEM_E != 0) {
        /* DiscreteIntegrator: '<S158>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator = localDW->DiscreteTimeIntegrator_DSTATE;
    } else {
        /* DiscreteIntegrator: '<S158>/Discrete-Time Integrator' */
        DiscreteTimeIntegrator = 0.0001F * (real32_T)Forward_theta_ELAPS_T
            * localDW->DiscreteTimeIntegrator_PREV_U +
            localDW->DiscreteTimeIntegrator_DSTATE;
    }

    /* End of DiscreteIntegrator: '<S158>/Discrete-Time Integrator' */

    /* Product: '<S158>/Product' */
    *rty_IF_omega = DiscreteTimeIntegrator * rtu_direction;

    /* UnitDelay: '<S159>/Unit Delay' */
    *rty_IF_theta = localDW->UnitDelay_DSTATE;

    /* Sum: '<S159>/Sum1' incorporates:
     *  Gain: '<S159>/Ts'
     */
    rtb_yk = 0.0001F * *rty_IF_omega + *rty_IF_theta;

    /* Update for DiscreteIntegrator: '<S158>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S158>/Constant'
     */
    localDW->DiscreteTimeIntegrator_SYSTEM_E = 0U;
    localDW->DiscreteTimeIntegrator_DSTATE = DiscreteTimeIntegrator;
    localDW->DiscreteTimeIntegrator_PREV_U = SOSOIFOParam.IF_Initial;

    /* If: '<S160>/If' incorporates:
     *  Constant: '<S160>/Constant'
     *  Constant: '<S160>/Constant1'
     *  RelationalOperator: '<S160>/Relational Operator'
     *  RelationalOperator: '<S160>/Relational Operator1'
     */
    if (rtb_yk > 6.28318548F) {
        /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S162>/Action Port'
         */
        /* Update for UnitDelay: '<S159>/Unit Delay' incorporates:
         *  Constant: '<S162>/Constant'
         *  Sum: '<S162>/Sum'
         */
        localDW->UnitDelay_DSTATE = rtb_yk - 6.28318548F;

        /* End of Outputs for SubSystem: '<S160>/If Action Subsystem1' */
    } else if (rtb_yk < 0.0F) {
        /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem' incorporates:
         *  ActionPort: '<S161>/Action Port'
         */
        /* Update for UnitDelay: '<S159>/Unit Delay' incorporates:
         *  Constant: '<S161>/Constant'
         *  Sum: '<S161>/Sum'
         */
        localDW->UnitDelay_DSTATE = rtb_yk + 6.28318548F;

        /* End of Outputs for SubSystem: '<S160>/If Action Subsystem' */
    } else {
        /* Outputs for IfAction SubSystem: '<S160>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S163>/Action Port'
         */
        /* Update for UnitDelay: '<S159>/Unit Delay' incorporates:
         *  SignalConversion generated from: '<S163>/In1'
         */
        localDW->UnitDelay_DSTATE = rtb_yk;

        /* End of Outputs for SubSystem: '<S160>/If Action Subsystem2' */
    }

    /* End of If: '<S160>/If' */
}

/* Output and update for atomic system: '<S2>/Park_Trans' */
static void Park_Trans(real32_T rtu_alpha, real32_T rtu_beta, const real32_T
                       rtu_SinCos[2], real32_T *rty_u_d, real32_T *rty_u_q)
{
    /* Product: '<S9>/Product' */
    *rty_u_d = rtu_alpha * rtu_SinCos[1];

    /* Product: '<S9>/Product1' */
    *rty_u_q = rtu_beta * rtu_SinCos[0];

    /* Sum: '<S9>/Add' */
    *rty_u_d += *rty_u_q;

    /* Product: '<S9>/Product2' */
    *rty_u_q = rtu_alpha * rtu_SinCos[0];

    /* Sum: '<S9>/Add1' incorporates:
     *  Product: '<S9>/Product3'
     */
    *rty_u_q = rtu_beta * rtu_SinCos[1] - *rty_u_q;
}

/* Output and update for atomic system: '<S2>/SVPWM_By_Average_Zero_Injection' */
static void SVPWM_By_Average_Zero_Injection(real32_T rtu_d, real32_T rtu_q,
    const real32_T rtu_SinCos[2], real32_T rtu_Udc, real_T rtu_CCR, real32_T
    rtyyy_TaTbTc[3], real32_T *rty_U_alpha, real32_T *rty_U_beta)
{
    real32_T rtb_Add1;
    real32_T rtb_Add2;
    real32_T rtb_Add_l;

    /* Product: '<S221>/Product' */
    *rty_U_alpha = rtu_d * rtu_SinCos[1];

    /* Sum: '<S221>/Add' incorporates:
     *  Product: '<S221>/Product1'
     */
    *rty_U_alpha -= rtu_q * rtu_SinCos[0];

    /* Gain: '<S223>/Gain' */
    rtb_Add2 = 0.5F * *rty_U_alpha;

    /* Sum: '<S221>/Add1' incorporates:
     *  Product: '<S221>/Product2'
     *  Product: '<S221>/Product3'
     */
    *rty_U_beta = rtu_d * rtu_SinCos[0] + rtu_q * rtu_SinCos[1];

    /* Gain: '<S223>/Gain1' */
    rtb_Add_l = 0.866025388F * *rty_U_beta;

    /* Sum: '<S223>/Add' */
    rtb_Add1 = rtb_Add_l - rtb_Add2;

    /* Sum: '<S223>/Add1' */
    rtb_Add2 = (0.0F - rtb_Add2) - rtb_Add_l;

    /* Gain: '<S222>/Gain' incorporates:
     *  MinMax: '<S222>/Max'
     *  MinMax: '<S222>/Max1'
     *  Sum: '<S222>/Add3'
     */
    rtb_Add_l = (fmaxf(fmaxf(*rty_U_alpha, rtb_Add1), rtb_Add2) + fminf(fminf
                  (*rty_U_alpha, rtb_Add1), rtb_Add2)) * -0.5F;

    /* Product: '<S222>/Product' incorporates:
     *  Constant: '<S222>/Constant'
     *  DataTypeConversion: '<S222>/Data Type Conversion'
     *  Gain: '<S222>/Gain1'
     *  Product: '<S222>/Divide'
     *  Sum: '<S222>/Add'
     *  Sum: '<S222>/Add1'
     *  Sum: '<S222>/Add2'
     *  Sum: '<S222>/Add4'
     */
    rtyyy_TaTbTc[0] = (-(*rty_U_alpha + rtb_Add_l) / rtu_Udc + 0.5F) * (real32_T)
        rtu_CCR;
    rtyyy_TaTbTc[1] = (-(rtb_Add1 + rtb_Add_l) / rtu_Udc + 0.5F) * (real32_T)
        rtu_CCR;
    rtyyy_TaTbTc[2] = (-(rtb_Add2 + rtb_Add_l) / rtu_Udc + 0.5F) * (real32_T)
        rtu_CCR;
}

/* Output and update for function-call system: '<S3>/Over_judge' */
static void Over_judge(real32_T rtu_Input, real32_T *rty_Out, DW_Over_judge
                       *localDW)
{
    /* Relay: '<S225>/Relay' */
    localDW->Relay_Mode = ((rtu_Input >= 28.0F) || ((!(rtu_Input <= 25.0F)) &&
                            localDW->Relay_Mode));
    *rty_Out = localDW->Relay_Mode;
}

/* Output and update for function-call system: '<S3>/Low_judge' */
static void Low_judge(real32_T rtu_Input, real32_T *rty_Out, DW_Low_judge
                      *localDW)
{
    /* Relay: '<S224>/Relay' */
    localDW->Relay_Mode = ((rtu_Input >= 20.0F) || ((!(rtu_Input <= 18.0F)) &&
                            localDW->Relay_Mode));

    /* DataTypeConversion: '<S224>/Data Type Conversion1' incorporates:
     *  DataTypeConversion: '<S224>/Data Type Conversion'
     *  Logic: '<S224>/NOR'
     *  Relay: '<S224>/Relay'
     */
    *rty_Out = (real32_T)!localDW->Relay_Mode;
}

/* Model step function */
void Algorithm_step(void)
{
    real_T rtb_Add15;
    real_T rtb_Add18;
    real_T rtb_Gain11;
    real_T rtb_Gain12;
    real_T rtb_Merge;
    real32_T rtb_TmpSignalConversionAtPark_0[2];
    real32_T Product_p;
    real32_T error_theta;
    real32_T iqavg;
    real32_T rtb_Delay;
    real32_T rtb_Sum;
    int8_T tmp;
    int8_T tmp_0;
    boolean_T rtb_AND3;

    /* Chart: '<S1>/Chart1' incorporates:
     *  Inport: '<Root>/Go_Flag'
     *  Inport: '<Root>/Udc'
     */
    if (rtDW.is_active_c2_Algorithm == 0U) {
        rtDW.is_active_c2_Algorithm = 1U;
        rtDW.is_c2_Algorithm = IN_None;
    } else if (rtDW.is_c2_Algorithm == IN_None) {
        if ((rtU.Go_Flag == 1.0F) && (ERROR_State.STOP == 0.0F)) {
            /* Outputs for Function Call SubSystem: '<S3>/Over_judge' */
            Over_judge(rtU.Udc, &(ERROR_State.Over_V), &rtDW.Over_judge_d);

            /* End of Outputs for SubSystem: '<S3>/Over_judge' */

            /* Outputs for Function Call SubSystem: '<S3>/Low_judge' */
            Low_judge(rtU.Udc, &(ERROR_State.Low_V), &rtDW.Low_judge_l);

            /* End of Outputs for SubSystem: '<S3>/Low_judge' */
            ERROR_State.STOP = ERROR_State.Low_V + ERROR_State.Over_V;
            rtDW.is_c2_Algorithm = IN_Out;
        } else {
            /* Outputs for Function Call SubSystem: '<S3>/Over_judge' */
            Over_judge(rtU.Udc, &(ERROR_State.Over_V), &rtDW.Over_judge_d);

            /* End of Outputs for SubSystem: '<S3>/Over_judge' */

            /* Outputs for Function Call SubSystem: '<S3>/Low_judge' */
            Low_judge(rtU.Udc, &(ERROR_State.Low_V), &rtDW.Low_judge_l);

            /* End of Outputs for SubSystem: '<S3>/Low_judge' */
            ERROR_State.STOP = ERROR_State.Low_V + ERROR_State.Over_V;
        }

        /* case IN_Out: */
    } else if ((ERROR_State.Over_V == 1.0F) || (ERROR_State.Low_V == 1.0F)) {
        rtDW.Go = 0.0;
        rtDW.is_c2_Algorithm = IN_None;
    } else if (rtU.Go_Flag == 0.0F) {
        rtDW.is_c2_Algorithm = IN_None;
    } else {
        /* Outputs for Function Call SubSystem: '<S3>/Over_judge' */
        Over_judge(rtU.Udc, &(ERROR_State.Over_V), &rtDW.Over_judge_d);

        /* End of Outputs for SubSystem: '<S3>/Over_judge' */

        /* Outputs for Function Call SubSystem: '<S3>/Low_judge' */
        Low_judge(rtU.Udc, &(ERROR_State.Low_V), &rtDW.Low_judge_l);

        /* End of Outputs for SubSystem: '<S3>/Low_judge' */
        ERROR_State.STOP = ERROR_State.Low_V + ERROR_State.Over_V;
        rtDW.Go = 1.0;
    }

    /* End of Chart: '<S1>/Chart1' */

    /* Outputs for Enabled SubSystem: '<S1>/Algorithm' incorporates:
     *  EnablePort: '<S2>/Enable'
     */
    if (rtDW.Go > 0.0) {
        if (!rtDW.Algorithm_MODE) {
            /* Enable for Chart: '<S2>/IF_Switch_Logical' incorporates:
             *  SubSystem: '<S7>/Forward_theta'
             */
            Forward_theta_Enable(&rtDW.Forward_theta_p);
            rtDW.Algorithm_MODE = true;
        }

        /* Delay: '<S2>/Delay' */
        rtb_Delay = rtDW.Saturation_p;

        /* Chart: '<S2>/IF_Switch_Logical' incorporates:
         *  Delay: '<S2>/Delay'
         *  Inport: '<Root>/Ref_Iq'
         *  Inport: '<Root>/Ref_RPM'
         *  UnitDelay: '<S166>/Unit Delay'
         */
        if (rtDW.is_active_c3_Algorithm == 0U) {
            rtDW.is_active_c3_Algorithm = 1U;
            rtDW.omega1 = 80.0F;
            rtDW.omega2 = 81.0F;
            rtDW.is_c3_Algorithm = IN_direction_judge;
            if (rtU.Ref_RPM > 30.0F) {
                rtDW.direction = 1.0F;
            } else if (rtU.Ref_RPM < -30.0F) {
                rtDW.direction = -1.0F;
            }
        } else {
            switch (rtDW.is_c3_Algorithm) {
              case IN_Backward:
                if ((rtDW.enable == 1.0F) && (rtDW.Saturation_p < rtDW.Iq_keep))
                {
                    rtDW.is_Backward = IN_NO_ACTIVE_CHILD;
                    rtDW.is_c3_Algorithm = IN_Speed_interve1;
                    rtDW.Iq_out = rtDW.Saturation_p;
                    rtDW.Use_Theta = rtDW.UnitDelay_DSTATE;
                } else {
                    /* Outputs for Function Call SubSystem: '<S7>/Forward_theta' */
                    Forward_theta(rtM, rtDW.direction, &rtb_Delay, &Product_p,
                                  &rtDW.Forward_theta_p);

                    /* End of Outputs for SubSystem: '<S7>/Forward_theta' */
                    error_theta = rtDW.UnitDelay_DSTATE - rtb_Delay;
                    iqavg = rtU.Ref_Iq * cosf(error_theta);
                    switch (rtDW.is_Backward) {
                      case IN_Swich_over:
                        rtDW.Iq_out = rtDW.Iq_keep;
                        rtDW.Use_Theta = rtDW.UnitDelay_DSTATE;
                        rtDW.enable = 1.0F;
                        break;

                      case IN_tcos_state1:
                        rtb_Sum = fabsf(Product_p);
                        if ((rtDW.omega1 < rtb_Sum) && (rtb_Sum < rtDW.omega2))
                        {
                            rtDW.is_Backward = IN_tcos_state2;
                            Product_p = cosf((rtb_Sum - rtDW.omega1) /
                                             (rtDW.omega2 - rtDW.omega1) *
                                             3.14159274F / 2.0F);
                            rtDW.Iq_out = iqavg / cosf(Product_p * error_theta);
                            rtDW.Use_Theta = (1.0F - Product_p) *
                                rtDW.UnitDelay_DSTATE + Product_p * rtb_Delay;
                            rtDW.Iq_keep = rtDW.Iq_out;
                        } else {
                            rtDW.Iq_out = rtU.Ref_Iq;
                            rtDW.Use_Theta = 0.0F * rtDW.UnitDelay_DSTATE +
                                rtb_Delay;
                        }
                        break;

                      default:
                        /* case IN_tcos_state2: */
                        rtb_Sum = fabsf(Product_p);
                        if (rtb_Sum >= rtDW.omega2) {
                            rtDW.is_Backward = IN_Swich_over;
                            rtDW.Iq_out = rtDW.Iq_keep;
                            rtDW.Use_Theta = rtDW.UnitDelay_DSTATE;
                            rtDW.enable = 1.0F;
                        } else {
                            Product_p = cosf((rtb_Sum - rtDW.omega1) /
                                             (rtDW.omega2 - rtDW.omega1) *
                                             3.14159274F / 2.0F);
                            rtDW.Iq_out = iqavg / cosf(Product_p * error_theta);
                            rtDW.Use_Theta = (1.0F - Product_p) *
                                rtDW.UnitDelay_DSTATE + Product_p * rtb_Delay;
                            rtDW.Iq_keep = rtDW.Iq_out;
                        }
                        break;
                    }
                }
                break;

              case IN_Forward:
                if ((rtDW.enable == 1.0F) && (rtDW.Saturation_p > rtDW.Iq_keep))
                {
                    rtDW.is_Forward = IN_NO_ACTIVE_CHILD;
                    rtDW.is_c3_Algorithm = IN_Speed_interve;
                    rtDW.Iq_out = rtDW.Saturation_p;
                    rtDW.Use_Theta = rtDW.UnitDelay_DSTATE;
                } else {
                    /* Outputs for Function Call SubSystem: '<S7>/Forward_theta' */
                    Forward_theta(rtM, rtDW.direction, &rtb_Delay, &Product_p,
                                  &rtDW.Forward_theta_p);

                    /* End of Outputs for SubSystem: '<S7>/Forward_theta' */
                    error_theta = rtDW.UnitDelay_DSTATE - rtb_Delay;
                    iqavg = rtU.Ref_Iq * cosf(error_theta);
                    switch (rtDW.is_Forward) {
                      case IN_Swich_over:
                        rtDW.enable = 1.0F;
                        rtDW.Iq_out = rtDW.Iq_keep;
                        rtDW.Use_Theta = rtDW.UnitDelay_DSTATE;
                        break;

                      case IN_tcos_state1:
                        rtb_Sum = fabsf(Product_p);
                        if ((rtDW.omega1 < rtb_Sum) && (rtb_Sum < rtDW.omega2))
                        {
                            rtDW.is_Forward = IN_tcos_state2;
                            Product_p = cosf((rtb_Sum - rtDW.omega1) /
                                             (rtDW.omega2 - rtDW.omega1) *
                                             3.14159274F / 2.0F);
                            rtDW.Iq_out = iqavg / cosf(Product_p * error_theta);
                            rtDW.Use_Theta = (1.0F - Product_p) *
                                rtDW.UnitDelay_DSTATE + Product_p * rtb_Delay;
                            rtDW.Iq_keep = rtDW.Iq_out;
                        } else {
                            rtDW.Iq_out = rtU.Ref_Iq;
                            rtDW.Use_Theta = 0.0F * rtDW.UnitDelay_DSTATE +
                                rtb_Delay;
                        }
                        break;

                      default:
                        /* case IN_tcos_state2: */
                        rtb_Sum = fabsf(Product_p);
                        if (rtb_Sum >= rtDW.omega2) {
                            rtDW.is_Forward = IN_Swich_over;
                            rtDW.enable = 1.0F;
                            rtDW.Iq_out = rtDW.Iq_keep;
                            rtDW.Use_Theta = rtDW.UnitDelay_DSTATE;
                        } else {
                            Product_p = cosf((rtb_Sum - rtDW.omega1) /
                                             (rtDW.omega2 - rtDW.omega1) *
                                             3.14159274F / 2.0F);
                            rtDW.Iq_out = iqavg / cosf(Product_p * error_theta);
                            rtDW.Use_Theta = (1.0F - Product_p) *
                                rtDW.UnitDelay_DSTATE + Product_p * rtb_Delay;
                            rtDW.Iq_keep = rtDW.Iq_out;
                        }
                        break;
                    }
                }
                break;

              case IN_Speed_interve:
                rtDW.Iq_out = rtDW.Saturation_p;
                rtDW.Use_Theta = rtDW.UnitDelay_DSTATE;
                break;

              case IN_Speed_interve1:
                rtDW.Iq_out = rtDW.Saturation_p;
                rtDW.Use_Theta = rtDW.UnitDelay_DSTATE;
                break;

              default:
                /* case IN_direction_judge: */
                if (rtDW.direction == 1.0F) {
                    rtDW.is_c3_Algorithm = IN_Forward;

                    /* Outputs for Function Call SubSystem: '<S7>/Forward_theta' */
                    Forward_theta(rtM, 1.0F, &rtb_Delay, &Product_p,
                                  &rtDW.Forward_theta_p);

                    /* End of Outputs for SubSystem: '<S7>/Forward_theta' */
                    rtDW.Iq_keep = 0.0F;
                    rtDW.is_Forward = IN_tcos_state1;
                    rtDW.Iq_out = rtU.Ref_Iq;
                    rtDW.Use_Theta = 0.0F * rtDW.UnitDelay_DSTATE + rtb_Delay;
                } else if (rtDW.direction == -1.0F) {
                    rtDW.is_c3_Algorithm = IN_Backward;

                    /* Outputs for Function Call SubSystem: '<S7>/Forward_theta' */
                    Forward_theta(rtM, -1.0F, &rtb_Delay, &Product_p,
                                  &rtDW.Forward_theta_p);

                    /* End of Outputs for SubSystem: '<S7>/Forward_theta' */
                    rtDW.Iq_keep = 0.0F;
                    rtDW.is_Backward = IN_tcos_state1;
                    rtDW.Iq_out = rtU.Ref_Iq;
                    rtDW.Use_Theta = 0.0F * rtDW.UnitDelay_DSTATE + rtb_Delay;
                }
                break;
            }
        }

        /* End of Chart: '<S2>/IF_Switch_Logical' */

        /* SignalConversion generated from: '<S2>/Park_Trans' incorporates:
         *  SignalConversion generated from: '<S2>/SVPWM_By_Average_Zero_Injection'
         *  Trigonometry: '<S2>/Sin2'
         *  Trigonometry: '<S2>/Sin3'
         */
        rtb_TmpSignalConversionAtPark_0[0] = sinf(rtDW.Use_Theta);
        rtb_TmpSignalConversionAtPark_0[1] = cosf(rtDW.Use_Theta);

        /* Saturate: '<S2>/Saturation' */
        if (rtDW.Iq_out > 10.0F) {
            rtb_Delay = 10.0F;
        } else if (rtDW.Iq_out < -10.0F) {
            rtb_Delay = -10.0F;
        } else {
            rtb_Delay = rtDW.Iq_out;
        }

        /* End of Saturate: '<S2>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/Clark_Trans' */
        /* Inport: '<Root>/Iabc' */
        Clark_Trans(rtU.Iabc[0], rtU.Iabc[1], rtU.Iabc[2], &iqavg, &Product_p);

        /* End of Outputs for SubSystem: '<S2>/Clark_Trans' */

        /* Outputs for Atomic SubSystem: '<S2>/Park_Trans' */
        /* SignalConversion generated from: '<S2>/Park_Trans' */
        Park_Trans(iqavg, Product_p, rtb_TmpSignalConversionAtPark_0,
                   &error_theta, &rtb_Sum);

        /* End of Outputs for SubSystem: '<S2>/Park_Trans' */

        /* Outputs for Atomic SubSystem: '<S2>/Current_PI_control' */
        /* Inport: '<Root>/Ref_Id' incorporates:
         *  Sum: '<S2>/Add'
         */
        Current_PI_control(rtU.Ref_Id, error_theta, rtb_Delay, rtb_Sum,
                           &rtb_Delay, &rtb_Sum, &rtDW.Current_PI_control_e);

        /* End of Outputs for SubSystem: '<S2>/Current_PI_control' */

        /* Outputs for Atomic SubSystem: '<S2>/SVPWM_By_Average_Zero_Injection' */
        /* Inport: '<Root>/Udc' incorporates:
         *  Inport: '<Root>/CCR'
         *  Outport: '<Root>/Tabc'
         */
        SVPWM_By_Average_Zero_Injection(rtb_Delay, rtb_Sum,
            rtb_TmpSignalConversionAtPark_0, rtU.Udc, rtU.CCR, rtY.Tabc,
            &error_theta, &rtb_Sum);

        /* End of Outputs for SubSystem: '<S2>/SVPWM_By_Average_Zero_Injection' */

        /* Sum: '<S8>/Add18' incorporates:
         *  Gain: '<S8>/Gain10'
         *  Gain: '<S8>/Gain13'
         *  Gain: '<S8>/Gain14'
         *  Sum: '<S8>/Add10'
         *  Sum: '<S8>/Add11'
         *  UnitDelay: '<S8>/Unit Delay4'
         *  UnitDelay: '<S8>/Unit Delay6'
         */
        rtb_Add18 = ((error_theta - 0.03F * iqavg) + 50000.0 *
                     rtDW.UnitDelay4_DSTATE) * 0.0001 + rtDW.UnitDelay6_DSTATE;

        /* Sum: '<S8>/Add12' incorporates:
         *  Gain: '<S8>/Gain15'
         */
        rtb_Gain11 = rtb_Add18 - 8.5E-5F * iqavg;

        /* Sum: '<S8>/Add15' incorporates:
         *  Gain: '<S8>/Gain16'
         *  Gain: '<S8>/Gain17'
         *  Gain: '<S8>/Gain18'
         *  Sum: '<S8>/Add14'
         *  Sum: '<S8>/Add19'
         *  UnitDelay: '<S8>/Unit Delay5'
         *  UnitDelay: '<S8>/Unit Delay7'
         */
        rtb_Add15 = ((rtb_Sum - 0.03F * Product_p) + 50000.0 *
                     rtDW.UnitDelay5_DSTATE) * 0.0001 + rtDW.UnitDelay7_DSTATE;

        /* Sum: '<S8>/Add13' incorporates:
         *  Gain: '<S8>/Gain19'
         */
        rtb_Gain12 = rtb_Add15 - 8.5E-5F * Product_p;

        /* Sum: '<S8>/Add17' incorporates:
         *  Constant: '<S8>/Constant1'
         *  Math: '<S8>/Math Function3'
         *  Math: '<S8>/Math Function4'
         *  Math: '<S8>/Math Function5'
         *  Sum: '<S8>/Add16'
         */
        rtb_Merge = PMSM_Para.flux * PMSM_Para.flux - (rtb_Gain11 * rtb_Gain11 +
            rtb_Gain12 * rtb_Gain12);

        /* Update for UnitDelay: '<S8>/Unit Delay4' incorporates:
         *  Product: '<S8>/Product2'
         */
        rtDW.UnitDelay4_DSTATE = rtb_Gain11 * rtb_Merge;

        /* Update for UnitDelay: '<S8>/Unit Delay5' incorporates:
         *  Product: '<S8>/Product3'
         */
        rtDW.UnitDelay5_DSTATE = rtb_Merge * rtb_Gain12;

        /* Sum: '<S164>/Add' incorporates:
         *  DataTypeConversion: '<S8>/Data Type Conversion1'
         *  DataTypeConversion: '<S8>/Data Type Conversion2'
         *  Gain: '<S8>/Gain11'
         *  Gain: '<S8>/Gain12'
         *  Product: '<S164>/Product'
         *  Product: '<S164>/Product1'
         *  Trigonometry: '<S164>/Cos'
         *  Trigonometry: '<S164>/Cos1'
         *  UnitDelay: '<S166>/Unit Delay'
         */
        rtb_Delay = (real32_T)(1.0 / PMSM_Para.flux * rtb_Gain12) * arm_cos_f32
            (rtDW.UnitDelay_DSTATE) - (real32_T)(1.0 / PMSM_Para.flux *
            rtb_Gain11) * arm_sin_f32(rtDW.UnitDelay_DSTATE);

        /* Sum: '<S209>/Sum' incorporates:
         *  DiscreteIntegrator: '<S200>/Integrator'
         *  Gain: '<S205>/Proportional Gain'
         */
        rtb_Sum = PLL.PLL_KP * rtb_Delay + rtDW.Integrator_DSTATE;

        /* DeadZone: '<S193>/DeadZone' */
        if (rtb_Sum > 1832.5957F) {
            error_theta = rtb_Sum - 1832.5957F;
        } else if (rtb_Sum >= -1832.5957F) {
            error_theta = 0.0F;
        } else {
            error_theta = rtb_Sum - -1832.5957F;
        }

        /* End of DeadZone: '<S193>/DeadZone' */

        /* Gain: '<S197>/Integral Gain' */
        rtb_Delay *= PLL.PLL_KI;

        /* Switch: '<S191>/Switch1' incorporates:
         *  Constant: '<S191>/Clamping_zero'
         *  Constant: '<S191>/Constant'
         *  Constant: '<S191>/Constant2'
         *  RelationalOperator: '<S191>/fix for DT propagation issue'
         */
        if (error_theta > 0.0F) {
            tmp = 1;
        } else {
            tmp = -1;
        }

        /* Switch: '<S191>/Switch2' incorporates:
         *  Constant: '<S191>/Clamping_zero'
         *  Constant: '<S191>/Constant3'
         *  Constant: '<S191>/Constant4'
         *  RelationalOperator: '<S191>/fix for DT propagation issue1'
         */
        if (rtb_Delay > 0.0F) {
            tmp_0 = 1;
        } else {
            tmp_0 = -1;
        }

        /* Logic: '<S191>/AND3' incorporates:
         *  Constant: '<S191>/Clamping_zero'
         *  RelationalOperator: '<S191>/Equal1'
         *  RelationalOperator: '<S191>/Relational Operator'
         *  Switch: '<S191>/Switch1'
         *  Switch: '<S191>/Switch2'
         */
        rtb_AND3 = ((error_theta != 0.0F) && (tmp == tmp_0));

        /* Saturate: '<S207>/Saturation' */
        if (rtb_Sum > 1832.5957F) {
            /* Saturate: '<S207>/Saturation' */
            iqavg = 1832.5957F;
        } else if (rtb_Sum < -1832.5957F) {
            /* Saturate: '<S207>/Saturation' */
            iqavg = -1832.5957F;
        } else {
            /* Saturate: '<S207>/Saturation' */
            iqavg = rtb_Sum;
        }

        /* End of Saturate: '<S207>/Saturation' */

        /* Sum: '<S166>/Sum' incorporates:
         *  Gain: '<S166>/Gain'
         *  UnitDelay: '<S166>/Unit Delay'
         */
        error_theta = 0.0001F * iqavg + rtDW.UnitDelay_DSTATE;

        /* If: '<S217>/If' incorporates:
         *  DataTypeConversion: '<S166>/Data Type Conversion1'
         */
        if (error_theta > 6.28318307f) {
            /* Outputs for IfAction SubSystem: '<S217>/If Action Subsystem' incorporates:
             *  ActionPort: '<S218>/Action Port'
             */
            /* Sum: '<S218>/Add' incorporates:
             *  Constant: '<S218>/Constant'
             */
            rtb_Merge = error_theta - 6.28318307f;

            /* End of Outputs for SubSystem: '<S217>/If Action Subsystem' */
        } else if (error_theta < 0.0F) {
            /* Outputs for IfAction SubSystem: '<S217>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S219>/Action Port'
             */
            /* Sum: '<S219>/Add' incorporates:
             *  Constant: '<S219>/Constant'
             */
            rtb_Merge = error_theta + 6.28318307f;

            /* End of Outputs for SubSystem: '<S217>/If Action Subsystem1' */
        } else {
            /* Outputs for IfAction SubSystem: '<S217>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S220>/Action Port'
             */
            /* SignalConversion generated from: '<S220>/Angle_input' */
            rtb_Merge = error_theta;

            /* End of Outputs for SubSystem: '<S217>/If Action Subsystem2' */
        }

        /* End of If: '<S217>/If' */

        /* Outport: '<Root>/obe' incorporates:
         *  DiscreteFilter: '<S164>/Discrete Filter2'
         *  Gain: '<S2>/Gain'
         */
        rtY.obe = 0.1454F * rtDW.DiscreteFilter2_states * 1.9098593F;

        /* Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
         *  EnablePort: '<S6>/Enable'
         */
        if (rtDW.enable > 0.0F) {
            /* Sum: '<S6>/Sum' incorporates:
             *  Inport: '<Root>/Ref_RPM'
             *  Outport: '<Root>/obe'
             */
            error_theta = rtU.Ref_RPM - rtY.obe;

            /* Sum: '<S150>/Sum' incorporates:
             *  DiscreteIntegrator: '<S141>/Integrator'
             *  Gain: '<S146>/Proportional Gain'
             */
            Product_p = SPEED.SPEED_KP * error_theta + rtDW.Integrator_DSTATE_p;

            /* Saturate: '<S148>/Saturation' */
            if (Product_p > 10.0F) {
                /* Saturate: '<S148>/Saturation' */
                rtDW.Saturation_p = 10.0F;
            } else if (Product_p < -10.0F) {
                /* Saturate: '<S148>/Saturation' */
                rtDW.Saturation_p = -10.0F;
            } else {
                /* Saturate: '<S148>/Saturation' */
                rtDW.Saturation_p = Product_p;
            }

            /* End of Saturate: '<S148>/Saturation' */

            /* Update for DiscreteIntegrator: '<S141>/Integrator' incorporates:
             *  Gain: '<S138>/Integral Gain'
             */
            rtDW.Integrator_DSTATE_p += SPEED.SPEED_KI * error_theta * 0.0001F;
        }

        /* End of Outputs for SubSystem: '<S2>/Enabled Subsystem' */

        /* Update for UnitDelay: '<S166>/Unit Delay' incorporates:
         *  DataTypeConversion: '<S166>/Data Type Conversion'
         */
        rtDW.UnitDelay_DSTATE = (real32_T)rtb_Merge;

        /* Update for UnitDelay: '<S8>/Unit Delay6' */
        rtDW.UnitDelay6_DSTATE = rtb_Add18;

        /* Update for UnitDelay: '<S8>/Unit Delay7' */
        rtDW.UnitDelay7_DSTATE = rtb_Add15;

        /* Switch: '<S191>/Switch' incorporates:
         *  Constant: '<S191>/Constant1'
         */
        if (rtb_AND3) {
            rtb_Delay = 0.0F;
        }

        /* Update for DiscreteIntegrator: '<S200>/Integrator' incorporates:
         *  Switch: '<S191>/Switch'
         */
        rtDW.Integrator_DSTATE += 0.0001F * rtb_Delay;

        /* Update for DiscreteFilter: '<S164>/Discrete Filter2' */
        rtDW.DiscreteFilter2_states = iqavg - -0.8546F *
            rtDW.DiscreteFilter2_states;
    } else {
        rtDW.Algorithm_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S1>/Algorithm' */

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick0" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick0++;
}

/* Model initialize function */
void Algorithm_initialize(void)
{
    /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
