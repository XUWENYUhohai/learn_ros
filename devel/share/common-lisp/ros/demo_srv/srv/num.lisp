; Auto-generated. Do not edit!


(cl:in-package demo_srv-srv)


;//! \htmlinclude num-request.msg.html

(cl:defclass <num-request> (roslisp-msg-protocol:ros-message)
  ((num1
    :reader num1
    :initarg :num1
    :type cl:integer
    :initform 0)
   (num2
    :reader num2
    :initarg :num2
    :type cl:integer
    :initform 0))
)

(cl:defclass num-request (<num-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <num-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'num-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name demo_srv-srv:<num-request> is deprecated: use demo_srv-srv:num-request instead.")))

(cl:ensure-generic-function 'num1-val :lambda-list '(m))
(cl:defmethod num1-val ((m <num-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_srv-srv:num1-val is deprecated.  Use demo_srv-srv:num1 instead.")
  (num1 m))

(cl:ensure-generic-function 'num2-val :lambda-list '(m))
(cl:defmethod num2-val ((m <num-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_srv-srv:num2-val is deprecated.  Use demo_srv-srv:num2 instead.")
  (num2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <num-request>) ostream)
  "Serializes a message object of type '<num-request>"
  (cl:let* ((signed (cl:slot-value msg 'num1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'num2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <num-request>) istream)
  "Deserializes a message object of type '<num-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num1) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num2) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<num-request>)))
  "Returns string type for a service object of type '<num-request>"
  "demo_srv/numRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'num-request)))
  "Returns string type for a service object of type 'num-request"
  "demo_srv/numRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<num-request>)))
  "Returns md5sum for a message object of type '<num-request>"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'num-request)))
  "Returns md5sum for a message object of type 'num-request"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<num-request>)))
  "Returns full string definition for message of type '<num-request>"
  (cl:format cl:nil "# 客户端请求时发送的两个数字~%int32 num1~%int32 num2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'num-request)))
  "Returns full string definition for message of type 'num-request"
  (cl:format cl:nil "# 客户端请求时发送的两个数字~%int32 num1~%int32 num2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <num-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <num-request>))
  "Converts a ROS message object to a list"
  (cl:list 'num-request
    (cl:cons ':num1 (num1 msg))
    (cl:cons ':num2 (num2 msg))
))
;//! \htmlinclude num-response.msg.html

(cl:defclass <num-response> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type cl:integer
    :initform 0))
)

(cl:defclass num-response (<num-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <num-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'num-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name demo_srv-srv:<num-response> is deprecated: use demo_srv-srv:num-response instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <num-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader demo_srv-srv:sum-val is deprecated.  Use demo_srv-srv:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <num-response>) ostream)
  "Serializes a message object of type '<num-response>"
  (cl:let* ((signed (cl:slot-value msg 'sum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <num-response>) istream)
  "Deserializes a message object of type '<num-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<num-response>)))
  "Returns string type for a service object of type '<num-response>"
  "demo_srv/numResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'num-response)))
  "Returns string type for a service object of type 'num-response"
  "demo_srv/numResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<num-response>)))
  "Returns md5sum for a message object of type '<num-response>"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'num-response)))
  "Returns md5sum for a message object of type 'num-response"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<num-response>)))
  "Returns full string definition for message of type '<num-response>"
  (cl:format cl:nil "# 服务器响应发送的数据~%int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'num-response)))
  "Returns full string definition for message of type 'num-response"
  (cl:format cl:nil "# 服务器响应发送的数据~%int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <num-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <num-response>))
  "Converts a ROS message object to a list"
  (cl:list 'num-response
    (cl:cons ':sum (sum msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'num)))
  'num-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'num)))
  'num-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'num)))
  "Returns string type for a service object of type '<num>"
  "demo_srv/num")