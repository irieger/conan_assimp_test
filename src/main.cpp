#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>

#include "colorspace.hpp"

int main(int argc, char** argv){

    Assimp::Importer importer;

    std::string sfmDataFilename;
    const aiScene* scene = importer.ReadFile(sfmDataFilename, 0);
    if (!scene)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}
