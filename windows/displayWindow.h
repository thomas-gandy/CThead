//
// Created by thomasgandy on 13/02/2022.
//

#ifndef CTHEAD_DISPLAYWINDOW_H
#define CTHEAD_DISPLAYWINDOW_H

#include <vector>
#include <GLFW/glfw3.h>

#include "window.h"
#include "../ctDataLoader.h"

class DisplayWindow: public Window {
    const float MIN_GAMMA_VALUE = 0.1;
    const float MAX_GAMMA_VALUE = 4;
    float prevGammaValue = gammaValue;
    float gammaValue = 1.f;

    bool nearestNeighbourSelected = true;
    bool previousNearestSelected = nearestNeighbourSelected;
    bool bilinearSelected = false;
    bool previousBilinear = bilinearSelected;

    const int MIN_SCALE_VALUE = 32;
    const int MAX_SCALE_VALUE = 1024;
    int prevScaleValue = scaleValue;
    int scaleValue = 256;

    float color[4] = {255, 255, 255, 255};
    ImU32 prevColorValue = colorValue;
    ImU32 colorValue = 77853;

    unsigned int ctSliceToDraw = 57;
    bool pixelBufferMustUpdate = false;

    bool pixelBufferNeedsUpdating() override;
    void updatePixelBuffer() override;
    void createImGuiGUI();
    static void drawImGuiGUI();

public:
    DisplayWindow() = delete;
    DisplayWindow(std::string title, int width, int height);
    void initialise() override;
    void render() override;
};

#endif //CTHEAD_DISPLAYWINDOW_H
