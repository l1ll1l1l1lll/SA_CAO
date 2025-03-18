//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Sub_diablo2023a.cpp
//
// Code generated for Simulink model 'Sub_diablo2023a'.
//
// Model version                  : 11.25
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Mar 18 14:57:28 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Sub_diablo2023a.h"
#include "Sub_diablo2023a_types.h"
#include "rtwtypes.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include <math.h>
#include "Sub_diablo2023a_private.h"
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include <stddef.h>
#include <stdlib.h>

int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    // Divide by zero handler
  } else {
    uint32_T tempAbsQuotient;
    tempAbsQuotient = (numerator < 0 ? ~static_cast<uint32_T>(numerator) + 1U :
                       static_cast<uint32_T>(numerator)) / (denominator < 0 ? ~
      static_cast<uint32_T>(denominator) + 1U : static_cast<uint32_T>
      (denominator));
    quotient = (numerator < 0) != (denominator < 0) ? -static_cast<int32_T>
      (tempAbsQuotient) : static_cast<int32_T>(tempAbsQuotient);
  }

  return quotient;
}

void Sub_diablo2023a::Sub_diablo2023_emxInit_real32_T
  (emxArray_real32_T_Sub_diablo2_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real32_T_Sub_diablo2_T *emxArray;
  *pEmxArray = static_cast<emxArray_real32_T_Sub_diablo2_T *>(malloc(sizeof
    (emxArray_real32_T_Sub_diablo2_T)));
  emxArray = *pEmxArray;
  emxArray->data = static_cast<real32_T *>(NULL);
  emxArray->numDimensions = numDimensions;
  emxArray->size = static_cast<int32_T *>(malloc(sizeof(int32_T)
    * static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void Sub_diablo2023a::Sub__emxEnsureCapacity_real32_T
  (emxArray_real32_T_Sub_diablo2_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc(static_cast<uint32_T>(i), sizeof(real32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real32_T) * static_cast<uint32_T>
             (oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = static_cast<real32_T *>(newData);
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void Sub_diablo2023a::Sub_diablo2023_emxFree_real32_T
  (emxArray_real32_T_Sub_diablo2_T **pEmxArray)
{
  if (*pEmxArray != static_cast<emxArray_real32_T_Sub_diablo2_T *>(NULL)) {
    if (((*pEmxArray)->data != static_cast<real32_T *>(NULL)) && (*pEmxArray)
        ->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = static_cast<emxArray_real32_T_Sub_diablo2_T *>(NULL);
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    real32_T tmp;
    real32_T tmp_0;
    tmp = static_cast<real32_T>(fabs(static_cast<real_T>(u0)));
    tmp_0 = static_cast<real32_T>(fabs(static_cast<real_T>(u1)));
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = static_cast<real32_T>(sqrt(static_cast<real_T>(u0)));
    } else if ((u0 < 0.0F) && (u1 > static_cast<real32_T>(floor
                 (static_cast<real_T>(u1))))) {
      y = (rtNaNF);
    } else {
      y = static_cast<real32_T>(pow(static_cast<real_T>(u0), static_cast<real_T>
        (u1)));
    }
  }

  return y;
}

// Function for MATLAB Function: '<S21>/Force to stop'
boolean_T Sub_diablo2023a::Sub_diablo2023a_isequal(const int32_T varargin_1[2],
  const real_T varargin_2[2])
{
  int32_T k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

void Sub_diablo2023a::Sub_diablo20_SystemCore_setup_p
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[11];
  static const char_T tmp[10] = { '/', 'j', 'o', 'y', '_', 's', 't', 'a', 't',
    'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 10; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[10] = '\x00';
  Sub_Sub_diablo2023a_1483.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void Sub_diablo2023a::Sub_diabl_SystemCore_setup_p3pb
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[8];
  static const char_T tmp[7] = { '/', 'p', 'p', '_', 'v', 'e', 'l' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 7; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[7] = '\x00';
  Sub_Sub_diablo2023a_1887.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void Sub_diablo2023a::Sub_diablo2023_SystemCore_setup
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[6];
  static const char_T tmp[5] = { '/', 's', 'c', 'a', 'n' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 5; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[5] = '\x00';
  Sub_Sub_diablo2023a_1432.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void Sub_diablo2023a::Sub_diab_SystemCore_setup_p3pbu
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[4];
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  b_zeroDelimTopic[0] = '/';
  b_zeroDelimTopic[1] = 't';
  b_zeroDelimTopic[2] = 'f';
  b_zeroDelimTopic[3] = '\x00';
  Sub_Sub_diablo2023a_1933.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void Sub_diablo2023a::Sub_diablo2_SystemCore_setup_p3
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[9];
  static const char_T tmp[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 8; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[8] = '\x00';
  Pub_Sub_diablo2023a_1880.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void Sub_diablo2023a::Sub_diablo_SystemCore_setup_p3p
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[18];
  static const char_T tmp[17] = { '/', 'd', 'i', 'a', 'b', 'l', 'o', '/', 'M',
    'o', 't', 'i', 'o', 'n', 'C', 'm', 'd' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 17; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[17] = '\x00';
  Pub_Sub_diablo2023a_1882.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void Sub_diablo2023a::step()
{
  emxArray_real32_T_Sub_diablo2_T *b;
  real_T u1;
  int32_T StateControl;
  int32_T StateFollowWaypoints;
  int32_T StateTeachandRepeat;
  int32_T StateWander;
  real32_T kd;
  real32_T tmp;
  real32_T y;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T height_ctrl_mode;
  boolean_T pitch_ctrl_mode;
  boolean_T roll_ctrl_mode;

  // MATLABSystem: '<S7>/SourceBlock'
  pitch_ctrl_mode = Sub_Sub_diablo2023a_1483.getLatestMessage
    (&Sub_diablo2023a_B.b_varargout_2_c);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S30>/Enable'

  if (pitch_ctrl_mode) {
    // SignalConversion generated from: '<S30>/In1'
    Sub_diablo2023a_B.In1_a = Sub_diablo2023a_B.b_varargout_2_c;
  }

  // End of MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

  // MATLAB Function: '<S3>/Behavior Switcher' incorporates:
  //   DataStoreRead: '<S3>/Data Store Read6'
  //   DataStoreRead: '<S3>/Data Store Read7'
  //   DataStoreWrite: '<S3>/Data Store Write10'
  //   DataStoreWrite: '<S3>/Data Store Write11'
  //   DataStoreWrite: '<S3>/Data Store Write13'
  //   DataStoreWrite: '<S3>/Data Store Write16'
  //   DataStoreWrite: '<S3>/Data Store Write6'
  //   DataStoreWrite: '<S3>/Data Store Write7'
  //   DataStoreWrite: '<S3>/Data Store Write8'
  //   DataStoreWrite: '<S3>/Data Store Write9'
  //   MATLAB Function: '<S9>/vw_calculator'

  Sub_diablo2023a_B.up = Sub_diablo2023a_DW.value[0];
  Sub_diablo2023a_B.roll = Sub_diablo2023a_DW.value[1];
  Sub_diablo2023a_B.pitch = Sub_diablo2023a_DW.value[2];
  pitch_ctrl_mode = Sub_diablo2023a_DW.mode[1];
  roll_ctrl_mode = Sub_diablo2023a_DW.mode[2];
  height_ctrl_mode = Sub_diablo2023a_DW.mode[3];
  Sub_diablo2023a_DW.mode[0] = false;
  if ((Sub_diablo2023a_B.In1_a.buttons[4] == 1) &&
      (Sub_diablo2023a_DW.prevButtons[4] == 0)) {
    Sub_diablo2023a_DW.behaviorSwitch--;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[5] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[5] == 0)) {
    Sub_diablo2023a_DW.behaviorSwitch++;
  }

  if ((Sub_diablo2023a_DW.behaviorSwitch >= 4.0) || rtIsNaN
      (Sub_diablo2023a_DW.behaviorSwitch)) {
    Sub_diablo2023a_DW.behaviorSwitch = 4.0;
  }

  if (Sub_diablo2023a_DW.behaviorSwitch <= 0.0) {
    Sub_diablo2023a_DW.behaviorSwitch = 0.0;
  }

  if (Sub_diablo2023a_DW.behaviorSwitch == 2.0) {
    if ((Sub_diablo2023a_B.In1_a.axes[7] > 0.9) && (Sub_diablo2023a_DW.prevAxes
         [7] < 0.1) && (Sub_diablo2023a_DW.prevAxes[7] > -0.1)) {
      Sub_diablo2023a_DW.WanderVelocity += 0.1;
    } else if ((Sub_diablo2023a_B.In1_a.axes[7] < -0.9) &&
               (Sub_diablo2023a_DW.prevAxes[7] < 0.1) &&
               (Sub_diablo2023a_DW.prevAxes[7] > -0.1)) {
      Sub_diablo2023a_DW.WanderVelocity -= 0.1;
    }

    if ((Sub_diablo2023a_DW.WanderVelocity >= 1.0) || rtIsNaN
        (Sub_diablo2023a_DW.WanderVelocity)) {
      Sub_diablo2023a_DW.WanderVelocity = 1.0;
    }

    if (Sub_diablo2023a_DW.WanderVelocity <= 0.0) {
      Sub_diablo2023a_DW.WanderVelocity = 0.0;
    }
  } else {
    Sub_diablo2023a_DW.WanderVelocity = 0.0;
  }

  switch (static_cast<int32_T>(Sub_diablo2023a_DW.behaviorSwitch)) {
   case 0:
    StateTeachandRepeat = 0;
    StateFollowWaypoints = 0;
    StateWander = 0;
    StateControl = 0;
    break;

   case 1:
    StateTeachandRepeat = 0;
    StateFollowWaypoints = 0;
    StateWander = 0;
    StateControl = 1;
    break;

   case 2:
    StateTeachandRepeat = 0;
    StateFollowWaypoints = 0;
    StateWander = 1;
    StateControl = 1;
    break;

   case 3:
    StateTeachandRepeat = 0;
    StateFollowWaypoints = 1;
    StateWander = 1;
    StateControl = 1;
    break;

   default:
    StateTeachandRepeat = 1;
    StateFollowWaypoints = 1;
    StateWander = 1;
    StateControl = 1;
    break;
  }

  if ((Sub_diablo2023a_B.In1_a.buttons[10] == 1) &&
      (Sub_diablo2023a_DW.prevButtons[10] == 0)) {
    Sub_diablo2023a_DW.mode[0] = true;
    pitch_ctrl_mode = true;
    roll_ctrl_mode = true;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[10] == 0) &&
             (Sub_diablo2023a_DW.prevButtons[10] == 1)) {
    Sub_diablo2023a_DW.mode[0] = true;
    pitch_ctrl_mode = false;
    roll_ctrl_mode = false;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[11] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[11] == 0)) {
    Sub_diablo2023a_DW.mode[0] = true;
    height_ctrl_mode = true;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[11] == 0) &&
             (Sub_diablo2023a_DW.prevButtons[11] == 1)) {
    Sub_diablo2023a_DW.mode[0] = true;
    height_ctrl_mode = false;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[2] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[2] == 0)) {
    Sub_diablo2023a_DW.mode[0] = true;
    Sub_diablo2023a_DW.mode[4] = true;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[3] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[3] == 0)) {
    Sub_diablo2023a_DW.mode[0] = true;
    Sub_diablo2023a_DW.mode[4] = false;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[10] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[10] == 0) &&
             (Sub_diablo2023a_B.In1_a.buttons[11] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[11] == 0)) {
    Sub_diablo2023a_DW.mode[0] = true;
    Sub_diablo2023a_B.pitch = 0.0;
    Sub_diablo2023a_B.roll = 0.0;
    pitch_ctrl_mode = false;
    roll_ctrl_mode = false;
  }

  if (pitch_ctrl_mode) {
    if ((Sub_diablo2023a_B.In1_a.axes[5] >= 1.0F) || rtIsNaNF
        (Sub_diablo2023a_B.In1_a.axes[5])) {
      y = 1.0F;
    } else {
      y = Sub_diablo2023a_B.In1_a.axes[5];
    }

    if (y <= -1.0F) {
      Sub_diablo2023a_B.pitch = -1.0;
    } else {
      Sub_diablo2023a_B.pitch = y;
    }
  }

  if (roll_ctrl_mode) {
    if ((Sub_diablo2023a_B.In1_a.axes[2] >= 1.0F) || rtIsNaNF
        (Sub_diablo2023a_B.In1_a.axes[2])) {
      y = 1.0F;
    } else {
      y = Sub_diablo2023a_B.In1_a.axes[2];
    }

    if (y <= -1.0F) {
      y = -1.0F;
    }

    Sub_diablo2023a_B.roll = -static_cast<real_T>(y) / 10.0;
  }

  if (height_ctrl_mode) {
    if ((Sub_diablo2023a_B.In1_a.axes[6] > 0.9) && (Sub_diablo2023a_DW.prevAxes
         [6] < 0.1) && (Sub_diablo2023a_DW.prevAxes[6] > -0.1)) {
      Sub_diablo2023a_B.up = Sub_diablo2023a_DW.value[0] - 0.1;
    } else if ((Sub_diablo2023a_B.In1_a.axes[6] < -0.9) &&
               (Sub_diablo2023a_DW.prevAxes[6] < 0.1) &&
               (Sub_diablo2023a_DW.prevAxes[6] > -0.1)) {
      Sub_diablo2023a_B.up = Sub_diablo2023a_DW.value[0] + 0.1;
    }

    if ((Sub_diablo2023a_B.up >= 1.0) || rtIsNaN(Sub_diablo2023a_B.up)) {
      Sub_diablo2023a_B.up = 1.0;
    }

    if (Sub_diablo2023a_B.up <= -0.1) {
      Sub_diablo2023a_B.up = -0.1;
    }
  }

  memcpy(&Sub_diablo2023a_DW.prevButtons[0], &Sub_diablo2023a_B.In1_a.buttons[0],
         sizeof(int32_T) << 7U);
  memcpy(&Sub_diablo2023a_DW.prevAxes[0], &Sub_diablo2023a_B.In1_a.axes[0],
         sizeof(real32_T) << 7U);
  Sub_diablo2023a_DW.value[0] = Sub_diablo2023a_B.up;
  Sub_diablo2023a_DW.value[1] = Sub_diablo2023a_B.roll;
  Sub_diablo2023a_DW.value[2] = Sub_diablo2023a_B.pitch;
  Sub_diablo2023a_DW.mode[1] = pitch_ctrl_mode;
  Sub_diablo2023a_DW.mode[2] = roll_ctrl_mode;
  Sub_diablo2023a_DW.mode[3] = height_ctrl_mode;

  // MATLABSystem: '<S13>/SourceBlock'
  pitch_ctrl_mode = Sub_Sub_diablo2023a_1887.getLatestMessage
    (&Sub_diablo2023a_B.b_varargout_2_k);

  // Outputs for Enabled SubSystem: '<S13>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S32>/Enable'

  if (pitch_ctrl_mode) {
    // SignalConversion generated from: '<S32>/In1'
    Sub_diablo2023a_B.In1_l = Sub_diablo2023a_B.b_varargout_2_k;
  }

  // End of MATLABSystem: '<S13>/SourceBlock'
  // End of Outputs for SubSystem: '<S13>/Enabled Subsystem'

  // Switch: '<S3>/Subsume3' incorporates:
  //   Constant: '<S3>/Constant'
  //   DataStoreRead: '<S3>/Data Store Read'

  if (StateControl > 0) {
    // Switch: '<S3>/Subsume4' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read1'

    if (StateWander > 0) {
      // Switch: '<S3>/Subsume2' incorporates:
      //   DataStoreRead: '<S3>/Data Store Read17'

      if (StateFollowWaypoints > 0) {
        // Switch: '<S3>/Subsume1' incorporates:
        //   DataStoreRead: '<S3>/Data Store Read16'

        if (StateTeachandRepeat > 0) {
          // Switch: '<S3>/Subsume3' incorporates:
          //   Reshape: '<S10>/Reshape'
          //   Switch: '<S3>/Subsume2'

          Sub_diablo2023a_B.roll = Sub_diablo2023a_B.In1_l.linear.x;
          Sub_diablo2023a_B.up = Sub_diablo2023a_B.In1_l.angular.z;
        } else {
          // Switch: '<S3>/Subsume3' incorporates:
          //   Switch: '<S3>/Subsume2'

          Sub_diablo2023a_B.roll = 0.0;
          Sub_diablo2023a_B.up = 0.0;
        }

        // End of Switch: '<S3>/Subsume1'
      } else {
        // Switch: '<S3>/Subsume3' incorporates:
        //   MATLAB Function: '<S3>/Behavior Switcher'

        Sub_diablo2023a_B.roll = Sub_diablo2023a_DW.WanderVelocity;
        Sub_diablo2023a_B.up = 0.0;
      }

      // End of Switch: '<S3>/Subsume2'
    } else {
      // Switch: '<S3>/Subsume3' incorporates:
      //   MATLAB Function: '<S9>/vw_calculator'

      Sub_diablo2023a_B.roll = Sub_diablo2023a_B.In1_a.axes[1];
      Sub_diablo2023a_B.up = Sub_diablo2023a_B.In1_a.axes[0] * 2.0;
    }

    // End of Switch: '<S3>/Subsume4'
  } else {
    Sub_diablo2023a_B.roll = 0.0;
    Sub_diablo2023a_B.up = 0.0;
  }

  // End of Switch: '<S3>/Subsume3'

  // MATLABSystem: '<S2>/SourceBlock'
  pitch_ctrl_mode = Sub_Sub_diablo2023a_1432.getLatestMessage
    (&Sub_diablo2023a_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  if (pitch_ctrl_mode) {
    // SignalConversion generated from: '<S15>/In1'
    Sub_diablo2023a_B.In1 = Sub_diablo2023a_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S2>/SourceBlock'
  // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'
  Sub_diablo2023_emxInit_real32_T(&b, 2);

  // MATLAB Function: '<S4>/read scan'
  if (rtIsNaNF(Sub_diablo2023a_B.In1.angle_min)) {
    StateFollowWaypoints = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = 1;
    Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
    b->data[0] = (rtNaNF);
  } else if (rtIsNaNF(Sub_diablo2023a_B.In1.angle_increment)) {
    StateFollowWaypoints = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = 1;
    Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
    b->data[0] = (rtNaNF);
  } else if (rtIsNaNF(Sub_diablo2023a_B.In1.angle_max)) {
    StateFollowWaypoints = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = 1;
    Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
    b->data[0] = (rtNaNF);
  } else if ((Sub_diablo2023a_B.In1.angle_increment == 0.0F) ||
             ((Sub_diablo2023a_B.In1.angle_min < Sub_diablo2023a_B.In1.angle_max)
              && (Sub_diablo2023a_B.In1.angle_increment < 0.0F)) ||
             ((Sub_diablo2023a_B.In1.angle_max < Sub_diablo2023a_B.In1.angle_min)
              && (Sub_diablo2023a_B.In1.angle_increment > 0.0F))) {
    b->size[0] = 1;
    b->size[1] = 0;
  } else {
    guard1 = false;
    guard2 = false;
    if (rtIsInfF(Sub_diablo2023a_B.In1.angle_min) || rtIsInfF
        (Sub_diablo2023a_B.In1.angle_max)) {
      if (rtIsInfF(Sub_diablo2023a_B.In1.angle_increment)) {
        StateFollowWaypoints = b->size[0] * b->size[1];
        b->size[0] = 1;
        b->size[1] = 1;
        Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
        b->data[0] = (rtNaNF);
      } else if (Sub_diablo2023a_B.In1.angle_min ==
                 Sub_diablo2023a_B.In1.angle_max) {
        StateFollowWaypoints = b->size[0] * b->size[1];
        b->size[0] = 1;
        b->size[1] = 1;
        Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
        b->data[0] = (rtNaNF);
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      if (rtIsInfF(Sub_diablo2023a_B.In1.angle_increment)) {
        StateFollowWaypoints = b->size[0] * b->size[1];
        b->size[0] = 1;
        b->size[1] = 1;
        Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
        b->data[0] = Sub_diablo2023a_B.In1.angle_min;
      } else {
        y = static_cast<real32_T>(floor(static_cast<real_T>
          (Sub_diablo2023a_B.In1.angle_min)));
        if (y == Sub_diablo2023a_B.In1.angle_min) {
          kd = static_cast<real32_T>(floor(static_cast<real_T>
            (Sub_diablo2023a_B.In1.angle_increment)));
          if (kd == Sub_diablo2023a_B.In1.angle_increment) {
            if (static_cast<real32_T>(fabs(static_cast<real_T>
                  (Sub_diablo2023a_B.In1.angle_min))) >= 1.07374182E+9F) {
              StateFollowWaypoints = b->size[0] * b->size[1];
              b->size[0] = 1;
              StateWander = static_cast<int32_T>((static_cast<real_T>
                (Sub_diablo2023a_B.In1.angle_max) -
                Sub_diablo2023a_B.In1.angle_min) /
                Sub_diablo2023a_B.In1.angle_increment);
              b->size[1] = StateWander + 1;
              Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
              for (StateTeachandRepeat = 0; StateTeachandRepeat <= StateWander;
                   StateTeachandRepeat++) {
                b->data[StateTeachandRepeat] = static_cast<real32_T>
                  (Sub_diablo2023a_B.In1.angle_increment * static_cast<real_T>
                   (StateTeachandRepeat) + Sub_diablo2023a_B.In1.angle_min);
              }
            } else if (static_cast<real32_T>(fabs(static_cast<real_T>
                         (Sub_diablo2023a_B.In1.angle_increment))) >=
                       1.07374182E+9F) {
              StateFollowWaypoints = b->size[0] * b->size[1];
              b->size[0] = 1;
              StateWander = static_cast<int32_T>((static_cast<real_T>
                (Sub_diablo2023a_B.In1.angle_max) -
                Sub_diablo2023a_B.In1.angle_min) /
                Sub_diablo2023a_B.In1.angle_increment);
              b->size[1] = StateWander + 1;
              Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
              for (StateTeachandRepeat = 0; StateTeachandRepeat <= StateWander;
                   StateTeachandRepeat++) {
                b->data[StateTeachandRepeat] = static_cast<real32_T>
                  (Sub_diablo2023a_B.In1.angle_increment * static_cast<real_T>
                   (StateTeachandRepeat) + Sub_diablo2023a_B.In1.angle_min);
              }
            } else if (static_cast<real32_T>(fabs(static_cast<real_T>
                         (Sub_diablo2023a_B.In1.angle_max))) >= 1.07374182E+9F)
            {
              StateFollowWaypoints = b->size[0] * b->size[1];
              b->size[0] = 1;
              StateWander = static_cast<int32_T>((static_cast<real_T>
                (Sub_diablo2023a_B.In1.angle_max) -
                Sub_diablo2023a_B.In1.angle_min) /
                Sub_diablo2023a_B.In1.angle_increment);
              b->size[1] = StateWander + 1;
              Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
              for (StateTeachandRepeat = 0; StateTeachandRepeat <= StateWander;
                   StateTeachandRepeat++) {
                b->data[StateTeachandRepeat] = static_cast<real32_T>
                  (Sub_diablo2023a_B.In1.angle_increment * static_cast<real_T>
                   (StateTeachandRepeat) + Sub_diablo2023a_B.In1.angle_min);
              }
            } else {
              if (Sub_diablo2023a_B.In1.angle_max < 0.0F) {
                tmp = static_cast<real32_T>(ceil(static_cast<real_T>
                  (Sub_diablo2023a_B.In1.angle_max)));
              } else {
                tmp = static_cast<real32_T>(floor(static_cast<real_T>
                  (Sub_diablo2023a_B.In1.angle_max)));
              }

              StateTeachandRepeat = div_s32(static_cast<int32_T>(tmp) -
                static_cast<int32_T>(y), static_cast<int32_T>(kd));
              StateFollowWaypoints = b->size[0] * b->size[1];
              b->size[0] = 1;
              Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
              if (Sub_diablo2023a_B.In1.angle_max < 0.0F) {
                tmp = static_cast<real32_T>(ceil(static_cast<real_T>
                  (Sub_diablo2023a_B.In1.angle_max)));
              } else {
                tmp = static_cast<real32_T>(floor(static_cast<real_T>
                  (Sub_diablo2023a_B.In1.angle_max)));
              }

              StateFollowWaypoints = b->size[0] * b->size[1];
              b->size[1] = div_s32(static_cast<int32_T>(tmp) -
                                   static_cast<int32_T>(y), static_cast<int32_T>
                                   (kd)) + 1;
              Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
              for (StateWander = 0; StateWander <= StateTeachandRepeat;
                   StateWander++) {
                b->data[StateWander] = static_cast<real32_T>(StateWander *
                  static_cast<int32_T>(kd) + static_cast<int32_T>(y));
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      }
    }

    if (guard1) {
      Sub_diablo2023a_B.pitch = floor((static_cast<real_T>
        (Sub_diablo2023a_B.In1.angle_max) - Sub_diablo2023a_B.In1.angle_min) /
        Sub_diablo2023a_B.In1.angle_increment + 0.5);
      Sub_diablo2023a_B.apnd = Sub_diablo2023a_B.pitch *
        Sub_diablo2023a_B.In1.angle_increment + Sub_diablo2023a_B.In1.angle_min;
      if (Sub_diablo2023a_B.In1.angle_increment > 0.0F) {
        Sub_diablo2023a_B.cdiff = Sub_diablo2023a_B.apnd -
          Sub_diablo2023a_B.In1.angle_max;
      } else {
        Sub_diablo2023a_B.cdiff = Sub_diablo2023a_B.In1.angle_max -
          Sub_diablo2023a_B.apnd;
      }

      Sub_diablo2023a_B.u0 = fabs(static_cast<real_T>
        (Sub_diablo2023a_B.In1.angle_min));
      u1 = fabs(static_cast<real_T>(Sub_diablo2023a_B.In1.angle_max));
      if ((Sub_diablo2023a_B.u0 >= u1) || rtIsNaN(u1)) {
        u1 = Sub_diablo2023a_B.u0;
      }

      if (fabs(Sub_diablo2023a_B.cdiff) < 2.384185791015625E-7 * u1) {
        Sub_diablo2023a_B.pitch++;
        y = Sub_diablo2023a_B.In1.angle_max;
      } else if (Sub_diablo2023a_B.cdiff > 0.0) {
        y = static_cast<real32_T>((Sub_diablo2023a_B.pitch - 1.0) *
          Sub_diablo2023a_B.In1.angle_increment +
          Sub_diablo2023a_B.In1.angle_min);
      } else {
        Sub_diablo2023a_B.pitch++;
        y = static_cast<real32_T>(Sub_diablo2023a_B.apnd);
      }

      if (Sub_diablo2023a_B.pitch >= 0.0) {
        StateWander = static_cast<int32_T>(Sub_diablo2023a_B.pitch) - 1;
      } else {
        StateWander = -1;
      }

      StateFollowWaypoints = b->size[0] * b->size[1];
      b->size[0] = 1;
      b->size[1] = StateWander + 1;
      Sub__emxEnsureCapacity_real32_T(b, StateFollowWaypoints);
      if (StateWander + 1 > 0) {
        b->data[0] = Sub_diablo2023a_B.In1.angle_min;
        if (StateWander + 1 > 1) {
          b->data[StateWander] = y;
          StateTeachandRepeat = StateWander / 2;
          for (StateFollowWaypoints = 0; StateFollowWaypoints <=
               StateTeachandRepeat - 2; StateFollowWaypoints++) {
            kd = static_cast<real32_T>(StateFollowWaypoints + 1) *
              Sub_diablo2023a_B.In1.angle_increment;
            b->data[StateFollowWaypoints + 1] = Sub_diablo2023a_B.In1.angle_min
              + kd;
            b->data[(StateWander - StateFollowWaypoints) - 1] = y - kd;
          }

          if (StateTeachandRepeat << 1 == StateWander) {
            b->data[StateTeachandRepeat] = (Sub_diablo2023a_B.In1.angle_min + y)
              / 2.0F;
          } else {
            kd = static_cast<real32_T>(StateTeachandRepeat) *
              Sub_diablo2023a_B.In1.angle_increment;
            b->data[StateTeachandRepeat] = Sub_diablo2023a_B.In1.angle_min + kd;
            b->data[StateTeachandRepeat + 1] = y - kd;
          }
        }
      }
    }
  }

  Sub_diablo2023a_DW.SFunction_DIMS3 = b->size[1];
  StateWander = b->size[1];
  if (StateWander - 1 >= 0) {
    memcpy(&Sub_diablo2023a_B.tmp_data[0], &b->data[0], static_cast<uint32_T>
           (StateWander) * sizeof(real32_T));
  }

  Sub_diablo2023_emxFree_real32_T(&b);

  // MATLAB Function: '<S17>/MATLAB Function' incorporates:
  //   DataStoreRead: '<S17>/Data Store Read'
  //   DataStoreRead: '<S17>/Data Store Read1'
  //   DataStoreRead: '<S17>/Data Store Read2'
  //   DataStoreRead: '<S17>/Data Store Read3'
  //   MATLAB Function: '<S4>/read scan'

  Sub_diablo2023a_B.pitch = 0.0;
  for (StateWander = 0; StateWander < 720; StateWander++) {
    // MATLAB Function: '<S4>/read scan'
    y = Sub_diablo2023a_B.In1.ranges[StateWander];
    if (y > Sub_diablo2023a_DW.max_scan) {
      y = (rtNaNF);
    }

    Sub_diablo2023a_B.x[StateWander] = 0.0;
    Sub_diablo2023a_B.b_x[StateWander] = 0.0;
    if (y > 0.0F) {
      if (y >= Sub_diablo2023a_DW.max_scan) {
        Sub_diablo2023a_B.pitch = 0.0;
      } else if ((y >= Sub_diablo2023a_DW.krit) && (y <
                  Sub_diablo2023a_DW.max_scan)) {
        Sub_diablo2023a_B.pitch = (1.0F / y - static_cast<real32_T>(1.0 /
          Sub_diablo2023a_DW.max_scan)) * static_cast<real32_T>
          (Sub_diablo2023a_DW.k1);
      } else if (y < Sub_diablo2023a_DW.krit) {
        Sub_diablo2023a_B.pitch = static_cast<real32_T>((1.0 /
          Sub_diablo2023a_DW.krit - 1.0 / Sub_diablo2023a_DW.max_scan) *
          Sub_diablo2023a_DW.k1 * rt_powd_snf(Sub_diablo2023a_DW.krit,
          Sub_diablo2023a_DW.k2)) * rt_powf_snf(1.0F / y, static_cast<real32_T>
          (Sub_diablo2023a_DW.k2));
      }

      y = Sub_diablo2023a_B.tmp_data[StateWander];
      Sub_diablo2023a_B.x[StateWander] = static_cast<real32_T>
        (Sub_diablo2023a_B.pitch) * static_cast<real32_T>(cos(static_cast<real_T>
        (y)));
      Sub_diablo2023a_B.b_x[StateWander] = static_cast<real32_T>
        (Sub_diablo2023a_B.pitch) * static_cast<real32_T>(sin(static_cast<real_T>
        (y)));
    }
  }

  Sub_diablo2023a_B.apnd = Sub_diablo2023a_B.x[0];
  Sub_diablo2023a_B.pitch = Sub_diablo2023a_B.b_x[0];
  for (StateWander = 0; StateWander < 719; StateWander++) {
    Sub_diablo2023a_B.apnd += Sub_diablo2023a_B.x[StateWander + 1];
    Sub_diablo2023a_B.pitch += Sub_diablo2023a_B.b_x[StateWander + 1];
  }

  // MATLAB Function: '<S20>/real' incorporates:
  //   DataStoreRead: '<S20>/Data Store Read'
  //   DataStoreRead: '<S20>/Data Store Read3'
  //   Gain: '<S22>/Gain3'
  //   MATLAB Function: '<S17>/MATLAB Function'

  Sub_diablo2023a_B.roll += -(Sub_diablo2023a_B.apnd / 20.0) *
    Sub_diablo2023a_DW.k_v * 0.05;
  if (!(Sub_diablo2023a_B.roll <= 1.0)) {
    Sub_diablo2023a_B.roll = 1.0;
  }

  Sub_diablo2023a_B.up += -(Sub_diablo2023a_B.pitch / 20.0) *
    Sub_diablo2023a_DW.k_w * 0.05;
  if (!(Sub_diablo2023a_B.up <= 2.0)) {
    Sub_diablo2023a_B.up = 2.0;
  }

  if (!(Sub_diablo2023a_B.roll >= -1.0)) {
    // MATLAB Function: '<S21>/Force to stop'
    Sub_diablo2023a_B.roll = -1.0;
  }

  if (!(Sub_diablo2023a_B.up >= -2.0)) {
    // MATLAB Function: '<S21>/Force to stop'
    Sub_diablo2023a_B.up = -2.0;
  }

  // End of MATLAB Function: '<S20>/real'

  // MATLAB Function: '<S21>/Force to stop' incorporates:
  //   MATLAB Function: '<S9>/vw_calculator'

  Sub_diablo2023a_B.xo[0] = Sub_diablo2023a_B.In1_a.buttons[0];
  Sub_diablo2023a_B.xo[1] = Sub_diablo2023a_B.In1_a.buttons[1];
  Sub_diablo2023a_B.dv[0] = 1.0;
  Sub_diablo2023a_B.dv[1] = 0.0;
  if (Sub_diablo2023a_isequal(Sub_diablo2023a_B.xo, Sub_diablo2023a_B.dv)) {
    Sub_diablo2023a_DW.stop = 0.0;
  } else {
    Sub_diablo2023a_B.dv[0] = 0.0;
    Sub_diablo2023a_B.dv[1] = 1.0;
    if (Sub_diablo2023a_isequal(Sub_diablo2023a_B.xo, Sub_diablo2023a_B.dv)) {
      Sub_diablo2023a_DW.stop = 1.0;
    }
  }

  if (Sub_diablo2023a_DW.stop != 0.0) {
    Sub_diablo2023a_B.roll = 0.0;
    Sub_diablo2023a_B.up = 0.0;
  }

  // DataStoreWrite: '<S3>/Data Store Write' incorporates:
  //   Constant: '<S3>/k_v'

  Sub_diablo2023a_DW.k_v = 2.0;

  // DataStoreWrite: '<S3>/Data Store Write1' incorporates:
  //   Constant: '<S3>/k_w'

  Sub_diablo2023a_DW.k_w = 4.0;

  // DataStoreWrite: '<S3>/Data Store Write17' incorporates:
  //   Constant: '<S3>/k1'

  Sub_diablo2023a_DW.k1 = 1.0;

  // DataStoreWrite: '<S3>/Data Store Write18' incorporates:
  //   Constant: '<S3>/kritt'

  Sub_diablo2023a_DW.krit = 0.6;

  // DataStoreWrite: '<S3>/Data Store Write2' incorporates:
  //   Constant: '<S3>/k2 how quick  repulsive at d< krit  increased '

  Sub_diablo2023a_DW.k2 = 2.0;

  // DataStoreWrite: '<S3>/Data Store Write3' incorporates:
  //   Constant: '<S3>/max_scan'

  Sub_diablo2023a_DW.max_scan = 0.9;

  // MATLABSystem: '<S14>/SourceBlock'
  Sub_Sub_diablo2023a_1933.getLatestMessage(&Sub_diablo2023a_B.b_varargout_2_m);

  // BusAssignment: '<S5>/Bus Assignment' incorporates:
  //   MATLAB Function: '<S5>/[v,w]==>geometry_msgs//Twist'

  Sub_diablo2023a_B.BusAssignment_a.linear.x = Sub_diablo2023a_B.roll;
  Sub_diablo2023a_B.BusAssignment_a.linear.y = 0.0;
  Sub_diablo2023a_B.BusAssignment_a.linear.z = 0.0;
  Sub_diablo2023a_B.BusAssignment_a.angular.x = 0.0;
  Sub_diablo2023a_B.BusAssignment_a.angular.y = 0.0;
  Sub_diablo2023a_B.BusAssignment_a.angular.z = Sub_diablo2023a_B.up;

  // MATLABSystem: '<S11>/SinkBlock'
  Pub_Sub_diablo2023a_1880.publish(&Sub_diablo2023a_B.BusAssignment_a);

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   MATLAB Function: '<Root>/[v,w]==>MotionCmd'
  //   MATLAB Function: '<Root>/mode reader'

  memset(&Sub_diablo2023a_B.BusAssignment, 0, sizeof
         (SL_Bus_motion_msgs_MotionCtrl));
  Sub_diablo2023a_B.BusAssignment.value.forward = Sub_diablo2023a_B.roll;
  Sub_diablo2023a_B.BusAssignment.value.left = Sub_diablo2023a_B.up;
  Sub_diablo2023a_B.BusAssignment.value.up = Sub_diablo2023a_DW.value[0];
  Sub_diablo2023a_B.BusAssignment.value.roll = Sub_diablo2023a_DW.value[1];
  Sub_diablo2023a_B.BusAssignment.value.pitch = Sub_diablo2023a_DW.value[2];
  Sub_diablo2023a_B.BusAssignment.mode_mark = Sub_diablo2023a_DW.mode[0];
  Sub_diablo2023a_B.BusAssignment.mode.pitch_ctrl_mode =
    Sub_diablo2023a_DW.mode[1];
  Sub_diablo2023a_B.BusAssignment.mode.roll_ctrl_mode = Sub_diablo2023a_DW.mode
    [2];
  Sub_diablo2023a_B.BusAssignment.mode.height_ctrl_mode =
    Sub_diablo2023a_DW.mode[3];
  Sub_diablo2023a_B.BusAssignment.mode.stand_mode = Sub_diablo2023a_DW.mode[4];

  // MATLABSystem: '<S12>/SinkBlock'
  Pub_Sub_diablo2023a_1882.publish(&Sub_diablo2023a_B.BusAssignment);
}

// Model initialize function
void Sub_diablo2023a::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // Start for MATLABSystem: '<S7>/SourceBlock'
  Sub_diablo20_SystemCore_setup_p(&Sub_diablo2023a_DW.obj_e);

  // Start for MATLABSystem: '<S13>/SourceBlock'
  Sub_diabl_SystemCore_setup_p3pb(&Sub_diablo2023a_DW.obj_d);

  // Start for MATLABSystem: '<S2>/SourceBlock'
  Sub_diablo2023_SystemCore_setup(&Sub_diablo2023a_DW.obj_g);

  // Start for MATLABSystem: '<S14>/SourceBlock'
  Sub_diab_SystemCore_setup_p3pbu(&Sub_diablo2023a_DW.obj);

  // Start for MATLABSystem: '<S11>/SinkBlock'
  Sub_diablo2_SystemCore_setup_p3(&Sub_diablo2023a_DW.obj_k);

  // Start for MATLABSystem: '<S12>/SinkBlock'
  Sub_diablo_SystemCore_setup_p3p(&Sub_diablo2023a_DW.obj_a);
}

// Model terminate function
void Sub_diablo2023a::terminate()
{
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!Sub_diablo2023a_DW.obj_e.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'

  // Terminate for MATLABSystem: '<S13>/SourceBlock'
  if (!Sub_diablo2023a_DW.obj_d.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/SourceBlock'

  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  if (!Sub_diablo2023a_DW.obj_g.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SourceBlock'

  // Terminate for MATLABSystem: '<S14>/SourceBlock'
  if (!Sub_diablo2023a_DW.obj.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SourceBlock'

  // Terminate for MATLABSystem: '<S11>/SinkBlock'
  if (!Sub_diablo2023a_DW.obj_k.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/SinkBlock'

  // Terminate for MATLABSystem: '<S12>/SinkBlock'
  if (!Sub_diablo2023a_DW.obj_a.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SinkBlock'
}

// Constructor
Sub_diablo2023a::Sub_diablo2023a() :
  Sub_diablo2023a_B(),
  Sub_diablo2023a_DW(),
  Sub_diablo2023a_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
Sub_diablo2023a::~Sub_diablo2023a()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Sub_diablo2023a_T * Sub_diablo2023a::getRTM()
{
  return (&Sub_diablo2023a_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
