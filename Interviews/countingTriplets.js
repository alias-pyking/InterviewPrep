function countTriplets(arr, r) {
    let leftmap = {};
    let rightmap = {}
    for(let i = 0; i < arr.length; i++) {
        rightmap[arr[i]] = 0;
    }
    for(let i = 0; i < arr.length; i++) {
        leftmap[arr[i]] = 0;
    }
    for(let i =0; i < arr.length; i++) {
        rightmap[arr[i]]++;
    }
    let triplets = 0;
    for (let i = 0; i < arr.length; i++) {
        rightmap[arr[i]]--;
        let mid = arr[i];
        let left = mid/r;
        let right = mid * r;
        
        if(leftmap[left] && rightmap[right]) {
            triplets += leftmap[left] * rightmap[right];
        }
        leftmap[mid]++;
    }
    return triplets;
}