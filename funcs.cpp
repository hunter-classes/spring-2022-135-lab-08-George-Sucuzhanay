#include <iostream>
#include "funcs.h"
#include "imageio.h"


void invert(std::string input)
{
        int img[MAX_H][MAX_W];
        int h, w;
        readImage(input, img, h, w);
        int out[MAX_H][MAX_W];

        for(int row = 0; row < h; row++)
        {
                for(int col = 0; col < w; col++)
                {
                        out[row][col] = abs(255 - img[row][col]);
                }
        }
        writeImage("taskA.pgm",out, h, w);
}

void invertHalf(std::string input)
{
        int img[MAX_H][MAX_W];
        int h, w;
        readImage(input, img, h, w);
        int out[MAX_H][MAX_W];
        for(int row = 0; row < h; row++)
        {
                for(int col = 0; col < w; col++)
                {
                        if(col < w/2)
                        {
                                out[row][col] = img[row][col];
                        }
                        else{
                                out[row][col] = abs(255 - img[row][col]);
                        }

                }
        }
        writeImage("taskB.pgm", out, h, w);
}

void whiteBox(std::string input)
{
        int img[MAX_H][MAX_W];
        int h, w;
        readImage(input, img, h, w);
        int out[MAX_H][MAX_W];
        for(int row = 0; row < h; row++)
        {
                for(int col = 0; col < w; col++)
                {
                        if(row >= h / 4 && row <= 3 * h/4 && col >= w/4 && col <= 3 * w/4)
                        {
                                out[row][col] = 255;
                        }
                        else{
                                out[row][col] = img[row][col];
                        }
                }
        }
        writeImage("taskC.pgm", out, h, w);
}

void whiteBoxOutline(std::string input)
{
        int img[MAX_H][MAX_W];
        int h, w;
        readImage(input, img, h, w);
        int out[MAX_H][MAX_W];
        for(int row = 0; row < h; row++)
        {
                for(int col = 0; col < w; col++)
                {
                        if (row == h/4 | row == 3*h/4)
                        {
                                if(col >= w/4 && col <= 3*w/4)
                                {
                                        out[row][col] = 255;
                                }
                                else
                                {
                                        out[row][col] = img[row][col];
                                }

                        }
                        else if (col == w/4 || col == 3*w/4)
                        {
                                if(row >= h/4 && row <= 3*h/4)
                                {
                                        out[row][col] = 255;
                                }
                                else
                                {
                                        out[row][col] = img[row][col];
                                }
                        }
                                
                        else
                        {
                                out[row][col] = img[row][col];
                        }

                               
                }
        }
        writeImage("taskD.pgm", out, h, w);
}

void scale(std::string input)
{
        int img[MAX_H][MAX_W];
        int h, w;
        readImage(input, img, h, w);
        int out[MAX_H][MAX_W];
        for(int row = 0; row < h; row++)
        {
                for(int col = 0; col < w; col++)
                {
                        out[row*2][col*2] = img[row][col];
                        out[row*2][col*2 + 1] = img[row][col];
                        out[row*2 + 1][col*2] = img[row][col];
                        out[row*2 + 1][col*2 + 1] = img[row][col];
                }
        }
        writeImage("taskE.pgm", out, h*2, w*2);
}

void pixelate(std::string input)
{
        int img[MAX_H][MAX_W];
        int h, w;
        readImage(input, img, h, w);
        int out[MAX_H][MAX_W];
        for(int row = 0; row < h; row+=2)
        {
                for(int col = 0; col < w; col+=2)
                {
                        int avg = img[row][col] + img[row+1][col] + img[row][col+1] + img[row+1][col+1];
                        avg /= 4;
                        out[row][col] = avg;
                        out[row+1][col+1] = avg;
                        out[row][col+1] = avg;
                        out[row+1][col] = avg;
                }
        }
        writeImage("taskF.pgm", out, h, w);
}