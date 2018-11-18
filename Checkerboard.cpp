#include "cv.h"
#include "highgui.h"
#include "cxcore.h"

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

int main(int argc, char*argv[])
{
	int width=height = 140;//width and heigth of single square
	IplImage *src = cvCreateImage(cvSize(width*(10+1),width*(6+1)), IPL_DEPTH_8U, 1);//in the CalibrationAndTest.cpp ,there is a param called boardsize(10,6), causing here:(10+1),(6+1)
	cvZero(src);
	for (int i = 0; i < src->height; i++)
	{
		for (int j = 0; j < src->width; j++)
		{
			if ((i / width + j / height) % 2 != 0)
			{
				src->imageData[i*src->widthStep + j * src->nChannels] = 255;
			}
		}
	}

	cvNamedWindow("src");
	cvShowImage("src", src);

	cvSaveImage("ChessBoard.bmp", src, 0);
	cvWaitKey(0);

	return 0;


}