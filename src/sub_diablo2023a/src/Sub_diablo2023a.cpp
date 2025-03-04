//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Sub_diablo2023a.cpp
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
#include "Sub_diablo2023a.h"
#include "Sub_diablo2023a_types.h"
#include "rtwtypes.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include <math.h>
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include <stddef.h>

// Function for MATLAB Function: '<S16>/Force to stop'
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
  char_T b_zeroDelimTopic[16];
  static const char_T tmp[15] = { '/', 'x', 'b', 'o', 'x', '_', 'j', 'o', 'y',
    '_', 's', 't', 'a', 't', 'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 15; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[15] = '\x00';
  Sub_Sub_diablo2023a_1483.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
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

void Sub_diablo2023a::Sub_diablo2_SystemCore_setup_p3
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

void Sub_diablo2023a::Sub_diablo_SystemCore_setup_p3p
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[12];
  static const char_T tmp[11] = { '/', 'c', 'u', 's', 't', 'o', 'm', '_', 'v',
    'e', 'l' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 11; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[11] = '\x00';
  Sub_Sub_diablo2023a_1887.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void Sub_diablo2023a::step()
{
  real_T b_y;
  real_T pitch;
  real_T roll;
  real_T up;
  int32_T xo[2];
  int32_T StateControl;
  int32_T StateWander;
  real32_T F_i;
  boolean_T height_ctrl_mode;
  boolean_T mode_mark;
  boolean_T pitch_ctrl_mode;
  boolean_T roll_ctrl_mode;
  static const real_T tmp[720] = { -3.1241390705, -3.1154245617218361,
    -3.1067100529436718, -3.0979955441655078, -3.0892810353873434,
    -3.0805665266091795, -3.0718520178310156, -3.0631375090528512,
    -3.0544230002746873, -3.0457084914965229, -3.036993982718359,
    -3.0282794739401946, -3.0195649651620307, -3.0108504563838667,
    -3.0021359476057023, -2.9934214388275384, -2.984706930049374,
    -2.97599242127121, -2.9672779124930457, -2.9585634037148818,
    -2.9498488949367179, -2.9411343861585535, -2.9324198773803896,
    -2.9237053686022252, -2.9149908598240613, -2.9062763510458973,
    -2.8975618422677329, -2.888847333489569, -2.8801328247114046,
    -2.8714183159332407, -2.8627038071550768, -2.8539892983769124,
    -2.8452747895987485, -2.8365602808205841, -2.82784577204242,
    -2.8191312632642558, -2.8104167544860919, -2.8017022457079275,
    -2.7929877369297635, -2.7842732281515996, -2.7755587193734352,
    -2.7668442105952713, -2.7581297018171069, -2.749415193038943,
    -2.7407006842607791, -2.7319861754826147, -2.7232716667044508,
    -2.7145571579262864, -2.7058426491481224, -2.6971281403699585,
    -2.6884136315917941, -2.67969912281363, -2.6709846140354658,
    -2.6622701052573019, -2.6535555964791375, -2.6448410877009736,
    -2.6361265789228097, -2.6274120701446453, -2.6186975613664814,
    -2.609983052588317, -2.601268543810153, -2.5925540350319887,
    -2.5838395262538247, -2.5751250174756608, -2.5664105086974964,
    -2.5576959999193325, -2.5489814911411681, -2.5402669823630042,
    -2.5315524735848403, -2.5228379648066759, -2.5141234560285119,
    -2.5054089472503476, -2.4966944384721836, -2.4879799296940197,
    -2.4792654209158553, -2.4705509121376914, -2.461836403359527,
    -2.4531218945813631, -2.4444073858031992, -2.4356928770250348,
    -2.4269783682468704, -2.4182638594687065, -2.4095493506905425,
    -2.4008348419123782, -2.3921203331342142, -2.38340582435605,
    -2.3746913155778859, -2.365976806799722, -2.3572622980215576,
    -2.3485477892433937, -2.3398332804652293, -2.3311187716870654,
    -2.3224042629089015, -2.3136897541307371, -2.3049752453525731,
    -2.2962607365744088, -2.2875462277962448, -2.2788317190180809,
    -2.2701172102399165, -2.2614027014617522, -2.2526881926835882,
    -2.2439736839054243, -2.23525917512726, -2.226544666349096,
    -2.2178301575709316, -2.2091156487927677, -2.2004011400146037,
    -2.1916866312364394, -2.1829721224582754, -2.1742576136801111,
    -2.1655431049019471, -2.1568285961237832, -2.1481140873456188,
    -2.1393995785674549, -2.1306850697892905, -2.1219705610111266,
    -2.1132560522329626, -2.1045415434547983, -2.0958270346766339,
    -2.08711252589847, -2.078398017120306, -2.0696835083421421,
    -2.0609689995639777, -2.0522544907858133, -2.0435399820076494,
    -2.0348254732294855, -2.0261109644513215, -2.0173964556731572,
    -2.0086819468949928, -1.9999674381168289, -1.9912529293386647,
    -1.9825384205605006, -1.9738239117823366, -1.9651094030041725,
    -1.9563948942260083, -1.9476803854478442, -1.93896587666968,
    -1.9302513678915159, -1.9215368591133519, -1.9128223503351878,
    -1.9041078415570236, -1.8953933327788595, -1.8866788240006953,
    -1.8779643152225312, -1.8692498064443672, -1.8605352976662031,
    -1.8518207888880389, -1.8431062801098748, -1.8343917713317106,
    -1.8256772625535465, -1.8169627537753825, -1.8082482449972184,
    -1.7995337362190542, -1.79081922744089, -1.7821047186627259,
    -1.7733902098845618, -1.7646757011063978, -1.7559611923282337,
    -1.7472466835500695, -1.7385321747719054, -1.7298176659937412,
    -1.7211031572155771, -1.7123886484374131, -1.703674139659249,
    -1.6949596308810848, -1.6862451221029207, -1.6775306133247565,
    -1.6688161045465923, -1.6601015957684284, -1.6513870869902643,
    -1.6426725782121, -1.633958069433936, -1.6252435606557718,
    -1.6165290518776076, -1.6078145430994437, -1.5991000343212796,
    -1.5903855255431154, -1.5816710167649513, -1.5729565079867871,
    -1.5642419992086229, -1.555527490430459, -1.5468129816522949,
    -1.5380984728741307, -1.5293839640959666, -1.5206694553178024,
    -1.5119549465396382, -1.5032404377614743, -1.4945259289833102,
    -1.485811420205146, -1.4770969114269819, -1.4683824026488177,
    -1.4596678938706535, -1.4509533850924896, -1.4422388763143255,
    -1.4335243675361613, -1.4248098587579971, -1.416095349979833,
    -1.4073808412016688, -1.3986663324235047, -1.3899518236453408,
    -1.3812373148671766, -1.3725228060890124, -1.3638082973108483,
    -1.3550937885326841, -1.34637927975452, -1.3376647709763561,
    -1.3289502621981919, -1.3202357534200277, -1.3115212446418636,
    -1.3028067358636994, -1.2940922270855353, -1.2853777183073714,
    -1.2766632095292072, -1.267948700751043, -1.2592341919728789,
    -1.2505196831947147, -1.2418051744165506, -1.2330906656383867,
    -1.2243761568602225, -1.2156616480820583, -1.2069471393038942,
    -1.19823263052573, -1.1895181217475659, -1.180803612969402,
    -1.1720891041912378, -1.1633745954130736, -1.1546600866349095,
    -1.1459455778567453, -1.1372310690785812, -1.1285165603004172,
    -1.1198020515222531, -1.1110875427440887, -1.1023730339659248,
    -1.0936585251877609, -1.0849440164095965, -1.0762295076314325,
    -1.0675149988532682, -1.0588004900751042, -1.0500859812969403,
    -1.0413714725187759, -1.032656963740612, -1.0239424549624476,
    -1.0152279461842837, -1.0065134374061193, -0.99779892862795538,
    -0.98908441984979145, -0.98036991107162708, -0.97165540229346314,
    -0.96294089351529877, -0.95422638473713484, -0.9455118759589709,
    -0.93679736718080653, -0.9280828584026426, -0.91936834962447822,
    -0.91065384084631429, -0.90193933206814991, -0.893224823289986,
    -0.884510314511822, -0.87579580573365767, -0.86708129695549374,
    -0.85836678817732937, -0.84965227939916543, -0.84093777062100106,
    -0.83222326184283713, -0.82350875306467319, -0.81479424428650882,
    -0.80607973550834489, -0.79736522673018051, -0.78865071795201658,
    -0.77993620917385265, -0.77122170039568827, -0.76250719161752434,
    -0.75379268283936, -0.745078174061196, -0.73636366528303165,
    -0.72764915650486772, -0.71893464772670379, -0.71022013894853941,
    -0.70150563017037548, -0.69279112139221111, -0.68407661261404717,
    -0.67536210383588324, -0.66664759505771887, -0.65793308627955494,
    -0.64921857750139056, -0.64050406872322663, -0.63178955994506225,
    -0.62307505116689832, -0.61436054238873439, -0.60564603361057,
    -0.59693152483240608, -0.5882170160542417, -0.57950250727607777,
    -0.57078799849791384, -0.56207348971974946, -0.55335898094158553,
    -0.54464447216342116, -0.53592996338525722, -0.52721545460709285,
    -0.51850094582892892, -0.509786437050765, -0.50107192827260061,
    -0.49235741949443668, -0.4836429107162723, -0.47492840193810837,
    -0.46621389315994444, -0.45749938438178006, -0.44878487560361613,
    -0.44007036682545175, -0.43135585804728782, -0.42264134926912345,
    -0.41392684049095951, -0.40521233171279558, -0.39649782293463121,
    -0.38778331415646727, -0.3790688053783029, -0.37035429660013897,
    -0.36163978782197503, -0.35292527904381066, -0.34421077026564673,
    -0.33549626148748235, -0.32678175270931842, -0.31806724393115404,
    -0.30935273515299011, -0.30063822637482618, -0.2919237175966618,
    -0.28320920881849787, -0.27449470004033349, -0.26578019126216956,
    -0.25706568248400519, -0.24835117370584125, -0.23963666492767732,
    -0.23092215614951295, -0.22220764737134902, -0.21349313859318464,
    -0.20477862981502071, -0.19606412103685678, -0.1873496122586924,
    -0.17863510348052847, -0.16992059470236409, -0.16120608592420016,
    -0.15249157714603578, -0.14377706836787185, -0.13506255958970792,
    -0.12634805081154354, -0.11763354203337961, -0.10891903325521524,
    -0.1002045244770513, -0.091490015698887373, -0.082775506920723,
    -0.074060998142559065, -0.065346489364394689, -0.056631980586230757,
    -0.047917471808066381, -0.039202963029902449, -0.030488454251738517,
    -0.021773945473574141, -0.013059436695410209, -0.0043449279172458333,
    0.0043695808609180986, 0.01308408963908203, 0.021798598417245962,
    0.030513107195410338, 0.03922761597357427, 0.047942124751738646,
    0.056656633529902578, 0.06537114230806651, 0.074085651086230886,
    0.082800159864394818, 0.0915146686425592, 0.10022917742072313,
    0.1089436861988875, 0.11765819497705143, 0.12637270375521537,
    0.13508721253337974, 0.14380172131154367, 0.15251623008970805,
    0.16123073886787198, 0.16994524764603591, 0.17865975642420029,
    0.18737426520236422, 0.1960887739805286, 0.20480328275869253,
    0.2135177915368569, 0.22223230031502084, 0.23094680909318477,
    0.23966131787134914, 0.24837582664951308, 0.25709033542767745,
    0.26580484420584138, 0.27451935298400532, 0.28323386176216969,
    0.29194837054033362, 0.300662879318498, 0.30937738809666193,
    0.31809189687482631, 0.32680640565299024, 0.33552091443115417,
    0.34423542320931855, 0.35294993198748248, 0.36166444076564686,
    0.37037894954381079, 0.37909345832197516, 0.38780796710013909,
    0.396522475878303, 0.4052369846564674, 0.41395149343463133,
    0.42266600221279571, 0.43138051099095964, 0.44009501976912357,
    0.44880952854728795, 0.45752403732545188, 0.46623854610361626,
    0.47495305488178019, 0.48366756365994457, 0.4923820724381085,
    0.50109658121627243, 0.50981108999443681, 0.51852559877260074,
    0.52724010755076511, 0.535954616328929, 0.544669125107093,
    0.55338363388525735, 0.56209814266342129, 0.57081265144158566,
    0.57952716021974959, 0.588241668997914, 0.5969561777760779,
    0.60567068655424183, 0.61438519533240621, 0.62309970411057014,
    0.63181421288873452, 0.64052872166689845, 0.64924323044506238,
    0.65795773922322676, 0.66667224800139069, 0.67538675677955506,
    0.684101265557719, 0.69281577433588337, 0.7015302831140473,
    0.71024479189221124, 0.71895930067037561, 0.72767380944853954,
    0.73638831822670392, 0.74510282700486785, 0.75381733578303178,
    0.76253184456119616, 0.77124635333936009, 0.77996086211752447,
    0.7886753708956884, 0.79738987967385277, 0.80610438845201671,
    0.81481889723018064, 0.823533406008345, 0.832247914786509,
    0.84096242356467332, 0.84967693234283725, 0.85839144112100119,
    0.86710594989916556, 0.87582045867732949, 0.88453496745549387,
    0.8932494762336578, 0.90196398501182218, 0.91067849378998611,
    0.91939300256815, 0.92810751134631442, 0.93682202012447835,
    0.94553652890264273, 0.95425103768080666, 0.962965546458971,
    0.971680055237135, 0.9803945640152989, 0.98910907279346327,
    0.99782358157162721, 1.0065380903497916, 1.0152525991279555,
    1.0239671079061194, 1.0326816166842838, 1.0413961254624478,
    1.0501106342406121, 1.0588251430187761, 1.0675396517969404,
    1.0762541605751044, 1.0849686693532683, 1.0936831781314327,
    1.1023976869095966, 1.111112195687761, 1.1198267044659249,
    1.1285412132440888, 1.1372557220222532, 1.1459702308004174,
    1.1546847395785813, 1.1633992483567455, 1.1721137571349096,
    1.1808282659130738, 1.1895427746912379, 1.1982572834694021,
    1.206971792247566, 1.2156863010257302, 1.2244008098038943,
    1.2331153185820585, 1.2418298273602226, 1.2505443361383868,
    1.2592588449165507, 1.2679733536947149, 1.276687862472879,
    1.2854023712510432, 1.2941168800292073, 1.3028313888073715,
    1.3115458975855354, 1.3202604063636996, 1.3289749151418637,
    1.3376894239200279, 1.346403932698192, 1.3551184414763562,
    1.3638329502545201, 1.3725474590326843, 1.3812619678108484,
    1.3899764765890126, 1.3986909853671767, 1.4074054941453409,
    1.4161200029235048, 1.424834511701669, 1.4335490204798331,
    1.4422635292579973, 1.4509780380361614, 1.4596925468143256,
    1.4684070555924897, 1.4771215643706537, 1.4858360731488178,
    1.494550581926982, 1.5032650907051461, 1.5119795994833103,
    1.5206941082614744, 1.5294086170396384, 1.5381231258178025,
    1.5468376345959667, 1.5555521433741308, 1.564266652152295,
    1.5729811609304591, 1.5816956697086231, 1.5904101784867872,
    1.5991246872649514, 1.6078391960431155, 1.6165537048212797,
    1.6252682135994438, 1.6339827223776078, 1.6426972311557719,
    1.6514117399339361, 1.6601262487121002, 1.6688407574902644,
    1.6775552662684285, 1.6862697750465925, 1.6949842838247566,
    1.7036987926029208, 1.7124133013810849, 1.7211278101592491,
    1.7298423189374132, 1.7385568277155772, 1.7472713364937413,
    1.7559858452719055, 1.7647003540500696, 1.7734148628282338,
    1.7821293716063979, 1.7908438803845619, 1.799558389162726,
    1.8082728979408902, 1.8169874067190543, 1.8257019154972185,
    1.8344164242753827, 1.8431309330535466, 1.8518454418317107,
    1.8605599506098749, 1.869274459388039, 1.8779889681662032,
    1.8867034769443674, 1.8954179857225313, 1.9041324945006954,
    1.9128470032788596, 1.9215615120570237, 1.9302760208351879,
    1.9389905296133521, 1.947705038391516, 1.9564195471696801,
    1.9651340559478443, 1.9738485647260084, 1.9825630735041726,
    1.9912775822823368, 1.9999920910605007, 2.0087065998386651,
    2.017421108616829, 2.0261356173949929, 2.0348501261731573,
    2.0435646349513217, 2.0522791437294856, 2.0609936525076495,
    2.0697081612858135, 2.0784226700639779, 2.0871371788421422,
    2.0958516876203062, 2.10456619639847, 2.113280705176634, 2.1219952139547984,
    2.1307097227329628, 2.1394242315111267, 2.1481387402892906,
    2.156853249067455, 2.1655677578456189, 2.1742822666237833,
    2.1829967754019473, 2.1917112841801112, 2.2004257929582756,
    2.2091403017364395, 2.2178548105146039, 2.2265693192927678,
    2.2352838280709317, 2.2439983368490961, 2.25271284562726, 2.2614273544054244,
    2.2701418631835883, 2.2788563719617523, 2.2875708807399167,
    2.296285389518081, 2.304999898296245, 2.3137144070744089, 2.3224289158525733,
    2.3311434246307372, 2.3398579334089016, 2.3485724421870655,
    2.3572869509652294, 2.3660014597433938, 2.3747159685215578,
    2.3834304772997221, 2.3921449860778861, 2.40085949485605, 2.4095740036342144,
    2.4182885124123783, 2.4270030211905427, 2.4357175299687066,
    2.4444320387468705, 2.4531465475250349, 2.4618610563031993,
    2.4705755650813632, 2.4792900738595272, 2.4880045826376915,
    2.4967190914158555, 2.50543360019402, 2.5141481089721838, 2.5228626177503477,
    2.5315771265285121, 2.540291635306676, 2.5490061440848404,
    2.5577206528630043, 2.5664351616411682, 2.5751496704193326,
    2.5838641791974966, 2.5925786879756609, 2.6012931967538249,
    2.6100077055319888, 2.6187222143101532, 2.6274367230883171,
    2.6361512318664815, 2.6448657406446454, 2.65358024942281, 2.6622947582009737,
    2.6710092669791377, 2.679723775757302, 2.688438284535466, 2.6971527933136303,
    2.7058673020917943, 2.7145818108699586, 2.7232963196481226,
    2.7320108284262865, 2.7407253372044509, 2.7494398459826148,
    2.7581543547607792, 2.7668688635389431, 2.7755833723171071,
    2.7842978810952714, 2.7930123898734354, 2.8017268986515997,
    2.8104414074297637, 2.8191559162079276, 2.827870424986092,
    2.8365849337642559, 2.8452994425424203, 2.8540139513205842,
    2.8627284600987486, 2.8714429688769125, 2.8801574776550769,
    2.8888719864332408, 2.8975864952114048, 2.9063010039895691,
    2.9150155127677331, 2.9237300215458975, 2.9324445303240614,
    2.9411590391022253, 2.9498735478803897, 2.9585880566585536,
    2.967302565436718, 2.9760170742148819, 2.9847315829930459,
    2.9934460917712102, 3.0021606005493742, 3.0108751093275385,
    3.0195896181057025, 3.0283041268838669, 3.0370186356620308,
    3.0457331444401947, 3.0544476532183591, 3.063162161996523,
    3.0718766707746874, 3.0805911795528513, 3.0893056883310157,
    3.0980201971091796, 3.1067347058873436, 3.1154492146655079,
    3.1241637234436719, 3.1328782322218363, 3.141592741 };

  // MATLABSystem: '<S6>/SourceBlock'
  mode_mark = Sub_Sub_diablo2023a_1483.getLatestMessage
    (&Sub_diablo2023a_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S25>/Enable'

  if (mode_mark) {
    // SignalConversion generated from: '<S25>/In1'
    Sub_diablo2023a_B.In1_a = Sub_diablo2023a_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // MATLAB Function: '<S3>/Behavior Switcher' incorporates:
  //   DataStoreRead: '<S3>/Data Store Read6'
  //   DataStoreRead: '<S3>/Data Store Read7'
  //   DataStoreWrite: '<S3>/Data Store Write11'
  //   DataStoreWrite: '<S3>/Data Store Write13'
  //   DataStoreWrite: '<S3>/Data Store Write6'
  //   DataStoreWrite: '<S3>/Data Store Write7'
  //   DataStoreWrite: '<S3>/Data Store Write8'
  //   DataStoreWrite: '<S3>/Data Store Write9'
  //   MATLAB Function: '<S8>/vw_calculator'

  up = Sub_diablo2023a_DW.value[0];
  roll = Sub_diablo2023a_DW.value[1];
  pitch = Sub_diablo2023a_DW.value[2];
  mode_mark = Sub_diablo2023a_DW.mode[0];
  pitch_ctrl_mode = Sub_diablo2023a_DW.mode[1];
  roll_ctrl_mode = Sub_diablo2023a_DW.mode[2];
  height_ctrl_mode = Sub_diablo2023a_DW.mode[3];
  if ((Sub_diablo2023a_B.In1_a.buttons[4] == 1) &&
      (Sub_diablo2023a_DW.prevButtons[4] == 0)) {
    Sub_diablo2023a_DW.behaviorSwitch--;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[5] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[5] == 0)) {
    Sub_diablo2023a_DW.behaviorSwitch++;
  }

  if ((Sub_diablo2023a_DW.behaviorSwitch >= 2.0) || rtIsNaN
      (Sub_diablo2023a_DW.behaviorSwitch)) {
    Sub_diablo2023a_DW.behaviorSwitch = 2.0;
  }

  if (Sub_diablo2023a_DW.behaviorSwitch <= 0.0) {
    Sub_diablo2023a_DW.behaviorSwitch = 0.0;
  }

  if ((Sub_diablo2023a_B.In1_a.axes[7] > 0.9) && (Sub_diablo2023a_DW.prevAxes[7]
       < 0.1) && (Sub_diablo2023a_DW.prevAxes[7] > -0.1)) {
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

  switch (static_cast<int32_T>(Sub_diablo2023a_DW.behaviorSwitch)) {
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

  if ((Sub_diablo2023a_B.In1_a.buttons[11] == 1) &&
      (Sub_diablo2023a_DW.prevButtons[11] == 0)) {
    pitch_ctrl_mode = true;
    roll_ctrl_mode = true;
    mode_mark = false;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[11] == 0) &&
             (Sub_diablo2023a_DW.prevButtons[11] == 1)) {
    pitch_ctrl_mode = false;
    roll_ctrl_mode = false;
    mode_mark = false;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[12] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[12] == 0)) {
    height_ctrl_mode = true;
    mode_mark = false;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[12] == 0) &&
             (Sub_diablo2023a_DW.prevButtons[12] == 1)) {
    height_ctrl_mode = false;
    mode_mark = false;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[2] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[2] == 0)) {
    Sub_diablo2023a_DW.mode[4] = true;
    mode_mark = false;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[3] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[3] == 0)) {
    Sub_diablo2023a_DW.mode[4] = false;
    mode_mark = false;
  } else if ((Sub_diablo2023a_B.In1_a.buttons[11] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[11] == 0) &&
             (Sub_diablo2023a_B.In1_a.buttons[12] == 1) &&
             (Sub_diablo2023a_DW.prevButtons[12] == 0)) {
    pitch = 0.0;
    roll = 0.0;
    pitch_ctrl_mode = false;
    roll_ctrl_mode = false;
    mode_mark = false;
  }

  if (pitch_ctrl_mode) {
    if ((Sub_diablo2023a_B.In1_a.axes[4] >= 1.0F) || rtIsNaNF
        (Sub_diablo2023a_B.In1_a.axes[4])) {
      F_i = 1.0F;
    } else {
      F_i = Sub_diablo2023a_B.In1_a.axes[4];
    }

    if (F_i <= -1.0F) {
      F_i = -1.0F;
    }

    pitch = F_i / 2.0;
  }

  if (roll_ctrl_mode) {
    if ((Sub_diablo2023a_B.In1_a.axes[3] >= 1.0F) || rtIsNaNF
        (Sub_diablo2023a_B.In1_a.axes[3])) {
      F_i = 1.0F;
    } else {
      F_i = Sub_diablo2023a_B.In1_a.axes[3];
    }

    if (F_i <= -1.0F) {
      F_i = -1.0F;
    }

    roll = F_i / 10.0;
  }

  if (height_ctrl_mode) {
    if ((Sub_diablo2023a_B.In1_a.axes[6] > 0.9) && (Sub_diablo2023a_DW.prevAxes
         [6] < 0.1) && (Sub_diablo2023a_DW.prevAxes[6] > -0.1)) {
      up = Sub_diablo2023a_DW.value[0] - 0.1;
    } else if ((Sub_diablo2023a_B.In1_a.axes[6] < -0.9) &&
               (Sub_diablo2023a_DW.prevAxes[6] < 0.1) &&
               (Sub_diablo2023a_DW.prevAxes[6] > -0.1)) {
      up = Sub_diablo2023a_DW.value[0] + 0.1;
    }

    if ((up >= 1.0) || rtIsNaN(up)) {
      up = 1.0;
    }

    if (up <= -0.1) {
      up = -0.1;
    }
  }

  memcpy(&Sub_diablo2023a_DW.prevButtons[0], &Sub_diablo2023a_B.In1_a.buttons[0],
         sizeof(int32_T) << 7U);
  memcpy(&Sub_diablo2023a_DW.prevAxes[0], &Sub_diablo2023a_B.In1_a.axes[0],
         sizeof(real32_T) << 7U);
  Sub_diablo2023a_DW.value[0] = up;
  Sub_diablo2023a_DW.value[1] = roll;
  Sub_diablo2023a_DW.value[2] = pitch;
  Sub_diablo2023a_DW.mode[0] = mode_mark;
  Sub_diablo2023a_DW.mode[1] = pitch_ctrl_mode;
  Sub_diablo2023a_DW.mode[2] = roll_ctrl_mode;
  Sub_diablo2023a_DW.mode[3] = height_ctrl_mode;

  // End of MATLAB Function: '<S3>/Behavior Switcher'

  // Switch: '<S3>/Subsume3' incorporates:
  //   Constant: '<S3>/Constant'
  //   DataStoreRead: '<S3>/Data Store Read'

  if (StateControl > 0) {
    // Switch: '<S3>/Subsume4' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read1'

    if (StateWander > 0) {
      // Switch: '<S3>/Subsume3' incorporates:
      //   DataStoreWrite: '<S3>/Data Store Write11'
      //   Switch: '<S3>/Subsume2'

      up = Sub_diablo2023a_DW.WanderVelocity;
      roll = Sub_diablo2023a_DW.WanderVelocity;
    } else {
      // Switch: '<S3>/Subsume3' incorporates:
      //   MATLAB Function: '<S8>/vw_calculator'

      up = Sub_diablo2023a_B.In1_a.axes[1] * 0.7;
      roll = Sub_diablo2023a_B.In1_a.axes[0] * 2.0;
    }

    // End of Switch: '<S3>/Subsume4'
  } else {
    up = 0.0;
    roll = 0.0;
  }

  // End of Switch: '<S3>/Subsume3'

  // MATLABSystem: '<S2>/SourceBlock'
  mode_mark = Sub_Sub_diablo2023a_1432.getLatestMessage
    (&Sub_diablo2023a_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (mode_mark) {
    // SignalConversion generated from: '<S12>/In1'
    Sub_diablo2023a_B.In1 = Sub_diablo2023a_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S2>/SourceBlock'
  // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'
  for (StateWander = 0; StateWander < 720; StateWander++) {
    // MATLAB Function: '<S3>/lidar offset setting' incorporates:
    //   MATLAB Function: '<S4>/MATLAB Function'

    pitch = tmp[StateWander];

    // MATLAB Function: '<S4>/MATLAB Function'
    F_i = Sub_diablo2023a_B.In1.ranges[StateWander];

    // MATLAB Function: '<S14>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S14>/Data Store Read'
    //   DataStoreRead: '<S14>/Data Store Read1'
    //   MATLAB Function: '<S4>/MATLAB Function'

    if (F_i > Sub_diablo2023a_DW.max_scan) {
      F_i = (rtNaNF);
    }

    Sub_diablo2023a_B.x[StateWander] = 0.0;
    Sub_diablo2023a_B.b_x[StateWander] = 0.0;
    if (F_i > 0.0F) {
      F_i = static_cast<real32_T>(exp(static_cast<real_T>(static_cast<real32_T>(
        -Sub_diablo2023a_DW.lambda) * F_i))) * 10.0F;
      Sub_diablo2023a_B.x[StateWander] = F_i * static_cast<real32_T>(cos(pitch));
      Sub_diablo2023a_B.b_x[StateWander] = F_i * static_cast<real32_T>(sin(pitch));
    }
  }

  // MATLAB Function: '<S14>/MATLAB Function'
  pitch = Sub_diablo2023a_B.x[0];
  b_y = Sub_diablo2023a_B.b_x[0];
  for (StateWander = 0; StateWander < 719; StateWander++) {
    pitch += Sub_diablo2023a_B.x[StateWander + 1];
    b_y += Sub_diablo2023a_B.b_x[StateWander + 1];
  }

  // MATLAB Function: '<S20>/keyboard_vw' incorporates:
  //   DataStoreRead: '<S20>/Data Store Read'
  //   DataStoreRead: '<S20>/Data Store Read3'
  //   DataStoreWrite: '<S20>/Data Store Write1'
  //   DataStoreWrite: '<S20>/Data Store Write2'
  //   MATLAB Function: '<S14>/MATLAB Function'

  Sub_diablo2023a_DW.v = (pitch * 0.01 * Sub_diablo2023a_DW.k_v * 0.05 + up) *
    0.19999999999999996 + 0.8 * Sub_diablo2023a_DW.v;
  if (!(Sub_diablo2023a_DW.v <= 0.5)) {
    Sub_diablo2023a_DW.v = 0.5;
  }

  if (!(Sub_diablo2023a_DW.v >= -0.5)) {
    Sub_diablo2023a_DW.v = -0.5;
  }

  Sub_diablo2023a_DW.w = (b_y * 0.01 * Sub_diablo2023a_DW.k_w * 0.05 + roll) *
    0.19999999999999996 + 0.8 * Sub_diablo2023a_DW.w;
  if (!(Sub_diablo2023a_DW.w <= 1.0)) {
    Sub_diablo2023a_DW.w = 1.0;
  }

  if (!(Sub_diablo2023a_DW.w >= -1.0)) {
    Sub_diablo2023a_DW.w = -1.0;
  }

  up = Sub_diablo2023a_DW.v;
  roll = Sub_diablo2023a_DW.w;

  // End of MATLAB Function: '<S20>/keyboard_vw'

  // MATLAB Function: '<S16>/Force to stop' incorporates:
  //   MATLAB Function: '<S8>/vw_calculator'

  xo[0] = Sub_diablo2023a_B.In1_a.buttons[0];
  xo[1] = Sub_diablo2023a_B.In1_a.buttons[1];
  Sub_diablo2023a_B.dv[0] = 1.0;
  Sub_diablo2023a_B.dv[1] = 0.0;
  if (Sub_diablo2023a_isequal(xo, Sub_diablo2023a_B.dv)) {
    Sub_diablo2023a_DW.stop = 0.0;
  } else {
    Sub_diablo2023a_B.dv[0] = 0.0;
    Sub_diablo2023a_B.dv[1] = 1.0;
    if (Sub_diablo2023a_isequal(xo, Sub_diablo2023a_B.dv)) {
      Sub_diablo2023a_DW.stop = 1.0;
    }
  }

  if (Sub_diablo2023a_DW.stop != 0.0) {
    up = 0.0;
    roll = 0.0;
  }

  // End of MATLAB Function: '<S16>/Force to stop'

  // DataStoreWrite: '<S3>/Data Store Write' incorporates:
  //   Constant: '<S3>/k_v'

  Sub_diablo2023a_DW.k_v = 11.288224299065419;

  // DataStoreWrite: '<S3>/Data Store Write1' incorporates:
  //   Constant: '<S3>/k_w'

  Sub_diablo2023a_DW.k_w = 12.430340557275541;

  // DataStoreWrite: '<S3>/Data Store Write2' incorporates:
  //   Constant: '<S3>/lambda'

  Sub_diablo2023a_DW.lambda = 2.1934984520123839;

  // DataStoreWrite: '<S3>/Data Store Write3' incorporates:
  //   Constant: '<S3>/max_scan'

  Sub_diablo2023a_DW.max_scan = 0.7;

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   MATLAB Function: '<Root>/[v,w]==>MotionCmd'
  //   MATLAB Function: '<Root>/mode reader'

  memset(&Sub_diablo2023a_B.BusAssignment, 0, sizeof
         (SL_Bus_motion_msgs_MotionCtrl));
  Sub_diablo2023a_B.BusAssignment.value.forward = up;
  Sub_diablo2023a_B.BusAssignment.value.left = roll;
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

  // MATLABSystem: '<S10>/SinkBlock'
  Pub_Sub_diablo2023a_1882.publish(&Sub_diablo2023a_B.BusAssignment);

  // MATLABSystem: '<S11>/SourceBlock'
  Sub_Sub_diablo2023a_1887.getLatestMessage(&Sub_diablo2023a_B.b_varargout_2_c);
}

// Model initialize function
void Sub_diablo2023a::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // Start for MATLABSystem: '<S6>/SourceBlock'
  Sub_diablo20_SystemCore_setup_p(&Sub_diablo2023a_DW.obj_e);

  // Start for MATLABSystem: '<S2>/SourceBlock'
  Sub_diablo2023_SystemCore_setup(&Sub_diablo2023a_DW.obj_g);

  // Start for MATLABSystem: '<S10>/SinkBlock'
  Sub_diablo2_SystemCore_setup_p3(&Sub_diablo2023a_DW.obj_a);

  // Start for MATLABSystem: '<S11>/SourceBlock'
  Sub_diablo_SystemCore_setup_p3p(&Sub_diablo2023a_DW.obj);
}

// Model terminate function
void Sub_diablo2023a::terminate()
{
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!Sub_diablo2023a_DW.obj_e.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  if (!Sub_diablo2023a_DW.obj_g.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SourceBlock'

  // Terminate for MATLABSystem: '<S10>/SinkBlock'
  if (!Sub_diablo2023a_DW.obj_a.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SinkBlock'

  // Terminate for MATLABSystem: '<S11>/SourceBlock'
  if (!Sub_diablo2023a_DW.obj.matlabCodegenIsDeleted) {
    Sub_diablo2023a_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/SourceBlock'
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
