; Auto-generated. Do not edit!


(cl:in-package peps-msg)


;//! \htmlinclude gps_data.msg.html

(cl:defclass <gps_data> (roslisp-msg-protocol:ros-message)
  ((beacon_1
    :reader beacon_1
    :initarg :beacon_1
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (beacon_2
    :reader beacon_2
    :initarg :beacon_2
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass gps_data (<gps_data>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <gps_data>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'gps_data)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name peps-msg:<gps_data> is deprecated: use peps-msg:gps_data instead.")))

(cl:ensure-generic-function 'beacon_1-val :lambda-list '(m))
(cl:defmethod beacon_1-val ((m <gps_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader peps-msg:beacon_1-val is deprecated.  Use peps-msg:beacon_1 instead.")
  (beacon_1 m))

(cl:ensure-generic-function 'beacon_2-val :lambda-list '(m))
(cl:defmethod beacon_2-val ((m <gps_data>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader peps-msg:beacon_2-val is deprecated.  Use peps-msg:beacon_2 instead.")
  (beacon_2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <gps_data>) ostream)
  "Serializes a message object of type '<gps_data>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'beacon_1) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'beacon_2) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <gps_data>) istream)
  "Deserializes a message object of type '<gps_data>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'beacon_1) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'beacon_2) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<gps_data>)))
  "Returns string type for a message object of type '<gps_data>"
  "peps/gps_data")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'gps_data)))
  "Returns string type for a message object of type 'gps_data"
  "peps/gps_data")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<gps_data>)))
  "Returns md5sum for a message object of type '<gps_data>"
  "47b81c8c692416b6c155fcbe00080eb3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'gps_data)))
  "Returns md5sum for a message object of type 'gps_data"
  "47b81c8c692416b6c155fcbe00080eb3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<gps_data>)))
  "Returns full string definition for message of type '<gps_data>"
  (cl:format cl:nil "geometry_msgs/Point beacon_1~%geometry_msgs/Point beacon_2~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'gps_data)))
  "Returns full string definition for message of type 'gps_data"
  (cl:format cl:nil "geometry_msgs/Point beacon_1~%geometry_msgs/Point beacon_2~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <gps_data>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'beacon_1))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'beacon_2))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <gps_data>))
  "Converts a ROS message object to a list"
  (cl:list 'gps_data
    (cl:cons ':beacon_1 (beacon_1 msg))
    (cl:cons ':beacon_2 (beacon_2 msg))
))
