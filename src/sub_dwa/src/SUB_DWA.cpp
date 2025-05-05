//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: SUB_DWA.cpp
//
// Code generated for Simulink model 'SUB_DWA'.
//
// Model version                  : 12.108
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Mon May  5 23:16:58 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "SUB_DWA.h"
#include "SUB_DWA_types.h"
#include "rtwtypes.h"
#include "coder_array.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include <string.h>
#include "SUB_DWA_private.h"
#include "rmw/qos_profiles.h"
#include <stddef.h>

static void rate_monotonic_scheduler(RT_MODEL_SUB_DWA_T *const SUB_DWA_M);
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

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void SUB_DWA_SetEventsForThisBaseStep(boolean_T *eventFlags, RT_MODEL_SUB_DWA_T *
  const SUB_DWA_M)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(SUB_DWA_M, 1));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(RT_MODEL_SUB_DWA_T *const SUB_DWA_M)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (SUB_DWA_M->Timing.TaskCounters.TID[1])++;
  if ((SUB_DWA_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.1s, 0.0s] 
    SUB_DWA_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// Function for MATLAB Function: '<S22>/Read Ultrasonic Data'
void SUB_DWA::SUB_DWA_eml_float_colon(real_T a, real_T d, real_T b, coder::array<
  real_T, 2U> &y)
{
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  real_T u0;
  real_T u1;
  int32_T n;
  ndbl = floor((b - a) / d + 0.5);
  apnd = ndbl * d + a;
  if (d > 0.0) {
    cdiff = apnd - b;
  } else {
    cdiff = b - apnd;
  }

  u0 = fabs(a);
  u1 = fabs(b);
  if ((u0 >= u1) || rtIsNaN(u1)) {
    u1 = u0;
  }

  if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = (ndbl - 1.0) * d + a;
  } else {
    ndbl++;
  }

  if (ndbl >= 0.0) {
    n = static_cast<int32_T>(ndbl) - 1;
  } else {
    n = -1;
  }

  y.set_size(1, n + 1);
  if (n + 1 > 0) {
    y[0] = a;
    if (n + 1 > 1) {
      int32_T nm1d2;
      y[n] = apnd;
      nm1d2 = n / 2;
      for (int32_T k = 0; k <= nm1d2 - 2; k++) {
        ndbl = (static_cast<real_T>(k) + 1.0) * d;
        y[k + 1] = a + ndbl;
        y[(n - k) - 1] = apnd - ndbl;
      }

      if (nm1d2 << 1 == n) {
        y[nm1d2] = (a + apnd) / 2.0;
      } else {
        ndbl = static_cast<real_T>(nm1d2) * d;
        y[nm1d2] = a + ndbl;
        y[nm1d2 + 1] = apnd - ndbl;
      }
    }
  }
}

// Function for MATLAB Function: '<S23>/MATLAB Function'
void SUB_DWA::SUB_DWA_linspace(real_T d1, real_T d2, real_T y[51])
{
  y[50] = d2;
  y[0] = d1;
  if (d1 == -d2) {
    real_T delta1;
    delta1 = d2 / 50.0;
    for (int32_T c_k = 0; c_k < 49; c_k++) {
      y[c_k + 1] = ((static_cast<real_T>(c_k) + 2.0) * 2.0 - 52.0) * delta1;
    }

    y[25] = 0.0;
  } else if (((d1 < 0.0) != (d2 < 0.0)) && ((fabs(d1) > 8.9884656743115785E+307)
              || (fabs(d2) > 8.9884656743115785E+307))) {
    real_T delta1;
    real_T delta2;
    delta1 = d1 / 50.0;
    delta2 = d2 / 50.0;
    for (int32_T c_k = 0; c_k < 49; c_k++) {
      y[c_k + 1] = ((static_cast<real_T>(c_k) + 1.0) * delta2 + d1) - (
        static_cast<real_T>(c_k) + 1.0) * delta1;
    }
  } else {
    real_T delta1;
    delta1 = (d2 - d1) / 50.0;
    for (int32_T c_k = 0; c_k < 49; c_k++) {
      y[c_k + 1] = (static_cast<real_T>(c_k) + 1.0) * delta1 + d1;
    }
  }
}

// Function for MATLAB Function: '<S23>/MATLAB Function'
void SUB_DWA::SUB_DWA_meshgrid(const real_T x[51], const real_T y[51], real_T
  xx[2601], real_T yy[2601])
{
  for (int32_T j = 0; j < 51; j++) {
    memcpy(&yy[j * 51], &y[0], 51U * sizeof(real_T));
    for (int32_T i = 0; i < 51; i++) {
      xx[i + 51 * j] = x[j];
    }
  }
}

// Function for MATLAB Function: '<S23>/MATLAB Function'
real_T SUB_DWA::SUB_DWA_sum_c(const real_T x[3])
{
  return (x[0] + x[1]) + x[2];
}

// Function for MATLAB Function: '<S23>/MATLAB Function'
void SUB_DWA::SUB_DWA_eml_float_colon_m(real_T d, real_T b, coder::array<real_T,
  2U> &y)
{
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  real_T u1;
  int32_T n;
  ndbl = floor(b / d + 0.5);
  apnd = ndbl * d;
  if (d > 0.0) {
    cdiff = apnd - b;
  } else {
    cdiff = b - apnd;
  }

  u1 = fabs(b);
  if ((u1 <= 0.0) || rtIsNaN(u1)) {
    u1 = 0.0;
  }

  if (fabs(cdiff) < 4.4408920985006262E-16 * u1) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = (ndbl - 1.0) * d;
  } else {
    ndbl++;
  }

  if (ndbl >= 0.0) {
    n = static_cast<int32_T>(ndbl) - 1;
  } else {
    n = -1;
  }

  y.set_size(1, n + 1);
  if (n + 1 > 0) {
    y[0] = 0.0;
    if (n + 1 > 1) {
      int32_T nm1d2;
      y[n] = apnd;
      nm1d2 = n / 2;
      for (int32_T k = 0; k <= nm1d2 - 2; k++) {
        ndbl = (static_cast<real_T>(k) + 1.0) * d;
        y[k + 1] = ndbl;
        y[(n - k) - 1] = apnd - ndbl;
      }

      if (nm1d2 << 1 == n) {
        y[nm1d2] = apnd / 2.0;
      } else {
        ndbl = static_cast<real_T>(nm1d2) * d;
        y[nm1d2] = ndbl;
        y[nm1d2 + 1] = apnd - ndbl;
      }
    }
  }
}

// Function for MATLAB Function: '<S23>/MATLAB Function'
void SUB_DWA::SUB_DWA_linspace_a(real_T d2, real_T n, coder::array<real_T, 2U>
  &y)
{
  real_T delta1;
  delta1 = floor(n);
  y.set_size(1, static_cast<int32_T>(delta1));
  if (static_cast<int32_T>(delta1) >= 1) {
    int32_T y_tmp;
    y_tmp = static_cast<int32_T>(delta1) - 1;
    y[static_cast<int32_T>(delta1) - 1] = d2;
    if (y.size(1) >= 2) {
      y[0] = 0.0;
      if (y.size(1) >= 3) {
        if (-d2 == 0.0) {
          delta1 = d2 / (static_cast<real_T>(y.size(1)) - 1.0);
          for (int32_T c_k = 2; c_k <= y_tmp; c_k++) {
            y[c_k - 1] = static_cast<real_T>(((c_k << 1) - y.size(1)) - 1) *
              delta1;
          }

          if ((y.size(1) & 1) == 1) {
            y[y.size(1) >> 1] = 0.0;
          }
        } else if ((d2 < 0.0) && (fabs(d2) > 8.9884656743115785E+307)) {
          delta1 = d2 / (static_cast<real_T>(y.size(1)) - 1.0);
          y_tmp = y.size(1);
          for (int32_T c_k = 0; c_k <= y_tmp - 3; c_k++) {
            y[c_k + 1] = (static_cast<real_T>(c_k) + 1.0) * delta1;
          }
        } else {
          delta1 = d2 / (static_cast<real_T>(y.size(1)) - 1.0);
          y_tmp = y.size(1);
          for (int32_T c_k = 0; c_k <= y_tmp - 3; c_k++) {
            y[c_k + 1] = (static_cast<real_T>(c_k) + 1.0) * delta1;
          }
        }
      }
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// Function for MATLAB Function: '<S23>/MATLAB Function'
boolean_T SUB_DWA::SUB_DWA_sortLE(const coder::array<real_T, 2U> &v, int32_T
  idx1, int32_T idx2)
{
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    SUB_DWA_B.v1 = v[(v.size(0) * k + idx1) - 1];
    SUB_DWA_B.v2 = v[(v.size(0) * k + idx2) - 1];
    if ((SUB_DWA_B.v1 == SUB_DWA_B.v2) || (rtIsNaN(SUB_DWA_B.v1) && rtIsNaN
         (SUB_DWA_B.v2))) {
      k++;
    } else {
      if ((!(SUB_DWA_B.v1 <= SUB_DWA_B.v2)) && (!rtIsNaN(SUB_DWA_B.v2))) {
        p = false;
      }

      exitg1 = true;
    }
  }

  return p;
}

// Function for MATLAB Function: '<S23>/MATLAB Function'
void SUB_DWA::SUB_DWA_unique_rows(const coder::array<real_T, 2U> &a, coder::
  array<real_T, 2U> &b)
{
  int32_T b_k;
  int32_T b_p;
  int32_T c_i;
  int32_T d_j;
  int32_T exitg1;
  int32_T i2;
  int32_T k;
  int32_T k0;
  int32_T kEnd;
  int32_T khi;
  int32_T nb;
  int32_T pEnd;
  int32_T q;
  int32_T qEnd;
  boolean_T exitg2;
  boolean_T p;
  if (a.size(0) == 0) {
    b.set_size(0, 2);
  } else {
    khi = a.size(0) + 1;
    SUB_DWA_B.idx.set_size(a.size(0));
    c_i = a.size(0);
    for (k = 0; k < c_i; k++) {
      SUB_DWA_B.idx[k] = 0;
    }

    SUB_DWA_B.iwork.set_size(a.size(0));
    nb = a.size(0) - 1;
    for (k = 1; k <= nb; k += 2) {
      if (SUB_DWA_sortLE(a, k, k + 1)) {
        SUB_DWA_B.idx[k - 1] = k;
        SUB_DWA_B.idx[k] = k + 1;
      } else {
        SUB_DWA_B.idx[k - 1] = k + 1;
        SUB_DWA_B.idx[k] = k;
      }
    }

    if ((static_cast<uint32_T>(a.size(0)) & 1U) != 0U) {
      SUB_DWA_B.idx[a.size(0) - 1] = a.size(0);
    }

    c_i = 2;
    while (c_i < khi - 1) {
      i2 = c_i << 1;
      d_j = 1;
      for (pEnd = c_i + 1; pEnd < khi; pEnd = qEnd + c_i) {
        b_p = d_j;
        q = pEnd;
        qEnd = d_j + i2;
        if (qEnd > khi) {
          qEnd = khi;
        }

        b_k = 0;
        kEnd = qEnd - d_j;
        while (b_k + 1 <= kEnd) {
          k = SUB_DWA_B.idx[b_p - 1];
          k0 = SUB_DWA_B.idx[q - 1];
          if (SUB_DWA_sortLE(a, k, k0)) {
            SUB_DWA_B.iwork[b_k] = k;
            b_p++;
            if (b_p == pEnd) {
              while (q < qEnd) {
                b_k++;
                SUB_DWA_B.iwork[b_k] = SUB_DWA_B.idx[q - 1];
                q++;
              }
            }
          } else {
            SUB_DWA_B.iwork[b_k] = k0;
            q++;
            if (q == qEnd) {
              while (b_p < pEnd) {
                b_k++;
                SUB_DWA_B.iwork[b_k] = SUB_DWA_B.idx[b_p - 1];
                b_p++;
              }
            }
          }

          b_k++;
        }

        for (k = 0; k < kEnd; k++) {
          SUB_DWA_B.idx[(d_j + k) - 1] = SUB_DWA_B.iwork[k];
        }

        d_j = qEnd;
      }

      c_i = i2;
    }

    b.set_size(a.size(0), 2);
    c_i = a.size(0) << 1;
    for (k = 0; k < c_i; k++) {
      b[k] = a[k];
    }

    SUB_DWA_B.ycol.set_size(a.size(0));
    for (khi = 0; khi < 2; khi++) {
      for (k = 0; k <= nb; k++) {
        SUB_DWA_B.ycol[k] = b[(b.size(0) * khi + SUB_DWA_B.idx[k]) - 1];
      }

      for (k = 0; k <= nb; k++) {
        b[k + b.size(0) * khi] = SUB_DWA_B.ycol[k];
      }
    }

    nb = -1;
    khi = a.size(0);
    k = 0;
    while (k + 1 <= khi) {
      k0 = k;
      do {
        exitg1 = 0;
        k++;
        if (k + 1 > khi) {
          exitg1 = 1;
        } else {
          p = false;
          c_i = 0;
          exitg2 = false;
          while ((!exitg2) && (c_i < 2)) {
            if (b[b.size(0) * c_i + k0] != b[b.size(0) * c_i + k]) {
              p = true;
              exitg2 = true;
            } else {
              c_i++;
            }
          }

          if (p) {
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);

      nb++;
      b[nb] = b[k0];
      b[nb + b.size(0)] = b[k0 + b.size(0)];
    }

    if (nb + 1 < 1) {
      nb = -1;
      k = -1;
    } else {
      k = nb;
    }

    c_i = k + 1;
    for (k = 0; k < 2; k++) {
      for (k0 = 0; k0 < c_i; k0++) {
        b[k0 + (nb + 1) * k] = b[b.size(0) * k + k0];
      }
    }

    b.set_size(nb + 1, 2);
  }
}

// Function for MATLAB Function: '<S23>/MATLAB Function'
real_T SUB_DWA::SUB_DWA_sum(const real_T x_data[], const int32_T x_size[1])
{
  real_T y;
  if (x_size[0] == 0) {
    y = 0.0;
  } else {
    int32_T firstBlockLength;
    int32_T lastBlockLength;
    int32_T nblocks;
    int32_T xblockoffset;
    if (x_size[0] <= 1024) {
      firstBlockLength = x_size[0];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int32_T>(static_cast<uint32_T>(x_size[0]) >> 10);
      lastBlockLength = x_size[0] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }

    y = x_data[0];
    for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
      y += x_data[xblockoffset - 1];
    }

    for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
    {
      real_T bsum;
      int32_T hi;
      xblockoffset = (firstBlockLength - 1) << 10;
      bsum = x_data[xblockoffset];
      if (firstBlockLength == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }

      for (int32_T b_k = 2; b_k <= hi; b_k++) {
        bsum += x_data[(xblockoffset + b_k) - 1];
      }

      y += bsum;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S23>/MATLAB Function'
void SUB_DWA::SUB_DWA_minimum(const real_T x[2601], real_T *ex, int32_T *idx)
{
  int32_T b_idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    b_idx = 1;
  } else {
    boolean_T exitg1;
    b_idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 2602)) {
      if (!rtIsNaN(x[k - 1])) {
        b_idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_idx == 0) {
    *ex = x[0];
    *idx = 1;
  } else {
    *ex = x[b_idx - 1];
    *idx = b_idx;
    for (k = b_idx + 1; k < 2602; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (*ex > x_0) {
        *ex = x_0;
        *idx = k;
      }
    }
  }
}

// Function for MATLAB Function: '<S23>/MATLAB Function2'
real_T SUB_DWA::SUB_DWA_minimum_i(const coder::array<real_T, 1U> &x)
{
  real_T ex;
  int32_T last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
    } else {
      ex = x[x.size(0) - 1];
      if (!(x[0] > ex)) {
        if (rtIsNaN(x[0])) {
          if (rtIsNaN(ex)) {
            ex = x[0];
          }
        } else {
          ex = x[0];
        }
      }
    }
  } else {
    int32_T idx;
    int32_T k;
    if (!rtIsNaN(x[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      for (k = idx + 1; k <= last; k++) {
        real_T x_0;
        x_0 = x[k - 1];
        if (ex > x_0) {
          ex = x_0;
        }
      }
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S24>/Force to stop'
boolean_T SUB_DWA::SUB_DWA_isequal(const int32_T varargin_1[2], const real_T
  varargin_2[2])
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

void SUB_DWA::SUB_DWA_SystemCore_setup_b2fg(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[5];
  static const char_T b_zeroDelimTopic_0[5] = "/joy";

  // Start for MATLABSystem: '<S8>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S8>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)5.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 5; i++) {
    // Start for MATLABSystem: '<S8>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_SUB_DWA_1483.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void SUB_DWA::SUB_DWA_SystemCore_setup_b2fgx2(ros_slros2_internal_block_Sub_T
  *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[8];
  static const char_T b_zeroDelimTopic_0[8] = "/pp_vel";

  // Start for MATLABSystem: '<S13>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S13>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 8; i++) {
    // Start for MATLABSystem: '<S13>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_SUB_DWA_1887.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void SUB_DWA::SUB_DWA_SystemCore_setup(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[6];
  static const char_T b_zeroDelimTopic_0[6] = "/scan";

  // Start for MATLABSystem: '<S2>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S2>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S2>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_SUB_DWA_1432.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void SUB_DWA::SUB_DWA_SystemCore_setup_b(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[18];
  static const char_T b_zeroDelimTopic_0[18] = "/ultrasonic/front";

  // Start for MATLABSystem: '<S5>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S5>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 18; i++) {
    // Start for MATLABSystem: '<S5>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_SUB_DWA_2634.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void SUB_DWA::SUB_DWA_SystemCore_setup_b2(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[17];
  static const char_T b_zeroDelimTopic_0[17] = "/ultrasonic/left";

  // Start for MATLABSystem: '<S6>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S6>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 17; i++) {
    // Start for MATLABSystem: '<S6>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_SUB_DWA_2651.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void SUB_DWA::SUB_DWA_SystemCore_setup_b2f(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[18];
  static const char_T b_zeroDelimTopic_0[18] = "/ultrasonic/right";

  // Start for MATLABSystem: '<S7>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S7>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 18; i++) {
    // Start for MATLABSystem: '<S7>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_SUB_DWA_2652.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void SUB_DWA::SUB_DWA_SystemCore_setup_b2fgx(ros_slros2_internal_block_Pub_T
  *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[18];
  static const char_T b_zeroDelimTopic_0[18] = "/diablo/MotionCmd";

  // Start for MATLABSystem: '<S12>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S12>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 18; i++) {
    // Start for MATLABSystem: '<S12>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_SUB_DWA_1882.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

// Model step function for TID0
void SUB_DWA::step0()                  // Sample time: [0.05s, 0.0s]
{
  {                                    // Sample time: [0.05s, 0.0s]
    rate_monotonic_scheduler((&SUB_DWA_M));
  }
}

// Model step function for TID1
void SUB_DWA::step1()                  // Sample time: [0.1s, 0.0s]
{
  int32_T loop_ub;
  boolean_T height_ctrl_mode;
  boolean_T pitch_ctrl_mode;
  boolean_T roll_ctrl_mode;
  static const real_T b[9] = { 0.36787944117144233, 0.60653065971263342,
    0.36787944117144233, 0.60653065971263342, 1.0, 0.60653065971263342,
    0.36787944117144233, 0.60653065971263342, 0.36787944117144233 };

  boolean_T guard1;

  // MATLABSystem: '<S8>/SourceBlock'
  pitch_ctrl_mode = Sub_SUB_DWA_1483.getLatestMessage(&SUB_DWA_B.b_varargout_2_c);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S40>/Enable'

  // Start for MATLABSystem: '<S8>/SourceBlock'
  if (pitch_ctrl_mode) {
    // SignalConversion generated from: '<S40>/In1'
    SUB_DWA_B.In1_a = SUB_DWA_B.b_varargout_2_c;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'

  // MATLABSystem: '<S13>/SourceBlock'
  pitch_ctrl_mode = Sub_SUB_DWA_1887.getLatestMessage(&SUB_DWA_B.b_varargout_2_p);

  // Outputs for Enabled SubSystem: '<S13>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S42>/Enable'

  // Start for MATLABSystem: '<S13>/SourceBlock'
  if (pitch_ctrl_mode) {
    // SignalConversion generated from: '<S42>/In1'
    SUB_DWA_B.In1_l = SUB_DWA_B.b_varargout_2_p;
  }

  // End of Start for MATLABSystem: '<S13>/SourceBlock'
  // End of Outputs for SubSystem: '<S13>/Enabled Subsystem'

  // MATLAB Function: '<S4>/Parameter defination'
  SUB_DWA_B.rtb_param_weight[0] = 1.0;
  SUB_DWA_B.rtb_param_weight[1] = 16.0;
  SUB_DWA_B.rtb_param_weight[2] = 2.0;

  // MATLABSystem: '<S2>/SourceBlock'
  pitch_ctrl_mode = Sub_SUB_DWA_1432.getLatestMessage(&SUB_DWA_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S17>/Enable'

  // Start for MATLABSystem: '<S2>/SourceBlock'
  if (pitch_ctrl_mode) {
    // SignalConversion generated from: '<S17>/In1'
    SUB_DWA_B.In1 = SUB_DWA_B.b_varargout_2;
  }

  // End of Start for MATLABSystem: '<S2>/SourceBlock'
  // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'

  // MATLAB Function: '<S3>/read scan'
  if (rtIsNaNF(SUB_DWA_B.In1.angle_min)) {
    SUB_DWA_B.y.set_size(1, 1);
    SUB_DWA_B.y[0] = (rtNaNF);
  } else if (rtIsNaNF(SUB_DWA_B.In1.angle_increment)) {
    SUB_DWA_B.y.set_size(1, 1);
    SUB_DWA_B.y[0] = (rtNaNF);
  } else if (rtIsNaNF(SUB_DWA_B.In1.angle_max)) {
    SUB_DWA_B.y.set_size(1, 1);
    SUB_DWA_B.y[0] = (rtNaNF);
  } else if ((SUB_DWA_B.In1.angle_increment == 0.0F) ||
             ((SUB_DWA_B.In1.angle_min < SUB_DWA_B.In1.angle_max) &&
              (SUB_DWA_B.In1.angle_increment < 0.0F)) ||
             ((SUB_DWA_B.In1.angle_max < SUB_DWA_B.In1.angle_min) &&
              (SUB_DWA_B.In1.angle_increment > 0.0F))) {
    SUB_DWA_B.y.set_size(1, 0);
  } else {
    guard1 = false;
    if (rtIsInfF(SUB_DWA_B.In1.angle_min) || rtIsInfF(SUB_DWA_B.In1.angle_max))
    {
      if (rtIsInfF(SUB_DWA_B.In1.angle_increment)) {
        SUB_DWA_B.y.set_size(1, 1);
        SUB_DWA_B.y[0] = (rtNaNF);
      } else if (SUB_DWA_B.In1.angle_min == SUB_DWA_B.In1.angle_max) {
        SUB_DWA_B.y.set_size(1, 1);
        SUB_DWA_B.y[0] = (rtNaNF);
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (rtIsInfF(SUB_DWA_B.In1.angle_increment)) {
        SUB_DWA_B.y.set_size(1, 1);
        SUB_DWA_B.y[0] = SUB_DWA_B.In1.angle_min;
      } else if ((static_cast<real32_T>(floor(static_cast<real_T>
                    (SUB_DWA_B.In1.angle_min))) == SUB_DWA_B.In1.angle_min) && (
                  static_cast<real32_T>(floor(static_cast<real_T>
                    (SUB_DWA_B.In1.angle_increment))) ==
                  SUB_DWA_B.In1.angle_increment)) {
        if (static_cast<real32_T>(fabs(static_cast<real_T>
              (SUB_DWA_B.In1.angle_min))) >= 1.07374182E+9F) {
          SUB_DWA_B.nm1d2 = static_cast<int32_T>((static_cast<real_T>
            (SUB_DWA_B.In1.angle_max) - SUB_DWA_B.In1.angle_min) /
            SUB_DWA_B.In1.angle_increment);
          SUB_DWA_B.y.set_size(1, SUB_DWA_B.nm1d2 + 1);
          for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
            SUB_DWA_B.y[SUB_DWA_B.n] = static_cast<real32_T>
              (SUB_DWA_B.In1.angle_increment * static_cast<real_T>(SUB_DWA_B.n)
               + SUB_DWA_B.In1.angle_min);
          }
        } else if (static_cast<real32_T>(fabs(static_cast<real_T>
                     (SUB_DWA_B.In1.angle_increment))) >= 1.07374182E+9F) {
          SUB_DWA_B.nm1d2 = static_cast<int32_T>((static_cast<real_T>
            (SUB_DWA_B.In1.angle_max) - SUB_DWA_B.In1.angle_min) /
            SUB_DWA_B.In1.angle_increment);
          SUB_DWA_B.y.set_size(1, SUB_DWA_B.nm1d2 + 1);
          for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
            SUB_DWA_B.y[SUB_DWA_B.n] = static_cast<real32_T>
              (SUB_DWA_B.In1.angle_increment * static_cast<real_T>(SUB_DWA_B.n)
               + SUB_DWA_B.In1.angle_min);
          }
        } else if (static_cast<real32_T>(fabs(static_cast<real_T>
                     (SUB_DWA_B.In1.angle_max))) >= 1.07374182E+9F) {
          SUB_DWA_B.nm1d2 = static_cast<int32_T>((static_cast<real_T>
            (SUB_DWA_B.In1.angle_max) - SUB_DWA_B.In1.angle_min) /
            SUB_DWA_B.In1.angle_increment);
          SUB_DWA_B.y.set_size(1, SUB_DWA_B.nm1d2 + 1);
          for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
            SUB_DWA_B.y[SUB_DWA_B.n] = static_cast<real32_T>
              (SUB_DWA_B.In1.angle_increment * static_cast<real_T>(SUB_DWA_B.n)
               + SUB_DWA_B.In1.angle_min);
          }
        } else {
          if (SUB_DWA_B.In1.angle_max < 0.0F) {
            SUB_DWA_B.b1 = static_cast<real32_T>(ceil(static_cast<real_T>
              (SUB_DWA_B.In1.angle_max)));
          } else {
            SUB_DWA_B.b1 = static_cast<real32_T>(floor(static_cast<real_T>
              (SUB_DWA_B.In1.angle_max)));
          }

          SUB_DWA_B.n = div_s32(static_cast<int32_T>(SUB_DWA_B.b1) -
                                static_cast<int32_T>(SUB_DWA_B.In1.angle_min),
                                static_cast<int32_T>
                                (SUB_DWA_B.In1.angle_increment));
          SUB_DWA_B.y.set_size(1, SUB_DWA_B.y.size(1));
          if (SUB_DWA_B.In1.angle_max < 0.0F) {
            SUB_DWA_B.b1 = static_cast<real32_T>(ceil(static_cast<real_T>
              (SUB_DWA_B.In1.angle_max)));
          } else {
            SUB_DWA_B.b1 = static_cast<real32_T>(floor(static_cast<real_T>
              (SUB_DWA_B.In1.angle_max)));
          }

          SUB_DWA_B.y.set_size(SUB_DWA_B.y.size(0), div_s32(static_cast<int32_T>
            (SUB_DWA_B.b1) - static_cast<int32_T>(SUB_DWA_B.In1.angle_min),
            static_cast<int32_T>(SUB_DWA_B.In1.angle_increment)) + 1);
          for (SUB_DWA_B.k = 0; SUB_DWA_B.k <= SUB_DWA_B.n; SUB_DWA_B.k++) {
            SUB_DWA_B.y[SUB_DWA_B.k] = static_cast<real32_T>(SUB_DWA_B.k *
              static_cast<int32_T>(SUB_DWA_B.In1.angle_increment) +
              static_cast<int32_T>(SUB_DWA_B.In1.angle_min));
          }
        }
      } else {
        SUB_DWA_B.ndbl = floor((static_cast<real_T>(SUB_DWA_B.In1.angle_max) -
          SUB_DWA_B.In1.angle_min) / SUB_DWA_B.In1.angle_increment + 0.5);
        SUB_DWA_B.apnd = SUB_DWA_B.ndbl * SUB_DWA_B.In1.angle_increment +
          SUB_DWA_B.In1.angle_min;
        if (SUB_DWA_B.In1.angle_increment > 0.0F) {
          SUB_DWA_B.cdiff = SUB_DWA_B.apnd - SUB_DWA_B.In1.angle_max;
        } else {
          SUB_DWA_B.cdiff = SUB_DWA_B.In1.angle_max - SUB_DWA_B.apnd;
        }

        SUB_DWA_B.s_end = fabs(static_cast<real_T>(SUB_DWA_B.In1.angle_min));
        SUB_DWA_B.u1 = fabs(static_cast<real_T>(SUB_DWA_B.In1.angle_max));
        if (SUB_DWA_B.s_end >= SUB_DWA_B.u1) {
          SUB_DWA_B.u1 = SUB_DWA_B.s_end;
        }

        if (fabs(SUB_DWA_B.cdiff) < 2.384185791015625E-7 * SUB_DWA_B.u1) {
          SUB_DWA_B.ndbl++;
          SUB_DWA_B.b1 = SUB_DWA_B.In1.angle_max;
        } else if (SUB_DWA_B.cdiff > 0.0) {
          SUB_DWA_B.b1 = static_cast<real32_T>((SUB_DWA_B.ndbl - 1.0) *
            SUB_DWA_B.In1.angle_increment + SUB_DWA_B.In1.angle_min);
        } else {
          SUB_DWA_B.ndbl++;
          SUB_DWA_B.b1 = static_cast<real32_T>(SUB_DWA_B.apnd);
        }

        if (SUB_DWA_B.ndbl >= 0.0) {
          SUB_DWA_B.b_n = static_cast<int32_T>(SUB_DWA_B.ndbl) - 1;
        } else {
          SUB_DWA_B.b_n = -1;
        }

        SUB_DWA_B.y.set_size(1, SUB_DWA_B.b_n + 1);
        if (SUB_DWA_B.b_n + 1 > 0) {
          SUB_DWA_B.y[0] = SUB_DWA_B.In1.angle_min;
          if (SUB_DWA_B.b_n + 1 > 1) {
            SUB_DWA_B.y[SUB_DWA_B.b_n] = SUB_DWA_B.b1;
            SUB_DWA_B.nm1d2 = SUB_DWA_B.b_n / 2;
            for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k <= SUB_DWA_B.nm1d2 - 2;
                 SUB_DWA_B.b_k++) {
              SUB_DWA_B.kd = static_cast<real32_T>(SUB_DWA_B.b_k + 1) *
                SUB_DWA_B.In1.angle_increment;
              SUB_DWA_B.y[SUB_DWA_B.b_k + 1] = SUB_DWA_B.In1.angle_min +
                SUB_DWA_B.kd;
              SUB_DWA_B.y[(SUB_DWA_B.b_n - SUB_DWA_B.b_k) - 1] = SUB_DWA_B.b1 -
                SUB_DWA_B.kd;
            }

            if (SUB_DWA_B.nm1d2 << 1 == SUB_DWA_B.b_n) {
              SUB_DWA_B.y[SUB_DWA_B.nm1d2] = (SUB_DWA_B.In1.angle_min +
                SUB_DWA_B.b1) / 2.0F;
            } else {
              SUB_DWA_B.kd = static_cast<real32_T>(SUB_DWA_B.nm1d2) *
                SUB_DWA_B.In1.angle_increment;
              SUB_DWA_B.y[SUB_DWA_B.nm1d2] = SUB_DWA_B.In1.angle_min +
                SUB_DWA_B.kd;
              SUB_DWA_B.y[SUB_DWA_B.nm1d2 + 1] = SUB_DWA_B.b1 - SUB_DWA_B.kd;
            }
          }
        }
      }
    }
  }

  SUB_DWA_DW.SFunction_DIMS3 = SUB_DWA_B.y.size(1);
  SUB_DWA_B.nm1d2 = SUB_DWA_B.y.size(1);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
    SUB_DWA_B.tmp_data[SUB_DWA_B.n] = SUB_DWA_B.y[SUB_DWA_B.n] -
      SUB_DWA_B.In1.angle_min;
  }

  // MATLAB Function: '<S30>/MATLAB Function3' incorporates:
  //   Constant: '<S22>/LiDAR offset to middle of robot'
  //   MATLAB Function: '<S3>/read scan'

  for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k < 720; SUB_DWA_B.b_k++) {
    // MATLAB Function: '<S3>/read scan'
    SUB_DWA_B.kd = SUB_DWA_B.In1.ranges[SUB_DWA_B.b_k];
    SUB_DWA_B.b1 = SUB_DWA_B.tmp_data[SUB_DWA_B.b_k];
    SUB_DWA_B.ndbl = SUB_DWA_B.kd * static_cast<real32_T>(cos(static_cast<real_T>
      (SUB_DWA_B.b1))) + 0.075F;
    SUB_DWA_B.x_o[SUB_DWA_B.b_k] = SUB_DWA_B.ndbl;
    SUB_DWA_B.apnd = SUB_DWA_B.kd * static_cast<real32_T>(sin(static_cast<real_T>
      (SUB_DWA_B.b1)));
    SUB_DWA_B.y_o[SUB_DWA_B.b_k] = SUB_DWA_B.apnd;
    SUB_DWA_B.ranges[SUB_DWA_B.b_k] = sqrt(SUB_DWA_B.ndbl * SUB_DWA_B.ndbl +
      SUB_DWA_B.apnd * SUB_DWA_B.apnd);
  }

  // MATLABSystem: '<S5>/SourceBlock'
  pitch_ctrl_mode = Sub_SUB_DWA_2634.getLatestMessage(&SUB_DWA_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S37>/Enable'

  // Start for MATLABSystem: '<S5>/SourceBlock'
  if (pitch_ctrl_mode) {
    // SignalConversion generated from: '<S37>/In1'
    SUB_DWA_B.In1_g = SUB_DWA_B.b_varargout_2_b;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // MATLABSystem: '<S6>/SourceBlock'
  pitch_ctrl_mode = Sub_SUB_DWA_2651.getLatestMessage(&SUB_DWA_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S38>/Enable'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (pitch_ctrl_mode) {
    // SignalConversion generated from: '<S38>/In1'
    SUB_DWA_B.In1_aj = SUB_DWA_B.b_varargout_2_b;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // MATLABSystem: '<S7>/SourceBlock'
  pitch_ctrl_mode = Sub_SUB_DWA_2652.getLatestMessage(&SUB_DWA_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S39>/Enable'

  // Start for MATLABSystem: '<S7>/SourceBlock'
  if (pitch_ctrl_mode) {
    // SignalConversion generated from: '<S39>/In1'
    SUB_DWA_B.In1_d = SUB_DWA_B.b_varargout_2_b;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

  // MATLAB Function: '<S22>/Read Ultrasonic Data' incorporates:
  //   MATLAB Function: '<S30>/MATLAB Function3'
  //   MATLAB Function: '<S4>/Parameter defination'
  //   Reshape: '<S10>/Reshape1'

  SUB_DWA_B.ndbl = SUB_DWA_B.In1_g.range;
  SUB_DWA_B.apnd = SUB_DWA_B.In1_aj.range;
  SUB_DWA_B.cdiff = SUB_DWA_B.In1_d.range;
  SUB_DWA_B.x_obj_ultrasonic.set_size(0, 1);
  SUB_DWA_B.y_obj_ultrasonic.set_size(0, 1);
  if ((!rtIsNaN(static_cast<real_T>(SUB_DWA_B.In1_g.range))) &&
      (SUB_DWA_B.In1_g.range >= 0.1) && (SUB_DWA_B.In1_g.range <= 0.5F)) {
    SUB_DWA_B.ndbl = SUB_DWA_B.In1_g.range + 0.22;
    SUB_DWA_eml_float_colon(-(SUB_DWA_B.In1_g.range + 0.22) *
      0.13165249758739583, (SUB_DWA_B.In1_g.range + 0.22) * 0.00872686779075879,
      (SUB_DWA_B.In1_g.range + 0.22) * 0.13165249758739583, SUB_DWA_B.y_front);
    SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.y_front.size(1));
    SUB_DWA_B.nm1d2 = SUB_DWA_B.y_front.size(1);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] = SUB_DWA_B.y_front[SUB_DWA_B.n];
    }

    SUB_DWA_B.y_obj_ultrasonic.set_size(SUB_DWA_B.y_obj_ultrasonic_m.size(0), 1);
    SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic_m.size(0);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic[SUB_DWA_B.n] =
        SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n];
    }

    SUB_DWA_B.b_n = SUB_DWA_B.y_front.size(1);
    SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.y_front.size(1));
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_n; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] = SUB_DWA_B.In1_g.range + 0.22;
    }

    SUB_DWA_B.x_obj_ultrasonic.set_size(SUB_DWA_B.y_obj_ultrasonic_m.size(0), 1);
    SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic_m.size(0);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.x_obj_ultrasonic[SUB_DWA_B.n] =
        SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n];
    }
  }

  if ((!rtIsNaN(static_cast<real_T>(SUB_DWA_B.In1_aj.range))) &&
      (SUB_DWA_B.In1_aj.range >= 0.1) && (SUB_DWA_B.In1_aj.range <= 0.5F)) {
    SUB_DWA_B.apnd = SUB_DWA_B.In1_aj.range + 0.074;
    SUB_DWA_eml_float_colon(-(SUB_DWA_B.In1_aj.range + 0.074) *
      0.13165249758739583 + 0.074, (SUB_DWA_B.In1_aj.range + 0.074) *
      0.00872686779075879, (SUB_DWA_B.In1_aj.range + 0.074) *
      0.13165249758739583 + 0.074, SUB_DWA_B.y_front);
    SUB_DWA_B.b_k = SUB_DWA_B.x_obj_ultrasonic.size(0);
    SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.b_k + SUB_DWA_B.y_front.size
      (1));
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] =
        SUB_DWA_B.x_obj_ultrasonic[SUB_DWA_B.n];
    }

    SUB_DWA_B.nm1d2 = SUB_DWA_B.y_front.size(1);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n + SUB_DWA_B.b_k] =
        SUB_DWA_B.y_front[SUB_DWA_B.n];
    }

    SUB_DWA_B.x_obj_ultrasonic.set_size(SUB_DWA_B.y_obj_ultrasonic_m.size(0), 1);
    SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic_m.size(0);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.x_obj_ultrasonic[SUB_DWA_B.n] =
        SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n];
    }

    SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic.size(0);
    SUB_DWA_B.b_n = SUB_DWA_B.y_front.size(1);
    SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.b_k + SUB_DWA_B.y_front.size
      (1));
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] =
        SUB_DWA_B.y_obj_ultrasonic[SUB_DWA_B.n];
    }

    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_n; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n + SUB_DWA_B.b_k] =
        SUB_DWA_B.In1_aj.range + 0.074;
    }

    SUB_DWA_B.y_obj_ultrasonic.set_size(SUB_DWA_B.y_obj_ultrasonic_m.size(0), 1);
    SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic_m.size(0);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic[SUB_DWA_B.n] =
        SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n];
    }
  }

  if ((!rtIsNaN(static_cast<real_T>(SUB_DWA_B.In1_d.range))) &&
      (SUB_DWA_B.In1_d.range >= 0.1) && (SUB_DWA_B.In1_d.range <= 0.5F)) {
    SUB_DWA_B.cdiff = SUB_DWA_B.In1_d.range + 0.074;
    SUB_DWA_eml_float_colon(-(SUB_DWA_B.In1_d.range + 0.074) *
      0.13165249758739583 + 0.074, (SUB_DWA_B.In1_d.range + 0.074) *
      0.00872686779075879, (SUB_DWA_B.In1_d.range + 0.074) * 0.13165249758739583
      + 0.074, SUB_DWA_B.y_front);
    SUB_DWA_B.b_k = SUB_DWA_B.x_obj_ultrasonic.size(0);
    SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.b_k + SUB_DWA_B.y_front.size
      (1));
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] =
        SUB_DWA_B.x_obj_ultrasonic[SUB_DWA_B.n];
    }

    SUB_DWA_B.nm1d2 = SUB_DWA_B.y_front.size(1);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n + SUB_DWA_B.b_k] =
        SUB_DWA_B.y_front[SUB_DWA_B.n];
    }

    SUB_DWA_B.x_obj_ultrasonic.set_size(SUB_DWA_B.y_obj_ultrasonic_m.size(0), 1);
    SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic_m.size(0);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.x_obj_ultrasonic[SUB_DWA_B.n] =
        SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n];
    }

    SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic.size(0);
    SUB_DWA_B.b_n = SUB_DWA_B.y_front.size(1);
    SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.b_k + SUB_DWA_B.y_front.size
      (1));
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] =
        SUB_DWA_B.y_obj_ultrasonic[SUB_DWA_B.n];
    }

    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_n; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n + SUB_DWA_B.b_k] =
        -(SUB_DWA_B.In1_d.range + 0.074);
    }

    SUB_DWA_B.y_obj_ultrasonic.set_size(SUB_DWA_B.y_obj_ultrasonic_m.size(0), 1);
    SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic_m.size(0);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic[SUB_DWA_B.n] =
        SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n];
    }
  }

  if (SUB_DWA_B.x_obj_ultrasonic.size(0) == 0) {
    SUB_DWA_B.x_obj_ultrasonic.set_size(1, 1);
    SUB_DWA_B.x_obj_ultrasonic[0] = (rtNaN);
  }

  if (SUB_DWA_B.y_obj_ultrasonic.size(0) == 0) {
    SUB_DWA_B.y_obj_ultrasonic.set_size(1, 1);
    SUB_DWA_B.y_obj_ultrasonic[0] = (rtNaN);
  }

  SUB_DWA_B.r2.set_size(3, 1);
  SUB_DWA_B.r2[0] = SUB_DWA_B.ndbl;
  SUB_DWA_B.r2[1] = SUB_DWA_B.apnd;
  SUB_DWA_B.r2[2] = SUB_DWA_B.cdiff;
  SUB_DWA_B.x_obj.set_size(3, 1);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < 3; SUB_DWA_B.n++) {
    SUB_DWA_B.x_obj[SUB_DWA_B.n] = SUB_DWA_B.r2[SUB_DWA_B.n];
  }

  // End of MATLAB Function: '<S22>/Read Ultrasonic Data'

  // MATLAB Function: '<S22>/MATLAB Function1'
  SUB_DWA_B.b_k = SUB_DWA_B.x_obj.size(0);
  SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.b_k + 720);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < 720; SUB_DWA_B.n++) {
    SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] = SUB_DWA_B.ranges[SUB_DWA_B.n];
  }

  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
    SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n + 720] =
      SUB_DWA_B.x_obj[SUB_DWA_B.n];
  }

  SUB_DWA_B.Sensor_ranges.set_size(SUB_DWA_B.y_obj_ultrasonic_m.size(0), 1);
  SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic_m.size(0);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
    SUB_DWA_B.Sensor_ranges[SUB_DWA_B.n] =
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n];
  }

  // End of MATLAB Function: '<S22>/MATLAB Function1'

  // MATLAB Function: '<S22>/MATLAB Function'
  SUB_DWA_B.b_k = SUB_DWA_B.x_obj_ultrasonic.size(0);
  SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.b_k + 720);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < 720; SUB_DWA_B.n++) {
    SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] = SUB_DWA_B.x_o[SUB_DWA_B.n];
  }

  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
    SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n + 720] =
      SUB_DWA_B.x_obj_ultrasonic[SUB_DWA_B.n];
  }

  SUB_DWA_B.x_obj.set_size(SUB_DWA_B.y_obj_ultrasonic_m.size(0), 1);
  SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic_m.size(0);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
    SUB_DWA_B.x_obj[SUB_DWA_B.n] = SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n];
  }

  SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic.size(0);
  SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.b_k + 720);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < 720; SUB_DWA_B.n++) {
    SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] = SUB_DWA_B.y_o[SUB_DWA_B.n];
  }

  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
    SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n + 720] =
      SUB_DWA_B.y_obj_ultrasonic[SUB_DWA_B.n];
  }

  SUB_DWA_B.y_obj.set_size(SUB_DWA_B.y_obj_ultrasonic_m.size(0), 1);
  SUB_DWA_B.b_k = SUB_DWA_B.y_obj_ultrasonic_m.size(0);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
    SUB_DWA_B.y_obj[SUB_DWA_B.n] = SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n];
  }

  // End of MATLAB Function: '<S22>/MATLAB Function'

  // MATLAB Function: '<S22>/Scan Grid Generation' incorporates:
  //   MATLAB Function: '<S4>/Parameter defination'

  SUB_DWA_B.x_grid[80] = 2.0;
  SUB_DWA_B.x_grid[0] = -2.0;
  for (SUB_DWA_B.k = 0; SUB_DWA_B.k < 79; SUB_DWA_B.k++) {
    SUB_DWA_B.x_grid[SUB_DWA_B.k + 1] = ((static_cast<real_T>(SUB_DWA_B.k) + 2.0)
      * 2.0 - 82.0) * 0.025;
  }

  SUB_DWA_B.x_grid[40] = 0.0;
  for (SUB_DWA_B.j = 0; SUB_DWA_B.j < 81; SUB_DWA_B.j++) {
    memcpy(&SUB_DWA_B.x_possible[SUB_DWA_B.j * 81], &SUB_DWA_B.x_grid[0], 81U *
           sizeof(real_T));
    for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k < 81; SUB_DWA_B.b_k++) {
      SUB_DWA_B.b_n = 81 * SUB_DWA_B.j + SUB_DWA_B.b_k;
      SUB_DWA_B.y_possible[SUB_DWA_B.b_n] = SUB_DWA_B.x_grid[SUB_DWA_B.j];
    }
  }

  for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k < 6561; SUB_DWA_B.b_k++) {
    SUB_DWA_B.x_possible[SUB_DWA_B.b_k] = -SUB_DWA_B.x_possible[SUB_DWA_B.b_k];
    SUB_DWA_B.y_possible[SUB_DWA_B.b_k] = -SUB_DWA_B.y_possible[SUB_DWA_B.b_k];

    // MATLAB Function: '<S22>/Potential Feld LiDAR'
    SUB_DWA_B.U_rep_sum[SUB_DWA_B.b_k] = 0.0;
  }

  // End of MATLAB Function: '<S22>/Scan Grid Generation'

  // MATLAB Function: '<S22>/Potential Feld LiDAR' incorporates:
  //   MATLAB Function: '<S4>/Parameter defination'

  SUB_DWA_B.b_n = SUB_DWA_B.x_obj.size(0);
  for (SUB_DWA_B.k = 0; SUB_DWA_B.k < SUB_DWA_B.b_n; SUB_DWA_B.k++) {
    SUB_DWA_B.s_end = SUB_DWA_B.x_obj[SUB_DWA_B.k];
    SUB_DWA_B.ndbl = SUB_DWA_B.y_obj[SUB_DWA_B.k];
    for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k < 6561; SUB_DWA_B.b_k++) {
      SUB_DWA_B.apnd = SUB_DWA_B.x_possible[SUB_DWA_B.b_k] - SUB_DWA_B.s_end;
      SUB_DWA_B.cdiff = SUB_DWA_B.apnd * SUB_DWA_B.apnd;
      SUB_DWA_B.apnd = SUB_DWA_B.y_possible[SUB_DWA_B.b_k] - SUB_DWA_B.ndbl;
      SUB_DWA_B.cdiff = sqrt(SUB_DWA_B.apnd * SUB_DWA_B.apnd + SUB_DWA_B.cdiff);
      if (SUB_DWA_B.cdiff < 0.01) {
        SUB_DWA_B.cdiff = 0.01;
      }

      SUB_DWA_B.cdiff = 1.0 / SUB_DWA_B.cdiff - 3.3333333333333335;
      if (!(SUB_DWA_B.cdiff >= 0.0)) {
        SUB_DWA_B.cdiff = 0.0;
      }

      SUB_DWA_B.U_rep_sum[SUB_DWA_B.b_k] += SUB_DWA_B.cdiff * SUB_DWA_B.cdiff;
    }
  }

  SUB_DWA_B.n = SUB_DWA_B.x_obj.size(0);
  for (SUB_DWA_B.i = 0; SUB_DWA_B.i < 6561; SUB_DWA_B.i++) {
    SUB_DWA_B.U_rep_sum[SUB_DWA_B.i] /= static_cast<real_T>(SUB_DWA_B.n);
  }

  // MATLAB Function: '<S20>/Kernel'
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < 9; SUB_DWA_B.n++) {
    SUB_DWA_B.K[SUB_DWA_B.n] = b[SUB_DWA_B.n] / 4.8976404035363039;
  }

  // End of MATLAB Function: '<S20>/Kernel'

  // MATLAB Function: '<S20>/2D Conv'
  for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k < 83; SUB_DWA_B.b_k++) {
    SUB_DWA_B.U_padded[SUB_DWA_B.b_k] = 0.0;
    SUB_DWA_B.U_padded[SUB_DWA_B.b_k + 6806] = 0.0;
  }

  for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k < 81; SUB_DWA_B.b_k++) {
    SUB_DWA_B.b_n = (SUB_DWA_B.b_k + 1) * 83;
    SUB_DWA_B.U_padded[SUB_DWA_B.b_n] = 0.0;
    SUB_DWA_B.U_padded[SUB_DWA_B.b_n + 82] = 0.0;
    memcpy(&SUB_DWA_B.U_padded[SUB_DWA_B.b_n + 1],
           &SUB_DWA_B.U_rep_sum[SUB_DWA_B.b_k * 81], 81U * sizeof(real_T));
  }

  for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k < 81; SUB_DWA_B.b_k++) {
    for (SUB_DWA_B.j = 0; SUB_DWA_B.j < 81; SUB_DWA_B.j++) {
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < 3; SUB_DWA_B.n++) {
        for (SUB_DWA_B.i = 0; SUB_DWA_B.i < 3; SUB_DWA_B.i++) {
          SUB_DWA_B.b_n = 3 * SUB_DWA_B.n + SUB_DWA_B.i;
          SUB_DWA_B.x[SUB_DWA_B.b_n] = SUB_DWA_B.U_padded[((SUB_DWA_B.j +
            SUB_DWA_B.n) * 83 + SUB_DWA_B.b_k) + SUB_DWA_B.i] *
            SUB_DWA_B.K[SUB_DWA_B.b_n];
        }
      }

      for (SUB_DWA_B.b_n = 0; SUB_DWA_B.b_n < 3; SUB_DWA_B.b_n++) {
        SUB_DWA_B.nm1d2 = SUB_DWA_B.b_n * 3;
        SUB_DWA_B.ultrasonic_ranges[SUB_DWA_B.b_n] =
          (SUB_DWA_B.x[SUB_DWA_B.nm1d2 + 1] + SUB_DWA_B.x[SUB_DWA_B.nm1d2]) +
          SUB_DWA_B.x[SUB_DWA_B.nm1d2 + 2];
      }

      SUB_DWA_B.y_possible[SUB_DWA_B.b_k + 81 * SUB_DWA_B.j] =
        (SUB_DWA_B.ultrasonic_ranges[0] + SUB_DWA_B.ultrasonic_ranges[1]) +
        SUB_DWA_B.ultrasonic_ranges[2];
    }
  }

  // End of MATLAB Function: '<S20>/2D Conv'

  // MATLAB Function: '<S4>/Behavior Switcher' incorporates:
  //   DataStoreRead: '<S4>/Data Store Read6'
  //   DataStoreRead: '<S4>/Data Store Read7'
  //   DataStoreWrite: '<S4>/Data Store Write11'
  //   DataStoreWrite: '<S4>/Data Store Write13'
  //   DataStoreWrite: '<S4>/Data Store Write8'
  //   DataStoreWrite: '<S4>/Data Store Write9'
  //   MATLAB Function: '<S9>/vw_calculator'

  SUB_DWA_B.ndbl = SUB_DWA_DW.value[0];
  SUB_DWA_B.apnd = SUB_DWA_DW.value[1];
  SUB_DWA_B.cdiff = SUB_DWA_DW.value[2];
  pitch_ctrl_mode = SUB_DWA_DW.mode[1];
  roll_ctrl_mode = SUB_DWA_DW.mode[2];
  height_ctrl_mode = SUB_DWA_DW.mode[3];
  SUB_DWA_DW.mode[0] = false;
  if ((SUB_DWA_B.In1_a.buttons[4] == 1) && (SUB_DWA_DW.prevButtons[4] == 0)) {
    SUB_DWA_DW.behaviorSwitch--;
  } else if ((SUB_DWA_B.In1_a.buttons[5] == 1) && (SUB_DWA_DW.prevButtons[5] ==
              0)) {
    SUB_DWA_DW.behaviorSwitch++;
  }

  if ((SUB_DWA_DW.behaviorSwitch >= 2.0) || rtIsNaN(SUB_DWA_DW.behaviorSwitch))
  {
    SUB_DWA_DW.behaviorSwitch = 2.0;
  }

  if (SUB_DWA_DW.behaviorSwitch <= 1.0) {
    SUB_DWA_DW.behaviorSwitch = 1.0;
  }

  if (SUB_DWA_DW.behaviorSwitch != 2.0) {
    SUB_DWA_DW.time_counter = 0.0;
    SUB_DWA_DW.WanderVelocity = 0.0;
  } else {
    SUB_DWA_DW.time_counter++;
    if (SUB_DWA_DW.time_counter >= 600.0) {
      SUB_DWA_DW.behaviorSwitch = 1.0;
    }

    if ((SUB_DWA_B.In1_a.axes[7] > 0.9) && (SUB_DWA_DW.prevAxes[7] < 0.1) &&
        (SUB_DWA_DW.prevAxes[7] > -0.1)) {
      SUB_DWA_DW.WanderVelocity += 0.1;
    } else if ((SUB_DWA_B.In1_a.axes[7] < -0.9) && (SUB_DWA_DW.prevAxes[7] < 0.1)
               && (SUB_DWA_DW.prevAxes[7] > -0.1)) {
      SUB_DWA_DW.WanderVelocity -= 0.1;
    }

    if ((SUB_DWA_DW.WanderVelocity >= 1.0) || rtIsNaN(SUB_DWA_DW.WanderVelocity))
    {
      SUB_DWA_DW.WanderVelocity = 1.0;
    }

    if (SUB_DWA_DW.WanderVelocity <= 0.0) {
      SUB_DWA_DW.WanderVelocity = 0.0;
    }
  }

  if ((SUB_DWA_B.In1_a.buttons[10] == 1) && (SUB_DWA_DW.prevButtons[10] == 0)) {
    SUB_DWA_DW.mode[0] = true;
    pitch_ctrl_mode = true;
    roll_ctrl_mode = true;
  } else if ((SUB_DWA_B.In1_a.buttons[10] == 0) && (SUB_DWA_DW.prevButtons[10] ==
              1)) {
    SUB_DWA_DW.mode[0] = true;
    pitch_ctrl_mode = false;
    roll_ctrl_mode = false;
  } else if ((SUB_DWA_B.In1_a.buttons[11] == 1) && (SUB_DWA_DW.prevButtons[11] ==
              0)) {
    SUB_DWA_DW.mode[0] = true;
    height_ctrl_mode = true;
  } else if ((SUB_DWA_B.In1_a.buttons[11] == 0) && (SUB_DWA_DW.prevButtons[11] ==
              1)) {
    SUB_DWA_DW.mode[0] = true;
    height_ctrl_mode = false;
  } else if ((SUB_DWA_B.In1_a.buttons[2] == 1) && (SUB_DWA_DW.prevButtons[2] ==
              0)) {
    SUB_DWA_DW.mode[0] = true;
    SUB_DWA_DW.mode[4] = true;
  } else if ((SUB_DWA_B.In1_a.buttons[3] == 1) && (SUB_DWA_DW.prevButtons[3] ==
              0)) {
    SUB_DWA_DW.mode[0] = true;
    SUB_DWA_DW.mode[4] = false;
  } else if ((SUB_DWA_B.In1_a.buttons[10] == 1) && (SUB_DWA_DW.prevButtons[10] ==
              0) && (SUB_DWA_B.In1_a.buttons[11] == 1) &&
             (SUB_DWA_DW.prevButtons[11] == 0)) {
    SUB_DWA_DW.mode[0] = true;
    SUB_DWA_B.cdiff = 0.0;
    SUB_DWA_B.apnd = 0.0;
    pitch_ctrl_mode = false;
    roll_ctrl_mode = false;
  }

  if (pitch_ctrl_mode) {
    if ((SUB_DWA_B.In1_a.axes[5] >= 1.0F) || rtIsNaNF(SUB_DWA_B.In1_a.axes[5]))
    {
      SUB_DWA_B.b1 = 1.0F;
    } else {
      SUB_DWA_B.b1 = SUB_DWA_B.In1_a.axes[5];
    }

    if (SUB_DWA_B.b1 <= -1.0F) {
      SUB_DWA_B.cdiff = -1.0;
    } else {
      SUB_DWA_B.cdiff = SUB_DWA_B.b1;
    }
  }

  if (roll_ctrl_mode) {
    if ((SUB_DWA_B.In1_a.axes[2] >= 1.0F) || rtIsNaNF(SUB_DWA_B.In1_a.axes[2]))
    {
      SUB_DWA_B.b1 = 1.0F;
    } else {
      SUB_DWA_B.b1 = SUB_DWA_B.In1_a.axes[2];
    }

    if (SUB_DWA_B.b1 <= -1.0F) {
      SUB_DWA_B.b1 = -1.0F;
    }

    SUB_DWA_B.apnd = -static_cast<real_T>(SUB_DWA_B.b1) / 10.0;
  }

  if (height_ctrl_mode) {
    if ((SUB_DWA_B.In1_a.axes[6] > 0.9) && (SUB_DWA_DW.prevAxes[6] < 0.1) &&
        (SUB_DWA_DW.prevAxes[6] > -0.1)) {
      SUB_DWA_B.ndbl = SUB_DWA_DW.value[0] - 0.1;
    } else if ((SUB_DWA_B.In1_a.axes[6] < -0.9) && (SUB_DWA_DW.prevAxes[6] < 0.1)
               && (SUB_DWA_DW.prevAxes[6] > -0.1)) {
      SUB_DWA_B.ndbl = SUB_DWA_DW.value[0] + 0.1;
    }

    if ((SUB_DWA_B.ndbl >= 1.0) || rtIsNaN(SUB_DWA_B.ndbl)) {
      SUB_DWA_B.ndbl = 1.0;
    }

    if (SUB_DWA_B.ndbl <= -0.1) {
      SUB_DWA_B.ndbl = -0.1;
    }
  }

  memcpy(&SUB_DWA_DW.prevButtons[0], &SUB_DWA_B.In1_a.buttons[0], sizeof(int32_T)
         << 7U);
  memcpy(&SUB_DWA_DW.prevAxes[0], &SUB_DWA_B.In1_a.axes[0], sizeof(real32_T) <<
         7U);
  SUB_DWA_DW.value[0] = SUB_DWA_B.ndbl;
  SUB_DWA_DW.value[1] = SUB_DWA_B.apnd;
  SUB_DWA_DW.value[2] = SUB_DWA_B.cdiff;
  SUB_DWA_DW.mode[1] = pitch_ctrl_mode;
  SUB_DWA_DW.mode[2] = roll_ctrl_mode;
  SUB_DWA_DW.mode[3] = height_ctrl_mode;

  // Switch: '<S4>/Subsume4' incorporates:
  //   DataStoreRead: '<S4>/Data Store Read1'
  //   MATLAB Function: '<S4>/Behavior Switcher'
  //   MATLAB Function: '<S9>/vw_calculator'
  //   Reshape: '<S11>/Reshape'

  if (SUB_DWA_DW.StateWander > 0.0) {
    SUB_DWA_B.ndbl = SUB_DWA_DW.WanderVelocity;
    SUB_DWA_B.apnd = 0.0;
  } else {
    // MATLAB Function: '<S9>/vw_calculator' incorporates:
    //   Reshape: '<S11>/Reshape'

    SUB_DWA_B.ndbl = ((-(SUB_DWA_B.In1_a.axes[4] + 1.0F) / 2.0F +
                       (SUB_DWA_B.In1_a.axes[3] + 1.0F) / 2.0F) +
                      SUB_DWA_B.In1_a.axes[1]) + static_cast<real32_T>
      (SUB_DWA_B.In1_l.linear.x);
    if (!(SUB_DWA_B.ndbl <= 1.0)) {
      SUB_DWA_B.ndbl = 1.0;
    }

    if (!(SUB_DWA_B.ndbl >= -1.0)) {
      SUB_DWA_B.ndbl = -1.0;
    }

    SUB_DWA_B.apnd = (SUB_DWA_B.In1_a.axes[0] + static_cast<real32_T>
                      (SUB_DWA_B.In1_l.angular.z)) / 0.6;
  }

  // End of Switch: '<S4>/Subsume4'

  // MATLAB Function: '<S23>/MATLAB Function' incorporates:
  //   DataStoreRead: '<S23>/Data Store Read14'
  //   MATLAB Function: '<S4>/Parameter defination'
  //   Switch: '<S4>/Subsume4'

  SUB_DWA_B.s_end = fabs(SUB_DWA_DW.vel_last[0]);
  if ((SUB_DWA_B.s_end >= 0.8) && (fabs(SUB_DWA_DW.vel_last[1]) >=
       1.3333333333333335)) {
    SUB_DWA_B.b_n = 6;
  } else if ((SUB_DWA_B.s_end >= 0.5) && (fabs(SUB_DWA_DW.vel_last[1]) >=
              0.83333333333333337)) {
    SUB_DWA_B.b_n = 3;
  } else if (SUB_DWA_B.s_end >= 0.8) {
    SUB_DWA_B.b_n = 5;
  } else if (SUB_DWA_B.s_end >= 0.5) {
    SUB_DWA_B.b_n = 2;
  } else {
    SUB_DWA_B.b_n = 1;
  }

  if (SUB_DWA_DW.vel_last[0] - 0.1 <= 1.0) {
    SUB_DWA_B.cdiff = SUB_DWA_DW.vel_last[0] - 0.1;
  } else {
    SUB_DWA_B.cdiff = 1.0;
  }

  if (SUB_DWA_DW.vel_last[0] + 0.1 <= 1.0) {
    SUB_DWA_B.u1 = SUB_DWA_DW.vel_last[0] + 0.1;
  } else {
    SUB_DWA_B.u1 = 1.0;
  }

  if (SUB_DWA_DW.vel_last[1] - 0.4 <= 1.6666666666666667) {
    SUB_DWA_B.y_c = SUB_DWA_DW.vel_last[1] - 0.4;
  } else {
    SUB_DWA_B.y_c = 1.6666666666666667;
  }

  if (SUB_DWA_DW.vel_last[1] + 0.4 <= 1.6666666666666667) {
    SUB_DWA_B.s_end = SUB_DWA_DW.vel_last[1] + 0.4;
  } else {
    SUB_DWA_B.s_end = 1.6666666666666667;
  }

  if (!(SUB_DWA_B.cdiff >= -1.0)) {
    SUB_DWA_B.cdiff = -1.0;
  }

  if (!(SUB_DWA_B.u1 >= -1.0)) {
    SUB_DWA_B.u1 = -1.0;
  }

  if (!(SUB_DWA_B.y_c >= -1.6666666666666667)) {
    SUB_DWA_B.y_c = -1.6666666666666667;
  }

  if (!(SUB_DWA_B.s_end >= -1.6666666666666667)) {
    SUB_DWA_B.s_end = -1.6666666666666667;
  }

  SUB_DWA_linspace(SUB_DWA_B.cdiff, SUB_DWA_B.u1, SUB_DWA_B.dv);
  SUB_DWA_linspace(SUB_DWA_B.y_c, SUB_DWA_B.s_end, SUB_DWA_B.dv1);
  SUB_DWA_meshgrid(SUB_DWA_B.dv, SUB_DWA_B.dv1, SUB_DWA_B.V,
                   SUB_DWA_B.U_Trajectories);
  SUB_DWA_B.s_end = SUB_DWA_sum_c(SUB_DWA_B.rtb_param_weight);
  SUB_DWA_B.cdiff = 1.0 / SUB_DWA_B.s_end;
  SUB_DWA_B.u1 = 16.0 / SUB_DWA_B.s_end;
  SUB_DWA_B.y_c = 2.0 / SUB_DWA_B.s_end;
  for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k < 2601; SUB_DWA_B.b_k++) {
    SUB_DWA_B.vw_possiables_f = SUB_DWA_B.V[SUB_DWA_B.b_k];
    SUB_DWA_B.vw_possiables[SUB_DWA_B.b_k] = SUB_DWA_B.vw_possiables_f;
    SUB_DWA_B.R_cur = SUB_DWA_B.U_Trajectories[SUB_DWA_B.b_k];
    SUB_DWA_B.vw_possiables[SUB_DWA_B.b_k + 2601] = SUB_DWA_B.R_cur;
    SUB_DWA_B.U_Trajectories[SUB_DWA_B.b_k] = 0.0;
    SUB_DWA_B.s_end = fabs(SUB_DWA_B.vw_possiables_f);
    if ((SUB_DWA_B.s_end < 0.01) && (fabs(SUB_DWA_B.R_cur) < 0.1)) {
      SUB_DWA_B.theta_range.set_size(1, 1);
      SUB_DWA_B.theta_range[0] = 41.0;
      SUB_DWA_B.dy.set_size(1, 1);
      SUB_DWA_B.dy[0] = 41.0;
    } else if ((SUB_DWA_B.s_end < 0.01) && (fabs(SUB_DWA_B.R_cur) >= 0.1)) {
      SUB_DWA_B.s_end = -SUB_DWA_B.R_cur * 3.5 / 5.0;
      if (rtIsNaN(SUB_DWA_B.s_end)) {
        SUB_DWA_B.vw_possiables_f = (rtNaN);
      } else if (SUB_DWA_B.s_end < 0.0) {
        SUB_DWA_B.vw_possiables_f = -1.0;
      } else {
        SUB_DWA_B.vw_possiables_f = (SUB_DWA_B.s_end > 0.0);
      }

      SUB_DWA_B.R_cur = SUB_DWA_B.vw_possiables_f * 0.05;
      SUB_DWA_B.s_end = fabs(SUB_DWA_B.s_end);
      if (!(SUB_DWA_B.s_end >= 0.05)) {
        SUB_DWA_B.s_end = 0.05;
      }

      SUB_DWA_B.s_end *= SUB_DWA_B.vw_possiables_f;
      if (rtIsNaN(SUB_DWA_B.R_cur)) {
        SUB_DWA_B.y_front.set_size(1, 1);
        SUB_DWA_B.y_front[0] = (rtNaN);
      } else if (rtIsNaN(SUB_DWA_B.s_end)) {
        SUB_DWA_B.y_front.set_size(1, 1);
        SUB_DWA_B.y_front[0] = (rtNaN);
      } else if ((SUB_DWA_B.R_cur == 0.0) || ((SUB_DWA_B.s_end > 0.0) &&
                  (SUB_DWA_B.R_cur < 0.0)) || ((SUB_DWA_B.s_end < 0.0) &&
                  (SUB_DWA_B.R_cur > 0.0))) {
        SUB_DWA_B.y_front.set_size(1, 0);
      } else if (floor(SUB_DWA_B.R_cur) == SUB_DWA_B.R_cur) {
        SUB_DWA_B.nm1d2 = static_cast<int32_T>(SUB_DWA_B.s_end / SUB_DWA_B.R_cur);
        SUB_DWA_B.y_front.set_size(1, SUB_DWA_B.nm1d2 + 1);
        for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
          SUB_DWA_B.y_front[SUB_DWA_B.n] = SUB_DWA_B.R_cur * static_cast<real_T>
            (SUB_DWA_B.n);
        }
      } else {
        SUB_DWA_eml_float_colon_m(SUB_DWA_B.R_cur, SUB_DWA_B.s_end,
          SUB_DWA_B.y_front);
      }

      SUB_DWA_B.dy.set_size(1, SUB_DWA_B.y_front.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.y_front.size(1);
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.dy[SUB_DWA_B.n] = SUB_DWA_B.y_front[SUB_DWA_B.n] / 0.05;
      }

      SUB_DWA_B.nm1d2 = SUB_DWA_B.dy.size(1);
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.dy[SUB_DWA_B.n] = rt_roundd_snf(SUB_DWA_B.dy[SUB_DWA_B.n]);
      }

      SUB_DWA_B.c_c.set_size(1, SUB_DWA_B.dy.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.dy.size(1);
      SUB_DWA_B.d.set_size(1, SUB_DWA_B.dy.size(1));
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.s_end = SUB_DWA_B.dy[SUB_DWA_B.n];
        SUB_DWA_B.c_c[SUB_DWA_B.n] = ceil(SUB_DWA_B.s_end);
        SUB_DWA_B.d[SUB_DWA_B.n] = floor(SUB_DWA_B.s_end);
      }

      SUB_DWA_B.dy.set_size(1, SUB_DWA_B.dy.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.dy.size(1) - 1;
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.s_end = SUB_DWA_B.dy[SUB_DWA_B.n];
        SUB_DWA_B.dy[SUB_DWA_B.n] = (static_cast<real_T>(SUB_DWA_B.s_end >= 0.0)
          * SUB_DWA_B.c_c[SUB_DWA_B.n] + static_cast<real_T>(SUB_DWA_B.s_end <
          0.0) * SUB_DWA_B.d[SUB_DWA_B.n]) + 41.0;
      }

      SUB_DWA_B.theta_range.set_size(1, SUB_DWA_B.y_front.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.y_front.size(1);
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.theta_range[SUB_DWA_B.n] = 41.0;
      }
    } else if (fabs(SUB_DWA_B.R_cur) < 0.1) {
      SUB_DWA_B.s_end = -SUB_DWA_B.vw_possiables_f * 3.5;
      if (rtIsNaN(SUB_DWA_B.s_end)) {
        SUB_DWA_B.vw_possiables_f = (rtNaN);
      } else if (SUB_DWA_B.s_end < 0.0) {
        SUB_DWA_B.vw_possiables_f = -1.0;
      } else {
        SUB_DWA_B.vw_possiables_f = (SUB_DWA_B.s_end > 0.0);
      }

      SUB_DWA_B.R_cur = SUB_DWA_B.vw_possiables_f * 0.05;
      SUB_DWA_B.s_end = fabs(SUB_DWA_B.s_end);
      if (!(SUB_DWA_B.s_end >= 0.05)) {
        SUB_DWA_B.s_end = 0.05;
      }

      SUB_DWA_B.s_end *= SUB_DWA_B.vw_possiables_f;
      if (rtIsNaN(SUB_DWA_B.R_cur)) {
        SUB_DWA_B.y_front.set_size(1, 1);
        SUB_DWA_B.y_front[0] = (rtNaN);
      } else if (rtIsNaN(SUB_DWA_B.s_end)) {
        SUB_DWA_B.y_front.set_size(1, 1);
        SUB_DWA_B.y_front[0] = (rtNaN);
      } else if ((SUB_DWA_B.R_cur == 0.0) || ((SUB_DWA_B.s_end > 0.0) &&
                  (SUB_DWA_B.R_cur < 0.0)) || ((SUB_DWA_B.s_end < 0.0) &&
                  (SUB_DWA_B.R_cur > 0.0))) {
        SUB_DWA_B.y_front.set_size(1, 0);
      } else if (floor(SUB_DWA_B.R_cur) == SUB_DWA_B.R_cur) {
        SUB_DWA_B.nm1d2 = static_cast<int32_T>(SUB_DWA_B.s_end / SUB_DWA_B.R_cur);
        SUB_DWA_B.y_front.set_size(1, SUB_DWA_B.nm1d2 + 1);
        for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
          SUB_DWA_B.y_front[SUB_DWA_B.n] = SUB_DWA_B.R_cur * static_cast<real_T>
            (SUB_DWA_B.n);
        }
      } else {
        SUB_DWA_eml_float_colon_m(SUB_DWA_B.R_cur, SUB_DWA_B.s_end,
          SUB_DWA_B.y_front);
      }

      SUB_DWA_B.theta_range.set_size(1, SUB_DWA_B.y_front.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.y_front.size(1);
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.theta_range[SUB_DWA_B.n] = SUB_DWA_B.y_front[SUB_DWA_B.n] /
          0.05;
      }

      SUB_DWA_B.c_c.set_size(1, SUB_DWA_B.theta_range.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.theta_range.size(1);
      SUB_DWA_B.d.set_size(1, SUB_DWA_B.theta_range.size(1));
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.s_end = SUB_DWA_B.theta_range[SUB_DWA_B.n];
        SUB_DWA_B.c_c[SUB_DWA_B.n] = ceil(SUB_DWA_B.s_end);
        SUB_DWA_B.d[SUB_DWA_B.n] = floor(SUB_DWA_B.s_end);
      }

      SUB_DWA_B.theta_range.set_size(1, SUB_DWA_B.theta_range.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.theta_range.size(1) - 1;
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.s_end = SUB_DWA_B.theta_range[SUB_DWA_B.n];
        SUB_DWA_B.theta_range[SUB_DWA_B.n] = (static_cast<real_T>
          (SUB_DWA_B.s_end >= 0.0) * SUB_DWA_B.c_c[SUB_DWA_B.n] + static_cast<
          real_T>(SUB_DWA_B.s_end < 0.0) * SUB_DWA_B.d[SUB_DWA_B.n]) + 41.0;
      }

      SUB_DWA_B.dy.set_size(1, SUB_DWA_B.theta_range.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.theta_range.size(1);
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.dy[SUB_DWA_B.n] = 41.0;
      }
    } else {
      SUB_DWA_B.R_cur = SUB_DWA_B.vw_possiables_f / SUB_DWA_B.R_cur;
      if (SUB_DWA_B.R_cur >= 5.0) {
        SUB_DWA_B.R_cur = 5.0;
      }

      SUB_DWA_B.s_end = -SUB_DWA_B.vw_possiables_f * 3.5;
      if (rtIsNaN(SUB_DWA_B.s_end)) {
        SUB_DWA_B.d_d_tmp = (rtNaN);
      } else if (SUB_DWA_B.s_end < 0.0) {
        SUB_DWA_B.d_d_tmp = -1.0;
      } else {
        SUB_DWA_B.d_d_tmp = (SUB_DWA_B.s_end > 0.0);
      }

      SUB_DWA_B.vw_possiables_f = SUB_DWA_B.d_d_tmp * 0.05;
      SUB_DWA_B.s_end = fabs(SUB_DWA_B.s_end);
      if (!(SUB_DWA_B.s_end >= 0.05)) {
        SUB_DWA_B.s_end = 0.05;
      }

      SUB_DWA_B.s_end *= SUB_DWA_B.d_d_tmp;
      if (rtIsNaN(SUB_DWA_B.vw_possiables_f)) {
        SUB_DWA_B.y_front.set_size(SUB_DWA_B.y_front.size(0), 1);
      } else if (rtIsNaN(SUB_DWA_B.s_end)) {
        SUB_DWA_B.y_front.set_size(SUB_DWA_B.y_front.size(0), 1);
      } else if ((SUB_DWA_B.vw_possiables_f == 0.0) || ((SUB_DWA_B.s_end > 0.0) &&
                  (SUB_DWA_B.vw_possiables_f < 0.0)) || ((SUB_DWA_B.s_end < 0.0)
                  && (SUB_DWA_B.vw_possiables_f > 0.0))) {
        SUB_DWA_B.y_front.set_size(SUB_DWA_B.y_front.size(0), 0);
      } else if (floor(SUB_DWA_B.vw_possiables_f) == SUB_DWA_B.vw_possiables_f)
      {
        SUB_DWA_B.nm1d2 = static_cast<int32_T>(SUB_DWA_B.s_end /
          SUB_DWA_B.vw_possiables_f);
        SUB_DWA_B.y_front.set_size(1, SUB_DWA_B.nm1d2 + 1);
        for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
          SUB_DWA_B.y_front[SUB_DWA_B.n] = SUB_DWA_B.vw_possiables_f *
            static_cast<real_T>(SUB_DWA_B.n);
        }
      } else {
        SUB_DWA_eml_float_colon_m(SUB_DWA_B.vw_possiables_f, SUB_DWA_B.s_end,
          SUB_DWA_B.y_front);
      }

      SUB_DWA_linspace_a(SUB_DWA_B.vw_possiables[SUB_DWA_B.b_k + 2601] * 3.5,
                         static_cast<real_T>(SUB_DWA_B.y_front.size(1)),
                         SUB_DWA_B.theta_range);
      SUB_DWA_B.dy.set_size(1, SUB_DWA_B.theta_range.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.theta_range.size(1);
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.dy[SUB_DWA_B.n] = cos(SUB_DWA_B.theta_range[SUB_DWA_B.n]);
      }

      SUB_DWA_B.dy.set_size(1, SUB_DWA_B.dy.size(1));
      SUB_DWA_B.j = SUB_DWA_B.dy.size(1) - 1;
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.j; SUB_DWA_B.n++) {
        SUB_DWA_B.dy[SUB_DWA_B.n] = (1.0 - SUB_DWA_B.dy[SUB_DWA_B.n]) *
          -SUB_DWA_B.R_cur / 0.05;
      }

      SUB_DWA_B.nm1d2 = SUB_DWA_B.theta_range.size(1);
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.theta_range[SUB_DWA_B.n] = sin
          (SUB_DWA_B.theta_range[SUB_DWA_B.n]);
      }

      SUB_DWA_B.theta_range.set_size(1, SUB_DWA_B.theta_range.size(1));
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.j; SUB_DWA_B.n++) {
        SUB_DWA_B.theta_range[SUB_DWA_B.n] = -SUB_DWA_B.R_cur *
          SUB_DWA_B.theta_range[SUB_DWA_B.n] / 0.05;
      }

      SUB_DWA_B.c_c.set_size(1, SUB_DWA_B.theta_range.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.theta_range.size(1);
      SUB_DWA_B.d.set_size(1, SUB_DWA_B.theta_range.size(1));
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.s_end = SUB_DWA_B.theta_range[SUB_DWA_B.n];
        SUB_DWA_B.c_c[SUB_DWA_B.n] = ceil(SUB_DWA_B.s_end);
        SUB_DWA_B.d[SUB_DWA_B.n] = floor(SUB_DWA_B.s_end);
      }

      SUB_DWA_B.theta_range.set_size(1, SUB_DWA_B.theta_range.size(1));
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.j; SUB_DWA_B.n++) {
        SUB_DWA_B.s_end = SUB_DWA_B.theta_range[SUB_DWA_B.n];
        SUB_DWA_B.theta_range[SUB_DWA_B.n] = (static_cast<real_T>
          (SUB_DWA_B.s_end >= 0.0) * SUB_DWA_B.c_c[SUB_DWA_B.n] + static_cast<
          real_T>(SUB_DWA_B.s_end < 0.0) * SUB_DWA_B.d[SUB_DWA_B.n]) + 41.0;
      }

      SUB_DWA_B.c_c.set_size(1, SUB_DWA_B.dy.size(1));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.dy.size(1);
      SUB_DWA_B.d.set_size(1, SUB_DWA_B.dy.size(1));
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.s_end = SUB_DWA_B.dy[SUB_DWA_B.n];
        SUB_DWA_B.c_c[SUB_DWA_B.n] = ceil(SUB_DWA_B.s_end);
        SUB_DWA_B.d[SUB_DWA_B.n] = floor(SUB_DWA_B.s_end);
      }

      SUB_DWA_B.dy.set_size(1, SUB_DWA_B.dy.size(1));
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n <= SUB_DWA_B.j; SUB_DWA_B.n++) {
        SUB_DWA_B.s_end = SUB_DWA_B.dy[SUB_DWA_B.n];
        SUB_DWA_B.dy[SUB_DWA_B.n] = (static_cast<real_T>(SUB_DWA_B.s_end >= 0.0)
          * SUB_DWA_B.c_c[SUB_DWA_B.n] + static_cast<real_T>(SUB_DWA_B.s_end <
          0.0) * SUB_DWA_B.d[SUB_DWA_B.n]) + 41.0;
      }
    }

    SUB_DWA_B.nm1d2 = SUB_DWA_B.theta_range.size(1);
    SUB_DWA_B.j = SUB_DWA_B.dy.size(1);
    SUB_DWA_B.theta_range_k.set_size(SUB_DWA_B.theta_range.size(1), 2);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
      SUB_DWA_B.theta_range_k[SUB_DWA_B.n] = SUB_DWA_B.theta_range[SUB_DWA_B.n];
    }

    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.j; SUB_DWA_B.n++) {
      SUB_DWA_B.theta_range_k[SUB_DWA_B.n + SUB_DWA_B.nm1d2] =
        SUB_DWA_B.dy[SUB_DWA_B.n];
    }

    SUB_DWA_unique_rows(SUB_DWA_B.theta_range_k, SUB_DWA_B.xy);
    SUB_DWA_B.b.set_size(SUB_DWA_B.xy.size(0));
    SUB_DWA_B.nm1d2 = SUB_DWA_B.xy.size(0);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
      SUB_DWA_B.s_end = SUB_DWA_B.xy[SUB_DWA_B.n];
      SUB_DWA_B.R_cur = SUB_DWA_B.xy[SUB_DWA_B.n + SUB_DWA_B.xy.size(0)];
      SUB_DWA_B.b[SUB_DWA_B.n] = ((SUB_DWA_B.s_end >= static_cast<real_T>
        (SUB_DWA_B.b_n) + 1.0) && (SUB_DWA_B.s_end <= 81.0 - static_cast<real_T>
        (SUB_DWA_B.b_n)) && (SUB_DWA_B.R_cur >= static_cast<real_T>
        (SUB_DWA_B.b_n) + 1.0) && (SUB_DWA_B.R_cur <= 81.0 - static_cast<real_T>
        (SUB_DWA_B.b_n)));
    }

    SUB_DWA_B.nm1d2 = SUB_DWA_B.b.size(0) - 1;
    SUB_DWA_B.n = 0;
    for (SUB_DWA_B.j = 0; SUB_DWA_B.j <= SUB_DWA_B.nm1d2; SUB_DWA_B.j++) {
      if (SUB_DWA_B.b[SUB_DWA_B.j]) {
        SUB_DWA_B.n++;
      }
    }

    SUB_DWA_B.r.set_size(SUB_DWA_B.n);
    SUB_DWA_B.n = 0;
    for (SUB_DWA_B.j = 0; SUB_DWA_B.j <= SUB_DWA_B.nm1d2; SUB_DWA_B.j++) {
      if (SUB_DWA_B.b[SUB_DWA_B.j]) {
        SUB_DWA_B.r[SUB_DWA_B.n] = SUB_DWA_B.j;
        SUB_DWA_B.n++;
      }
    }

    SUB_DWA_B.nm1d2 = SUB_DWA_B.r.size(0);
    SUB_DWA_B.theta_range_k.set_size(SUB_DWA_B.r.size(0), 2);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < 2; SUB_DWA_B.n++) {
      for (SUB_DWA_B.i = 0; SUB_DWA_B.i < SUB_DWA_B.nm1d2; SUB_DWA_B.i++) {
        SUB_DWA_B.theta_range_k[SUB_DWA_B.i + SUB_DWA_B.theta_range_k.size(0) *
          SUB_DWA_B.n] = SUB_DWA_B.xy[SUB_DWA_B.xy.size(0) * SUB_DWA_B.n +
          SUB_DWA_B.r[SUB_DWA_B.i]];
      }
    }

    SUB_DWA_B.xy.set_size(SUB_DWA_B.theta_range_k.size(0), 2);
    SUB_DWA_B.nm1d2 = SUB_DWA_B.theta_range_k.size(0) << 1;
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
      SUB_DWA_B.xy[SUB_DWA_B.n] = SUB_DWA_B.theta_range_k[SUB_DWA_B.n];
    }

    SUB_DWA_B.e = SUB_DWA_B.xy.size(0);
    for (SUB_DWA_B.j = 0; SUB_DWA_B.j < SUB_DWA_B.e; SUB_DWA_B.j++) {
      SUB_DWA_B.s_end = SUB_DWA_B.xy[SUB_DWA_B.j];
      SUB_DWA_B.R_cur = SUB_DWA_B.s_end - static_cast<real_T>(SUB_DWA_B.b_n);
      SUB_DWA_B.s_end += static_cast<real_T>(SUB_DWA_B.b_n);
      if (SUB_DWA_B.R_cur > SUB_DWA_B.s_end) {
        SUB_DWA_B.k = 0;
        SUB_DWA_B.nm1d2 = 0;
      } else {
        SUB_DWA_B.k = static_cast<int32_T>(SUB_DWA_B.R_cur) - 1;
        SUB_DWA_B.nm1d2 = static_cast<int32_T>(SUB_DWA_B.s_end);
      }

      SUB_DWA_B.s_end = SUB_DWA_B.xy[SUB_DWA_B.j + SUB_DWA_B.xy.size(0)];
      SUB_DWA_B.R_cur = SUB_DWA_B.s_end - static_cast<real_T>(SUB_DWA_B.b_n);
      SUB_DWA_B.s_end += static_cast<real_T>(SUB_DWA_B.b_n);
      if (SUB_DWA_B.R_cur > SUB_DWA_B.s_end) {
        SUB_DWA_B.o = 0;
        SUB_DWA_B.n = 0;
      } else {
        SUB_DWA_B.o = static_cast<int32_T>(SUB_DWA_B.R_cur) - 1;
        SUB_DWA_B.n = static_cast<int32_T>(SUB_DWA_B.s_end);
      }

      SUB_DWA_B.nm1d2 -= SUB_DWA_B.k;
      loop_ub = SUB_DWA_B.n - SUB_DWA_B.o;
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < loop_ub; SUB_DWA_B.n++) {
        for (SUB_DWA_B.i = 0; SUB_DWA_B.i < SUB_DWA_B.nm1d2; SUB_DWA_B.i++) {
          SUB_DWA_B.x_possible[SUB_DWA_B.i + SUB_DWA_B.nm1d2 * SUB_DWA_B.n] =
            SUB_DWA_B.y_possible[((SUB_DWA_B.o + SUB_DWA_B.n) * 81 + SUB_DWA_B.k)
            + SUB_DWA_B.i];
        }
      }

      SUB_DWA_B.h[0] = SUB_DWA_B.nm1d2 * loop_ub;
      SUB_DWA_B.U_Trajectories[SUB_DWA_B.b_k] += SUB_DWA_sum
        (SUB_DWA_B.x_possible, SUB_DWA_B.h);
    }

    SUB_DWA_B.s_end = SUB_DWA_B.U_Trajectories[SUB_DWA_B.b_k] /
      static_cast<real_T>(SUB_DWA_B.xy.size(0));
    SUB_DWA_B.U_Trajectories[SUB_DWA_B.b_k] = SUB_DWA_B.s_end;
    SUB_DWA_B.vw_possiables_f = SUB_DWA_B.vw_possiables[SUB_DWA_B.b_k];
    SUB_DWA_B.R_cur = fabs(SUB_DWA_B.vw_possiables[SUB_DWA_B.b_k + 2601] -
      SUB_DWA_B.apnd);
    SUB_DWA_B.V[SUB_DWA_B.b_k] = SUB_DWA_B.R_cur;
    SUB_DWA_B.score[SUB_DWA_B.b_k] = ((fabs(SUB_DWA_B.vw_possiables_f -
      SUB_DWA_B.ndbl) * 3.0 + 0.9 * SUB_DWA_B.R_cur) * SUB_DWA_B.cdiff +
      SUB_DWA_B.u1 * SUB_DWA_B.s_end) + SUB_DWA_B.y_c *
      -SUB_DWA_B.vw_possiables_f;
  }

  SUB_DWA_minimum(SUB_DWA_B.score, &SUB_DWA_B.ndbl, &SUB_DWA_B.b_k);
  SUB_DWA_B.s_end = SUB_DWA_B.score[SUB_DWA_B.b_k - 1];
  if (rtIsNaN(SUB_DWA_B.s_end)) {
    SUB_DWA_B.ndbl = 0.0;
    SUB_DWA_B.apnd = 0.0;
  } else if (rtIsInf(SUB_DWA_B.s_end)) {
    SUB_DWA_B.ndbl = 0.0;
    SUB_DWA_B.apnd = 0.0;
  } else {
    SUB_DWA_B.ndbl = SUB_DWA_B.vw_possiables[SUB_DWA_B.b_k - 1];
    SUB_DWA_B.apnd = SUB_DWA_B.vw_possiables[SUB_DWA_B.b_k + 2600];
  }

  // End of MATLAB Function: '<S23>/MATLAB Function'

  // MATLAB Function: '<S23>/MATLAB Function2' incorporates:
  //   MATLAB Function: '<S4>/Parameter defination'

  SUB_DWA_B.b_k = SUB_DWA_B.Sensor_ranges.size(0);
  SUB_DWA_B.b.set_size(SUB_DWA_B.b_k);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
    SUB_DWA_B.b[SUB_DWA_B.n] = (SUB_DWA_B.Sensor_ranges[SUB_DWA_B.n] > 0.0);
  }

  SUB_DWA_B.b_k = SUB_DWA_B.Sensor_ranges.size(0);
  SUB_DWA_B.c.set_size(SUB_DWA_B.b_k);
  for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
    SUB_DWA_B.c[SUB_DWA_B.n] = (SUB_DWA_B.Sensor_ranges[SUB_DWA_B.n] <= 1.3);
  }

  SUB_DWA_B.b_n = SUB_DWA_B.b.size(0) - 1;
  SUB_DWA_B.n = 0;
  for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k <= SUB_DWA_B.b_n; SUB_DWA_B.b_k++) {
    // MATLAB Function: '<S23>/MATLAB Function2'
    if (SUB_DWA_B.b[SUB_DWA_B.b_k] && SUB_DWA_B.c[SUB_DWA_B.b_k]) {
      SUB_DWA_B.n++;
    }
  }

  // MATLAB Function: '<S23>/MATLAB Function2' incorporates:
  //   MATLAB Function: '<S4>/Parameter defination'

  if (SUB_DWA_B.n != 0) {
    SUB_DWA_B.n = 0;
    for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k <= SUB_DWA_B.b_n; SUB_DWA_B.b_k++) {
      if (SUB_DWA_B.b[SUB_DWA_B.b_k] && SUB_DWA_B.c[SUB_DWA_B.b_k]) {
        SUB_DWA_B.n++;
      }
    }

    SUB_DWA_B.r1.set_size(SUB_DWA_B.n);
    SUB_DWA_B.n = 0;
    for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k <= SUB_DWA_B.b_n; SUB_DWA_B.b_k++) {
      if (SUB_DWA_B.b[SUB_DWA_B.b_k] && SUB_DWA_B.c[SUB_DWA_B.b_k]) {
        SUB_DWA_B.r1[SUB_DWA_B.n] = SUB_DWA_B.b_k;
        SUB_DWA_B.n++;
      }
    }

    SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.r1.size(0));
    SUB_DWA_B.nm1d2 = SUB_DWA_B.r1.size(0);
    for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
      SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] =
        SUB_DWA_B.Sensor_ranges[SUB_DWA_B.r1[SUB_DWA_B.n]];
    }

    SUB_DWA_B.cdiff = SUB_DWA_minimum_i(SUB_DWA_B.y_obj_ultrasonic_m) / 1.3;
    SUB_DWA_DW.is_limited = true;
    SUB_DWA_DW.counter = 0.0;
  } else if (SUB_DWA_DW.is_limited) {
    SUB_DWA_DW.counter++;
    if (SUB_DWA_DW.counter >= 60.0) {
      SUB_DWA_DW.is_limited = false;
      SUB_DWA_B.cdiff = 1.0;
    } else {
      SUB_DWA_B.b_k = SUB_DWA_B.Sensor_ranges.size(0);
      SUB_DWA_B.b.set_size(SUB_DWA_B.b_k);
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.b_k; SUB_DWA_B.n++) {
        SUB_DWA_B.b[SUB_DWA_B.n] = (SUB_DWA_B.Sensor_ranges[SUB_DWA_B.n] > 0.0);
      }

      SUB_DWA_B.nm1d2 = SUB_DWA_B.b.size(0) - 1;
      SUB_DWA_B.n = 0;
      for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k <= SUB_DWA_B.nm1d2; SUB_DWA_B.b_k++)
      {
        if (SUB_DWA_B.b[SUB_DWA_B.b_k]) {
          SUB_DWA_B.n++;
        }
      }

      SUB_DWA_B.r1.set_size(SUB_DWA_B.n);
      SUB_DWA_B.n = 0;
      for (SUB_DWA_B.b_k = 0; SUB_DWA_B.b_k <= SUB_DWA_B.nm1d2; SUB_DWA_B.b_k++)
      {
        if (SUB_DWA_B.b[SUB_DWA_B.b_k]) {
          SUB_DWA_B.r1[SUB_DWA_B.n] = SUB_DWA_B.b_k;
          SUB_DWA_B.n++;
        }
      }

      SUB_DWA_B.y_obj_ultrasonic_m.set_size(SUB_DWA_B.r1.size(0));
      SUB_DWA_B.nm1d2 = SUB_DWA_B.r1.size(0);
      for (SUB_DWA_B.n = 0; SUB_DWA_B.n < SUB_DWA_B.nm1d2; SUB_DWA_B.n++) {
        SUB_DWA_B.y_obj_ultrasonic_m[SUB_DWA_B.n] =
          SUB_DWA_B.Sensor_ranges[SUB_DWA_B.r1[SUB_DWA_B.n]];
      }

      SUB_DWA_B.cdiff = SUB_DWA_minimum_i(SUB_DWA_B.y_obj_ultrasonic_m) / 1.3;
    }
  } else {
    SUB_DWA_B.cdiff = 1.0;
  }

  if (!(SUB_DWA_B.cdiff >= 0.0)) {
    SUB_DWA_B.cdiff = 0.0;
  }

  if (!(SUB_DWA_B.cdiff <= 1.0)) {
    SUB_DWA_B.cdiff = 1.0;
  }

  if (!(SUB_DWA_B.ndbl <= SUB_DWA_B.cdiff)) {
    SUB_DWA_B.ndbl = SUB_DWA_B.cdiff;
  }

  if ((SUB_DWA_B.ndbl >= -SUB_DWA_B.cdiff) || rtIsNaN(-SUB_DWA_B.cdiff)) {
    // MATLAB Function: '<S24>/Force to stop'
    SUB_DWA_DW.vel_last[0] = SUB_DWA_B.ndbl;
  } else {
    // MATLAB Function: '<S24>/Force to stop'
    SUB_DWA_DW.vel_last[0] = -SUB_DWA_B.cdiff;
  }

  if (!(SUB_DWA_B.apnd <= 1.6666666666666667)) {
    SUB_DWA_B.apnd = 1.6666666666666667;
  }

  if (SUB_DWA_B.apnd >= -1.6666666666666667) {
    // MATLAB Function: '<S24>/Force to stop'
    SUB_DWA_DW.vel_last[1] = SUB_DWA_B.apnd;
  } else {
    // MATLAB Function: '<S24>/Force to stop'
    SUB_DWA_DW.vel_last[1] = -1.6666666666666667;
  }

  // MATLAB Function: '<S24>/Force to stop' incorporates:
  //   MATLAB Function: '<S9>/vw_calculator'

  SUB_DWA_B.xo[0] = SUB_DWA_B.In1_a.buttons[0];
  SUB_DWA_B.xo[1] = SUB_DWA_B.In1_a.buttons[1];
  SUB_DWA_B.dv2[0] = 1.0;
  SUB_DWA_B.dv2[1] = 0.0;
  if (SUB_DWA_isequal(SUB_DWA_B.xo, SUB_DWA_B.dv2)) {
    SUB_DWA_DW.stop = 0.0;
  } else {
    SUB_DWA_B.dv2[0] = 0.0;
    SUB_DWA_B.dv2[1] = 1.0;
    if (SUB_DWA_isequal(SUB_DWA_B.xo, SUB_DWA_B.dv2)) {
      SUB_DWA_DW.stop = 1.0;
    }
  }

  if (SUB_DWA_DW.stop != 0.0) {
    SUB_DWA_DW.vel_last[0] = 0.0;
    SUB_DWA_DW.vel_last[1] = 0.0;
  }

  // MATLAB Function: '<S4>/Behavior Switcher'
  if (static_cast<int32_T>(SUB_DWA_DW.behaviorSwitch) == 1) {
    // DataStoreWrite: '<S4>/Data Store Write6'
    SUB_DWA_DW.StateWander = 0.0;
  } else {
    // DataStoreWrite: '<S4>/Data Store Write6'
    SUB_DWA_DW.StateWander = 1.0;
  }

  // BusAssignment: '<S1>/Bus Assignment' incorporates:
  //   MATLAB Function: '<S1>/[v,w]==>MotionCmd'
  //   MATLAB Function: '<S1>/mode reader'

  memset(&SUB_DWA_B.BusAssignment, 0, sizeof(SL_Bus_motion_msgs_MotionCtrl));
  SUB_DWA_B.BusAssignment.value.forward = SUB_DWA_DW.vel_last[0];
  SUB_DWA_B.BusAssignment.value.left = SUB_DWA_DW.vel_last[1];
  SUB_DWA_B.BusAssignment.value.up = SUB_DWA_DW.value[0];
  SUB_DWA_B.BusAssignment.value.roll = SUB_DWA_DW.value[1];
  SUB_DWA_B.BusAssignment.value.pitch = SUB_DWA_DW.value[2];
  SUB_DWA_B.BusAssignment.mode_mark = SUB_DWA_DW.mode[0];
  SUB_DWA_B.BusAssignment.mode.pitch_ctrl_mode = SUB_DWA_DW.mode[1];
  SUB_DWA_B.BusAssignment.mode.roll_ctrl_mode = SUB_DWA_DW.mode[2];
  SUB_DWA_B.BusAssignment.mode.height_ctrl_mode = SUB_DWA_DW.mode[3];
  SUB_DWA_B.BusAssignment.mode.stand_mode = SUB_DWA_DW.mode[4];

  // MATLABSystem: '<S12>/SinkBlock'
  Pub_SUB_DWA_1882.publish(&SUB_DWA_B.BusAssignment);
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void SUB_DWA_step(SUB_DWA & SUB_DWA_Obj, int_T tid)
{
  switch (tid) {
   case 0 :
    SUB_DWA_Obj.step0();
    break;

   case 1 :
    SUB_DWA_Obj.step1();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void SUB_DWA::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // Start for MATLAB Function: '<S4>/Behavior Switcher' incorporates:
  //   DataStoreMemory: '<S4>/Data Store Memory6'

  SUB_DWA_DW.behaviorSwitch = 1.0;

  // Start for MATLABSystem: '<S8>/SourceBlock'
  SUB_DWA_SystemCore_setup_b2fg(&SUB_DWA_DW.obj_e);

  // Start for MATLABSystem: '<S13>/SourceBlock'
  SUB_DWA_SystemCore_setup_b2fgx2(&SUB_DWA_DW.obj);

  // Start for MATLABSystem: '<S2>/SourceBlock'
  SUB_DWA_SystemCore_setup(&SUB_DWA_DW.obj_g);

  // Start for MATLABSystem: '<S5>/SourceBlock'
  SUB_DWA_SystemCore_setup_b(&SUB_DWA_DW.obj_m);

  // Start for MATLABSystem: '<S6>/SourceBlock'
  SUB_DWA_SystemCore_setup_b2(&SUB_DWA_DW.obj_ez);

  // Start for MATLABSystem: '<S7>/SourceBlock'
  SUB_DWA_SystemCore_setup_b2f(&SUB_DWA_DW.obj_i);

  // Start for MATLABSystem: '<S12>/SinkBlock'
  SUB_DWA_SystemCore_setup_b2fgx(&SUB_DWA_DW.obj_a);
}

// Model terminate function
void SUB_DWA::terminate()
{
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!SUB_DWA_DW.obj_e.matlabCodegenIsDeleted) {
    SUB_DWA_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'

  // Terminate for MATLABSystem: '<S13>/SourceBlock'
  if (!SUB_DWA_DW.obj.matlabCodegenIsDeleted) {
    SUB_DWA_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/SourceBlock'

  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  if (!SUB_DWA_DW.obj_g.matlabCodegenIsDeleted) {
    SUB_DWA_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!SUB_DWA_DW.obj_m.matlabCodegenIsDeleted) {
    SUB_DWA_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!SUB_DWA_DW.obj_ez.matlabCodegenIsDeleted) {
    SUB_DWA_DW.obj_ez.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!SUB_DWA_DW.obj_i.matlabCodegenIsDeleted) {
    SUB_DWA_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'

  // Terminate for MATLABSystem: '<S12>/SinkBlock'
  if (!SUB_DWA_DW.obj_a.matlabCodegenIsDeleted) {
    SUB_DWA_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SinkBlock'
}

// Constructor
SUB_DWA::SUB_DWA() :
  SUB_DWA_B(),
  SUB_DWA_DW(),
  SUB_DWA_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
SUB_DWA::~SUB_DWA()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_SUB_DWA_T * SUB_DWA::getRTM()
{
  return (&SUB_DWA_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
