// -*- C++ -*-
/*!
 * @file  SampleTouchSensor.cpp
 * @brief Raspberry Pi Mouse Controller by Touch Sensor
 * @date $Date$
 *
 * @author 宮本　信彦　n-miyamoto@aist.go.jp
 * 産業技術総合研究所　ロボットイノベーション研究センター
 * ロボットソフトウエアプラットフォーム研究チーム
 *
 * $Id$
 */

#include "SampleTouchSensor.h"

// Module specification
// <rtc-template block="module_spec">
static const char* sampletouchsensor_spec[] =
  {
    "implementation_id", "SampleTouchSensor",
    "type_name",         "SampleTouchSensor",
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
SampleTouchSensor::SampleTouchSensor(RTC::Manager* manager)
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
SampleTouchSensor::~SampleTouchSensor()
{
}



RTC::ReturnCode_t SampleTouchSensor::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("touch", m_touchIn);
  
  // Set OutPort buffer
  addOutPort("target_velocity", m_target_velocityOut);
  
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
RTC::ReturnCode_t SampleTouchSensor::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensor::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensor::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensor::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SampleTouchSensor::onDeactivated(RTC::UniqueId ec_id)
{
	//非アクティブ化時に停止する
	//目標速度を格納
	m_target_velocity.data.vx = 0;
	m_target_velocity.data.vy = 0;
	m_target_velocity.data.va = 0;
	setTimestamp(m_target_velocity);
	//データ出力
	m_target_velocityOut.write();

  return RTC::RTC_OK;
}


RTC::ReturnCode_t SampleTouchSensor::onExecute(RTC::UniqueId ec_id)
{
	//新規データの確認
	if (m_touchIn.isNew())
	{
		//データの読み込み
		m_touchIn.read();
		//配列の要素数が1以上かを確認
		if (m_touch.data.length() == 2)
		{
			//0番目のデータがオンの場合は直進する指令を出力
			//0番目のデータは右側のタッチセンサに対応
			if (m_touch.data[0])
			{
				//目標速度を格納
				m_target_velocity.data.vx = m_speed;
				m_target_velocity.data.vy = 0;
				m_target_velocity.data.va = 0;
				setTimestamp(m_target_velocity);
				//データ出力
				m_target_velocityOut.write();
			}
			//1番目のデータがオンの場合は後退する指令を出力
			//1番目のデータは左側のタッチセンサに対応
			else if (m_touch.data[1])
			{
				//目標速度を格納
				m_target_velocity.data.vx = -m_speed;
				m_target_velocity.data.vy = 0;
				m_target_velocity.data.va = 0;
				setTimestamp(m_target_velocity);
				//データ出力
				m_target_velocityOut.write();
			}
			//オフの場合は停止する
			else
			{
				//目標速度を格納
				m_target_velocity.data.vx = 0;
				m_target_velocity.data.vy = 0;
				m_target_velocity.data.va = 0;
				setTimestamp(m_target_velocity);
				//データ出力
				m_target_velocityOut.write();
			}
		}
	}
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SampleTouchSensor::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensor::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensor::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensor::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SampleTouchSensor::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SampleTouchSensorInit(RTC::Manager* manager)
  {
    coil::Properties profile(sampletouchsensor_spec);
    manager->registerFactory(profile,
                             RTC::Create<SampleTouchSensor>,
                             RTC::Delete<SampleTouchSensor>);
  }
  
};


