const { snailsort } = require("../build/Release/dsaAddon.node");

const input = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
];
console.log("input: ", input);

/*
 * @param {Array} - [[Interger]]
 */
console.log("output: ", snailsort(input));
