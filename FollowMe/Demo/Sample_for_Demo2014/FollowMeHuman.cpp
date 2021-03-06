#include "ControllerEvent.h"  
#include "Controller.h"  
#include "Logger.h"
#include <unistd.h>
#include <algorithm>

#define DEG2RAD(DEG) ( (M_PI) * (DEG) / 180.0 )   

bool start;
bool sw;
using namespace std;

class MyController : public Controller {
public:
	void   onInit(InitEvent &evt);
	double onAction(ActionEvent&);
	void   onRecvMsg(RecvMsgEvent &evt);
	void   onCollision(CollisionEvent &evt);

private:
	SimObj *my;

	FILE* fp;
	int sleeptime;
	const static int SIZE = 30;
	int motionNum;
	double HEIGHT[SIZE];
	double LARM_JOINT1[SIZE]; // left shoulder
	double LARM_JOINT3[SIZE]; // left elbow
	double RARM_JOINT1[SIZE]; // right shoulder
	double RARM_JOINT3[SIZE]; // right elbow
	double LLEG_JOINT2[SIZE]; // left groin(leg)
	double LLEG_JOINT4[SIZE]; // left knee
	double LLEG_JOINT6[SIZE]; // left ankle
	double RLEG_JOINT2[SIZE]; // right groin
	double RLEG_JOINT4[SIZE]; // right knee
	double RLEG_JOINT6[SIZE]; // right ankle
};

void MyController::onInit(InitEvent &evt)
{
	my = getObj(myname());

	start = false;
	sw = false;

	// 手を下げる
	my->setJointAngle("LARM_JOINT2", DEG2RAD(-90));
	my->setJointAngle("RARM_JOINT2", DEG2RAD(90));

	sleeptime = 300000;

	if((fp = fopen("motion.txt", "r")) == NULL) {
		LOG_MSG(("File do not exist."));
	}
	else{
		fscanf(fp, "%d", &motionNum);
		fscanf(fp, "%d", &sleeptime);
		for(int i=0; i<motionNum; i++){
			fscanf(fp, "%f %f %f %f %f %f %f %f %f %f %f",
					   &HEIGHT[i],
					   &LARM_JOINT1[i],
					   &LARM_JOINT3[i],
					   &RARM_JOINT1[i],
					   &RARM_JOINT3[i],
					   &LLEG_JOINT2[i],
					   &LLEG_JOINT4[i],
					   &LLEG_JOINT6[i],
					   &RLEG_JOINT2[i],
					   &RLEG_JOINT4[i],
					   &RLEG_JOINT6[i]);
		}
	}
}

double MyController::onAction(ActionEvent &evt)
{
	int count = 0;
	Vector3d pos;

	if (start == true){
		int step = 3;
		while (count<step){
			double dx = 0;
			double dz = -2.5;
			double addx = 0.0;
			double addz = 0.0;
			my->getPosition(pos);
			for(int i=0; i<motionNum; i++){
				addx += dx;
				addz += dz;
				if(motionNum)
					usleep(sleeptime);
				my->setPosition(pos.x()+addx, HEIGHT[i], pos.z()+addz);
				my->setJointAngle("LARM_JOINT1", DEG2RAD(LARM_JOINT1[i]));
				my->setJointAngle("LARM_JOINT3", DEG2RAD(LARM_JOINT3[i]));
				my->setJointAngle("RARM_JOINT1", DEG2RAD(RARM_JOINT1[i]));
				my->setJointAngle("RARM_JOINT3", DEG2RAD(RARM_JOINT3[i]));
				my->setJointAngle("LLEG_JOINT2", DEG2RAD(LLEG_JOINT2[i]));
				my->setJointAngle("LLEG_JOINT4", DEG2RAD(LLEG_JOINT4[i]));
				my->setJointAngle("LLEG_JOINT6", DEG2RAD(LLEG_JOINT6[i]));
				my->setJointAngle("RLEG_JOINT2", DEG2RAD(RLEG_JOINT2[i]));
				my->setJointAngle("RLEG_JOINT4", DEG2RAD(RLEG_JOINT4[i]));
				my->setJointAngle("RLEG_JOINT6", DEG2RAD(RLEG_JOINT6[i]));
			}
			for(int i=0; i<motionNum; i++){
				addx += dx;
				addz += dz;
				usleep(sleeptime);
				my->setPosition(pos.x()+addx, HEIGHT[i], pos.z()+addz);
				my->setJointAngle("RARM_JOINT1", DEG2RAD(LARM_JOINT1[i]));
				my->setJointAngle("RARM_JOINT3", DEG2RAD(-LARM_JOINT3[i]));
				my->setJointAngle("LARM_JOINT1", DEG2RAD(RARM_JOINT1[i]));
				my->setJointAngle("LARM_JOINT3", DEG2RAD(-RARM_JOINT3[i]));
				my->setJointAngle("RLEG_JOINT2", DEG2RAD(LLEG_JOINT2[i]));
				my->setJointAngle("RLEG_JOINT4", DEG2RAD(LLEG_JOINT4[i]));
				my->setJointAngle("RLEG_JOINT6", DEG2RAD(LLEG_JOINT6[i]));
				my->setJointAngle("LLEG_JOINT2", DEG2RAD(RLEG_JOINT2[i]));
				my->setJointAngle("LLEG_JOINT4", DEG2RAD(RLEG_JOINT4[i]));
				my->setJointAngle("LLEG_JOINT6", DEG2RAD(RLEG_JOINT6[i]));
			}
			count++;
			if(count==1){
				usleep(3000000);
			}

			start = false;
		}
		/*while (count<20){
			if (sw == false){
				my->getPosition(pos);
				my->setPosition(pos.x(), pos.y(), pos.z() - 10);
				my->setJointAngle("LARM_JOINT1", DEG2RAD(-30));
				my->setJointAngle("RLEG_JOINT2", DEG2RAD(-20));
				my->setJointAngle("RLEG_JOINT4", DEG2RAD(10));
				usleep(100000);
				my->setJointAngle("LARM_JOINT1", DEG2RAD(0));
				my->setJointAngle("RLEG_JOINT2", DEG2RAD(0));
				my->setJointAngle("RLEG_JOINT4", DEG2RAD(0));
				sw = true;
			}
			else{
				my->getPosition(pos);
				my->setPosition(pos.x(), pos.y(), pos.z() - 10);
				my->setJointAngle("RARM_JOINT1", DEG2RAD(-30));
				my->setJointAngle("LLEG_JOINT2", DEG2RAD(-20));
				my->setJointAngle("LLEG_JOINT4", DEG2RAD(10));
				usleep(100000);
				my->setJointAngle("RARM_JOINT1", DEG2RAD(0));
				my->setJointAngle("LLEG_JOINT2", DEG2RAD(0));
				my->setJointAngle("LLEG_JOINT4", DEG2RAD(0));
				sw = false;
			}
			count++;

			if(count==7){
				usleep(3000000);
			}

			start = false;
		}*/
	}

	return 0.1;
}

void MyController::onRecvMsg(RecvMsgEvent &evt)
{
	string msg = evt.getMsg();
	if (msg == "point1"){
		start = true;
	}
}

void MyController::onCollision(CollisionEvent &evt)
{
}

extern "C" Controller * createController() {
	return new MyController;
}

