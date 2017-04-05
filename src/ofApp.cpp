#include "ofApp.h"

vector<leaf> leaves;

leaf::leaf(){


}

void leaf::setup(){
   
    a = ofRandom(0,1);
    
    fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA32F);
    fbo.begin();
    ofClear(250,250,255,0);
    fbo.end();
//    ofSetBackgroundColor(0);
    //color.set(ofRandom(200,255),ofRandom(100,200),ofRandom(100,200));
    color.set(ofRandom(100,255),ofRandom(100,200),ofRandom(100,200));
     loc = ofPoint(0, 0, 0);
   
}
void leaf::update(){
   
    //float time = sTime + ofGetElapsedTimef() * a;
    float time = ofGetElapsedTimef() * a;
    rX = ofSignedNoise(time * 0.5) * 200;  // rotate +- 400deg
    rY = ofSignedNoise(time * 0.3) * 200;
    rZ = ofSignedNoise(time * 0.9) * 200;

    
    aX = ofSignedNoise(time * 2) * 50;  // rotate +- 400deg
    aY = ofSignedNoise(time * 4) * 50;
    aZ = ofSignedNoise(time * 6) * 50;

    
    vX = ofSignedNoise(time * 0.2)*20;  // rotate +- 400deg
    vY = ofSignedNoise(time * 0.4)*20;
    vZ = ofSignedNoise(time * 0.6);
//
//    vX = ofMap(ofSignedNoise(time * 0.2),-1,1,0,ofGetWidth()+100);
//    vY = ofMap(ofSignedNoise(time * 0.4), -1,1, 0, ofGetHeight()+100);
//    vZ = ofMap(ofSignedNoise(time * 0.6) , -1, 1, -800, 800);
   // ofMap(<#float value#>, <#float inputMin#>, <#float inputMax#>, <#float outputMin#>, <#float outputMax#>)

  

  
   loc += ofPoint(vX,vY,vZ);
   
   // loc = ofPoint(vX,vY,vZ);
//    if( loc.x> ofGetWidth()||loc.y > ofGetHeight()){
//     color.set(255);
//    
//    }
//    if (vX<0 +100|| vX >ofGetWidth()-100||vY<0 +100|| vY> ofGetHeight()-100) {
//    color.set(255);
    
    
   // }

   
}

void leaf::draw() {
    fbo.begin();
   
    
    ofPushStyle();
    ofSetColor(0,0,0,1);
    ofDrawRectangle(0,0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
    ofPushMatrix();
    
//    float z = ofSignedNoise((ofGetElapsedTimef() + sTime) * 0.9) * 400;
    
    ofTranslate(loc.x, loc.y, loc.z);
    
    // ofScale(dScaleX, dScaleY, dScaleZ);  // can be 3 dimensional
//    ofScale(dScaleX, dScaleY, dScaleZ);
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofPushStyle();
    ofFill();
    ofSetColor(color);
    ofDrawLine(-30,0,30,0);
//    ofDrawCircle(20, 20, 5);
//    
//    ofSetColor (ofRandom(100,250),ofRandom(90,255),0);
//    ofDrawLine(-20,80,20,80);
    ofPopStyle();
    ofPopMatrix();
    
    //----------------------------------------
    ofPushMatrix();
    
    //    float z = ofSignedNoise((ofGetElapsedTimef() + sTime) * 0.9) * 400;
//    
//    ofTranslate(loc.x+ 200, loc.y+200, loc.z+200);
//    
//   
//    
//    ofRotateX(aX);
//    ofRotateY(aY);
//    ofRotateZ(aZ);
//    
//    ofPushStyle();
//    ofFill();
//    ofSetColor(color);
//    ofDrawLine(-30,0,30,0);
//    
//    ofSetColor (ofRandom(100,250),ofRandom(90,255),0);
//    ofDrawLine(-20,80,20,80);
//
//    
//    
//    ofPopStyle();
//    ofPopMatrix();
        //----------------------------------------
    
    fbo.end();
    fbo.draw(0,0);
    
}




void ofApp::setup(){
   for(int i = 0; i <5; i++){
        leaf newLeaf;
        newLeaf.setup();
        leaves.push_back(newLeaf);
        
    }
    cout<<leaves.size()<<endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i < leaves.size(); i++) {
        if (leaves[i].loc.x<0 || leaves[i].loc.x >ofGetWidth() || leaves[i].loc.y<0|| leaves[i].loc.y> ofGetHeight()) {
            cout<<"leaves["<<i<<"] loc: "<< leaves[i].loc<< "out of boudary"<< endl;
            leaves.erase(leaves.begin() +i);
            leaf newLeaf;
            newLeaf.setup();
            leaves.push_back(newLeaf);
            
        }
        leaves[i].update();
    
    }
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundColor(0);

    for (int i = 0; i <5; i ++){
              leaves[i].draw();
     }

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
   
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
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
