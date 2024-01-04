/*
 * File: Algorithm.c
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

#include "Algorithm.h"
#include "rtwtypes.h"
#include <math.h>

/* Exported data definition */

/* Definition for custom storage class: Struct */
LADRC_Para_type LADRC_Para = {
    /* ADRC_times */
    1.0F,

    /* b0 */
    30000.0F,

    /* omega_c */
    50.0F
};

Obe_Para_type Obe_Para = {
    /* PLL_I */
    3000.0F,

    /* PLL_P */
    10.0F
};

Obe_data_type Obe_data;
PI_Para_type PI_Para = {
    /* current_bandwidth */
    1500.0F
};

PMSM_Para_type PMSM_Para = {
    /* Ls */
    0.0001952F,

    /* Rs */
    0.1763F,

    /* flux */
    0.011F
};

SOSOIFOParam_type SOSOIFOParam = {
    /* FLL_K */
    1.414F,

    /* Min_FLL_omega */
    10.0F,

    /* Swich_time */
    1.5F,

    /* tao */
    -30.0F
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
static void Switch_Counter(real32_T rtu_T_omega, real32_T rtu_one, real32_T
    rtu_zero, real32_T *rty_flag_Set_dir_0neg_1pos, real32_T *rty_time_count,
    real32_T *rty_omega_T, DW_Switch_Counter *localDW);
static void Clark_Trans(real32_T rtu_Ia, real32_T rtu_Ib, real32_T rtu_Ic,
                        real32_T *rty_I_alpha, real32_T *rty_I_beta);
static void Current_PI_control(real32_T rtu_refD, real32_T rtu_realD, real32_T
    rtu_refQ, real32_T rtu_realQ, real32_T *rty_Ud, real32_T *rty_Uq,
    DW_Current_PI_control *localDW);
static void IF_Current_Switch(real32_T rtu_Time, real32_T rtu_IF_iq, real32_T
    rtu_Speed_iq, real32_T rtu_Cos_error, real32_T rtu_Swich_time, real32_T
    *rty_Iq, DW_IF_Current_Switch *localDW);
static void IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1);
static void IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1);
static void IF_Theta_Switch(real32_T rtu_Time, real32_T rtu_IF_theta, real32_T
    rtu_Obe_theta, real32_T rtu_one, real32_T rtu_zero, real32_T rtu_Switch_time,
    real32_T *rty_sensorless_theta, real32_T *rty_theta_compa, real32_T
    *rty_flag_1, DW_IF_Theta_Switch *localDW);
static void IF_theta_Select(real32_T rtu_input, real32_T rtu_pos_theta, real32_T
    rtu_pos_omega, real32_T rtu_neg_theta, real32_T rtu_neg_omega, real32_T
    *rty_IF_theta, real32_T *rty_IF_omega);
static void LADRC_Control1(real32_T rtu_Enable, real32_T rtu_Ref, real32_T
    rtu_real, real32_T rtu_disturbance, real32_T *rty_Iq_Ref, DW_LADRC_Control1 *
    localDW);
static void Park_Trans(real32_T rtu_alpha, real32_T rtu_beta, const real32_T
                       rtu_SinCos[2], real32_T *rty_u_d, real32_T *rty_u_q);
static real32_T Park_Trans1(real32_T rtu_alpha, real32_T rtu_beta, const
    real32_T rtu_SinCos[2]);
static void SVPWM_By_Average_Zero_Injection(real32_T rtu_d, real32_T rtu_q,
    const real32_T rtu_SinCos[2], real32_T rtu_Udc, real32_T rtyyy_TaTbTc[3],
    real32_T *rty_U_alpha, real32_T *rty_U_beta);

/* Output and update for atomic system: '<S1>/ Switch_Counter' */
static void Switch_Counter(real32_T rtu_T_omega, real32_T rtu_one, real32_T
    rtu_zero, real32_T *rty_flag_Set_dir_0neg_1pos, real32_T *rty_time_count,
    real32_T *rty_omega_T, DW_Switch_Counter *localDW)
{
    *rty_time_count = rtu_zero;
    *rty_flag_Set_dir_0neg_1pos = rtu_zero;
    *rty_omega_T = rtu_T_omega;
    if (!localDW->time_not_empty) {
        localDW->time = rtu_zero;
        localDW->time_not_empty = true;
    }

    if (rtu_T_omega > 30.0F) {
        *rty_flag_Set_dir_0neg_1pos = rtu_one;
        localDW->time += 0.0001F;
        *rty_time_count = localDW->time;
    } else if (rtu_T_omega < -30.0F) {
        localDW->time += 0.0001F;
        *rty_time_count = localDW->time;
    }
}

/* Output and update for atomic system: '<S1>/Clark_Trans' */
static void Clark_Trans(real32_T rtu_Ia, real32_T rtu_Ib, real32_T rtu_Ic,
                        real32_T *rty_I_alpha, real32_T *rty_I_beta)
{
    /* Sum: '<S3>/Add1' */
    *rty_I_alpha = rtu_Ib + rtu_Ic;

    /* Gain: '<S3>/Gain' */
    *rty_I_alpha *= 0.5F;

    /* Sum: '<S3>/Add' */
    *rty_I_alpha = rtu_Ia - *rty_I_alpha;

    /* Gain: '<S3>/Gain2' */
    *rty_I_alpha *= 0.666666687F;

    /* Sum: '<S3>/Add2' */
    *rty_I_beta = rtu_Ib - rtu_Ic;

    /* Gain: '<S3>/Gain1' */
    *rty_I_beta *= 0.577350259F;
}

/* Output and update for atomic system: '<S1>/Current_PI_control' */
static void Current_PI_control(real32_T rtu_refD, real32_T rtu_realD, real32_T
    rtu_refQ, real32_T rtu_realQ, real32_T *rty_Ud, real32_T *rty_Uq,
    DW_Current_PI_control *localDW)
{
    real32_T rtb_IProdOut_b_tmp;
    real32_T rtb_IProdOut_o;
    real32_T rtb_Sum_g;
    real32_T tmp;

    /* Sum: '<S4>/Sum1' */
    rtb_Sum_g = rtu_refD - rtu_realD;

    /* Gain: '<S4>/Gain' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Gain: '<S4>/Gain2'
     */
    tmp = PI_Para.current_bandwidth * PMSM_Para.Ls;

    /* Sum: '<S56>/Sum' incorporates:
     *  DiscreteIntegrator: '<S47>/Integrator'
     *  Gain: '<S4>/Gain'
     *  Product: '<S52>/PProd Out'
     */
    *rty_Ud = tmp * rtb_Sum_g + localDW->Integrator_DSTATE;

    /* Saturate: '<S54>/Saturation' */
    if (*rty_Ud > 20.0F) {
        *rty_Ud = 20.0F;
    } else if (*rty_Ud < -20.0F) {
        *rty_Ud = -20.0F;
    }

    /* End of Saturate: '<S54>/Saturation' */

    /* Gain: '<S4>/Gain1' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Gain: '<S4>/Gain3'
     */
    rtb_IProdOut_b_tmp = PI_Para.current_bandwidth * PMSM_Para.Rs;

    /* Product: '<S44>/IProd Out' incorporates:
     *  Gain: '<S4>/Gain1'
     */
    rtb_IProdOut_o = rtb_IProdOut_b_tmp * rtb_Sum_g;

    /* Sum: '<S4>/Sum' */
    rtb_Sum_g = rtu_refQ - rtu_realQ;

    /* Sum: '<S104>/Sum' incorporates:
     *  DiscreteIntegrator: '<S95>/Integrator'
     *  Product: '<S100>/PProd Out'
     */
    *rty_Uq = tmp * rtb_Sum_g + localDW->Integrator_DSTATE_c;

    /* Saturate: '<S102>/Saturation' */
    if (*rty_Uq > 20.0F) {
        *rty_Uq = 20.0F;
    } else if (*rty_Uq < -20.0F) {
        *rty_Uq = -20.0F;
    }

    /* End of Saturate: '<S102>/Saturation' */

    /* Update for DiscreteIntegrator: '<S47>/Integrator' */
    localDW->Integrator_DSTATE += 0.0001F * rtb_IProdOut_o;

    /* Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
     *  Product: '<S92>/IProd Out'
     */
    localDW->Integrator_DSTATE_c += rtb_IProdOut_b_tmp * rtb_Sum_g * 0.0001F;
}

/* Output and update for atomic system: '<S1>/IF_Current_Switch' */
static void IF_Current_Switch(real32_T rtu_Time, real32_T rtu_IF_iq, real32_T
    rtu_Speed_iq, real32_T rtu_Cos_error, real32_T rtu_Swich_time, real32_T
    *rty_Iq, DW_IF_Current_Switch *localDW)
{
    if (!localDW->real_Iq_not_empty) {
        localDW->real_Iq = rtu_Cos_error;
        localDW->real_Iq_not_empty = true;
        localDW->last_iq = rtu_IF_iq;
    }

    if (rtu_Time < rtu_Swich_time) {
        *rty_Iq = rtu_IF_iq;
        localDW->real_Iq = rtu_Cos_error;
    } else if ((rtu_Swich_time <= rtu_Time) && (rtu_Time <= rtu_Swich_time +
                0.05F)) {
        *rty_Iq = 0.0594119355F * localDW->real_Iq + 0.940588057F *
            localDW->last_iq;
    } else {
        *rty_Iq = rtu_Speed_iq;
    }

    localDW->last_iq = *rty_Iq;
}

/*
 * Output and update for action system:
 *    '<S115>/If Action Subsystem1'
 *    '<S120>/If Action Subsystem1'
 *    '<S128>/If Action Subsystem1'
 */
static void IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1)
{
    /* Sum: '<S117>/Sum' incorporates:
     *  Constant: '<S117>/Constant'
     */
    *rty_Out1 = rtu_In1 - 6.28318548F;
}

/*
 * Output and update for action system:
 *    '<S115>/If Action Subsystem'
 *    '<S120>/If Action Subsystem'
 *    '<S128>/If Action Subsystem'
 */
static void IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1)
{
    /* Sum: '<S116>/Sum' incorporates:
     *  Constant: '<S116>/Constant'
     */
    *rty_Out1 = rtu_In1 + 6.28318548F;
}

/* Output and update for atomic system: '<S1>/IF_Theta_Switch' */
static void IF_Theta_Switch(real32_T rtu_Time, real32_T rtu_IF_theta, real32_T
    rtu_Obe_theta, real32_T rtu_one, real32_T rtu_zero, real32_T rtu_Switch_time,
    real32_T *rty_sensorless_theta, real32_T *rty_theta_compa, real32_T
    *rty_flag_1, DW_IF_Theta_Switch *localDW)
{
    real_T tmp;
    real32_T theta_give;
    theta_give = rtu_zero;
    *rty_theta_compa = rtu_zero;
    *rty_flag_1 = rtu_zero;
    if (!localDW->theta_give_not_empty) {
        localDW->theta_give_not_empty = true;
        localDW->theta_comp = rtu_zero;
        localDW->last_error = rtu_one;
        localDW->last_comp = rtu_zero;
        localDW->flag = rtu_zero;
    }

    if (localDW->flag == 1.0F) {
        theta_give = rtu_Obe_theta;
    }

    if ((rtu_Time < rtu_Switch_time) && (localDW->flag == 0.0F)) {
        theta_give = rtu_IF_theta;
    } else if ((rtu_Switch_time <= rtu_Time) && (rtu_Time <= rtu_Switch_time +
                0.05F) && (localDW->flag == 0.0F)) {
        localDW->theta_comp = 0.00995016657F * localDW->last_error +
            0.990049839F * localDW->last_comp;
        *rty_theta_compa = localDW->theta_comp;
        theta_give = rtu_IF_theta + localDW->theta_comp;
        tmp = theta_give - rtu_Obe_theta;
        if ((tmp < 0.1) && (tmp > -0.1)) {
            localDW->flag = rtu_one;
        }
    }

    localDW->last_error = rtu_Obe_theta - rtu_IF_theta;
    localDW->last_comp = localDW->theta_comp;
    tmp = theta_give - rtu_Obe_theta;
    if ((tmp < 0.2) && (tmp > -0.2)) {
        *rty_flag_1 = rtu_one;
    }

    *rty_sensorless_theta = theta_give;
}

/* Output and update for atomic system: '<S1>/IF_theta_Select' */
static void IF_theta_Select(real32_T rtu_input, real32_T rtu_pos_theta, real32_T
    rtu_pos_omega, real32_T rtu_neg_theta, real32_T rtu_neg_omega, real32_T
    *rty_IF_theta, real32_T *rty_IF_omega)
{
    if (rtu_input == 0.0F) {
        *rty_IF_theta = rtu_neg_theta;
        *rty_IF_omega = rtu_neg_omega;
    } else {
        *rty_IF_theta = rtu_pos_theta;
        *rty_IF_omega = rtu_pos_omega;
    }
}

/* Output and update for enable system: '<S1>/LADRC_Control1' */
static void LADRC_Control1(real32_T rtu_Enable, real32_T rtu_Ref, real32_T
    rtu_real, real32_T rtu_disturbance, real32_T *rty_Iq_Ref, DW_LADRC_Control1 *
    localDW)
{
    real32_T rtb_Sum2_n;
    real32_T rtb_u_k;

    /* Outputs for Enabled SubSystem: '<S1>/LADRC_Control1' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    if (rtu_Enable > 0.0F) {
        /* Product: '<S9>/Divide' incorporates:
         *  Constant: '<S9>/Constant'
         *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator3'
         *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator4'
         *  Gain: '<S9>/Gain3'
         *  Sum: '<S9>/Sum'
         *  Sum: '<S9>/Sum1'
         */
        rtb_Sum2_n = ((rtu_Ref - localDW->DiscreteTimeIntegrator3_DSTATE) *
                      LADRC_Para.omega_c -
                      localDW->DiscreteTimeIntegrator4_DSTATE) / LADRC_Para.b0;

        /* Saturate: '<S9>/Saturation' */
        if (rtb_Sum2_n > 20.0F) {
            rtb_Sum2_n = 20.0F;
        } else if (rtb_Sum2_n < -20.0F) {
            rtb_Sum2_n = -20.0F;
        }

        /* End of Saturate: '<S9>/Saturation' */

        /* Sum: '<S9>/Add' */
        *rty_Iq_Ref = rtu_disturbance + rtb_Sum2_n;

        /* Gain: '<S9>/Gain5' */
        rtb_u_k = LADRC_Para.b0 * rtb_Sum2_n;

        /* Sum: '<S9>/Sum2' incorporates:
         *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator3'
         */
        rtb_Sum2_n = rtu_real - localDW->DiscreteTimeIntegrator3_DSTATE;

        /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator3' incorporates:
         *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator4'
         *  Gain: '<S9>/Gain1'
         *  Gain: '<S9>/Gain4'
         *  Gain: '<S9>/Gain8'
         *  Sum: '<S9>/Add1'
         */
        localDW->DiscreteTimeIntegrator3_DSTATE += ((LADRC_Para.omega_c *
            rtb_Sum2_n * LADRC_Para.ADRC_times * 2.0F + rtb_u_k) +
            localDW->DiscreteTimeIntegrator4_DSTATE) * 0.0001F;
        if (localDW->DiscreteTimeIntegrator3_DSTATE >= 2500.0F) {
            localDW->DiscreteTimeIntegrator3_DSTATE = 2500.0F;
        } else if (localDW->DiscreteTimeIntegrator3_DSTATE <= -2500.0F) {
            localDW->DiscreteTimeIntegrator3_DSTATE = -2500.0F;
        }

        /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator3' */

        /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator4' incorporates:
         *  Gain: '<S9>/Gain2'
         *  Gain: '<S9>/Gain6'
         *  Gain: '<S9>/Gain7'
         *  Gain: '<S9>/Gain9'
         */
        localDW->DiscreteTimeIntegrator4_DSTATE += LADRC_Para.ADRC_times *
            rtb_Sum2_n * LADRC_Para.omega_c * LADRC_Para.ADRC_times *
            LADRC_Para.omega_c * 0.0001F;
    }

    /* End of Outputs for SubSystem: '<S1>/LADRC_Control1' */
}

/* Output and update for atomic system: '<S1>/Park_Trans' */
static void Park_Trans(real32_T rtu_alpha, real32_T rtu_beta, const real32_T
                       rtu_SinCos[2], real32_T *rty_u_d, real32_T *rty_u_q)
{
    /* Product: '<S10>/Product' */
    *rty_u_d = rtu_alpha * rtu_SinCos[1];

    /* Product: '<S10>/Product1' */
    *rty_u_q = rtu_beta * rtu_SinCos[0];

    /* Sum: '<S10>/Add' */
    *rty_u_d += *rty_u_q;

    /* Product: '<S10>/Product2' */
    *rty_u_q = rtu_alpha * rtu_SinCos[0];

    /* Sum: '<S10>/Add1' incorporates:
     *  Product: '<S10>/Product3'
     */
    *rty_u_q = rtu_beta * rtu_SinCos[1] - *rty_u_q;
}

/* Output and update for atomic system: '<S1>/Park_Trans1' */
static real32_T Park_Trans1(real32_T rtu_alpha, real32_T rtu_beta, const
    real32_T rtu_SinCos[2])
{
    /* Sum: '<S11>/Add1' incorporates:
     *  Product: '<S11>/Product2'
     *  Product: '<S11>/Product3'
     */
    return rtu_beta * rtu_SinCos[1] - rtu_alpha * rtu_SinCos[0];
}

/* Output and update for atomic system: '<S1>/SVPWM_By_Average_Zero_Injection' */
static void SVPWM_By_Average_Zero_Injection(real32_T rtu_d, real32_T rtu_q,
    const real32_T rtu_SinCos[2], real32_T rtu_Udc, real32_T rtyyy_TaTbTc[3],
    real32_T *rty_U_alpha, real32_T *rty_U_beta)
{
    real32_T rtb_Add1_l;
    real32_T rtb_Add2;
    real32_T rtb_Add_l;

    /* Product: '<S184>/Product' */
    *rty_U_alpha = rtu_d * rtu_SinCos[1];

    /* Sum: '<S184>/Add' incorporates:
     *  Product: '<S184>/Product1'
     */
    *rty_U_alpha -= rtu_q * rtu_SinCos[0];

    /* Gain: '<S186>/Gain' */
    rtb_Add2 = 0.5F * *rty_U_alpha;

    /* Product: '<S184>/Product3' */
    *rty_U_beta = rtu_q * rtu_SinCos[1];

    /* Sum: '<S184>/Add1' incorporates:
     *  Product: '<S184>/Product2'
     */
    *rty_U_beta += rtu_d * rtu_SinCos[0];

    /* Gain: '<S186>/Gain1' */
    rtb_Add_l = 0.866025388F * *rty_U_beta;

    /* Sum: '<S186>/Add' */
    rtb_Add1_l = rtb_Add_l - rtb_Add2;

    /* Sum: '<S186>/Add1' */
    rtb_Add2 = (0.0F - rtb_Add2) - rtb_Add_l;

    /* Gain: '<S185>/Gain' incorporates:
     *  MinMax: '<S185>/Max'
     *  MinMax: '<S185>/Max1'
     *  Sum: '<S185>/Add3'
     */
    rtb_Add_l = (fmaxf(fmaxf(*rty_U_alpha, rtb_Add1_l), rtb_Add2) + fminf(fminf(*
                   rty_U_alpha, rtb_Add1_l), rtb_Add2)) * -0.5F;

    /* Gain: '<S185>/Gain1' incorporates:
     *  Sum: '<S185>/Add'
     *  Sum: '<S185>/Add1'
     *  Sum: '<S185>/Add2'
     */
    rtyyy_TaTbTc[0] = -(*rty_U_alpha + rtb_Add_l);
    rtyyy_TaTbTc[1] = -(rtb_Add1_l + rtb_Add_l);
    rtyyy_TaTbTc[2] = -(rtb_Add2 + rtb_Add_l);

    /* Gain: '<S185>/Gain2' incorporates:
     *  Constant: '<S185>/Constant'
     *  Product: '<S185>/Divide'
     *  Sum: '<S185>/Add4'
     */
    rtyyy_TaTbTc[0] = (rtyyy_TaTbTc[0] / rtu_Udc + 0.5F) * 8000.0F;
    rtyyy_TaTbTc[1] = (rtyyy_TaTbTc[1] / rtu_Udc + 0.5F) * 8000.0F;
    rtyyy_TaTbTc[2] = (rtyyy_TaTbTc[2] / rtu_Udc + 0.5F) * 8000.0F;
}

/* Model step function */
void Algorithm_step(void)
{
    real32_T rtb_TmpSignalConversionAtPark_0[2];
    real32_T rtb_TmpSignalConversionAtPark_T[2];
    real32_T rtb_DiscreteTimeIntegrator;
    real32_T rtb_DiscreteTimeIntegrator_p;
    real32_T rtb_Gain1_m;
    real32_T rtb_IF_omega;
    real32_T rtb_Integrator;
    real32_T rtb_PLL_error;
    real32_T rtb_Sum1_f;
    real32_T rtb_UnitDelay;
    real32_T rtb_UnitDelay_l;
    real32_T rtb_omega_T;
    real32_T rtb_qv_prime_f;
    real32_T rtb_yk;

    /* Outputs for Atomic SubSystem: '<Root>/Algorithm' */
    /* Delay: '<S126>/Delay' */
    Obe_data.Obe_theta = rtDW.Delay_DSTATE;

    /* Trigonometry: '<S124>/Cos2' */
    rtb_Integrator = sinf(Obe_data.Obe_theta);

    /* Trigonometry: '<S124>/Cos1' */
    rtb_PLL_error = cosf(Obe_data.Obe_theta);

    /* SignalConversion generated from: '<S1>/Park_Trans1' */
    rtb_TmpSignalConversionAtPark_T[0] = rtb_Integrator;
    rtb_TmpSignalConversionAtPark_T[1] = rtb_PLL_error;

    /* MATLAB Function: '<S1>/ Switch_Counter' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Constant: '<S1>/Constant4'
     *  Inport: '<Root>/Ref_RPM'
     */
    Switch_Counter(rtU.Ref_RPM, 1.0F, 0.0F, &rtb_Gain1_m, &rtb_qv_prime_f,
                   &rtb_omega_T, &rtDW.sf_Switch_Counter);

    /* Outputs for Atomic SubSystem: '<S6>/IFpos' */
    /* DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */
    rtb_DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE_a;

    /* UnitDelay: '<S119>/Unit Delay' */
    rtb_UnitDelay = rtDW.UnitDelay_DSTATE;

    /* Sum: '<S119>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator'
     *  Gain: '<S119>/Ts'
     *  UnitDelay: '<S119>/Unit Delay'
     */
    rtb_yk = 0.0001F * rtDW.DiscreteTimeIntegrator_DSTATE_a +
        rtDW.UnitDelay_DSTATE;

    /* If: '<S120>/If' incorporates:
     *  Constant: '<S120>/Constant'
     *  Constant: '<S120>/Constant1'
     *  RelationalOperator: '<S120>/Relational Operator'
     *  RelationalOperator: '<S120>/Relational Operator1'
     */
    if (rtb_yk > 6.28318548F) {
        /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S122>/Action Port'
         */
        /* Update for UnitDelay: '<S119>/Unit Delay' */
        IfActionSubsystem1(rtb_yk, &rtDW.UnitDelay_DSTATE);

        /* End of Outputs for SubSystem: '<S120>/If Action Subsystem1' */
    } else if (rtb_yk < 0.0F) {
        /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem' incorporates:
         *  ActionPort: '<S121>/Action Port'
         */
        /* Update for UnitDelay: '<S119>/Unit Delay' */
        IfActionSubsystem(rtb_yk, &rtDW.UnitDelay_DSTATE);

        /* End of Outputs for SubSystem: '<S120>/If Action Subsystem' */
    } else {
        /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S123>/Action Port'
         */
        /* Update for UnitDelay: '<S119>/Unit Delay' incorporates:
         *  SignalConversion generated from: '<S123>/In1'
         */
        rtDW.UnitDelay_DSTATE = rtb_yk;

        /* End of Outputs for SubSystem: '<S120>/If Action Subsystem2' */
    }

    /* End of If: '<S120>/If' */

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S113>/Constant'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE_a += 0.00399999972F;

    /* End of Outputs for SubSystem: '<S6>/IFpos' */

    /* Outputs for Atomic SubSystem: '<S6>/IFneg' */
    /* DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
    rtb_DiscreteTimeIntegrator_p = rtDW.DiscreteTimeIntegrator_DSTATE_f;

    /* UnitDelay: '<S114>/Unit Delay' */
    rtb_UnitDelay_l = rtDW.UnitDelay_DSTATE_a;

    /* Sum: '<S114>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator'
     *  Gain: '<S114>/Ts'
     *  UnitDelay: '<S114>/Unit Delay'
     */
    rtb_yk = 0.0001F * rtDW.DiscreteTimeIntegrator_DSTATE_f +
        rtDW.UnitDelay_DSTATE_a;

    /* If: '<S115>/If' incorporates:
     *  Constant: '<S115>/Constant'
     *  Constant: '<S115>/Constant1'
     *  RelationalOperator: '<S115>/Relational Operator'
     *  RelationalOperator: '<S115>/Relational Operator1'
     */
    if (rtb_yk > 6.28318548F) {
        /* Outputs for IfAction SubSystem: '<S115>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S117>/Action Port'
         */
        /* Update for UnitDelay: '<S114>/Unit Delay' */
        IfActionSubsystem1(rtb_yk, &rtDW.UnitDelay_DSTATE_a);

        /* End of Outputs for SubSystem: '<S115>/If Action Subsystem1' */
    } else if (rtb_yk < 0.0F) {
        /* Outputs for IfAction SubSystem: '<S115>/If Action Subsystem' incorporates:
         *  ActionPort: '<S116>/Action Port'
         */
        /* Update for UnitDelay: '<S114>/Unit Delay' */
        IfActionSubsystem(rtb_yk, &rtDW.UnitDelay_DSTATE_a);

        /* End of Outputs for SubSystem: '<S115>/If Action Subsystem' */
    } else {
        /* Outputs for IfAction SubSystem: '<S115>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S118>/Action Port'
         */
        /* Update for UnitDelay: '<S114>/Unit Delay' incorporates:
         *  SignalConversion generated from: '<S118>/In1'
         */
        rtDW.UnitDelay_DSTATE_a = rtb_yk;

        /* End of Outputs for SubSystem: '<S115>/If Action Subsystem2' */
    }

    /* End of If: '<S115>/If' */

    /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_f -= 0.00399999972F;

    /* End of Outputs for SubSystem: '<S6>/IFneg' */

    /* MATLAB Function: '<S1>/IF_theta_Select' */
    IF_theta_Select(rtb_Gain1_m, rtb_UnitDelay, rtb_DiscreteTimeIntegrator,
                    rtb_UnitDelay_l, rtb_DiscreteTimeIntegrator_p, &rtb_yk,
                    &rtb_IF_omega);

    /* MATLAB Function: '<S1>/IF_Theta_Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Constant: '<S1>/Constant3'
     *  Constant: '<S1>/Constant6'
     */
    IF_Theta_Switch(rtb_qv_prime_f, rtb_yk, Obe_data.Obe_theta, 1.0F, 0.0F,
                    SOSOIFOParam.Swich_time, &rtb_DiscreteTimeIntegrator,
                    &rtb_Gain1_m, &rtb_UnitDelay, &rtDW.sf_IF_Theta_Switch);

    /* SignalConversion generated from: '<S1>/Park_Trans' incorporates:
     *  SignalConversion generated from: '<S1>/SVPWM_By_Average_Zero_Injection'
     *  Trigonometry: '<S1>/Sin2'
     *  Trigonometry: '<S1>/Sin3'
     */
    rtb_TmpSignalConversionAtPark_0[0] = sinf(rtb_DiscreteTimeIntegrator);
    rtb_TmpSignalConversionAtPark_0[1] = cosf(rtb_DiscreteTimeIntegrator);

    /* Outputs for Atomic SubSystem: '<S1>/Clark_Trans' */
    /* Inport: '<Root>/Iabc' */
    Clark_Trans(rtU.Iabc[0], rtU.Iabc[1], rtU.Iabc[2],
                &rtb_DiscreteTimeIntegrator_p, &rtb_Gain1_m);

    /* End of Outputs for SubSystem: '<S1>/Clark_Trans' */

    /* Sum: '<S124>/Sum2' incorporates:
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator2'
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator2'
     *  Gain: '<S125>/Gain1'
     *  Gain: '<S125>/Gain2'
     *  Product: '<S124>/Product2'
     *  Product: '<S124>/Product3'
     *  Sum: '<S125>/Add14'
     *  Sum: '<S125>/Add7'
     */
    rtb_PLL_error = (rtDW.DiscreteTimeIntegrator2_DSTAT_m - PMSM_Para.Ls *
                     rtb_Gain1_m) * rtb_PLL_error -
        (rtDW.DiscreteTimeIntegrator2_DSTATE - PMSM_Para.Ls *
         rtb_DiscreteTimeIntegrator_p) * rtb_Integrator;

    /* Sum: '<S172>/Sum' incorporates:
     *  Constant: '<S124>/Constant1'
     *  DiscreteIntegrator: '<S163>/Integrator'
     *  Gain: '<S124>/Gain'
     *  Gain: '<S124>/Gain2'
     *  Product: '<S168>/PProd Out'
     */
    rtb_Integrator = Obe_Para.PLL_I * Obe_Para.PLL_P * 2.0F * rtb_PLL_error +
        rtDW.Integrator_DSTATE;

    /* Saturate: '<S170>/Saturation' */
    if (rtb_Integrator > 1400.0F) {
        /* Saturate: '<S170>/Saturation' */
        Obe_data.Obe_omega = 1400.0F;
    } else if (rtb_Integrator < -1400.0F) {
        /* Saturate: '<S170>/Saturation' */
        Obe_data.Obe_omega = -1400.0F;
    } else {
        /* Saturate: '<S170>/Saturation' */
        Obe_data.Obe_omega = rtb_Integrator;
    }

    /* End of Saturate: '<S170>/Saturation' */

    /* Outputs for Enabled SubSystem: '<S1>/LADRC_Control1' */
    /* SignalConversion generated from: '<S9>/Enable' */
    LADRC_Control1(rtb_UnitDelay, rtb_omega_T, Obe_data.Obe_omega, 0.0F,
                   &rtDW.Add, &rtDW.LADRC_Control1_b);

    /* End of Outputs for SubSystem: '<S1>/LADRC_Control1' */

    /* MATLAB Function: '<S1>/IF_Current_Switch' incorporates:
     *  Constant: '<S1>/Constant5'
     *  Inport: '<Root>/Ref_Iq'
     *  Product: '<S1>/Product'
     *  Sum: '<S1>/Sum'
     *  Trigonometry: '<S1>/Cos'
     */
    IF_Current_Switch(rtb_qv_prime_f, rtU.Ref_Iq, rtDW.Add, rtU.Ref_Iq * cosf
                      (Obe_data.Obe_theta - rtb_yk), SOSOIFOParam.Swich_time,
                      &rtb_yk, &rtDW.sf_IF_Current_Switch);

    /* Saturate: '<S1>/Saturation' */
    if (rtb_yk > 20.0F) {
        /* Sum: '<S1>/Add' */
        Obe_data.Ref_Iq = 20.0F;
    } else if (rtb_yk < -20.0F) {
        /* Sum: '<S1>/Add' */
        Obe_data.Ref_Iq = -20.0F;
    } else {
        /* Sum: '<S1>/Add' */
        Obe_data.Ref_Iq = rtb_yk;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Outputs for Atomic SubSystem: '<S1>/Park_Trans' */
    /* SignalConversion generated from: '<S1>/Park_Trans' */
    Park_Trans(rtb_DiscreteTimeIntegrator_p, rtb_Gain1_m,
               rtb_TmpSignalConversionAtPark_0, &rtb_yk, &(Obe_data.Real_Iq));

    /* End of Outputs for SubSystem: '<S1>/Park_Trans' */

    /* Outputs for Atomic SubSystem: '<S1>/Current_PI_control' */
    /* Inport: '<Root>/Ref_Id' */
    Current_PI_control(rtU.Ref_Id, rtb_yk, Obe_data.Ref_Iq, Obe_data.Real_Iq,
                       &rtb_yk, &rtb_UnitDelay, &rtDW.Current_PI_control_e);

    /* End of Outputs for SubSystem: '<S1>/Current_PI_control' */

    /* Outputs for Atomic SubSystem: '<S1>/SVPWM_By_Average_Zero_Injection' */
    /* Outport: '<Root>/Tabc' incorporates:
     *  Inport: '<Root>/Udc'
     */
    SVPWM_By_Average_Zero_Injection(rtb_yk, rtb_UnitDelay,
        rtb_TmpSignalConversionAtPark_0, rtU.Udc, rtY.Tabc,
        &rtb_DiscreteTimeIntegrator, &rtb_yk);

    /* End of Outputs for SubSystem: '<S1>/SVPWM_By_Average_Zero_Injection' */

    /* If: '<S180>/If' incorporates:
     *  Constant: '<S180>/Constant'
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator4'
     *  Saturate: '<S180>/Saturation'
     *  SignalConversion generated from: '<S183>/In1'
     *  Sum: '<S180>/Add1'
     */
    if (rtDW.DiscreteTimeIntegrator4_DSTATE - SOSOIFOParam.Min_FLL_omega < 0.0F)
    {
        /* Outputs for IfAction SubSystem: '<S180>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S183>/Action Port'
         */
        rtb_Integrator = SOSOIFOParam.Min_FLL_omega;

        /* End of Outputs for SubSystem: '<S180>/If Action Subsystem2' */
    } else {
        rtb_Integrator = rtDW.DiscreteTimeIntegrator4_DSTATE;
    }

    if (rtb_Integrator > 1500.0F) {
        rtb_Integrator = 1500.0F;
    } else if (rtb_Integrator < SOSOIFOParam.Min_FLL_omega) {
        rtb_Integrator = SOSOIFOParam.Min_FLL_omega;
    }

    /* End of If: '<S180>/If' */

    /* Sum: '<S180>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator1'
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator3'
     *  Gain: '<S12>/Gain19'
     *  Gain: '<S180>/Gain'
     *  Product: '<S180>/Product1'
     *  Sum: '<S12>/Add'
     *  Sum: '<S180>/Sum'
     */
    rtb_qv_prime_f = ((rtb_DiscreteTimeIntegrator - PMSM_Para.Rs *
                       rtb_DiscreteTimeIntegrator_p) -
                      rtDW.DiscreteTimeIntegrator3_DSTATE) * 1.56F -
        rtDW.DiscreteTimeIntegrator1_DSTATE * rtb_Integrator;

    /* Product: '<S180>/Product6' incorporates:
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator2'
     *  Product: '<S180>/Product2'
     */
    rtb_omega_T = rtb_Integrator * rtDW.DiscreteTimeIntegrator2_DSTATE;

    /* Math: '<S180>/Square' incorporates:
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator3'
     */
    rtb_UnitDelay_l = rtDW.DiscreteTimeIntegrator3_DSTATE *
        rtDW.DiscreteTimeIntegrator3_DSTATE;

    /* Sum: '<S180>/Sum2' incorporates:
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator3'
     */
    rtb_UnitDelay = rtDW.DiscreteTimeIntegrator_DSTATE -
        rtDW.DiscreteTimeIntegrator3_DSTATE;

    /* Sum: '<S181>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator1'
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator3'
     *  Gain: '<S12>/Gain3'
     *  Gain: '<S181>/Gain'
     *  Product: '<S181>/Product1'
     *  Sum: '<S12>/Add4'
     *  Sum: '<S181>/Sum'
     */
    rtb_yk = ((rtb_yk - PMSM_Para.Rs * rtb_Gain1_m) -
              rtDW.DiscreteTimeIntegrator3_DSTAT_n) * 1.56F -
        rtDW.DiscreteTimeIntegrator1_DSTAT_b * rtb_Integrator;

    /* Sum: '<S181>/Sum3' incorporates:
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator2'
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator3'
     *  Gain: '<S181>/Gain1'
     *  Product: '<S181>/Product2'
     *  Sum: '<S181>/Sum2'
     */
    rtb_IF_omega = (rtDW.DiscreteTimeIntegrator_DSTATE_p -
                    rtDW.DiscreteTimeIntegrator3_DSTAT_n) * 3.11F -
        rtDW.DiscreteTimeIntegrator2_DSTAT_m * rtb_Integrator;

    /* Sum: '<S126>/Sum1' incorporates:
     *  Gain: '<S126>/Ts'
     */
    rtb_Sum1_f = 0.0001F * Obe_data.Obe_omega + Obe_data.Obe_theta;

    /* If: '<S128>/If' incorporates:
     *  Constant: '<S128>/Constant'
     *  Constant: '<S128>/Constant1'
     *  RelationalOperator: '<S128>/Relational Operator'
     *  RelationalOperator: '<S128>/Relational Operator1'
     */
    if (rtb_Sum1_f > 6.28318548F) {
        /* Outputs for IfAction SubSystem: '<S128>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S130>/Action Port'
         */
        /* Update for Delay: '<S126>/Delay' */
        IfActionSubsystem1(rtb_Sum1_f, &rtDW.Delay_DSTATE);

        /* End of Outputs for SubSystem: '<S128>/If Action Subsystem1' */
    } else if (rtb_Sum1_f < 0.0F) {
        /* Outputs for IfAction SubSystem: '<S128>/If Action Subsystem' incorporates:
         *  ActionPort: '<S129>/Action Port'
         */
        /* Update for Delay: '<S126>/Delay' */
        IfActionSubsystem(rtb_Sum1_f, &rtDW.Delay_DSTATE);

        /* End of Outputs for SubSystem: '<S128>/If Action Subsystem' */
    } else {
        /* Outputs for IfAction SubSystem: '<S128>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S131>/Action Port'
         */
        /* Update for Delay: '<S126>/Delay' incorporates:
         *  SignalConversion generated from: '<S131>/In1'
         */
        rtDW.Delay_DSTATE = rtb_Sum1_f;

        /* End of Outputs for SubSystem: '<S128>/If Action Subsystem2' */
    }

    /* End of If: '<S128>/If' */

    /* Outputs for Atomic SubSystem: '<S1>/Park_Trans1' */
    rtb_Sum1_f = Park_Trans1(rtb_DiscreteTimeIntegrator_p, rtb_Gain1_m,
        rtb_TmpSignalConversionAtPark_T);

    /* End of Outputs for SubSystem: '<S1>/Park_Trans1' */

    /* Update for DiscreteIntegrator: '<S180>/Discrete-Time Integrator2' incorporates:
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator3'
     */
    rtDW.DiscreteTimeIntegrator2_DSTATE += 0.0001F *
        rtDW.DiscreteTimeIntegrator3_DSTATE;

    /* Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator2' incorporates:
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator3'
     */
    rtDW.DiscreteTimeIntegrator2_DSTAT_m += 0.0001F *
        rtDW.DiscreteTimeIntegrator3_DSTAT_n;

    /* Update for DiscreteIntegrator: '<S163>/Integrator' incorporates:
     *  Constant: '<S124>/Constant2'
     *  Gain: '<S124>/Gain1'
     *  Product: '<S160>/IProd Out'
     */
    rtDW.Integrator_DSTATE += Obe_Para.PLL_I * Obe_Para.PLL_I * rtb_PLL_error *
        0.0001F;

    /* Update for DiscreteIntegrator: '<S180>/Discrete-Time Integrator3' incorporates:
     *  Gain: '<S180>/Gain1'
     *  Product: '<S180>/Product3'
     *  Sum: '<S180>/Sum3'
     */
    rtDW.DiscreteTimeIntegrator3_DSTATE += (3.11F * rtb_UnitDelay - rtb_omega_T)
        * rtb_Integrator * 0.0001F;

    /* Update for DiscreteIntegrator: '<S180>/Discrete-Time Integrator4' incorporates:
     *  Gain: '<S180>/Gain2'
     *  Gain: '<S180>/Gain3'
     *  Math: '<S180>/Square1'
     *  Product: '<S180>/Divide'
     *  Product: '<S180>/Product4'
     *  Product: '<S180>/Product6'
     *  Sum: '<S180>/Add'
     */
    rtDW.DiscreteTimeIntegrator4_DSTATE += rtb_UnitDelay * rtb_omega_T
        * (SOSOIFOParam.FLL_K * rtb_Integrator) / (rtb_omega_T * rtb_omega_T
        + rtb_UnitDelay_l) * SOSOIFOParam.tao * 0.0001F;

    /* Update for DiscreteIntegrator: '<S180>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator'
     */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.0001F *
        rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S180>/Discrete-Time Integrator' incorporates:
     *  Product: '<S180>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += rtb_Integrator * rtb_qv_prime_f *
        0.0001F;

    /* Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator'
     */
    rtDW.DiscreteTimeIntegrator1_DSTAT_b += 0.0001F *
        rtDW.DiscreteTimeIntegrator_DSTATE_p;

    /* Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator3' incorporates:
     *  Product: '<S181>/Product3'
     */
    rtDW.DiscreteTimeIntegrator3_DSTAT_n += rtb_Integrator * rtb_IF_omega *
        0.0001F;

    /* Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' incorporates:
     *  Product: '<S181>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE_p += rtb_Integrator * rtb_yk * 0.0001F;

    /* End of Outputs for SubSystem: '<Root>/Algorithm' */
}

/* Model initialize function */
void Algorithm_initialize(void)
{
    /* SystemInitialize for Atomic SubSystem: '<Root>/Algorithm' */
    /* InitializeConditions for DiscreteIntegrator: '<S180>/Discrete-Time Integrator2' */
    rtDW.DiscreteTimeIntegrator2_DSTATE = PMSM_Para.flux;

    /* InitializeConditions for DiscreteIntegrator: '<S181>/Discrete-Time Integrator2' */
    rtDW.DiscreteTimeIntegrator2_DSTAT_m = PMSM_Para.flux;

    /* InitializeConditions for DiscreteIntegrator: '<S180>/Discrete-Time Integrator3' */
    rtDW.DiscreteTimeIntegrator3_DSTATE = 1.0F;

    /* InitializeConditions for DiscreteIntegrator: '<S180>/Discrete-Time Integrator4' */
    rtDW.DiscreteTimeIntegrator4_DSTATE = 200.0F;

    /* InitializeConditions for DiscreteIntegrator: '<S180>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTATE = 1.0F;

    /* InitializeConditions for DiscreteIntegrator: '<S180>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE = 1.0F;

    /* InitializeConditions for DiscreteIntegrator: '<S181>/Discrete-Time Integrator1' */
    rtDW.DiscreteTimeIntegrator1_DSTAT_b = 1.0F;

    /* InitializeConditions for DiscreteIntegrator: '<S181>/Discrete-Time Integrator3' */
    rtDW.DiscreteTimeIntegrator3_DSTAT_n = 1.0F;

    /* InitializeConditions for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_DSTATE_p = 1.0F;

    /* End of SystemInitialize for SubSystem: '<Root>/Algorithm' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
