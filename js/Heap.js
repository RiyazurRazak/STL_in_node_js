// import heap from addon
const { heap } = require("../build/Release/dsaAddon.node");

// create random number of array with length 15
const input = Array.from({ length: 15 }, () =>
  Math.floor(Math.random() * 1000)
);

const minResult = [];
const maxResult = [];

/*
initialize the heap class from cpp
 * @param {Array} - array of type number
 * @param {String} - "min" \ "max"
*/

// create two class instance from cpp one with min Heap and another with max heap
const minHeap = new heap(input, "min");
const maxHeap = new heap(input, "max");

for (let i = 0; i < input.length; i++) {
  //remove the priority number from the heap
  minResult.push(minHeap.pop());
  maxResult.push(maxHeap.pop());
}

// log the sorted output
console.table({ input: input, minimum: minResult, maximum: maxResult });
