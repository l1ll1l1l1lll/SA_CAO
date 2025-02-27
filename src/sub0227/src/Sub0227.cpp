//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Sub0227.cpp
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
#include "Sub0227.h"
#include "Sub0227_types.h"
#include "rtwtypes.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include <emmintrin.h>
#include <math.h>
#include "rmw/qos_profiles.h"
#include <stddef.h>

// Function for MATLAB Function: '<S13>/Force to stop'
boolean_T Sub0227::Sub0227_isequal(const int32_T varargin_1[2], const real_T
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

void Sub0227::Sub0227_Subscriber_setupImpl_b(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  static const char_T b_zeroDelimTopic[16] = "/xbox_joy_state";
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S6>/SourceBlock'
  deadline.sec = 0.0;
  deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 16; i++) {
    // Start for MATLABSystem: '<S6>/SourceBlock'
    Sub0227_B.b_zeroDelimTopic[i] = b_zeroDelimTopic[i];
  }

  Sub_Sub0227_1483.createSubscriber(&Sub0227_B.b_zeroDelimTopic[0], qos_profile);
}

void Sub0227::Sub0227_Subscriber_setupImpl(const ros_slros2_internal_block_Sub_T
  *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  char_T b_zeroDelimTopic[6];
  static const char_T b_zeroDelimTopic_0[6] = "/scan";
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S2>/SourceBlock'
  Sub0227_B.deadline_k.sec = 0.0;
  Sub0227_B.deadline_k.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, Sub0227_B.deadline_k,
                 lifespan, RMW_QOS_POLICY_LIVELINESS_AUTOMATIC,
                 liveliness_lease_duration, (bool)
                 obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S2>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_Sub0227_1432.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
}

void Sub0227::Sub0227_Publisher_setupImpl(const ros_slros2_internal_block_Pub_T *
  obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  char_T b_zeroDelimTopic[9];
  static const char_T b_zeroDelimTopic_0[9] = "/cmd_vel";
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S8>/SinkBlock'
  Sub0227_B.deadline.sec = 0.0;
  Sub0227_B.deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE, Sub0227_B.deadline,
                 lifespan, RMW_QOS_POLICY_LIVELINESS_AUTOMATIC,
                 liveliness_lease_duration, (bool)
                 obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 9; i++) {
    // Start for MATLABSystem: '<S8>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_Sub0227_1434.createPublisher(&b_zeroDelimTopic[0], qos_profile);
}

// Model step function
void Sub0227::step()
{
  real_T b_y;
  real_T rtb_angels_0;
  real_T rtb_vw_idx_0;
  real_T rtb_vw_idx_1;
  int32_T xo[2];
  int32_T StateControl;
  int32_T StateWander;
  real32_T F_i;
  boolean_T b_varargout_1;
  static const real_T tmp[360] = { 0.0, 0.017501908933647871,
    0.035003817867295742, 0.052505726800943613, 0.070007635734591483,
    0.087509544668239347, 0.10501145360188723, 0.1225133625355351,
    0.14001527146918297, 0.15751718040283083, 0.17501908933647869,
    0.19252099827012659, 0.21002290720377445, 0.22752481613742231,
    0.24502672507107021, 0.26252863400471804, 0.28003054293836593,
    0.29753245187201383, 0.31503436080566166, 0.33253626973930955,
    0.35003817867295739, 0.36754008760660528, 0.38504199654025317,
    0.402543905473901, 0.4200458144075489, 0.43754772334119679,
    0.45504963227484463, 0.47255154120849252, 0.49005345014214041,
    0.5075553590757883, 0.52505726800943608, 0.542559176943084,
    0.56006108587673187, 0.57756299481037976, 0.59506490374402765,
    0.61256681267767543, 0.63006872161132332, 0.64757063054497122,
    0.66507253947861911, 0.682574448412267, 0.70007635734591478,
    0.71757826627956267, 0.73508017521321056, 0.75258208414685845,
    0.77008399308050635, 0.78758590201415424, 0.805087810947802,
    0.82258971988144991, 0.8400916288150978, 0.85759353774874569,
    0.87509544668239359, 0.89259735561604137, 0.91009926454968926,
    0.92760117348333715, 0.945103082416985, 0.96260499135063293,
    0.98010690028428082, 0.9976088092179286, 1.0151107181515766,
    1.0326126270852243, 1.0501145360188722, 1.06761644495252, 1.085118353886168,
    1.1026202628198158, 1.1201221717534637, 1.1376240806871116,
    1.1551259896207595, 1.1726278985544074, 1.1901298074880553,
    1.2076317164217032, 1.2251336253553509, 1.2426355342889988,
    1.2601374432226466, 1.2776393521562945, 1.2951412610899424,
    1.3126431700235903, 1.3301450789572382, 1.3476469878908861,
    1.365148896824534, 1.3826508057581819, 1.4001527146918296,
    1.4176546236254775, 1.4351565325591253, 1.4526584414927732,
    1.4701603504264211, 1.487662259360069, 1.5051641682937169,
    1.5226660772273648, 1.5401679861610127, 1.5576698950946606,
    1.5751718040283085, 1.5926737129619561, 1.610175621895604,
    1.6276775308292519, 1.6451794397628998, 1.6626813486965477,
    1.6801832576301956, 1.6976851665638435, 1.7151870754974914,
    1.7326889844311393, 1.7501908933647872, 1.7676928022984351,
    1.7851947112320827, 1.8026966201657306, 1.8201985290993785,
    1.8377004380330264, 1.8552023469666743, 1.8727042559003222, 1.89020616483397,
    1.907708073767618, 1.9252099827012659, 1.9427118916349138,
    1.9602138005685616, 1.9777157095022093, 1.9952176184358572,
    2.0127195273695051, 2.0302214363031532, 2.0477233452368009,
    2.0652252541704486, 2.0827271631040967, 2.1002290720377443,
    2.1177309809713925, 2.13523288990504, 2.1527347988386882, 2.1702367077723359,
    2.187738616705984, 2.2052405256396317, 2.22274243457328, 2.2402443435069275,
    2.2577462524405751, 2.2752481613742233, 2.2927500703078709,
    2.310251979241519, 2.3277538881751667, 2.3452557971088148,
    2.3627577060424625, 2.3802596149761106, 2.3977615239097583,
    2.4152634328434064, 2.4327653417770541, 2.4502672507107017, 2.46776915964435,
    2.4852710685779975, 2.5027729775116456, 2.5202748864452933,
    2.5377767953789414, 2.5552787043125891, 2.5727806132462372,
    2.5902825221798849, 2.607784431113533, 2.6252863400471806,
    2.6427882489808283, 2.6602901579144764, 2.6777920668481241,
    2.6952939757817722, 2.71279588471542, 2.730297793649068, 2.7477997025827157,
    2.7653016115163638, 2.7828035204500114, 2.8003054293836591,
    2.8178073383173072, 2.8353092472509549, 2.852811156184603,
    2.8703130651182507, 2.8878149740518988, 2.9053168829855465,
    2.9228187919191946, 2.9403207008528423, 2.9578226097864904,
    2.975324518720138, 2.9928264276537857, 3.0103283365874338,
    3.0278302455210815, 3.0453321544547296, 3.0628340633883773,
    3.0803359723220254, 3.0978378812556731, 3.1153397901893212,
    3.1328416991229688, 3.1503436080566174, 3.1678455169902651,
    3.1853474259239132, 3.2028493348575608, 3.220351243791209,
    3.2378531527248566, 3.2553550616585047, 3.2728569705921524,
    3.2903588795258005, 3.3078607884594482, 3.3253626973930959,
    3.342864606326744, 3.3603665152603917, 3.3778684241940398,
    3.3953703331276874, 3.4128722420613355, 3.4303741509949832,
    3.4478760599286313, 3.465377968862279, 3.4828798777959271,
    3.5003817867295748, 3.5178836956632225, 3.5353856045968706,
    3.5528875135305182, 3.5703894224641664, 3.587891331397814,
    3.6053932403314621, 3.62289514926511, 3.6403970581987579, 3.6578989671324056,
    3.6754008760660533, 3.6929027849997014, 3.710404693933349,
    3.7279066028669972, 3.7454085118006448, 3.7629104207342929,
    3.7804123296679406, 3.7979142386015887, 3.8154161475352364,
    3.8329180564688845, 3.8504199654025322, 3.86792187433618, 3.885423783269828,
    3.9029256922034756, 3.9204276011371237, 3.9379295100707714,
    3.9554314190044195, 3.9729333279380672, 3.9904352368717153,
    4.0079371458053625, 4.0254390547390111, 4.0429409636726588,
    4.0604428726063064, 4.077944781539955, 4.0954466904736027, 4.11294859940725,
    4.130450508340898, 4.1479524172745457, 4.1654543262081933,
    4.1829562351418419, 4.20045814407549, 4.2179600530091381, 4.2354619619427858,
    4.2529638708764335, 4.2704657798100811, 4.2879676887437288,
    4.3054695976773765, 4.3229715066110241, 4.3404734155446727, 4.35797532447832,
    4.375477233411968, 4.3929791423456166, 4.4104810512792643,
    4.4279829602129119, 4.44548486914656, 4.4629867780802073, 4.4804886870138558,
    4.4979905959475035, 4.5154925048811512, 4.5329944138147988,
    4.5504963227484474, 4.5679982316820951, 4.5855001406157427, 4.60300204954939,
    4.6205039584830381, 4.6380058674166866, 4.6555077763503343,
    4.673009685283982, 4.6905115942176305, 4.7080135031512782,
    4.7255154120849259, 4.7430173210185735, 4.7605192299522212,
    4.7780211388858689, 4.7955230478195174, 4.8130249567531651,
    4.8305268656868128, 4.8480287746204613, 4.865530683554109,
    4.8830325924877567, 4.9005345014214043, 4.918036410355052, 4.9355383192887,
    4.9530402282223482, 4.9705421371559959, 4.9880440460896436,
    5.0055459550232921, 5.02304786395694, 5.0405497728905875, 5.0580516818242351,
    5.0755535907578828, 5.0930554996915305, 5.110557408625179,
    5.1280593175588267, 5.1455612264924744, 5.1630631354261229,
    5.1805650443597706, 5.1980669532934183, 5.2155688622270659,
    5.2330707711607136, 5.2505726800943622, 5.26807458902801, 5.2855764979616575,
    5.3030784068953052, 5.3205803158289537, 5.3380822247626014,
    5.3555841336962491, 5.3730860426298968, 5.3905879515635444,
    5.408089860497193, 5.4255917694308406, 5.4430936783644883, 5.460595587298136,
    5.4780974962317845, 5.4955994051654322, 5.51310131409908, 5.5306032230327276,
    5.5481051319663752, 5.5656070409000238, 5.5831089498336715,
    5.6006108587673191, 5.6181127677009668, 5.6356146766346153,
    5.653116585568263, 5.6706184945019107, 5.6881204034355584, 5.705622312369206,
    5.7231242213028546, 5.7406261302365023, 5.75812803917015, 5.7756299481037976,
    5.7931318570374462, 5.8106337659710938, 5.8281356749047415,
    5.8456375838383892, 5.8631394927720377, 5.8806414017056854,
    5.8981433106393331, 5.9156452195729807, 5.9331471285066293,
    5.950649037440277, 5.9681509463739246, 5.9856528553075723, 6.00315476424122,
    6.0206566731748685, 6.0381585821085162, 6.0556604910421639,
    6.0731623999758115, 6.09066430890946, 6.1081662178431078, 6.1256681267767554,
    6.1431700357104031, 6.1606719446440508, 6.1781738535776993,
    6.195675762511347, 6.2131776714449947, 6.2306795803786423,
    6.2481814893122909, 6.2656833982459386, 6.2831853071795862 };

  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = Sub_Sub0227_1483.getLatestMessage
    (&Sub0227_B.rtb_SourceBlock_o2_b_c);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S23>/Enable'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S23>/In1'
    Sub0227_B.In1_a = Sub0227_B.rtb_SourceBlock_o2_b_c;
  }

  // End of Start for MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // MATLAB Function: '<S3>/MATLAB Function' incorporates:
  //   DataStoreWrite: '<S3>/Data Store Write11'
  //   DataStoreWrite: '<S3>/Data Store Write13'
  //   DataStoreWrite: '<S3>/Data Store Write6'
  //   DataStoreWrite: '<S3>/Data Store Write7'
  //   DataStoreWrite: '<S3>/Data Store Write8'
  //   DataStoreWrite: '<S3>/Data Store Write9'
  //   MATLAB Function: '<S7>/vw_calculator'

  if ((Sub0227_B.In1_a.buttons[4] == 1) && (Sub0227_DW.prevButtons[4] == 0)) {
    Sub0227_DW.behaviorSwitch--;
  } else if ((Sub0227_B.In1_a.buttons[5] == 1) && (Sub0227_DW.prevButtons[5] ==
              0)) {
    Sub0227_DW.behaviorSwitch++;
  }

  if ((Sub0227_DW.behaviorSwitch >= 2.0) || rtIsNaN(Sub0227_DW.behaviorSwitch))
  {
    Sub0227_DW.behaviorSwitch = 2.0;
  }

  if (Sub0227_DW.behaviorSwitch <= 0.0) {
    Sub0227_DW.behaviorSwitch = 0.0;
  }

  if ((Sub0227_B.In1_a.axes[7] > 0.9) && (Sub0227_DW.prevAxes[7] < 0.1) &&
      (Sub0227_DW.prevAxes[7] > -0.1)) {
    Sub0227_DW.WanderVelocity += 0.1;
  } else if ((Sub0227_B.In1_a.axes[7] < -0.9) && (Sub0227_DW.prevAxes[7] < 0.1) &&
             (Sub0227_DW.prevAxes[7] > -0.1)) {
    Sub0227_DW.WanderVelocity -= 0.1;
  }

  if ((Sub0227_DW.WanderVelocity >= 1.0) || rtIsNaN(Sub0227_DW.WanderVelocity))
  {
    Sub0227_DW.WanderVelocity = 1.0;
  }

  if (Sub0227_DW.WanderVelocity <= 0.0) {
    Sub0227_DW.WanderVelocity = 0.0;
  }

  switch (static_cast<int32_T>(Sub0227_DW.behaviorSwitch)) {
   case 0:
    StateWander = 0;
    StateControl = 0;
    break;

   case 1:
    StateWander = 0;
    StateControl = 1;
    break;

   default:
    StateWander = 1;
    StateControl = 1;
    break;
  }

  memcpy(&Sub0227_DW.prevButtons[0], &Sub0227_B.In1_a.buttons[0], sizeof(int32_T)
         << 7U);
  memcpy(&Sub0227_DW.prevAxes[0], &Sub0227_B.In1_a.axes[0], sizeof(real32_T) <<
         7U);

  // End of MATLAB Function: '<S3>/MATLAB Function'

  // Switch: '<S3>/Subsume3' incorporates:
  //   Constant: '<S3>/Constant'
  //   DataStoreRead: '<S3>/Data Store Read'

  if (StateControl > 0) {
    // Switch: '<S3>/Subsume4' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read1'
    //   MATLAB Function: '<S7>/vw_calculator'
    //   Switch: '<S3>/Subsume3'

    if (StateWander > 0) {
      // Switch: '<S3>/Subsume3' incorporates:
      //   DataStoreWrite: '<S3>/Data Store Write11'
      //   Switch: '<S3>/Subsume2'

      rtb_vw_idx_0 = Sub0227_DW.WanderVelocity;
      rtb_vw_idx_1 = Sub0227_DW.WanderVelocity;
    } else {
      _mm_storeu_pd(&Sub0227_B.dv[0], _mm_mul_pd(_mm_set_pd(static_cast<real_T>
        (Sub0227_B.In1_a.axes[0]), static_cast<real_T>(Sub0227_B.In1_a.axes[1])),
        _mm_set_pd(2.0, 0.7)));
      rtb_vw_idx_0 = Sub0227_B.dv[0];
      rtb_vw_idx_1 = Sub0227_B.dv[1];
    }

    // End of Switch: '<S3>/Subsume4'
  } else {
    rtb_vw_idx_0 = 0.0;
    rtb_vw_idx_1 = 0.0;
  }

  // End of Switch: '<S3>/Subsume3'

  // MATLABSystem: '<S2>/SourceBlock'
  b_varargout_1 = Sub_Sub0227_1432.getLatestMessage
    (&Sub0227_B.rtb_SourceBlock_o2_m);

  // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // Start for MATLABSystem: '<S2>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S9>/In1'
    Sub0227_B.In1 = Sub0227_B.rtb_SourceBlock_o2_m;
  }

  // End of Start for MATLABSystem: '<S2>/SourceBlock'
  // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'
  for (StateWander = 0; StateWander < 360; StateWander++) {
    // MATLAB Function: '<S3>/lidar offset setting' incorporates:
    //   MATLAB Function: '<S21>/MATLAB Function'

    rtb_angels_0 = tmp[StateWander] + Sub0227_ConstB.Gain;

    // MATLAB Function: '<S21>/MATLAB Function'
    F_i = Sub0227_B.In1.ranges[StateWander];

    // MATLAB Function: '<S10>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S10>/Data Store Read'
    //   DataStoreRead: '<S10>/Data Store Read1'
    //   MATLAB Function: '<S21>/MATLAB Function'

    if (F_i > Sub0227_DW.max_scan) {
      F_i = (rtNaNF);
    }

    Sub0227_B.x[StateWander] = 0.0;
    Sub0227_B.b_x[StateWander] = 0.0;
    if (F_i > 0.0F) {
      F_i = static_cast<real32_T>(exp(static_cast<real_T>(static_cast<real32_T>(
        -Sub0227_DW.lambda) * F_i))) * 10.0F;
      Sub0227_B.x[StateWander] = F_i * static_cast<real32_T>(cos(rtb_angels_0));
      Sub0227_B.b_x[StateWander] = F_i * static_cast<real32_T>(sin(rtb_angels_0));
    }
  }

  // MATLAB Function: '<S10>/MATLAB Function'
  rtb_angels_0 = Sub0227_B.x[0];
  b_y = Sub0227_B.b_x[0];
  for (StateWander = 0; StateWander < 359; StateWander++) {
    _mm_storeu_pd(&Sub0227_B.dv[0], _mm_add_pd(_mm_set_pd
      (Sub0227_B.b_x[StateWander + 1], Sub0227_B.x[StateWander + 1]), _mm_set_pd
      (b_y, rtb_angels_0)));
    rtb_angels_0 = Sub0227_B.dv[0];
    b_y = Sub0227_B.dv[1];
  }

  // MATLAB Function: '<S17>/keyboard_vw' incorporates:
  //   DataStoreRead: '<S17>/Data Store Read'
  //   DataStoreRead: '<S17>/Data Store Read3'
  //   DataStoreWrite: '<S17>/Data Store Write1'
  //   DataStoreWrite: '<S17>/Data Store Write2'
  //   MATLAB Function: '<S10>/MATLAB Function'

  Sub0227_DW.v = (rtb_angels_0 * 0.01 * Sub0227_DW.k_v * 0.05 + rtb_vw_idx_0) *
    0.19999999999999996 + 0.8 * Sub0227_DW.v;
  if (!(Sub0227_DW.v <= 0.5)) {
    Sub0227_DW.v = 0.5;
  }

  if (!(Sub0227_DW.v >= -0.5)) {
    Sub0227_DW.v = -0.5;
  }

  Sub0227_DW.w = (b_y * 0.01 * Sub0227_DW.k_w * 0.05 + rtb_vw_idx_1) *
    0.19999999999999996 + 0.8 * Sub0227_DW.w;
  if (!(Sub0227_DW.w <= 1.0)) {
    Sub0227_DW.w = 1.0;
  }

  if (!(Sub0227_DW.w >= -1.0)) {
    Sub0227_DW.w = -1.0;
  }

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   MATLAB Function: '<S12>/speed limiter'
  //   MATLAB Function: '<S13>/Force to stop'
  //   MATLAB Function: '<S17>/keyboard_vw'

  Sub0227_B.BusAssignment.linear.x = Sub0227_DW.v * 0.8;
  Sub0227_B.BusAssignment.angular.z = Sub0227_DW.w * 0.8;

  // MATLAB Function: '<S13>/Force to stop' incorporates:
  //   MATLAB Function: '<S7>/vw_calculator'

  xo[0] = Sub0227_B.In1_a.buttons[0];
  xo[1] = Sub0227_B.In1_a.buttons[1];
  Sub0227_B.dv[0] = 1.0;
  Sub0227_B.dv[1] = 0.0;
  if (Sub0227_isequal(xo, Sub0227_B.dv)) {
    Sub0227_DW.stop = 0.0;
  } else {
    Sub0227_B.dv[0] = 0.0;
    Sub0227_B.dv[1] = 1.0;
    if (Sub0227_isequal(xo, Sub0227_B.dv)) {
      Sub0227_DW.stop = 1.0;
    }
  }

  if (Sub0227_DW.stop != 0.0) {
    // BusAssignment: '<Root>/Bus Assignment'
    Sub0227_B.BusAssignment.linear.x = 0.0;
    Sub0227_B.BusAssignment.angular.z = 0.0;
  }

  // DataStoreWrite: '<S3>/Data Store Write' incorporates:
  //   Constant: '<S3>/k_v'

  Sub0227_DW.k_v = 11.288224299065419;

  // DataStoreWrite: '<S3>/Data Store Write1' incorporates:
  //   Constant: '<S3>/k_w'

  Sub0227_DW.k_w = 13.43147431035171;

  // DataStoreWrite: '<S3>/Data Store Write2' incorporates:
  //   Constant: '<S3>/lambda'

  Sub0227_DW.lambda = 3.2298654636911648;

  // DataStoreWrite: '<S3>/Data Store Write3' incorporates:
  //   Constant: '<S3>/max_scan'

  Sub0227_DW.max_scan = 0.47431775700934581;

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   MATLAB Function: '<Root>/[v,w]==>geometry_msgs//Twist'

  Sub0227_B.BusAssignment.linear.y = 0.0;
  Sub0227_B.BusAssignment.linear.z = 0.0;
  Sub0227_B.BusAssignment.angular.x = 0.0;
  Sub0227_B.BusAssignment.angular.y = 0.0;

  // MATLABSystem: '<S8>/SinkBlock'
  Pub_Sub0227_1434.publish(&Sub0227_B.BusAssignment);
}

// Model initialize function
void Sub0227::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // Start for MATLABSystem: '<S6>/SourceBlock'
  Sub0227_DW.obj.QOSAvoidROSNamespaceConventions = false;
  Sub0227_DW.obj.matlabCodegenIsDeleted = false;
  Sub0227_DW.obj.isSetupComplete = false;
  Sub0227_DW.obj.isInitialized = 1;
  Sub0227_Subscriber_setupImpl_b(&Sub0227_DW.obj);
  Sub0227_DW.obj.isSetupComplete = true;

  // Start for MATLABSystem: '<S2>/SourceBlock'
  Sub0227_DW.obj_g.QOSAvoidROSNamespaceConventions = false;
  Sub0227_DW.obj_g.matlabCodegenIsDeleted = false;
  Sub0227_DW.obj_g.isSetupComplete = false;
  Sub0227_DW.obj_g.isInitialized = 1;
  Sub0227_Subscriber_setupImpl(&Sub0227_DW.obj_g);
  Sub0227_DW.obj_g.isSetupComplete = true;

  // Start for MATLABSystem: '<S8>/SinkBlock'
  Sub0227_DW.obj_n.QOSAvoidROSNamespaceConventions = false;
  Sub0227_DW.obj_n.matlabCodegenIsDeleted = false;
  Sub0227_DW.obj_n.isSetupComplete = false;
  Sub0227_DW.obj_n.isInitialized = 1;
  Sub0227_Publisher_setupImpl(&Sub0227_DW.obj_n);
  Sub0227_DW.obj_n.isSetupComplete = true;
}

// Model terminate function
void Sub0227::terminate()
{
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!Sub0227_DW.obj.matlabCodegenIsDeleted) {
    Sub0227_DW.obj.matlabCodegenIsDeleted = true;
    if ((Sub0227_DW.obj.isInitialized == 1) && Sub0227_DW.obj.isSetupComplete) {
      Sub_Sub0227_1483.resetSubscriberPtr();//();
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  if (!Sub0227_DW.obj_g.matlabCodegenIsDeleted) {
    Sub0227_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Sub0227_DW.obj_g.isInitialized == 1) &&
        Sub0227_DW.obj_g.isSetupComplete) {
      Sub_Sub0227_1432.resetSubscriberPtr();//();
    }
  }

  // End of Terminate for MATLABSystem: '<S2>/SourceBlock'

  // Terminate for MATLABSystem: '<S8>/SinkBlock'
  if (!Sub0227_DW.obj_n.matlabCodegenIsDeleted) {
    Sub0227_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Sub0227_DW.obj_n.isInitialized == 1) &&
        Sub0227_DW.obj_n.isSetupComplete) {
      Pub_Sub0227_1434.resetPublisherPtr();//();
    }
  }

  // End of Terminate for MATLABSystem: '<S8>/SinkBlock'
}

// Constructor
Sub0227::Sub0227() :
  Sub0227_B(),
  Sub0227_DW(),
  Sub0227_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
Sub0227::~Sub0227()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_Sub0227_T * Sub0227::getRTM()
{
  return (&Sub0227_M);
}

const char_T* RT_MODEL_Sub0227_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_Sub0227_T::setErrorStatus(const char_T* const volatile
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
