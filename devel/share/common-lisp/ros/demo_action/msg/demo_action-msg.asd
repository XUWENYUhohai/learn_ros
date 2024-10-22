
(cl:in-package :asdf)

(defsystem "demo_action-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "addAction" :depends-on ("_package_addAction"))
    (:file "_package_addAction" :depends-on ("_package"))
    (:file "addActionFeedback" :depends-on ("_package_addActionFeedback"))
    (:file "_package_addActionFeedback" :depends-on ("_package"))
    (:file "addActionGoal" :depends-on ("_package_addActionGoal"))
    (:file "_package_addActionGoal" :depends-on ("_package"))
    (:file "addActionResult" :depends-on ("_package_addActionResult"))
    (:file "_package_addActionResult" :depends-on ("_package"))
    (:file "addFeedback" :depends-on ("_package_addFeedback"))
    (:file "_package_addFeedback" :depends-on ("_package"))
    (:file "addGoal" :depends-on ("_package_addGoal"))
    (:file "_package_addGoal" :depends-on ("_package"))
    (:file "addResult" :depends-on ("_package_addResult"))
    (:file "_package_addResult" :depends-on ("_package"))
  ))