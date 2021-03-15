#ifndef DISARM_PLUGIN
#define DISARM_PLUGIN

//Gazebo headers
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>



// Include ROS headers so we can communicate with our robot
#include <ros/ros.h>

// Include std::string's because they're pretty darn useful.
#include <string>


namespace gazebo
 {
 	class DisarmPlugin : public ModelPlugin {
 	
 	private:
 	
 	// Model pointer
    	physics::ModelPtr _m;

    	// Pointer to our onUpdate callback
    	event::ConnectionPtr updateConnection;
 	
 	public:
 	
 	DisarmPlugin() {}
 	
	void onUpdate(const common::UpdateInfo &inf) {
	
		//_m->GetJoint("innerGRJoint")->SetForce(0,5); 
			
	}
 	
 	virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf) 
 		{
	 		if(!ros::isInitialized) {
	 		
		 		ROS_FATAL_STREAM("Plugin failed.");
		 		return;
		 	}
		 	ROS_INFO("DISARM plugin loaded");
		 	
		 	_m = _model;
		 	
		 	this->updateConnection = event::Events::ConnectWorldUpdateBegin(boost::bind(&DisarmPlugin::onUpdate, this, _1));
	 	}
	};
	
	
	
	GZ_REGISTER_MODEL_PLUGIN(DisarmPlugin)
}
#endif


