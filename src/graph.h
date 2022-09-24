#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <cmath>
#include "screen.h"

class Graph{
    public:
        Graph(Screen *screen, double xMin, double xMax, double yMin, double yMax, int pxWidth, int pxHeight);

        void render();

        void rescale();

        void hLine(double y1);
        void vLine(double x1);
        void drawLine(double x1, double y1, double x2, double y2);
        void drawFunc();

        void makeAxis();

    private:
        Screen *screen;
        double xMin;
        double xMax;
        double yMin;
        double yMax;
        int pxWidth;
        int pxHeight;
        double xScale;
        double yScale;


};

#endif