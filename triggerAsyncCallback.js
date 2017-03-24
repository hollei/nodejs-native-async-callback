const native = require("./build/Release/native-example")

exports.triggerAsyncCallbackWithPromise = function() {
    return new Promise(function(res) {
        native.TriggerAsyncCalback(function() {
            console.log("promise resolved")
            res();
        });
    });
}

exports.triggerAsyncCallbackNoPromise = function(done) {
    native.TriggerAsyncCalback(function() {
        done();
    });
}