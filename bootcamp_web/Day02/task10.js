function removeFalsyValues(arr)
{
    let res = [];
    for (let a = 0; a < arr.length; a++) {
        if (arr[a])
            res.push(arr[a]);
    }
    return res;
}
const array = [0, 1, false, true, "", "hello", null, undefined, NaN];
const filteredArray = removeFalsyValues(array);
console.log(filteredArray);