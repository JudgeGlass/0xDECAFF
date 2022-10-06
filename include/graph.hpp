#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <cmath>
#include <screen.hpp>
#include <core/shuntingyard.hpp>

class Graph{
    public:
        Graph(Screen *screen, double xMin, double xMax, double yMin, double yMax, int pxWidth, int pxHeight);
        ~Graph();
        void render();

        void rescale();

        void hLine(double y1);
        void vLine(double x1);
        void drawLine(double x1, double y1, double x2, double y2);
        void drawFunc();
        void setF1(std::string &f1);

        void makeAxis();

        void update();

    private:
        Screen *screen;
        ShuntingYard *f1;
        


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