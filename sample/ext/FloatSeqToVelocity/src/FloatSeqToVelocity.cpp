// -*- C++ -*-
/*!
 * @file  FloatSeqToVelocity.cpp
 * @brief AIST
 * @date $Date$
 *
 * @author 宮本　信彦　n-miyamoto@aist.go.jp
 * 産業技術総合研究所　ロボットイノベーション研究センター
 * ロボットソフトウエアプラットフォーム研究チーム
 *
 * LGPL
 *
 * $Id$
 */

#include "FloatSeqToVelocity.h"

// Module specification
// <rtc-template block="module_spec">
static const char* floatseqtovelocity_spec[] =
  {
    "implementation_id", "FloatSeqToVelocity",
    "type_name",         "FloatSeqToVelocity",
    "description",       "AIST",
    "version",           "1.0.0",
    "vendor",            "AIST",
    "category",          "Converter",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.rotation_by_position", "-0.02",
    "conf.default.velocity_by_position", "0.002",

    // Widget
    "conf.__widget__.rotation_by_position", "text",
    "conf.__widget__.velocity_by_position", "text",
    // Constraints

    "conf.__type__.rotation_by_position", "double",
    "conf.__type__.velocity_by_position", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
FloatSeqToVelocity::FloatSeqToVelocity(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in),
    m_outOut("out", m_out)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
FloatSeqToVelocity::~FloatSeqToVelocity()
{
}



RTC::ReturnCode_t FloatSeqToVelocity::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  addOutPort("out", m_outOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("rotation_by_position", m_rotation_by_position, "-0.02");
  bindParameter("velocity_by_position", m_velocity_by_position, "0.002");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t FloatSeqToVelocity::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t FloatSeqToVelocity::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t FloatSeqToVelocity::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t FloatSeqToVelocity::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t FloatSeqToVelocity::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t FloatSeqToVelocity::onExecute(RTC::UniqueId ec_id)
{
	//新規データの確認
	if (m_inIn.isNew())
	{
		//データの読み込み
		m_inIn.read();
		//配列のデータ数確認
		if (m_in.data.length() >= 2)
		{
			//目標速度格納
			m_out.data.vx = m_in.data[1] * m_velocity_by_position;
			m_out.data.vy = 0;
			m_out.data.va = m_in.data[0] * m_rotation_by_position;
			setTimestamp(m_out);
			//目標速度出力
			m_outOut.write();
		}
	}
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t FloatSeqToVelocity::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t FloatSeqToVelocity::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t FloatSeqToVelocity::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t FloatSeqToVelocity::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t FloatSeqToVelocity::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void FloatSeqToVelocityInit(RTC::Manager* manager)
  {
    coil::Properties profile(floatseqtovelocity_spec);
    manager->registerFactory(profile,
                             RTC::Create<FloatSeqToVelocity>,
                             RTC::Delete<FloatSeqToVelocity>);
  }
  
};


