const { reversenumber } = require("../build/Release/dsaAddon.node");

const input = 123456789;
console.log("input: ", input);

/*
 * @param {Integer} - number to reverse
 */
console.log("output: ", reversenumber(input));
