Add to WASIC Compiler to environment

Do this every time console is created

source ~/.wasienv/wasienv.sh

To install WASI Compiler

Only do this first time

curl <https://raw.githubusercontent.com/wasienv/wasienv/master/install.sh> | sh

Install wasi sdk

Linux

$ cd ~/.wasienv
$ export WASI_VERSION=14
$ export WASI_VERSION_FULL=${WASI_VERSION}.0
$ wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_VERSION}/wasi-sdk-${WASI_VERSION_FULL}-linux.tar.gz
tar xvf wasi-sdk-${WASI_VERSION_FULL}-linux.tar.gz
$ echo "export WASI_SDK_PATH=`pwd`/wasi-sdk-${WASI_VERSION_FULL}" > wasi_sdk_env.sh

MacOS

$ cd ~/.wasienv
$ export WASI_VERSION=14
$ export WASI_VERSION_FULL=${WASI_VERSION}.0
$ wget <https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_VERSION}/wasi-sdk-${WASI_VERSION_FULL}-macos.tar.gz>
tar xvf wasi-sdk-${WASI_VERSION_FULL}-macos.tar.gz
$ echo "export WASI_SDK_PATH=`pwd`/wasi-sdk-${WASI_VERSION_FULL}" > wasi_sdk_env.sh

Initialize wasm-example

cd ~/
unzip wasm-example.zip or download from https://bitbucket.org/mimiktech/ti-vision-app-example/src/develop/wasm-example/
cd wasm-example
npm install

To compile

Assume you are in the wasm-example folder.
The commandlines below allow you to build wtest-v1-1.0.0.tar in the deploy folder

./build.sh

How to test

Get the WASI image from ~/wasm-service/deploy directory  (e.g wasm-example-v1-1.0.0.tar)  and deploy WASI microservice  by using Android Studio “http” plug in with “wasm-test.http” under ~/wasm-service/deploy directory or by following “Deploying the edgeEngine Image for the microservice” section in  https://devdocs.mimik.com/tutorials/05-index  link.

ls ~/wasm-service/deploy
curl - http://{{host}}:8083/{{clientId}}/wasm-example/v1/time

It will print “"hello world" string. If you would like to change, you can update ~/wasm-service/main.cpp