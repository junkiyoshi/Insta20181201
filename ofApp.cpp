#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetColor(239);
	ofSetLineWidth(1.5);
	ofEnableDepthTest();

	for (int i = 0; i < 2048; i++) {

		this->locations.push_back(glm::vec3(ofRandom(-ofGetWidth() * 0.5, ofGetWidth() * 0.5), ofRandom(-ofGetHeight() * 0.5, ofGetHeight() * 0.5), ofRandom(-360, 360)));
	}

	for (int i = 0; i < this->locations.size(); i++) {

		vector<int> next_index = vector<int>();
		for (int j = 0; j < this->locations.size(); j++) {

			if (i == j) { continue; }

			glm::vec3 distance = this->locations[i] - this->locations[j];
			if (glm::length(distance) <= 100) {

				next_index.push_back(j);
			}
		}

		this->next_indexes.push_back(next_index);
	}

	for (int i = 0; i < 80; i++) { this->particles.push_back(Particle(this->locations, this->next_indexes)); }
}
//--------------------------------------------------------------
void ofApp::update() {

	for (Particle& particle : particles) { particle.Upate(); }
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(180);
	ofRotateY(ofGetFrameNum() * -0.5);

	for (Particle& particle : particles) { particle.Draw(); }

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}