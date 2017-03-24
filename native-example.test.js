'use strict'

const asyncCb = require("./triggerAsyncCallback")

describe('Mocha unit test for async callback', function () {
    let p = undefined;

    it('trigger asnyc callback in Promise', function() {
       return asyncCb.triggerAsyncCallbackWithPromise()
    })

    it('trigger asnyc without Promise', function(done) {
        asyncCb.triggerAsyncCallbackNoPromise(done);
    })

})