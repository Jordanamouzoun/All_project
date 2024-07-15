function calculateProduct(arr)
{
    let sum = 1;
    arr.forEach(element => {
        sum *= element;
    });
    return sum;
}
const numbers = [2, 3, 4, 5];
const product = calculateProduct(numbers);
console.log(product);