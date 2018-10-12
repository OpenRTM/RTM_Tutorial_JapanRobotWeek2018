// -*- C++ -*-
/*!
 * @file  SpeechSample.cpp
 * @brief EV3 Speech Sample
 * @date $Date$
 *
 * @author 宮本　信彦　n-miyamoto@aist.go.jp
 * 産業技術総合研究所　ロボットイノベーション研究センター
 * ロボットソフトウエアプラットフォーム研究チーム
 *
 * $Id$
 */

#include "SpeechSample.h"

// Module specification
// <rtc-template block="module_spec">
static const char* speechsample_spec[] =
  {
    "implementation_id", "SpeechSample",
    "type_name",         "SpeechSample",
    "description",       "EV3 Speech Sample",
    "version",           "1.0.0",
    "vendor",            "AIST",
    "category",          "Sample",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SpeechSample::SpeechSample(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_outOut("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SpeechSample::~SpeechSample()
{
}



RTC::ReturnCode_t SpeechSample::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("out", m_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SpeechSample::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeechSample::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeechSample::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeechSample::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeechSample::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SpeechSample::onExecute(RTC::UniqueId ec_id)
{
	std::cout << "Please input: ";
	std::string ret;
	//文字入力
	std::cin >> ret;
	//データに格納
	m_out.data = CORBA::string_dup(ret.c_str());
	setTimestamp(m_out);
	//データ出力
	m_outOut.write();

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SpeechSample::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeechSample::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeechSample::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeechSample::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeechSample::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SpeechSampleInit(RTC::Manager* manager)
  {
    coil::Properties profile(speechsample_spec);
    manager->registerFactory(profile,
                             RTC::Create<SpeechSample>,
                             RTC::Delete<SpeechSample>);
  }
  
};


