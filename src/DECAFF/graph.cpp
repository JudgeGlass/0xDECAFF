#include <graph.hpp>

Graph::Graph(Screen *screen, double xMin, double xMax, double yMin, double yMax, int pxWidth, int pxHeight){
    this->screen = screen;
    this->xMin = xMin;
    this->xMax = xMax;
    this->yMin = yMin;
    this->yMax = yMax;
    this->pxWidth = pxWidth;
    this->pxHeight = pxHeight;

    this->xScale = (this->xMax-this->xMin) /(double) pxWidth;
    this->yScale = (this->yMax - this->yMin) / (double) pxHeight;

    f1 = nullptr;
}

void Graph::setF1(std::string &f1){
    this->f1 = new ShuntingYard(f1);
}

void Graph::rescale(){
    xScale = (xMax - xMin) / ((double) pxWidth);
    yScale = (yMax - yMin) / ((double) pxHeight);
}

void Graph::hLine(double y1){
    int y = pxHeight - (int)((y1 - yMin) / yScale);
    screen->drawHLine(0, pxWidth, y, 1);
}

void Graph::vLine(double x1){
    int x = (int)((x1 - xMin) / xScale);
    screen->drawVLine(0, pxHeight, x, 1);
}

void Graph::drawLine(double x1, double y1, double x2, double y2){
    int xG = (int)((x1 - xMin) / xScale);
    int yG = pxHeight - (int)((y2 - yMin) / yScale);

    int xx = (int)((x2 - xMin) / xScale);
    int yy = pxHeight - (int)((y2 - yMin) / yScale);

    screen->drawLine(xG, yG, xx, yy);
}

void Graph::drawFunc(){
    if(f1 == nullptr) return;

    double lastY = f1->eval(xMin);
    double lastX = xMin;

    for(double i = xMin; i <= xMax; i += 0.02){
        double y1 = f1->eval(i);

        if(y1 > yMax || y1 < yMin) continue;

        drawLine(lastX, lastY, i, y1);
        //screen->renderFrameBuffer(false);


        lastX = i;
        lastY = y1;
    }
}

void Graph::update(){
    bool updateDisp = false;


    if(updateDisp) drawFunc();
}

void Graph::makeAxis(){
    hLine(0);
    vLine(0);

    screen->drawString(pxWidth / 2 + 4, 5, std::to_string((int)yMax), false);
    screen->drawString(pxWidth / 2 + 4, pxHeight - 8, std::to_string((int)yMin), false);
    screen->drawString(0, pxHeight / 2 + 4, std::to_string((int)xMin), false);
    screen->drawString(pxWidth - std::to_string((int)xMax).size() * 8, pxHeight / 2 + 4, std::to_string((int)xMax), false);
}

void Graph::render(){
    makeAxis();

    screen->renderFrameBuffer(false);
}

Graph::~Graph(){
    delete f1;
}