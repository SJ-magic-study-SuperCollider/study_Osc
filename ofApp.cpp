/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp()
// : Osc("127.0.0.1", 12345, 12345)
: Osc("127.0.0.1", 57120, 12345)
{
}

/******************************
******************************/
ofApp::~ofApp()
{
}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("OSC send");
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
}

/******************************
******************************/
void ofApp::update(){
	/********************
	********************/
	while(Osc.OscReceive.hasWaitingMessages()){
		ofxOscMessage m_receive;
		Osc.OscReceive.getNextMessage(m_receive); // 引数がpointerから参照に変わった.
		
		if(m_receive.getAddress() == "/OSC_test"){
			float val[2];
			val[0] = m_receive.getArgAsFloat(0);
			val[1] = m_receive.getArgAsFloat(1);
			
			printf("%f, %f\n", val[0], val[1]);
			fflush(stdout);
		}
	}
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(30);
}

/******************************
******************************/
void ofApp::keyPressed(int key){
	switch(key){
		case 'a':
		{
			ofxOscMessage m;
			m.setAddress("/OSC_test");
			m.addFloatArg(109.1);
			m.addFloatArg(202.5);
			
			Osc.OscSend.sendMessage(m);
		}
			break;
	}
}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
