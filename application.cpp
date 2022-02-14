//
// Created by thomasgandy on 12/02/2022.
//

#include <iostream>
#include <stdexcept>

#include "application.h"
#include "ctDataLoader.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"


void Application::initialiseGLFW() {
    if (!glfwInit()) throw std::runtime_error("Failed to initialise GLFW");
}

void Application::createWindows() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    this->galleryWindow.initialise();
    this->displayWindow.initialise();
    glfwMakeContextCurrent(this->displayWindow.getWindow());
}

void Application::initialiseImGui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(this->displayWindow.getWindow(), true);
    ImGui_ImplOpenGL3_Init(this->glslVersion);
}

void Application::mainloop() {
    bool galleryClose = false;
    bool displayClose = false;
    ImGuiIO& io = ImGui::GetIO();

    while (!galleryClose && !displayClose) {
        glfwPollEvents();

        this->galleryWindow.render();
        this->displayWindow.render();

        if (this->galleryWindow.windowShouldClose()) galleryClose = true;
        if (this->displayWindow.windowShouldClose()) displayClose = true;
    }
}

void Application::start() {
    this->initialiseGLFW();
    this->createWindows();
    this->initialiseImGui();
    CTDataLoader::loadData();

    this->mainloop();
}

Application::~Application() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
}