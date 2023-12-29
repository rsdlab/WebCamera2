// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  WebCamera2Test.cpp
 * @brief Web Camera RTC with common camera interface version 2.0 for RTM2.0 (test code)
 *
 */
// </rtc-template>

#include "WebCamera2Test.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const webcamera2_spec[] =
#else
static const char* webcamera2_spec[] =
#endif
  {
    "implementation_id", "WebCamera2Test",
    "type_name",         "WebCamera2Test",
    "description",       "Web Camera RTC with common camera interface version 2.0 for RTM2.0",
    "version",           "2.0.0",
    "vendor",            "Kenichi Ohara, Meijo University",
    "category",          "ImageProcessing",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.camera_id", "0",
    "conf.default.output_color_format", "RGB",
    "conf.default.camera_param_filename", "..\..\camera.yml",
    "conf.default.undistortion_flag", "false",
    "conf.default.cap_continuous_flag", "false",
    "conf.default.compression_ratio", "75",
    "conf.default.frame_width", "640",
    "conf.default.frame_height", "480",
    "conf.default.auto_exposure", "0",
    "conf.default.auto_focus", "false",
    "conf.default.auto_white_balance", "false",
    "conf.default.exposure_param", "4.0",
    "conf.default.brightness_param", "128.0",
    "conf.default.contrast_param", "128.0",
    "conf.default.saturation_param", "128",
    "conf.default.focus_param", "30",

    // Widget
    "conf.__widget__.camera_id", "text",
    "conf.__widget__.output_color_format", "radio",
    "conf.__widget__.camera_param_filename", "text",
    "conf.__widget__.undistortion_flag", "radio",
    "conf.__widget__.cap_continuous_flag", "radio",
    "conf.__widget__.compression_ratio", "slider.1",
    "conf.__widget__.frame_width", "text",
    "conf.__widget__.frame_height", "text",
    "conf.__widget__.auto_exposure", "text",
    "conf.__widget__.auto_focus", "text",
    "conf.__widget__.auto_white_balance", "text",
    "conf.__widget__.exposure_param", "text",
    "conf.__widget__.brightness_param", "text",
    "conf.__widget__.contrast_param", "text",
    "conf.__widget__.saturation_param", "text",
    "conf.__widget__.focus_param", "slider",
    // Constraints
    "conf.__constraints__.output_color_format", "(RGB,GRAY,JPEG,PNG)",
    "conf.__constraints__.undistortion_flag", "(true,false)",
    "conf.__constraints__.cap_continuous_flag", "(true,false)",
    "conf.__constraints__.compression_ratio", "0<=x<=100",
    "conf.__constraints__.auto_exposure", "(true,false)",
    "conf.__constraints__.auto_focus", "(true,false)",
    "conf.__constraints__.auto_white_balance", "(true,false)",

    "conf.__type__.camera_id", "int",
    "conf.__type__.output_color_format", "string",
    "conf.__type__.camera_param_filename", "string",
    "conf.__type__.undistortion_flag", "string",
    "conf.__type__.cap_continuous_flag", "string",
    "conf.__type__.compression_ratio", "int",
    "conf.__type__.frame_width", "int",
    "conf.__type__.frame_height", "int",
    "conf.__type__.auto_exposure", "double",
    "conf.__type__.auto_focus", "string",
    "conf.__type__.auto_white_balance", "string",
    "conf.__type__.exposure_param", "double",
    "conf.__type__.brightness_param", "int",
    "conf.__type__.contrast_param", "int",
    "conf.__type__.saturation_param", "int",
    "conf.__type__.focus_param", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
WebCamera2Test::WebCamera2Test(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_CameraImageIn("CameraImage", m_CameraImage),
    m_CameraCaptureServicePort("CameraCaptureService")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
WebCamera2Test::~WebCamera2Test()
{
}



RTC::ReturnCode_t WebCamera2Test::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("CameraImage", m_CameraImageIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  m_CameraCaptureServicePort.registerConsumer("CameraCaptureService", "Img::CameraCaptureService", m_CameraCaptureService);
  
  // Set CORBA Service Ports
  addPort(m_CameraCaptureServicePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("camera_id", m_camera_id, "0");
  bindParameter("output_color_format", m_output_color_format, "RGB");
  bindParameter("camera_param_filename", m_camera_param_filename, "..\..\camera.yml");
  bindParameter("undistortion_flag", m_undistortion_flag, "false");
  bindParameter("cap_continuous_flag", m_cap_continuous_flag, "false");
  bindParameter("compression_ratio", m_compression_ratio, "75");
  bindParameter("frame_width", m_frame_width, "640");
  bindParameter("frame_height", m_frame_height, "480");
  bindParameter("auto_exposure", m_auto_exposure, "0");
  bindParameter("auto_focus", m_auto_focus, "false");
  bindParameter("auto_white_balance", m_auto_white_balance, "false");
  bindParameter("exposure_param", m_exposure_param, "4.0");
  bindParameter("brightness_param", m_brightness_param, "128.0");
  bindParameter("contrast_param", m_contrast_param, "128.0");
  bindParameter("saturation_param", m_saturation_param, "128");
  bindParameter("focus_param", m_focus_param, "30");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t WebCamera2Test::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t WebCamera2Test::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCamera2Test::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t WebCamera2Test::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t WebCamera2Test::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t WebCamera2Test::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t WebCamera2Test::onAborting(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t WebCamera2Test::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCamera2Test::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCamera2Test::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCamera2Test::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool WebCamera2Test::runTest()
{
    return true;
}


extern "C"
{
 
  void WebCamera2TestInit(RTC::Manager* manager)
  {
    coil::Properties profile(webcamera2_spec);
    manager->registerFactory(profile,
                             RTC::Create<WebCamera2Test>,
                             RTC::Delete<WebCamera2Test>);
  }
  
}
