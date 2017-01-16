
#ifndef MATERIALCLASS_MATERIAL_H
#define MATERIALCLASS_MATERIAL_H

#include <sstream>
#include <vector>
#define GLM_FORCE_RADIANS
#include <glm/vec3.hpp>
#include "Shader.h"

class Material {
public:
    Shader* shader;

    glm::vec3 ambient;      // mtl file: Ka
    glm::vec3 diffuse;      // mtl file: Kd
    glm::vec3 specular;     // mtl file: Ks
    float shininess, constant, linear, quadratic;
    glm::vec3 lightDir;    // mtl file: Ns

    Material();
    Material(
             float shininess,
             glm::vec3 ambient,
             glm::vec3 diffuse,
             glm::vec3 specular,
             glm::vec3 lightDir,
             float constant,
             float linear,
             float quadratic);
    ~Material();

    void activateTextures();
    void updateMaterialUniforms();
};


#endif //MATERIALCLASS_MATERIAL_H
