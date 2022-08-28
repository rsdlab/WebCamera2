﻿// -*-C++-*-
/*!
 * @file  CameraCommonInterfaceSVC_impl.h
 * @brief Service implementation header of CameraCommonInterface.idl
 *
 */
#include "BasicDataTypeSkel.h"

#include "CameraCommonInterfaceSkel.h"

#ifndef CAMERACOMMONINTERFACESVC_IMPL_H
#define CAMERACOMMONINTERFACESVC_IMPL_H
#include<iostream>
 
/*!
 * @class Img_CameraCaptureServiceSVC_impl
 * Example class implementing IDL interface Img::CameraCaptureService
 */
class Img_CameraCaptureServiceSVC_impl
 : public virtual POA_Img::CameraCaptureService,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~Img_CameraCaptureServiceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   Img_CameraCaptureServiceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~Img_CameraCaptureServiceSVC_impl();

   // attributes and operations
   void take_one_frame();
   void take_multi_frames(::CORBA::Long num);
   void start_continuous();
   void stop_continuous();
   void getProfile(Img::CameraDeviceProfile_out profile);

   int m_cap_count;
   bool m_cap_continuous;
};



#endif // CAMERACOMMONINTERFACESVC_IMPL_H


