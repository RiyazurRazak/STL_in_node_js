// import stack addon from cpp
const { stack } = require("../build/Release/dsaAddon.node");

// input
const input = [100, 65, 23, 09, 876];

const result = [];

// initialize our stack from js to cpp
const Stack = new stack();

// load elements in the stack
for (let i = 0; i < input.length; i++) {
  Stack.push(input[i]);
}

// remove elements from the stack (LIFO)
for (let i = 0; i < input.length; i++) {
  result.push(Stack.pop());
}

//log the result
console.table({ input: input, result: result });
