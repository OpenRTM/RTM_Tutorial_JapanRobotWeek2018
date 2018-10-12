﻿// -*- C++ -*-
/*!
 * @file  testARToolKitTest.cpp
 * @brief test ARToolKitPlus
 * @date $Date$
 *
 * @author 宮本　信彦　n-miyamoto@aist.go.jp
 * 産業技術総合研究所　ロボットイノベーション研究センター
 * ロボットソフトウエアプラットフォーム研究チーム
 *
 * $Id$
 */

#include "testARToolKitTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* testartoolkit_spec[] =
  {
    "implementation_id", "testARToolKitTest",
    "type_name",         "testARToolKitTest",
    "description",       "test ARToolKitPlus",
    "version",           "1.0.0",
    "vendor",            "AIST",
    "category",          "Sample",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.x_distance", "0.5",
    "conf.default.y_distance", "0",
    "conf.default.x_speed", "0.1",
    "conf.default.r_speed", "0.5",
    "conf.default.error_range_x", "0.1",
    "conf.default.error_range_y", "0.05",

    // Widget
    "conf.__widget__.x_distance", "text",
    "conf.__widget__.y_distance", "text",
    "conf.__widget__.x_speed", "text",
    "conf.__widget__.r_speed", "text",
    "conf.__widget__.error_range_x", "text",
    "conf.__widget__.error_range_y", "text",
    // Constraints

    "conf.__type__.x_distance", "double",
    "conf.__type__.y_distance", "double",
    "conf.__type__.x_speed", "double",
    "conf.__type__.r_speed", "double",
    "conf.__type__.error_range_x", "double",
    "conf.__type__.error_range_y", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
testARToolKitTest::testARToolKitTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_marker_posIn("marker_pos", m_marker_pos),
    m_target_velOut("target_vel", m_target_vel)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
testARToolKitTest::~testARToolKitTest()
{
}



RTC::ReturnCode_t testARToolKitTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("target_vel", m_target_velIn);
  
  // Set OutPort buffer
  addOutPort("marker_pos", m_marker_posOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("x_distance", m_x_distance, "0.5");
  bindParameter("y_distance", m_y_distance, "0");
  bindParameter("x_speed", m_x_speed, "0.1");
  bindParameter("r_speed", m_r_speed, "0.5");
  bindParameter("error_range_x", m_error_range_x, "0.1");
  bindParameter("error_range_y", m_error_range_y, "0.05");
  // </rtc-template>
  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onFinalize()
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t testARToolKitTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}



extern "C"
{
 
  void testARToolKitTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(testartoolkit_spec);
    manager->registerFactory(profile,
                             RTC::Create<testARToolKitTest>,
                             RTC::Delete<testARToolKitTest>);
  }
  
};


