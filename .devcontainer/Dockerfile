FROM --platform=linux/amd64 mcr.microsoft.com/devcontainers/cpp:1-ubuntu-22.04

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="3.22.2"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>


ENV WASI_VERSION=14
ENV WASI_VERSION_FULL=${WASI_VERSION}.0
ENV WASI_SDK_PATH=${HOME}/wasi-sdk

ENV EDGE_ENGINE_VERSION=v3.9.2
ENV EDGE_ENGINE_PATH=${HOME}/edgeengine

# Create the wasi-sdk directory in the home directory
RUN mkdir -p ${WASI_SDK_PATH}

# Add the WASI SDK tarball from the remote URL
ADD https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_VERSION}/wasi-sdk-${WASI_VERSION_FULL}-linux.tar.gz ${WASI_SDK_PATH}

# Change to the target directory and extract the tarball
WORKDIR ${WASI_SDK_PATH}
RUN tar xvf wasi-sdk-${WASI_VERSION_FULL}-linux.tar.gz --strip-components=1

# Remove the downloaded tarball file to clean up
RUN rm wasi-sdk-${WASI_VERSION_FULL}-linux.tar.gz

#######
# Create the edgeEngine directory i the home directory
RUN mkdir -p ${EDGE_ENGINE_PATH}

# Add the edgeEngine tarball
ADD https://github.com/edgeEngine/edgeEngine-SE-Linux/releases/download/edgeEngine-SE-Linux-${EDGE_ENGINE_VERSION}/edgeEngine-SE-Linux-Trial-x86-${EDGE_ENGINE_VERSION}.tar ${EDGE_ENGINE_PATH}

# Change to the target directory and extract the tarball
WORKDIR ${EDGE_ENGINE_PATH}
RUN tar xvf edgeEngine-SE-Linux-Trial-x86-${EDGE_ENGINE_VERSION}.tar --strip-components=1

# Remove the downloaded tarball file to clean up
RUN rm edgeEngine-SE-Linux-Trial-x86-${EDGE_ENGINE_VERSION}.tar
