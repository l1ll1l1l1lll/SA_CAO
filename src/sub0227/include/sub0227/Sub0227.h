//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Sub0227.h
//
// Code generated for Simulink model 'Sub0227'.
//
// Model version                  : 14.43
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Thu Feb 27 09:58:45 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: AMD->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef Sub0227_h_
#define Sub0227_h_
#include "rtwtypes.h"
#include "slros2_initialize.h"
#include "Sub0227_types.h"

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
struct B_Sub0227_T {
  SL_Bus_sensor_msgs_LaserScan In1;    // '<S9>/In1'
  SL_Bus_sensor_msgs_LaserScan rtb_SourceBlock_o2_m;
  real_T x[360];
  real_T b_x[360];
  SL_Bus_sensor_msgs_Joy In1_a;        // '<S23>/In1'
  SL_Bus_sensor_msgs_Joy rtb_SourceBlock_o2_b_c;
  SL_Bus_geometry_msgs_Twist BusAssignment;// '<Root>/Bus Assignment'
  char_T b_zeroDelimTopic[16];
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF deadline_k;
  real_T dv[2];
};

// Block states (default storage) for system '<Root>'
struct DW_Sub0227_T {
  ros_slros2_internal_block_Sub_T obj; // '<S6>/SourceBlock'
  ros_slros2_internal_block_Sub_T obj_g;// '<S2>/SourceBlock'
  ros_slros2_internal_block_Pub_T obj_n;// '<S8>/SinkBlock'
  real_T w;                            // '<S17>/Data Store1'
  real_T v;                            // '<S17>/Data Store2'
  real_T stop;                         // '<S13>/Data Store1'
  real_T k_v;                          // '<S3>/Data Store Memory'
  real_T k_w;                          // '<S3>/Data Store Memory1'
  real_T lambda;                       // '<S3>/Data Store Memory2'
  real_T max_scan;                     // '<S3>/Data Store Memory3'
  real_T behaviorSwitch;               // '<S3>/Data Store Memory6'
  real_T WanderVelocity;               // '<S3>/Data Store Memory9'
  real32_T prevAxes[128];              // '<S3>/Data Store Memory10'
  int32_T prevButtons[128];            // '<S3>/Data Store Memory7'
};

// Invariant block signals (default storage)
struct ConstB_Sub0227_T {
  real_T Gain;                         // '<S3>/Gain'
};

// Real-time Model Data Structure
struct tag_RTM_Sub0227_T {
  const char_T * volatile errorStatus;
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
};

extern const ConstB_Sub0227_T Sub0227_ConstB;// constant block i/o

// Class declaration for model Sub0227
class Sub0227
{
  // public data and function members
 public:
  // Real-Time Model get method
  RT_MODEL_Sub0227_T * getRTM();

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Sub0227();

  // Destructor
  ~Sub0227();

  // private data and function members
 private:
  // Block signals
  B_Sub0227_T Sub0227_B;

  // Block states
  DW_Sub0227_T Sub0227_DW;

  // private member function(s) for subsystem '<Root>'
  boolean_T Sub0227_isequal(const int32_T varargin_1[2], const real_T
    varargin_2[2]);
  void Sub0227_Subscriber_setupImpl_b(const ros_slros2_internal_block_Sub_T *obj);
  void Sub0227_Subscriber_setupImpl(const ros_slros2_internal_block_Sub_T *obj);
  void Sub0227_Publisher_setupImpl(const ros_slros2_internal_block_Pub_T *obj);

  // Real-Time Model
  RT_MODEL_Sub0227_T Sub0227_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/StateControl' : Unused code path elimination
//  Block '<S3>/StateWander' : Unused code path elimination
//  Block '<S3>/WanderVelocity' : Unused code path elimination
//  Block '<S3>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S3>/Manual Switch1' : Eliminated due to constant selection input
//  Block '<S14>/Gain2' : Eliminated nontunable gain of 1
//  Block '<S14>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S7>/Manual Switch' : Eliminated due to constant selection input
//  Block '<S7>/Reshape2' : Reshape block reduction
//  Block '<S7>/Reshape3' : Reshape block reduction
//  Block '<S3>/Force to stop' : Unused code path elimination
//  Block '<S14>/Gain3' : Unused code path elimination
//  Block '<S3>/offset for simulation' : Unused code path elimination
//  Block '<S4>/Lidar selector' : Unused code path elimination


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
//  '<Root>' : 'Sub0227'
//  '<S1>'   : 'Sub0227/Msg Format lesen'
//  '<S2>'   : 'Sub0227/Subscribe'
//  '<S3>'   : 'Sub0227/Subsumtion Architecture'
//  '<S4>'   : 'Sub0227/Subsystem'
//  '<S5>'   : 'Sub0227/[v,w]==>geometry_msgs//Twist'
//  '<S6>'   : 'Sub0227/keyboard-telelop'
//  '<S7>'   : 'Sub0227/read_Keyboard'
//  '<S8>'   : 'Sub0227/roboter cmd Publish'
//  '<S9>'   : 'Sub0227/Subscribe/Enabled Subsystem'
//  '<S10>'  : 'Sub0227/Subsumtion Architecture/CalculateRepulsiveForce'
//  '<S11>'  : 'Sub0227/Subsumtion Architecture/MATLAB Function'
//  '<S12>'  : 'Sub0227/Subsumtion Architecture/Velocity calculator'
//  '<S13>'  : 'Sub0227/Subsumtion Architecture/force to stop'
//  '<S14>'  : 'Sub0227/Subsumtion Architecture/is simulation£¿'
//  '<S15>'  : 'Sub0227/Subsumtion Architecture/lidar offset setting'
//  '<S16>'  : 'Sub0227/Subsumtion Architecture/CalculateRepulsiveForce/MATLAB Function'
//  '<S17>'  : 'Sub0227/Subsumtion Architecture/Velocity calculator/get v_cmd'
//  '<S18>'  : 'Sub0227/Subsumtion Architecture/Velocity calculator/speed limiter'
//  '<S19>'  : 'Sub0227/Subsumtion Architecture/Velocity calculator/get v_cmd/keyboard_vw'
//  '<S20>'  : 'Sub0227/Subsumtion Architecture/force to stop/Force to stop'
//  '<S21>'  : 'Sub0227/Subsystem/Scan Reader'
//  '<S22>'  : 'Sub0227/Subsystem/Scan Reader/MATLAB Function'
//  '<S23>'  : 'Sub0227/keyboard-telelop/Enabled Subsystem'
//  '<S24>'  : 'Sub0227/read_Keyboard/vw_calculator'

#endif                                 // Sub0227_h_

//
// File trailer for generated code.
//
// [EOF]
//
