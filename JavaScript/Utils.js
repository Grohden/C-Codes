/** Function that search a value inside an array/object of arrays/objects
 * @param {Object | Array} objOrArray - a object or array where the value will be searched
 * @param {String | number} searchValue - a number or string to be searched.
 * @returns Array.[Object,String] | boolean - An array containing [0] the object that contains the key and [1] the key to the value.
 */
var objectOrArrayContainsValue = function (objOrArray, searchValue) {
  var x = 0;
  var matched = false;

  if (objOrArray instanceof Object) {
    var keys = Object.keys(objOrArray);

    for (x = 0; x < keys.length; x++) {
      matched = objectOrArrayContainsValue(objOrArray[keys[x]], searchValue,objOrArray,keys[x]);
      if (matched[0]) {
        break;
      }
    }
    return matched;
  }

  if (objOrArray instanceof Array) {
    for (x = 0; x < objOrArray.length; x++) {
      matched = objectOrArrayContainsValue(objOrArray[x], searchValue,objOrArray,x);
      if (matched[0]) {
        break;
      }
    }
    return matched;
  }
  if (objOrArray == searchValue){
    return Array.prototype.slice.call(arguments).slice(2);
  } else{
    return false;
  }
};


/**
 * Single execution for function, prevents it to be called if its in a loop
 * @param {Function} fn function to be executed
 * @param {Number} time time for timeout
 * @returns Function call this to reset timeout*/
function singleExecutionTimeout(fn, time){
    fn = fn || $.noop;

    var timeoutId;

    function reScheduleTimeout(){
        clearTimeout(timeoutId);
        timeoutId = setTimeout(function(){
            fn.apply(this,arguments);
        },time);
    }
    return reScheduleTimeout
}

/**
 * Prevents a function to be called multiple times on a certain time
 * @param {Function} fn function to be executed
 * @param {Number} time time to be executed, if is called again and time hasnt passed the call is ignored
 * @returns Function function to call on place of the old one */
function intervalExecution(fn, time){
    fn = fn || $.noop;

    var timeoutId;
    var called = true;

    function scheduleIfNotCalled(){
        if(called){
            called = false;
            timeoutId = setTimeout(function(){
                fn.apply(this,arguments);
                called = true;
            },time);
        } else {
        }
    }

    return scheduleIfNotCalled
}

/**
  @name getSafe
  @description get the property from object with safety checks to avoid non-object properties access (nulls, undefined and others)
  @param {Object} object object to search in
  @param {String} str path to search
  @return {Any} Returns undefined if not found, returns prop value if found.
*/
Object.prototype.getSafe = function(object, str){
    if(typeof str !== 'string'){
        console.error('cannot get undefined');
        return undefined;
    }

	if(typeof object !== 'object'){
		console.error('cannot acess property of non object');
		return undefined;
	}

	propList = str.split('.');
    var currentValue = object;
    
    var i = 0;
    for(i = 0; i < propList.length; i++){
		currentValue = currentValue[propList[i]];

		if(typeof currentValue !== 'object' && i !== propList.length-1){
			return undefined;		
		}
    }

	return currentValue;
}
