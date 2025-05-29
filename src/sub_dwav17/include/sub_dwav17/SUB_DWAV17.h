//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SUB_DWAV17.h
//
// Code generated for Simulink model 'SUB_DWAV17'.
//
// Model version                  : 12.155
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu May 29 03:31:28 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_SUB_DWAV17_h_
#define RTW_HEADER_SUB_DWAV17_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "SUB_DWAV17_types.h"
#include "coder_array.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals (default storage)
struct B_SUB_DWAV17_T {
  coder::array<real32_T,2> y;
  coder::array<boolean_T,1> b;
  coder::array<boolean_T,1> c;
  coder::array<int32_T,1> r;
  coder::array<int32_T,1> r1;
  coder::array<int32_T,1> idx;
  coder::array<int32_T,1> iwork;
  coder::array<real_T,2> y_front;
  coder::array<real_T,2> dy;
  coder::array<real_T,2> theta_range;
  coder::array<real_T,2> xy;
  coder::array<real_T,2> c_c;
  coder::array<real_T,2> d;
  coder::array<real_T,2> r2;
  coder::array<real_T,2> theta_range_k;
  coder::array<real_T,1> y_obj_ultrasonic_m;
  coder::array<real_T,1> ycol;
  real_T U_padded[6889];
  real_T x_possible[6561];             // '<S29>/Scan Grid Generation'
  real_T y_possible[6561];             // '<S29>/Scan Grid Generation'
  real_T U_rep_sum[6561];              // '<S29>/Potential Feld LiDAR'
  real_T vw_possiables[5202];
  real_T U_Trajectories[2601];
  real_T score[2601];
  real_T V[2601];
  real_T W[2601];
  real_T b_b[2601];
  real_T tmp_data[2601];
  SL_Bus_sensor_msgs_LaserScan In1;    // '<S24>/In1'
  SL_Bus_sensor_msgs_LaserScan b_varargout_2;
  real_T x_o[720];                     // '<S37>/MATLAB Function3'
  real_T y_o[720];                     // '<S37>/MATLAB Function3'
  real_T ranges[720];                  // '<S37>/MATLAB Function3'
  int16_T tmp_data_c[2601];
  int16_T tmp_data_b[2601];
  real32_T tmp_data_p[720];
  boolean_T bv[2601];
  SL_Bus_sensor_msgs_Joy In1_a;        // '<S51>/In1'
  SL_Bus_sensor_msgs_Joy b_varargout_2_c;
  real_T x_grid[81];
  real_T dv[51];
  real_T dv1[51];
  SL_Bus_sensor_msgs_Range In1_d;      // '<S50>/In1'
  SL_Bus_sensor_msgs_Range In1_aj;     // '<S49>/In1'
  SL_Bus_sensor_msgs_Range In1_g;      // '<S48>/In1'
  SL_Bus_sensor_msgs_Range b_varargout_2_f;
  real_T x[9];
  real_T K[9];                         // '<S27>/Kernel'
  SL_Bus_motion_msgs_MotionCtrl BusAssignment;// '<S1>/Bus Assignment'
  SL_Bus_geometry_msgs_Twist In1_l;    // '<S54>/In1'
  SL_Bus_geometry_msgs_Twist b_varargout_2_g;
  SL_Bus_geometry_msgs_Twist BusAssignment_a;// '<S5>/Bus Assignment'
  coder::array<real_T,2> x_obj_ultrasonic;// '<S29>/Read Ultrasonic Data'
  coder::array<real_T,2> y_obj_ultrasonic;// '<S29>/Read Ultrasonic Data'
  coder::array<real_T,2> Sensor_ranges;// '<S29>/MATLAB Function1'
  coder::array<real_T,2> y_obj;        // '<S29>/MATLAB Function'
  coder::array<real_T,2> x_obj;        // '<S29>/MATLAB Function'
  real_T ultrasonic_ranges[3];
  real_T rtb_param_weight[3];
  real_T dv2[2];
  real_T ndbl;
  real_T apnd;
  real_T cdiff;
  real_T u_front;
  real_T s_end;
  real_T R_cur;
  real_T y_g;
  real_T y_m;
  real_T v1;
  real_T v2;
  SL_Bus_std_msgs_Bool In1_p;          // '<S52>/In1'
  int32_T xo[2];
  real32_T kd;
  real32_T b1;
  int32_T n;
  int32_T k;
  int32_T nm1d2;
  int32_T b_n;
  int32_T b_k;
  int32_T j;
  int32_T o;
  int32_T g_nx;
  int32_T i;
  int32_T loop_ub;
  int32_T h[1];
  int32_T vw_possiables_size[1];
};

// Block states (default storage) for system '<Root>'
struct DW_SUB_DWAV17_T {
  ros_slros2_internal_block_Sub_T obj; // '<S20>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_b;// '<S12>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_e;// '<S11>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_i;// '<S10>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_ez;// '<S9>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_m;// '<S8>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_g;// '<S2>/SourceBlock'
  ros_slros2_internal_block_Pub_T obj_a;// '<S19>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_k;// '<S18>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_n;// '<S17>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_d;// '<S16>/SinkBlock'
  real_T stop;                         // '<S31>/Data Store1'
  real_T value[3];                     // '<S4>/Data Store Memory11'
  real_T StateWander;                  // '<S4>/Data Store Memory5'
  real_T behaviorSwitch;               // '<S4>/Data Store Memory6'
  real_T WanderVelocity;               // '<S4>/Data Store Memory9'
  real_T vel_last[2];                  // '<S4>/Last Velocity commed'
  real_T counter;                      // '<S30>/MATLAB Function2'
  real_T time_counter;                 // '<S4>/Behavior Switcher'
  real32_T prevAxes[128];              // '<S4>/Data Store Memory10'
  int32_T prevButtons[128];            // '<S4>/Data Store Memory7'
  int32_T SFunction_DIMS3;             // '<S3>/read scan'
  boolean_T is_recording;              // '<S4>/Data Store Memory1'
  boolean_T is_repeating;              // '<S4>/Data Store Memory2'
  boolean_T mode[5];                   // '<S4>/Data Store Memory8'
  boolean_T is_limited;                // '<S30>/MATLAB Function2'
};

// Real-time Model Data Structure
struct tag_RTM_SUB_DWAV17_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

// External function called from main
#ifdef __cplusplus

extern "C"
{

#endif

  extern void SUB_DWAV17_SetEventsForThisBaseStep(boolean_T *eventFlags,
    RT_MODEL_SUB_DWAV17_T *const SUB_DWAV17_M);

#ifdef __cplusplus

}

#endif

// Class declaration for model SUB_DWAV17
class SUB_DWAV17
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_SUB_DWAV17_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step0();

  // model step function
  void step1();

  // model terminate function
  void terminate();

  // Constructor
  SUB_DWAV17();

  // Destructor
  ~SUB_DWAV17();

  // private data and function members
 private:
  // Block signals
  B_SUB_DWAV17_T SUB_DWAV17_B;

  // Block states
  DW_SUB_DWAV17_T SUB_DWAV17_DW;

  // private member function(s) for subsystem '<Root>'
  void SUB_DWAV17_eml_float_colon(real_T a, real_T d, real_T b, coder::array<
    real_T, 2U> &y);
  void SUB_DWAV17_linspace(real_T d1, real_T d2, real_T y[51]);
  void SUB_DWAV17_meshgrid(const real_T x[51], const real_T y[51], real_T xx
    [2601], real_T yy[2601]);
  void SUB_DWAV17_eml_float_colon_m(real_T d, real_T b, coder::array<real_T, 2U>
    &y);
  void SUB_DWAV17_linspace_a(real_T d2, real_T n, coder::array<real_T, 2U> &y);
  boolean_T SUB_DWAV17_sortLE(const coder::array<real_T, 2U> &v, int32_T idx1,
    int32_T idx2);
  void SUB_DWAV17_unique_rows(const coder::array<real_T, 2U> &a, coder::array<
    real_T, 2U> &b);
  real_T SUB_DWAV17_sum(const real_T x_data[], const int32_T x_size[1]);
  void SUB_DWAV17_abs(const real_T x_data[], const int32_T x_size[1], real_T
                      y_data[], int32_T y_size[1]);
  real_T SUB_DWAV17_sum_c(const real_T x[3]);
  void SUB_DWAV17_minimum(const real_T x[2601], real_T *ex, int32_T *idx);
  real_T SUB_DWAV17_minimum_i(const coder::array<real_T, 1U> &x);
  boolean_T SUB_DWAV17_isequal(const int32_T varargin_1[2], const real_T
    varargin_2[2]);
  void SUB_DWAV1_SystemCore_setup_bqol(ros_slros2_internal_block_Sub_T *obj);
  void SUB_SystemCore_setup_bqolvcy332(ros_slros2_internal_block_Sub_T *obj);
  void SUB_DWAV17_SystemCore_setup(ros_slros2_internal_block_Sub_T *obj);
  void SUB_DWAV17_SystemCore_setup_b(ros_slros2_internal_block_Sub_T *obj);
  void SUB_DWAV17_SystemCore_setup_bq(ros_slros2_internal_block_Sub_T *obj);
  void SUB_DWAV17_SystemCore_setup_bqo(ros_slros2_internal_block_Sub_T *obj);
  void SUB_DWAV_SystemCore_setup_bqolv(ros_slros2_internal_block_Sub_T *obj);
  void SUB_DWA_SystemCore_setup_bqolvc(ros_slros2_internal_block_Pub_T *obj);
  void SUB_DW_SystemCore_setup_bqolvcy(ros_slros2_internal_block_Pub_T *obj);
  void SUB_D_SystemCore_setup_bqolvcy3(ros_slros2_internal_block_Pub_T *obj);
  void SUB__SystemCore_setup_bqolvcy33(ros_slros2_internal_block_Pub_T *obj);

  // Real-Time Model
  RT_MODEL_SUB_DWAV17_T SUB_DWAV17_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S4>/vel_cmd' : Unused code path elimination
//  Block '<Root>/ convert 20Hz to 10Hz' : Eliminated since input and output rates are identical
//  Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
//  Block '<S4>/Manual Switch1' : Eliminated due to constant selection input
//  Block '<S4>/Manual control ' : Eliminated due to constant selection input
//  Block '<S4>/Reshape1' : Reshape block reduction
//  Block '<S4>/Reshape2' : Reshape block reduction
//  Block '<S13>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S13>/Reshape2' : Reshape block reduction
//  Block '<S13>/Reshape3' : Reshape block reduction
//  Block '<S4>/Force to stop' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'SUB_DWAV17'
//  '<S1>'   : 'SUB_DWAV17/Diablo Bus'
//  '<S2>'   : 'SUB_DWAV17/Lidar scan'
//  '<S3>'   : 'SUB_DWAV17/Sim!=Real'
//  '<S4>'   : 'SUB_DWAV17/Subsumtion Architecture'
//  '<S5>'   : 'SUB_DWAV17/Subsystem1'
//  '<S6>'   : 'SUB_DWAV17/Subsystem2'
//  '<S7>'   : 'SUB_DWAV17/Subsystem3'
//  '<S8>'   : 'SUB_DWAV17/Ultrasonic scan1'
//  '<S9>'   : 'SUB_DWAV17/Ultrasonic scan2'
//  '<S10>'  : 'SUB_DWAV17/Ultrasonic scan3'
//  '<S11>'  : 'SUB_DWAV17/controller'
//  '<S12>'  : 'SUB_DWAV17/read map2'
//  '<S13>'  : 'SUB_DWAV17/read_Keyboard'
//  '<S14>'  : 'SUB_DWAV17/read_Keyboard1'
//  '<S15>'  : 'SUB_DWAV17/read_vel_cmd from PP controller'
//  '<S16>'  : 'SUB_DWAV17/to connect the turtlebot1'
//  '<S17>'  : 'SUB_DWAV17/to connect the turtlebot2'
//  '<S18>'  : 'SUB_DWAV17/to connect the turtlebot3'
//  '<S19>'  : 'SUB_DWAV17/to diablo'
//  '<S20>'  : 'SUB_DWAV17/vel_cmd from PP controller'
//  '<S21>'  : 'SUB_DWAV17/Diablo Bus/Blank Message'
//  '<S22>'  : 'SUB_DWAV17/Diablo Bus/[v,w]==>MotionCmd'
//  '<S23>'  : 'SUB_DWAV17/Diablo Bus/mode reader'
//  '<S24>'  : 'SUB_DWAV17/Lidar scan/Enabled Subsystem'
//  '<S25>'  : 'SUB_DWAV17/Sim!=Real/read scan'
//  '<S26>'  : 'SUB_DWAV17/Subsumtion Architecture/Behavior Switcher'
//  '<S27>'  : 'SUB_DWAV17/Subsumtion Architecture/Filter'
//  '<S28>'  : 'SUB_DWAV17/Subsumtion Architecture/Parameter defination'
//  '<S29>'  : 'SUB_DWAV17/Subsumtion Architecture/Read sesor Datas and generate Potential Feld'
//  '<S30>'  : 'SUB_DWAV17/Subsumtion Architecture/Subsystem DWA'
//  '<S31>'  : 'SUB_DWAV17/Subsumtion Architecture/force to stop'
//  '<S32>'  : 'SUB_DWAV17/Subsumtion Architecture/Filter/2D Conv'
//  '<S33>'  : 'SUB_DWAV17/Subsumtion Architecture/Filter/Kernel'
//  '<S34>'  : 'SUB_DWAV17/Subsumtion Architecture/Read sesor Datas and generate Potential Feld/MATLAB Function'
//  '<S35>'  : 'SUB_DWAV17/Subsumtion Architecture/Read sesor Datas and generate Potential Feld/MATLAB Function1'
//  '<S36>'  : 'SUB_DWAV17/Subsumtion Architecture/Read sesor Datas and generate Potential Feld/Potential Feld LiDAR'
//  '<S37>'  : 'SUB_DWAV17/Subsumtion Architecture/Read sesor Datas and generate Potential Feld/Read LiDAR Data'
//  '<S38>'  : 'SUB_DWAV17/Subsumtion Architecture/Read sesor Datas and generate Potential Feld/Read Ultrasonic Data'
//  '<S39>'  : 'SUB_DWAV17/Subsumtion Architecture/Read sesor Datas and generate Potential Feld/Scan Grid Generation'
//  '<S40>'  : 'SUB_DWAV17/Subsumtion Architecture/Read sesor Datas and generate Potential Feld/Read LiDAR Data/MATLAB Function3'
//  '<S41>'  : 'SUB_DWAV17/Subsumtion Architecture/Subsystem DWA/MATLAB Function'
//  '<S42>'  : 'SUB_DWAV17/Subsumtion Architecture/Subsystem DWA/MATLAB Function2'
//  '<S43>'  : 'SUB_DWAV17/Subsumtion Architecture/force to stop/Force to stop'
//  '<S44>'  : 'SUB_DWAV17/Subsystem1/Msg Format lesen'
//  '<S45>'  : 'SUB_DWAV17/Subsystem1/[v,w]==>geometry_msgs//Twist'
//  '<S46>'  : 'SUB_DWAV17/Subsystem2/Msg Format lesen'
//  '<S47>'  : 'SUB_DWAV17/Subsystem3/Msg Format lesen'
//  '<S48>'  : 'SUB_DWAV17/Ultrasonic scan1/Enabled Subsystem'
//  '<S49>'  : 'SUB_DWAV17/Ultrasonic scan2/Enabled Subsystem'
//  '<S50>'  : 'SUB_DWAV17/Ultrasonic scan3/Enabled Subsystem'
//  '<S51>'  : 'SUB_DWAV17/controller/Enabled Subsystem'
//  '<S52>'  : 'SUB_DWAV17/read map2/Enabled Subsystem'
//  '<S53>'  : 'SUB_DWAV17/read_Keyboard/vw_calculator'
//  '<S54>'  : 'SUB_DWAV17/vel_cmd from PP controller/Enabled Subsystem'

#endif                                 // RTW_HEADER_SUB_DWAV17_h_

//
// File trailer for generated code.
//
// [EOF]
//
