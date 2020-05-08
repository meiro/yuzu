#!/bin/bash -ex
mkdir -p "$HOME/.ccache"

chmod a+x ./.ci/scripts/linux-flatpak/docker.sh

# the UID for the container yuzu user is 1027
sudo chown -R 1027 ./
docker run --env-file .ci/scripts/linux-flatpak/azure-ci.env --env-file .ci/scripts/linux-flatpak/azure-ci-flatpak.env -v $(pwd):/yuzu -v "$HOME/.ccache":/root/.ccache -v "$HOME/.ssh":/root/.ssh --privileged meirod/build-environments:linux-flatpak /bin/bash -ex /yuzu/.ci/scripts/linux-flatpak/docker.sh
sudo chown -R $UID ./

