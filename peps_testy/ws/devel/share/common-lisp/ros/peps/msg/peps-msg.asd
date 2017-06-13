
(cl:in-package :asdf)

(defsystem "peps-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "gps_data" :depends-on ("_package_gps_data"))
    (:file "_package_gps_data" :depends-on ("_package"))
  ))