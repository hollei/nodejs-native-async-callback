'use strict'

const asyncCb = require("../../triggerAsyncCallback")

const {defineSupportCode} = require('cucumber')

defineSupportCode(function({Given, Then, When}) {

    When(/^I trigger without promise$/, function(callback) {
         asyncCb.triggerAsyncCallbackNoPromise(callback);
    })

    Then(/^I can successfully trigger with promise$/, function(callback) {
        asyncCb.triggerAsyncCallbackWithPromise().then(callback);
    })
})