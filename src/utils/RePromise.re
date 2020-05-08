include Promise;
let let_ = Promise.flatMap;

/* This is totally optional. It can be nice sometimes to return a
   non-promise value at the end of a function and have it automatically
   wrapped. See example inside the Some branch of the switch below. */
module Wrap = {
  let let_ = Promise.map;
};