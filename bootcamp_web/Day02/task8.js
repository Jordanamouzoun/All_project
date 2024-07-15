function countOccurrences(arr)
{
    let occ = {};
    for (let a = 0; a < arr.length; a++){
        if (occ[arr[a]])
            occ[arr[a]]++;
        else
        occ[arr[a]] = 1;
    }
    return occ;
}
const array = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4];
const occurrences = countOccurrences(array);
console.log(occurrences);