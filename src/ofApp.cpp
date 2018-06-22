#include "ofApp.h"

int ofApp::coroutineTest(coroutine& coro) {
	int i;
	int temp = 0;
	reenter(coro) {
		yield return 1;
		for (i = 0; i < 10; i++) {
			temp = i;
		}
		yield return temp;
	}
}

// This method works like unity's "WaitForseconds".
void ofApp::coroutineTest2(coroutine& coro) {
	reenter(coro) {
		cout << "coroutine start" << endl;
		while (true) {
			if (difftime(time(NULL), start_time) >= 5) {
				break;
			}
			yield;
		}
		cout << "coroutine end" << endl;
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	start_time = time(NULL);

	std::cout << coroutineTest(coro) << std::endl;
	coroutineTest2(coro2);
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	std::cout << coroutineTest(coro) << std::endl;
	coroutineTest2(coro2);
	cout << "current time:" << difftime(time(NULL), start_time) << endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
