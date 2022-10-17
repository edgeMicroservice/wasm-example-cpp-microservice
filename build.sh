source ~/.wasienv/wasi_sdk_env.sh
cmake -Bbuild \
    -DCMAKE_BUILD_TYPE=Release \
    -DWASI_SDK_PREFIX=${WASI_SDK_PATH} \
    -DCMAKE_TOOLCHAIN_FILE=${WASI_SDK_PATH}/share/cmake/wasi-sdk.cmake \
    -H.
cmake --build build

# Strip out the unnecessary symbols
${WASI_SDK_PATH}/bin/strip ./build/wasm-example.wasm -o ./build/wasm-example-strip.wasm

npm run package
