function findSubsets(arr, index, target, curr, result) {
  if (index >= arr.length) {
    if (target === 0) {
      result.push([...curr]);
      return;
    }

    return;
  }

  curr.push(arr[index]);
  findSubsets(arr, index + 1, target - arr[index], curr, result);

  curr.pop();
  findSubsets(arr, index + 1, target, curr, result);
}

function perfectSum(arr, target) {
  let result = [];
  let curr = [];
  findSubsets(arr, 0, target, curr, result);
  return result;
}

function print2dArray(arr) {
  if (arr.length === 0) {
    console.log("-1");
    return;
  }

  let output = arr.map((subset) => "[" + subset.join(", ") + "]").join(", ");
  console.log(output);
}

let arr = [5, 2, 3, 10, 6, 8, 1];
let target = 10;
let result = perfectSum(arr, target);
print2dArray(result);
