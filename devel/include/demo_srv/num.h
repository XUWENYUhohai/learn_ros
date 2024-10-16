// Generated by gencpp from file demo_srv/num.msg
// DO NOT EDIT!


#ifndef DEMO_SRV_MESSAGE_NUM_H
#define DEMO_SRV_MESSAGE_NUM_H

#include <ros/service_traits.h>


#include <demo_srv/numRequest.h>
#include <demo_srv/numResponse.h>


namespace demo_srv
{

struct num
{

typedef numRequest Request;
typedef numResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct num
} // namespace demo_srv


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::demo_srv::num > {
  static const char* value()
  {
    return "4781436a0c2affec8025955a6041e481";
  }

  static const char* value(const ::demo_srv::num&) { return value(); }
};

template<>
struct DataType< ::demo_srv::num > {
  static const char* value()
  {
    return "demo_srv/num";
  }

  static const char* value(const ::demo_srv::num&) { return value(); }
};


// service_traits::MD5Sum< ::demo_srv::numRequest> should match
// service_traits::MD5Sum< ::demo_srv::num >
template<>
struct MD5Sum< ::demo_srv::numRequest>
{
  static const char* value()
  {
    return MD5Sum< ::demo_srv::num >::value();
  }
  static const char* value(const ::demo_srv::numRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::demo_srv::numRequest> should match
// service_traits::DataType< ::demo_srv::num >
template<>
struct DataType< ::demo_srv::numRequest>
{
  static const char* value()
  {
    return DataType< ::demo_srv::num >::value();
  }
  static const char* value(const ::demo_srv::numRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::demo_srv::numResponse> should match
// service_traits::MD5Sum< ::demo_srv::num >
template<>
struct MD5Sum< ::demo_srv::numResponse>
{
  static const char* value()
  {
    return MD5Sum< ::demo_srv::num >::value();
  }
  static const char* value(const ::demo_srv::numResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::demo_srv::numResponse> should match
// service_traits::DataType< ::demo_srv::num >
template<>
struct DataType< ::demo_srv::numResponse>
{
  static const char* value()
  {
    return DataType< ::demo_srv::num >::value();
  }
  static const char* value(const ::demo_srv::numResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DEMO_SRV_MESSAGE_NUM_H
