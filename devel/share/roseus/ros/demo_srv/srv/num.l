;; Auto-generated. Do not edit!


(when (boundp 'demo_srv::num)
  (if (not (find-package "DEMO_SRV"))
    (make-package "DEMO_SRV"))
  (shadow 'num (find-package "DEMO_SRV")))
(unless (find-package "DEMO_SRV::NUM")
  (make-package "DEMO_SRV::NUM"))
(unless (find-package "DEMO_SRV::NUMREQUEST")
  (make-package "DEMO_SRV::NUMREQUEST"))
(unless (find-package "DEMO_SRV::NUMRESPONSE")
  (make-package "DEMO_SRV::NUMRESPONSE"))

(in-package "ROS")





(defclass demo_srv::numRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod demo_srv::numRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass demo_srv::numResponse
  :super ros::object
  :slots (_sum ))

(defmethod demo_srv::numResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass demo_srv::num
  :super ros::object
  :slots ())

(setf (get demo_srv::num :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get demo_srv::num :datatype-) "demo_srv/num")
(setf (get demo_srv::num :request) demo_srv::numRequest)
(setf (get demo_srv::num :response) demo_srv::numResponse)

(defmethod demo_srv::numRequest
  (:response () (instance demo_srv::numResponse :init)))

(setf (get demo_srv::numRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get demo_srv::numRequest :datatype-) "demo_srv/numRequest")
(setf (get demo_srv::numRequest :definition-)
      "# 客户端请求时发送的两个数字
int32 num1
int32 num2
---
# 服务器响应发送的数据
int32 sum
")

(setf (get demo_srv::numResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get demo_srv::numResponse :datatype-) "demo_srv/numResponse")
(setf (get demo_srv::numResponse :definition-)
      "# 客户端请求时发送的两个数字
int32 num1
int32 num2
---
# 服务器响应发送的数据
int32 sum
")



(provide :demo_srv/num "4781436a0c2affec8025955a6041e481")


