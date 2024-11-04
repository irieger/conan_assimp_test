# conan_assimp_test

docker run --memory=10g --cpus=10 --rm -ti debian:bullseye

apt -y update

apt install -y python3-pip cmake ninja-build git vim pkg-config

pip install --upgrade "conan"

git clone https://github.com/EstebanDugueperoux2/conan_assimp_test.git

cd conan_assimp_test

time conan create . --build missing -s build_type=Debug --profile:build .conan/profiles/build_profile --profile:host .conan/profiles/build_profile -c tools.system.package_manager:mode=install &> build.log

cp $HOME/.conan2/p/b/conan9c3d7421a84e0/b/build/Debug/game .
export ALICEVISION_OCIO=$PWD/config.ocio
./game
