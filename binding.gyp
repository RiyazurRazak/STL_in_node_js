{
    "targets": [
    {
      "target_name": "dsaAddon",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "cpp/src/main.cpp",
            "cpp/src/heap/wrapper.cpp",
            "cpp/src/heap/heap.cpp",
            "cpp/src/stack/wrapper.cpp",
            "cpp/src/stack/stack.cpp",
            "cpp/src/queue/wrapper.cpp",
            "cpp/src/queue/queue.cpp",
            "cpp/src/reversenumber.cpp",
            "cpp/src/snailsort.cpp",
          
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    },]
}