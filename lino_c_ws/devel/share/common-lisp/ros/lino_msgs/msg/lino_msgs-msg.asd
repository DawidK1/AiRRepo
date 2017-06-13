
(cl:in-package :asdf)

(defsystem "lino_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "PID" :depends-on ("_package_PID"))
    (:file "_package_PID" :depends-on ("_package"))
    (:file "Velocities" :depends-on ("_package_Velocities"))
    (:file "_package_Velocities" :depends-on ("_package"))
  ))