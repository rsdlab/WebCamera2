// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  WebCamera2Test.h
 * @brief Web Camera RTC with common camera interface version 2.0 for RTM2.0 (test code)
 *
 */
// </rtc-template>

#ifndef WEBCAMERA2_TEST__H
#define WEBCAMERA2_TEST_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "CameraCommonInterfaceStub.h"

// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

/*!
 * @class WebCamera2Test
 * @brief Web Camera RTC with common camera interface version 2.0 for RTM2.0
 *
 */
class WebCamera2Test
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  WebCamera2Test(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~WebCamera2Test() override;

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  // <rtc-template block="activity">
  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onInitialize() override;

  /***
   *
   * The finalize action (on ALIVE->END transition)
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onFinalize() override;

  /***
   *
   * The startup action when ExecutionContext startup
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id) override;

  /***
   *
   * The shutdown action when ExecutionContext stop
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id) override;

  /***
   *
   * The activated action (Active state entry action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id) override;

  /***
   *
   * The deactivated action (Active state exit action)
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id) override;

  /***
   *
   * The execution action that is invoked periodically
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id) override;

  /***
   *
   * The aborting action when main logic error occurred.
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id) override;

  /***
   *
   * The error action in ERROR state
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onError(RTC::UniqueId ec_id) override;

  /***
   *
   * The reset action that is invoked resetting
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onReset(RTC::UniqueId ec_id) override;
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id) override;

  /***
   *
   * The action that is invoked when execution context's rate is changed
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id) override;
  // </rtc-template>

  bool runTest();

 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  camera_id
   * - DefaultValue: 0
   */
  int m_camera_id;
  /*!
   * 
   * - Name:  output_color_format
   * - DefaultValue: RGB
   */
  std::string m_output_color_format;
  /*!
   * 
   * - Name:  camera_param_filename
   * - DefaultValue: ..\..\camera.yml
   */
  std::string m_camera_param_filename;
  /*!
   * 
   * - Name:  undistortion_flag
   * - DefaultValue: false
   */
  std::string m_undistortion_flag;
  /*!
   * 
   * - Name:  cap_continuous_flag
   * - DefaultValue: false
   */
  std::string m_cap_continuous_flag;
  /*!
   * This parameter can control the compression ratio for JPEG
   * and PNG color format.
   * - Name:  compression_ratio
   * - DefaultValue: 75
   */
  int m_compression_ratio;
  /*!
   * 
   * - Name:  frame_width
   * - DefaultValue: 640
   */
  int m_frame_width;
  /*!
   * 
   * - Name:  frame_height
   * - DefaultValue: 480
   */
  int m_frame_height;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  Img::TimedCameraImage m_CameraImage;
  /*!
   */
  RTC::InPort<Img::TimedCameraImage> m_CameraImageIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  /*!
   */
  RTC::CorbaPort m_CameraCaptureServicePort;
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  /*!
   */
  RTC::CorbaConsumer<Img::CameraCaptureService> m_CameraCaptureService;
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


extern "C"
{
  DLL_EXPORT void WebCamera2TestInit(RTC::Manager* manager);
};

#endif // WEBCAMERA2_TEST_H
