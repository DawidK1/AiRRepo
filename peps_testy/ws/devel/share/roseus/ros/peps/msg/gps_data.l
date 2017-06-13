;; Auto-generated. Do not edit!


(when (boundp 'peps::gps_data)
  (if (not (find-package "PEPS"))
    (make-package "PEPS"))
  (shadow 'gps_data (find-package "PEPS")))
(unless (find-package "PEPS::GPS_DATA")
  (make-package "PEPS::GPS_DATA"))

(in-package "ROS")
;;//! \htmlinclude gps_data.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass peps::gps_data
  :super ros::object
  :slots (_beacon_1 _beacon_2 ))

(defmethod peps::gps_data
  (:init
   (&key
    ((:beacon_1 __beacon_1) (instance geometry_msgs::Point :init))
    ((:beacon_2 __beacon_2) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _beacon_1 __beacon_1)
   (setq _beacon_2 __beacon_2)
   self)
  (:beacon_1
   (&rest __beacon_1)
   (if (keywordp (car __beacon_1))
       (send* _beacon_1 __beacon_1)
     (progn
       (if __beacon_1 (setq _beacon_1 (car __beacon_1)))
       _beacon_1)))
  (:beacon_2
   (&rest __beacon_2)
   (if (keywordp (car __beacon_2))
       (send* _beacon_2 __beacon_2)
     (progn
       (if __beacon_2 (setq _beacon_2 (car __beacon_2)))
       _beacon_2)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _beacon_1
    (send _beacon_1 :serialization-length)
    ;; geometry_msgs/Point _beacon_2
    (send _beacon_2 :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _beacon_1
       (send _beacon_1 :serialize s)
     ;; geometry_msgs/Point _beacon_2
       (send _beacon_2 :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _beacon_1
     (send _beacon_1 :deserialize buf ptr-) (incf ptr- (send _beacon_1 :serialization-length))
   ;; geometry_msgs/Point _beacon_2
     (send _beacon_2 :deserialize buf ptr-) (incf ptr- (send _beacon_2 :serialization-length))
   ;;
   self)
  )

(setf (get peps::gps_data :md5sum-) "47b81c8c692416b6c155fcbe00080eb3")
(setf (get peps::gps_data :datatype-) "peps/gps_data")
(setf (get peps::gps_data :definition-)
      "geometry_msgs/Point beacon_1
geometry_msgs/Point beacon_2
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :peps/gps_data "47b81c8c692416b6c155fcbe00080eb3")


