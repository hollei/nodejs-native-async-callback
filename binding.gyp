{
  "targets": [
    {
      "target_name": "native-example",
      "sources": [ "native-example.cc" ],
      'conditions': [
        [ 'OS!="win"', {
          "cflags+": [ "-std=c++11" ],
          "cflags_c+": [ "-std=c++11" ],
          "cflags_cc+": [ "-std=c++11" ],
        }]
       ]
    }
  ]
}