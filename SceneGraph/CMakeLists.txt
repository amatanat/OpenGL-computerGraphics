cmake_minimum_required(VERSION 3.6)
project(MaterialClass)

find_package(OpenGL)
find_package(GLUT)
find_package(GLU)
find_package(GLEW REQUIRED)
find_package(glfw3)
find_package(X11)
find_package(Threads REQUIRED)
#find_package(assimp)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL -lGLU -lGLEW -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lSOIL") # -lassimp")


set(SOURCE_FILES main.cpp Shader.cpp Material.cpp Mesh.h Model.h)
add_executable(MaterialClass ${SOURCE_FILES})

target_link_libraries(
        ${PROJECT_NAME}
        ${OPENGL_gl_LIBRARY}
        ${GLUT_LIBRARIES}
        ${GLU_LIBRARY}
        ${GLEW_LIBRARIES}
        glfw3
        ${X11_LIBRARIES}
        ${X11_Xxf86vm_LIB}
        ${X11_Xrandr_LIB}
        pthread
        ${X11_Xi_LIB}
        ${CMAKE_DL_LIBS}
        ${X11_Xinerama_LIB}
        ${X11_Xcursor_LIB}
        SOIL
      #  assimp
)
