#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle(vector<glm::vec3> locations, vector<vector<int>> next_indexes);
	~Particle();
	void Upate();
	void Draw();

	ofPoint location;
private:

	vector<glm::vec3> locations;
	vector<vector<int>> next_indexes;

	int locations_index;
	int next_index;

	std::deque<glm::vec3> logs;
};