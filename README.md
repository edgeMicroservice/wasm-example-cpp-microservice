On Linux/Ubuntu: Install pip

sudo apt update

sudo apt install python3-pip -y

Install cmake

sudo apt install cmake -y

Install edgeEngine

wget https://github.com/edgeEngine/edgeengine-linux/releases/download/v3.0.0/edge-linux-v3.0.0.tar

tar xvf edge-linux-v3.0.0.tar

cd edge-v3.0.0

sh ./start.sh

Install the edgeEngine CLI tool

npm install -g @mimik/mimik-edge-cli

To install WASI Compiler

Only do this first time

curl https://raw.githubusercontent.com/wasienv/wasienv/master/install.sh | sh

Add to WASIC Compiler to environment

Do this every time the console is created

source ~/.wasienv/wasienv.sh



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

git clone https://metinbarut@bitbucket.org/mimiktech/wasm-example-cpp-microservice.git

cd wasm-example-cpp-microservice

git checkout develop

npm install

To compile

Assume you are in the ~/wasm-example-cpp-microservice folder.
The command lines below allow you to build wtest-v1-1.0.0.tar in the deploy folder

./build.sh

Installing edgeEngine and the mimik-edge-cli Tool on a Linux System or MacOS

Please floor the instructions in the following link to install mimik-edge-cli tool on a Linux System or MacOS

https://devdocs.mimik.com/tutorials/01-index 

and using the mimik-edge-cli Tool to Get An Access Token by following instructions on this link 

https://devdocs.mimik.com/tutorials/02-index 

Deploying the edgeEngine Image for the microservice

In order to get an edgeEngine microservice up and running you need to deploy an edgeEngine Image which will be derived from the .tar file created previously. Then, once the edgeEngine image is deployed, you'll deploy an edgeEngine Container that is based on the newly deployed edgeEngine Image.

To deploy the edgeEngine Imaged execute the following steps.

Step 1: Navigate to the deploy directory

cd ./deploy

Step 2: Using the mimik-edge-cli tool, execute a command similar to the following:

mimik-edge-cli image deploy --image={YOUR_IMAGE_PATH} --token={EDGE_ACCESS_TOKEN}

WHERE

{YOUR_IMAGE_PATH} is the location of the .tar file that represents the edgeEngine microservice

{EDGE_ACCESS_TOKEN} is the Access Token you generated and associated previously with the current edgeEngine installation. (You can read about creating and using an edgeEngine Access Token here).

In this instance you'll execute the following command to deploy the edgeEngine Image:

 mimik-edge-cli image deploy --image=./wasm-example-v1-1.0.0.tar --token={EDGE_ACCESS_TOKEN}

Upon executing the command described above, you'll get output similar to the following:

{
  "created": 1665061762,
  "digest": "sha265:c0877a6b610edcfc872626055378dc2e3b115cb13e23cbc5389d978169682c4e",
  "id": "23fe3714-fa90-4baa-92a7-0a2415147ea8-wasm-example-v1",
  "name": "wasm-example-v1",
  "repoTags": ["wasm-example-v1:1.0.0", "runtime:wasm"],
  "size": 154692,
  "status": "successfully deployed"
}

Step 3: Copy the value for name: from the successful response output and save it. You will need this value in the future. (In this case, the value to save is wasm-example-v1)

You have created the edgeEngine Image for the wasm-example-cpp-microservice.

Deploying the edgeEngine Container

To the deploy an edgeEngine Container based on the edgeEngine Image you created previously, take the following steps.

Step 1: Navigate to the root of the working directory, wasm-example-cpp-microservice

You'll see create a file, start.json. This file has the information that the mimik-edge-cli tool needs to deploy the edgeEngine Container. You're going to add the necessary information to the file, start.json.

Step 2: Open the file, start.json in a text editor. In this case we'll use vi.

vi start.json

You'll the insert the following lines into start.json file and save it.

{
    "name": "wasm-example-v1",
    "image": "wasm-example-v1",
    "env": {
      "MCM.BASE_API_PATH": "/wasm-example/v1",
      "MCM.CHILD_RUNTIME": "true"
    }
}

or

{
    "name": "{{containerName}}",
    "image": "{{imageName}}",
    "env": {
      "MCM.BASE_API_PATH": "{{YOUR_PATH}}",
      "MCM.CHILD_RUNTIME": "true"
    }
}



WHERE

{{containerName}} is the name you'll assign to the edgeEngine container

{{imageName}} is the name of thee edgeEngine Image defined in the output from the mimik-edge-cli image deploy command set.

{{YOUR_PATH}} is the custom defined path that will be assigned to the base route of the edgeEngine microservice

Step 3: Replace {{containerName}} & {{imageName}} with the name: value you copied earlier from the successful deployment response.

Step 4: Start the edgeContainer of our microservice using the mimik-edge-cli tool and our start.json file as the payload. Run command below in terminal window. Replace {EDGE_ACCESS_TOKEN} with your edge Access Token:

 mimik-edge-cli container deploy --payload start.json --token={EDGE_ACCESS_TOKEN}

You'll get output similar to the following:

{
  "clientId": "23fe3714-fa90-4baa-92a7-0a2415147ea8",
  "created": 1665061921577,
  "env": {
    "MCM.BASE_API_PATH": "/23fe3714-fa90-4baa-92a7-0a2415147ea8/wasm-example/v1",
    "MCM.CHILD_RUNTIME": "true",
    "MCM.DB_ENCRYPTION_SUPPORT": "false",
    "MCM.LINKLOCAL_REPLAY_NONCE_SUPPORT": "false",
    "MCM.RUNTIME": "wasm",
    "MCM.WEBSOCKET_SUPPORT": "false"
  },
  "id": "23fe3714-fa90-4baa-92a7-0a2415147ea8-wasm-example-v1",
  "image": "wasm-example-v1",
  "imageId": "23fe3714-fa90-4baa-92a7-0a2415147ea8-wasm-example-v1",
  "name": "wasm-example-v1",
  "state": "started"
}

Step 8: Copy the value for MCM.BASE_API_PATH: to a safe place. MCM.BASE_API_PATH is the route to the edgeEngine microservice that you'll append to path of the microservice at localhost:8083

Running the edgeEngine microservice

Step 1: To run the edgeEngine microservice, you'll use curl to make an HTTP request using the following path format:

 curl http://localhost:8083/<MCM.BASE_API_PATH>/time

WHERE

<MCM.BASE_API_PATH> is the route to the edgeEngine microservice.

Step 2: In this case, we'll replace <MCM.BASE_API_PATH> with the value we copied earlier from the successful deployment of the edgeEngine container, like so:

Upon successful execution of the curl command to call the microservice you'll get output similar to the following:

{
  "year": 2022,
  "month": 10,
  "day": 11,
  "hour": 17,
  "minute": 4,
  "seconds": 54,
  "milliSeconds": 971,
  "dateTime": "2022-10-11T17:04:54.9718168",
  "date": "10/11/2022",
  "time": "17:04",
  "timeZone": "Europe/Amsterdam",
  "dayOfWeek": "Tuesday",
  "dstActive": true
}

Congratulations! You've built an edgeEngine  Image and deployed the Image and an edgeEngine Container using the mimik-edge-cli tool.