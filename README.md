## Add the WASIC Compiler to environment

Execute the following command in a terminal window.

`curl <https://raw.githubusercontent.com/wasienv/wasienv/master/install.sh> | sh`

Then, execute the following command in a terminal window:

`source ~/.wasienv/wasienv.sh`

## Install wasi sdk

**Linux**

```
$ cd ~/.wasienv
$ export WASI_VERSION=14
$ export WASI_VERSION_FULL=${WASI_VERSION}.0
$ wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_VERSION}/wasi-sdk-${WASI_VERSION_FULL}-linux.tar.gz
tar xvf wasi-sdk-${WASI_VERSION_FULL}-linux.tar.gz
$ echo "export WASI_SDK_PATH=`pwd`/wasi-sdk-${WASI_VERSION_FULL}" > wasi_sdk_env.sh
```

**MacOS**

```
$ cd ~/.wasienv
$ export WASI_VERSION=14
$ export WASI_VERSION_FULL=${WASI_VERSION}.0
$ wget <https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_VERSION}/wasi-sdk-${WASI_VERSION_FULL}-macos.tar.gz>
tar xvf wasi-sdk-${WASI_VERSION_FULL}-macos.tar.gz
$ echo "export WASI_SDK_PATH=`pwd`/wasi-sdk-${WASI_VERSION_FULL}" > wasi_sdk_env.sh
```
## Initialize the wasm-example

```
cd ~/
unzip wasm-example.zip or download from https://bitbucket.org/mimiktech/ti-vision-app-example/src/develop/wasm-example/
cd wasm-example
npm install
```

## Compile the code

Assuming you are in the `wasm-example` folder, run the following command in a terminal window to build `wtest-v1-1.0.0.tar` in the deploy folder.

```
./build.sh
```

## Deploying the code as a mimik WASM service

## Running the mimik service in edgeEngine

MORE TO COME

```
curl - http://{{host}}:8083/{{clientId}}/wasm-example/v1/time
```