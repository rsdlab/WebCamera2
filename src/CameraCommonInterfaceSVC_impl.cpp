// -*-C++-*-
/*!
 * @file  CameraCommonInterfaceSVC_impl.cpp
 * @brief Service implementation code of CameraCommonInterface.idl
 *
 */

#include "CameraCommonInterfaceSVC_impl.h"

/*
 * Example implementational code for IDL interface Img::CameraCaptureService
 */
Img_CameraCaptureServiceSVC_impl::Img_CameraCaptureServiceSVC_impl()
{
  // Please add extra constructor code here.
}


Img_CameraCaptureServiceSVC_impl::~Img_CameraCaptureServiceSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
void Img_CameraCaptureServiceSVC_impl::take_one_frame()
{
  m_cap_count = 1;
}

void Img_CameraCaptureServiceSVC_impl::take_multi_frames(::CORBA::Long num)
{
  m_cap_count = num;
}

void Img_CameraCaptureServiceSVC_impl::start_continuous()
{
  m_cap_continuous = true;
}

void Img_CameraCaptureServiceSVC_impl::stop_continuous()
{
  m_cap_continuous = false;
}

void Img_CameraCaptureServiceSVC_impl::getProfile(Img::CameraDeviceProfile_out profile)
{
  std::cout << "The method has not been implemented!" << std::endl;
}



// End of example implementational code



