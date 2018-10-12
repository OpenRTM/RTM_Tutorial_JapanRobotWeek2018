// -*- C++ -*-
/*!
 * @file  SampleTouchSensorTest.cpp
 * @brief Raspberry Pi Mouse Controller by Touch Sensor
 * @date $Date$
 *
 * @author 宮本　信彦　n-miyamoto@aist.go.jp
 * 産業技術総合研究所　ロボットイノベーション研究センター
 * ロボットソフトウエアプラットフォーム研究チーム
 *
 * $Id$
 */

#include "SampleTouchSensorTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* sampletouchsensor_spec[] =
  {
    "implementation_id", "SampleTouchSensorTest",
    "type_name",         "SampleTouchSensorTest",
    "description",       "Raspberry Pi Mouse Controller by Touch Sensor",
    "version",           "1.0.0",
    "vendor",            "AIST",
    "category",          "Sample",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.speed", "0.2",

    // Widget
    "conf.__widget__.speed", "text",
    // Constraints

    "conf.__type__.speed", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SampleTouchSensorTest::SampleTouchSensorTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_touchIn("touch", m_touch),
    m_target_velocityOut("target_velocity", m_target_velocity)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SampleTouchSensorTest::~SampleTouchSensorTest()
{
}



RTC::ReturnCode_t SampleTouchSensorTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("target_velocity", m_target_velocityIn);
  
  // Set OutPort buffer
  addOutPort("touch", m_touchOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("speed", m_speed, "0.2");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SampleTouchSensorTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensorTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensorTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensorTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SampleTouchSensorTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SampleTouchSensorTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SampleTouchSensorTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensorTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensorTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensorTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensorTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SampleTouchSensorTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(sampletouchsensor_spec);
    manager->registerFactory(profile,
                             RTC::Create<SampleTouchSensorTest>,
                             RTC::Delete<SampleTouchSensorTest>);
  }
  
};


