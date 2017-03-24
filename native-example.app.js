const asyncCb = require("./triggerAsyncCallback")

asyncCb.triggerAsyncCallbackWithPromise().then(function() {
    console.log("async callback triggered successfully!!");
});