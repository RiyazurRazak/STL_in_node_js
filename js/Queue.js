// import Queue addon from cpp
const { queue } = require("../build/Release/dsaAddon.node");

// input
const input = [100, 65, 23, 09, 876];

const result = [];

// initialize our Queue from js to cpp
const Queue = new queue();

// load elements in the Queue
for (let i = 0; i < input.length; i++) {
  Queue.push(input[i]);
}

// remove elements from the Queue (FIFO)
for (let i = 0; i < input.length; i++) {
  result.push(Queue.pop());
}

//log the result
console.table({ input: input, result: result });
