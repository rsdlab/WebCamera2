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
  m_cap_continuous = false;
  m_cap_count = 0;
}

Img_CameraCaptureServiceSVC_impl::~Img_CameraCaptureServiceSVC_impl()
{
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
}



// End of example implementational code



