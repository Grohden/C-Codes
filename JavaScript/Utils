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
