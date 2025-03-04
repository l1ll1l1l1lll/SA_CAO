//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Sub_diablo2023a_types.h
//
// Code generated for Simulink model 'Sub_diablo2023a'.
//
// Model version                  : 11.3
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Mar  4 03:55:39 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Sub_diablo2023a_types_h_
#define RTW_HEADER_Sub_diablo2023a_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_motion_msgs_MovementCtrlData_
#define DEFINED_TYPEDEF_FOR_SL_Bus_motion_msgs_MovementCtrlData_

// MsgType=motion_msgs/MovementCtrlData
struct SL_Bus_motion_msgs_MovementCtrlData
{
  real_T forward;
  real_T left;
  real_T up;
  real_T roll;
  real_T pitch;
  real_T leg_split;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_motion_msgs_MovementCtrlMode_
#define DEFINED_TYPEDEF_FOR_SL_Bus_motion_msgs_MovementCtrlMode_

// MsgType=motion_msgs/MovementCtrlMode
struct SL_Bus_motion_msgs_MovementCtrlMode
{
  boolean_T pitch_ctrl_mode;
  boolean_T roll_ctrl_mode;
  boolean_T height_ctrl_mode;
  boolean_T stand_mode;
  boolean_T jump_mode;
  boolean_T split_mode;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_motion_msgs_MotionCtrl_
#define DEFINED_TYPEDEF_FOR_SL_Bus_motion_msgs_MotionCtrl_

// MsgType=motion_msgs/MotionCtrl
struct SL_Bus_motion_msgs_MotionCtrl
{
  boolean_T mode_mark;

  // MsgType=motion_msgs/MovementCtrlData
  SL_Bus_motion_msgs_MovementCtrlData value;

  // MsgType=motion_msgs/MovementCtrlMode
  SL_Bus_motion_msgs_MovementCtrlMode mode;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_builtin_interfaces_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_builtin_interfaces_Time_

// MsgType=builtin_interfaces/Time
struct SL_Bus_builtin_interfaces_Time
{
  int32_T sec;
  uint32_T nanosec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_std_msgs_Header
{
  // MsgType=builtin_interfaces/Time
  SL_Bus_builtin_interfaces_Time stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=frame_id_SL_Info:TruncateAction=warn 
  uint8_T frame_id[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=frame_id
  SL_Bus_ROSVariableLengthArrayInfo frame_id_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_sensor_msgs_LaserScan_
#define DEFINED_TYPEDEF_FOR_SL_Bus_sensor_msgs_LaserScan_

// MsgType=sensor_msgs/LaserScan
struct SL_Bus_sensor_msgs_LaserScan
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;
  real32_T angle_min;
  real32_T angle_max;
  real32_T angle_increment;
  real32_T time_increment;
  real32_T scan_time;
  real32_T range_min;
  real32_T range_max;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=ranges_SL_Info:TruncateAction=warn 
  real32_T ranges[720];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=ranges
  SL_Bus_ROSVariableLengthArrayInfo ranges_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=intensities_SL_Info:TruncateAction=warn 
  real32_T intensities[720];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=intensities
  SL_Bus_ROSVariableLengthArrayInfo intensities_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_sensor_msgs_Joy_
#define DEFINED_TYPEDEF_FOR_SL_Bus_sensor_msgs_Joy_

// MsgType=sensor_msgs/Joy
struct SL_Bus_sensor_msgs_Joy
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=axes_SL_Info:TruncateAction=warn
  real32_T axes[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=axes
  SL_Bus_ROSVariableLengthArrayInfo axes_SL_Info;

  // IsVarLen=1:VarLenCategory=data:VarLenElem=buttons_SL_Info:TruncateAction=warn 
  int32_T buttons[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=buttons
  SL_Bus_ROSVariableLengthArrayInfo buttons_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_geometry_msgs_Vector3
{
  real_T x;
  real_T y;
  real_T z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 angular;
};

#endif

// Custom Type definition for MATLABSystem: '<S11>/SourceBlock'
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include "rmw/types.h"
#include "rmw/types.h"
#ifndef struct_ros_slros2_internal_block_Sub_T
#define struct_ros_slros2_internal_block_Sub_T

struct ros_slros2_internal_block_Sub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slros2_internal_block_Sub_T

#ifndef struct_ros_slros2_internal_block_Pub_T
#define struct_ros_slros2_internal_block_Pub_T

struct ros_slros2_internal_block_Pub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slros2_internal_block_Pub_T

// Forward declaration for rtModel
typedef struct tag_RTM_Sub_diablo2023a_T RT_MODEL_Sub_diablo2023a_T;

#endif                                 // RTW_HEADER_Sub_diablo2023a_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
