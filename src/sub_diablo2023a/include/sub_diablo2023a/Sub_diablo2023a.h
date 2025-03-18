//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Sub_diablo2023a.h
//
// Code generated for Simulink model 'Sub_diablo2023a'.
//
// Model version                  : 11.26
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Mar 18 23:29:50 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Sub_diablo2023a_h_
#define RTW_HEADER_Sub_diablo2023a_h_
#include <cstdio>
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "Sub_diablo2023a_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

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

// Block signals (default storage)
struct B_Sub_diablo2023a_T {
  SL_Bus_sensor_msgs_LaserScan In1;    // '<S15>/In1'
  SL_Bus_sensor_msgs_LaserScan b_varargout_2;
  real_T F_x[720];
  real_T F_y[720];
  SL_Bus_tf2_msgs_TFMessage b_varargout_2_m;
  real32_T tmp_data[720];
  boolean_T b_x_data[1440];
  SL_Bus_sensor_msgs_Joy In1_a;        // '<S31>/In1'
  SL_Bus_sensor_msgs_Joy b_varargout_2_c;
  boolean_T x_data[720];
  SL_Bus_motion_msgs_MotionCtrl BusAssignment;// '<Root>/Bus Assignment'
  SL_Bus_geometry_msgs_Twist In1_l;    // '<S33>/In1'
  SL_Bus_geometry_msgs_Twist b_varargout_2_k;
  SL_Bus_geometry_msgs_Twist BusAssignment_a;// '<S5>/Bus Assignment'
  real_T dv[2];
  real_T up;
  real_T roll;
  real_T pitch;
  real_T factor;
  real_T rtb_Gain3_idx_0;
  real_T d;
  real_T d1;
  int32_T xo[2];
  real32_T kd;
  int32_T nm1d2;
  int32_T b_k;
};

// Block states (default storage) for system '<Root>'
struct DW_Sub_diablo2023a_T {
  ros_slros2_internal_block_Sub_T obj; // '<S14>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_d;// '<S13>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_e;// '<S7>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_g;// '<S2>/SourceBlock'
  ros_slros2_internal_block_Pub_T obj_a;// '<S12>/SinkBlock'
  ros_slros2_internal_block_Pub_T obj_k;// '<S11>/SinkBlock'
  real_T stop;                         // '<S21>/Data Store1'
  real_T k_v;                          // '<S3>/Data Store Memory'
  real_T k_w;                          // '<S3>/Data Store Memory1'
  real_T value[3];                     // '<S3>/Data Store Memory11'
  real_T k1;                           // '<S3>/Data Store Memory17'
  real_T krit;                         // '<S3>/Data Store Memory18'
  real_T deceleration;                 // '<S3>/Data Store Memory19'
  real_T k2;                           // '<S3>/Data Store Memory2'
  real_T acceleration;                 // '<S3>/Data Store Memory22'
  real_T max_scan;                     // '<S3>/Data Store Memory3'
  real_T behaviorSwitch;               // '<S3>/Data Store Memory6'
  real_T WanderVelocity;               // '<S3>/Data Store Memory9'
  real32_T prevAxes[128];              // '<S3>/Data Store Memory10'
  int32_T prevButtons[128];            // '<S3>/Data Store Memory7'
  int32_T SFunction_DIMS3;             // '<S4>/read scan'
  boolean_T mode[5];                   // '<S3>/Data Store Memory8'
};

// Real-time Model Data Structure
struct tag_RTM_Sub_diablo2023a_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model Sub_diablo2023a
class Sub_diablo2023a
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_Sub_diablo2023a_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Sub_diablo2023a();

  // Destructor
  ~Sub_diablo2023a();

  // private data and function members
 private:
  // Block signals
  B_Sub_diablo2023a_T Sub_diablo2023a_B;

  // Block states
  DW_Sub_diablo2023a_T Sub_diablo2023a_DW;

  // private member function(s) for subsystem '<Root>'
  void Sub_diablo2023_emxInit_real32_T(emxArray_real32_T_Sub_diablo2_T
    **pEmxArray, int32_T numDimensions);
  void Sub__emxEnsureCapacity_real32_T(emxArray_real32_T_Sub_diablo2_T *emxArray,
    int32_T oldNumel);
  void Sub_diablo2023_emxFree_real32_T(emxArray_real32_T_Sub_diablo2_T
    **pEmxArray);
  real_T Sub_diablo2023a_rt_powd_snf(real_T u0, real_T u1);
  boolean_T Sub_diablo2023a_isequal(const int32_T varargin_1[2], const real_T
    varargin_2[2]);
  void Sub_diablo20_SystemCore_setup_p(ros_slros2_internal_block_Sub_T *obj);
  void Sub_diablo2023_SystemCore_setup(ros_slros2_internal_block_Sub_T *obj);
  void Sub_diabl_SystemCore_setup_p3pb(ros_slros2_internal_block_Sub_T *obj);
  void Sub_diab_SystemCore_setup_p3pbu(ros_slros2_internal_block_Sub_T *obj);
  void Sub_diablo2_SystemCore_setup_p3(ros_slros2_internal_block_Pub_T *obj);
  void Sub_diablo_SystemCore_setup_p3p(ros_slros2_internal_block_Pub_T *obj);

  // Real-Time Model
  RT_MODEL_Sub_diablo2023a_T Sub_diablo2023a_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/Reshape4' : Unused code path elimination
//  Block '<S3>/Manual Switch1' : Eliminated due to constant selection input
//  Block '<S3>/Manual Switch2' : Eliminated due to constant selection input
//  Block '<S3>/Reshape1' : Reshape block reduction
//  Block '<S3>/Reshape2' : Reshape block reduction
//  Block '<S3>/Reshape3' : Reshape block reduction
//  Block '<S22>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S9>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S9>/Reshape2' : Reshape block reduction
//  Block '<S9>/Reshape3' : Reshape block reduction
//  Block '<S3>/Force to stop' : Unused code path elimination
//  Block '<S20>/Velocity Controller' : Unused code path elimination
//  Block '<S22>/simulation LiDAR' : Unused code path elimination
//  Block '<S3>/take repulsive out' : Unused code path elimination


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
//  '<Root>' : 'Sub_diablo2023a'
//  '<S1>'   : 'Sub_diablo2023a/Blank Message'
//  '<S2>'   : 'Sub_diablo2023a/LIdar scan'
//  '<S3>'   : 'Sub_diablo2023a/Subsumtion Architecture'
//  '<S4>'   : 'Sub_diablo2023a/Subsystem'
//  '<S5>'   : 'Sub_diablo2023a/Subsystem1'
//  '<S6>'   : 'Sub_diablo2023a/[v,w]==>MotionCmd'
//  '<S7>'   : 'Sub_diablo2023a/keyboard-telelop'
//  '<S8>'   : 'Sub_diablo2023a/mode reader'
//  '<S9>'   : 'Sub_diablo2023a/read_Keyboard'
//  '<S10>'  : 'Sub_diablo2023a/read_vel_cmd from PP controller'
//  '<S11>'  : 'Sub_diablo2023a/to connect the pp controller and turtlebot3'
//  '<S12>'  : 'Sub_diablo2023a/to diablo'
//  '<S13>'  : 'Sub_diablo2023a/vel_cmd from PP controller'
//  '<S14>'  : 'Sub_diablo2023a/vel_cmd from PP controller1'
//  '<S15>'  : 'Sub_diablo2023a/LIdar scan/Enabled Subsystem'
//  '<S16>'  : 'Sub_diablo2023a/Subsumtion Architecture/Behavior Switcher'
//  '<S17>'  : 'Sub_diablo2023a/Subsumtion Architecture/CalculateRepulsiveForce'
//  '<S18>'  : 'Sub_diablo2023a/Subsumtion Architecture/Collision Detection'
//  '<S19>'  : 'Sub_diablo2023a/Subsumtion Architecture/MATLAB Function'
//  '<S20>'  : 'Sub_diablo2023a/Subsumtion Architecture/Velocity calculator'
//  '<S21>'  : 'Sub_diablo2023a/Subsumtion Architecture/force to stop'
//  '<S22>'  : 'Sub_diablo2023a/Subsumtion Architecture/is simulation£¿'
//  '<S23>'  : 'Sub_diablo2023a/Subsumtion Architecture/tf bus select'
//  '<S24>'  : 'Sub_diablo2023a/Subsumtion Architecture/CalculateRepulsiveForce/MATLAB Function'
//  '<S25>'  : 'Sub_diablo2023a/Subsumtion Architecture/Collision Detection/ReadRanges'
//  '<S26>'  : 'Sub_diablo2023a/Subsumtion Architecture/Velocity calculator/real'
//  '<S27>'  : 'Sub_diablo2023a/Subsumtion Architecture/force to stop/Force to stop'
//  '<S28>'  : 'Sub_diablo2023a/Subsystem/read scan'
//  '<S29>'  : 'Sub_diablo2023a/Subsystem1/Msg Format lesen'
//  '<S30>'  : 'Sub_diablo2023a/Subsystem1/[v,w]==>geometry_msgs//Twist'
//  '<S31>'  : 'Sub_diablo2023a/keyboard-telelop/Enabled Subsystem'
//  '<S32>'  : 'Sub_diablo2023a/read_Keyboard/vw_calculator'
//  '<S33>'  : 'Sub_diablo2023a/vel_cmd from PP controller/Enabled Subsystem'
//  '<S34>'  : 'Sub_diablo2023a/vel_cmd from PP controller1/Enabled Subsystem'

#endif                                 // RTW_HEADER_Sub_diablo2023a_h_

//
// File trailer for generated code.
//
// [EOF]
//
