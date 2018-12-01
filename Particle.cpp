#include "Particle.h"

//--------------------------------------------------------------
Particle::Particle(vector<glm::vec3> locations, vector<vector<int>> next_indexes) {

	this->locations = locations;
	this->next_indexes = next_indexes;
	this->locations_index = (int)ofRandom(this->locations.size());
	this->next_index = this->next_indexes[this->locations_index][(int)ofRandom(this->next_indexes[this->locations_index].size())];
}

//--------------------------------------------------------------
Particle::~Particle() {

}

//--------------------------------------------------------------
void Particle::Upate() {

	int frame_span = 10;

	if (ofGetFrameNum() % frame_span == 0) {

		this->locations_index = this->next_index;
		this->next_index = this->next_indexes[this->locations_index][(int)ofRandom(this->next_indexes[this->locations_index].size())];
	}

	glm::vec3 distance = this->locations[this->next_index] - this->locations[this->locations_index];
	this->location = this->locations[this->locations_index] + distance / frame_span * (ofGetFrameNum() % frame_span);

	this->logs.push_front(this->location);
	while (this->logs.size() > 10) { this->logs.pop_back(); }
}

//--------------------------------------------------------------
void Particle::Draw() {

	ofFill();
	//ofDrawSphere(this->location, 3);

	ofNoFill();
	ofBeginShape();
	for (glm::vec3& log : this->logs) {

		ofVertex(log);
	}
	ofEndShape();
}