
#include "Material.h"

Material::Material() {

}

Material::Material(float shininess, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular,  glm::vec3 lightDir,
                   float constant,
                   float linear,
                   float quadratic) {
    this->shininess = shininess;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->lightDir = lightDir;
    this->constant = constant;
    this->linear = linear;
    this->quadratic = quadratic;
}

Material::~Material(){

}

void Material::activateTextures() {
    glUniform1i(glGetUniformLocation(shader->Program, "material.diffuse"),  0);
    glUniform1i(glGetUniformLocation(shader->Program, "material.specular"), 1);
}

void Material::updateMaterialUniforms() {

/*    GLint matAmbientLoc  = glGetUniformLocation(shader->Program, "material.ambient");
    GLint matDiffuseLoc  = glGetUniformLocation(shader->Program, "material.diffuse");
    GLint matSpecularLoc = glGetUniformLocation(shader->Program, "material.specular");*/
    GLint matShineLoc    = glGetUniformLocation(shader->Program, "material.shininess");

/*    glUniform3f(matAmbientLoc, this->ambient.x, this->ambient.y, this->ambient.z);
    glUniform3f(matDiffuseLoc,  this->diffuse.x, this->diffuse.y, this->diffuse.z);
    glUniform3f(matSpecularLoc, this->specular.x, this->specular.y, this->specular.z);*/
    glUniform1f(matShineLoc,    this->shininess);

    glUniform1f(glGetUniformLocation(shader->Program, "light.constant"), constant);
    glUniform1f(glGetUniformLocation(shader->Program, "light.linear"),    linear);
    glUniform1f(glGetUniformLocation(shader->Program, "light.quadratic"),quadratic);

    GLint lightAmbientLoc  = glGetUniformLocation(shader->Program, "light.ambient");
    GLint lightDiffuseLoc  = glGetUniformLocation(shader->Program, "light.diffuse");
    GLint lightSpecularLoc = glGetUniformLocation(shader->Program, "light.specular");
    GLint lightDirPos = glGetUniformLocation(shader->Program, "light.direction");

    glUniform3f(lightAmbientLoc, this->ambient.x, this->ambient.y, this->ambient.z );
    glUniform3f(lightDiffuseLoc, this->diffuse.x, this->diffuse.y, this->diffuse.z  ); // Let's darken the light a bit to fit the scene
    glUniform3f(lightSpecularLoc, this->specular.x, this->specular.y, this->specular.z);
    glUniform3f(lightDirPos, this->lightDir.x, this->lightDir.y, this->lightDir.z);


}
