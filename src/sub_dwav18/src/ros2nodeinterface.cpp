
//
// File ros2nodeinterface.cpp
//
// Code generated for Simulink model 'SUB_DWAV18'.
//
// Model version                  : 12.161
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Jun 05 02:24:59 2025
//
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
#include "SUB_DWAV18.h"
#include "ros2nodeinterface.h"
#include <thread>
#include <chrono>
#include <utility>
const std::string SLROSNodeName("SUB_DWAV18");
extern rclcpp::Node::SharedPtr SLROSNodePtr;
namespace ros2 {
namespace matlab {
NodeInterface::NodeInterface()
    : mModel()
    , mExec()
    , mBaseRateSem()
    , mBaseRateThread()
    , mSchedulerTimer()
    , mSubRate1Sem()
    , mSubRate1Thread()
    , mStopSem()
    , mRunModel(true){
  }
NodeInterface::~NodeInterface() {
    terminate();
  }
void NodeInterface::initialize(int argc, char * const argv[]) {
    try {
        //initialize ros2
        std::vector<char *> args(argv, argv + argc);
        rclcpp::init(static_cast<int>(args.size()), args.data());
        //create the Node specified in Model
        std::string NodeName("SUB_DWAV18");
        SLROSNodePtr = std::make_shared<rclcpp::Node>(NodeName);
        RCLCPP_INFO(SLROSNodePtr->get_logger(),"** Starting the model \"SUB_DWAV18\" **\n");
        mExec = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
        mExec->add_node(SLROSNodePtr);
        //initialize the model which will initialize the publishers and subscribers
        mModel = std::make_shared<SUB_DWAV18>(
        );
		rtmSetErrorStatus(mModel->getRTM(), (NULL));
        mModel->initialize();
        //create the threads for the rates in the Model
        mBaseRateThread = std::make_shared<std::thread>(&NodeInterface::baseRateTask, this);
            mSubRate1Thread = std::make_shared<std::thread>(&NodeInterface::subRate1Task, this);
		mSchedulerTimer = SLROSNodePtr->create_wall_timer(std::chrono::nanoseconds(50000000),std::bind(&NodeInterface::schedulerThreadCallback,this));
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        throw ex;
    }
    catch (...) {
        std::cout << "Unknown exception" << std::endl;
        throw;
    }
}
int NodeInterface::run() {
  if (mExec) {
    mExec->spin();
  }
  mRunModel = false;
  return 0;
}
boolean_T NodeInterface::getStopRequestedFlag(void) {
    #ifndef rtmGetStopRequested
    return (!(rtmGetErrorStatus(mModel->getRTM())
        == (NULL)));
    #else
    return (!(rtmGetErrorStatus(mModel->getRTM())
        == (NULL)) || rtmGetStopRequested(mModel->getRTM()));
    #endif
}
void NodeInterface::stop(void) {
  if (mExec.get()) {
    mExec->cancel();
    if (SLROSNodePtr) {
      mExec->remove_node(SLROSNodePtr);
    }
    while (mExec.use_count() > 1);
  }
}
void NodeInterface::terminate(void) {
    if (mBaseRateThread.get()) {
        mRunModel = false;
        mBaseRateSem.notify(); // break out wait
        mBaseRateThread->join();
        if (mSchedulerTimer.get()) {
	        mSchedulerTimer->cancel();
    	    mSchedulerTimer->reset();
        }
        mSubRate1Sem.notify();
        mSubRate1Thread->join();
        mSubRate1Thread.reset();
        mBaseRateThread.reset();
        if (mModel.get()) {
            mModel->terminate();
        }
        mModel.reset();
        mExec.reset();
        SLROSNodePtr.reset();
        rclcpp::shutdown();
    }
}
//
// Scheduler Task using wall clock timer to run base-rate
//
void NodeInterface::schedulerThreadCallback(void)
{
  if(mRunModel) {
        mBaseRateSem.notify();
    }
}
//
//Model specific
void NodeInterface::baseRateTask(void) {
  mRunModel = (rtmGetErrorStatus(mModel->getRTM()) ==
              (NULL));
  while (mRunModel) {
    mBaseRateSem.wait();
#ifdef MW_DEBUG_LOG
    RCLCPP_INFO(SLROSNodePtr->get_logger(),"** Base rate task semaphore received\n");
#endif
    if (!mRunModel) break;
        //Check if subrate 1 should be unblocked
        if (rtmStepTask(mModel->getRTM(), 1)) {
          mSubRate1Sem.notify();
        }
    mModel->step0();
    mRunModel &= !NodeInterface::getStopRequestedFlag(); //If RunModel and not stop requested
  }
  // Shutdown the ROS 2 node
  NodeInterface::stop();
}
void NodeInterface::subRate1Task(void) {
  while (mRunModel) {
    mSubRate1Sem.wait();
#ifdef MW_DEBUG_LOG
    RCLCPP_INFO(SLROSNodePtr->get_logger(),"** Sub-rate 1 task semaphore received\n");
#endif
    if (!mRunModel) break;
    mModel->step1();
  }
}
}//namespace matlab
}//namespace ros2
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
