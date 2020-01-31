#pragma once
// Image.h

#include <cmath>
#include <string>
#include <fstream>
#include "rgb.h"
using namespace std;

class Image
{
public:
	Image();

	// initializes raster to default rgb color
	Image(int width, int height);
	
	// initializes raster to 'background'
	Image(int width, int height, rgb background);

	// returns false if x or y are out of bounds, else true
	bool set(int x, int y, const rgb& color);
	void gammaCorrect(float gamma);
	
	// outputs PPM image to 'out'
	void writePPM(ostream& out);
	void readPPM(string file_name);

	rgb getPixel(int x, int y) const;
	int width() const { return nx; }
	int height() const { return ny; }


private:
	rgb** raster;
	int nx;	// raster width
	int ny;	// raster height
};
