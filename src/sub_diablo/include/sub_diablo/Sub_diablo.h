//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Sub_diablo.h
//
// Code generated for Simulink model 'Sub_diablo'.
//
// Model version                  : 14.47
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Thu Feb 27 22:54:23 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: AMD->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef Sub_diablo_h_
#define Sub_diablo_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "Sub_diablo_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Block signals (default storage)
struct B_Sub_diablo_T {
  SL_Bus_sensor_msgs_LaserScan In1;    // '<S8>/In1'
  SL_Bus_sensor_msgs_LaserScan rtb_SourceBlock_o2_m;
  real_T x[720];
  real_T b_x[720];
  SL_Bus_sensor_msgs_Joy In1_a;        // '<S24>/In1'
  SL_Bus_sensor_msgs_Joy rtb_SourceBlock_o2_b_c;
  SL_Bus_geometry_msgs_Twist BusAssignment;// '<S4>/Bus Assignment'
  char_T b_zeroDelimTopic[16];
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF deadline_k;
  real_T dv[2];
};

// Block states (default storage) for system '<Root>'
struct DW_Sub_diablo_T {
  ros_slros2_internal_block_Sub_T obj; // '<S5>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_g;// '<S1>/SourceBlock'
  ros_slros2_internal_block_Pub_T obj_k;// '<S7>/SinkBlock'
  real_T w;                            // '<S16>/Data Store1'
  real_T v;                            // '<S16>/Data Store2'
  real_T stop;                         // '<S12>/Data Store1'
  real_T k_v;                          // '<S2>/Data Store Memory'
  real_T k_w;                          // '<S2>/Data Store Memory1'
  real_T lambda;                       // '<S2>/Data Store Memory2'
  real_T max_scan;                     // '<S2>/Data Store Memory3'
  real_T behaviorSwitch;               // '<S2>/Data Store Memory6'
  real_T WanderVelocity;               // '<S2>/Data Store Memory9'
  real32_T prevAxes[128];              // '<S2>/Data Store Memory10'
  int32_T prevButtons[128];            // '<S2>/Data Store Memory7'
};

// Real-time Model Data Structure
struct tag_RTM_Sub_diablo_T {
  const char_T * volatile errorStatus;
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
};

// Class declaration for model Sub_diablo
class Sub_diablo
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_Sub_diablo_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Sub_diablo();

  // Destructor
  ~Sub_diablo();

  // private data and function members
 private:
  // Block signals
  B_Sub_diablo_T Sub_diablo_B;

  // Block states
  DW_Sub_diablo_T Sub_diablo_DW;

  // private member function(s) for subsystem '<Root>'
  boolean_T Sub_diablo_isequal(const int32_T varargin_1[2], const real_T
    varargin_2[2]);
  void Sub_diab_Subscriber_setupImpl_o(const ros_slros2_internal_block_Sub_T
    *obj);
  void Sub_diablo_Subscriber_setupImpl(const ros_slros2_internal_block_Sub_T
    *obj);
  void Sub_diablo_Publisher_setupImpl(const ros_slros2_internal_block_Pub_T *obj);

  // Real-Time Model
  RT_MODEL_Sub_diablo_T Sub_diablo_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/StateControl' : Unused code path elimination
//  Block '<S2>/StateWander' : Unused code path elimination
//  Block '<S2>/WanderVelocity' : Unused code path elimination
//  Block '<S2>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S2>/Manual Switch1' : Eliminated due to constant selection input
//  Block '<S13>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S13>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S6>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S6>/Reshape2' : Reshape block reduction
//  Block '<S6>/Reshape3' : Reshape block reduction
//  Block '<S2>/Force to stop' : Unused code path elimination
//  Block '<S2>/Gain' : Unused code path elimination
//  Block '<S13>/Gain3' : Unused code path elimination
//  Block '<S2>/lidar offset' : Unused code path elimination


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
//  '<Root>' : 'Sub_diablo'
//  '<S1>'   : 'Sub_diablo/Subscribe'
//  '<S2>'   : 'Sub_diablo/Subsumtion Architecture'
//  '<S3>'   : 'Sub_diablo/Subsystem'
//  '<S4>'   : 'Sub_diablo/Subsystem1'
//  '<S5>'   : 'Sub_diablo/keyboard-telelop'
//  '<S6>'   : 'Sub_diablo/read_Keyboard'
//  '<S7>'   : 'Sub_diablo/roboter cmd Publish1'
//  '<S8>'   : 'Sub_diablo/Subscribe/Enabled Subsystem'
//  '<S9>'   : 'Sub_diablo/Subsumtion Architecture/CalculateRepulsiveForce'
//  '<S10>'  : 'Sub_diablo/Subsumtion Architecture/MATLAB Function'
//  '<S11>'  : 'Sub_diablo/Subsumtion Architecture/Velocity calculator'
//  '<S12>'  : 'Sub_diablo/Subsumtion Architecture/force to stop'
//  '<S13>'  : 'Sub_diablo/Subsumtion Architecture/is simulation£¿'
//  '<S14>'  : 'Sub_diablo/Subsumtion Architecture/lidar offset setting'
//  '<S15>'  : 'Sub_diablo/Subsumtion Architecture/CalculateRepulsiveForce/MATLAB Function'
//  '<S16>'  : 'Sub_diablo/Subsumtion Architecture/Velocity calculator/get v_cmd'
//  '<S17>'  : 'Sub_diablo/Subsumtion Architecture/Velocity calculator/speed limiter'
//  '<S18>'  : 'Sub_diablo/Subsumtion Architecture/Velocity calculator/get v_cmd/keyboard_vw'
//  '<S19>'  : 'Sub_diablo/Subsumtion Architecture/force to stop/Force to stop'
//  '<S20>'  : 'Sub_diablo/Subsystem/Scan Reader'
//  '<S21>'  : 'Sub_diablo/Subsystem/Scan Reader/MATLAB Function'
//  '<S22>'  : 'Sub_diablo/Subsystem1/Msg Format lesen'
//  '<S23>'  : 'Sub_diablo/Subsystem1/[v,w]==>geometry_msgs//Twist'
//  '<S24>'  : 'Sub_diablo/keyboard-telelop/Enabled Subsystem'
//  '<S25>'  : 'Sub_diablo/read_Keyboard/vw_calculator'

#endif                                 // Sub_diablo_h_

//
// File trailer for generated code.
//
// [EOF]
//
